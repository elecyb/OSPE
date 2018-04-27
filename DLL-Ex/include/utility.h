#ifndef __UTILITY_H
#define __UTILITY_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_UTILITY__
#define __STD_UTILITY__

/***************************************************************************
 *
 * utility - Declarations for the Standard Library utility classes
 *
 ***************************************************************************
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
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

#include <stdcomp.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _RWSTD_NO_NAMESPACE
  namespace rel_ops {
#endif

//
// Operators
//

    template <class T>
    inline bool operator!=(const T& x, const T& y)
    {
      return !(x == y);
    }

    template <class T>
    inline bool operator>(const T& x, const T& y)
    {
      return y < x;
    }

    template <class T>
    inline bool operator<=(const T& x, const T& y)
    {
      return !(y < x);
    }

    template <class T>
    inline bool operator>=(const T& x, const T& y)
    {
      return !(x < y);
    }

#ifndef _RWSTD_NO_NAMESPACE
  } /* End of namespace rel_ops */
#endif

//
// Pairs.
//

  template <class T1, class T2>
  struct pair
  {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;
    pair (const T1& a, const T2& b) : first(a), second(b) {}
    pair () 
#ifndef _RWSTD_NO_BUILT_IN_CTOR
      : first(T1()), second(T2()) 
#endif
    { ; }

    pair(const pair& p) 
      : first(p.first), second(p.second)
    { ; }
#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template <class U, class V> pair(const pair<U,V>& p) 
      : first(p.first), second(p.second)
    { ; }
#endif

  };

  template <class T1, class T2>
  inline bool operator==(const pair<T1, T2>& x, const pair<T1, T2>& y)
  { 
    return x.first == y.first && x.second == y.second; 
  }

  template <class T1, class T2>
  inline bool operator<(const pair<T1, T2>& x, const pair<T1, T2>& y)
  { 
    return x.first < y.first || (!(y.first < x.first) && x.second < y.second); 
  }

#ifndef _RWSTD_NO_NAMESPACE
  template <class T1, class T2>
  inline bool operator!=(const pair<T1, T2>& x, const pair<T1, T2>& y)
  { 
    return !(x == y);
  }

  template <class T1, class T2>
  inline bool operator>(const pair<T1, T2>& x, const pair<T1, T2>& y)
  { 
    return y < x;
  }

  template <class T1, class T2>
  inline bool operator>=(const pair<T1, T2>& x, const pair<T1, T2>& y)
  { 
    return !(x < y);
  }

  template <class T1, class T2>
  inline bool operator<=(const pair<T1, T2>& x, const pair<T1, T2>& y)
  { 
    return !(y < x);
  }
#endif

  template <class T1, class T2>
  inline pair<T1, T2> make_pair(const T1& x, const T2& y)
  {
    return pair<T1, T2>(x, y);
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif /*__STD_UTILITY__*/

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __UTILITY_H */
