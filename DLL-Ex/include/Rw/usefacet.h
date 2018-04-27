#ifndef __USEFACET_H
#define __USEFACET_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * usefacet - Declarations for the Standard Library facet access functions
 *            and for the convenience functions (isalpha etc.)
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

#ifndef __STD_USEFACET__
#define __STD_USEFACET__

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

// Template use_facet<Facet>(loc) returns a reference to a facet.  Its result
// is guaranteed by locale's value semantics to last at least as long as the
// locale or any copy of the locale it came from.

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
#define _RWSTD_SELECT_FACET
#else
#define _RWSTD_SELECT_FACET ,Facet*
#endif

template <class Facet>
_RWSTD_TRICKY_INLINE
const Facet &use_facet (const locale &loc _RWSTD_SELECT_FACET)
{
  // Ensure that Facet has a static member named id, and (via cast) that it is
  // of type locale::id, and obtain from it (via size_t conversion operator)
  // the private numeric index associated with type Facet for this run.
  size_t i=(const locale::id&) Facet::id;

  // Get pointer to facet from locale.
  const __RWSTD::facet_imp *f=loc.get_facet(i);

  // If facet is not explicitly present in locale yet, use private function
  // locale::__make_explicit to construct it or retrieve it from a cache, and
  // install it in the locale.  This function can throw bad_cast or other
  // exceptions.
  if (!f)
    f=loc.__make_explicit(Facet::id,Facet::__ok_implicit,Facet::__facet_cat,
        __RWSTD::facet_maker<Facet>::maker_func);

  return (const Facet&)*f;
}

// Function has_facet<Facet>(loc) simply reports whether a locale implements a
// particular facet.  If has_facet<facet>(loc) is false, use_facet<facet>(loc)
// would throw an exception.

template <class Facet>
inline bool has_facet (const locale &loc _RWSTD_SELECT_FACET)
    _RWSTD_THROW_SPEC_NULL
{
  size_t ix = (const locale::id&) Facet::id;  // verify is a locale::id.
  return loc.__imp->get_facet(ix) != NULL || Facet::__ok_implicit;
}

// convenience interfaces: is*(char)

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE

template <class charT> inline bool isspace(charT c, const locale& loc)
  { typedef ctype<charT> idiot; return use_facet<idiot>(loc).is(ctype_base::space, c); }
template <class charT> inline bool isprint(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::print, c); }
template <class charT> inline bool iscntrl(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::cntrl, c); }
template <class charT> inline bool isupper(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::upper, c); }
template <class charT> inline bool islower(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::lower, c); }
template <class charT> inline bool isalpha(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::alpha, c); }
template <class charT> inline bool isdigit(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::digit, c); }
template <class charT> inline bool ispunct(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::punct, c); }
template <class charT> inline bool isxdigit(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::xdigit, c); }
template <class charT> inline bool isalnum(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::alnum, c); }
template <class charT> inline bool isgraph(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).is(ctype_base::graph, c); }

template <class charT> inline charT toupper(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).toupper(c); }
template <class charT> inline charT tolower(charT c, const locale& loc)
  { return use_facet<ctype<charT> >(loc).tolower(c); }

#else

template <class charT> inline bool isspace(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::space, c); }
template <class charT> inline bool isprint(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::print, c); }
template <class charT> inline bool iscntrl(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::cntrl, c); }
template <class charT> inline bool isupper(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::upper, c); }
template <class charT> inline bool islower(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::lower, c); }
template <class charT> inline bool isalpha(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::alpha, c); }
template <class charT> inline bool isdigit(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::digit, c); }
template <class charT> inline bool ispunct(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::punct, c); }
template <class charT> inline bool isxdigit(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::xdigit, c); }
template <class charT> inline bool isalnum(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::alnum, c); }
template <class charT> inline bool isgraph(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).is(ctype_base::graph, c); }

template <class charT> inline charT toupper(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).toupper(c); }
template <class charT> inline charT tolower(charT c, const locale& loc)
  { return use_facet(loc,(ctype<charT>*)0).tolower(c); }

#endif

#ifndef _RWSTD_NO_NAMESPACE
} // namespace std
#endif

#endif //  __STD_USEFACET__
#pragma option pop
#endif /* __USEFACET_H */
