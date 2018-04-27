/*  mem.h

    Memory manipulation functions

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4.1.0  $ */

#if !defined(__MEM_H)
#define __MEM_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */


#ifdef __cplusplus
extern "C" {
#endif

/* Intrinsic functions, defined outside of the namespace */

void _FAR * _RTLENTRY  _EXPFUNC16 __memchr__(const void _FAR * __s, int __c, _SIZE_T __n);
int         _RTLENTRY  _EXPFUNC16 __memcmp__(const void _FAR * __s1, const void _FAR * __s2, _SIZE_T __n);
void _FAR * _RTLENTRY  _EXPFUNC16 __memcpy__(void _FAR * __dest, const void _FAR * __src, _SIZE_T __n);
void _FAR * _RTLENTRYF _EXPFUNC16 __memset__(void _FAR * __s, int __c, _SIZE_T __n);

#ifdef __cplusplus
namespace std {
#endif

void _FAR * _RTLENTRY  _EXPFUNC memccpy(void _FAR *__dest, const void _FAR *__src,
                                        int __c, _SIZE_T __n);
int         _RTLENTRY  _EXPFUNC memcmp(const void _FAR *__s1, const void _FAR *__s2,
                                       _SIZE_T __n);
void _FAR * _RTLENTRY  _EXPFUNC memcpy(void _FAR *__dest, const void _FAR *__src,
                                       _SIZE_T __n);
int         _RTLENTRY  _EXPFUNC memicmp(const void _FAR *__s1, const void _FAR *__s2,
                                        _SIZE_T __n);
void _FAR * _RTLENTRYF _EXPFUNC memmove(void _FAR *__dest, const void _FAR *__src,
                                        _SIZE_T __n);
void _FAR * _RTLENTRYF _EXPFUNC memset(void _FAR *__s, int __c, _SIZE_T __n);

void *          _RTLENTRY  _EXPFUNC _wmemset(void *__s, int __c, _SIZE_T __n);
void *          _RTLENTRY  _EXPFUNC _wmemcpy(void *__dest, const void *__src, _SIZE_T __n);

#if defined(__cplusplus)
extern "C++"
{
          void _FAR * _RTLENTRY _EXPFUNC32 memchr(void _FAR *__s, int __c, _SIZE_T __n);
    const void _FAR * _RTLENTRY _EXPFUNC32 memchr(const void _FAR *__s, int __c, _SIZE_T __n);
          void      * _RTLENTRY _EXPFUNC32 _wmemchr(void *__s, int __c, _SIZE_T __n);
    const void      * _RTLENTRY _EXPFUNC32 _wmemchr(const void *__s, int __c, _SIZE_T __n);
}
#else
          void _FAR * _RTLENTRY _EXPFUNC32 memchr(const void _FAR *__s, int __c, _SIZE_T __n);
          void      * _RTLENTRY _EXPFUNC32 _wmemchr(const void *__s, int __c, _SIZE_T __n);
#endif



#define movmem(src,dest,length) (void)memmove(dest,src,length)
#define setmem(dest,length,value) (void)memset(dest,value,length)

#if !defined(__STDC__) /* NON_ANSI  */
#define _fmemccpy memccpy
#define _fmemchr  memchr
#define _fmemcmp  memcmp
#define _fmemcpy  memcpy
#define _fmemicmp memicmp
#define _fmemmove memmove
#define _fmemset  memset
#define _fmovmem  movmem
#define _fsetmem  setmem
#endif /* __STDC__  */

#ifdef __cplusplus
} // std
} // extern "C"
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __MEM_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__MEM_H_USING_LIST)
#define __MEM_H_USING_LIST
   using std::_wmemchr;
   using std::_wmemcpy;
   using std::_wmemset;
   using std::memccpy;
   using std::memicmp;
   using std::memmove;

/*
   Handle intrinsics specially.  If intrinsics are on, the compiler creates
   a macro of the normal function mapping to the __ intrinsic version, ie:
     #define strcpy __strcpy__
   Thus, we can test the normal name as a macro to see if it's defined, and
   only preform a using statement if it's not an intrinsic
*/

#  ifndef memchr
     using std::memchr;
#  endif // ifndef memchr
#  ifndef memcmp
     using std::memcmp;
#  endif // ifndef memcmp
#  ifndef memcpy
     using std::memcpy;
#  endif // ifndef memcpy
#  ifndef memset
     using std::memset;
#  endif // ifndef memset

#endif /* __USING_CNAME__ */