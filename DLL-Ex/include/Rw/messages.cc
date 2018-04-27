#ifndef __MESSAGES_CC
#define __MESSAGES_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * messages.cc - Definitions for the Standard Library messaging facet
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

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

// ---------------------------------------
// Facet messages<charT> member templates.
// ---------------------------------------

template <class charT>
locale::id messages<charT>::id;

template <class charT>
messages<charT>::messages (size_t refs):
    locale::facet(refs,locale::messages), __RWSTD::messages_impl("C")
{ }

template <class charT>
messages<charT>::messages (size_t refs,string name):
    locale::facet(refs,locale::messages), __RWSTD::messages_impl(name)
{ }

template <class charT>
messages<charT>::~messages() { }

template <class charT>
messages_base::catalog
messages<charT>::do_open (const string &cat_name,const locale &loc) const
{
  return open_cat_(cat_name,loc);
}

template <class charT>
_TYPENAME messages<charT>::string_type
messages<charT>::do_get (messages_base::catalog cat,
    int set,int msgid,const string_type &dflt) const
{
  char *text=get_mess_(cat,set,msgid);

  // The following is wrong -- it should be using codecvt instead of
  // ctype.widen, but this requires an effective codecvt implementation ...

  if (text) {
  const _RW_STD::ctype<charT>& ct =
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    _RW_STD::use_facet<_RW_STD::ctype<charT> >(get_loc_(cat));
#else
    _RW_STD::use_facet(get_loc_(cat), (_RW_STD::ctype<charT>*)0);
#endif

#ifndef _RWSTD_STRICT_ANSI
    return ct.widen(string(text));
#else
    charT* __theText = new charT[strlen(text)];
    ct.widen(text, text+strlen(text), __theText);
    return string_type(__theText);
#endif

  }
  return dflt;
}

template <class charT>
void messages<charT>::do_close (messages_base::catalog cat) const
{
  close_cat_(cat);
}
// ----------------------------------------------------------
// Messages by-name member templates: messages_byname<charT>.
// ----------------------------------------------------------

template <class charT>
messages_byname<charT>::messages_byname (const char *name, size_t refs):
    messages<charT>(refs,__RWSTD::messages_impl::get_loc_name_(name))
{ }

#ifndef _RWSTD_NO_NAMESPACE
} // namespace std
#endif

#pragma option pop
#endif /* __MESSAGES_CC */
