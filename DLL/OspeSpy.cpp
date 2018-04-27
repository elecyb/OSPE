/*
* OSPE - Open Source Packet Editor
* Copyright(C) 2018  Javier Pereda <https://github.com/elecyb>
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

#define SOCKET_ERROR            (-1)
#include <ws2tcpip.h>
#include "MinHook.h"

#if defined _M_X64
#pragma comment(lib, "Lib\\libMinHook-x64-v141-mdd.lib")
#elif defined _M_IX86
#pragma comment(lib, "Lib\\libMinHook-x86-v141-mdd.lib")
#endif

#include "Defines.h"
#include "OspeSpy.h"
#include "DllCommunication.h"
#include "stdafx.h"
#include "ipc.h"

// Targent Function Pointers ------------------------------------------------------------
#pragma region Function Pointers

int (WINAPI *pSend)(SOCKET s, const char * buf, int len, int flags) = NULL;
int WINAPI MySend(SOCKET s, const char * buf, int len, int flags);
int (WINAPI *pSendTo)(SOCKET s, const char *buf, int len, int flags, const SOCKADDR *to, int tolen) = NULL;
int WINAPI MySendTo(SOCKET s, const char *buf, int len, int flags, const SOCKADDR *to, int tolen);
int (WINAPI *pRecv)(SOCKET s, char * buf, int len, int flags) = NULL;
int WINAPI MyRecv(SOCKET s, char * buf, int len, int flags);
int (WINAPI *pRecvFrom)(SOCKET s, char *buf, int len, int flags, SOCKADDR *from, int *fromlen) = NULL;
int WINAPI MyRecvFrom(SOCKET s, char *buf, int len, int flags, SOCKADDR *from, int *fromlen);

int (WINAPI *pWS2Send)(SOCKET s, const char* buf, int len, int flags) = NULL;
int WINAPI MyWS2Send(SOCKET s, const char* buf, int len, int flags);
int (WINAPI *pWS2SendTo)(SOCKET s, const char *buf, int len, int flags, const SOCKADDR *to, int tolen) = NULL;
int WINAPI MyWS2SendTo(SOCKET s, const char *buf, int len, int flags, const SOCKADDR *to, int tolen);
int (WINAPI *pWS2Recv)(SOCKET s, char* buf, int len, int flags) = NULL;
int WINAPI MyWS2Recv(SOCKET s, char* buf, int len, int flags);
int (WINAPI *pWS2RecvFrom)(SOCKET s, char *buf, int len, int flags, SOCKADDR *from, int *fromlen) = NULL;
int WINAPI MyWS2RecvFrom(SOCKET s, char *buf, int len, int flags, SOCKADDR *from, int *fromlen);

int (WINAPI *pWSASend)(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSASend(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount,    LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped,    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
int (WINAPI *pWSASendTo)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const SOCKADDR *lpTo, int iToLen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSASendTo(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const SOCKADDR *lpTo, int iToLen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
int (WINAPI *pWSARecv)(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSARecv(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount,    LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
int (WINAPI *pWSARecvFrom)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, SOCKADDR *lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSARecvFrom(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, SOCKADDR *lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

#pragma endregion
//-----------------------------------------------------------------------------------

//  Hooking functions ----------------------------------------------------------------------
#pragma region Hooks

// WS 1.1 SEND
int WINAPI MySend( SOCKET s, const char *buf, int len, int flags )
{
	int originalLen = len;
    bool blocked = false;
	ProcessPacket(CODE_SEND, (char * &)buf, len, s, blocked);

    if (send_ws1 != NULL)
        (send_ws1)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return originalLen;

    pSend( s, buf, len, flags );
	return originalLen;
}
// WS 1.1 SEND TO
int WINAPI MySendTo(SOCKET s, const char *buf, int len, int flags, const SOCKADDR *to, int tolen)
{
    bool blocked = false;
	ProcessPacket(CODE_SENDTO, (char * &)buf, len, s, blocked);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return pSendTo( s, buf,  len,  flags, to,  tolen );
}
// WS 1.1 RECV
int WINAPI MyRecv( SOCKET s, char *buf, int len, int flags )
{
    bool blocked = false;
    int ret = pRecv( s, buf, len, flags );

    if(ret != SOCKET_ERROR)
		ProcessPacket(CODE_RECV, buf, ret, s, blocked);

    if (recv_ws1 != NULL)
        (recv_ws1)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return ret;

}
// WS 1.1 RECV FROM
int WINAPI MyRecvFrom( SOCKET s, char *buf, int len, int flags, SOCKADDR *from, int *fromlen )
{
    bool blocked = false;
    int ret = pRecvFrom( s, buf, len, flags, from, fromlen );
    if(ret != SOCKET_ERROR)
		ProcessPacket(CODE_RECVFROM, buf, ret, s, blocked);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return ret;
}


// WS 2.0 SEND
int WINAPI MyWS2Send( SOCKET s, const char *buf, int len, int flags ) {
	int originalLen = len;
    bool blocked = false;
	ProcessPacket(CODE_WS2SEND, (char * &)buf, len, s, blocked);
    if (send_ws2 != NULL)
        (send_ws2)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    pWS2Send( s, buf, len, flags );
	return originalLen;
}
// WS 2.0 SEND TO
int WINAPI MyWS2SendTo(SOCKET s, const char *buf, int len, int flags, const SOCKADDR *to, int tolen){
    bool blocked = false;
	ProcessPacket(CODE_WS2SENDTO, (char * &)buf, len, s, blocked);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return pWS2SendTo( s, buf,  len,  flags, to,  tolen );
}
// WS 2.0 RECV
int WINAPI MyWS2Recv( SOCKET s, char *buf, int len, int flags ) {
    bool blocked = false;
    int ret = pWS2Recv( s, buf, len, flags );
    if(ret != SOCKET_ERROR)
		ProcessPacket(CODE_WS2RECV, buf, ret, s, blocked);
    if (recv_ws2 != NULL)
        (recv_ws2)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return ret;
}
// WS 2.0 RECV FROM
int WINAPI MyWS2RecvFrom( SOCKET s, char *buf, int len, int flags, SOCKADDR *from, int *fromlen ) {
    bool blocked = false;
    int ret = pWS2RecvFrom( s, buf, len, flags, from, fromlen );
    if(ret != SOCKET_ERROR)
		ProcessPacket(CODE_WS2RECVFROM, buf, ret, s, blocked);

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return ret;
}


// WSA SEND
int WINAPI MyWSASend(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount,    LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped,    LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine){
    bool blocked = false;
    for ( DWORD i=0; i<dwBufferCount; i++) {
		ProcessPacket(CODE_WSASEND, lpBuffers[i].buf, (int &) lpBuffers[i].len, s, blocked);
    }

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return pWSASend(s, lpBuffers, dwBufferCount,    lpNumberOfBytesSent, dwFlags, lpOverlapped,    lpCompletionRoutine);
}
// WSA SEND TO
int WINAPI MyWSASendTo(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const SOCKADDR *lpTo, int iToLen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine){
    bool blocked = false;
    for ( DWORD i=0; i<dwBufferCount; i++) {
		ProcessPacket(CODE_WSASENDTO, lpBuffers[i].buf, (int &) lpBuffers[i].len, s, blocked);
    }

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return pWSASendTo(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpTo, iToLen, lpOverlapped, lpCompletionRoutine);
}
// WSA RECV
int WINAPI MyWSARecv(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount,    LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags,LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine){
    bool blocked = false;
    int ret = pWSARecv(s, lpBuffers, dwBufferCount,    lpNumberOfBytesRecvd, lpFlags, lpOverlapped, lpCompletionRoutine);
    if(ret != SOCKET_ERROR){
        if( lpNumberOfBytesRecvd != NULL ){
            DWORD bytesRecvd = *lpNumberOfBytesRecvd;
            DWORD bufferDataSize;
            for ( DWORD i=0; i<dwBufferCount; i++) 
			{
                bufferDataSize = (bytesRecvd > lpBuffers[i].len) ? lpBuffers[i].len : bytesRecvd ;
				ProcessPacket(CODE_WSARECV, lpBuffers[i].buf, (int &) bufferDataSize, s, blocked);

                bytesRecvd -= bufferDataSize;
                if( !bytesRecvd )
                    break;
            }
        }
        else{
			errorLog("CODE_WASA_lpNumberOfBytesRecvd_NULL");
        }
    }

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return ret;
}
// WSA RECV FROM
int WINAPI MyWSARecvFrom(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, SOCKADDR *lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine){
    bool blocked = false;
    int ret = pWSARecvFrom(s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpFrom, lpFromlen, lpOverlapped, lpCompletionRoutine);
    if(ret != SOCKET_ERROR){
        if( lpNumberOfBytesRecvd != NULL ){
            DWORD bytesRecvd = *lpNumberOfBytesRecvd;
            DWORD bufferDataSize;
            for ( DWORD i=0; i<dwBufferCount; i++) {
                bufferDataSize = (bytesRecvd > lpBuffers[i].len) ? lpBuffers[i].len : bytesRecvd;
				ProcessPacket(CODE_WSARECVFROM, lpBuffers[i].buf, (int &) bufferDataSize, s, blocked);

                bytesRecvd -= bufferDataSize;
                if( !bytesRecvd )
                    break;
            }
        }
        else{
            errorLog("CODE_WASA_lpNumberOfBytesRecvd_NULL");
        }
    }

	// Packet blocked, no llamamos a la funcion original
	if (blocked)
		return NULL;

    return ret;
}

#pragma endregion

//-----------------------------------------------------------------------------------

// Estos son punteros a las funciones de la DLL Ex, si las define entonces se llaman en las funciones hook de OspeSpy
T_SENDWS1 send_ws1 = NULL;
T_RECVWS1 recv_ws1 = NULL;
T_SENDWS2 send_ws2 = NULL;
T_RECVWS2 recv_ws2 = NULL;
T_SENDWSA send_wsa = NULL;
T_RECVWSA recv_wsa = NULL;

HMODULE hDllEx;
HANDLE hMainThread;

bool isCapturing = false;
bool isFiltering = false;


void LoadDllEx(LPCSTR lpFileName) {
	hDllEx = LoadLibraryA(lpFileName);
	send_ws1 = (T_SENDWS1)GetProcAddress(hDllEx, "Send_WS1");
	recv_ws1 = (T_RECVWS1)GetProcAddress(hDllEx, "Recv_WS1");
	send_ws2 = (T_SENDWS2)GetProcAddress(hDllEx, "Send_WS2");
	recv_ws2 = (T_RECVWS2)GetProcAddress(hDllEx, "Recv_WS2");
	send_wsa = (T_SENDWSA)GetProcAddress(hDllEx, "Send_WSA");
	recv_wsa = (T_RECVWSA)GetProcAddress(hDllEx, "Recv_WSA");
	//(recv_ws1)(NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL);
}

void UnLoadDllEx() {
	FreeLibrary(hDllEx);
	send_ws1 = NULL;
	recv_ws1 = NULL;
	send_ws2 = NULL;
	recv_ws2 = NULL;
	send_wsa = NULL;
	recv_wsa = NULL;
}

// DLL Main
INT APIENTRY DllMain( HMODULE hDLL, DWORD dwReason, LPVOID Reserved) {
    switch ( dwReason ) {
    case DLL_PROCESS_ATTACH:

        DisableThreadLibraryCalls(hDLL);

		// Initialize MinHook.
		if (MH_Initialize() != MH_OK)
		{
			errorLog("MH_Initialize FAIL! ");
			return 1;
		}

		// Create a hook for each winsock function, in disabled state.   //	MH_CreateHook(&send, &MySend, (LPVOID*)&pSend); 
		MH_CreateHookApi(L"wsock32.dll", "send", MySend, (LPVOID*)&pSend);
		MH_CreateHookApi(L"wsock32.dll", "sendto", MySendTo, (LPVOID*)&pSendTo);
		MH_CreateHookApi(L"wsock32.dll", "recv", MyRecv, (LPVOID*)&pRecv); 
		MH_CreateHookApi(L"wsock32.dll", "recvfrom", MyRecvFrom, (LPVOID*)&pRecvFrom); 

		MH_CreateHookApi(L"Ws2_32.dll", "send", MyWS2Send, (LPVOID*)&pWS2Send); 
		MH_CreateHookApi(L"Ws2_32.dll", "sendto", MyWS2SendTo, (LPVOID*)&pWS2SendTo);
		MH_CreateHookApi(L"Ws2_32.dll", "recv", MyWS2Recv, (LPVOID*)&pWS2Recv); 
		MH_CreateHookApi(L"Ws2_32.dll", "recvfrom", MyWS2RecvFrom, (LPVOID*)&pRecvFrom); 

		MH_CreateHookApi(L"Ws2_32.dll", "WSASend", MyWSASend, (LPVOID*)&pWSASend);
		MH_CreateHookApi(L"Ws2_32.dll", "WSASendTo", MyWSASendTo, (LPVOID*)&pWSASendTo); 
		MH_CreateHookApi(L"Ws2_32.dll", "WSARecv", MyWSARecv, (LPVOID*)&pWSARecv); 
		MH_CreateHookApi(L"Ws2_32.dll", "WSARecvFrom", MyWSARecvFrom, (LPVOID*)&pWSARecvFrom);

		MH_EnableHook(MH_ALL_HOOKS); // errorLog("HOOKED! ");

        // Spawn command reader thread worker
        CreateThread(NULL, 0, Command_Reader, NULL, 0, NULL);
		
        break;
    case DLL_PROCESS_DETACH:

		MH_DisableHook(MH_ALL_HOOKS);

        break;
    }

    return TRUE;
}

