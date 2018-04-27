#ifndef __BOR_RW__CTYPE_H
#define __BOR_RW__CTYPE_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * ctype - Declarations for the Standard Library character
 * classification facet
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

#ifndef __STD_CTYPE__
#define __STD_CTYPE__

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale> 
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

class _RWSTDExport ctype_base {
 public:
  enum mask {
    space=1<<0, print=1<<1, cntrl=1<<2, upper=1<<3, lower=1<<4,
    alpha=1<<5, digit=1<<6, punct=1<<7, xdigit=1<<8,
    alnum=(1<<5)|(1<<6), graph=1<<9
  };
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

// -----------------------------------------------------
// Implementation class template -- ctype_helper<charT>.
// -----------------------------------------------------

// Character classification facet ctype<charT> derives from this to obtain
// its private __digit_map member.

template <class charT>
class _RWSTDExportTemplate ctype_helper {
#if !defined(_MSC_VER) || defined(__BORLANDC__)
  friend class digit_map<charT>;
#else
public:
#endif
  digit_map<charT> __digit_map;
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// --------------------------------------------------------
// Standard character classification facet -- ctype<charT>.
// --------------------------------------------------------

_RWSTD_TEMPLATE
class _RWSTDExport ctype_byname<char>;

// First, a specialization on char, so that char operations may be inline.
// This specialization is defined in the standard because it affects the
// derivation interface (in particular because its constructor's signature
// differs from the constructors for ctype<charT> for other charT's).

_RWSTD_TEMPLATE
class _RWSTDExport ctype<char>: public locale::facet, public ctype_base,
    public __RWSTD::ctype_helper<char>
{
  friend class _RWSTDExport locale;
  friend class _RWSTDExport ctype_byname<char>;

  #ifndef _RWSTD_NO_WIDE_CHAR
  friend class _RWSTDExport ctype<wchar_t>;
  #endif

 public:
  typedef char char_type;

  #ifndef _RWSTD_NO_STI_SIMPLE
  static const size_t table_size = 256;
  #else
  enum { table_size = 256 };
  #endif

  _EXPLICIT ctype (const mask* tab=0,bool del=false,size_t refs=0);

  #if UCHAR_MAX <= 255
  bool is (mask m,char c) const
    { return (__table[(unsigned char)c] & m) != 0; }
  #else
  bool is (mask m,char c) const
    { return c<table_size && (__table[(unsigned char)c] & m) != 0; }
  #endif

  const char* is (const char* lo,const char* hi,mask* vec) const;
  const char* scan_is (mask m,const char* low,const char* high) const;
  const char* scan_not (mask m,const char* low,const char* high) const;

  char toupper (char c) const { return do_toupper(c); }
  char tolower (char c) const { return do_tolower(c); }
  char widen (char c) const { return do_widen(c); }
  char narrow (char c, char dfault) const { return do_narrow(c,dfault); }

  const char* toupper (char* low,const char* high) const
    { return do_toupper(low,high); }
  const char* tolower (char* low,const char* high) const
    { return do_tolower(low,high); }
  const char* widen (const char* lo, const char* hi, char* to) const
      { return do_widen(lo,hi,to); }
  const char* narrow (const char* lo, const char* hi, char dfault,
                         char* to) const
      { return do_narrow(lo,hi,dfault,to); }

#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static locale::id _RWSTDExport id;
#else
  static locale::id id;
#endif

#ifndef _RWSTD_STRICT_ANSI
  // Rogue Wave extensions:
  typedef string string_type;
  string_type widen (const string &s) const { return s; }
  string narrow (const string_type &s, char) const { return s; };
#endif

  // Implementation.
  enum { __facet_cat = locale::__rw_ctype_category, __ok_implicit = 1 };

 protected:
  const mask* table() const _RWSTD_THROW_SPEC_NULL
    { return __table; }
  static const mask* classic_table() _RWSTD_THROW_SPEC_NULL
    { return __classic_table; }

//  virtual 
  virtual ~ctype ();

  virtual char do_toupper (char) const;
  virtual const char* do_toupper (char* low, const char* high) const;
  virtual char do_tolower (char) const;
  virtual const char* do_tolower (char* low, const char* high) const;
  virtual char        do_widen (char c) const { return c; }
  virtual const char*    do_widen (const char* low, const char* high, char* to) const
    { memcpy(to,low,high-low); return high; }
  virtual char           do_narrow (char c, char /*dfault*/) const { return c; }
  virtual const char* do_narrow (const char* low, const char* high,
                                    char /*dfault*/, char* to) const
    { memcpy(to,low,high-low); return high; }

  void __initfacet (const locale*);
 private:
  static const mask __classic_table[table_size];
  const mask* __table;
  bool __delete_it;
  int __lower_min, __lower_max;
  int __upper_min, __upper_max;
  char *__to_upper_tab;
  char *__to_lower_tab;

  #if defined(__TURBOC__) && __TURBOC__ >= 0x0469
  // Without this, compiler complains that ctype(size_t) is not a member of
  // ctype<char> when it hits the constructor template for ctype<charT> in
  // locale.cc ... needs a proper config test.
  _EXPLICIT ctype (size_t);
  #endif

  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

#ifndef _RWSTD_NO_WIDE_CHAR

// Specialization for wchar_t.

_RWSTD_TEMPLATE
class _RWSTDExport ctype<wchar_t>: public locale::facet, public ctype_base,
    public __RWSTD::ctype_helper<wchar_t>
{
 public:
  typedef wchar_t char_type;

  _EXPLICIT ctype (size_t refs=0);

  bool is (mask m, wchar_t c) const
      { return do_is( m, c); }

  const wchar_t* is (const wchar_t* lo, const wchar_t* hi, mask* vec) const
      { return do_is(lo,hi,vec); }

  const wchar_t* scan_is (mask m, const wchar_t* lo, const wchar_t* hi) const
      { return do_scan_is(m,lo,hi); }

  const wchar_t* scan_not (mask m, const wchar_t* lo, const wchar_t* hi) const
      { return do_scan_not(m,lo,hi); }

  wchar_t toupper(wchar_t c) const
      { return do_toupper(c); }

  const wchar_t* toupper (wchar_t* lo, const wchar_t* hi) const
      { return do_toupper(lo,hi); }

  wchar_t tolower (wchar_t c) const
      { return do_tolower(c); }

  const wchar_t* tolower (wchar_t* lo, const wchar_t* hi) const
      { return do_tolower(lo,hi); }

  wchar_t widen (char c) const
      { return do_widen(c); }

  const char* widen (const char* lo, const char* hi, wchar_t* to) const
      { return do_widen(lo,hi,to); }

  char narrow (wchar_t c, char dfault) const
      { return do_narrow(c,dfault); }

  const wchar_t* narrow (const wchar_t* lo, const wchar_t* hi, char dfault,
                         char* to) const
      { return do_narrow(lo,hi,dfault,to); }

#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static locale::id _RWSTDExport id;
#else
  static locale::id id;
#endif

#ifndef _RWSTD_STRICT_ANSI
  // Rogue Wave extensions:
  typedef wstring string_type;
  string_type widen (const string&) const;
  string narrow (const string_type&, char) const;
#endif

  // Implementation:
  enum { __facet_cat = locale::__rw_ctype_category, __ok_implicit = 1 };

 protected:
  virtual ~ctype () { }

  virtual bool do_is (mask, wchar_t) const;
  virtual const wchar_t* do_is (const wchar_t*, const wchar_t*, mask*) const;
  virtual const wchar_t* do_scan_is (mask,const wchar_t*,const wchar_t*) const;
  virtual const wchar_t* do_scan_not (mask,const wchar_t*,const wchar_t*) const;
  virtual wchar_t        do_toupper (wchar_t) const;
  virtual const wchar_t* do_toupper (wchar_t*, const wchar_t*) const;
  virtual wchar_t        do_tolower (wchar_t) const;
  virtual const wchar_t* do_tolower (wchar_t*, const wchar_t*) const;
  virtual wchar_t        do_widen (char) const ;
  virtual const char*    do_widen (const char*, const char*, wchar_t*) const;
  virtual char           do_narrow (wchar_t, char dfault) const;
  virtual const wchar_t* do_narrow (const wchar_t*, const wchar_t*,
                                    char dfault, char* dest) const;
 private:
  static mask mask_of (wchar_t);

  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

#endif // _RWSTD_NO_WIDE_CHAR

template <class charT>
class _RWSTDExportTemplate ctype : public locale::facet, public ctype_base,
    public __RWSTD::ctype_helper<charT>
{
 public:
  typedef charT char_type;

  _EXPLICIT ctype (size_t refs = 0);

  bool         is(mask m, charT c) const
                 { return do_is( m, c); }
  const charT* is(const charT* low, const charT* high, mask* vec) const
                 { return do_is(low, high, vec); }
  const charT* scan_is(mask m, const charT* low, const charT* high) const
                 { return do_scan_is( m, low, high); }
  const charT* scan_not(mask m, const charT* low, const charT* high) const
                 { return do_scan_not( m, low, high); }

  charT        toupper(charT c)               const
                 { return do_toupper(c); }
  const charT* toupper(charT* low, const charT* high) const
                 { return do_toupper(low, high); }
  charT        tolower(charT c)               const
                 { return do_tolower(c); }
  const charT* tolower(charT* low, const charT* high) const
                 { return do_tolower(low, high); }

  charT  widen(char c) const { return do_widen(c); }
  const char* widen(const char* lo, const char* hi, charT* to) const
           { return do_widen(lo, hi, to); }
  char   narrow(charT c, char dfault) const { return do_narrow(c, dfault); }
  const charT* narrow(const charT* lo, const charT* hi,
                      char dfault, char* to) const
           { return do_narrow(lo, hi, dfault, to); }

  static locale::id id;

#ifndef _RWSTD_STRICT_ANSI
  // Rogue Wave extensions:
  typedef basic_string<charT,char_traits<charT>,allocator<charT> > string_type;
  string_type widen (const string&) const;
  string narrow (const string_type&, char) const;
#endif

  // Implementation:
  enum { __facet_cat = locale::__rw_ctype_category, __ok_implicit = 1 };

 protected:
  inline virtual ~ctype () { }

  virtual bool do_is(mask m, charT c) const
  { return false; }
  virtual const charT* do_is(
            const charT* low, const charT* high, mask* vec) const
  { return high; }
  virtual const charT* do_scan_is(
            mask m, const charT* low, const charT* high) const
  { return high; }
  virtual const charT* do_scan_not(
            mask m, const charT* low, const charT* high) const
  { return high; }
  virtual charT        do_toupper(charT c)                         const
  { return c; }
  virtual const charT* do_toupper(charT* low, const charT* high) const
  { return high; }
  virtual charT        do_tolower(charT c)                         const
  { return c; }
  virtual const charT* do_tolower(charT* low, const charT* high) const
  { return high; }

  virtual charT        do_widen(char c) const
  { return charT(c); }
  virtual const char*  do_widen(const char* lo,
                                const char* hi, charT* dest) const
  { 
    while (lo < hi)  
      *dest++ = charT(*lo++); 
    return hi; 
  }
  virtual char         do_narrow(charT c, char dfault) const
  { return dfault; }
  virtual const charT* do_narrow(const charT* lo, const charT* hi,
                                 char dfault, char* dest) const
  { return hi; }

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif

};

// ----------------------------------------------
// Standard derived facet -- ctype_byname<charT>.
// ----------------------------------------------

// Specialization for char.  Uses the passed name to build an appropriate mask
// table and upper-to-lower translate tables, which it passes to the base class
// class ctype<char> constructor.  The do_xxx virtual member functions are all
// inherited from the base class.

_RWSTD_TEMPLATE
class _RWSTDExport ctype_byname<char> : public ctype<char> {
 public:
  _EXPLICIT ctype_byname (const char*, size_t refs=0);

 protected:
  virtual ~ctype_byname ();

 private:
  // Constructor helper function:
  static const mask *get_mask_table (const char*);
};

#ifndef _RWSTD_NO_WIDE_CHAR

// -------------------------------------------------------
// Standard facet specialization -- ctype_byname<wchar_t>.
// -------------------------------------------------------

_RWSTD_TEMPLATE
class _RWSTDExport ctype_byname<wchar_t> : public ctype<wchar_t> {
 public:
  _EXPLICIT ctype_byname (const char*, size_t refs=0);

 protected:
  virtual ~ctype_byname();

// Virtual member functions inherited from ctype<wchar_t>:
// virtual bool do_is (mask m, wchar_t c) const;
// virtual const wchar_t* do_is (const wchar_t*, const wchar_t*, mask*) const;
// virtual const wchar_t* do_scan_is (mask,const wchar_t*,const wchar_t*) const;
// virtual const wchar_t* do_scan_not (mask,const wchar_t*,const wchar_t*) const;
// virtual wchar_t        do_toupper (wchar_t) const;
// virtual const wchar_t* do_toupper (wchar_t* low, const wchar_t* high) const;
// virtual wchar_t        do_tolower (wchar_t) const;
// virtual const wchar_t* do_tolower (wchar_t* low, const wchar_t* high) const;
//
// virtual wchar_t        do_widen (char) const;
// virtual const char*    do_widen (const char*, const char*, wchar_t*) const;
// virtual char           do_narrow (wchar_t, char dfault) const;
// virtual const wchar_t* do_narrow (const wchar_t* lo, const wchar_t* hi,
//                                   char dfault, char* dest) const;
};

#endif // _RWSTD_NO_WIDE_CHAR

// ----------------------------------------------
// Standard derived facet -- ctype_byname<charT>.
// ----------------------------------------------

template <class charT>
class ctype_byname: public ctype<charT> {
 public:
  _EXPLICIT ctype_byname (const char*, size_t refs=0):
      ctype<charT>(refs) { }

 protected:
  virtual ~ctype_byname() { }

// Virtual member functions inherited from ctype<charT>:
// virtual bool do_is (mask m, charT c) const;
// virtual const charT* do_is (const charT*, const charT*, mask* vec) const;
// virtual const charT* do_scan_is (mask m, const charT*, const charT*) const;
// virtual const charT* do_scan_not (mask m, const charT*, const charT*) const;
// virtual charT        do_toupper (charT) const;
// virtual const charT* do_toupper (charT* low, const charT* high) const;
// virtual charT        do_tolower (charT) const;
// virtual const charT* do_tolower (charT* low, const charT* high) const;
//
// virtual charT        do_widen (char) const;
// virtual const char*  do_widen (const char*,const char*, charT* dest) const;
// virtual char         do_narrow (charT, char dfault) const;
// virtual const charT* do_narrow (const charT* lo, const charT* hi,
//                                 char dfault, char* dest) const;
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

inline const digit_map<char>&
digit_map<char>::get_digit_map (const _RW_STD::ctype<char>& ct)
{
  return ct.__digit_map;
}

#ifndef _RWSTD_NO_NEW_TEMPLATE_SYNTAX
template <>
inline _RW_STD::ctype<char>* create_named_facet<_RW_STD::ctype<char> >
#else
inline _RW_STD::ctype<char>* create_named_facet
#endif // _RWSTD_NO_NEW_TEMPLATE_SYNTAX
    (_RW_STD::ctype<char>*,const char *name,size_t refs)
{ return new _RW_STD::ctype_byname<char>(name,refs); }

#ifndef _RWSTD_NO_NEW_TEMPLATE_SYNTAX
template <>
inline _RW_STD::ctype<char>* create_classic_facet<_RW_STD::ctype<char> >
#else
inline _RW_STD::ctype<char>* create_classic_facet
#endif // _RWSTD_NO_NEW_TEMPLATE_SYNTAX
    (_RW_STD::ctype<char>*) 
{ return new _RW_STD::ctype<char>(NULL,false,1); }
#ifndef _RWSTD_NO_NAMESPACE
} // namespace std
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/ctype.cc>
#endif

#endif // __STD_CTYPE__

#pragma option pop
#endif /* __BOR_RW__CTYPE_H */
