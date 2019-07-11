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

#ifndef DLLCOMMUNICATION_H
#define DLLCOMMUNICATION_H

#include <ws2tcpip.h>
#include "Defines.h"


#define SOCKET_ERROR            (-1)
#define IPV4 0
#define IPV6 128


void SetInfo(SOCKET socket, Functions functionId, int length, PacketInfo* info);
void ProcessPacket(Functions functionId, char*& buffer, int& length, SOCKET socket, bool& blocked);
void ProcessPacket(Functions functionId, char*& buffer, int& length);

DWORD WINAPI Command_Reader(LPVOID context);

#endif // DLLCOMMUNICATION_H