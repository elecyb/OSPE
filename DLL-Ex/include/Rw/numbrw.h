#ifndef __NUMBRW_H
#define __NUMBRW_H
#pragma option push -b -a8 -pc -Vx- -Ve- -A- -w-inl -w-aus -w-sig
// -*- C++ -*-
/****************************************************************************
 *
 * rw/numbrw - Internal classes for numeric formatting and parsing.
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

#ifndef __STD_RW_LOCNUMRW__
#define __STD_RW_LOCNUMRW__

#ifndef _RWSTD_NO_NEW_HEADER
#include <ctime>
#else
#include <time.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

// -------------------------------------------------------
// Implementation class template -- timepunct_init<charT>.
// -------------------------------------------------------

// Structure used to initialize the private data members of timepunct<charT>.
template <class charT>
class _RWSTDExportTemplate timepunct_init
{
public:
  const charT *dn_[7][2];       // Day names and abbreviations
  const charT *mn_[12][2];      // Month names and abbreviations
  const charT *ampm_[2];        // AM/PM strings
  const charT *bad_;            // Bad value output signal
  const charT *ord_[100];       // Ordinal numbers
  const charT *pat_[6];         // Patterns for formats "xXcDrT" resp.
};

template <class charT>
class _RWSTDExport timepunct_loc;

_RWSTD_TEMPLATE
class _RWSTDExport timepunct_loc<char> 
{
  typedef _RW_STD::basic_string<char,_RW_STD::char_traits<char>,_RW_STD::allocator<char> > string_type;
  const timepunct_init<char>& ti_;

 public:
  timepunct_loc (const timepunct_init<char> &i)
    : ti_(i) 
  {}

  const string_type get_day(int i, bool abbr) const;
  const string_type get_month(int i, bool abbr) const;
  const string_type get_ampm(bool afternoon) const;
  const string_type get_bad() const  { return ti_.bad_; }
  const string_type get_ord(int i) const { return ti_.ord_[i]; }
  const string_type get_pattern(int i) const { return ti_.pat_[i]; }
};

#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
class _RWSTDExport timepunct_loc<wchar_t> 
{
  typedef _RW_STD::basic_string<wchar_t,_RW_STD::char_traits<wchar_t>,_RW_STD::allocator<wchar_t> > string_type;
  const timepunct_init<wchar_t>& ti_;

 public:
  timepunct_loc (const timepunct_init<wchar_t> &i)
    : ti_(i) 
  {}

#ifndef _RWSTD_NO_WSTR
  const string_type get_day(int i, bool abbr) const;
  const string_type get_month(int i, bool abbr) const;
  const string_type get_ampm(bool afternoon) const;
#else
  const string_type get_day(int i, bool abbr) const { return ti_.dn_[i][abbr]; }
  const string_type get_month(int i, bool abbr) const { return ti_.mn_[i][abbr]; }
  const string_type get_ampm(bool afternoon) const { return ti_.ampm_[afternoon]; }
#endif //  _RWSTD_NO_WSTR
  const string_type get_bad() const  { return ti_.bad_; }
  const string_type get_ord(int i) const { return ti_.ord_[i]; }
  const string_type get_pattern(int i) const { return ti_.pat_[i]; }
};
#endif // _RWSTD_NO_WIDE_CHAR
template <class charT>
class _RWSTDExportTemplate timepunct_loc
{
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;
  const timepunct_init<charT>& ti_;

 public:
  timepunct_loc (const timepunct_init<charT> &i)
    : ti_(i) 
  {}

  const string_type get_day(int i, bool abbr) const  { return ti_.dn_[i][abbr]; }
  const string_type get_month(int i, bool abbr) const { return ti_.mn_[i][abbr]; }
  const string_type get_ampm(bool afternoon) const { return ti_.ampm_[afternoon]; }
  const string_type get_bad() const  { return ti_.bad_; }
  const string_type get_ord(int i) const { return ti_.ord_[i]; }
  const string_type get_pattern(int i) const { return ti_.pat_[i]; }
};

// -------------------------------------------------------
// Implementation class template -- timepunct_data<charT>.
// -------------------------------------------------------

// timepunct<charT> derives from this (via rwstd::timepunct_impl) to get its
// private data members.

template <class charT>
class _RWSTDExportTemplate timepunct_data {
  friend class timepunct<charT>;
  friend class keyword_cracker<charT>;
 public:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;
 private:

  string_type dn_[7][2];
  string_type mn_[12][2];
  string_type ampm_[2];
  string_type bad_;
  string_type ord_[100];
  string_type pat_[6];

  keyword_def<charT> dn_defs_[7][2];
  keyword_map<charT> dn_map_;
  keyword_def<charT> mn_defs_[12][2];
  keyword_map<charT> mn_map_;
  keyword_def<charT> ampm_defs_[2];
  keyword_map<charT> ampm_map_;

 protected:
  timepunct_data (const timepunct_loc<charT> &i);
  void __initpat (const locale*);
  void __initfacet (const locale*);
};

// -------------------------------------------------------
// Implementation class template -- timepunct_impl<charT>.
// -------------------------------------------------------

// timepunct<charT> derives from this to get the parts of its behavior that
// must be specialized on the character type.  Currently the only specialized
// behavior is the initialization logic in the constructor.

template <class charT>
class _RWSTDExportTemplate timepunct_impl :
    public timepunct_data<charT>
{
 protected:
  timepunct_impl(void);
};

_RWSTD_TEMPLATE
class _RWSTDExport timepunct_impl<char>:                 // Specialization
    public timepunct_data<char>
{
#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static _RWSTDExport timepunct_init<char> __ivals;      // Vendor-supplied
#else
  static timepunct_init<char> __ivals;
#endif

 protected:
  timepunct_impl (void):
    timepunct_data<char>(timepunct_loc<char>(__ivals)) { }
};

#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
class _RWSTDExport timepunct_impl<wchar_t>:              // Specialization
    public timepunct_data<wchar_t>
{
#if !defined(_MSC_VER) || defined(__BORLANDC__)
  static _RWSTDExport timepunct_init<wchar_t> __ivals;   // Vendor-supplied
#else
  static timepunct_init<wchar_t> __ivals;
#endif

 protected:
  timepunct_impl(void):
      timepunct_data<wchar_t>(timepunct_loc<wchar_t>(__ivals)) { }
};
#endif // _RWSTD_NO_WIDE_CHAR
// ----------------------------------------------------
// Time and date punctuation facet -- timepunct<charT>.
// ----------------------------------------------------

template <class charT>
class _RWSTDExportTemplate timepunct : public _RW_STD::locale::facet,
    public timepunct_impl<charT>
{
 public:
  typedef charT char_type;
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> >
    string_type;

  _EXPLICIT timepunct (size_t refs=0):
      _RW_STD::locale::facet(refs,_RW_STD::locale::time) { }

  string_type dayname (int day, bool abbreviated) const
      { return do_dayname(day,abbreviated); }
  string_type monthname (int month, bool abbreviated) const
      { return do_monthname(month,abbreviated); }
  string_type ordinal (int number) const
      { return do_ordinal(number); }

  static _RW_STD::locale::id id;

  // Implementation:
  enum { __facet_cat = _RW_STD::locale::time, __ok_implicit = 1 };

 protected:
  virtual ~timepunct() { }

  virtual string_type do_dayname (int day, bool abbreviated) const;
  virtual string_type do_monthname (int month, bool abbreviated) const;
  virtual string_type do_ordinal (int number) const;

 private:
  void __initfacet (const locale*);

  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  _RW_STD::locale::id &__get_id (void) const { return id; }
  #endif
};
// --------------------------------------------------------
// Implementation class template -- keyword_cracker<charT>.
// --------------------------------------------------------

// Gives derived classes a backdoor way to get the private keyword_map and
// other members out of numpunct and timepunct facets.

template <class charT>
class _RWSTDExportTemplate keyword_cracker {
 public:
  static const keyword_map<charT>& get_tf_map
      (const _RW_STD::numpunct<charT> &nump)
      { return nump.tf_map_; }
  static const keyword_map<charT>& get_day_map
      (const timepunct<charT>& timp)
      { return timp.dn_map_; }
  static const keyword_map<charT>& get_month_map
      (const timepunct<charT>& timp)
      { return timp.mn_map_; }
  static const keyword_map<charT>& get_ampm_map
      (const timepunct<charT>& timp)
      { return timp.ampm_map_; }
#ifndef _RWSTD_NO_NAMESPACE
  static const _TYPENAME _RW_STD::numpunct<charT>::string_type& get_tf_string
#else
  static const _TYPENAME numpunct<charT>::string_type& get_tf_string
#endif
      (const _RW_STD::numpunct<charT>& nump,bool v)
      { return v? nump.tn_ : nump.fn_; }
  static const _TYPENAME timepunct<charT>::string_type&
      get_day_string
      (const timepunct<charT>& timp,unsigned n,bool abbr)
      { return n<7? timp.dn_[n][abbr] : timp.bad_; }
  static const _TYPENAME timepunct<charT>::string_type&
      get_month_string
      (const timepunct<charT>& timp,unsigned n,bool abbr)
      { return n<12? timp.mn_[n][abbr] : timp.bad_; }
  static const _TYPENAME timepunct<charT>::string_type&
      get_ampm_string
      (const timepunct<charT>& timp,bool pm)
      { return timp.ampm_[pm]; }
  static const _TYPENAME timepunct<charT>::string_type&
      get_ord_string
      (const timepunct<charT>& timp,unsigned n)
      { return n<99? timp.ord_[n] : timp.bad_; }
  static const _TYPENAME timepunct<charT>::string_type&
      get_patt_string
      (const timepunct<charT>& timp,unsigned n)
      { return n<6? timp.pat_[n] : timp.bad_; }
};

// -------------------------------------------------------------
// Implementation class template -- digit_handler_base_1<charT>.
// -------------------------------------------------------------

// Contains charT-dependent functionality that is common to the digit_reader
// and digit_writer classes, particularly related to getting access to ctype
// and punct facets they both use.

template <class charT>
class _RWSTDExportTemplate digit_handler_base_1:
    public keyword_cracker<charT>
{
 public:
  const _RW_STD::ctype<charT> &ctyp;
  const digit_map<charT>& dmap;
  const punct_data<charT>& punct;

  // Constructor for general numerics, gets punct from loc's numpunct facet.
  digit_handler_base_1 (const _RW_STD::locale &loc);

  // Constructor for money, passed punct_data is in fact a moneypunct facet.
  digit_handler_base_1 (const _RW_STD::locale &loc,const punct_data<charT>&);
};

// ------------------------------------------
// Implementation class -- digit_reader_base.
// ------------------------------------------

// Contains digit_reader members that do not depend on the digit_reader
// template parameters, particularly for converting strings of char digits
// to long and floating-point binary values.

class _RWSTDExport digit_reader_base : public digit_map_base
{
 public:
  enum {
    good              = 0x0000,
    no_digits         = 0x0001,
    too_many_digits   = 0x0002,
    too_many_groups   = 0x0004,
    group_too_long    = 0x0008,
    group_is_empty    = 0x0010,
    bad_grouping      = 0x0020,
    bad_exponent      = 0x0040,
    overflow          = 0x0080,
    bad_curr_symbol   = 0x0100,
    bad_sign          = 0x0200
  };

  enum {
    digit_buf_size = LDBL_MAX_10_EXP+200
  };

  // Fields defining digits to be converted, usually filled in by derived
  // class before calling one of the conversion methods below.
  int error;                    // Bit-field
  int radix;                    // 8, 10, or 16, 0=not yet determined
  bool is_signed;               // Sign allowed in input
  bool negative;                // Minus sign was present
  bool advanced;                // Iterator was advanced
  bool reached_end;             // Needed a char, but iterator matched end
  bool exp_negative;            // Minus sign was present on exponent
  char *frac_beg;               // Start of fractional part of digits
  char *exp_beg;                // Start of exponent in digits
  char digits[digit_buf_size];  // Binary digits (i.e. 0,1,2 not '0','1','2')

  digit_reader_base (void): error(good), radix(0),
      is_signed(true), negative(false), advanced(false), reached_end(false)
  { }

  unsigned long to_ulong (char *end);
  unsigned long to_ulong_dec (char *beg,char *end);

#ifdef _RWSTD_LONG_LONG
  unsigned _RWSTD_LONG_LONG to_ulong_ulong (char *end);
#endif

  void *to_pointer (char *end);
  float to_float (char *end);
  double to_double (char *end);
  long double to_long_double (char *end);

 private:
  void to_floating_point (char *end, char *pattern, void *result);
};

// ------------------------------------------------------------
// Implementation class template -- digit_reader_base_1<charT>.
// ------------------------------------------------------------

// Contains parts of digit_reader that depend on charT but not on the iterator
// type.

template <class charT>
class _RWSTDExportTemplate digit_reader_base_1 :
    public digit_reader_base,
    public digit_handler_base_1<charT>
{
 public:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

 protected:
  // Constructor for general numerics, gets punct from loc's numpunct<charT>.
  digit_reader_base_1 (const _RW_STD::locale &loc);

  // Constructor for use by derived money_reader, caller passes punct, which
  // in fact is loc's moneypunct<charT,true|false> facet.
  digit_reader_base_1 (const _RW_STD::locale &loc, const punct_data<charT>&);

  // These could be moved to digit_handler_base_1<charT> ...
  charT get_decimal_point() const { return this->punct.dp_; }
  charT get_thousands_sep() const { return this->punct.ts_; }
  const char *get_grouping() const { return this->punct.gr_.c_str(); }
};

// -------------------------------------------------------------------
// Implementation class template -- digit_reader<charT,InputIterator>.
// -------------------------------------------------------------------

// Facets that do numeric input use temporary objects of this class to
// extract keywords and strings of digits and punctuation from the input
// stream.

template <class charT,class InputIterator>
class _RWSTDExportTemplate digit_reader :
    public digit_reader_base_1<charT>
{
 public:
  // Constructor for reading general numerics.
  digit_reader (InputIterator& in,InputIterator& end,
      _RW_STD::ios_base &io);

 protected:
  // Constructor for use by derived money_reader class.
  digit_reader (InputIterator& in,InputIterator& end,
      _RW_STD::ios_base &io,const punct_data<charT>&);

 public:
  char *get_int_digits (void);      // Get integer-format digits
  char *get_float_digits (void);    // Get floating point-format digits
  char *get_pointer_digits (void);  // Get pointer-format digits

  // Parse keyword from input, return associated integer value
  int get_keyword (const keyword_map<charT>&);

 protected:
  _RW_STD::ios_base &io;
  InputIterator& in;
  InputIterator& end;

  const char *grouping;
  charT thousands_sep;
  char groups[40];
  char *gpos;

  // Helper functions
  char *get_digit_string (char*);       // Get a string of digits
  char *get_digit_groups (char*);       // Get grouped digits (recursive)

  inline bool at_end (void) {           // Test for end of stream, and
#ifdef _HPACC_
    if (_RW_STD::operator == (in,end)) {
#else
    if (in == end) {                    //  remember whether end was
#endif
      this->reached_end=true;           //  ever reached
      return true;
    }
    return false;
  }
};
// ------------------------------------------
// Implementation class -- digit_writer_base.
// ------------------------------------------

// Contains the parts of digit_writer that do not depend on the template
// parameters.

class _RWSTDExport digit_writer_base :
    public digit_map_base
{
 public:
  digit_writer_base (_RW_STD::ios_base &b);

  void get_pattern(char *p, char *prefix, bool is_signed);
  bool get_f_pattern(char *p, char prefix);
  void digitize (const void*);
  void digitize (unsigned short);
  void digitize (short);
  void digitize (unsigned int);
  void digitize (int);
  void digitize (unsigned long);
  void digitize (long);
#ifdef _RWSTD_LONG_LONG
  void digitize (unsigned _RWSTD_LONG_LONG);
  void digitize (_RWSTD_LONG_LONG);
#endif
  void digitize (double);
#ifndef _RWSTD_NO_LONG_DOUBLE
  void digitize (long double);
#endif

  _RW_STD::ios_base &io;
  _RW_STD::ios_base::fmtflags flags;
  int precision,width,radix,iprecision,num_groups;
  enum { left, internal, right } adjust;
  bool fractional,separable;
  char *start,*end,*group;
  char buffer[400];
  char groups[150];

  int calc_groups (int,const char*);
};

// ------------------------------------------------------------
// Implementation class template -- digit_writer_base_1<charT>.
// ------------------------------------------------------------

// Contains parts of digit_writer<charT,OutputWriter> that depend only on the
// charT parameter.

template <class charT>
class _RWSTDExportTemplate digit_writer_base_1 :
    public digit_writer_base,
    public digit_handler_base_1<charT>
{
 public:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

 protected:
  // Constructor for general numerics, gets punct from loc's numpunct<charT>.
  digit_writer_base_1
      (_RW_STD::ios_base&,const _RW_STD::locale&);

  // Constructor for money, passed punct is really a moneypunct<charT,Intl>.
  digit_writer_base_1  (_RW_STD::ios_base&,const punct_data<charT>&);

  // These could be moved to digit_handler_base_1<charT> ...
  charT get_decimal_point() const { return this->punct.dp_; }
  charT get_thousands_sep() const { return this->punct.ts_; }
  const char *get_grouping() const { return this->punct.gr_.c_str(); }
};

// --------------------------------------------------------------------
// Implementation class template -- digit_writer<charT,OutputIterator>.
// --------------------------------------------------------------------

// Facets that do numeric output use temporary objects of this type (on the
// stack) to convert numeric quantities into sequences of digits and other
// punctuation.

template <class charT,class OutputIterator>
class _RWSTDExportTemplate digit_writer :
    public digit_writer_base_1<charT>
{
 public:
  typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > string_type;

  // Constructor for general numerics.
  digit_writer (OutputIterator&,_RW_STD::ios_base&);

 protected:
  // Constructor for use by derived money_writer classes, passed punct_data is
  // really a moneypunct<charT,Intl> facet.
  digit_writer (OutputIterator&,_RW_STD::ios_base&,
      const punct_data<charT>&);

 public:
  void put_digits (charT fill);
  void put_keyword (const string_type&,charT fill);

 protected:
  OutputIterator &out;
};
#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/numbrw.cc>
#endif

#endif
#pragma option pop
#endif /* __NUMBRW_H */
