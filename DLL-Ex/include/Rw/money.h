#ifndef __MONEY_H
#define __MONEY_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * money - Declarations for the Standard Library money facets
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

#ifndef __STD_MONEY__
#define __STD_MONEY__

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale> 
#endif

#ifndef __STD_RW_LOCNUMRW__
#include <rw/numbrw>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

struct _RWSTDExport money_base {
  enum part { none, space, symbol, sign, value };
  struct pattern { char field[4]; };
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

template <class charT> class money_handler_base_1;
template <class charT> class money_reader_base_1;
template <class charT> class money_writer_base_1;
template <class charT,class OutputIterator> class money_reader_base_2;
template <class charT,class OutputIterator> class money_writer_base_2;

// --------------------------------------------------------
// Implementation class template -- moneypunct_init<charT>.
// --------------------------------------------------------

// Structure used to initialize a rwstd::moneypunct_data<charT>.

template <class charT>
class moneypunct_init {
 public:
  bool del_;                         // Delete when initialization is done
  charT dp_, ts_;                    // Decimal point and thousands separator
  const char *gr_;                   // Grouping pattern
  const charT *cs_;                  // Currency symbol string
  const charT *ps_, *ns_;            // Positive and negative sign strings
  int fd_;                           // Number of fractional digits
  _RW_STD::money_base::pattern pf_;  // Positive format pattern
  _RW_STD::money_base::pattern nf_;  // Negative format pattern
};

// ----------------------------------------
// Implementation class -- moneypunct_base.
// ----------------------------------------

// Contains parts of moneypunct_data<charT> that do not depend on the template
// parameter.

class _RWSTDExport moneypunct_base {
 public:
  static __RWSTD::moneypunct_init<char> *__get_named_init
      (const char*,bool);
};

// --------------------------------------------------------
// Implementation class template -- moneypunct_data<charT>.
// --------------------------------------------------------

// moneypunct<charT,Intl> derives from this (via moneypunct_impl<charT,Intl>)
// to get its private data members.

template <class charT>
class moneypunct_data :
    public moneypunct_base,
    public punct_data<charT>
{
  friend class money_handler_base_1<charT>;
#ifndef _RWSTD_NO_NAMESPACE
  friend class _RW_STD::moneypunct<charT,false>;
  friend class _RW_STD::moneypunct<charT,true>;
#else
  friend class moneypunct<charT,false>;
  friend class moneypunct<charT,true>;
#endif

  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

  string_type cs_;                  // Currency symbol
  string_type ps_, ns_;             // Positive and negative sign strings
  int fd_;                          // Number of fractional digits
  _RW_STD::money_base::pattern pf_, nf_;     // Positive and negative format patterns

 protected:
  moneypunct_data (moneypunct_init<charT>*);

  void __initfacetbase (const locale*);
  moneypunct_init<charT> *get_init_by_name_ (const char*,bool);
};
// -------------------------------------------------------------
// Implementation class template -- money_handler_base_1<charT>.
// -------------------------------------------------------------

// Contains common money_reader and money_writer functionality that depends
// only on the charT template parameter.

template <class charT>
class money_handler_base_1
{
  const moneypunct_data<charT> &mpunct;
 protected:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

  money_handler_base_1
      (const moneypunct_data<charT> &p): mpunct(p) { }

  inline static const moneypunct_data<charT>&
      get_punct_data (const _RW_STD::locale &loc,bool intl);

  const _RW_STD::money_base::pattern &get_pos_format() const { return mpunct.pf_; }
  const _RW_STD::money_base::pattern &get_neg_format() const { return mpunct.nf_; }
  const string_type &get_positive_sign() const      { return mpunct.ps_; }
  const string_type &get_negative_sign() const      { return mpunct.ns_; }
  const string_type &get_curr_symbol() const        { return mpunct.cs_; }
  int get_frac_digits() const                       { return mpunct.fd_; }
};

// ------------------------------------------------------------
// Implementation class template -- money_reader_base_1<charT>.
// ------------------------------------------------------------

// Contains parts of money_reader<charT,InputIterator> that depend only on the
// charT template parameter.

template <class charT>
class money_reader_base_1:
    public money_handler_base_1<charT>
{
 protected:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

  digit_reader_base_1<charT> &reader;

  money_reader_base_1
      (digit_reader_base_1<charT> &r,
       const moneypunct_data<charT> &mp);

 public:
  void get_money_string (string_type&,const char*);
};

// --------------------------------------------------------------------------
// Implementation class template -- money_reader_base_2<charT,InputIterator>.
// --------------------------------------------------------------------------

// Contains parts of money_reader<charT,InputIterator> that do not depend on
// the intl constructor parameter.

template <class charT, class InputIterator>
class money_reader_base_2 :
    public digit_reader<charT,InputIterator>,
    public money_reader_base_1<charT>
{
 protected:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,
                                _RW_STD::allocator<charT> > string_type;

  money_reader_base_2 (InputIterator &i,InputIterator &e,
      _RW_STD::ios_base &b,const moneypunct_data<charT> &mp);

  inline digit_reader_base_1<charT> &this_as_digit_reader () { return *this; }

 public:
  char *get_money_digits (void);    // Get monetary-format digits
};

// -------------------------------------------------------------------
// Implementation class template -- money_reader<charT,InputIterator>.
// -------------------------------------------------------------------

template <class charT, class InputIterator>
class money_reader :
    public money_reader_base_2<charT,InputIterator>
{
 public:
  money_reader (InputIterator &i,InputIterator &e,
      _RW_STD::ios_base &b,bool intl);
};
// ------------------------------------------------------------
// Implementation class template -- money_writer_base_1<charT>.
// ------------------------------------------------------------

// Contains parts of money_writer<charT,Intl,OutputIterator> that depend only
// on the charT template parameter.

template <class charT>
class money_writer_base_1 :
    public money_handler_base_1<charT>
{
 public:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

  void put_money (charT fill);
  void put_money (const string_type&,charT fill);

 protected:
  digit_writer_base_1<charT> &writer;

  money_writer_base_1
      (digit_writer_base_1<charT> &w,
       const moneypunct_data<charT> &mp);

  virtual void put_money_sub (const charT*,const charT*,bool,charT)=0;
};

// ---------------------------------------------------------------------------
// Implementation class template -- money_writer_base_2<charT,OutputIterator>.
// ---------------------------------------------------------------------------

// Contains parts of money_writer<charT,OutputIterator> that do not depend on
// the intl constructor parameter.

template <class charT,class OutputIterator>
class money_writer_base_2:
    public digit_writer<charT,OutputIterator>,
    public money_writer_base_1<charT>
{
 protected:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,
                                _RW_STD::allocator<charT> > string_type;

  money_writer_base_2 (OutputIterator &os,_RW_STD::ios_base &io,
      const moneypunct_data<charT> &mp);

  inline digit_writer_base_1<charT> &this_as_digit_writer () { return *this; }

  virtual void put_money_sub (const charT*,const charT*,bool,charT fill);
};

// --------------------------------------------------------------------
// Implementation class template -- money_writer<charT,OutputIterator>.
// --------------------------------------------------------------------

template <class charT,class OutputIterator>
class money_writer :
    public money_writer_base_2<charT,OutputIterator>
{
 public:
  money_writer (OutputIterator &os,_RW_STD::ios_base &io,bool intl);
};

template <class charT>
moneypunct_init<charT>* _RWSTDExportTemplate
fixup_moneypunct_init (moneypunct_init<char>*,charT*);

#ifndef _RWSTD_NO_NEW_TEMPLATE_SYNTAX
template <>
inline moneypunct_init<char>* fixup_moneypunct_init<char>
    (moneypunct_init<char> *init,char*)
#else
inline moneypunct_init<char>* fixup_moneypunct_init
    (moneypunct_init<char> *init,char*)
#endif // _RWSTD_NO_NEW_TEMPLATE_SYNTAX
{
  return init;
}

// -------------------------------------------------------------
// Implementation class template -- moneypunct_impl<charT,Intl>.
// -------------------------------------------------------------

// moneypunct<charT,Intl> derives from this to get the parts of its behavior
// that are specialized for the character type and the Intl format selection.

template <class charT,bool Intl>
class moneypunct_impl:
    public moneypunct_data<charT>
{
 protected:
  moneypunct_impl (void);
};

_RWSTD_TEMPLATE
class _RWSTDExport moneypunct_impl<char,false>:          // Specialization
    public moneypunct_data<char>
{
  friend class moneypunct_base;
 protected:
  typedef moneypunct_data<char> parent_type;
  static _RWSTDExportStatic moneypunct_init<char> ivals_; // Vendor-supplied
  moneypunct_impl
      ( moneypunct_init<char> *init=&ivals_ ):
        parent_type(init) { }
};

_RWSTD_TEMPLATE
class _RWSTDExport moneypunct_impl<char,true>:           // Specialization
    public moneypunct_data<char>
{
  friend class moneypunct_base;
 protected:
  typedef moneypunct_data<char> parent_type;
  static _RWSTDExportStatic moneypunct_init<char> ivals_; // Vendor-supplied
  moneypunct_impl
      ( moneypunct_init<char> *init=&ivals_ ):
        parent_type(init) { }
};

#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
class _RWSTDExport moneypunct_impl<wchar_t,false>:       // Specialization
    public moneypunct_data<wchar_t>
{
 protected:
  typedef moneypunct_data<wchar_t> parent_type;
  static _RWSTDExportStatic moneypunct_init<wchar_t> ivals_; // Vendor-supplied
  moneypunct_impl
      ( moneypunct_init<wchar_t> *init=&ivals_ ):
        parent_type(init) { }
};

_RWSTD_TEMPLATE
class _RWSTDExport moneypunct_impl<wchar_t,true>:        // Specialization
    public moneypunct_data<wchar_t>
{
 protected:
  typedef moneypunct_data<wchar_t> parent_type;
  static _RWSTDExportStatic moneypunct_init<wchar_t> ivals_; // Vendor-supplied
  moneypunct_impl
      ( moneypunct_init<wchar_t> *init=&ivals_ ):
        parent_type(init) { }
};
#endif // _RWSTD_NO_WIDE_CHAR

#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// ---------------------------------------------------------------
// Standard money parsing facet -- money_get<charT,InputIterator>.
// ---------------------------------------------------------------

template <class charT, class InputIterator>
class _RWSTDExportTemplate money_get: public locale::facet {
 public:
  typedef charT char_type;
  typedef InputIterator iter_type;
  typedef basic_string<charT,char_traits<charT>,allocator<charT> > string_type;

  _EXPLICIT money_get (size_t refs=0): locale::facet(refs,locale::monetary) { }

  iter_type get (iter_type s,  iter_type e, bool intl, ios_base& f,
                 ios_base::iostate& err, long double& units) const
  { return do_get(s,e,intl,f,err,units); }

  iter_type get (iter_type s, iter_type e,  bool intl, ios_base& f,
                 ios_base::iostate& err, string_type& digits) const
  { return do_get(s,e,intl,f,err,digits); }

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::monetary, __ok_implicit = 1 };

 protected:
  virtual ~money_get();

  virtual iter_type do_get (iter_type, iter_type,  bool, ios_base&,
                            ios_base::iostate&, long double& units) const;
  virtual iter_type do_get (iter_type, iter_type,  bool, ios_base&,
                            ios_base::iostate&, string_type& digits) const;

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// -------------------------------------------------------------------
// Standard money formatting facet -- money_put<charT,OutputIterator>.
// -------------------------------------------------------------------

template <class charT, class OutputIterator>
class _RWSTDExportTemplate money_put: public locale::facet {
 public:
  typedef charT char_type;
  typedef OutputIterator iter_type;
  typedef basic_string<charT,char_traits<charT>,allocator<charT> > string_type;

  _EXPLICIT money_put (size_t refs=0): locale::facet(refs,locale::monetary) { }

#ifndef _RWSTD_NO_LONG_DOUBLE
  iter_type put (iter_type out, bool intl, ios_base& io, char_type fill,
                 long double quant) const
#else
  iter_type put (iter_type out, bool intl, ios_base& io, char_type fill,
                 double quant) const
#endif
     { return do_put(out,intl,io,fill,quant); }

  iter_type put (iter_type out, bool intl, ios_base& io, char_type fill,
                 const string_type& digits) const
     { return do_put(out,intl,io,fill,digits); }

  static locale::id  id;

  // Implementation:
  enum { __facet_cat = locale::monetary, __ok_implicit = 1 };

 protected:
  virtual ~money_put();

#ifndef _RWSTD_NO_LONG_DOUBLE
  virtual iter_type do_put (iter_type out, bool intl, ios_base& io,
                            char_type fill, long double quant) const;
#else
  virtual iter_type do_put (iter_type out, bool intl, ios_base& io,
                            char_type fill, double quant) const;
#endif

  virtual iter_type do_put (iter_type out, bool intl, ios_base& io,
                            char_type fill, const string_type &digits) const;

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// -----------------------------------------------------------
// Standard money punctuation facet -- moneypunct<charT,bool>.
// -----------------------------------------------------------

template <class charT, bool Intl>
class _RWSTDExportTemplate moneypunct: public locale::facet, public money_base,
    public __RWSTD::moneypunct_impl<charT,Intl>
{
 public:
  typedef charT char_type;
  typedef basic_string<charT,char_traits<charT>,allocator<charT> > string_type;

  #ifndef _RWSTD_NO_STI_SIMPLE
  static const bool intl = Intl;
  #else
  enum { intl = Intl };
  #endif

  // The second parameter (i) to the constructor is implementation specific.
  // For portable code, always let it default as shown.
  _EXPLICIT moneypunct (size_t refs=0,
      __RWSTD::moneypunct_init<charT> *i = get_ivals_());

  char_type    decimal_point() const  { return do_decimal_point(); }
  char_type    thousands_sep() const  { return do_thousands_sep(); }
  string       grouping()      const  { return do_grouping(); }
  string_type  curr_symbol()   const  { return do_curr_symbol(); };
  string_type  positive_sign() const  { return do_positive_sign(); }
  string_type  negative_sign() const  { return do_negative_sign(); }
  int          frac_digits()   const  { return do_frac_digits(); }
  pattern      pos_format()    const  { return do_pos_format(); }
  pattern      neg_format()    const  { return do_neg_format(); }

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::monetary, __ok_implicit = 1 };

 protected:
  virtual ~moneypunct();

  virtual char_type    do_decimal_point()  const;
  virtual char_type    do_thousands_sep()  const;
  virtual string       do_grouping()       const;
  virtual string_type  do_curr_symbol()    const;
  virtual string_type  do_positive_sign()  const;
  virtual string_type  do_negative_sign()  const;
  virtual int          do_frac_digits()    const;
  virtual pattern      do_pos_format()     const;
  virtual pattern      do_neg_format()     const;

 private:
  void __initfacet (const locale*);

  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif

 public:
  static __RWSTD::moneypunct_init<charT> *get_ivals_ ()
    { return &__RWSTD::moneypunct_impl<charT,Intl>::ivals_; }
};

template <class charT,bool Intl>
inline moneypunct<charT,Intl>::moneypunct
    (size_t refs,__RWSTD::moneypunct_init<charT> *init):
     locale::facet(refs,locale::monetary),
     __RWSTD::moneypunct_impl<charT,Intl>(init) { }
// --------------------------------------------------------
// Standard derived facet -- moneypunct_byname<charT,Intl>.
// --------------------------------------------------------

template <class charT, bool Intl>
class moneypunct_byname: public moneypunct<charT,Intl> {
 public:
  _EXPLICIT moneypunct_byname (const char*, size_t refs=0);

 protected:
  virtual ~moneypunct_byname();

// Virtual member functions inherited from moneypunct<charT,Intl>:
// virtual char_type     do_decimal_point () const;
// virtual char_type     do_thousands_sep () const;
// virtual string        do_grouping ()      const;
// virtual string_type   do_curr_symbol ()   const;
// virtual string_type   do_positive_sign () const;
// virtual string_type   do_negative_sign () const;
// virtual int           do_frac_digits ()   const;
// virtual pattern       do_pos_format ()    const;
// virtual pattern       do_neg_format ()    const;
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

#ifndef _RWSTD_NO_FUNC_PARTIAL_SPEC
template <class charT,bool Intl>
inline _RW_STD::moneypunct<charT,Intl>* create_named_facet
    (_RW_STD::moneypunct<charT,Intl>*,const char *name,size_t refs)
{ return new _RW_STD::moneypunct_byname<charT,Intl>(name,refs); }
#else

inline _RW_STD::moneypunct<char,false>* create_named_facet
    (_RW_STD::moneypunct<char,false>*,const char *name,size_t refs)
{ return new _RW_STD::moneypunct_byname<char,false>(name,refs); }
inline _RW_STD::moneypunct<char,true>* create_named_facet
    (_RW_STD::moneypunct<char,true>*,const char *name,size_t refs)
{ return new _RW_STD::moneypunct_byname<char,true>(name,refs); }

#ifndef _RWSTD_NO_WIDE_CHAR
inline _RW_STD::moneypunct<wchar_t,false>* create_named_facet
    (_RW_STD::moneypunct<wchar_t,false>*,const char *name,size_t refs)
{ return new _RW_STD::moneypunct_byname<wchar_t,false>(name,refs); }

inline _RW_STD::moneypunct<wchar_t,true>* create_named_facet
    (_RW_STD::moneypunct<wchar_t,true>*,const char *name,size_t refs)
{ return new _RW_STD::moneypunct_byname<wchar_t,true>(name,refs); }
#endif
#endif
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/money.cc>
#endif
#endif // __STD_MONEY__
#pragma option pop
#endif /* __MONEY_H */
