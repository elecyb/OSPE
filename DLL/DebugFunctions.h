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

// Print error string to file
void errorLog(char* cStr, int level=0);

// Convert integer to string (allocates needed memory)
char* itos( int n );

// Concatena strings (allocates needed memory)
char* strm( unsigned char count, ... );

char* GetSystemError( const char* msg );

const char * GetBufferAsHex(char * buf, int len);