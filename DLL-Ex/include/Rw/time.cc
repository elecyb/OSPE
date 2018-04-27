#ifndef __TIME_CC
#define __TIME_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * time.cc - Definitions for the Standard Library time facets
 *
 *
 ***************************************************************************
 *
 * Copyright (c) 1994-1999 Rogue Wave Software, Inc.  All Rights Reserved.
 *
 * This computer software is owned by Rogue Wave Software, Inc. and is
 * protected by U.S. copyright laws and other laws and by international
 * treaties.  This computer software is furnished by Rogue Wave Software,
 * Inc. pursuant to a written license agreement and may be used, copied,
 * transmitted, and stored only in accordance with the terms of such
 * license and with the inclusion of the above copyright notice.  This
 * computer software or any other copies thereof may not be provided or
 * otherwise made available to any other person.
 *
 * U.S. Government Restricted Rights.  This computer software is provided
 * with Restricted Rights.  Use, duplication, or disclosure by the
 * Government is subject to restrictions as set forth in subparagraph (c)
 * (1) (ii) of The Rights in Technical Data and Computer Software clause
 * at DFARS 252.227-7013 or subparagraphs (c) (1) and (2) of the
 * Commercial Computer Software – Restricted Rights at 48 CFR 52.227-19,
 * as applicable.  Manufacturer is Rogue Wave Software, Inc., 5500
 * Flatiron Parkway, Boulder, Colorado 80301 USA.
 *
 **************************************************************************/

#include <time.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

// --------------------------------------
// Template time_reader member templates.
// --------------------------------------

template <class charT,class InputIterator>
time_reader<charT,InputIterator>::time_reader
    (InputIterator& in,InputIterator& end,_RW_STD::ios_base& io,
     const __RWSTD::timepunct<charT>& tpunct)
  : digit_reader<charT,InputIterator>(in,end,io), __timp(tpunct)
{
  // Don't recognize signs on any numeric input.
  this->is_signed=false;
}

template <class charT,class InputIterator>
bool time_reader<charT,InputIterator>::
    get_time_pattern (const string_type &patt,tm *time)
{
  enum {
    edit_year    = 0x01,
    edit_month   = 0x02,
    edit_century = 0x04,
    edit_hour    = 0x08
  };

  int post_edits=0;
  const charT *p=patt.c_str(),*patt_end=p+patt.length();
  for ( ; p<patt_end; p++) {
    switch (this->ctyp.narrow(*p,' ')) {
     case '%':
      {
        int *iresult;
        int ampm_dummy;  // scratch space for ampm value
        const keyword_map<charT> *keywords=NULL;

        switch (this->ctyp.narrow(*++p,' ')) {
         case 'a':
         case 'A':
          // Day of week (abbreviated or not).
          keywords=&get_day_map(__timp);
          iresult=&time->tm_wday;
          break;
         case 'b':
         case 'B':
          // Month name (abbreviated or not).
          keywords=&get_month_map(__timp);
          iresult=&time->tm_mon;
          break;
         case 'm':
          // Numeric month, comes in 1 higher than the number we want.
          post_edits|=edit_month;
          iresult=&time->tm_mon;
          break;
         case 'c':
          // Full date, time and year in default format.
          return get_time_pattern(get_patt_string(__timp,2),time);
         case 'd':
          // Day of month.
          iresult=&time->tm_mday;
          break;
         case 'I': // 12-hour clock
         case 'H': // 24-hour clock
          // Hours (12/24 distinction is made in the 'p' section)
          iresult=&time->tm_hour;
          break;
         case 'p':
          // am/pm indicator
          keywords=&get_ampm_map(__timp);
          //  Assumes charT[0] are equal means entire string will be
          if (*(this->in) == get_ampm_string(__timp,true)[0])
            post_edits|=edit_hour;
          iresult=&ampm_dummy;
          break;
         case 'M':
          // Minutes.
          iresult=&time->tm_min;
          break;
         case 'S':
          // Seconds.
          iresult=&time->tm_sec;
          break;
         case 'Y':
          // Year with Century.
          post_edits|=edit_year;
          iresult=&time->tm_year;
          break;
         case 'y':
          // 2-digit Year without Century.
          post_edits|=(edit_year|edit_century);
          iresult=&time->tm_year;
          break;
         default:
          // All other format characters are not supported on input.
          return false;
        }

        if (keywords) {
          if ((*iresult=get_keyword(*keywords))<0)
            return false;
        } else
          *iresult=to_ulong(this->get_int_digits());
      }
      break;

     default:
      if (!this->at_end() && *this->in==*p)
        this->in++;
      else
        return false;
    }

    if (this->error)
      return false;
  }

  if (post_edits&edit_year)
    if (post_edits&edit_century && time->tm_year<100)
      ; // 2-digit year is already relative to 1900
    else
      time->tm_year-=1900;

  if (post_edits&edit_month)
    time->tm_mon--;

  if (post_edits&edit_hour)
    if (time->tm_hour < 12)
      time->tm_hour+=12;

  return true;
}
#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif
// -----------------------------------------------------
// Facet time_get<charT,InputIterator> member templates.
// -----------------------------------------------------

template <class charT, class InputIterator>
locale::id time_get<charT,InputIterator>::id;

template <class charT, class InputIterator>
time_get<charT,InputIterator>::~time_get() { }

template <class charT, class InputIterator>
time_base::dateorder time_get<charT,InputIterator>::do_date_order () const
{
  // We would prefer to return a value that matches the date format defined
  // in the timepunct facet in the caller's locale, but we can't get there
  // from here ...

#ifndef _RWSTD_NO_NAMESPACE
    const _TYPENAME __RWSTD::timepunct<charT>::string_type& s =
        __RWSTD::keyword_cracker<charT>::get_patt_string(*__timp,0);
#else
    const _TYPENAME timepunct<charT>::string_type& s =
        keyword_cracker<charT>::get_patt_string(*__timp,0);
#endif

  bool haveYear = false;

  for (size_t i = 0; i < s.length(); i++) {
    if (s[i] == charT('y') || s[i] == charT('Y')) haveYear = true;
    if (s[i] == charT('d') || s[i] == charT('a') || s[i] == charT('A'))
      if (haveYear) return ydm;
      else return dmy;
    if (s[i] == charT('m') || s[i] == charT('b') || s[i] == charT('B'))
      if (haveYear) return ymd;
      else return mdy;
  }

  return no_order;
}

template <class charT, class InputIterator>
_TYPENAME time_get<charT,InputIterator>::iter_type
time_get<charT,InputIterator>::do_get_time (InputIterator in,
    InputIterator end, ios_base& io, ios_base::iostate& err, tm* time) const
{
  __RWSTD::time_reader<charT,InputIterator> reader(in,end,io,*__timp);
  err=ios_base::goodbit;

  // Parse according to pattern 1 (strftime '%X' -- default time pattern)
  if (!reader.get_time_pattern(reader.get_patt_string(reader.__timp,1),time))
    err=ios_base::failbit;

  if (reader.reached_end)
    err|=ios_base::eofbit;
    
  return in;
}

template <class charT, class InputIterator >
_TYPENAME time_get<charT,InputIterator>::iter_type
time_get<charT,InputIterator>::do_get_date (InputIterator in,
    InputIterator end, ios_base& io, ios_base::iostate& err, tm* time) const
{
  __RWSTD::time_reader<charT,InputIterator> reader(in,end,io,*__timp);
  err=ios_base::goodbit;

  // Parse according to pattern 0 (strftime '%x' -- default date pattern)
  if (!reader.get_time_pattern(reader.get_patt_string(reader.__timp,0),time))
    err=ios_base::failbit;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator >
_TYPENAME time_get<charT,InputIterator>::iter_type
time_get<charT,InputIterator>::do_get_weekday (InputIterator in,
    InputIterator end, ios_base& io, ios_base::iostate& err, tm* time) const
{
  __RWSTD::time_reader<charT,InputIterator> reader(in,end,io,*__timp);
  int wd=reader.get_keyword(reader.get_day_map(reader.__timp));
  err=ios_base::goodbit;

  if (wd<0)
    err=ios_base::failbit;
  else
    time->tm_wday=wd;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator >
_TYPENAME time_get<charT,InputIterator>::iter_type
time_get<charT,InputIterator>::do_get_monthname (InputIterator in,
    InputIterator end, ios_base& io, ios_base::iostate& err, tm* time) const
{
  __RWSTD::time_reader<charT,InputIterator> reader(in,end,io,*__timp);
  int mo=reader.get_keyword(reader.get_month_map(reader.__timp));
  err=ios_base::goodbit;

  if (mo<0)
    err=ios_base::failbit;
  else
    time->tm_mon=mo;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator >
_TYPENAME time_get<charT,InputIterator>::iter_type
time_get<charT,InputIterator>::do_get_year (InputIterator in,
    InputIterator end, ios_base& io, ios_base::iostate& err, tm* time) const
{
  __RWSTD::time_reader<charT,InputIterator> reader(in,end,io,*__timp);
  int yr=reader.to_ulong(reader.get_int_digits());
  err=ios_base::goodbit;

  // 2-digit year numbers are accepted, but are not treated specially, and so
  // end up in the 1st century C.E.
  if (reader.error)
    err=ios_base::failbit;
  else
    time->tm_year=yr-1900;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

// -----------------------------------------------------
// Facet time_put<charT,InputIterator> member templates.
// -----------------------------------------------------

template <class charT, class OutputIterator>
locale::id time_put<charT,OutputIterator>::id;

template <class charT, class OutputIterator>
time_put<charT,OutputIterator>::~time_put() { }

template <class charT, class OutputIterator>
OutputIterator time_put<charT,OutputIterator>::put
    (OutputIterator out, ios_base &io, charT fill, const tm *time,
     const charT* pattern, const charT* patt_end) const
{
  size_t patt_len=patt_end-pattern;
  char scratch[40];
  char *narrow_patt=(patt_len<=sizeof scratch)? scratch : new char[patt_len];
  
  #ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
  use_facet<ctype<charT> >(io.getloc()).narrow(pattern,patt_end,' ',narrow_patt);
  #else
  use_facet(io.getloc(),(ctype<charT>*)0).narrow(pattern,patt_end,' ',narrow_patt);
  #endif

  char *np=narrow_patt;
  for (const charT* wp=pattern; wp<patt_end; wp++,np++)
    if (*np!='%')
      *out++=*wp;
    else if (++wp<patt_end)
      switch (*++np) {

       case 'O':
        // POSIX-style modifier
        if (++wp<patt_end)
          out=do_put(out,io,fill,time,*++np,'O');
        break;

       case '%':
        // Literal percent sign
        *out++=*wp;
        break;

       default:
        // Treat everything else as a time format specifier.
        out=do_put(out,io,fill,time,*np,' ');
      }

  if (narrow_patt!=scratch)
    delete[] narrow_patt;

  return out;
}

template <class charT, class OutputIterator>
OutputIterator time_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base &io, charT fill, const tm *time,
     char format, char modifier) const
{

  static const char do_as_pattern[]="xXcDrT";
  const char *p=strchr(do_as_pattern,format);
  if (p) {
    // Catch formats implemented as calls to the pattern-based method before
    // going to the expense of constructing a digit_writer.
    unsigned i=p-do_as_pattern;
#ifndef _RWSTD_NO_NAMESPACE
    const _TYPENAME __RWSTD::timepunct<charT>::string_type& s =
        __RWSTD::keyword_cracker<charT>::get_patt_string(*__timp,i);
#else
    const _TYPENAME timepunct<charT>::string_type& s =
        keyword_cracker<charT>::get_patt_string(*__timp,i);
#endif
    return put(out,io,fill,time,s.c_str(),s.c_str()+s.length());
  }

  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.width=0;

  if (modifier=='O') {
    // Uppercase letter O (not zero) -- requests ordinal string if defined.
    int n,m;
    switch (format) {
     case 'C':
      // Exclusive Rogue Wave extension: Lets you announce, 
      // "Welcome to the %OC century!"  (See note on unmodified 'C' below.)
      n=(time->tm_year+1999)/100;
      break;
     case 'd':
     case 'e':
      n=time->tm_mday;
      break;
     case 'H':
      n=time->tm_hour+1;
      break;
     case 'I':
      n=time->tm_hour+1;
      if (n>12)
        n-=12;
      break;
     case 'm':
      n=time->tm_mon+1;
      break;
     case 'M':
      n=time->tm_min+1;
      break;
     case 'S':
      n=time->tm_sec+1;
      break;
     case 'u':
      n=time->tm_wday;
      if (n==0) n=7;
      break;
     case 'w':
      n=time->tm_wday;
      break;
     case 'U':
      // Week number of year (assuming weeks start on Sunday).
      // set m to wday of first day of year
      m = (time->tm_wday)-((time->tm_yday)%7);
      // Correct m to account for "days before first Sunday"
      // and "Sunday first day of year" conditions
      if ( m <= 0 ) 
        m += 7;
      if ( m == 7 )
        // Sunday is first day of year
        n = ((time->tm_yday)/7)+1;
      else
        // if not, shift Sunday to first day of week 1
        n = ((time->tm_yday)+m)/7;
      break;
     case 'W':
      // Week number of year (assuming weeks start on Monday).
      // set m to wday of first day of year
      m = (time->tm_wday)-((time->tm_yday)%7);
      // Correct m to account for "days before first Monday"
      // and "Monday first day of year" conditions
      if ( m <= 0 ) 
        m += 7;
      if ( m == 1 )
        // Monday is first day of year
        n = ((time->tm_yday)/7)+1;
      else
        // if not, shift Monday to first day of week 1
        n = (((time->tm_yday)+(m-1))/7);
      break;
     case 'y':
      n=((time->tm_year+1900)%100)+1;
      break;
     default:
      n=999; // Cause error output.
    }

    writer.put_keyword(writer.get_ord_string(*__timp,n),fill);

  } else {
    bool abbrev=false;
#ifndef _RWSTD_NO_NAMESPACE
    const _TYPENAME __RWSTD::timepunct<charT>::string_type *s=NULL;
    _TYPENAME __RWSTD::timepunct<charT>::string_type tzs;
#else
    const _TYPENAME timepunct<charT>::string_type *s=NULL;
    _TYPENAME timepunct<charT>::string_type tzs;
#endif

    int n,m;

    writer.radix=10;
    writer.separable=false;

    switch (format) {
     case 'a':
      abbrev=true;
     case 'A':
      // Week day name or abbreviation.
      s=&writer.get_day_string(*__timp,time->tm_wday,abbrev);
      break;

     case 'b':
     case 'h':
      abbrev=true;
     case 'B':
      // Month name or abbreviation.
      s=&writer.get_month_string(*__timp,time->tm_mon,abbrev);
      break;

     case 'C':
      // Century.  Note that we begin the 20th century in 1901, not 1900.  
      // The draft standard does not seem to address this controversy.
      n=(time->tm_year+1999)/100;
      break;

     case 'd':
      // Day of month with leading zero.
      writer.iprecision=2;
     case 'e':
      // Day of month with leading blank.
      n=time->tm_mday;
      writer.width=2;
      break;

     case 'H':
      // Hour (24-hour clock).
      n=time->tm_hour;
      writer.iprecision=2;
      break;

     case 'I':
      // Hour (12-hour clock, caller must append am/pm to resolve ambiguity).
      n=time->tm_hour;
      if (n==0)
        n=12;
      else if (n>12)
        n-=12;
      writer.iprecision=2;
      break;

     case 'j':
      // 3-digit day of year.
      n=time->tm_yday+1;
      writer.iprecision=3;
      break;

     case 'm':
      // Month number.
      n=time->tm_mon+1;
      writer.iprecision=2;
      break;

     case 'M':
      // Minutes.
      n=time->tm_min;
      writer.iprecision=2;
      break;

     case 'n':
      // Newline character.
      *out++=writer.ctyp.widen('\n');
      break;

     case 'p':
      // ante/post meridian string.
      s=&writer.get_ampm_string(*__timp,time->tm_hour>=12);
      break;

     case 'S':
      // Seconds.
      n=time->tm_sec;
      writer.iprecision=2;
      break;

     case 't':
      // Tab character.
      *out++=writer.ctyp.widen('\t');
      break;

     case 'u':
      // Weekday (1-7, 1==Monday)
      n=time->tm_wday;
      if (n==0)
        n=7;
      break;

     case 'U':
      // Week number of year (assuming weeks start on Sunday).
      // set m to wday of first day of year
      m = (time->tm_wday)-((time->tm_yday)%7);
      // Correct m to account for "days before first Sunday"
      // and "Sunday first day of year" conditions
      if ( m <= 0 ) 
        m += 7;
      if ( m == 7 )
        // Sunday is first day of year
        n = ((time->tm_yday)/7)+1;
      else
        // if not, shift Sunday to first day of week 1
        n = ((time->tm_yday)+m)/7;
      writer.iprecision=2;
      break;

     case 'w':
      // Weekday (0-6, 0==Sunday).
      n=time->tm_wday;
      break;

     case 'W':
      // Week number of year (assuming weeks start on Monday).
      // set m to wday of first day of year
      m = (time->tm_wday)-((time->tm_yday)%7);
      // Correct m to account for "days before first Monday"
      // and "Monday first day of year" conditions
      if ( m <= 0 ) 
        m += 7;
      if ( m == 1 )
        // Monday is first day of year
        n = ((time->tm_yday)/7)+1;
      else
        // if not, shift Monday to first day of week 1
        n = (((time->tm_yday)+(m-1))/7);
      writer.iprecision=2;
      break;

     case 'y':
      // Year without century.
      n=(time->tm_year+1900)%100;
      writer.iprecision=2;
      break;
        
     case 'Y':
      // Year with century.
      n=time->tm_year+1900;
      break;

     case 'Z':

      // Time zone name (This is really standard, isn't it?)
      #ifdef _RWSTD_STRUCT_TM_TZ
      tzs = __RWSTD::timepunct<charT>::string_type(
               writer.ctyp.widen(time->tm_zone));
      s = &tzs;
      break;
      #else
      # ifndef _RWSTD_NO_GLOBAL_TZ
      #  ifndef _RWSTD_STRICT_ANSI
      #  ifdef _RWSTD_NO_LEADING_UNDERSCORE
      tzs = __RWSTD::timepunct<charT>::string_type(
               writer.ctyp.widen(tzname[time->tm_isdst ? 1 : 0]));
      #else
      tzs = __RWSTD::timepunct<charT>::string_type(
               writer.ctyp.widen(_tzname[time->tm_isdst ? 1 : 0]));
      #  endif
      #  else
      charT* __temp;
      __temp = 0;
      #  ifdef _RWSTD_NO_LEADING_UNDERSCORE
      writer.ctyp.widen(tzname[time->tm_isdst ? 1 : 0], tzname[time->tm_isdst ? 1 : 0] + strlen(tzname[time->tm_isdst ? 1 : 0]), __temp);
      #  else
      writer.ctyp.widen(_tzname[time->tm_isdst ? 1 : 0], _tzname[time->tm_isdst ? 1 : 0] + strlen(_tzname[time->tm_isdst ? 1 : 0]), __temp);
      #  endif
      tzs = __temp;
      #  endif
      s = &tzs;
      break;
      # endif // _RWSTD_NO_GLOBAL_TZ
      #endif // _RWSTD_STRUCT_TM_TZ

     default:
      // Everything else is an error.
      s=&writer.get_day_string(*__timp,99,false);
    }

    if (s)
      writer.put_keyword(*s,fill);
    else {
      writer.digitize((unsigned long) n);
      writer.put_digits(fill);
    }
  }

  return out;
}
// --------------------------------------------------------------------
// Time input by-name member templates: time_get<charT,InputIterator>
// --------------------------------------------------------------------

template <class charT, class InputIterator >
time_get_byname<charT, InputIterator>::time_get_byname
    (const char* name, size_t refs): time_get<charT,InputIterator>(refs)
{ 
  this->__name = name;
}

template <class charT, class InputIterator>
time_get_byname<charT, InputIterator>::~time_get_byname()
{ }

// --------------------------------------------------------------------
// Time output by-name member templates: time_put<charT,InputIterator>
// --------------------------------------------------------------------

template <class charT, class OutputIterator>
time_put_byname<charT,OutputIterator>::time_put_byname
    (const char* name, size_t refs): time_put<charT,OutputIterator>(refs)
{ 
  this->__name = name;
}

template <class charT, class OutputIterator>
time_put_byname<charT,OutputIterator>::~time_put_byname()
{ }
#ifndef _RWSTD_NO_NAMESPACE
} 
#endif

#pragma option pop
#endif /* __TIME_CC */
