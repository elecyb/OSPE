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

#ifndef _HOOKEDFUNCTIONS_H_
#define _HOOKEDFUNCTIONS_H_

#define SECURITY_WIN32

#include "MinHook.h"
#include <winsock2.h>
#include <security.h>
#include <stdio.h>

// =============================================================================================//

// PR_Read, PR_Write, SSLGetSessionID

typedef int (*PR_Write_Typedef)(void*, void*, DWORD);
typedef int (*PR_Read_Typedef)(void*, void*, DWORD);
typedef int (*PR_GetDescType_Typedef)(void* fd);

// Callbacks

int PR_Write_Callback(void* fd, void* buffer, DWORD amount);
int PR_Read_Callback(void* fd, void* buffer, DWORD amount);

// =============================================================================================//

// SSL_Read, SSL_Write

typedef int (*SSL_Write_Typedef)(void*, void*, int);
typedef int (*SSL_Read_Typedef)(void*, void*, int);

// Callbacks

int SSL_Write_Callback(void* ssl, void* buffer, int amount);
int SSL_Read_Callback(void* ssl, void* buffer, int amount);

// =============================================================================================//

// SSLEay_Read, SSLEay_Write

typedef int(*SSLeay_Write_Typedef)(void*, void*, int);
typedef int(*SSLeay_Read_Typedef)(void*, void*, int);

// Callbacks

int SSLeay_Write_Callback(void* ssl, void* buffer, int amount);
int SSLeay_Read_Callback(void* ssl, void* buffer, int amount);

// =============================================================================================//

// SecureCRT_Write

typedef int(__stdcall* SecureCRT_Typedef)(void* pthis, unsigned char** data, DWORD);

// Callback

int __cdecl SecureCRT_Callback(void* pthis, unsigned char** data, DWORD size);

// =============================================================================================//

// PuttySend, PuttyRecv

typedef void (*PuttySend_Typedef)(void* handle, char* buf, int len, int interactive);
typedef int (*PuttyRecv_Typedef)(void* term, int is_stderr, const char* data, int len);

// Callbacks

void PuttySend_Callback(void* handle, char* buf, int len, int interactive);
int PuttyRecv_Callback(void* term, int is_stderr, const char* data, int len);

// =============================================================================================//

// PR_Send, PR_Recv

typedef int (*PR_Send_Typedef)(void* fd, const void* buf, int amount, int flags, DWORD timeout);
typedef int (*PR_Recv_Typedef)(void* fd, void* buf, int amount, int flags, DWORD timeout);

// Callbacks

int PR_Send_Callback(void* fd, const void* buf, int amount, int flags, DWORD timeout);
int PR_Recv_Callback(void* fd, void* buf, int amount, int flags, DWORD timeout);

// =============================================================================================//

// SSH_Rdpkt

typedef int(__fastcall* SSH_Rdpkt_Typedef)(int datalen, unsigned char* data);
typedef void(__fastcall* SSH_Pktsend_Typedef)(int datalen, unsigned char* data);

// Callbacks

int __fastcall SSH_Rdpkt_Callback(int datalen, unsigned char* data);
void __fastcall SSH_Pktsend_Callback(int datalen, unsigned char* data);

// =============================================================================================//

// SslEncryptPacket, SslDecryptPacket

typedef LONG(__stdcall* SslEncryptPacket_Typedef)(ULONG_PTR hSslProvider, ULONG_PTR hKey, PBYTE* pbInput, DWORD cbInput,
	PBYTE pbOutput, DWORD cbOutput, DWORD* pcbResult, ULONGLONG SequenceNumber, DWORD dwContentType, DWORD dwFlags);
typedef LONG(__stdcall* SslDecryptPacket_Typedef)(ULONG_PTR hSslProvider, ULONG_PTR hKey, PBYTE* pbInput, DWORD cbInput,
	PBYTE pbOutput, DWORD cbOutput, DWORD* pcbResult, ULONGLONG SequenceNumber, DWORD dwFlags);

// Callbacks

LONG __stdcall SslEncryptPacket_Callback(ULONG_PTR hSslProvider, ULONG_PTR hKey, PBYTE* pbInput, DWORD cbInput, PBYTE pbOutput,
	DWORD cbOutput, DWORD* pcbResult, ULONGLONG SequenceNumber, DWORD dwContentType, DWORD dwFlags);
LONG __stdcall SslDecryptPacket_Callback(ULONG_PTR hSslProvider, ULONG_PTR hKey, PBYTE* pbInput, DWORD cbInput, PBYTE pbOutput,
	DWORD cbOutput, DWORD* pcbResult, ULONGLONG SequenceNumber, DWORD dwFlags);

// =============================================================================================//

// EncryptMessage, DecryptMessage

typedef SECURITY_STATUS(__stdcall* EncryptMessage_Typedef)(PCtxtHandle phContext, ULONG fQOP, PSecBufferDesc pMessage, ULONG MessageSeqNo);
typedef SECURITY_STATUS(__stdcall* DecryptMessage_Typedef)(PCtxtHandle phContext, PSecBufferDesc pMessage, ULONG MessageSeqNo, PULONG pfQOP);

// Callbacks

SECURITY_STATUS __stdcall EncryptMessage_Callback(PCtxtHandle phContext, ULONG fQOP, PSecBufferDesc pMessage, ULONG MessageSeqNo);
SECURITY_STATUS __stdcall DecryptMessage_Callback(PCtxtHandle phContext, PSecBufferDesc pMessage, ULONG MessageSeqNo, PULONG pfQOP);

// =============================================================================================//

typedef void(__stdcall* T_SENDWS1)(SOCKET, const char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall* T_RECVWS1)(SOCKET, char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall* T_SENDWS2)(SOCKET, const char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall* T_RECVWS2)(SOCKET, char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall* T_SENDWSA)(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall* T_RECVWSA)(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE, LPVOID, LPVOID, LPVOID, LPVOID, bool);


// Variables (function pointers)

extern PR_Write_Typedef PR_Write_Original;
extern PR_Read_Typedef PR_Read_Original;
extern PR_GetDescType_Typedef PR_GetDescType_Original;

extern SSL_Write_Typedef SSL_Write_Original;
extern SSL_Read_Typedef SSL_Read_Original;

extern SSLeay_Write_Typedef SSLeay_Write_Original;
extern SSLeay_Read_Typedef SSLeay_Read_Original;

extern PR_Send_Typedef PR_Send_Original;
extern PR_Recv_Typedef PR_Recv_Original;

extern SSH_Pktsend_Typedef SSH_Pktsend_Original;
extern SSH_Rdpkt_Typedef SSH_Rdpkt_Original;

extern SslEncryptPacket_Typedef SslEncryptPacket_Original;
extern SslDecryptPacket_Typedef SslDecryptPacket_Original;

extern EncryptMessage_Typedef EncryptMessage_Original;
extern DecryptMessage_Typedef DecryptMessage_Original;

// =============================================================================================//


extern int (WINAPI* pSend)(SOCKET, const char*, int, int);
extern int WINAPI MySend(SOCKET, const char*, int, int);
extern int (WINAPI* pSendTo)(SOCKET, const char*, int, int, const SOCKADDR*, int);
extern int WINAPI MySendTo(SOCKET, const char*, int, int, const SOCKADDR*, int);
extern int (WINAPI* pRecv)(SOCKET, char*, int, int);
extern int WINAPI MyRecv(SOCKET, char*, int, int);
extern int (WINAPI* pRecvFrom)(SOCKET, char*, int, int, SOCKADDR*, int*);
extern int WINAPI MyRecvFrom(SOCKET, char*, int, int, SOCKADDR*, int*);

extern int (WINAPI* pWS2Send)(SOCKET, const char*, int, int);
extern int WINAPI MyWS2Send(SOCKET, const char*, int, int);
extern int (WINAPI* pWS2SendTo)(SOCKET, const char*, int, int, const SOCKADDR*, int);
extern int WINAPI MyWS2SendTo(SOCKET, const char*, int, int, const SOCKADDR*, int);
extern int (WINAPI* pWS2Recv)(SOCKET, char*, int, int);
extern int WINAPI MyWS2Recv(SOCKET, char*, int, int);
extern int (WINAPI* pWS2RecvFrom)(SOCKET, char*, int, int, SOCKADDR*, int*);
extern int WINAPI MyWS2RecvFrom(SOCKET, char*, int, int, SOCKADDR*, int*);

extern int (WINAPI* pWSASend)(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern int WINAPI MyWSASend(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern int (WINAPI* pWSASendTo)(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, const SOCKADDR*, int, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern int WINAPI MyWSASendTo(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, const SOCKADDR*, int, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern int (WINAPI* pWSARecv)(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern int WINAPI MyWSARecv(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern int (WINAPI* pWSARecvFrom)(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, SOCKADDR*, LPINT, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);
extern int WINAPI MyWSARecvFrom(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, SOCKADDR*, LPINT, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE);


extern T_SENDWS1 send_ws1;
extern T_RECVWS1 recv_ws1;
extern T_SENDWS2 send_ws2;
extern T_RECVWS2 recv_ws2;
extern T_SENDWSA send_wsa;
extern T_RECVWSA recv_wsa;

#endif


