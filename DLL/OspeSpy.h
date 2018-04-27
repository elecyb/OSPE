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

#ifndef WEPESPY_H
#define WEPESPY_H

#include <winsock2.h>
#include <Windows.h>
#include "ipc.h"

typedef void(__stdcall *T_SENDWS1)(SOCKET, const char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall *T_RECVWS1)(SOCKET, char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall *T_SENDWS2)(SOCKET, const char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall *T_RECVWS2)(SOCKET, char*, int, int, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall *T_SENDWSA)(SOCKET, LPWSABUF, DWORD, LPDWORD, DWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE, LPVOID, LPVOID, LPVOID, LPVOID, bool);
typedef void(__stdcall *T_RECVWSA)(SOCKET, LPWSABUF, DWORD, LPDWORD, LPDWORD, LPWSAOVERLAPPED, LPWSAOVERLAPPED_COMPLETION_ROUTINE, LPVOID, LPVOID, LPVOID, LPVOID, bool);

// Variables Globales
extern T_SENDWS1 send_ws1;
extern T_RECVWS1 recv_ws1;
extern T_SENDWS2 send_ws2;
extern T_RECVWS2 recv_ws2;
extern T_SENDWSA send_wsa;
extern T_RECVWSA recv_wsa;

extern bool isCapturing;
extern bool isFiltering;

extern HMODULE hDllEx;
extern HANDLE hMainThread;

void LoadDllEx(LPCSTR lpFileName);
void UnLoadDllEx();

// Create the IPC client
static osIPC::Server server;


#endif
