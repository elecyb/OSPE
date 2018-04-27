/*  cstring.h

    Standard C header file wrapper for string.h
*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1997, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $ */

#define  __USING_CNAME__
#include <_str.h>
#if !defined(__USING_STD_NAMES__) && !defined(__STD_STRING)
/* Include the STL string class for backwards support if the user includes
   <cstring.h>.  Else this is an include of <cstring> and our previous include
   of _str.h will suffice.
*/
#  undef   __USING_CNAME__
#  include <string.stl>
   using std::string;
#endif  /* __USING_STD_NAMES__ */

#undef   __USING_CNAME__
