#ifndef __COLLATE_CC
#define __COLLATE_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * collate.cc - Definitions for the Standard Library character collation facet
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

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

// --------------------------------------
// Facet collate<charT> member templates.
// --------------------------------------

template <class charT>
locale::id collate<charT>::id;

template <class charT>
collate<charT>::~collate() { }

template <class charT>
int collate<charT>::do_compare
    (const charT* low1, const charT* high1,
     const charT* low2, const charT* high2) const
{
  size_t len1=high1-low1;
  size_t len2=high2-low2;
  size_t len = len1 < len2 ? len1 : len2;
  int comp;

  for (const charT *p=low1,*q=low2; len--; p++,q++)
    if ((comp=__coll_order(*p)-__coll_order(*q))!=0)
      return comp<0? -1 : 1;

  if (len1<len2)
    return -1;
  if (len2<len1)
    return 1;
  return 0;
}

template <class charT>
_TYPENAME collate<charT>::string_type
collate<charT>::do_transform
    (const charT* low, const charT* high) const
{
  string_type result(high-low,'\0');
  _TYPENAME string_type::iterator out=result.begin();
  for (const charT *p=low; p!=high; p++)
    *out++=__coll_order(*p);
  return result;
}

template <class charT>
long collate<charT>::do_hash (const charT *start, const charT *end) const
{
  // We hash the result of do_transform, so that keys that transform equally
  // will hash equally, per the draft.

  string_type s=do_transform(start,end);
  start=s.begin();
  end=s.end();

  // Peter Weinberger's generic hashing algorithm, adapted by Andrew Binstock
  // from a version by Allen Holub (see Andrew Binstock, "Hashing Revisited",
  // Dr. Dobb's Journal, April 1996) and templatized by Rogue Wave.

  const int long_bits=CHAR_BIT*sizeof(long);
  const int one_eighth=long_bits/8;
  const int three_fourths=long_bits*3/4;
  const int high_bits=(int)((~0L) << (long_bits-one_eighth));

  long result=0;
  for (const charT *p=start; start<end; start++) {
    result=(result << one_eighth) + *p;
    long temp=result & high_bits;
    if (temp)
      result=(result^(temp>>three_fourths)) &~ high_bits;
  }

  return result;
}

// --------------------------------------------------------------------
// Character collation by-name member templates: collate_byname<charT>
// --------------------------------------------------------------------

template <class charT>
collate_byname<charT>::collate_byname (const char* /*name*/, size_t refs):
    collate<charT>(refs)
{ }

template <class charT>
collate_byname<charT>::~collate_byname()
{ }

template <class charT>
int collate_byname<charT>::do_compare
    (const charT* /*low1*/, const charT* /*high1*/,
     const charT* /*low2*/, const charT* /*high2*/) const
{
  return 0;
}

template <class charT>
_TYPENAME collate_byname<charT>::string_type
collate_byname<charT>::do_transform
    (const charT* /*low*/, const charT* /*high*/) const
{
  return string_type();
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace std
#endif
#pragma option pop
#endif /* __COLLATE_CC */
