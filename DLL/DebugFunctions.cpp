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

#include "stdafx.h"

// Convert integer to string (allocates needed memory)
char* itos( int n )
{
	char* s= (char*) malloc(12);// incluye signo y caracter nulo
	_itoa(n, s, 10);
	return s;
}

// Concatena strings (allocates needed memory)
char* strm( unsigned char count, ... )
{
    // new string from Multiple Strings
	va_list pL;
	va_start( pL, count );

	int i,length=0;
	char* string,*tmp;
	char** str = (char**) malloc(sizeof(void*)*count);
	int* len = (int*) malloc(sizeof(int)*count);

	for( i=0; i<count; i++ ){
		str[i]= va_arg( pL, char* );
		len[i]= strlen(str[i]);
		length+= len[i];
	}

	string = (char*) malloc(length+1);
	string[length]=0;
	tmp = string;

	for(i=0;i<count;i++){
		memcpy(tmp,str[i],len[i]);
		tmp+= len[i];
	}

	va_end(pL);
	return string;
}


char* GetSystemError( const char* msg ){

	char* Msg;

	// Retrieve the system error message for the last-error code
	DWORD e = GetLastError();
	LPSTR errorMsg;
	FormatMessageA( FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, NULL, e, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), (LPSTR)&errorMsg, 0, NULL );
    Msg= strm(6 , msg, "\nGetLastError(): Err# ", itos(e), "\n" , errorMsg, "\n" );
	LocalFree(errorMsg);

	return Msg;
}

//LOG
// Level es opcional, indica el nivel de detalle requerido para mostrar log
// VER Defines.h para los log de funciones
#define ERRORLEVEL 1

void errorLog(char* cStr, int level){

    if (level > ERRORLEVEL)
        return;

	//FILE* pFile;
	//fopen_s(&pFile, "C:\\DllErrorLog.txt", "a+");
	//fprintf(pFile, "%s", GetSystemError(cStr));
	//fclose(pFile);

	MessageBoxA(0,GetSystemError(cStr),"Error",MB_OK);

}


#include <iomanip>
#include <sstream>
const char * GetBufferAsHex(char * buf, int len){
      std::ostringstream Logger;
      Logger.str("");
     for ( int i = 0; i < len; ++i ) {
            Logger << std::hex << std::setw( 2 ) << std::setfill( '0' ) << ( int( buf[i] ) & 0xFF );
      }
      return Logger.str().data();
}