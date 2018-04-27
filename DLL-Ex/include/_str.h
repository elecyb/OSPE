/*  _str.h internal version of "C" string.h functions

    Definitions for string functions.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.1.1.0  $ */

#ifndef __STRING_H
#define __STRING_H
#define _INC_STRING  /* MSC Guard name */

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(__STDC__) && defined(__USELOCALES__)
#if !defined(__LOCALE_H)
#include <locale.h>
#endif
#endif  /* !__STDC__ && __USELOCALES__ */

#if !defined(RC_INVOKED)

#ifndef __MEM_H
#include <mem.h>  /* All mem... functions have now been moved to MEM.H */
#endif

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

#define wcscmpi(s1,s2)      _wcsicmp(s1,s2)
#define _wcscmpi(s1,s2)     _wcsicmp(s1,s2)
#define wcsncmpi(s1,s2,n)   _wcsnicmp(s1,s2,n)
#define _wcsncmpi(s1,s2,n)  _wcsnicmp(s1,s2,n)

_SIZE_T          _RTLENTRY  _EXPFUNC wcslen(const wchar_t *__s);
wchar_t *       _RTLENTRY  _EXPFUNC wcscpy(wchar_t *__dst, const wchar_t *__src);
wchar_t *       _RTLENTRY  _EXPFUNC wcscat(wchar_t *__dest, const wchar_t *__src);
wchar_t *       _RTLENTRY  _EXPFUNC wcschr(const wchar_t *__s, int __c);
int             _RTLENTRY  _EXPFUNC wcscmp(const wchar_t *__s1, const wchar_t *__s2);
int             _RTLENTRY  _EXPFUNC wcscoll(const wchar_t * __s1, const wchar_t * __s2);
_SIZE_T          _RTLENTRY  _EXPFUNC wcscspn(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsdup(const wchar_t *__s);
int             _RTLENTRY  _EXPFUNC wcsncmp(const wchar_t *__s1, const wchar_t *__s2, _SIZE_T __maxlen);
wchar_t *       _RTLENTRY  _EXPFUNC wcsncpy(wchar_t *__dest, const wchar_t *__src, _SIZE_T __maxlen);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsnset(wchar_t *__s, wchar_t __ch, _SIZE_T __n);
wchar_t *       _RTLENTRY  _EXPFUNC wcspbrk(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcsrchr(const wchar_t *__s, wchar_t __c);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsrev(wchar_t *__s);
wchar_t *       _RTLENTRY  _EXPFUNC _wcsset(wchar_t*__s, wchar_t __ch);
_SIZE_T          _RTLENTRY  _EXPFUNC wcsspn(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcsstr(const wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcstok(wchar_t *__s1, const wchar_t *__s2);
wchar_t *       _RTLENTRY  _EXPFUNC wcsncat(wchar_t *__dest, const wchar_t *__src, _SIZE_T __maxlen);
wchar_t *       _RTLENTRY  _EXPFUNC wcspcpy(wchar_t *__dest, const wchar_t *__src);
wchar_t *       _RTLENTRY  _EXPFUNC _wcspcpy(wchar_t *__dest, const wchar_t *__src);
int             _RTLENTRY  _EXPFUNC _wcsicmp(const wchar_t *__s1, const wchar_t *__s2);
int             _RTLENTRY  _EXPFUNC _wcsnicmp(const wchar_t *__s1, const wchar_t *__s2, _SIZE_T __maxlen);
wchar_t *       _RTLENTRYF _EXPFUNC _wcslwr(wchar_t *__s);
wchar_t *       _RTLENTRYF _EXPFUNC _wcsupr(wchar_t *__s);
wchar_t *       _RTLENTRYF _EXPFUNC _lwcslwr(wchar_t *__s);
wchar_t *       _RTLENTRYF _EXPFUNC _lwcsupr(wchar_t *__s);

char _FAR * _RTLENTRYF _EXPFUNC strcat(char _FAR *__dest, const char _FAR *__src);
int         _RTLENTRYF _EXPFUNC strcmp(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC strcpy(char _FAR *__dest, const char _FAR *__src);
_SIZE_T      _RTLENTRY  _EXPFUNC strcspn(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRY  _EXPFUNC strerror(int __errnum);
_SIZE_T      _RTLENTRYF _EXPFUNC strlen(const char _FAR *__s);
char _FAR * _RTLENTRYF _EXPFUNC strncat(char _FAR *__dest, const char _FAR *__src,
                                        _SIZE_T __maxlen);
int         _RTLENTRYF _EXPFUNC strncmp(const char _FAR *__s1, const char _FAR *__s2,
                                        _SIZE_T __maxlen);
char _FAR * _RTLENTRYF _EXPFUNC strncpy(char _FAR *__dest, const char _FAR *__src,
                                        _SIZE_T __maxlen);
_SIZE_T      _RTLENTRY  _EXPFUNC strspn(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC strtok(char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRY  _EXPFUNC _strerror(const char _FAR *__s);


#if !defined(__STDC__)
/* compatibility with other compilers */
#define strcmpi(s1,s2)      stricmp(s1,s2)
#define strncmpi(s1,s2,n)   strnicmp(s1,s2,n)

char _FAR * _RTLENTRYF _EXPFUNC   _lstrlwr(char _FAR *__s);
char _FAR * _RTLENTRYF _EXPFUNC   _lstrupr(char _FAR *__s);
char _FAR * _RTLENTRYF _EXPFUNC32 stpcpy(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _EXPFUNC32 _stpcpy(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _EXPFUNC   strdup(const char _FAR *__s);
int         _RTLENTRYF _EXPFUNC   stricmp(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC   strlwr(char _FAR *__s);
int         _RTLENTRYF _EXPFUNC   strnicmp(const char _FAR *__s1, const char _FAR *__s2,
                                           _SIZE_T __maxlen);
char _FAR * _RTLENTRY  _EXPFUNC   strnset(char _FAR *__s, int __ch, _SIZE_T __n);
char _FAR * _RTLENTRY  _EXPFUNC   strrev(char _FAR *__s);
char _FAR * _RTLENTRY  _EXPFUNC   strset(char _FAR *__s, int __ch);
char _FAR * _RTLENTRYF _EXPFUNC   strupr(char _FAR *__s);
#endif  /* !__STDC__ */


#if defined(__cplusplus)
extern "C++"
{
          char _FAR * _RTLENTRYF _EXPFUNC   strchr(char _FAR * __s, int __c);
    const char _FAR * _RTLENTRYF _EXPFUNC   strchr(const char _FAR * __s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strrchr(char _FAR *__s, int __c);
    const char _FAR * _RTLENTRYF _EXPFUNC   strrchr(const char _FAR *__s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strpbrk(char _FAR *__s1, const char _FAR *__s2);
    const char _FAR * _RTLENTRYF _EXPFUNC   strpbrk(const char _FAR *__s1, const char _FAR *__s2);
          char _FAR * _RTLENTRY  _EXPFUNC   strstr(char _FAR *__s1, const char _FAR *__s2);
    const char _FAR * _RTLENTRY  _EXPFUNC   strstr(const char _FAR *__s1, const char _FAR *__s2);
}
#else
          char _FAR * _RTLENTRYF _EXPFUNC   strchr(const char _FAR * __s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strrchr(const char _FAR *__s, int __c);
          char _FAR * _RTLENTRYF _EXPFUNC   strpbrk(const char _FAR *__s1, const char _FAR *__s2);
          char _FAR * _RTLENTRY  _EXPFUNC   strstr(const char _FAR *__s1, const char _FAR *__s2);
#endif


/* Intrinsic functions */

/* Intrinsics must be prototyped outside of any namespace */
#ifdef __cplusplus
} // std
#endif /* __cplusplus */

char _FAR * _RTLENTRY             __stpcpy__(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRYF _EXPFUNC16 __strcat__(char _FAR *__dest, const char _FAR *__src);
char _FAR * _RTLENTRY  _EXPFUNC16 __strchr__(const char _FAR *__s, int __c);
int         _RTLENTRYF _EXPFUNC16 __strcmp__(const char _FAR *__s1, const char _FAR *__s2);
char _FAR * _RTLENTRYF _EXPFUNC16 __strcpy__(char _FAR *__dest, const char _FAR *__src);
_SIZE_T     _RTLENTRYF _EXPFUNC16 __strlen__(const char _FAR *__s);
char _FAR * _RTLENTRY  _EXPFUNC16 __strncat__(char _FAR *__dest, const char _FAR *__src,
                                              _SIZE_T __maxlen);
int         _RTLENTRY  _EXPFUNC16 __strncmp__(const char _FAR *__s1, const char _FAR *__s2,
                                              _SIZE_T __maxlen);
char _FAR * _RTLENTRYF _EXPFUNC16 __strncpy__(char _FAR *__dest, const char _FAR *__src,
                                              _SIZE_T __maxlen);
char _FAR * _RTLENTRY  _EXPFUNC16 __strnset__(char _FAR *__s, int __ch, _SIZE_T __n);
char _FAR * _RTLENTRYF _EXPFUNC16 __strrchr__(const char _FAR *__s, int __c);
char _FAR * _RTLENTRY  _EXPFUNC16 __strset__(char _FAR *__s, int __ch);

/* Now that the intrinsics are finished, turn the namespace back on */
#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */


#if defined(__MSC) && !defined(__MFC_COMPAT__)
#define _strnicmp(s1,s2,s3) strnicmp(s1,s2,s3)
#define _stricmp(s1,s2)     stricmp(s1,s2)
#define _strdup(s1)         strdup(s1)
#define _strupr(s1)         strupr(s1)
#define _strlwr(s1)         strlwr(s1)
#define _strrev(s1)         strrev(s1)
#endif  /* __MSC */

#if defined(__MFC_COMPAT__)
__inline char _FAR * _RTLENTRY  _strrev(char _FAR *__s) { return strrev(__s); }

__inline char _FAR * _RTLENTRY  _strset(char _FAR *__s, int __ch)
                              { return strset(__s, __ch); }
__inline char _FAR * _RTLENTRY  _strnset(char _FAR *__s, int __ch, _SIZE_T __n)
                              { return strnset(__s, __ch, __n); }
__inline char _FAR * _RTLENTRYF _strupr(char _FAR *__s) { return strupr(__s); }

__inline char _FAR * _RTLENTRYF _strlwr(char _FAR *__s) { return strlwr(__s); }

__inline char _FAR * _RTLENTRY  _strdup(const char _FAR *__s)
                              { return strdup(__s); }
__inline int         _RTLENTRYF _strcmpi(const char _FAR *__s1, const char _FAR *__s2)
                              { return stricmp (__s1, __s2); }
__inline int         _RTLENTRYF _stricmp(const char _FAR *__s1, const char _FAR *__s2)
                              { return stricmp (__s1, __s2); }
__inline int         _RTLENTRYF _strcmp(const char _FAR *__s1, const char _FAR *__s2)
                              { return strcmp (__s1, __s2); }
__inline int         _RTLENTRYF _strnicmp(const char _FAR *__s1, const char _FAR *__s2, _SIZE_T __maxlen)
                              { return strnicmp (__s1, __s2, __maxlen); }
#endif

int    _RTLENTRY  _EXPFUNC _lstrcoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _lstricoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _lstrncoll(const char * __s1, const char * __s2, const int __len);
int    _RTLENTRY  _EXPFUNC _lstrnicoll(const char * __s1, const char * __s2, int __len);
_SIZE_T _RTLENTRY  _EXPFUNC _lstrxfrm(char * __s1, const char * __s2,_SIZE_T __n );
int    _RTLENTRY  _EXPFUNC strcoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _stricoll(const char * __s1, const char * __s2);
int    _RTLENTRY  _EXPFUNC _strncoll(const char * __s1, const char * __s2, _SIZE_T __n);
int    _RTLENTRY  _EXPFUNC _strnicoll(const char * __s1, const char * __s2, int __len);
_SIZE_T _RTLENTRY  _EXPFUNC strxfrm(char * __s1, const char * __s2,_SIZE_T __n );

int    _RTLENTRY  _EXPFUNC _lwcscoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _lwcsicoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _lwcsncoll(const wchar_t * __s1, const wchar_t * __s2, const int __len);
int    _RTLENTRY  _EXPFUNC _lwcsnicoll(const wchar_t * __s1, const wchar_t * __s2, int __len);
_SIZE_T _RTLENTRY  _EXPFUNC _lwcsxfrm(wchar_t * __s1, const wchar_t * __s2,_SIZE_T __n );
int    _RTLENTRY  _EXPFUNC wcscoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _wcsicoll(const wchar_t * __s1, const wchar_t * __s2);
int    _RTLENTRY  _EXPFUNC _wcsncoll(const wchar_t * __s1, const wchar_t * __s2, _SIZE_T __n);
int    _RTLENTRY  _EXPFUNC _wcsnicoll(const wchar_t * __s1, const wchar_t * __s2, int __len);
_SIZE_T _RTLENTRY  _EXPFUNC wcsxfrm(wchar_t * __s1, const wchar_t * __s2, _SIZE_T __n );


#if !defined(__STDC__) /* NON_ANSI  */
#define _fstrcat   strcat
#define _fstrchr   strchr
#define _fstrcmp   strcmp
#define _fstrcpy   strcpy
#define _fstrcspn  strcspn
#define _fstrdup   strdup
#define _fstricmp  stricmp
#define _fstrlen   strlen
#define _fstrlwr   strlwr
#define _fstrncat  strncat
#define _fstrncmp  strncmp
#define _fstrncpy  strncpy
#define _fstrnicmp strnicmp
#define _fstrnset  strnset
#define _fstrpbrk  strpbrk
#define _fstrrchr  strrchr
#define _fstrrev   strrev
#define _fstrset   strset
#define _fstrspn   strspn
#define _fstrstr   strstr
#define _fstrtok   strtok
#define _fstrupr   strupr
#endif /* __STDC__  */

#if defined(__USELOCALES__)
#define  strupr     _lstrupr
#define  strlwr     _lstrlwr
#define  strcoll    _lstrcoll
#define  stricoll   _lstricoll
#define  strncoll   _lstrncoll
#define  strnicoll  _lstrnicoll
#define  strxfrm    _lstrxfrm
#endif  /* __USELOCALES__ */

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#ifdef __cplusplus
}
#endif

#endif  /* __STRING_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__STRING_H_USING_LIST)
#define __STRING_H_USING_LIST
#if !defined(__STDC__)
     using std::_lstrlwr;
     using std::_lstrupr;
     using std::_stpcpy;
     using std::strdup;
     using std::stricmp;
     using std::strlwr;
     using std::strnicmp;
     using std::strrev;
     using std::strupr;
#endif
#if defined(__MFC_COMPAT__)

     using std::_strrev;
     using std::_strset;
     using std::_strnset;
     using std::_strupr;
     using std::_strdup;
     using std::_strlwr;
     using std::_strcmpi;
     using std::_stricmp;
     using std::_strcmp;
     using std::_strnicmp;
#endif
     using std::_lstrcoll;
     using std::_lstricoll;
     using std::_lstrncoll;
     using std::_lstrnicoll;
     using std::_lstrxfrm;
     using std::_lwcscoll;
     using std::_lwcsicoll;
     using std::_lwcslwr;
     using std::_lwcsncoll;
     using std::_lwcsnicoll;
     using std::_lwcsupr;
     using std::_lwcsxfrm;
     using std::_strerror;
     using std::_stricoll;
     using std::_strncoll;
     using std::_strnicoll;
     using std::_wcsdup;
     using std::_wcsicmp;
     using std::_wcsicoll;
     using std::_wcslwr;
     using std::_wcsncoll;
     using std::_wcsnicmp;
     using std::_wcsnicoll;
     using std::_wcsnset;
     using std::_wcspcpy;
     using std::_wcsrev;
     using std::_wcsset;
     using std::_wcsupr;

/*
   Handle intrinsics specially.  If intrinsics are on, the compiler creates
   a macro of the normal function mapping to the __ intrinsic version, ie:
     #define strcpy __strcpy__
   Thus, we can test the normal name as a macro to see if it's defined, and
   only preform a using statement if it's not an intrinsic
*/

#if !defined(__STDC__)
#    ifndef strnset
    using std::strnset;
#    endif // ifndef strnset
#    ifndef stpcpy
    using std::stpcpy;
#    endif // ifndef stpcpy
#    ifndef strset
    using std::strset;
#    endif // ifndef strset
#endif // __STDC__

#    ifndef strcat
    using std::strcat;
#    endif // ifndef strcat
#    ifndef strchr
    using std::strchr;
#    endif // ifndef strchr
#    ifndef strcmp
    using std::strcmp;
#    endif // ifndef strcmp
#    ifndef strcpy
    using std::strcpy;
#    endif // ifndef strcpy
#    ifndef strlen
    using std::strlen;
#    endif // ifndef strlen
#    ifndef strncat
    using std::strncat;
#    endif // ifndef strncat
#    ifndef strncmp
    using std::strncmp;
#    endif // ifndef strncmp
#    ifndef strncpy
    using std::strncpy;
#    endif // ifndef strncpy
#    ifndef strrchr
    using std::strrchr;
#    endif // ifndef strrchr

     using std::strcspn;
     using std::strerror;
     using std::strpbrk;
     using std::strspn;
     using std::strstr;
     using std::strtok;
     using std::strxfrm;
     using std::strcoll;

     using std::wcscat;
     using std::wcschr;
     using std::wcscmp;
     using std::wcscoll;
     using std::wcscpy;
     using std::wcscspn;
     using std::wcslen;
     using std::wcsncat;
     using std::wcsncmp;
     using std::wcsncpy;
     using std::wcspbrk;
     using std::wcspcpy;
     using std::wcsrchr;
     using std::wcsspn;
     using std::wcsstr;
     using std::wcstok;
     using std::wcsxfrm;
#endif /* __USING_CNAME__ */
