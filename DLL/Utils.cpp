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

// Original code by Ionut Popescu (@NytroRST)

#include "stdafx.h"
#include "Utils.h"

// Function to convert a string to lower

string Utils::ToLower(string p_sString)
{
	string result = "";

	for (size_t i = 0; i < p_sString.length(); i++)
	{
		if (p_sString[i] >= 65 && p_sString[i] <= 90) result += (char)(p_sString[i] + 32);
		else result += p_sString[i];
	}

	return result;
}

// Converts an integer to string

string Utils::IntToString(unsigned int p_nNumer)
{
	string sResult = "";
	ostringstream ss;

	ss << p_nNumer;
	sResult = ss.str();

	return sResult;
}

// Converts a string to integer

unsigned int Utils::StringToInt(string p_sNumer)
{
	unsigned int ret = 0;

	ret = stoi(p_sNumer);

	return ret;
}

// Converts an integer to hex string

string Utils::IntToHex(unsigned int p_nNumer)
{
	string sResult = "";
	ostringstream ss;

	ss << std::hex << p_nNumer;
	sResult = ss.str();

	return sResult;
}

// Get string between two separators

string Utils::GetStringBetween(string p_sString, string p_sStart, string p_sStop)
{
	size_t start = p_sString.find(p_sStart);
	size_t end = p_sString.find(p_sStop, start);
	string substring = "";

	// Get strings

	if (start != std::string::npos && end != std::string::npos)
	{
		substring = p_sString.substr(start + p_sStart.length(), end - start - p_sStop.length() + 1);
	}
	else
	{
		//DebugLog::LogString("[ERROR] Cannot get string between separators in: ", p_sString);
		return "";
	}

	return substring;
}

// Split a string in multiple strings

vector<string> Utils::SplitString(string p_sString, string p_sDelimiter)
{
	vector<string> sVector;

	size_t lastPos = 0;
	size_t pos = p_sString.find(p_sDelimiter, lastPos);

	while (string::npos != pos)
	{
		sVector.push_back(p_sString.substr(lastPos, pos - lastPos));
		lastPos = pos + p_sDelimiter.size();
		pos = p_sString.find(p_sDelimiter, lastPos);
	}

	sVector.push_back(p_sString.substr(lastPos, p_sString.size() - lastPos));
	return sVector;
}

// Check if a process is 32 bit or 64 bit

bool Utils::Is32BitProcess()
{
	if (sizeof(void*) == 4) return true;
	else return false;
}

// Get IP and port information

IPInfo Utils::GetIPInfo(unsigned int p_nSocket)
{
	IPInfo data;
	sockaddr_in sock_client, sock_server;
	int len_client = sizeof(sock_client);
	int len_server = sizeof(sock_server);

	// Get socket data

	memset(&sock_client, 0, sizeof(sock_client));
	memset(&sock_server, 0, sizeof(sock_server));

	getsockname((SOCKET)p_nSocket, (struct sockaddr*) & sock_client, &len_client);
	getpeername((SOCKET)p_nSocket, (struct sockaddr*) & sock_server, &len_server);

	// Save data

	data.nSrcIP = (uint32_t)sock_client.sin_addr.S_un.S_addr;
	data.nDstIP = (uint32_t)sock_server.sin_addr.S_un.S_addr;
	data.nSrcPort = (uint16_t)ntohs(sock_client.sin_port);
	data.nDstPort = (uint16_t)ntohs(sock_server.sin_port);

	return data;
}

// Concatena strings (allocates needed memory)
char* Utils::strm(unsigned char count, ...)
{
	// new string from Multiple Strings
	va_list pL;
	va_start(pL, count);

	int i, length = 0;
	char* string, * tmp;
	char** str = (char**)malloc(sizeof(void*) * count);
	int* len = (int*)malloc(sizeof(int) * count);

	for (i = 0; i < count; i++) {
		str[i] = va_arg(pL, char*);
		len[i] = strlen(str[i]);
		length += len[i];
	}

	string = (char*)malloc(length + 1);
	string[length] = 0;
	tmp = string;

	for (i = 0; i < count; i++) {
		memcpy(tmp, str[i], len[i]);
		tmp += len[i];
	}

	va_end(pL);
	return string;
}

char* Utils::GetSystemError(const char* msg) {

	char* Msg;

	// Retrieve the system error message for the last-error code
	DWORD e = GetLastError();
	LPSTR errorMsg;
	FormatMessageA(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, e, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)& errorMsg, 0, NULL);
	Msg = Utils::strm(6, msg, "\nGetLastError(): Err# ", Utils::IntToString(e).data(), "\n", errorMsg, "\n");
	LocalFree(errorMsg);

	return Msg;
}

//LOG
// Level es opcional, indica el nivel de detalle requerido para mostrar log
// VER Defines.h para los log de funciones
#define ERRORLEVEL 1

void Utils::errorLog(char* cStr, int level) {

	if (level > ERRORLEVEL)
		return;

	//FILE* pFile;
	//fopen_s(&pFile, "C:\\DllErrorLog.txt", "a+");
	//fprintf(pFile, "%s", GetSystemError(cStr));
	//fclose(pFile);

	//MessageBoxA(0, GetSystemError(cStr), "Error", MB_OK);
	MessageBoxA(0, cStr, "Error", MB_OK);
}

#include <iomanip>
#include <sstream>
const char* Utils::GetBufferAsHex(char* buf, int len) {
	std::ostringstream Logger;
	Logger.str("");
	for (int i = 0; i < len; ++i) {
		Logger << std::hex << std::setw(2) << std::setfill('0') << (int(buf[i]) & 0xFF);
	}
	return Logger.str().data();
}
