#ifndef __RWLOCALE_CC
#define __RWLOCALE_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/****************************************************************************
 *
 * locale.cc - Definitions of the Standard Library locale classes
 *
 * $Id: locale.cc,v 1.67 1996/10/22 05:11:35 delaney Exp $
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
 ***************************************************************************/

#ifndef __STD_RWLOCALE_IMPL__
#define __STD_RWLOCALE_IMPL__

#ifndef __STD_RW_LOCNUMRW__
#include <rw/numbrw>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

// ------------------------------
// Class locale member templates.
// ------------------------------

// Operator () compares two strings according to the collate<charT> facet of
// the locale.  It lets you use a locale object directly as a comparator
// predicate for strings in various algorithms.  For instance, you can sort
// a vector<string> according to the collating sequence of a locale with an
// expression like: sort(v.begin(),v.end(),mylocale).

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
template <class charT, class Traits, class Allocator>
bool locale::operator() (
    const basic_string<charT,Traits,Allocator>& s1,
    const basic_string<charT,Traits,Allocator>& s2) const
{
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
  return use_facet<_RW_STD::collate<charT> >(*this).compare
      (s1.data(),s1.data()+s1.length(),s2.data(),s2.data()+s2.length()) < 0;
#else
  return use_facet(*this,(_RW_STD::collate<charT>*)0).compare
      (s1.data(),s1.data()+s1.length(),s2.data(),s2.data()+s2.length()) < 0;
#endif
}
#endif // _RWSTD_NO_MEMBER_TEMPLATES
#ifndef _RWSTD_NO_NAMESPACE
} // namespace std
#endif

#endif // __STD_RWLOCALE_IMPL__
#pragma option pop
#endif /* __RWLOCALE_CC */
