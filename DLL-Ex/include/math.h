
/*  math.h

    Definitions for the math floating point package.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.13.1.0  $ */

#ifndef  __MATH_H
#define  __MATH_H

#if !defined(___STDDEF_H)
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */


#if !defined(__STDC__) /* NON-ANSI */

#ifdef __cplusplus
  extern "C" {
#endif

/* Intrinsic functions listed before any namespace */

double      _RTLENTRY __sin__ (double __x);
double      _RTLENTRY __cos__ (double __x);
long double _RTLENTRY __cosl__(long double __x);
long double _RTLENTRY __sinl__(long double __x);
int         _RTLENTRY __abs__ (int);

/* matherr and struct _exception must not be availible in __STDC__ nor
   can they be in namespace std since user's won't be able to override them
   there.
*/

#ifndef __STDC__
/* In "C" mode, (but not in standard C mode) we can allow the old name of
   'exception' for this structure.
 */
#ifndef __cplusplus
#define _exception exception
#endif
#endif /* __STDC__ */



struct  _exception
{
    int type;
    char   _FAR *name;
    double  arg1, arg2, retval;
};

struct  _exceptionl
{
    int type;
    char   _FAR *name;
    long double  arg1, arg2, retval;
};

typedef enum
{
    DOMAIN = 1,    /* argument domain error -- log (-1)        */
    SING,          /* argument singularity  -- pow (0,-2))     */
    OVERFLOW,      /* overflow range error  -- exp (1000)      */
    UNDERFLOW,     /* underflow range error -- exp (-1000)     */
    TLOSS,         /* total loss of significance -- sin(10e70) */
    PLOSS,         /* partial loss of signif. -- not used      */
    STACKFAULT     /* floating point unit stack overflow       */
}   _mexcep;

int         _RTLENTRY          _matherr(struct _exception  *__e);
int         _RTLENTRY          _matherrl(struct _exceptionl *__e);

#ifdef __cplusplus
}  // extern "C"
#endif

#ifdef __cplusplus
    /* use class complex instead of _cabs in C++ (now in STL 2.0) */
#else
struct complex      /* as used by "_cabs" function */
{
    double  x, y;
};

struct _complexl    /* as used by "_cabsl" function */
{
    long double  x, y;
};

#define cabs(z)     (hypot  ((z).x, (z).y))
#define cabsl(z)    (hypotl ((z).x, (z).y))
#endif /* __cplusplus */
#endif /* NON-ANSI */

#ifdef __cplusplus
  namespace std {
#endif


/* Constants rounded for 21 decimals. */
#define M_E         2.71828182845904523536
#define M_LOG2E     1.44269504088896340736
#define M_LOG10E    0.434294481903251827651
#define M_LN2       0.693147180559945309417
#define M_LN10      2.30258509299404568402
#define M_PI        3.14159265358979323846
#define M_PI_2      1.57079632679489661923
#define M_PI_4      0.785398163397448309616
#define M_1_PI      0.318309886183790671538
#define M_2_PI      0.636619772367581343076
#define M_1_SQRTPI  0.564189583547756286948
#define M_2_SQRTPI  1.12837916709551257390
#define M_SQRT2     1.41421356237309504880
#define M_SQRT_2    0.707106781186547524401

#define EDOM    33      /* Math argument */
#define ERANGE  34      /* Result too large */


#ifdef __cplusplus
extern "C" {
#endif

#define HUGE_VAL    _huge_dble
extern double _RTLENTRY _EXPDATA _huge_dble;
#define _LHUGE_VAL   _huge_ldble
extern long double _RTLENTRY _EXPDATA _huge_ldble;

double      _RTLENTRY _EXPFUNC acos    (double __x);
double      _RTLENTRY _EXPFUNC asin    (double __x);
double      _RTLENTRY _EXPFUNC atan    (double __x);
double      _RTLENTRY _EXPFUNC atan2   (double __y, double __x);
double      _RTLENTRY _EXPFUNC ceil    (double __x);
double      _RTLENTRY _EXPFUNC cos     (double __x);
double      _RTLENTRY _EXPFUNC cosh    (double __x);
double      _RTLENTRY _EXPFUNC exp     (double __x);
double      _RTLENTRY _EXPFUNC fabs    (double __x);
double      _RTLENTRY _EXPFUNC floor   (double __x);
double      _RTLENTRY _EXPFUNC fmod    (double __x, double __y);
double      _RTLENTRY _EXPFUNC frexp   (double __x, int * __exponent);
double      _RTLENTRY _EXPFUNC ldexp   (double __x, int __exponent);
double      _RTLENTRY _EXPFUNC log     (double __x);
double      _RTLENTRY _EXPFUNC log10   (double __x);
double      _RTLENTRY _EXPFUNC modf    (double __x, double * __ipart);
double      _RTLENTRY _EXPFUNC pow     (double __x, double __y);
double      _RTLENTRY _EXPFUNC sin     (double __x);
double      _RTLENTRY _EXPFUNC sinh    (double __x);
double      _RTLENTRY _EXPFUNC sqrt    (double __x);
double      _RTLENTRY _EXPFUNC tan     (double __x);
double      _RTLENTRY _EXPFUNC tanh    (double __x);

long double _RTLENTRY _EXPFUNC acosl  (long double __x);
long double _RTLENTRY _EXPFUNC asinl  (long double __x);
long double _RTLENTRY _EXPFUNC atan2l (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC atanl  (long double __x);
long double _RTLENTRY _EXPFUNC ceill  (long double __x);
long double _RTLENTRY _EXPFUNC coshl  (long double __x);
long double _RTLENTRY _EXPFUNC cosl   (long double __x);
long double _RTLENTRY _EXPFUNC expl   (long double __x);
long double _RTLENTRY _EXPFUNC fabsl  (long double __x);
long double _RTLENTRY _EXPFUNC floorl (long double __x);
long double _RTLENTRY _EXPFUNC fmodl  (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC frexpl (long double __x, int * __exponent);
long double _RTLENTRY _EXPFUNC ldexpl (long double __x, int __exponent);
long double _RTLENTRY _EXPFUNC log10l (long double __x);
long double _RTLENTRY _EXPFUNC logl   (long double __x);
long double _RTLENTRY _EXPFUNC modfl  (long double __x, long double * __ipart);
long double _RTLENTRY _EXPFUNC powl   (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC sinhl  (long double __x);
long double _RTLENTRY _EXPFUNC sinl   (long double __x);
long double _RTLENTRY _EXPFUNC sqrtl  (long double __x);
long double _RTLENTRY _EXPFUNC tanhl  (long double __x);
long double _RTLENTRY _EXPFUNC tanl   (long double __x);


double      _RTLENTRY _EXPFUNC atof    (const char * __s);

#if !defined(__STDC__) /* NON_ANSI */

#if !defined(__ABS_DEFINED)
#define __ABS_DEFINED
#ifdef __cplusplus
inline int _RTLENTRY  abs(int __x) { return __abs__(__x); }
#else
int         _RTLENTRYF _EXPFUNC abs(int __x);
#  define abs(x)   __abs__(x)
#endif
#endif /* __ABS_DEFINED */

long        _RTLENTRY _EXPFUNC labs    (long __x);
double      _RTLENTRY _EXPFUNC pow10   (int __p);

long double _RTLENTRY _EXPFUNC _atold  (const char * __s);


double      _RTLENTRY _EXPFUNC hypot   (double __x, double __y);
double      _RTLENTRY _EXPFUNC poly    (double __x, int __degree, double __coeffs []);
long double _RTLENTRY _EXPFUNC hypotl  (long double __x, long double __y);
long double _RTLENTRY _EXPFUNC polyl   (long double __x, int __degree, long double __coeffs []);
long double _RTLENTRY _EXPFUNC pow10l  (int __p);

#if defined (_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
__int64     _RTLENTRY _EXPFUNC   _atoi64(const char * __s);
char *      _RTLENTRY   _EXPFUNC _i64toa(__int64 __value, char *__strP, int __radix);
char *      _RTLENTRY   _EXPFUNC _ui64toa(unsigned __int64 __value, char *__strP, int __radix);
__int64     _RTLENTRY _EXPFUNC   _wtoi64(const wchar_t * __s);
wchar_t *   _RTLENTRY   _EXPFUNC _i64tow(__int64 __value, wchar_t *__strP, int __radix);
wchar_t *   _RTLENTRY   _EXPFUNC _ui64tow(unsigned __int64 __value, wchar_t *__strP, int __radix);
#endif
double      _RTLENTRY _EXPFUNC   _wtof(const wchar_t * __s);
int         _RTLENTRY _EXPFUNC   _wtoi(const wchar_t * __s);
long        _RTLENTRY _EXPFUNC   _wtol(const wchar_t * __s);
long double _RTLENTRY _EXPFUNC   _wtold(const wchar_t * __s);

#endif  /* !__STDC__ */

#ifdef __cplusplus
} // extern "C"
} // std
#endif /* __cplusplus */

#if !defined(RC_INVOKED)

/* restore default packing */
#pragma pack(pop)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */
#endif  /* __MATH_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__MATH_H_USING_LIST)
#define __MATH_H_USING_LIST
    using std::_huge_dble;
    using std::_huge_ldble;
    using std::acos;
    using std::asin;
    using std::atan;
    using std::atan2;
    using std::ceil;
    using std::cosh;
    using std::exp;
    using std::fabs;
    using std::floor;
    using std::fmod;
    using std::frexp;
    using std::ldexp;
    using std::log;
    using std::log10;
    using std::modf;
    using std::pow;
    using std::sinh;
    using std::sqrt;
    using std::tan;
    using std::tanh;
    using std::acosl;
    using std::asinl;
    using std::atan2l;
    using std::atanl;
    using std::ceill;
    using std::coshl;
    using std::expl;
    using std::fabsl;
    using std::floorl;
    using std::fmodl;
    using std::frexpl;
    using std::ldexpl;
    using std::log10l;
    using std::logl;
    using std::modfl;
    using std::powl;
    using std::sinhl;
    using std::sqrtl;
    using std::tanhl;
    using std::tanl;
    using std::atof;

/*
   Handle intrinsics specially.  If intrinsics are on, the compiler creates
   a macro of the normal function mapping to the __ intrinsic version, ie:
     #define strcpy __strcpy__
   Thus, we can test the normal name as a macro to see if it's defined, and
   only preform a using statement if it's not an intrinsic
*/

#   ifndef sin
      using std::sin;
#   endif // ifndef sin
#   ifndef cos
      using std::cos;
#   endif // ifndef cos
#   ifndef sinl
      using std::sinl;
#   endif // ifndef sinl
#   ifndef cosl
      using std::cosl;
#   endif // ifndef cosl

# if !defined(__STDC__) /* NON_ANSI */
#   ifndef abs
      using std::abs;
#   endif // ifndef abs

    using std::labs;
    using std::pow10;
    using std::_atold;
    using std::hypot;
    using std::poly;
    using std::hypotl;
    using std::polyl;
    using std::pow10l;

# if defined (_INTEGRAL_MAX_BITS) && (_INTEGRAL_MAX_BITS >= 64)
    using std::_atoi64;
    using std::_i64toa;
    using std::_ui64toa;
    using std::_wtoi64;
    using std::_i64tow;
    using std::_ui64tow;
    using std::_wtof;
    using std::_wtoi;
    using std::_wtol;
    using std::_wtold;
# endif // _INTEGRAL_MAX_BITS
# endif // !__STDC__
#endif /* __USING_CNAME__ */

#if defined(_FM_USE_FASTMATH) && !defined(__FASTMATH_H)
#   include <fastmath.h>
#endif /* _FM_USE_FASTMATH */

