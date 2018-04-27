/*  stdlib.h

    Definitions for common types, variables, and functions.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.20.1.0  $ */

#ifndef __STDLIB_H
#define __STDLIB_H
#define _INC_STDLIB  /* MSC Guard name */

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#ifndef __SEARCH_H
#include <search.h>  /* Factored out all the search functions to search.h */
#endif

#if !defined(RC_INVOKED)
#if defined(__STDC__)
#pragma warn -nak
#endif
#endif  /* !RC_INVOKED */

#ifdef __cplusplus
extern "C"{
#endif

/* Intrinsics must be prototyped outside of any namespace, so we list them here
   before entering namespace std.
 */
int            _RTLENTRY __abs__(int);
unsigned char  _RTLENTRY ___crotl__(unsigned char __value, int __count);
unsigned char  _RTLENTRY ___crotr__(unsigned char __value, int __count);
unsigned long  _RTLENTRY ___lrotl__(unsigned long __val, int __count);
unsigned long  _RTLENTRY ___lrotr__(unsigned long __val, int __count);
unsigned short _RTLENTRY ___rotl__ (unsigned short __value, int __count);
unsigned short _RTLENTRY ___rotr__ (unsigned short __value, int __count);

#ifdef __cplusplus
} // extern "C"
#endif

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

#if !defined(RC_INVOKED)

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */

#ifndef _DIV_T
#define _DIV_T
typedef struct {
        int     quot;
        int     rem;
} div_t;
#endif

#ifndef _LDIV_T
#define _LDIV_T
typedef struct {
        long    quot;
        long    rem;
} ldiv_t;
#endif

#define MB_CUR_MAX __mb_cur_max

/* Maximum value returned by "rand" function
*/
#define RAND_MAX  0x7FFFU

/* Maximum value returned by "_lrand" function (also used by random() macro)
*/
#define LRAND_MAX 0x7FFFFFFFU

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1

typedef void (_USERENTRY * atexit_t)(void);

/*
  These 2 constants are defined in MS's stdlib.h.
*/

#define DOS_MODE    0  /* DOS 16-bit */
#define OS2_MODE    1  /* OS/2 16-bit */


#ifdef __cplusplus
extern "C" {
#endif

void        _RTLENTRY _EXPFUNC abort(void);

#if !defined(__ABS_DEFINED)
#define __ABS_DEFINED


#ifdef __cplusplus
inline int _RTLENTRY  abs(int __x) { return __abs__(__x); }
#else
int         _RTLENTRY _EXPFUNC abs(int __x);
#  define abs(__x)   __abs__(__x)
#endif

#endif /* __ABS_DEFINED */


int           _RTLENTRY _EXPFUNC atexit(void (_USERENTRY * __func)(void));
double        _RTLENTRY _EXPFUNC atof(const char * __s);
int           _RTLENTRY _EXPFUNC atoi(const char * __s);
long          _RTLENTRY _EXPFUNC atol(const char * __s);
void *        _RTLENTRY _EXPFUNC calloc(_SIZE_T __nitems, _SIZE_T __size);
div_t         _RTLENTRY _EXPFUNC div(int __numer, int __denom);
void          _RTLENTRY _EXPFUNC exit(int __status);
void          _RTLENTRY _EXPFUNC free(void * __block);
char *        _RTLENTRY _EXPFUNC getenv(const char * __name);
long          _RTLENTRY _EXPFUNC labs(long __x);
ldiv_t        _RTLENTRY _EXPFUNC ldiv(long __numer, long __denom);
void *        _RTLENTRY _EXPFUNC malloc(_SIZE_T __size);
int           _RTLENTRY _EXPFUNC mblen(const char * __s, _SIZE_T __n);
_SIZE_T       _RTLENTRY _EXPFUNC mbstowcs(wchar_t *__pwcs, const char * __s,
                                     _SIZE_T __n);
int           _RTLENTRY _EXPFUNC mbtowc(wchar_t *__pwc, const char * __s, _SIZE_T __n);
int           _RTLENTRY _EXPFUNC rand(void);
void *        _RTLENTRY _EXPFUNC realloc(void * __block, _SIZE_T __size);
void          _RTLENTRY _EXPFUNC srand(unsigned __seed);
double        _RTLENTRY _EXPFUNC strtod(const char * __s, char * *__endptr);
long          _RTLENTRY _EXPFUNC strtol(const char * __s, char * *__endptr,
                                     int __radix);
long double   _RTLENTRY _EXPFUNC _strtold(const char * __s, char * *__endptr);
unsigned long _RTLENTRY _EXPFUNC strtoul(const char * __s, char * *__endptr,
                                     int __radix);
int           _RTLENTRY _EXPFUNC system(const char * __command);

_SIZE_T       _RTLENTRY _EXPFUNC wcstombs(char * __s, const wchar_t *__pwcs,_SIZE_T __n);
int           _RTLENTRY _EXPFUNC wctomb(char * __s, wchar_t __wc);
double        _RTLENTRY _EXPFUNC _wtof(const wchar_t * __s);
int           _RTLENTRY _EXPFUNC _wtoi(const wchar_t * __s);
long          _RTLENTRY _EXPFUNC _wtol(const wchar_t * __s);
long double   _RTLENTRY _EXPFUNC _wtold(const wchar_t * __s);
double        _RTLENTRY _EXPFUNC wcstod(const wchar_t * __s, wchar_t * *__endptr);
long          _RTLENTRY _EXPFUNC wcstol(const wchar_t * __s, wchar_t * *__endptr, int __radix);
long double   _RTLENTRY _EXPFUNC _wcstold(const wchar_t * __s, wchar_t * *__endptr);
unsigned long _RTLENTRY _EXPFUNC wcstoul(const wchar_t * __s, wchar_t * *__endptr, int __radix);
int           _RTLENTRY _EXPFUNC _wsystem(const wchar_t * __command);
wchar_t *     _RTLENTRY _EXPFUNC _itow(int __value, wchar_t *__string, int __radix);
wchar_t *     _RTLENTRY _EXPFUNC _ltow(long __value, wchar_t *__string, int __radix);
wchar_t *     _RTLENTRY _EXPFUNC _ultow(unsigned long __value, wchar_t *__string, int __radix);

#if !defined(__STDC__)
#if defined (_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
__int64       _RTLENTRY _EXPFUNC _atoi64(const char * __s);
char *        _RTLENTRY _EXPFUNC _i64toa(__int64 __value, char *__strP, int __radix);
char *        _RTLENTRY _EXPFUNC _ui64toa(unsigned __int64 __value, char *__strP, int __radix);
__int64       _RTLENTRY _EXPFUNC _wtoi64(const wchar_t * __s);
wchar_t *     _RTLENTRY _EXPFUNC _i64tow(__int64 __value, wchar_t *__strP, int __radix);
wchar_t *     _RTLENTRY _EXPFUNC _ui64tow(unsigned __int64 __value, wchar_t *__strP, int __radix);
#endif
char *        _RTLENTRY _EXPFUNC ltoa(long __value, char * __string, int __radix);
char *        _RTLENTRY _EXPFUNC ecvt(double __value, int __ndig, int * __dec, int * __sign);
char *        _RTLENTRY _EXPFUNC fcvt(double __value, int __ndig, int * __dec, int * __sign);
char *        _RTLENTRY _EXPFUNC gcvt(double __value, int __ndec, char * __buf);

#endif /* __STDC__ */


/* Variables */

#ifdef _MT

extern  int * _RTLENTRY _EXPFUNC __errno(void);
extern  int * _RTLENTRY _EXPFUNC __doserrno(void);
#define errno (*__errno())
#define _doserrno (*__doserrno())

#else   /* MT */

extern  int   _RTLENTRY _EXPDATA errno;
extern  int   _RTLENTRY _EXPDATA _doserrno;

#endif  /* MT */

extern  int   _RTLENTRY _EXPDATA __mb_cur_max;

#if !defined(__STDC__)

/* Values for _osmode */

#define _WIN_MODE    2  /* Windows 16- or 32-bit */
#define _OS2_20_MODE 3  /* OS/2 32-bit */
#define _DOSX32_MODE 4  /* DOS 32-bit */

#define environ  _environ

/* MSC compatible routines: */

void _RTLENTRY _EXPFUNC _seterrormode(int __mode);

#endif /* __STDC__ */

extern char **       _RTLENTRY _EXPDATA _environ;
extern wchar_t **    _RTLENTRY _EXPDATA _wenviron;
extern int           _RTLENTRY _EXPDATA _fileinfo;
extern int           _RTLENTRY          _fmode;
extern unsigned char _RTLENTRY _EXPDATA _osmajor;
extern unsigned char _RTLENTRY _EXPDATA _osminor;
extern unsigned char _RTLENTRY _EXPDATA _osmode;
extern unsigned int  _RTLENTRY _EXPDATA _osversion;
extern int           _RTLENTRY _EXPDATA _cmdline_escapes;


#if !defined(__STDC__)
#define sys_nerr     _sys_nerr
#define sys_errlist  _sys_errlist
#endif

extern char *        _RTLENTRY _EXPDATA _sys_errlist[];
extern int           _RTLENTRY _EXPDATA _sys_nerr;

#ifdef __cplusplus
}
#endif

#if !defined(__STDC__) && !defined(__CODEGUARD__)
#ifdef __cplusplus
   inline int _RTLENTRY atoi(const char *__s) { return (int)atol(__s); }
#else
#  define atoi(__s)((int) atol(__s))
#endif
#endif

/* Constants for MSC pathname functions */

#define _MAX_PATH       260
#define _MAX_DRIVE      3
#define _MAX_DIR        256
#define _MAX_FNAME      256
#define _MAX_EXT        256

#ifdef __cplusplus
extern "C" {
#endif

long double   _RTLENTRY _EXPFUNC _atold(const char * __s);

unsigned char _RTLENTRY _EXPFUNC _crotl(unsigned char __value, int __count);
unsigned char _RTLENTRY _EXPFUNC _crotr(unsigned char __value, int __count);

char *        _RTLENTRY _EXPFUNC _ecvt(double __value, int __ndig, int * __dec,
                                     int * __sign);
void          _RTLENTRY _EXPFUNC _exit(int __status);
char *        _RTLENTRY _EXPFUNC _fcvt(double __value, int __ndig, int * __dec,
                                     int * __sign);
char *        _RTLENTRY _EXPFUNC _fullpath(char * __buf, const char * __path,
                                     _SIZE_T __maxlen);
char *        _RTLENTRY _EXPFUNC _gcvt(double __value, int __ndec,
                                     char * __buf);
char *        _RTLENTRY _EXPFUNC itoa(int __value, char * __string,
                                     int __radix);
long          _RTLENTRY _EXPFUNC _lrand(void);
unsigned long _RTLENTRY _EXPFUNC _lrotl(unsigned long __val, int __count);
unsigned long _RTLENTRY _EXPFUNC _lrotr(unsigned long __val, int __count);

char *        _RTLENTRY _EXPFUNC _ltoa(long __value, char * __string,
                                     int __radix);
void          _RTLENTRY _EXPFUNC _makepath(char * __path,
                                     const char * __drive,
                                     const char * __dir,
                                     const char * __name,
                                     const char * __ext );
int           _RTLENTRY _EXPFUNC putenv(const char * __name);

unsigned short _RTLENTRY _EXPFUNC _rotl(unsigned short __value, int __count);
unsigned short _RTLENTRY _EXPFUNC _rotr(unsigned short __value, int __count);

void          _RTLENTRY _EXPFUNC _searchenv(const char * __file,
                                     const char * __varname,
                                     char *__pathname);
void          _RTLENTRY _EXPFUNC _searchstr(const char * __file,
                                     const char * __ipath,
                                     char *__pathname);
void          _RTLENTRY _EXPFUNC _splitpath(const char * __path,
                                     char * __drive,
                                     char * __dir,
                                     char * __name,
                                     char * __ext );
void          _RTLENTRY _EXPFUNC swab(char * __from, char * __to, int __nbytes);
char *        _RTLENTRY _EXPFUNC ultoa(unsigned long __value, char * __string,
                                     int __radix);
void          _RTLENTRY _EXPFUNC perror(const char * __s);

void          _RTLENTRY _EXPFUNC _wperror(const wchar_t * __s);
wchar_t *     _RTLENTRY _EXPFUNC _wfullpath(wchar_t * __buf,const wchar_t * __path,
                                     _SIZE_T __maxlen);
void          _RTLENTRY _EXPFUNC _wmakepath(wchar_t * __path,
                                     const wchar_t * __drive,
                                     const wchar_t * __dir,
                                     const wchar_t * __name,
                                     const wchar_t * __ext );
void          _RTLENTRY _EXPFUNC _wsplitpath(const wchar_t * __path,
                                     wchar_t * __drive,
                                     wchar_t * __dir,
                                     wchar_t * __name,
                                     wchar_t * __ext );

void          _RTLENTRY _EXPFUNC _wsearchenv(const wchar_t * __file,
                                     const wchar_t * __varname,
                                     wchar_t *__pathname);
void          _RTLENTRY _EXPFUNC _wsearchstr(const wchar_t * __file,
                                     const wchar_t * __ipath,
                                     wchar_t *__pathname);
wchar_t *     _RTLENTRY _EXPFUNC  _wgetenv(const wchar_t * __name);
int           _RTLENTRY _EXPFUNC  _wputenv(const wchar_t * __name);

#ifdef __cplusplus
}
#endif

#if !defined(__STDC__)

#if defined(__cplusplus)
inline int  _RTLENTRY random(int __num)
                       { return __num ? (int)(_lrand()%(__num)) : 0; }
#else /* __cplusplus */
#define random(__num) (__num ? (int)(_lrand()%(__num)) : 0)
#endif  /* __cplusplus  */

#endif /* __STDC__ */

#if defined(__cplusplus)
extern "C" {
#endif
long _RTLENTRY _EXPFUNC time(long *);
#if defined(__cplusplus)
}
#endif

#if !defined(__STDC__)

#if defined(__cplusplus)

/* Need prototype of time() for C++ randomize() */
inline void _RTLENTRY randomize(void) { srand((unsigned) time(NULL)); }

#if defined(__MFC_COMPAT__)
#if !defined( __MINMAX_DEFINED)
#define __MINMAX_DEFINED
#define NOMINMAX    /* for WINDEF.H */
#undef min  // make sure these aren't macros
#undef max
/*
  MFC code sometimes contains usages of min() and max() of dis-similar types
  which prevents using a normal template implementation.  We cannot
  implement min and max as macros (like Microsoft does), since parts of the
  Rogue Wave Standard Library need to #undef them.

  So we start by providing the normal template implementation and then also
  provide a global, non-template version, of min and max that take and
  return unsigned longs. The theory is that the compiler will first look at
  the non-template version and promote both params to unsigned long before
  looking at the template version and failing because of the two different
  types involved.
*/
template <class _T> inline const _T _FAR &min( const _T _FAR &__t1, const _T _FAR &__t2 )
{
    if  (__t1 < __t2)
        return __t1;
    else
        return __t2;
}

template <class _T> inline const _T _FAR &max( const _T _FAR &__t1, const _T _FAR &__t2 )
{
    if  (__t1 > __t2)
        return __t1;
    else
        return __t2;
}

inline unsigned long min (unsigned long __a, unsigned long __b)
{
    return min<unsigned long> (__a, __b);
}

inline unsigned long max (unsigned long __a, unsigned long __b)
{
    return max<unsigned long> (__a, __b);
}
#define __max       max
#define __min       min
#endif /*__MINMAX_DEFINED */

inline char * _RTLENTRY  _ecvt(double __value, int __ndig, int * __dec,
                            int * __sign)
                            { return ecvt (__value, __ndig, __dec, __sign); }
inline char * _RTLENTRY  _fcvt(double __value, int __ndig, int * __dec,
                            int * __sign)
                            { return fcvt (__value, __ndig, __dec, __sign); }
inline char * _RTLENTRY  _gcvt(double __value, int __ndec,
                            char * __buf)
                            { return gcvt(__value, __ndec, __buf); }
inline char * _RTLENTRY _itoa(int __value, char * __string,
                            int __radix)
                            { return itoa(__value, __string, __radix); }
inline char * _RTLENTRY _ltoa(long __value, char * __string,
                            int __radix)
                            { return ltoa(__value, __string, __radix); }
inline char * _RTLENTRY _ultoa(unsigned long __value, char * __string,
                            int __radix)
                            { return ultoa(__value, __string, __radix); }
inline int    _RTLENTRY _putenv(const char * __name) {return putenv(__name);}
inline void   _RTLENTRY _swab(char * __from, char * __to, int __nbytes)
                            { swab (__from, __to, __nbytes); }
#else   /* __MFC_COMPAT__ */
#if !defined( __MINMAX_DEFINED) && defined(__cplusplus)
#define __MINMAX_DEFINED
#undef min  // make sure these aren't macros
#undef max
template <class _T> inline const _T _FAR &min( const _T _FAR &__t1, const _T _FAR &__t2 )
{
    if  (__t1 < __t2)
        return __t1;
    else
        return __t2;
}

template <class _T> inline const _T _FAR &max( const _T _FAR &__t1, const _T _FAR &__t2 )
{
    if  (__t1 > __t2)
        return __t1;
    else
        return __t2;
}
#endif
#endif /* __MFC_COMPAT__ */

#else /* __cplusplus */

#define randomize() srand((unsigned)time(NULL))
#ifndef max
#define max(__a,__b)    (((__a) > (__b)) ? (__a) : (__b))
#endif
#ifndef min
#define min(__a,__b)    (((__a) < (__b)) ? (__a) : (__b))
#endif
#endif /* __cplusplus */

#endif /* __STDC__ */

#if defined(__MSC) && !defined(__MFC_COMPAT__)
#define _itoa(__value, __string, __radix) itoa(__value, __string, __radix)
#endif

/* argv & argc definitions */

#ifdef __cplusplus
extern "C"{
#endif
#if !defined(__ARGV_DEFINED)
#define __ARGV_DEFINED
    extern int           _RTLENTRY _EXPDATA _argc;
    extern char **       _RTLENTRY _EXPDATA _argv;
#   define __argc        _argc  /* MSC Version */
#   define __argv        _argv  /* MSC Version */
#endif /* __ARGV_DEFINED */
#ifdef __cplusplus
} /* __cplusplus */
#endif


#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
} // std
#endif /* __cplusplus */

#endif  /* __STDLIB_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__STDLIB_H_USING_LIST)
#define __STDLIB_H_USING_LIST
     using std::_argc;
     using std::_argv;
#ifdef _MT
     using std::__doserrno;
     using std::__errno;
#else
     using std::_doserrno;
     using std::errno;
#endif
     using std::__mb_cur_max;

     using std::_ecvt;
     using std::_atold;
     using std::_cmdline_escapes;
     using std::_environ;
     using std::_exit;
     using std::_fileinfo;
     using std::_fmode;
     using std::_fullpath;
     using std::_fcvt;
     using std::_gcvt;

#if defined(__MFC_COMPAT__)
     using std::_itoa;
     using std::_ultoa;
     using std::_putenv;
     using std::_swab;
#endif

     using std::_ultow;
     using std::_itow;
     using std::_lrand;
     using std::_ltoa;
     using std::_ltow;

#if !defined(__STDC__) && defined (_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
     using std::_atoi64;
     using std::_i64toa;
     using std::_i64tow;
     using std::_ui64toa;
     using std::_ui64tow;
     using std::_wtoi64;
#endif

     using std::_makepath;
     using std::_osmajor;
     using std::_osminor;
     using std::_osmode;
     using std::_osversion;
     using std::_searchenv;
     using std::_searchstr;
     using std::_splitpath;
     using std::_strtold;
     using std::_sys_errlist;
     using std::_sys_nerr;
     using std::_wcstold;
     using std::_wenviron;
     using std::_wfullpath;
     using std::_wgetenv;
     using std::_wmakepath;
     using std::_wperror;
     using std::_wputenv;
     using std::_wsearchenv;
     using std::_wsearchstr;
     using std::_wsplitpath;
     using std::_wsystem;
     using std::_wtof;
     using std::_wtoi;
     using std::_wtol;
     using std::_wtold;
     using std::abort;
     using std::atexit;
     using std::atexit_t;
     using std::atof;
     using std::atoi;
     using std::atol;
     using std::calloc;
     using std::div;
     using std::div_t;
     using std::exit;
     using std::free;
     using std::getenv;
     using std::itoa;
     using std::labs;
     using std::ldiv;
     using std::ldiv_t;
     using std::malloc;

#if !defined(__STDC__)
     using std::ecvt;
     using std::fcvt;
     using std::gcvt;
     using std::ltoa;
     using std::random;
     using std::randomize;
#endif

#if !defined(__STDC__) // The standard says that min() and max() should only
     using std::min;   // come in from algorith.h, but we'll allow it here
     using std::max;   // unless -A is specified
     using std::_seterrormode;
#endif
     using std::mblen;
     using std::mbstowcs;
     using std::mbtowc;
     using std::perror;
     using std::putenv;
     using std::rand;
     using std::realloc;
     using std::srand;
     using std::strtod;
     using std::strtol;
     using std::strtoul;
     using std::swab;
     using std::system;
     using std::time;
     using std::ultoa;
     using std::wcstod;
     using std::wcstol;
     using std::wcstombs;
     using std::wcstoul;
     using std::wctomb;

/*
   Handle intrinsics specially.  If intrinsics are on, the compiler creates
   a macro of the normal function mapping to the __ intrinsic version, ie:
     #define strcpy __strcpy__
   Thus, we can test the normal name as a macro to see if it's defined, and
   only preform a using statement if it's not an intrinsic
*/

#    ifndef abs
       using std::abs;
#    endif // ifndef abs
#    ifndef _crotl
       using std::_crotl;
#    endif // ifndef _crotl
#    ifndef _lrotl
       using std::_lrotl;
#    endif // ifndef _lrotl
#    ifndef _lrotr
       using std::_lrotr;
#    endif // ifndef _lrotr
#    ifndef _crotr
       using std::_crotr;
#    endif // ifndef _crotr
#    ifndef _rotl
       using std::_rotl;
#    endif // ifndef _rotl
#    ifndef _rotr
       using std::_rotr;
#    endif // ifndef _rotr

#endif /* __USING_CNAME__ */
