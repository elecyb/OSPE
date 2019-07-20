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
#include "NonExportedHooks.h"

bool Is32BitProcess()
{
	if (sizeof(void*) == 4) return true;
	else return false;
}

// Chrome 64

void HookChrome(string p_sModule)
{
	SECTION_INFO rdata = { 0, 0 };
	SECTION_INFO text = { 0, 0 };

	// 64 bits signatures

	unsigned char Write_Signature64[] = {
		0x41, 0x56, 0x56, 0x57, 0x55, 0x53, 0x48, 0x83, 0xEC, 0x40, 0x44, 0x89, 0xC6, 0x48, 0x89, 0xD7,
		0x48, 0x89, 0xCB, 0x48, 0x8B, 0x05, '?' , '?' , '?' , '?' , 0x48, 0x31, 0xE0, 0x48, 0x89, 0x44 };
	unsigned char Read_Signature64[] = {
		0x56, 0x57, 0x53, 0x48, 0x83, 0xEC, 0x20, 0x44, 0x89, 0xC6, 0x48, 0x89, 0xD7, 0x48, 0x89, 0xCB,
		0xE8, '?' , '?' , '?' , '?' , 0x85, 0xC0, 0x7E, '?' , 0x85, 0xF6, 0x7E, '?' , 0x48, 0x63, 0xCE };

	// 32 bits signatures

	unsigned char Write_Signature32[] = {
		0x55, 0x89, 0xE5, 0x53, 0x57, 0x56, 0x83, 0xEC, 0x08, 0xA1, '?' , '?' , '?' , '?' , 0x8B, 0x7D,
		0x08, 0x31, 0xE8, 0x89, 0x45, 0xF0, 0x8B, 0x47, 0x18, 0xC7, 0x80, 0x98, 0x00, 0x00, 0x00, 0x01 };
	unsigned char Read_Signature32[] = {
		0x55, 0x89, 0xE5, 0x57, 0x56, 0x8B, 0x7D, 0x08, 0xFF, 0x75, 0x10, 0xFF, 0x75, 0x0C, 0x57, 0xE8,
		'?' , '?' , '?' , '?' , 0x83, 0xC4, 0x0C, 0x89, 0xC6, 0x85, 0xC0, 0x7E, 0x21, 0x8B, 0x47, 0x18 };

	// Get section

	text = Process::GetModuleSection(p_sModule, ".text");

	// Check if chrome

	if (text.dwSize == 0 || text.dwStartAddress == 0)
	{
		Utils::errorLog("[ERROR] Cannot get Chrome text section!");
		return;
	}

	// We have the x86 versions

	if (Is32BitProcess())
	{
		// Search memory

		ADDRESS_VALUE pWrite32 = Process::SearchSignature((void*)text.dwStartAddress, text.dwSize, (void*)Write_Signature32, sizeof(Write_Signature32));
		ADDRESS_VALUE pRead32 = Process::SearchSignature((void*)text.dwStartAddress, text.dwSize, (void*)Read_Signature32, sizeof(Read_Signature32));

		if (pRead32 == 0 || pWrite32 == 0)
		{
			Utils::errorLog("[ERROR] Cannot get Chrome SSL functions!");
			return;
		}

		// Add hooks

		SSL_Write_Original = (SSL_Write_Typedef)pWrite32;
		SSL_Read_Original = (SSL_Read_Typedef)pRead32;

		MH_CreateHook((void*)pWrite32, (void*)SSL_Write_Callback, (void**)& SSL_Write_Original);
		MH_CreateHook((void*)pRead32, (void*)SSL_Read_Callback, (void**)& SSL_Read_Original);

		return;
	}
	else
	{
		// Search memory

		ADDRESS_VALUE pWrite64 = Process::SearchSignature((void*)text.dwStartAddress, text.dwSize, (void*)Write_Signature64, sizeof(Write_Signature64));
		ADDRESS_VALUE pRead64 = Process::SearchSignature((void*)text.dwStartAddress, text.dwSize, (void*)Read_Signature64, sizeof(Read_Signature64));

		if (pRead64 == 0 || pWrite64 == 0)
		{
			Utils::errorLog("[ERROR] Cannot get Chrome SSL functions!");
			return;
		}

		// Add hooks

		SSL_Write_Original = (SSL_Write_Typedef)pWrite64;
		SSL_Read_Original = (SSL_Read_Typedef)pRead64;

		MH_CreateHook((void*)pWrite64, (void*)SSL_Write_Callback, (void**)& SSL_Write_Original);
		MH_CreateHook((void*)pRead64, (void*)SSL_Read_Callback, (void**)& SSL_Read_Original);

		return;
	}
}
