#include <windows.h>
#include <winuser.h>
#include <iomanip>
#include <sstream>
#include "ospefunc.h"


int ChangeIfMatch(char * buf, int len, TChangeList ChangeList){
      // reemplasos
      return 0;
}

void ShowMessage (const char *  cStr) {
        MessageBox( NULL, cStr , "OSPE", MB_ICONEXCLAMATION );
}

/*
	Function: GetBufferAsHex
	Propouse: Coverts the buffer data in ASCII to a hexadecimal representation.
	Parameters: buf: Pointer to a buffer
				len: Buffer length 
	Returns: Pointer to a null terminated string with data in hexadecimal.
*/
const char * GetBufferAsHex(char * buf, int len){
      std::ostringstream Logger;
      Logger.str("");
     for ( int i = 0; i < len; ++i ) {
            Logger << std::hex << std::setw( 2 ) << std::setfill( '0' ) << ( int( buf[i] ) & 0xFF );
      }
      return Logger.str().data();
}

/*
	Function: GetBufferAsHex
	Propouse: Coverts the buffer data in ASCII to a null terminated string.
	Parameters: buf: Pointer to a buffer
				len: Buffer length 
	Returns: Pointer to a null terminated string.
*/
const char * GetBufferAsText(char * buf, int len){
      char* str2 = new char[len+1];
	  for (int i=0; i<len; i++){
		if (buf[i]==0) 
			str2[i]=46;
		else
			str2[i]=buf[i];
	  }
      str2[len]= '\0';
      return str2;
}





