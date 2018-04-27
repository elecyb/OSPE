/*  _loc.h - Internal version of "C" locale.h header file

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.0  $ */

#ifndef __LOCALE_H
#define __LOCALE_H

#if !defined(___STDDEF_H)
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
namespace std {
#endif

#define LOCALE_ERROR(code) 0x00000100 + code
#define ERROR_LOCALE_INVALID   (APPLICATION_ERROR_MASK + LOCALE_ERROR(1))
#define ERROR_CATEGORY_INVALID (APPLICATION_ERROR_MASK + LOCALE_ERROR(2))
#define ERROR_LOCALE_NOTINSTALLED (APPLICATION_ERROR_MASK + LOCALE_ERROR(3))
#define ERROR_LOCALE_NOTSUPPORTED (APPLICATION_ERROR_MASK + LOCALE_ERROR(4))
#define ERROR_CATEGORY_NOTOPEN (APPLICATION_ERROR_MASK + LOCALE_ERROR(5))

#define LC_COLLATE  0x01
#define LC_CTYPE    0x02
#define LC_MONETARY 0x04
#define LC_NUMERIC  0x10
#define LC_TIME     0x20
#define LC_ALL      0xFF
#define LC_MIN      LC_COLLATE
#define LC_MAX      LC_ALL
#define LC_LAST     LC_MAX

struct lconv {

   char _FAR *decimal_point;
   char _FAR *thousands_sep;
   char _FAR *grouping;
   char _FAR *int_curr_symbol;
   char _FAR *currency_symbol;
   char _FAR *mon_decimal_point;
   char _FAR *mon_thousands_sep;
   char _FAR *mon_grouping;
   char _FAR *positive_sign;
   char _FAR *negative_sign;
   char int_frac_digits;
   char frac_digits;
   char p_cs_precedes;
   char p_sep_by_space;
   char n_cs_precedes;
   char n_sep_by_space;
   char p_sign_posn;
   char n_sign_posn;
};


#pragma pack(push, 1)

#ifdef __cplusplus
extern "C" {
#endif
char *         _RTLENTRY _EXPFUNC setlocale( int __category, const char *__locale );
char *         _RTLENTRY _EXPFUNC _lsetlocale( int __category, const char *__locale );
struct lconv * _RTLENTRY _EXPFUNC localeconv( void );
struct lconv * _RTLENTRY _EXPFUNC _llocaleconv( void );
wchar_t *      _RTLENTRY _EXPFUNC _wsetlocale( int __category, const wchar_t *__locale );
wchar_t *      _RTLENTRY _EXPFUNC _lwsetlocale( int __category, const wchar_t *__locale );
#ifdef __cplusplus
}
#endif

#pragma pack(pop) /* restore default packing */

#if defined( __USELOCALES__ )
#ifndef _UNICODE
  #define setlocale  _lsetlocale
#else
  #define _wsetlocale  _lwsetlocale
#endif
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif

#endif  /* __LOCALE_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__LOCALE_H_USING_LIST)
#define __LOCALE_H_USING_LIST
    using std::lconv;
    using std::setlocale;
    using std::_lsetlocale;
    using std::localeconv;
    using std::_llocaleconv;
    using std::_wsetlocale;
    using std::_lwsetlocale;
#endif /* __USING_CNAME__ */
