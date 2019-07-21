/*
* OSPE - Open Source Packet Editor
* Copyright(C) 2018-2019 Javier Pereda <https://github.com/elecyb>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "stdafx.h"
#include "DllCommunication.h"
#include "OspeDll.h"
#include "FilterManager.h"
#include <sstream>
#include "Utils.h"

//#define DBG_BLOCKPKT // para debuggear packets bloqueados
//#define DBG_SENDPACKETDATA // para debuggear data de los packets 

char readData[IPC_BLOCK_SIZE];



// Agrega a info la informacion del socket (ip, port) y tambien el tipo de funcion y size del packet
void SetInfo(SOCKET socket, Functions functionId, int length, PacketInfo* info)
{
	//char ipstr[INET6_ADDRSTRLEN];
	BYTE ipver = IPV4;

	struct sockaddr_storage addrLocal;
	struct sockaddr_storage addrRemote;
	socklen_t addr_len = sizeof(struct sockaddr_storage);

	if (getsockname(socket, (struct sockaddr*)&addrLocal, &addr_len) == SOCKET_ERROR)
		Utils::errorLog(Utils::strm(2, "getsockname: ", Utils::IntToString(WSAGetLastError())));

	if (getpeername(socket, (struct sockaddr*)&addrRemote, &addr_len) == SOCKET_ERROR)
		Utils::errorLog(Utils::strm(2, "getpeername: ", Utils::IntToString(WSAGetLastError())));

	// deal with both IPv4 and IPv6:
	if (addrLocal.ss_family == AF_INET)
	{
		info->localIp = htonl(((struct sockaddr_in *)&addrLocal)->sin_addr.s_addr);
		info->localPort = htons(((struct sockaddr_in *)&addrLocal)->sin_port);

		info->remoteIp = htonl(((struct sockaddr_in *)&addrRemote)->sin_addr.s_addr);
		info->remotePort = htons(((struct sockaddr_in *)&addrRemote)->sin_port);

	}
	else
	{ // AF_INET6
		//Falta implementar
		Utils::errorLog("CRASH ALERT: IPv6 SOCKET NOT IMPLEMENTED");
		//struct sockaddr_in6 *sock_addr = (struct sockaddr_in6 *)&addrFrom;
		//info->portFrom = ntohs(sock_addr->sin6_port);
		//inet_ntop(AF_INET6, &sock_addr->sin6_addr, ipstr, sizeof ipstr);
		ipver = IPV6;
	}

	//Envía la versión del protocolo a través del campo functionId
	info->functionId = (Functions)(functionId | ipver);
	info->socketId = socket;
	info->size = length;
}

// This method writes the packet to the memory mapped file then returns
void ProcessPacket(Functions functionId, char* &buffer, int &length, SOCKET socket, bool &blocked)
{
	char * name = (char*)malloc(IPC_MAX_NAME);
	sprintf(name, "%s%u", "OSPEPACKETBUFF", GetCurrentProcessId());
	static osIPC::Client client(name);


	if (!client.IsOk())
	{
#ifdef DBG_SENDPACKETDATA 
		Utils::errorLog("Fail to open MMF!!", 1);
#endif
		return;
	}		

	// Set needed packet info (ip, port, Function, Size)
	PacketInfo info;
	if (socket != NULL)
		SetInfo(socket, functionId, (int)length, &info);
	else {
		info.functionId = functionId;
		info.localIp = 0;
		info.localPort = 0;
		info.remoteIp = 0;
		info.remotePort = 0;
		info.size = length;
		info.socketId = 0;
	}

	// Set data


#ifdef DBG_SENDPACKETDATA
	std::stringstream sinfo;
	sinfo << "GOT Info - FunctionID=" << info.functionId << " LocalIp=" << info.localIp << " LocalPort=" << info.localPort << " RemoteIp="
		<< info.remoteIp << " RemotePort=" << info.remotePort << " Size=" << info.size;
	Utils::errorLog((char*)sinfo.str().c_str(), 2);
#endif

	char* pBuff = (char *) malloc(sizeof(info) + length);
	memcpy(pBuff, &info, sizeof(info));
	memcpy(pBuff + sizeof(info), buffer, length);

	bool breakpoint = false;
	if (isFiltering)
		// Only filter if it wasn't blocked, makes no sense filter a blocked packet
		if (!CheckPacketBlock(pBuff + sizeof(info), info.size, (FilterCaptureFuncs)info.functionId))
			// If filter is a Breakpoint filter then stop filtering
			if (!CheckPacketBreak(pBuff + sizeof(info), info.size, (FilterCaptureFuncs)info.functionId)) {
				if (DoFilteringForPacket(pBuff + sizeof(info), info.size, (FilterCaptureFuncs)info.functionId))
					// Copy new filtered data
					memcpy((void*)buffer, pBuff + sizeof(info), length);
			}
			else 
				breakpoint = true;							
		else
			blocked = true;

	client.write(pBuff, sizeof(info) + length); // Send the packet to ospe

	if (breakpoint)
	{
		hMainThread = OpenThread(THREAD_ALL_ACCESS, FALSE, GetCurrentThreadId());
		SuspendThread(hMainThread); // Suspend thread until we receive new data from ospe
		UINT16 newLength = 0; 
		newLength = ((UINT8)readData[2] << 8) | ((UINT8)readData[1]); // Set the length for the new packet
		length = newLength;
		buffer = (char *)malloc(length);
		memcpy((void*)buffer, &readData[3], length); // read new data
	}
	
	free(pBuff);
}

void ProcessPacket(Functions functionId, char*& buffer, int& length) 
{
	bool blocked = false;
	ProcessPacket(functionId, buffer, length, NULL, blocked);
}

void InjectPacket() 
{
	SOCKET s = (((UINT8)readData[2] << 8) | (UINT8)readData[1]);
	int len = (((UINT8)readData[4] << 8) | (UINT8)readData[3]);
	const char * buf = &readData[5];
	int flags = MSG_DONTROUTE;
	send(s, buf, len, flags);
}

// Command reader thread worker
DWORD WINAPI Command_Reader(LPVOID context)
{
    // Continuously read data
    for (;;)
    {
        server.read(readData, IPC_BLOCK_SIZE, INFINITE);
		ServerCodes sc = (ServerCodes)readData[0];
		switch (sc)
		{
			case SCODE_INJECTPACKET:
				InjectPacket();
				break;
			case SCODE_SETPACKET:
				ResumeThread(hMainThread);
				break;
			case SCODE_STARTFILTERING:
				{		
					CovertBytesToFilterList(readData);
					isFiltering = true;
				}
				break;
			case SCODE_STOPFILTERING:
				isFiltering = false;
				break;
			case SCODE_STARTCAPTURE:
				isCapturing = true;
				break;
			case SCODE_STOPCAPTURE:
				isCapturing = false;
				break;
			case SCODE_LOADDLLEX:
				LoadDllEx(&readData[1]);
				break;
			case SCODE_UNLOADDLLEX:
				UnLoadDllEx();
				break;
			default:
				Utils::errorLog("UNKNOWN SERVER CODE!");
		}

    }

    // Success
    return 0;
};