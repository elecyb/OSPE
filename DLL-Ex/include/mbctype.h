/*  mbctype.h

    Defines the mbctype macros.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1997, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.4  $ */

#ifndef __MBCTYPE_H
#define __MBCTYPE_H
#define _INC_MBCTYPE  /* MSC Guard name */

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#ifndef __CTYPE_H
#include <ctype.h>
#endif

#define __MBBS ((unsigned char)0x01) /* Non-punctuation of single byte set   */
#define __MBBP ((unsigned char)0x02) /* Punctuation of single byte set       */
#define __MBB1 ((unsigned char)0x04) /* Legal 1st byte of double byte stream */
#define __MBB2 ((unsigned char)0x08) /* Legal 2nd btye of double byte stream */

extern unsigned char _RTLENTRY _EXPDATA _mbctype[];    /* character type array */

/* values used in _mbbtype(), _mbsbtype() */
#define _MBC_SINGLE       0
#define _MBC_LEAD         1
#define _MBC_TRAIL        2
#define _MBC_ILLEGAL    (-1)

/* Japanese code page */
#define _KANJI_CP 932

/* values used in _setmbcp() */
#define _MB_CP_SBCS       0
#define _MB_CP_OEM      (-2)
#define _MB_CP_ANSI     (-3)
#define _MB_CP_LOCALE   (-4)

#ifdef __cplusplus
extern "C" {
#endif

int _RTLENTRY _EXPFUNC _setmbcp(int newCodePage);
int _RTLENTRY _EXPFUNC _getmbcp(void);

int _RTLENTRY _ismbbkalpha(unsigned int __c);
int _RTLENTRY _ismbbkpunct(unsigned int __c);
int _RTLENTRY _ismbbkana  (unsigned int __c);
int _RTLENTRY _ismbbalpha (unsigned int __c);
int _RTLENTRY _ismbbpunct (unsigned int __c);
int _RTLENTRY _ismbbalnum (unsigned int __c);
int _RTLENTRY _ismbbprint (unsigned int __c);
int _RTLENTRY _ismbbgraph (unsigned int __c);

#ifndef __MBCS_LEADTRAIL
#define __MBCS_LEADTRAIL
int _RTLENTRY _ismbblead  (unsigned int __c);
int _RTLENTRY _ismbbtrail (unsigned int __c);
int _RTLENTRY _ismbslead  (const unsigned char _FAR *__s1, const unsigned char _FAR *__s2);
int _RTLENTRY _ismbstrail (const unsigned char _FAR *__s1, const unsigned char _FAR *__s2);
#endif  /* ! __MBCS_LEADTRAIL */

#ifdef __cplusplus
}
#endif

#define _ismbbkalpha(__c) ((_mbctype+1)[(unsigned char)(__c)] & __MBBS)
#define _ismbbkpunct(__c) ((_mbctype+1)[(unsigned char)(__c)] & __MBBP)
#define _ismbbkana(__c)   ((_mbctype+1)[(unsigned char)(__c)] &(__MBBS|__MBBP))
#define _ismbbalpha(__c)  (isalpha((unsigned char)(__c)) || _ismbbkalpha(__c))
#define _ismbbpunct(__c)  (ispunct((unsigned char)(__c)) || _ismbbkpunct(__c))
#define _ismbbalnum(__c)  (isalnum((unsigned char)(__c)) || _ismbbkalpha(__c))
#define _ismbbprint(__c)  (isprint((unsigned char)(__c)) || _ismbbkana(__c))
#define _ismbbgraph(__c)  (isgraph((unsigned char)(__c)) || _ismbbkana(__c))

#define _ismbblead(__c)   ((_mbctype+1)[(unsigned char)(__c)] & __MBB1)
#define _ismbbtrail(__c)  ((_mbctype+1)[(unsigned char)(__c)] & __MBB2)

#endif /* __MBCTYPE_H */
