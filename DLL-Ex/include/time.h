/*  time.h

    Struct and function declarations for dealing with time.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1987, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.9  $ */

#ifndef __TIME_H
#define __TIME_H
#define _INC_TIME  /* MSC Guard name */

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#ifdef __cplusplus
namespace std {
#endif /* __cplusplus */

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#pragma pack(push, 1)

#endif  /* !RC_INVOKED */


#ifndef  _TIME_T
typedef long time_t;
#ifdef __cplusplus
#  define _TIME_T std::time_t
#else
#  define _TIME_T time_t
#endif /* __cplusplus */
#endif

#ifndef  _CLOCK_T
#define  _CLOCK_T
typedef long clock_t;
#endif

#define CLOCKS_PER_SEC 1000.0
#define CLK_TCK        1000.0

struct tm
{
  int   tm_sec;
  int   tm_min;
  int   tm_hour;
  int   tm_mday;
  int   tm_mon;
  int   tm_year;
  int   tm_wday;
  int   tm_yday;
  int   tm_isdst;
};

#ifdef __cplusplus
extern "C" {
#endif
char  *     _RTLENTRY _EXPFUNC asctime(const struct tm *__tblock);
char  *     _RTLENTRY _EXPFUNC ctime(const time_t *__time);
double      _RTLENTRY _EXPFUNC difftime(time_t __time2, time_t __time1);
struct tm * _RTLENTRY _EXPFUNC gmtime(const time_t *__timer);
struct tm * _RTLENTRY _EXPFUNC localtime(const time_t *__timer);
time_t      _RTLENTRY _EXPFUNC time(time_t *__timer);
time_t      _RTLENTRY _EXPFUNC mktime(struct tm *__timeptr);
clock_t     _RTLENTRY _EXPFUNC clock(void);
_SIZE_T     _RTLENTRY _EXPFUNC strftime(char *__s, _SIZE_T __maxsize,
                                        const char *__fmt, const struct tm *__t);
_SIZE_T     _RTLENTRY _EXPFUNC _lstrftim(char  *__s, _SIZE_T __maxsize,
                                          const char *__fmt, const struct tm *__t);
wchar_t   * _RTLENTRY _EXPFUNC _wasctime(const struct tm *__tblock);
wchar_t   * _RTLENTRY _EXPFUNC _wctime(const time_t *__time);
wchar_t   * _RTLENTRY _EXPFUNC _wstrdate(wchar_t *__datestr);
wchar_t   * _RTLENTRY _EXPFUNC _wstrtime(wchar_t *__timestr);
_SIZE_T     _RTLENTRY _EXPFUNC wcsftime(wchar_t *__s, _SIZE_T __maxsize,
                                        const wchar_t *__fmt, const struct tm *__t);
void        _RTLENTRY _EXPFUNC _wtzset(void);

extern int               _RTLENTRY _EXPDATA _daylight;
extern long              _RTLENTRY _EXPDATA _timezone;
extern char *    const   _RTLENTRY _EXPDATA _tzname[2];
extern wchar_t * const   _RTLENTRY _EXPDATA _wtzname[2];

int         _RTLENTRY          stime(time_t *__tp);
void        _RTLENTRY _EXPFUNC _tzset(void);
char  *     _RTLENTRY _EXPFUNC _strdate(char *__datestr);
char  *     _RTLENTRY _EXPFUNC _strtime(char *__timestr);

#if !defined(__STDC__)
void        _RTLENTRY  _EXPFUNC tzset(void);

/* MSC compatible routines: */
unsigned int _RTLENTRY _EXPFUNC _getsystime(struct tm *__timeptr);
unsigned int _RTLENTRY _EXPFUNC _setsystime(struct tm *__timeptr, unsigned int __ms);

#endif  /* __STDC__  */

#ifdef __cplusplus
}
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
#endif

#endif  /* __TIME_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__TIME_H_USING_LIST)
#define __TIME_H_USING_LIST
     using std::time_t;
     using std::clock_t;
     using std::tm;
     using std::asctime;
     using std::ctime;
     using std::difftime;
     using std::gmtime;
     using std::localtime;
     using std::time;
     using std::mktime;
     using std::clock;
     using std::strftime;
     using std::_lstrftim;
     using std::_wasctime;
     using std::_wctime;
     using std::_wstrdate;
     using std::_wstrtime;
     using std::wcsftime;
     using std::_wtzset;
     using std::stime;
     using std::_tzset;
     using std::_strdate;
     using std::_strtime;
     using std::_daylight;
     using std::_timezone;
     using std::_tzname;
     using std::_wtzname;
#if !defined(__STDC__)
     using std::tzset;
     using std::_getsystime;
     using std::_setsystime;
#endif
#endif /* __USING_CNAME__ */

