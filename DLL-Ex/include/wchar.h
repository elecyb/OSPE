/* WCHAR.H - Most of this stuff is in TCHAR.H, so we include that */

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1997, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1  $ */

#ifndef __WCHAR_H
#define __WCHAR_H

#if !defined(__TCHAR_H)
#  include <tchar.h>
#endif

#define wmemcpy _wmemcpy
#define wmemchr _wmemchr
#define wmemset _wmemset

#endif /* __WCHAR_H */