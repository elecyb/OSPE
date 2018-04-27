/*  ctype.h

    Defines the locale aware ctype macros.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.8  $ */

#ifndef __CTYPE_H
#define __CTYPE_H

#if !defined(RC_INVOKED)

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#ifndef __STDC__

#include <mbctype.h>

/* MSC compatible macro: */
#define isleadbyte(__c)     _ismbblead(__c)

#endif /* __STDC__ */

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
extern "C" {
#endif

extern unsigned short _RTLENTRY _EXPDATA _chartype[ 257 ];
extern unsigned char _RTLENTRY  _EXPDATA _lower[ 256 ];
extern unsigned char _RTLENTRY  _EXPDATA _upper[ 256 ];

int _RTLENTRY _EXPFUNC isalnum (int __c);
int _RTLENTRY _EXPFUNC isalpha (int __c);
int _RTLENTRY _EXPFUNC iscntrl (int __c);
int _RTLENTRY _EXPFUNC isdigit (int __c);
int _RTLENTRY _EXPFUNC isgraph (int __c);
int _RTLENTRY _EXPFUNC islower (int __c);
int _RTLENTRY _EXPFUNC isprint (int __c);
int _RTLENTRY _EXPFUNC ispunct (int __c);
int _RTLENTRY _EXPFUNC isspace (int __c);
int _RTLENTRY _EXPFUNC isupper (int __c);
int _RTLENTRY _EXPFUNC isxdigit(int __c);
int _RTLENTRY _EXPFUNC isascii (int __c);

int _RTLENTRY _EXPFUNC iswalnum (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswalpha (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswcntrl (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswdigit (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswgraph (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswlower (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswprint (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswpunct (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswspace (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswupper (_WINT_T __c);
int _RTLENTRY _EXPFUNC iswxdigit(_WINT_T __c);
int _RTLENTRY _EXPFUNC iswascii (_WINT_T __c);
#ifdef __cplusplus
}
#endif

/* character classes */

#define _IS_UPP    0x0001           /* upper case */
#define _IS_LOW    0x0002           /* lower case */
#define _IS_DIG    0x0004           /* digit */
#define _IS_SP     0x0008           /* space */
#define _IS_PUN    0x0010           /* punctuation */
#define _IS_CTL    0x0020           /* control */
#define _IS_BLK    0x0040           /* blank */
#define _IS_HEX    0x0080           /* [0..9] or [A-F] or [a-f] */
#define _IS_ALPHA  0x0100

#define _IS_ALNUM    (_IS_DIG | _IS_ALPHA)
#define _IS_GRAPH    (_IS_ALNUM | _IS_HEX | _IS_PUN)

#ifndef __USELOCALES__

/* C locale character classification macros */

#define isalnum(c)   (__STD _chartype[ (c)+1 ] & (_IS_ALNUM))
#define isalpha(c)   (__STD _chartype[ (c)+1 ] & (_IS_ALPHA))
#define iscntrl(c)   (__STD _chartype[ (c)+1 ] & (_IS_CTL))
#define isdigit(c)   (__STD _chartype[ (c)+1 ] & (_IS_DIG))
#define isgraph(c)   (__STD _chartype[ (c)+1 ] & (_IS_GRAPH))
#define islower(c)   (__STD _chartype[ (c)+1 ] & (_IS_LOW))
#define isprint(c)   (__STD _chartype[ (c)+1 ] & (_IS_GRAPH | _IS_BLK))
#define ispunct(c)   (__STD _chartype[ (c)+1 ] & (_IS_PUN))
#define isspace(c)   (__STD _chartype[ (c)+1 ] & (_IS_SP))
#define isupper(c)   (__STD _chartype[ (c)+1 ] & (_IS_UPP))
#define isxdigit(c)  (__STD _chartype[ (c)+1 ] & (_IS_HEX))

#ifndef _UNICODE
#define iswalnum(c)   (__STD _chartype[ (c)+1 ] & (_IS_ALNUM))
#define iswalpha(c)   (__STD _chartype[ (c)+1 ] & (_IS_ALPHA))
#define iswcntrl(c)   (__STD _chartype[ (c)+1 ] & (_IS_CTL))
#define iswdigit(c)   (__STD _chartype[ (c)+1 ] & (_IS_DIG))
#define iswgraph(c)   (__STD _chartype[ (c)+1 ] & (_IS_GRAPH))
#define iswlower(c)   (__STD _chartype[ (c)+1 ] & (_IS_LOW))
#define iswprint(c)   (__STD _chartype[ (c)+1 ] & (_IS_GRAPH | _IS_BLK))
#define iswpunct(c)   (__STD _chartype[ (c)+1 ] & (_IS_PUN))
#define iswspace(c)   (__STD _chartype[ (c)+1 ] & (_IS_SP))
#define iswupper(c)   (__STD _chartype[ (c)+1 ] & (_IS_UPP))
#define iswxdigit(c)  (__STD _chartype[ (c)+1 ] & (_IS_HEX))

#endif /* _UNICODE */

#endif /* __USELOCALES__ */

#define iswascii(c)  ((unsigned)(c) < 128)
#define isascii(c)  ((unsigned)(c) < 128)
#define toascii(c)  ((c) & 0x7f)

#ifdef __cplusplus
extern "C" {
#endif


#if !defined( __USELOCALES__ )
int     _RTLENTRY _EXPFUNC tolower(int __ch);
int     _RTLENTRY _EXPFUNC toupper(int __ch);
_WINT_T _RTLENTRY _EXPFUNC towlower(_WINT_T __ch);
_WINT_T _RTLENTRY _EXPFUNC towupper(_WINT_T __ch);
#endif

int     _RTLENTRY _EXPFUNC _ltolower(int __ch);
int     _RTLENTRY _EXPFUNC _ltoupper(int __ch);
wchar_t _RTLENTRY _EXPFUNC _ltowupper(wchar_t __ch);
wchar_t _RTLENTRY _EXPFUNC _ltowlower(wchar_t __ch);

#if !defined(__STDC__)	/* NON-ANSI */
#define _toupper(__c)   ((__c) + 'A' - 'a')
#define _tolower(__c)   ((__c) + 'a' - 'A')
#endif


#ifdef __cplusplus
}
#endif

#if defined( __USELOCALES__ )
/* The following four functions cannot be macros, since the Rogue Wave headers
   #undef them.  So instead we'll use inline functions. */

/* Inline functions in "C" mode will disable precompiled headers if they are
   generated out-of-line.  Enabling debugging info, by default, will do this.
   Since most folks build with debug info frequently, we enable the -vi switch
   which forces these inline functions to be expanded inline even if debug
   info is enabled.
*/
#pragma option push -vi
__inline int     _RTLENTRY _EXPFUNC tolower(int __ch)      { return _ltolower(__ch);  }
__inline int     _RTLENTRY _EXPFUNC toupper(int __ch)      { return _ltoupper(__ch);  }
__inline _WINT_T _RTLENTRY _EXPFUNC towlower(_WINT_T __ch) { return _ltowlower(__ch); }
__inline _WINT_T _RTLENTRY _EXPFUNC towupper(_WINT_T __ch) { return _ltowupper(__ch); }
#pragma option pop /* -vi */

#define _wcsupr    _lwcsupr
#define _wcslwr    _lwcslwr

#endif  /*  __USELOCALES__  */

/* some MSC compatible macros */

#define __iscsymf(__c)  (isalpha(__c) || ((__c) == '_'))
#define __iscsym(__c)   (isalnum(__c) || ((__c) == '_'))

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* !RC_INVOKED */

#endif /* __CTYPE_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__CTYPE_H_USING_LIST)
#define __CTYPE_H_USING_LIST
     using std::_chartype;
     using std::_lower;
     using std::_upper;
     using std::isalnum;
     using std::isalpha;
     using std::iscntrl;
     using std::isdigit;
     using std::isgraph;
     using std::islower;
     using std::isprint;
     using std::ispunct;
     using std::isspace;
     using std::isupper;
     using std::isxdigit;
     using std::isascii;
     using std::iswalnum;
     using std::iswalpha;
     using std::iswcntrl;
     using std::iswdigit;
     using std::iswgraph;
     using std::iswlower;
     using std::iswprint;
     using std::iswpunct;
     using std::iswspace;
     using std::iswupper;
     using std::iswxdigit;
     using std::iswascii;
     using std::tolower;
     using std::_ltolower;
     using std::toupper;
     using std::_ltoupper;
     using std::towlower;
     using std::towupper;
     using std::_ltowupper;
     using std::_ltowlower;
#endif /* __USING_CNAME__ */
