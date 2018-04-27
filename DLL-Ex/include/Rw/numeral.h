#ifndef __NUMERAL_H
#define __NUMERAL_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * numeral - Declarations for the Standard Library numeric facets
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

#ifndef __STD_NUMERAL__
#define __STD_NUMERAL__ 1

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale> 
#endif

#ifndef __STD_IOSBASE__
#include <rw/iosbase> 
#endif

#ifndef __STD_LIMITS
#include <limits>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

// ------------------------------------------------------
// Implementation class template -- numpunct_init<charT>.
// ------------------------------------------------------

// Structure used to initialize a rwstd::numpunct_data.

template <class charT>
class _RWSTDExportTemplate numpunct_init {
 public:
  bool del_;                    // Kill the bearer of this message
  charT dp_, ts_;               // Decimal point and thousands separator
  const char *gr_;              // Digit grouping rule
  const charT *tn_, *fn_;       // Strings for boolean true and false
};

// --------------------------------------
// Implementation class -- numpunct_base.
// --------------------------------------

// Contains parts of numpunct<charT> that don't depend on the charT template
// parameter.

class _RWSTDExport numpunct_base {
 public:
  static numpunct_init<char> *get_named_init_ (const char*);
};

// ------------------------------------------------------
// Implementation class template -- numpunct_data<charT>.
// ------------------------------------------------------

// numpunct<charT> derives from this (via rwstd::numpunct_impl) to get its
// private data members.

template <class charT>
class _RWSTDExportTemplate numpunct_data :
    public numpunct_base,
    public punct_data<charT>
{
#ifndef _RWSTD_NO_NAMESPACE
  friend class _RW_STD::numpunct<charT>;
#else
  friend class numpunct<charT>;
#endif
  friend class keyword_cracker<charT>;

  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

  string_type tn_, fn_;

  keyword_def<charT> tf_defs_[2];
  keyword_map<charT> tf_map_;

 protected:
  inline numpunct_data (const numpunct_init<charT>*);
  numpunct_init<charT> *get_init_by_name_ (const char*);
  void __initfacetbase (const locale*);
};

template <class charT>
inline numpunct_data<charT>::numpunct_data
    (const numpunct_init<charT> *init)
{
  if (!init) {
    this->dp_=charT('.');
    this->ts_=charT(',');
  } else {
    this->dp_=init->dp_;
    this->ts_=init->ts_;
    this->gr_=init->gr_;
    tn_=init->tn_;
    fn_=init->fn_;

    if (init->del_)
      delete[] (char*) init;
  }
}

template <class charT>
numpunct_init<charT>* _RWSTDExportTemplate
fixup_numpunct_init
    (numpunct_init<char>*,charT*);

#ifndef _RWSTD_NO_NEW_TEMPLATE_SYNTAX
template <>
inline numpunct_init<char>* 
fixup_numpunct_init<char>(numpunct_init<char> *init,char*)
#else
inline numpunct_init<char>* 
fixup_numpunct_init(numpunct_init<char> *init,char*)
#endif // _RWSTD_NO_NEW_TEMPLATE_SYNTAX
{  return init; }

// ------------------------------------------------------
// Implementation class template -- numpunct_impl<charT>.
// ------------------------------------------------------

// numpunct<charT> derives from this to obtain the part of its behavior that
// must be specialized for char and wchar_t.  This lets us avoid specializing
// the whole numpunct<charT> template.  Currently the only specialized behavior
// is the initialization of private data members in the constructor.

template <class charT>
class _RWSTDExportTemplate numpunct_impl :
    public numpunct_data<charT>
{
 protected:
  numpunct_impl (const numpunct_init<charT>* init)
   : numpunct_data<charT>(init) { }
 public:
  static const numpunct_init<charT> *get_ivals_ ()
    { return NULL; }
};

_RWSTD_TEMPLATE
class _RWSTDExport numpunct_impl<char>:                  // Specialization
    public numpunct_data<char>
{
#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static _RWSTDExport numpunct_init<char> ivals_;        // Vendor-supplied
#else
  static numpunct_init<char> ivals_;
#endif

 protected:
  numpunct_impl
      (const numpunct_init<char> *init):
       numpunct_data<char>(init) { }
 public:
  static const numpunct_init<char> *get_ivals_ ()
    { return &ivals_; }
};

#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
class _RWSTDExport numpunct_impl<wchar_t>:               // Specialization
    public numpunct_data<wchar_t>
{
#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static _RWSTDExport numpunct_init<wchar_t> ivals_;     // Vendor-supplied
#else
  static numpunct_init<wchar_t> ivals_;
#endif

 protected:
  numpunct_impl
      (const numpunct_init<wchar_t> *init):
       numpunct_data<wchar_t>(init) { }
 public:
  static const numpunct_init<wchar_t> *get_ivals_ ()
    { return &ivals_; }
};
#endif // _RWSTD_NO_WIDE_CHAR

#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// ---------------------------------------------------------------
// Standard numeric parsing facet -- num_get<charT,InputIterator>.
// ---------------------------------------------------------------

template <class charT, class InputIterator>
class _RWSTDExportTemplate num_get: public locale::facet
{
 public:
  typedef charT char_type;
  typedef InputIterator iter_type;

  _EXPLICIT num_get (size_t refs=0): locale::facet(refs,locale::numeric) { }

#ifndef _RWSTD_NO_BOOL
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 bool& v) const            { return do_get(i,e,f,err,v); }
#endif
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 long& v) const            { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 unsigned short& v) const  { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 unsigned int& v) const    { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 unsigned long& v) const   { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 float& v) const           { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 double& v) const          { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 long double& v) const     { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 void*& p) const           { return do_get(i,e,f,err,p); }

  static locale::id id;

  // Extension for compilers that have an extra-long integer type:
#ifdef _RWSTD_LONG_LONG
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 _RWSTD_LONG_LONG& v) const 
  { return do_get(i,e,f,err,v); }
  iter_type get (iter_type i, iter_type e, ios_base &f, ios_base::iostate &err,
                 unsigned _RWSTD_LONG_LONG& v) const 
  { return do_get(i,e,f,err,v); }
#endif

  // Implementation:
  enum { __facet_cat = locale::numeric, __ok_implicit = 1 };

 protected:
  virtual ~num_get();

#ifndef _RWSTD_NO_BOOL
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, bool& v) const;
#endif
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, long& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, unsigned short& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, unsigned int& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, unsigned long& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, float& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, double& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, long double& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, void*& p) const;

#ifdef _RWSTD_LONG_LONG
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, 
                            _RWSTD_LONG_LONG& v) const;
  virtual iter_type do_get (iter_type, iter_type, ios_base&,
                            ios_base::iostate& err, 
                            unsigned _RWSTD_LONG_LONG& v) const;
#endif

  // Implementation:

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// -------------------------------------------------------------------
// Standard numeric formatting facet -- num_put<charT,OutputIterator>.
// -------------------------------------------------------------------

template <class charT, class OutputIterator>
class _RWSTDExportTemplate num_put: public locale::facet {
 public:
  typedef charT char_type;
  typedef OutputIterator iter_type;

  _EXPLICIT num_put (size_t refs=0): locale::facet(refs,locale::numeric) { }

#ifndef _RWSTD_NO_BOOL
  iter_type put (iter_type s, ios_base& f, char_type fill, bool v)
                 const { return do_put(s,f,fill,v); }
#endif
  iter_type put (iter_type s, ios_base& f, char_type fill, long v)
                 const { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, unsigned long v)
                 const { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, double v)
                 const { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, long double v)
                 const { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, const void* p)
                 const { return do_put(s,f,fill,p); }

#ifndef _RWSTD_STRICT_ANSI
  // Rogue Wave extensions.
#ifdef __TURBOC__
  iter_type put (iter_type s, ios_base& f, char_type fill, float v)
                 const { return do_put(s,f,fill,(double)v); }
#endif
  iter_type put (iter_type s, ios_base& f, char_type fill, short v)
                 const { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, unsigned short v)
                 const { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, int v)
                 const { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, unsigned int v)
                 const { return do_put(s,f,fill,v); }
#endif

#ifdef _RWSTD_LONG_LONG
  iter_type put (iter_type s, ios_base& f, char_type fill, 
                 _RWSTD_LONG_LONG v) const 
  { return do_put(s,f,fill,v); }
  iter_type put (iter_type s, ios_base& f, char_type fill, 
                 unsigned _RWSTD_LONG_LONG v) const 
  { return do_put(s,f,fill,v); }
#endif

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::numeric, __ok_implicit = 1 };

 protected:
  virtual ~num_put();

#ifndef _RWSTD_NO_BOOL
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            bool v) const;
#endif
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            long v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            unsigned long v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            double v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            long double v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            const void* p) const;

#ifndef _RWSTD_STRICT_ANSI
  // Rogue Wave extensions.
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            short v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            unsigned short v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            int v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            unsigned int v) const;
#endif

#ifdef _RWSTD_LONG_LONG
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            _RWSTD_LONG_LONG v) const;
  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
                            unsigned _RWSTD_LONG_LONG v) const;
#endif

  // Implementation.

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// ------------------------------------------------------
// Standard numeric punctuation facet -- numpunct<charT>.
// ------------------------------------------------------

template <class charT>
class _RWSTDExportTemplate numpunct: public locale::facet,
    public __RWSTD::numpunct_impl<charT>
{
 public:
  typedef charT char_type;
  typedef basic_string<charT,char_traits<charT>,allocator<charT> >
    string_type;

  // The second parameter (i) to the constructor is implementation specific.
  // For portable code, always let it default as shown.
  _EXPLICIT numpunct (size_t refs=0,
#if !defined(_MSC_VER) || defined(__BORLANDC__)
      const __RWSTD::numpunct_init<charT> *i = __RWSTD::numpunct_impl<charT>::get_ivals_());
#else
      const __RWSTD::numpunct_init<charT> *i = get_ivals_());
#endif
  char_type   decimal_point() const { return do_decimal_point(); }
  char_type   thousands_sep() const { return do_thousands_sep(); }
  string      grouping()      const { return do_grouping(); }
  string_type truename()      const { return do_truename(); }
  string_type falsename()     const { return do_falsename(); }

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::numeric, __ok_implicit = 1 };

 protected:
  virtual ~numpunct();

  virtual char_type   do_decimal_point() const;
  virtual char_type   do_thousands_sep() const;
  virtual string      do_grouping()      const;
  virtual string_type do_truename()      const;
  virtual string_type do_falsename()     const;

  // Implementation:

 private:
  void __initfacet (const locale*);

  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

template <class charT>
inline numpunct<charT>::numpunct
    (size_t refs,const __RWSTD::numpunct_init<charT> *init):
     locale::facet(refs,locale::numeric),
     __RWSTD::numpunct_impl<charT>(init)
{ }

// -------------------------------------------------
// Standard derived facet -- numpunct_byname<charT>.
// -------------------------------------------------

template <class charT>
class numpunct_byname: public numpunct<charT> {
 public:
  _EXPLICIT numpunct_byname (const char*, size_t refs=0);

 protected:
  virtual ~numpunct_byname();

// Virtual member functions inherited from numpunct<charT>:
// virtual char_type   do_decimal_point() const;
// virtual char_type   do_thousands_sep() const;
// virtual string      do_grouping() const;
// virtual string_type do_truename() const;
// virtual string_type do_falsename() const;
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

#ifndef _RWSTD_NO_FUNC_PARTIAL_SPEC
template <class charT>
inline _RW_STD::numpunct<charT>* create_named_facet
    (_RW_STD::numpunct<charT>*,const char *name,size_t refs)
{ return new _RW_STD::numpunct_byname<charT>(name,refs); }
#else

inline _RW_STD::numpunct<char>* create_named_facet
    (_RW_STD::numpunct<char>*,const char *name,size_t refs)
{ return new _RW_STD::numpunct_byname<char>(name,refs); }

#ifndef _RWSTD_NO_WIDE_CHAR
inline _RW_STD::numpunct<wchar_t>* create_named_facet
    (_RW_STD::numpunct<wchar_t>*,const char *name,size_t refs)
{ return new _RW_STD::numpunct_byname<wchar_t>(name,refs); }
#endif
#endif

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/numeral.cc>
#endif
#endif // __STD_NUMERAL__
#pragma option pop
#endif /* __NUMERAL_H */
