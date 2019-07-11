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

#ifndef WEPEDLL_H
#define WEPEDLL_H

#include <string>
#include <vector>
#include <winsock2.h>
#include <Windows.h>
#include <tlhelp32.h> 
#include "ipc.h"

extern bool isCapturing;
extern bool isFiltering;

extern HMODULE hDllEx;
extern HANDLE hMainThread;

void LoadDllEx(LPCSTR lpFileName);
void UnLoadDllEx();

// Create the IPC client
static osIPC::Server server;


#endif // WEPEDLL_H
