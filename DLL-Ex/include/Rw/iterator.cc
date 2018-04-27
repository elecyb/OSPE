#ifndef __RW_ITERATOR_CC
#define __RW_ITERATOR_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * iterator.cc - Non-inline definitions for the Standard Library iterators
 *
 * $Id:
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

  template <class InputIterator, class Distance>
  void __distance (InputIterator first, InputIterator last, Distance& n, 
                   input_iterator_tag)
  {
    while (first != last) { ++first; ++n; }
  }

  template <class ForwardIterator, class Distance>
  void __distance (ForwardIterator first, ForwardIterator last, Distance& n, 
                   forward_iterator_tag)
  {
    while (first != last) { ++first; ++n; }
  }

  template <class BidirectionalIterator, class Distance>
  void __distance (BidirectionalIterator first, BidirectionalIterator last, 
                   Distance& n, bidirectional_iterator_tag)
  {
    while (first != last) { ++first; ++n; }
  }
#ifdef _RWSTD_NO_BASE_CLASS_MATCH
//
// We include assert() to test for possible problem in advance().
// Furthermore, we FORCE assert() to always expand.
//
#ifdef  NDEBUG
#define __RW_NDEBUG
#undef  NDEBUG
#endif
#ifndef _RWSTD_NO_NEW_HEADER
#include <cassert>
#else
#include <assert.h>
#endif

#endif /*_RWSTD_NO_BASE_CLASS_MATCH*/
  template <class InputIterator, class Distance>
  void __advance (InputIterator& i, Distance n, input_iterator_tag)
  {
#ifdef _RWSTD_NO_BASE_CLASS_MATCH
    //
    // All uses of advance() end up calling this template, even
    // when advance() is being invoked on a bidirectional or random
    // iterator.  We need to check that n is non-negative, or else
    // this algorithm will fail horribly.  We MUST document the
    // restriction that advance() only be called with non-negative
    // Distance.  There don't appear to be any _EXPLICIT uses of advance()
    // with a negative Distance argument in the STL library itself.
    //
    // This assert() is ALWAYS on -- see how it's included'd above.
    //
    assert(n >= 0);
#endif /*_RWSTD_NO_BASE_CLASS_MATCH*/
    while (n--) ++i;
  }

//
// Don't forget to turn off expansion of assert() if that's what the
// user expects.
//
#ifdef  __RW_NDEBUG
#define NDEBUG
#undef  __RW_NDEBUG
#endif

  template <class ForwardIterator, class Distance>
  void __advance (ForwardIterator& i, Distance n, forward_iterator_tag)
  {
    while (n--) ++i;
  }

  template <class BidirectionalIterator, class Distance>
  void __advance (BidirectionalIterator& i, Distance n, 
                  bidirectional_iterator_tag)
  {
    if (n >= 1)
      while (n--) ++i;
    else
      while (n++) --i;
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __RW_ITERATOR_CC */
