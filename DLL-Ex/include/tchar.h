/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1995, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.21  $ */

#if !defined(__TCHAR_H)
#define __TCHAR_H
#define _INC_TCHAR  /* MSC Guard name */

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

/*
    This file is parsed with a tool that will spit out a table of
    function mappings for the online help.  The format is as follows:

    Inside a single-line slash-star comment, there will be a command:

    @+(col_name[,col]) ..descrip..   Define (start) current column block(s)
    @-                               Stop the current block(s)
    @:..descrip..                    Change description for the current block(s)
    @!:portable_name                 Adds in a brute force entry with no equiv.
    @!(portable_name,cur_col_name)   Adds in a brute force entry

    The lines following these commands will then be processed:
      #define portable_name cur_col_name
      typedef cur_col_name portable_name

    #defines that are macros (have parens) or are more than two words are
    ignored.
*/

#if defined(__USING_CNAME__)
#  undef __USING_CNAME__
#  include <string.h>
#  define __USING_CNAME__
#else
#  include <string.h>
#endif

#ifdef  __cplusplus
extern "C" {
#endif

#if defined(_MBCS) && !defined(__MBSTRING_H)
#include <mbstring.h>
#endif

#if !defined(_UNICODE)

#ifdef __cplusplus
namespace std {
#endif

/* @+(SBCS) Types */

#if !defined(_MBCS)

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef char            _TXCHAR;
typedef int             _TINT;
#define __TCHAR_DEFINED
#endif
#endif /* _MBCS */

#ifdef __cplusplus
} // std
#endif

/* @: misc. functions */

#define _tfdopen        _fdopen
#define _fputtchar      _fputchar
#define _fgettchar      _fgetchar
#define _tmktemp        _mktemp
#define _tunlink        _unlink
#define _ttempnam       _tempnam
#define _trmdir         _rmdir
#define _tmkdir         _mkdir
#define _tutime         _utime
#define _ltot           _ltoa
#define _tsopen         _sopen

/* @: program specific functions */

#define _tmain          main
#define _tWinMain       WinMain
#define _tenviron       _environ
#define _targv          _argv

/* @: path/environment specific functions */

#define _tfullpath      _fullpath
#define _tmakepath      _makepath
#define _tsplitpath     _splitpath
#define _tsearchpath    searchpath
#define _tsearchenv     _searchenv
#define _tsearchstr     _searchstr
#define _tgetenv        getenv
#define _tputenv        putenv
#define _tfnsplit       fnsplit
#define _tfnmerge       fnmerge

/* @: directory functions */

#define _topendir       opendir
#define _treaddir       readdir
#define _trewinddir     rewinddir
#define _tclosedir      closedir
#define _tDIR           DIR
#define _tdirent        dirent

/* @: stdio functions */

#define _tpopen         _popen
#define _tfsopen        _fsopen
#define _tfopen         fopen
#define _tfreopen       freopen
#define _tperror        perror
#define _ttmpnam        tmpnam

/* @: time functions */

#define _tstrdate       _strdate
#define _tstrtime       _strtime
#define _tasctime       asctime
#define _tctime         ctime
#define _tcsftime       strftime
#define _ttzset         _tzset
#define _ttzname        _tzname

/* @: I/O functions */

#define _taccess        access
#define _tchmod         chmod
#define _trtl_open      _rtl_open
#define _trtl_creat     _rtl_creat
#define _trtl_chmod     _rtl_chmod
#define _tcreat         creat
#define __tcreat        _creat
#define _tfindfirst     findfirst
#define _tfindnext      findnext
#define _tfindclose     findclose
#define __tfindfirsti64 _findfirsti64
#define __tfindnexti64  _findnexti64
#define __tfinddatai64_t _finddatai64_t
#define __tfinddata_t   _finddata_t

#define __tfindfirst    _findfirst
#define __tfindnext     _findnext
#define _topen          open
#define __topen         _open
#define _tremove        remove
#define _trename        rename

#define _tffblk         ffblk

/* @: string conversion functions */

#define _ttof           atof
#define _ttoi           atoi
#define _ttol           atol
#define _ttoi64         _atoi64
#define _ttold          _atold
#define _tcstod         strtod
#define _tcstol         strtol
#define _tcstold        _strtold
#define _tcstoul        strtoul
#define _itot           itoa
#define _ultot          ultoa
#define _i64tot         _i64toa
#define _ui64tot        _ui64toa

/* @: generic string functions  */

#define _tcscat         strcat
#define _tcscpy         strcpy
#define _tcspcpy        _stpcpy
#define _tcslen         strlen
#define _tcsdup         strdup

/* @: directory functions */

#define _tchdir         chdir
#define _tgetcurdir     getcurdir
#define _tgetcwd        getcwd
#define _tgetdcwd       _getdcwd

/* @: process execution functions */

#define _texecl     execl
#define _texecle    execle
#define _texeclp    execlp
#define _texeclpe   execlpe
#define _texecv     execv
#define _texecve    execve
#define _texecvp    execvp
#define _texecvpe   execvpe

#define _tspawnl    spawnl
#define _tspawnle   spawnle
#define _tspawnlp   spawnlp
#define _tspawnlpe  spawnlpe
#define _tspawnv    spawnv
#define _tspawnve   spawnve
#define _tspawnvp   spawnvp
#define _tspawnvpe  spawnvpe

#define _tsystem    system

/* @: unformated I/O */

#define _fgettc         fgetc
#define _fgetts         fgets
#define _fputtc         fputc
#define _fputts         fputs
#define _gettc          getc
#define _gettchar       getchar
#define _getts          gets
#define _puttc          putc
#define _puttchar       putchar
#define _putts          puts
#define _ungettc        ungetc

/* @: formated I/O functions */

#define _ftprintf       fprintf
#define _tprintf        printf
#define _stprintf       sprintf
#define _vtprintf       vprintf
#define _vftprintf      vfprintf
#define _vstprintf      vsprintf
#define _sntprintf      snprintf
#define _vsntprintf     vsnprintf
#define __sntprintf     _snprintf       // MSC compat.
#define __vsntprintf    _vsnprintf      // MSC compat.


#define _tscanf         scanf
#define _stscanf        sscanf
#define _ftscanf        fscanf
#define _vstscanf       vsscanf
#define _vtscanf        vscanf
#define _vftscanf       vfscanf

/* @: stat functions */

#define _tstat          _stat
#define _tstati64       _stati64

/* @: setlocale functions */

#define _tsetlocale setlocale

/* @: memory functions */

#define _tmemcpy        memcpy
#define _tmemchr        memchr
#define _tmemset        memset

/* @: generic text macros */
/* @!:__T */
/* @!:_TEXT */
/* @!:_T */

#define __T(__x)          __x
#define _TEXT(__x)        __T(__x)
#define _T(__x)           __T(__x)
#define _TEOF           EOF

#if defined(_MBCS)

/* ----------------- MBCS functions -------------------------- */

#ifdef __cplusplus
namespace std {
#endif

/* @+(MBCS) Types */

#ifndef __TCHAR_DEFINED
typedef char            _TCHAR;
typedef signed char     _TSCHAR;
typedef unsigned char   _TUCHAR;
typedef unsigned char   _TXCHAR;
/* typedef unsigned int    _TINT; */ /* HACK: for now */
typedef int    _TINT;
#define __TCHAR_DEFINED
#endif

#ifdef __cplusplus
} // std
#endif

#ifdef _MBC_USE_MACROS
/* @: string functions */

#define _tcschr         _mbschr
#define _tcscspn        _mbscspn
#define _tcsncat        _mbsnbcat
#define _tcsncpy        _mbsnbcpy
#define _tcspbrk        _mbspbrk
#define _tcsrchr        _mbsrchr
#define _tcsspn         _mbsspn
#define _tcsstr         _mbsstr
#define _tcstok         _mbstok

#define _tcsset         _mbsset
#define _tcsnset        _mbsnbset
#define _tcsrev         _mbsrev
#define _tcscmp         _mbscmp
#define _tcsicmp        _mbsicmp
#define _tcsncmp        _mbsnbcmp
#define _tcsnicmp       _mbsnbicmp
#define _tcsnccmp       _mbsncmp
#define _tcsncicmp      _mbsnicmp

/* todo : correct the mapping of these functions and add the new functions */
#define _tcscoll        _mbscoll
#define _tcsncoll       _mbsnbcoll
#define _tcsnccoll      _mbsncoll
#define _tcsicoll       _mbsicoll
#define _tcsnicoll      _mbsnbicoll
#define _tcsncicoll     _mbsnicoll

/* @: logical-character functions */

#define _tcsclen        _mbslen
#define _tcsnccat       _mbsncat
#define _tcsnccpy       _mbsncpy
#define _tcsncset       _mbsnset

/* @: misc. functions */

#define _tcsdec         _mbsdec
#define _tcsinc         _mbsinc
#define _tcsnbcnt       _mbsnbcnt
#define _tcsnccnt       _mbsnccnt
#define _tcsnextc       _mbsnextc
#define _tcsninc        _mbsninc
#define _tcsspnp        _mbsspnp

#define _tcslwr         _mbslwr
#define _tcsupr         _mbsupr

#define _tclen          _mbclen
#define _tccpy          _mbccpy

/* @!(_tccmp,_mbsncmp) */
/* @- */
#define _tccmp(__a,__b) _mbsncmp(__a,__b,1)

#else /* _MBC_USE_MACROS */

#if (!defined ( __cplusplus) || defined( _NO_INLINING ))

/* String functions */

char * _RTLENTRY  _EXPFUNC _tcschr(const char *, unsigned int);
_SIZE_T _RTLENTRY  _EXPFUNC _tcscspn(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsncat(char *, const char *, _SIZE_T);
char * _RTLENTRY  _EXPFUNC _tcsncpy(char *, const char *, _SIZE_T);
char * _RTLENTRY  _EXPFUNC _tcspbrk(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsrchr(const char *, int);
_SIZE_T _RTLENTRY  _EXPFUNC _tcsspn(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsstr(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcstok(char *, const char *);

char * _RTLENTRY  _EXPFUNC _tcsnset(char *, unsigned int, _SIZE_T);
char * _RTLENTRY  _EXPFUNC _tcsrev(char *);
char * _RTLENTRY  _EXPFUNC _tcsset(char *, unsigned int);

int _RTLENTRY  _EXPFUNC _tcscmp(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsicmp(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsnccmp(const char *, const char *, _SIZE_T);
int _RTLENTRY  _EXPFUNC _tcsncmp(const char *, const char *, _SIZE_T);
int _RTLENTRY  _EXPFUNC _tcsncicmp(const char *, const char *, _SIZE_T);
int _RTLENTRY  _EXPFUNC _tcsnicmp(const char *, const char *, _SIZE_T);

int _RTLENTRY  _EXPFUNC _tcscoll(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsicoll(const char *, const char *);
int _RTLENTRY  _EXPFUNC _tcsnccoll(const char *, const char *, _SIZE_T);
int _RTLENTRY  _EXPFUNC _tcsncoll(const char *, const char *, _SIZE_T);
int _RTLENTRY  _EXPFUNC _tcsncicoll(const char *, const char *, _SIZE_T);
int _RTLENTRY  _EXPFUNC _tcsnicoll(const char *, const char *, _SIZE_T);


/* "logical-character" functions */

_SIZE_T _RTLENTRY  _EXPFUNC _tcsclen(const char *);
char * _RTLENTRY  _EXPFUNC _tcsnccat(char *, const char *, _SIZE_T);
char * _RTLENTRY  _EXPFUNC _tcsnccpy(char *, const char *, _SIZE_T);
char * _RTLENTRY  _EXPFUNC _tcsncset(char *, unsigned int, _SIZE_T);


/* MBCS-specific functions */

char * _RTLENTRY  _EXPFUNC _tcsdec(const char *, const char *);
char * _RTLENTRY  _EXPFUNC _tcsinc(const char *);
_SIZE_T _RTLENTRY  _EXPFUNC _tcsnbcnt(const char *, _SIZE_T);
_SIZE_T _RTLENTRY  _EXPFUNC _tcsnccnt(const char *, _SIZE_T);
unsigned int _RTLENTRY  _EXPFUNC _tcsnextc (const char *);
char * _RTLENTRY  _EXPFUNC _tcsninc(const char *, _SIZE_T);
char * _RTLENTRY  _EXPFUNC _tcsspnp(const char *, const char *);

char * _RTLENTRY  _EXPFUNC _tcslwr(char *);
char * _RTLENTRY  _EXPFUNC _tcsupr(char *);

_SIZE_T _RTLENTRY  _EXPFUNC _tclen(const char *);
void   _RTLENTRY  _EXPFUNC _tccpy(char *, const char *);
int    _RTLENTRY  _EXPFUNC _tccmp(const char *, const char *);

#else  /* (!defined( __cplusplus) || defined( _NO_INLINING )) */

inline char * _tcschr(const char * __s1,unsigned int __c) {return (char *)_mbschr((const unsigned char *)__s1,__c);}
inline _SIZE_T _tcscspn(const char * __s1,const char * __s2) {return _mbscspn((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline char * _tcsncat(char * __s1,const char * __s2,_SIZE_T __n) {return (char *)_mbsnbcat((unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline char * _tcsncpy(char * __s1,const char * __s2,_SIZE_T __n) {return (char *)_mbsnbcpy((unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline char * _tcspbrk(const char * __s1,const char * __s2) {return (char *)_mbspbrk((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline char * _tcsrchr(const char * __s1,unsigned int __c) {return (char *)_mbsrchr((const unsigned char *)__s1,__c);}
inline _SIZE_T _tcsspn(const char * __s1,const char * __s2) {return _mbsspn((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline char * _tcsstr(const char * __s1,const char * __s2) {return (char *)_mbsstr((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline char * _tcstok(char * __s1,const char * __s2) {return (char *)_mbstok((unsigned char *)__s1,(const unsigned char *)__s2);}

inline char * _tcsnset(char * __s1,unsigned int __c,_SIZE_T __n) {return (char *)_mbsnbset((unsigned char *)__s1,__c,__n);}
inline char * _tcsrev(char * __s1) {return (char *)_mbsrev((unsigned char *)__s1);}
inline char * _tcsset(char * __s1,unsigned int __c) {return (char *)_mbsset((unsigned char *)__s1,__c);}

inline int _tcscmp(const char * __s1,const char * __s2) {return _mbscmp((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline int _tcsicmp(const char * __s1,const char * __s2) {return _mbsicmp((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline int _tcsnccmp(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsncmp((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline int _tcsncmp(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsnbcmp((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline int _tcsncicmp(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsnicmp((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline int _tcsnicmp(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsnbicmp((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}

inline int _tcscoll(const char * __s1,const char * __s2) {return _mbscoll((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline int _tcsicoll(const char * __s1,const char * __s2) {return _mbsicoll((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline int _tcsnccoll(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsncoll((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline int _tcsncoll(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsnbcoll((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline int _tcsncicoll(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsnicoll((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline int _tcsnicoll(const char * __s1,const char * __s2,_SIZE_T __n) {return _mbsnbicoll((const unsigned char *)__s1,(const unsigned char *)__s2,__n);}


/* logical-character functions */

inline _SIZE_T _tcsclen(const char * __s1) {return _mbslen((const unsigned char *)__s1);}
inline char * _tcsnccat(char * __s1,const char * __s2,_SIZE_T __n) {return (char *)_mbsncat((unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline char * _tcsnccpy(char * __s1,const char * __s2,_SIZE_T __n) {return (char *)_mbsncpy((unsigned char *)__s1,(const unsigned char *)__s2,__n);}
inline char * _tcsncset(char * __s1,unsigned int __c,_SIZE_T __n) {return (char *)_mbsnset((unsigned char *)__s1,__c,__n);}


/* MBCS-specific functions */

inline char * _tcsdec(const char * __s1,const char * __s2) {return (char *)_mbsdec((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline char * _tcsinc(const char * __s1) {return (char *)_mbsinc((const unsigned char *)__s1);}
inline _SIZE_T _tcsnbcnt(const char * __s1,_SIZE_T __n) {return _mbsnbcnt((const unsigned char *)__s1,__n);}
inline _SIZE_T _tcsnccnt(const char * __s1,_SIZE_T __n) {return _mbsnccnt((const unsigned char *)__s1,__n);}

inline unsigned int _tcsnextc(const char * __s1)
{
   const unsigned char *__p = (const unsigned char *) __s1;
   return (_ismbblead(*__p)) ? (((unsigned int)*__p << 8) | __p[0]) : *__p;
}

inline char * _tcsninc(const char * __s1,_SIZE_T __n) {return (char *)_mbsninc((const unsigned char *)__s1,__n);}
inline char * _tcsspnp(const char * __s1,const char * __s2) {return (char *)_mbsspnp((const unsigned char *)__s1,(const unsigned char *)__s2);}
inline char * _tcslwr(char * __s1) {return (char *)_mbslwr((unsigned char *)__s1);}
inline char * _tcsupr(char * __s1) {return (char *)_mbsupr((unsigned char *)__s1);}

inline _SIZE_T _tclen(const char * __s1) {return _mbclen((const unsigned char *)__s1);}
inline void   _tccpy(char * __s1,const char * __s2) {_mbccpy((unsigned char *)__s1,(const unsigned char *)__s2); return;}
inline int    _tccmp(const char *__s1, const char *__s2){ return  _mbsncmp((const unsigned char *)__s1,(const unsigned char *)__s2,1);}

#endif  /* (!defined ( __cplusplus) || defined( _NO_INLINING )) */

#endif  /* _MBC_USE_MACROS */

/* @+(MBCS) comparison functions */

#define _tcscmpi        _tcsicmp
#define _tcsncmpi       _tcsnicmp

/* @: ctype functions */

#define _istalnum       _ismbcalnum
#define _istalpha       _ismbcalpha
#define _istdigit       _ismbcdigit
#define _istgraph       _ismbcgraph
#define _istlower       _ismbclower
#define _istprint       _ismbcprint
#define _istpunct       _ismbcpunct
#define _istspace       _ismbcspace
#define _istupper       _ismbcupper
#define _istlegal       _ismbclegal

#define _totlower       _mbctolower
#define _totupper       _mbctoupper

#define _istlead        _ismbblead
#define _istleadbyte    _ismbblead

/* @- */
#else  /* _MBCS */

/* ------------------- SBCS functions ----------------------- */


/* @+(SBCS) string functions */

#define _tcschr         strchr
#define _tcscspn        strcspn
#define _tcsncpy        strncpy
#define _tcsncat        strncat
#define _tcspbrk        strpbrk
#define _tcsrchr        strrchr
#define _tcsspn         strspn
#define _tcsstr         strstr
#define _tcstok         strtok

#define _tcsnset        strnset
#define _tcsrev         strrev
#define _tcsset         strset

#define _tcscmp         strcmp
#define _tcsicmp        stricmp
#define _tcsnccmp       strncmp
#define _tcsncmp        strncmp
#define _tcsncicmp      strnicmp
#define _tcsnicmp       strnicmp
#define _tcscmpi        strcmpi
#define _tcsncmpi       strncmpi

#define _tcscoll        strcoll
#define _tcsicoll       _stricoll
#define _tcsnccoll      _strncoll
#define _tcsncoll       _strncoll
#define _tcsncicoll     _strnicoll
#define _tcsnicoll      _strnicoll
#define _tcsxfrm        strxfrm

#define _ltcscoll       _lstrcoll
#define _ltcsicoll      _lstricoll
#define _ltcsnccoll     _lstrncoll
#define _ltcsncoll      _lstrncoll
#define _ltcsncicoll    _lstrnicoll
#define _ltcsnicoll     _lstrnicoll
#define _ltcsxfrm       _lstrxfrm

/* A few MBCS-like functions */

#define _tcsdec         _strdec
#define _tcsinc         _strinc
#define _tcsnbcnt       _strncnt
#define _tcsnccnt       _strncnt
#define _tcsnextc       _strnextc
#define _tcsninc        _strninc
#define _tcsspnp        _strspnp

#define _tcslwr         strlwr
#define _tcsupr         strupr

/* @!:_istlegal */
/* @!:_istlead */
/* @!:_istleadbyte */

#define _istlegal(__a)    (1)
#define _istlead(__a)     (0)
#define _istleadbyte(__a) (0)


#if (!defined ( __cplusplus) || defined( _NO_INLINING ))

/* @!:_tclen */
/* @!:_tccpy */
/* @!:_tccmp */

#define _tclen(__a)         (1)
#define _tccpy(__a,__b)     ((*(__a))=(*(__b)))
#define _tccmp(__a,__b)     ((*(__a))-(*(__b)))

#else  /* (!defined ( __cplusplus) || defined( _NO_INLINING )) */

inline _SIZE_T _RTLENTRY _tclen(const char *__s ){return (1); }
inline void   _RTLENTRY _tccpy(char *__s1, const char *__s2) {*(__s1) = *(__s2); }
inline int    _RTLENTRY _tccmp(const char *__s1, const char *__s2){ return (int) ( ((unsigned char*)__s1)-((unsigned char*)__s2)); }

#endif  /* (!defined ( __cplusplus) || defined( _NO_INLINING )) */

/* @: logical-character functions */

#define _tcsclen        strlen
#define _tcsnccat       strncat
#define _tcsnccpy       strncpy
#define _tcsncset       strnset

/* @: ctype functions */

#define _istalnum       isalnum
#define _istalpha       isalpha
#define _istdigit       isdigit
#define _istgraph       isgraph
#define _istlower       islower
#define _istprint       isprint
#define _istpunct       ispunct
#define _istspace       isspace
#define _istupper       isupper
#define _istascii       isascii
#define _istcntrl       iscntrl
#define _istxdigit      isxdigit

#define _totlower       tolower
#define _totupper       toupper

#if (!defined (__cplusplus) || defined( _NO_INLINING ))

#define _strinc(__a)       ((__a)+1)
#define _strdec(__a, __b)    ((__b)-1)
#define _strnextc(__a)     ((unsigned int) ((__a) ? (__a)[0] : 0))
#define _strninc(__a, __b)   ((__a)+(__b))
#define _strncnt(__a, __b)   ((strlen(__a)>__b) ? __b : strlen(__a))
#define _strspnp(__a, __b)   ((*((__a)+strspn(__a,__b))) ? ((__a)+strspn(__a,__b)) : NULL)

#else  /* (!defined( __cplusplus) || defined( _NO_INLINING )) */

inline char * _RTLENTRY strinc(const char * __s) { return (char *)(__s+1); }
inline char * _RTLENTRY strdec(const char * __s1, const char * __s2) { return (char *)(__s1,(__s2-1)); }

inline char * _RTLENTRY _strinc(const char * __s) { return (char *)(__s+1); }
inline char * _RTLENTRY _strdec(const char * __s1, const char * __s2) { return (char *)(__s1,(__s2-1)); }
inline unsigned int _RTLENTRY _strnextc(const char *__s) { return (unsigned int) (__s ? __s[0] : 0); }
inline char * _RTLENTRY _strninc(const char * __s, _SIZE_T __n) { return (char *)(__s+__n); }
inline _SIZE_T _RTLENTRY _strncnt( const char * __s, _SIZE_T __n) { _SIZE_T __len; __len = strlen(__s); return (__len>__n) ? __n : __len; }
inline char * _RTLENTRY _strspnp( const char * __s1, const char * __s2) { return (*(__s1 += strspn(__s1,__s2))!='\0') ? (char*)__s1 : NULL; }

#endif /* (!defined (__cplusplus) || defined( _NO_INLINING )) */

#endif /* _MBCS */

/* @- */

#else  /* _UNICODE */

#ifdef __cplusplus
namespace std {
#endif

/* @+(UNICODE) types */

#ifndef __TCHAR_DEFINED
typedef wchar_t         _TCHAR;
typedef wchar_t         _TSCHAR;
typedef wchar_t         _TUCHAR;
typedef wchar_t         _TXCHAR;
typedef _WINT_T          _TINT;
#define __TCHAR_DEFINED
#endif

#ifdef __cplusplus
} // std
#endif

/* @: generic text macros */
/* @!:__T */
/* @!:_TEXT */
/* @!:_T */

#define _TEOF             WEOF
#define __T(__x)          L ## __x
#define _TEXT(__x)        __T(__x)
#define _T(__x)           __T(__x)

/* @: string functions */

#define _tcschr         wcschr
#define _tcscspn        wcscspn
#define _tcsncpy        wcsncpy
#define _tcsncat        wcsncat
#define _tcspbrk        wcspbrk
#define _tcsrchr        wcsrchr
#define _tcsspn         wcsspn
#define _tcsstr         wcsstr
#define _tcstok         wcstok
#define _tcsnset        _wcsnset
#define _tcsrev         _wcsrev
#define _tcsset         _wcsset
#define _tcscmp         wcscmp
#define _tcsicmp        _wcsicmp
#define _tcsnccmp       wcsncmp
#define _tcsncmp        wcsncmp
#define _tcsnicmp       _wcsnicmp
#define _tcsncicmp      _wcsnicmp
#define _tcscmpi        wcscmpi
#define _tcsncmpi       wcsncmpi
#define _tcscat         wcscat
#define _tcscpy         wcscpy
#define _tcspcpy        _wcspcpy
#define _tcslen         wcslen
#define _tcsdup         _wcsdup
#define _tcslwr         _wcslwr
#define _tcsupr         _wcsupr
#define _totlower       towlower
#define _totupper       towupper


#define _tcsdec         _wcsdec
#define _tcsinc         _wcsinc
#define _tcsnbcnt       _wcsncnt
#define _tcsnccnt       _wcsncnt
#define _tcsnextc       _wcsnextc
#define _tcsninc        _wcsninc
#define _tcsspnp        _wcsspnp

#define _tcscoll        wcscoll
#define _tcsicoll       _wcsicoll
#define _tcsnccoll      _wcsncoll
#define _tcsncoll       _wcsncoll
#define _tcsncicoll     _wcsnicoll
#define _tcsnicoll      _wcsnicoll
#define _tcsxfrm        wcsxfrm

#define _ltcscoll       _lwcscoll
#define _ltcsicoll      _lwcsicoll
#define _ltcsnccoll     _lwcsncoll
#define _ltcsncoll      _lwcsncoll
#define _ltcsncicoll    _lwcsnicoll
#define _ltcsnicoll     _lwcsnicoll
#define _ltcsxfrm       _lwcsxfrm

/* @: time functions */

#define _tasctime       _wasctime
#define _tutime         _wutime
#define _tctime         _wctime
#define _tstrdate       _wstrdate
#define _tstrtime       _wstrtime
#define _tcsftime       wcsftime
#define _ttzset         _wtzset
#define _ttzname        _wtzname

/* @: ctype functions */

#define _istalnum       iswalnum
#define _istalpha       iswalpha
#define _istdigit       iswdigit
#define _istgraph       iswgraph
#define _istlower       iswlower
#define _istprint       iswprint
#define _istpunct       iswpunct
#define _istspace       iswspace
#define _istupper       iswupper
#define _istascii       iswascii
#define _istcntrl       iswcntrl
#define _istxdigit      iswxdigit

/* @!:_istlegal */
/* @!:_istlead */
/* @!:_istleadbyte */

#define _istlegal(__a)    (1)
#define _istlead(__a)     (0)
#define _istleadbyte(__a) (0)

/* @: process execution functions */

#define _texecl     _wexecl
#define _texecle    _wexecle
#define _texeclp    _wexeclp
#define _texeclpe   _wexeclpe
#define _texecv     _wexecv
#define _texecve    _wexecve
#define _texecvp    _wexecvp
#define _texecvpe   _wexecvpe

#define _tspawnl    _wspawnl
#define _tspawnle   _wspawnle
#define _tspawnlp   _wspawnlp
#define _tspawnlpe  _wspawnlpe
#define _tspawnv    _wspawnv
#define _tspawnve   _wspawnve
#define _tspawnvp   _wspawnvp
#define _tspawnvp   _wspawnvp
#define _tspawnvpe  _wspawnvpe

#define _tsystem        _wsystem

/* @: path/environment specific functions  */

#define _tfullpath      _wfullpath
#define _tsplitpath     _wsplitpath
#define _tfnsplit       _wfnsplit
#define _tfnmerge       _wfnmerge
#define _tmakepath      _wmakepath
#define _tsearchpath    wsearchpath
#define _tsearchenv     _wsearchenv
#define _tsearchstr     _wsearchstr
#define _tgetenv        _wgetenv
#define _tputenv        _wputenv

/* @: I/O functions   */

#define _taccess        _waccess
#define _tchmod         _wchmod
#define _trtl_open      _wrtl_open
#define _trtl_creat     _wrtl_creat
#define _trtl_chmod     _wrtl_chmod
#define _tcreat         _wcreat
#define __tcreat        __wcreat
#define _tfindfirst     _wfindfirst
#define _tfindnext      _wfindnext
#define _tfindclose     _wfindclose
#define __tfindfirsti64 _wfindfirsti64
#define __tfindnexti64  _wfindnexti64
#define __tfinddatai64_t _wfinddatai64_t
#define __tfinddata_t   _wfinddata_t
#define __tfindfirst    __wfindfirst
#define __tfindnext     __wfindnext

#define _tmktemp        _wmktemp
#define _topen          _wopen
#define __topen         __wopen
#define _tremove        _wremove
#define _trename        _wrename
#define _tsopen         _wsopen
#define _tunlink        _wunlink

#define _tffblk         _wffblk

/* @: directory functions */

#define _topendir       wopendir
#define _treaddir       wreaddir
#define _trewinddir     wrewinddir
#define _tclosedir      wclosedir
#define _tDIR           wDIR
#define _tdirent        wdirent

/* @: stdio functions   */

#define _tpopen         _wpopen
#define _tfopen         _wfopen
#define _tfsopen        _wfsopen
#define _tfreopen       _wfreopen
#define _tfdopen        _wfdopen
#define _tperror        _wperror
#define _ttmpnam        _wtmpnam
#define _ttempnam       _wtempnam

/* @: program specific functions */

#define _tmain          wmain
#define _tWinMain       wWinMain
#define _tenviron       _wenviron
#define _targv          _wargv

/* @: directory functions */

#define _tchdir     _wchdir
#define _tgetcurdir _wgetcurdir
#define _tgetcwd    _wgetcwd
#define _tgetdcwd   _wgetdcwd
#define _tmkdir     _wmkdir
#define _trmdir     _wrmdir

/* @: string conversion functions */

#define _ttof           _wtof
#define _ttoi           _wtoi
#define _ttol           _wtol
#define _ttoi64         _wtoi64
#define _ttold          _wtold
#define _tcstod         wcstod
#define _tcstol         wcstol
#define _tcstold        _wcstold
#define _tcstoul        wcstoul
#define _itot           _itow
#define _ltot           _ltow
#define _ultot          _ultow
#define _i64tot         _i64tow
#define _ui64tot        _ui64tow

/* @: stat functions */

#define _tstat          _wstat
#define _tstati64       _wstati64

/* @: setlocale functions */

#define _tsetlocale _wsetlocale

/* @: memory functions */

#define _tmemcpy        _wmemcpy
#define _tmemchr        _wmemchr
#define _tmemset        _wmemset

/* @: unformated I/O */

#define _fgettc         fgetwc
#define _gettc          getwc
#define _fputtc         fputwc
#define _puttc          putwc
#define _fgettchar      _fgetwchar
#define _fgetts         fgetws
#define _fputtchar      _fputwchar
#define _puttchar       putwchar
#define _getts          _getws
#define _fputts         fputws
#define _gettchar       getwchar
#define _putts          _putws
#define _ungettc        ungetwc

/* @: formated I/O */

#define _tprintf        wprintf
#define _vstprintf      vswprintf
#define _stprintf       swprintf
#define _ftprintf       fwprintf
#define _vftprintf      vfwprintf
#define _vtprintf       vwprintf
#define _sntprintf      snwprintf
#define _vsntprintf     vsnwprintf
#define __sntprintf     _snwprintf     // MSC compat.
#define __vsntprintf    _vsnwprintf    // MSC compat.


#define _tscanf         wscanf
#define _stscanf        swscanf
#define _vstscanf       vswscanf
#define _vtscanf        vwscanf
#define _vftscanf       vfwscanf
#define _ftscanf        fwscanf


#define _wcsinc(__a)         ((__a)+1)
#define _wcsdec(__a, __b)    ((__b)-1)
#define _wcsnextc(__a)       ((wchar_t) ((__a) ? (__a)[0] : 0))
#define _wcsninc(__a, __b)   ((__a)+(__b))
#define _wcsncnt(__a, __b)   ((wcslen(__a)>__b) ? __b : wcslen(__a))
#define _wcsspnp(__a, __b)   ((*((__a)+wcsspn(__a,__b))) ? ((__a)+wcsspn(__a,__b)) : NULL)

/* @- */

#endif /* _UNICODE */

#define __targv _targv  /* MS Compatibility */

#ifdef __cplusplus
}
    using std::_TCHAR;
    using std::_TSCHAR;
    using std::_TUCHAR;
    using std::_TXCHAR;
    using std::_TINT;
#endif

#endif  /* __TCHAR_H */
