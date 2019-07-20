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
#include "HookedFunctions.h"
#include "DllCommunication.h"
#include "Utils.h"

// Variables (function pointers)

PR_Write_Typedef PR_Write_Original;
PR_Read_Typedef PR_Read_Original;
PR_GetDescType_Typedef PR_GetDescType_Original;

SSL_Write_Typedef SSL_Write_Original;
SSL_Read_Typedef SSL_Read_Original;

SSLeay_Write_Typedef SSLeay_Write_Original;
SSLeay_Read_Typedef SSLeay_Read_Original;

PR_Send_Typedef PR_Send_Original;
PR_Recv_Typedef PR_Recv_Original;

SSH_Pktsend_Typedef SSH_Pktsend_Original;
SSH_Rdpkt_Typedef SSH_Rdpkt_Original;

SslEncryptPacket_Typedef SslEncryptPacket_Original;
SslDecryptPacket_Typedef SslDecryptPacket_Original;

EncryptMessage_Typedef EncryptMessage_Original;
DecryptMessage_Typedef DecryptMessage_Original;

PuttySend_Typedef PuttySend_Original;
PuttyRecv_Typedef PuttyRecv_Original;

SecureCRT_Typedef SecureCRT_Original;


// Estos son punteros a las funciones de la DLL Ex, si las define entonces se llaman en las funciones hook de OspeDll
T_SENDWS1 send_ws1 = NULL;
T_RECVWS1 recv_ws1 = NULL;
T_SENDWS2 send_ws2 = NULL;
T_RECVWS2 recv_ws2 = NULL;
T_SENDWSA send_wsa = NULL;
T_RECVWSA recv_wsa = NULL;


// PR_Write callback

int PR_Write_Callback(void* fd, void* buffer, DWORD amount)
{
	// Check if this is traffic
	if ((PR_GetDescType_Original(fd) == 2 || PR_GetDescType_Original(fd) == 4) && buffer != NULL)
		ProcessPacket(CODE_PR_WRITE, (char*&)buffer, (int&)amount);

	// Call original function
	return PR_Write_Original(fd, buffer, amount);
}

// PR_Read callback

int PR_Read_Callback(void* fd, void* buffer, DWORD amount)
{
	signed int ret = PR_Read_Original(fd, buffer, amount);
	// Do things
	if ((PR_GetDescType_Original(fd) == 2 || PR_GetDescType_Original(fd) == 4) && ret > 0)
			ProcessPacket(CODE_PR_READ, (char*&)buffer, (int&)ret);

	return ret;
}

// SSL_Write callback 64 bits

int SSL_Write_Callback(void* fd, void* buffer, int amount)
{
	ProcessPacket(CODE_SSL_WRITE, (char*&)buffer, amount);

	// Call original function
	return SSL_Write_Original(fd, buffer, amount);;
}

// SSL_Read callback 64 bits

int SSL_Read_Callback(void* fd, void* buffer, int amount)
{
	int ret = SSL_Read_Original(fd, buffer, amount);
	// Do things
	if (ret > 0) 
		ProcessPacket(CODE_SSL_READ, (char*&)buffer, amount);

	return ret;
}

// SSLeay_Write callback

int SSLeay_Write_Callback(void* fd, void* buffer, int amount)
{
	ProcessPacket(CODE_SSL_WRITE, (char*&)buffer, amount);

	// Call original function
	return SSLeay_Write_Original(fd, buffer, amount);;
}

// SSLeay_Read callback 

int SSLeay_Read_Callback(void* fd, void* buffer, int amount)
{
	int ret = SSLeay_Read_Original(fd, buffer, amount);
	// Do things
	if (ret > 0) 
		ProcessPacket(CODE_SSL_READ, (char*&)buffer, amount);

	return ret;
}

// PR_Send callback

int PR_Send_Callback(void* fd, const void* buf, int amount, int flags, DWORD timeout)
{
	LONG originalLen = amount;
	bool blocked = false;

	// Do things
	if (buf != NULL && amount > 0)
		ProcessPacket(CODE_PR_SEND, (char*&)buf, amount);

	// If blocked, don't call original function
	if (blocked)
		return originalLen;

	// Call original function
	return PR_Send_Original(fd, buf, amount, flags, timeout);;
}

// PR_Recv callback

int PR_Recv_Callback(void* fd, void* buf, int amount, int flags, DWORD timeout)
{
	signed int ret = PR_Recv_Original(fd, buf, amount, flags, timeout);
	// Do things
	if (ret > 0)
		ProcessPacket(CODE_PR_RECV, (char*&)buf, amount);

	return ret;
}

// SslEncryptPacket

LONG __stdcall SslEncryptPacket_Callback(ULONG_PTR hSslProvider, ULONG_PTR hKey, PBYTE* pbInput, DWORD cbInput, PBYTE pbOutput, DWORD cbOutput, DWORD* pcbResult, ULONGLONG SequenceNumber, DWORD dwContentType, DWORD dwFlags)
{
	// Do things
	if (pbInput != NULL && cbInput > 0)
	{
		ProcessPacket(CODE_SSLENCRYPTPACKET, (char*&)pbInput, (int&) cbInput);
	}

	// Call original function
	return SslEncryptPacket_Original(hSslProvider, hKey, pbInput, cbInput, pbOutput, cbOutput, pcbResult, SequenceNumber, dwContentType, dwFlags);;
}

// SslDecryptPacket

LONG __stdcall SslDecryptPacket_Callback(ULONG_PTR hSslProvider, ULONG_PTR hKey, PBYTE* pbInput, DWORD cbInput,
	PBYTE pbOutput, DWORD cbOutput, DWORD* pcbResult, ULONGLONG SequenceNumber, DWORD dwFlags)
{
	LONG res = SslDecryptPacket_Original(hSslProvider, hKey, pbInput, cbInput, pbOutput, cbOutput, pcbResult, SequenceNumber, dwFlags);
	// Do things
	if (pcbResult > 0)
		ProcessPacket(CODE_SSLDECRYPTPACKET, (char*& )pbOutput, (int&) pcbResult);

	return res;
}

// EncryptMessage

SECURITY_STATUS __stdcall EncryptMessage_Callback(PCtxtHandle phContext, ULONG fQOP, PSecBufferDesc pMessage, ULONG MessageSeqNo)
{
	SECURITY_STATUS res;

	// Do things


		if (pMessage->pBuffers != NULL && pMessage->cBuffers > 0)
		{
			for (DWORD i = 0; i < pMessage->cBuffers; i++)
			{
				SecBuffer buf = pMessage->pBuffers[i];
				if (buf.BufferType == SECBUFFER_DATA)
					ProcessPacket(CODE_ENCRYPTMESSAGE, (char*&)buf.pvBuffer, (int&) buf.cbBuffer);
			}
		}


	// Call original function

	res = EncryptMessage_Original(phContext, fQOP, pMessage, MessageSeqNo);


	return res;
}

// DecryptMessage

SECURITY_STATUS __stdcall DecryptMessage_Callback(PCtxtHandle phContext, PSecBufferDesc pMessage, ULONG MessageSeqNo, PULONG pfQOP)
{

	int ret = DecryptMessage_Original(phContext, pMessage, MessageSeqNo, pfQOP);

	// Do things


		if (ret == SEC_E_OK)
		{
			if (pMessage->pBuffers != NULL && pMessage->cBuffers > 0)
			{
				for (DWORD i = 0; i < pMessage->cBuffers; i++)
				{
					SecBuffer buf = pMessage->pBuffers[i];

					if (buf.BufferType == SECBUFFER_DATA)
						ProcessPacket(CODE_DECRYPTMESSAGE, (char*&)buf.pvBuffer, (int&)buf.cbBuffer);
				}
			}
		}

	return ret;
}

// PuttySend callback

void PuttySend_Callback(void* handle, char* buf, int len, int interactive)
{
	// If allowed
	if (buf != NULL)
		ProcessPacket(CODE_DECRYPTMESSAGE, (char*&)buf, (int&) len);

	// Call original function
	PuttySend_Original(handle, buf, len, interactive);
}

// PuttyRecv callback

int PuttyRecv_Callback(void* term, int is_stderr, const char* data, int len)
{
	signed int ret = PuttyRecv_Original(term, is_stderr, data, len);
	// Do things
	if (data != NULL) 
		ProcessPacket(CODE_DECRYPTMESSAGE, (char*&)data, (int&)len);
	
	return ret;
}

// SSH_Pktsend - WinSCP send callback

void __fastcall SSH_Pktsend_Callback(int datalen, unsigned char* data)
{
	DWORD pThis = 0;

	// Backup EAX register

#if defined _M_IX86
#ifdef _MSC_VER
	__asm { mov pThis, EAX }
#else 
	register unsigned long eax asm("eax");
	pThis = eax;
#endif
#endif 

	// If allowed
	if (data != NULL && datalen > 0) 
		ProcessPacket(CODE_DECRYPTMESSAGE, (char*&)data, (int&)datalen);

	// Restore EAX register

#if defined _M_IX86
#ifdef _MSC_VER
	__asm { mov EAX, pThis }
#else 
	eax = pThis;

#endif
#endif

	// Call original function
	SSH_Pktsend_Original(datalen, data);

}

// SSH_Rdpkt - WinSCP receive callback

int __fastcall SSH_Rdpkt_Callback(int datalen, unsigned char* data)
{
	DWORD pThis = 0;

	// Backup EAX register

#if defined _M_IX86
#ifdef _MSC_VER
	__asm { mov pThis, EAX }
#else 
	register unsigned long eax asm("eax");
	pThis = eax;
#endif 
#endif



	// Restore EAX register

#if defined _M_IX86
#ifdef _MSC_VER
	__asm { mov EAX, pThis }
#else 
	eax = pThis;
#endif 
#endif

	int ret = SSH_Rdpkt_Original(datalen, data);

	// Do things
   if (data != NULL && datalen > 0) 
	   ProcessPacket(CODE_DECRYPTMESSAGE, (char*&)data, (int&)datalen); 

	return ret;
}

// Targent Function Pointers ------------------------------------------------------------
#pragma region Function Pointers

int (WINAPI* pSend)(SOCKET s, const char* buf, int len, int flags) = NULL;
int WINAPI MySend(SOCKET s, const char* buf, int len, int flags);
int (WINAPI* pSendTo)(SOCKET s, const char* buf, int len, int flags, const SOCKADDR* to, int tolen) = NULL;
int WINAPI MySendTo(SOCKET s, const char* buf, int len, int flags, const SOCKADDR* to, int tolen);
int (WINAPI* pRecv)(SOCKET s, char* buf, int len, int flags) = NULL;
int WINAPI MyRecv(SOCKET s, char* buf, int len, int flags);
int (WINAPI* pRecvFrom)(SOCKET s, char* buf, int len, int flags, SOCKADDR* from, int* fromlen) = NULL;
int WINAPI MyRecvFrom(SOCKET s, char* buf, int len, int flags, SOCKADDR* from, int* fromlen);

int (WINAPI* pWS2Send)(SOCKET s, const char* buf, int len, int flags) = NULL;
int WINAPI MyWS2Send(SOCKET s, const char* buf, int len, int flags);
int (WINAPI* pWS2SendTo)(SOCKET s, const char* buf, int len, int flags, const SOCKADDR* to, int tolen) = NULL;
int WINAPI MyWS2SendTo(SOCKET s, const char* buf, int len, int flags, const SOCKADDR* to, int tolen);
int (WINAPI* pWS2Recv)(SOCKET s, char* buf, int len, int flags) = NULL;
int WINAPI MyWS2Recv(SOCKET s, char* buf, int len, int flags);
int (WINAPI* pWS2RecvFrom)(SOCKET s, char* buf, int len, int flags, SOCKADDR* from, int* fromlen) = NULL;
int WINAPI MyWS2RecvFrom(SOCKET s, char* buf, int len, int flags, SOCKADDR* from, int* fromlen);

int (WINAPI* pWSASend)(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSASend(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
int (WINAPI* pWSASendTo)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const SOCKADDR* lpTo, int iToLen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSASendTo(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const SOCKADDR* lpTo, int iToLen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
int (WINAPI* pWSARecv)(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSARecv(SOCKET socket, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);
int (WINAPI* pWSARecvFrom)(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, SOCKADDR* lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) = NULL;
int WINAPI MyWSARecvFrom(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, SOCKADDR* lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine);

#pragma endregion
//-----------------------------------------------------------------------------------

//  Hooking functions ----------------------------------------------------------------------
#pragma region Hooks

// WS 1.1 SEND
int WINAPI MySend(SOCKET s, const char* buf, int len, int flags)
{
	int originalLen = len;
	bool blocked = false;
	ProcessPacket(CODE_SEND, (char*&)buf, len, s, blocked);

	if (send_ws1 != NULL)
		(send_ws1)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	// If blocked, don't call original function
	if (blocked)
		return originalLen;

	pSend(s, buf, len, flags);
	return originalLen;
}
// WS 1.1 SEND TO
int WINAPI MySendTo(SOCKET s, const char* buf, int len, int flags, const SOCKADDR* to, int tolen)
{
	bool blocked = false;
	ProcessPacket(CODE_SENDTO, (char*&)buf, len, s, blocked);

	// If blocked, don't call original function
	if (blocked)
		return NULL;

	return pSendTo(s, buf, len, flags, to, tolen);
}
// WS 1.1 RECV
int WINAPI MyRecv(SOCKET s, char* buf, int len, int flags)
{
	bool blocked = false;
	int ret = pRecv(s, buf, len, flags);

	if (ret != SOCKET_ERROR)
		ProcessPacket(CODE_RECV, buf, ret, s, blocked);

	if (recv_ws1 != NULL)
		(recv_ws1)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	return ret;

}
// WS 1.1 RECV FROM
int WINAPI MyRecvFrom(SOCKET s, char* buf, int len, int flags, SOCKADDR* from, int* fromlen)
{
	bool blocked = false;
	int ret = pRecvFrom(s, buf, len, flags, from, fromlen);
	if (ret != SOCKET_ERROR)
		ProcessPacket(CODE_RECVFROM, buf, ret, s, blocked);

	return ret;
}


// WS 2.0 SEND
int WINAPI MyWS2Send(SOCKET s, const char* buf, int len, int flags) {
	int originalLen = len;
	bool blocked = false;
	ProcessPacket(CODE_WS2SEND, (char*&)buf, len, s, blocked);
	if (send_ws2 != NULL)
		(send_ws2)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	// If blocked, don't call original function
	if (blocked)
		return NULL;

	pWS2Send(s, buf, len, flags);
	return originalLen;
}
// WS 2.0 SEND TO
int WINAPI MyWS2SendTo(SOCKET s, const char* buf, int len, int flags, const SOCKADDR* to, int tolen) {
	bool blocked = false;
	ProcessPacket(CODE_WS2SENDTO, (char*&)buf, len, s, blocked);

	// If blocked, don't call original function
	if (blocked)
		return NULL;

	return pWS2SendTo(s, buf, len, flags, to, tolen);
}
// WS 2.0 RECV
int WINAPI MyWS2Recv(SOCKET s, char* buf, int len, int flags) {
	bool blocked = false;
	int ret = pWS2Recv(s, buf, len, flags);
	if (ret != SOCKET_ERROR)
		ProcessPacket(CODE_WS2RECV, buf, ret, s, blocked);
	if (recv_ws2 != NULL)
		(recv_ws2)(s, buf, len, flags, NULL, NULL, NULL, NULL, NULL);

	return ret;
}
// WS 2.0 RECV FROM
int WINAPI MyWS2RecvFrom(SOCKET s, char* buf, int len, int flags, SOCKADDR* from, int* fromlen) {
	bool blocked = false;
	int ret = pWS2RecvFrom(s, buf, len, flags, from, fromlen);
	if (ret != SOCKET_ERROR)
		ProcessPacket(CODE_WS2RECVFROM, buf, ret, s, blocked);

	return ret;
}


// WSA SEND
int WINAPI MyWSASend(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
	bool blocked = false;
	for (DWORD i = 0; i < dwBufferCount; i++) {
		ProcessPacket(CODE_WSASEND, lpBuffers[i].buf, (int&)lpBuffers[i].len, s, blocked);
	}

	// If blocked, don't call original function
	if (blocked)
		return NULL;

	return pWSASend(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpOverlapped, lpCompletionRoutine);
}
// WSA SEND TO
int WINAPI MyWSASendTo(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesSent, DWORD dwFlags, const SOCKADDR* lpTo, int iToLen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
	bool blocked = false;
	for (DWORD i = 0; i < dwBufferCount; i++) {
		ProcessPacket(CODE_WSASENDTO, lpBuffers[i].buf, (int&)lpBuffers[i].len, s, blocked);
	}

	// If blocked, don't call original function
	if (blocked)
		return NULL;

	return pWSASendTo(s, lpBuffers, dwBufferCount, lpNumberOfBytesSent, dwFlags, lpTo, iToLen, lpOverlapped, lpCompletionRoutine);
}
// WSA RECV
int WINAPI MyWSARecv(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
	bool blocked = false;
	int ret = pWSARecv(s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpOverlapped, lpCompletionRoutine);
	if (ret != SOCKET_ERROR) {
		if (lpNumberOfBytesRecvd != NULL) {
			DWORD bytesRecvd = *lpNumberOfBytesRecvd;
			DWORD bufferDataSize;
			for (DWORD i = 0; i < dwBufferCount; i++)
			{
				bufferDataSize = (bytesRecvd > lpBuffers[i].len) ? lpBuffers[i].len : bytesRecvd;
				ProcessPacket(CODE_WSARECV, lpBuffers[i].buf, (int&)bufferDataSize, s, blocked);

				bytesRecvd -= bufferDataSize;
				if (!bytesRecvd)
					break;
			}
		}
		else {
			Utils::errorLog("CODE_WASA_lpNumberOfBytesRecvd_NULL");
		}
	}

	return ret;
}
// WSA RECV FROM
int WINAPI MyWSARecvFrom(SOCKET s, LPWSABUF lpBuffers, DWORD dwBufferCount, LPDWORD lpNumberOfBytesRecvd, LPDWORD lpFlags, SOCKADDR* lpFrom, LPINT lpFromlen, LPWSAOVERLAPPED lpOverlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE lpCompletionRoutine) {
	bool blocked = false;
	int ret = pWSARecvFrom(s, lpBuffers, dwBufferCount, lpNumberOfBytesRecvd, lpFlags, lpFrom, lpFromlen, lpOverlapped, lpCompletionRoutine);
	if (ret != SOCKET_ERROR) {
		if (lpNumberOfBytesRecvd != NULL) {
			DWORD bytesRecvd = *lpNumberOfBytesRecvd;
			DWORD bufferDataSize;
			for (DWORD i = 0; i < dwBufferCount; i++) {
				bufferDataSize = (bytesRecvd > lpBuffers[i].len) ? lpBuffers[i].len : bytesRecvd;
				ProcessPacket(CODE_WSARECVFROM, lpBuffers[i].buf, (int&)bufferDataSize, s, blocked);

				bytesRecvd -= bufferDataSize;
				if (!bytesRecvd)
					break;
			}
		}
		else {
			Utils::errorLog("CODE_WASA_lpNumberOfBytesRecvd_NULL");
		}
	}

	return ret;
}

#pragma endregion

//-----------------------------------------------------------------------------------