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

#ifndef _PROCESS_H_
#define _PROCESS_H_

#include <string>
#include <vector>
#include <windows.h>
#include <tlhelp32.h> 
#include "Utils.h"

using namespace std;

// Address type

#if defined _M_X64
#define ADDRESS_VALUE uint64_t
#elif defined _M_IX86
#define ADDRESS_VALUE uint32_t
#endif

// Struct for sections

struct SECTION_INFO
{
	ADDRESS_VALUE dwStartAddress;
	DWORD dwSize;
};

// Struct for exports

struct EXPORT_ENTRY
{
	ADDRESS_VALUE dwAddress;
	ADDRESS_VALUE dwPointerOfAddress;
	string sName;
	USHORT uOrdinal;
};

// Process and PE stuff

class Process
{
public:
	static vector<MODULEENTRY32> GetProcessModules(DWORD p_dwID);
	static SECTION_INFO GetModuleSection(string p_sModule, string p_sSection);
	static ADDRESS_VALUE SearchMemory(void* p_pvStartAddress, DWORD p_dwSize, void* p_pvBuffer, DWORD p_dwBufferSize);
	static ADDRESS_VALUE SearchSignature(void* p_pvStartAddress, DWORD p_dwSize, void* p_pvBuffer, DWORD p_dwBufferSize);
};

#endif


