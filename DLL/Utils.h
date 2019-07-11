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

#ifndef _UTILS_H_
#define _UTILS_H_

#include <string>
#include <cstdio>
#include <sstream>
#include <vector>
#include <cstdint>
#include <winsock2.h>

using namespace std;

#pragma comment(lib, "Ws2_32.lib")

// Used to get IP/Port info

struct IPInfo
{
	uint32_t nSrcIP;
	uint32_t nDstIP;
	uint16_t nSrcPort;
	uint16_t nDstPort;
};

// Defines

#define MAX_TEMP_PATH 300

// Some useful stuff

class Utils
{
public:

	static string ToLower(string p_sString);
	static string IntToString(unsigned int p_nNumer);
	static string IntToHex(unsigned int p_nNumer);
	static unsigned int StringToInt(string p_sNumer);
	static string GetStringBetween(string p_sString, string p_sStart, string p_sStop);
	static vector<string> SplitString(string p_sString, string p_sDelimiter);
	static bool Is32BitProcess();
	static IPInfo GetIPInfo(unsigned int p_nSocket);

	// Print error string to file
	static void errorLog(char* cStr, int level = 0);
	// Concatena strings (allocates needed memory)
	static char* strm(unsigned char count, ...);
	static char* GetSystemError(const char* msg);
	static const char* GetBufferAsHex(char* buf, int len);
};

#endif
