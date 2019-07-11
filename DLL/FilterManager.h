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

#ifndef FILTERMANAGER_H
#define FILTERMANAGER_H

#include "Defines.h"
#include <map>

enum FilterCaptureFuncs
{
	None = 0x0,
	WSSend = 0x1,
	WSSendTo = 0x2,
	WSRecv = 0x4,
	WSRecvFrom = 0x8,
	WS2Send = 0x10,
	WS2SendTo = 0x20,
	WS2Recv = 0x40,
	WS2RecvFrom = 0x80,
	WSA2Send = 0x100,
	WSA2SendTo = 0x200,
	WSA2Recv = 0x400,
	WSA2RecvFrom = 0x800
};

enum FilterModes
{
	SearchAndReplaceFromBegin,
	SearchOcurrenceReplaceFromBegin,
	SearchOcurrenceReplaceFromPosition
};

enum FilterActions
{
	Non = 0x0,
	Block = 0x1,
	Ignore = 0x2,
	Watch = 0x4,
	Break = 0x8
};

typedef struct
{
	bool Active;
	FilterModes Mode;
	FilterCaptureFuncs Functions;
	FilterActions Actions;
	UINT16 PacketLengthMin;
	UINT16 PacketLengthMax;
	UINT8 NumTimesApply;
	std::map<int, char> searches;
	std::map<int, char> replaces;
} Filter;

const short FILTERINBYTESSIZE = 3015;

extern Filter _filterList[50];
extern UINT8 filterCount;

void CovertBytesToFilterList(char *);
bool DoFilteringForPacket(char * data, UINT16 size, FilterCaptureFuncs functionFlag);
bool CheckPacketBlock(char * data, UINT16 size, FilterCaptureFuncs functionFlag);
bool CheckPacketBreak(char * data, UINT16 size, FilterCaptureFuncs functionFlag);

#endif // FILTERMANAGER_H