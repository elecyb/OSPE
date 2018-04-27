#ifndef __MESSAGES_H
#define __MESSAGES_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * messages - Declarations for the Standard Library messaging facet
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

#ifndef __STD_MESSAGE__
#define __STD_MESSAGE__

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale> 
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

struct _RWSTDExport messages_base {
  typedef size_t catalog;
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

// --------------------------------------
// Implementation class -- messages_impl.
// --------------------------------------

class _RWSTDExport messages_impl {
  _RW_STD::string loc_name_;                          \
 protected:
  messages_impl (_RW_STD::string name);

  _RW_STD::messages_base::catalog open_cat_ (const _RW_STD::string &,const _RW_STD::locale &) const;
  char *get_mess_ (_RW_STD::messages_base::catalog,int,int) const;
  const _RW_STD::locale &get_loc_ (_RW_STD::messages_base::catalog) const;
  void close_cat_ (_RW_STD::messages_base::catalog) const;
  static _RW_STD::string get_loc_name_ (const char*);
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// ----------------------------------------------------
// Standard message retrieval facet -- messages<charT>.
// ----------------------------------------------------

template <class charT>
class _RWSTDExportTemplate  messages: public locale::facet, public messages_base,
    public __RWSTD::messages_impl
{
 public:
  typedef charT char_type;
  typedef basic_string<charT,char_traits<charT>,allocator<charT> > string_type;

  _EXPLICIT messages (size_t refs=0);

  catalog open (const string& fn, const locale& loc) const
    { return do_open(fn,loc); }
  string_type get (catalog c, int set, int msgid, const string_type& df) const
    { return do_get(c,set,msgid,df); }
  void close (catalog c) const { do_close(c); }

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::__rw_messages_category, __ok_implicit = 1 };

 protected:
  virtual ~messages();

  virtual catalog do_open (const string&, const locale&) const;
  virtual string_type do_get (catalog, int, int, const string_type&) const;
  virtual void do_close (catalog) const;

  // Implementation:
  messages (size_t refs,string);

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// -------------------------------------------------
// Standard derived facet -- messages_byname<charT>.
// -------------------------------------------------

template <class charT>
class  messages_byname: public messages<charT> {
 public:
  _EXPLICIT messages_byname (const char*, size_t refs=0);

 protected:

  // Virtual members inherited from messages<charT>:
  // ~messages_byname();
  // catalog do_open (const string&, const locale&) const;
  // string_type do_get (catalog, int, int, const string_type&) const;
  // void do_close (catalog) const;
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

#ifndef _RWSTD_NO_FUNC_PARTIAL_SPEC

template <class charT>
inline _RW_STD::messages<charT>* create_named_facet
    (_RW_STD::messages<charT>*,const char *name,size_t refs)
{ return new _RW_STD::messages_byname<charT>(name,refs); }

#else
_RWSTD_TEMPLATE
inline _RW_STD::messages<char>* create_named_facet
    (_RW_STD::messages<char>*,const char *name,size_t refs)
{ return new _RW_STD::messages_byname<char>(name,refs); }

#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
inline _RW_STD::messages<wchar_t>* create_named_facet
    (_RW_STD::messages<wchar_t>*,const char *name,size_t refs)
{ return new _RW_STD::messages_byname<wchar_t>(name,refs); }

#endif // _RWSTD_NO_WIDE_CHAR
#endif // _RWSTD_NO_FUNC_PARTIAL_SPEC
#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/messages.cc>
#endif
#endif /* __STD_MESSAGE__ */

#pragma option pop
#endif /* __MESSAGES_H */
