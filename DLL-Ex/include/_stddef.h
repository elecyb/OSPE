/*  _stddef.h

    multi-includable Definitions for common types, and NULL

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $ */

#ifndef ___STDDEF_H
#define ___STDDEF_H

#if !defined(___DEFS_H)
#include <_defs.h>
#endif

#ifndef NULL
#include <_null.h>
#endif

/* Full locale support is on by default now.  To get the previous behavior,
   define __SIMPLE_LOCALES__
*/
#ifndef __SIMPLE_LOCALES__
#define __USELOCALES__
#endif

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

/* Define __STD to expand to std:: or nothing depending on being in C++. */
#ifdef __cplusplus
#  define __STD std::
#else
#  define __STD
#endif

/*
   Define the size_t type in the std namespace if in C++ or globally if in C.
   If we're in C++, make the _SIZE_T macro expand to std::size_t
*/

#if !defined(_SIZE_T) && !defined(_SIZE_T_DEFINED)
#  define _SIZE_T_DEFINED
   typedef unsigned int size_t;
#  if defined(__cplusplus)
#    define _SIZE_T std::size_t
#  else
#    define _SIZE_T size_t
#  endif
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifndef _PTRDIFF_T
#define _PTRDIFF_T
typedef int     ptrdiff_t;
#endif


#define offsetof( s_name, m_name )  (_SIZE_T)&(((s_name _FAR *)0)->m_name)

#ifndef __cplusplus
#if !defined(_WCHAR_T) && !defined(_WCHAR_T_DEFINED)
#define _WCHAR_T
#define _WCHAR_T_DEFINED  /* For WINDOWS.H */
typedef unsigned short wchar_t;
#endif
#endif

/*
   Define the wint_t type in the std namespace if in C++ or globally if in C.
   If we're in C++, make the _WINT_T macro expand to std::wint_t
*/

#if !defined(_WINT_T)
typedef wchar_t wint_t;
#  ifdef __cplusplus
#    define _WINT_T std::wint_t
#  else
#    define _WINT_T wint_t
#  endif
#endif

#ifndef _WCTYPE_T_DEFINED
typedef wchar_t wctype_t;
#define _WCTYPE_T_DEFINED
#endif

#ifdef __cplusplus
extern "C" {
#endif
extern unsigned long _RTLENTRY _EXPFUNC __threadid(void);
#define _threadid (__threadid())

#ifdef  __cplusplus
}
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* __STDDEF_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(___STDDEF_H_USING_LIST)
#define ___STDDEF_H_USING_LIST
     using std::ptrdiff_t;
     using std::__threadid;
     using std::size_t;
     using std::wint_t;
     using std::wctype_t;
#endif /* __USING_CNAME__ */
