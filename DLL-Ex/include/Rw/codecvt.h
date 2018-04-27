#ifndef __CODECVT_H
#define __CODECVT_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * codecvt - Declarations for the Standard Library code conversion facet
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

#ifndef __STD_CODECVT__
#define __STD_CODECVT__

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale> 
#endif

#ifndef __STD_LIMITS
#include <limits>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

class _RWSTDExport codecvt_base {
 public:
  enum result { ok, partial, error, noconv };
};

// ------------------------------------------------------
// Codeset conversion facet -- codecvt<fromT,toT,stateT>.
// ------------------------------------------------------

_RWSTD_TEMPLATE
class _RWSTDExport codecvt<char,char,mbstate_t>:
    public locale::facet, public codecvt_base
{
 public:
  typedef char      extern_type;   
  typedef char      intern_type;
  typedef mbstate_t state_type;

  _EXPLICIT codecvt (size_t refs=0):
      locale::facet(refs,locale::__rw_ctype_category) { }

  result out (mbstate_t& state,
      const char* from, const char* from_end, const char*& from_next,
      char* to, char* to_limit, char*& to_next) const
    { return do_out(state,from,from_end,from_next,to,to_limit,to_next); }

  result unshift (mbstate_t& state,
      char* to, char* to_limit, char*& to_next) const
    { return do_unshift(state,to,to_limit,to_next); }

  result in(mbstate_t& state,
      const char* from, const char* from_end, const char*& from_next,
      char* to, char* to_limit, char*& to_next) const
    { return do_in(state,from,from_end,from_next,to,to_limit,to_next); }

  int encoding() const _RWSTD_THROW_SPEC_NULL
    { return do_encoding(); }

  bool always_noconv() const _RWSTD_THROW_SPEC_NULL
    { return do_always_noconv(); }

  int length (const mbstate_t& state, const char* from, const char* end,
      size_t max) const { return do_length(state,from,end,max); }

  int max_length() const _RWSTD_THROW_SPEC_NULL
    { return do_max_length(); }

#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static locale::id _RWSTDExport id;
#else
  static locale::id id;
#endif

  // Rogue Wave extension:
  typedef string internal_string_type;
  typedef string external_string_type;
  internal_string_type in (const external_string_type &s) const { return s; }
  external_string_type out (const internal_string_type &s) const { return s; }

  // Implementation:
  enum { __facet_cat = locale::__rw_ctype_category, __ok_implicit = 1 };

 protected:
  virtual ~codecvt();

  virtual result do_out(mbstate_t& state,
    const char* from, const char* from_end, const char*& from_next,
          char* to, char* to_limit, char*& to_next) const;

  virtual result do_in(mbstate_t& state,
    const char* from, const char* from_end, const char*& from_next,
          char* to, char* to_limit, char*& to_next) const;

  virtual result do_unshift(mbstate_t& state,
          char* to, char* to_limit, char*& to_next) const;

  virtual int do_encoding() const _RWSTD_THROW_SPEC_NULL;

  virtual bool do_always_noconv() const _RWSTD_THROW_SPEC_NULL;

  virtual int do_length (const mbstate_t&, const char* from, const char* end,
      size_t max) const;

  virtual int do_max_length() const _RWSTD_THROW_SPEC_NULL;

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
class _RWSTDExport codecvt<wchar_t,char,mbstate_t>:
    public locale::facet, public codecvt_base
{
 public:
  typedef wchar_t intern_type;
  typedef char    extern_type;
  typedef mbstate_t state_type;

  _EXPLICIT codecvt (size_t refs=0):
      locale::facet(refs,locale::__rw_ctype_category) { }

  result out (mbstate_t& state,
      const wchar_t* from, const wchar_t* from_end, const wchar_t*& from_next,
      char* to, char* to_limit, char*& to_next) const
    { return do_out(state,from,from_end,from_next,to,to_limit,to_next); }

  result unshift (mbstate_t& state,
      char* to, char* to_limit, char*& to_next) const
    { return do_unshift(state,to,to_limit,to_next); }

  result in (mbstate_t& state,
      const char* from, const char* from_end, const char*& from_next,
      wchar_t* to, wchar_t* to_limit, wchar_t*& to_next) const
    { return do_in(state,from,from_end,from_next,to,to_limit,to_next); }

  int encoding() const _RWSTD_THROW_SPEC_NULL
    { return do_encoding(); }

  bool always_noconv() const _RWSTD_THROW_SPEC_NULL
    { return do_always_noconv(); }

  int length (const mbstate_t& state, const char* from, const char* end,
      size_t max) const
    { return do_length(state,from,end,max); }

  int max_length() const _RWSTD_THROW_SPEC_NULL
    { return do_max_length(); }

#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static locale::id _RWSTDExport id;
#else
  static locale::id id;
#endif

  // Rogue Wave extension:
  typedef string external_string_type;
  typedef wstring internal_string_type;
  internal_string_type in (const external_string_type &s) const;
  external_string_type out (const internal_string_type &s) const;

  // Implementation:
  enum { __facet_cat = locale::__rw_ctype_category, __ok_implicit = 1 };

 protected:
  virtual ~codecvt();

  virtual result do_out (mbstate_t& state,
    const wchar_t* from, const wchar_t* from_end, const wchar_t*& from_next,
          char* to, char* to_limit, char*& to_next) const;

  virtual result do_in (mbstate_t& state,
    const char* from, const char* from_end, const char*& from_next,
          wchar_t* to, wchar_t* to_limit, wchar_t*& to_next) const;

  virtual result do_unshift (mbstate_t& state,
          char* to, char* to_limit, char*& to_next) const;

  virtual bool do_always_noconv() const _RWSTD_THROW_SPEC_NULL;

  virtual int do_encoding() const _RWSTD_THROW_SPEC_NULL;

  virtual int do_length (const mbstate_t&, const char* from,
      const char* end, size_t max) const;

  virtual int do_max_length() const _RWSTD_THROW_SPEC_NULL;

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

#endif // _RWSTD_NO_WIDE_CHAR

template <class internT, class externT, class stateT>
class _RWSTDExportTemplate codecvt: public locale::facet, public codecvt_base {
 public:
  typedef internT intern_type;
  typedef externT extern_type;
  typedef stateT state_type;

  _EXPLICIT codecvt (size_t refs=0): locale::facet(refs) { }

  result out (stateT& state,
      const internT* from, const internT* from_end, const internT*& from_next,
      externT* to, externT* to_limit, externT*& to_next) const
    { return do_out(state,from,from_end,from_next,to,to_limit,to_next); }

  result unshift (stateT& state,
      externT* to, externT* to_limit, externT*& to_next) const
    { return do_unshift(state,to,to_limit,to_next); }

  result in (stateT& state,
      const externT* from, const externT* from_end, const externT*& from_next,
      internT* to, internT* to_limit, internT*& to_next) const
    { return do_in(state,from,from_end,from_next,to,to_limit,to_next); }

  bool always_noconv() const _RWSTD_THROW_SPEC_NULL
    { return do_always_noconv(); }

  int encoding() const _RWSTD_THROW_SPEC_NULL
    { return do_encoding(); }

  int length (const stateT& state, const externT* from, const externT* end,
      size_t max) const
    { return do_length(state,from,end,max); }

  int max_length() const _RWSTD_THROW_SPEC_NULL
    { return do_max_length(); }

  static locale::id id;

  // Rogue Wave extension:
  typedef basic_string<externT,char_traits<externT>,allocator<externT> >
      external_string_type;
  typedef basic_string<internT,char_traits<internT>,allocator<internT> >
      internal_string_type;
  internal_string_type in (const external_string_type &s) const;
  external_string_type out (const internal_string_type &s) const;

  // Implementation:
  enum { __facet_cat = locale::__rw_ctype_category, __ok_implicit = 1 };

 protected:
  virtual ~codecvt();

  virtual result do_out (stateT& state,
    const internT* from, const internT* from_end, const internT*& from_next,
          externT* to, externT* to_limit, externT*& to_next) const;

  virtual result do_in (stateT& state,
    const externT* from, const externT* from_end, const externT*& from_next,
          internT* to, internT* to_limit, internT*& to_next) const;

  virtual result do_unshift (stateT& state,
          externT* to, externT* to_limit, externT*& to_next) const;

  virtual int do_encoding() const _RWSTD_THROW_SPEC_NULL;

  virtual bool do_always_noconv() const _RWSTD_THROW_SPEC_NULL;

  virtual int do_length (const stateT&, const externT* from, const externT* end,
      size_t max) const;

  virtual int do_max_length() const _RWSTD_THROW_SPEC_NULL;

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

template <class internT, class externT, class stateT>
class codecvt_byname: public codecvt<internT,externT,stateT> {
 public:
  
  typedef internT intern_type;
  typedef externT extern_type;
  typedef stateT state_type; 

  _EXPLICIT codecvt_byname (const char*, size_t refs=0);

 protected:
  virtual ~codecvt_byname();

  virtual codecvt_base::result do_out (stateT&, 
          const internT*, const internT*, const internT*&,
          externT*, externT*, externT*&) const;

  virtual codecvt_base::result do_in (stateT&,
    const externT*, const externT*, const externT*&,
          internT*, internT*, internT*&) const;

  virtual codecvt_base::result do_unshift (stateT&,
          externT*, externT*, externT*&) const;

  virtual int do_encoding () const _RWSTD_THROW_SPEC_NULL;

  virtual bool do_always_noconv () const _RWSTD_THROW_SPEC_NULL;

// Virtual member functions inherited from codecvt<,,>:
// virtual int do_length (const stateT &state, const externT* from,
//     const externT* end, size_t max) const;
// virtual int do_max_length() const _RWSTD_THROW_SPEC_NULL;
};

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/codecvt.cc>
#endif

#endif // __STD_CODECVT__
#pragma option pop
#endif /* __CODECVT_H */
