#ifndef __IOMANIP_H
#define __IOMANIP_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_IOMANIP__
#define __STD_IOMANIP__

/***************************************************************************
 *
 * iomanip - Declarations for the iomanip classes
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

#include <stdcomp.h>
#include <iostream> 

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif
  
  /*
   * class smanip
   */

  template<class T>
  class smanip {

  public:
    smanip(ios_base& (*pf)(ios_base&, T), T manarg)
      : __pf(pf)
      , __manarg(manarg)
    { ; }
      
    ios_base&           (*__pf)(ios_base&, T);
    T              __manarg;
  protected:

  private:
  };

  /*
   * class smanip_fill
   */

  template<class T, class traits>
  class smanip_fill {

  public:
    smanip_fill(basic_ios< T, traits >& (*pf)(basic_ios< T, traits >&, T), T manarg)
      : __pf(pf)
      , __manarg(manarg)
    { ; }

    basic_ios< T, traits >&   (*__pf)(basic_ios< T, traits >&, T);
    T              __manarg;
  protected:

  private:
  };
 
  /*
   * global manipulators
   */

  inline ios_base& rsios(ios_base& str, ios_base::fmtflags mask)
  {
    str.setf((ios_base::fmtflags)0, mask);
    return str;
  }

  inline ios_base& sios(ios_base& str, ios_base::fmtflags mask)
  {
    str.setf(mask);
    return str;
  }

  inline ios_base& sbase(ios_base& str, int base)
  {
    str.setf(base == 8 ? ios_base::oct :
             base == 10 ? ios_base::dec :
             base == 16 ? ios_base::hex :
             ios_base::fmtflags(0), ios_base::basefield);

    return str;
  }

  template < class charT, class traits >
  inline basic_ios< charT, traits >& sfill( basic_ios< charT, traits >& str, charT c)
  {
    str.fill(c);
    return str;
  }

  inline ios_base& sprec(ios_base& str, int n)
  {
    str.precision(n);
    return str;
  }

  inline ios_base& swidth(ios_base& str, int n)
  {
    str.width(n);
    return str;
  }
 
  inline smanip<ios_base::fmtflags> resetiosflags(ios_base::fmtflags mask )
  { return smanip<ios_base::fmtflags>(rsios, mask); }
 
  inline smanip<ios_base::fmtflags> setiosflags(ios_base::fmtflags mask )
  { return smanip<ios_base::fmtflags>(sios, mask); }

  inline smanip<int> setbase(int base)
  { return smanip<int>(sbase, base); }

  template < class charT >
  inline smanip_fill<charT, char_traits<charT> > setfill( charT c)
  { return smanip_fill<charT, char_traits<charT> >((basic_ios< charT, char_traits<charT> >& (*)(basic_ios< charT, char_traits<charT> >&, charT))sfill, c); 
  }

  inline smanip<int> setprecision(int n)
  { return smanip<int>(sprec, n); }

  inline smanip<int> setw(int n)
  { return smanip<int>(swidth, n); }

  template<class charT, class traits, class T>
  inline basic_istream<charT, traits>& operator>>(basic_istream<charT, traits>& is, const smanip<T>& a)
  {
#ifndef _RWSTD_NO_EXCEPTIONS
    try {
      (*a.__pf)(is, a.__manarg);
    }
    catch(...) {
      is.setstate(ios_base::failbit);
    }
#else
    (*a.__pf)(is, a.__manarg);
#endif // _RWSTD_NO_EXCEPTIONS
  
    return is;
  }

  template<class charT, class traits, class T>
  inline basic_ostream<charT, traits>& operator<<(basic_ostream<charT, traits>& os, const smanip<T>& a)
  {
#ifndef _RWSTD_NO_EXCEPTIONS
    try {
      (*a.__pf)(os, a.__manarg);
    }
    catch(...) {
      os.setstate(ios_base::failbit);
    }
#else
    (*a.__pf)(os, a.__manarg);
#endif // _RWSTD_NO_EXCEPTIONS
  
    return os;
  }

  template<class T, class traits>
  inline basic_istream<T, traits>& operator>>(basic_istream<T, traits>& is, const smanip_fill<T, traits>& a)
  {
#ifndef _RWSTD_NO_EXCEPTIONS
    try {
      (*a.__pf)(is, a.__manarg);
    }
    catch(...) {
      is.setstate(ios_base::failbit);
    }
#else
    (*a.__pf)(is, a.__manarg);
#endif // _RWSTD_NO_EXCEPTIONS
  
    return is;
  }

  template<class T, class traits>
  inline basic_ostream<T, traits>& operator<<(basic_ostream<T, traits>& os, const smanip_fill<T, traits>& a)
  {
#ifndef _RWSTD_NO_EXCEPTIONS
    try {
      (*a.__pf)(os, a.__manarg);
    }
    catch(...) {
      os.setstate(ios_base ::failbit);
    }
#else
    (*a.__pf)(os, a.__manarg);
#endif // _RWSTD_NO_EXCEPTIONS
  
    return os;
  }
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif // __STD__IOMANIP__ 
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __IOMANIP_H */
