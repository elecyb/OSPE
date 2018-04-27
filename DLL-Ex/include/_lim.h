/*  _lim.h - Internal version of "C" limits.h header

    Defines implementation specific limits on type values.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */


#ifndef __LIMITS_H
#define __LIMITS_H
#define _INC_LIMITS  /* MSC Guard name */

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#define CHAR_BIT        8               /* number of bits in a char */
#define MB_LEN_MAX      2               /* max. # bytes in multibyte char */

#define SCHAR_MIN     (-128)            /* minimum signed   char value */
#define SCHAR_MAX       127             /* maximum signed   char value */
#define UCHAR_MAX       255             /* maximum unsigned char value */

#if ('\x80' < 0)
#define CHAR_MIN        SCHAR_MIN       /* minimum char value */
#define CHAR_MAX        SCHAR_MAX       /* maximum char value */
#else
#define CHAR_MIN        0
#define CHAR_MAX        UCHAR_MAX
#endif

#define SHRT_MIN      (-32767-1)        /* minimum signed   short value */
#define SHRT_MAX        32767           /* maximum signed   short value */
#define USHRT_MAX       65535U          /* maximum unsigned short value */

#define LONG_MIN      (-2147483647L-1)  /* minimum signed   long value */
#define LONG_MAX        2147483647L     /* maximum signed   long value */
#define ULONG_MAX       4294967295UL    /* maximum unsigned long value */

#if defined (_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
#define _I64_MIN      (-9223372036854775807i64-1) /* minimum signed   __int64 value */
#define _I64_MAX        9223372036854775807i64    /* maximum signed   __int64 value */
#define _UI64_MAX       18446744073709551615ui64  /* maximum unsigned __int64 value */
#endif

#define INT_MIN         LONG_MIN        /* minimum signed   int value */
#define INT_MAX         LONG_MAX        /* maximum signed   int value */
#define UINT_MAX        ULONG_MAX       /* maximum unsigned int value */

#if defined(_POSIX_)

#define _POSIX_ARG_MAX          4096
#define _POSIX_CHILD_MAX        6
#define _POSIX_LINK_MAX         8
#define _POSIX_MAX_CANON        255
#define _POSIX_MAX_INPUT        255
#define _POSIX_NAME_MAX         14
#define _POSIX_NGROUPS_MAX      0
#define _POSIX_OPEN_MAX         16
#define _POSIX_PATH_MAX         255
#define _POSIX_PIPE_BUF         512
#define _POSIX_SSIZE_MAX        32767
#define _POSIX_STREAM_MAX       8
#define _POSIX_TZNAME_MAX       3

#define ARG_MAX                 (16384 - 256)   /* 16k-(heap overhead+safety) */
#define CHILD_MAX               32
#define LINK_MAX                _POSIX_LINK_MAX
#define MAX_CANON               _POSIX_MAX_CANON
#define MAX_INPUT               _POSIX_MAX_INPUT
#define NAME_MAX                255
#define NGROUPS_MAX             16
#define OPEN_MAX                32
#define PATH_MAX                512
#define PIPE_BUF                _POSIX_PIPE_BUF
#define SSIZE_MAX               _POSIX_SSIZE_MAX
#define STREAM_MAX              20
#define TZNAME_MAX              10

#endif /* POSIX */
#endif  /* __LIMITS_H */