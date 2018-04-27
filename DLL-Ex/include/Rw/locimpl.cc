#ifndef __LOCIMPL_CC
#define __LOCIMPL_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * rw/locimpl.cc - Template definitions for the Standard Library locale
 *                 private implementation classes.
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
namespace __rwstd {
#endif

// -------------------------------------------
// Template digit_map<charT> member templates.
// -------------------------------------------

template <class charT>
void 
digit_map<charT>::init (const _RW_STD::ctype<charT> &ct)
{
  ct.widen(punct_chars,punct_chars+sizeof punct_chars,punct_array);
  ct.widen(digit_chars,digit_chars+sizeof digit_chars,digit_array);

#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE)
  std::memcpy(value_array,char_values,sizeof value_array);
#else
  memcpy(value_array,char_values,sizeof value_array);
#endif
  inited=true;
}

template <class charT>
int digit_map<charT>::eval (charT c) const {
  const charT *end=digit_array+sizeof value_array;
  for (const charT *p=digit_array; p<end; p++)
    if (*p==c)
      return value_array[p-digit_array];
  return -1;
}
#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#pragma option pop
#endif /* __LOCIMPL_CC */
