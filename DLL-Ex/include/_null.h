/*  _null.h

    Definition of NULL.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $ */

#ifndef NULL
#  if defined(__cplusplus) || defined(_Windows)
#    define NULL 0
#  else
#    define NULL ((void *)0)
#  endif
#endif

