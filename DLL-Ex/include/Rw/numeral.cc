#ifndef __NUMERAL_CC
#define __NUMERAL_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * numeral.cc - Definitions for the Standard Library numeric facets
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

#ifndef __STD_RW_LOCNUMRW__
#include <rw/numbrw>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

// -----------------------------------------------
// Template numpunct_data<charT> member functions.
// -----------------------------------------------

template <class charT>
void numpunct_data<charT>::__initfacetbase (const locale*) {
  tf_defs_[0].s=tn_.c_str();
  tf_defs_[0].v=1;
  tf_defs_[1].s=fn_.c_str();
  tf_defs_[1].v=0;

  tf_map_.num_defs_=2 ;
  tf_map_.defs_=tf_defs_;
}

template <class charT>
numpunct_init<charT>*
_RWSTDExportTemplate fixup_numpunct_init
    (numpunct_init<char> *init,charT*)
{
  if (init->del_)
    delete[] (char*) init;
  return NULL;
}

template <class charT>
numpunct_init<charT>*
numpunct_data<charT>::get_init_by_name_
    (const char *name)
{
  return fixup_numpunct_init(get_named_init_(name),(charT*)0);
}
#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// ----------------------------------------------------
// Facet num_get<charT,InputIterator> member templates.
// ----------------------------------------------------
template <class charT, class InputIterator>
locale::id num_get<charT, InputIterator>::id;

template <class charT, class InputIterator>
num_get<charT,InputIterator>::~num_get() { }

#ifndef _RWSTD_NO_BOOL

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, bool& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  long v=reader.to_ulong(reader.get_int_digits());
  err=ios_base::goodbit; // aka 0

  if (!reader.error)
    if (v==0)
      value=false;
    else if (v==1 && !reader.negative)
      value=true;
    else
      err=ios_base::failbit;
  else if (reader.advanced)
    err=ios_base::failbit;
  else {
    const numpunct<charT>& nump =
        _RWSTD_STATIC_CAST(const numpunct<charT>&,reader.punct);
    int k=reader.get_keyword(reader.get_tf_map(nump));
    if (k<0)
      err=ios_base::failbit;
    else
      value=k;
  }

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

#endif // _RWSTD_NO_BOOL

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, void*& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  void *v=reader.to_pointer(reader.get_pointer_digits());
  err=ios_base::goodbit;

  if (reader.error)
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, long& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  long v=reader.to_ulong(reader.get_int_digits());
  err=ios_base::goodbit;

  if (!reader.error)
    if (reader.negative) {
      if ((v=-v)>0)
        reader.error=reader.overflow;
    } else
      if (v<0 && reader.radix==10)
        reader.error=reader.overflow;

  if (reader.error)
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;
    
  return in;
}

#ifdef _RWSTD_LONG_LONG

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, _RWSTD_LONG_LONG& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  _RWSTD_LONG_LONG v=reader.to_ulong_ulong(reader.get_int_digits());
  err=ios_base::goodbit;

  if (!reader.error)
    if (reader.negative) {
      if ((v=-v)>0)
        reader.error=reader.overflow;
    } else
      if (v<0 && reader.radix==10)
        reader.error=reader.overflow;

  if (reader.error)
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;
    
  return in;
}

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, unsigned _RWSTD_LONG_LONG& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  unsigned _RWSTD_LONG_LONG v=reader.to_ulong_ulong(reader.get_int_digits());
  err=ios_base::goodbit;

  if (reader.error || (reader.negative && v!=0))
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

#endif // _RWSTD_LONG_LONG

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, unsigned short& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  unsigned long v=reader.to_ulong(reader.get_int_digits());
  err=ios_base::goodbit;

  if (reader.error
      || v > (unsigned long) numeric_limits<unsigned short>::max()
      || (reader.negative && v!=0))
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, unsigned int& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  unsigned long v=reader.to_ulong(reader.get_int_digits());
  err=ios_base::goodbit;

  if (reader.error
      || v > (unsigned long) numeric_limits<unsigned int>::max()
      || (reader.negative && v!=0))
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, unsigned long& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  unsigned long v=reader.to_ulong(reader.get_int_digits());
  err=ios_base::goodbit;

  if (reader.error || (reader.negative && v!=0))
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, float& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  float v=reader.to_float(reader.get_float_digits());
  err=ios_base::goodbit;

  if (reader.error)
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, double& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  double v=reader.to_double(reader.get_float_digits());
  err=ios_base::goodbit;

  if (reader.error)
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator>
InputIterator num_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, ios_base& io,
     ios_base::iostate& err, long double& value) const
{
  __RWSTD::digit_reader<charT,InputIterator> reader(in,end,io);
  long double v=reader.to_long_double(reader.get_float_digits());
  err=ios_base::goodbit;

  if (reader.error)
    err=ios_base::failbit;
  else
    value=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

// -----------------------------------------------------
// Facet num_put<charT,OutputIterator> member templates.
// -----------------------------------------------------

template <class charT, class OutputIterator>
locale::id num_put<charT, OutputIterator>::id;

template <class charT, class OutputIterator>
num_put<charT,OutputIterator>::~num_put() { }

#ifndef _RWSTD_NO_BOOL

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, bool value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  if (io.flags() & ios_base::boolalpha) {
    const numpunct<charT>& nump =
        _RWSTD_STATIC_CAST(const numpunct<charT>&,writer.punct);
    writer.put_keyword(writer.get_tf_string(nump,value),fill);
  } else {
    writer.digitize((unsigned long) (value? 1 : 0));
    writer.put_digits(fill);
  }
  return out;
}

#endif // _RWSTD_NO_BOOL

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, const void* value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(value);
  writer.put_digits(fill);
  return out;
}

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, long value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(value);
  writer.put_digits(fill);
  return out;
}

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, unsigned long value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(value);
  writer.put_digits(fill);
  return out;
}

#ifdef _RWSTD_LONG_LONG

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, 
     _RWSTD_LONG_LONG val) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(val);
  writer.put_digits(fill);
  return out;
}

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, 
     unsigned _RWSTD_LONG_LONG val) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(val);
  writer.put_digits(fill);
  return out;
}

#endif // _RWSTD_LONG_LONG

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, double value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> digits(out,io);
  digits.digitize(value);
  digits.put_digits(fill);
  return out;
}

#ifndef _RWSTD_NO_LONG_DOUBLE
template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, long double value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> digits(out,io);
  digits.digitize(value);
  digits.put_digits(fill);
  return out;
}
#endif // _RWSTD_NO_LONG_DOUBLE

#ifndef _RWSTD_STRICT_ANSI
// Rogue wave extensions
template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, short value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(value);
  writer.put_digits(fill);
  return out;
}

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, unsigned short value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(value);
  writer.put_digits(fill);
  return out;
}

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, int value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(value);
  writer.put_digits(fill);
  return out;
}

template <class charT, class OutputIterator>
OutputIterator num_put<charT,OutputIterator>::do_put
    (OutputIterator out, ios_base& io, charT fill, unsigned int value) const
{
  __RWSTD::digit_writer<charT,OutputIterator> writer(out,io);
  writer.digitize(value);
  writer.put_digits(fill);
  return out;
}
#endif // _RWSTD_STRICT_ANSI

// ---------------------------------------
// Facet numpunct<charT> member templates.
// ---------------------------------------

template <class charT>
locale::id numpunct<charT>::id;

template <class charT>
numpunct<charT>::~numpunct() { }

template <class charT>
charT numpunct<charT>::do_decimal_point () const { return this->dp_; }

template <class charT>
charT numpunct<charT>::do_thousands_sep () const { return this->ts_; }

template <class charT>
string numpunct<charT>::do_grouping () const { return this->gr_; }

template <class charT>
_TYPENAME numpunct<charT>::string_type
numpunct<charT>::do_falsename () const { return this->fn_; }

template <class charT>
_TYPENAME numpunct<charT>::string_type
numpunct<charT>::do_truename () const { return this->tn_; }

template <class charT>
void numpunct<charT>::__initfacet (const locale* loc) {
  this->dp_=do_decimal_point();
  this->ts_=do_thousands_sep();
  this->gr_=do_grouping();
  this->fn_=do_falsename();
  this->tn_=do_truename();
  this->__initfacetbase(loc);
}

// ----------------------------------------------------------------------
// Numeric punctuation by-name member templates: numpunct_byname<charT>
// ----------------------------------------------------------------------

template <class charT>
numpunct_byname<charT>::numpunct_byname (const char *n, size_t refs):
#if defined (_MSC_VER) && !defined (__BORLANDC__)
    numpunct<charT>(refs,get_init_by_name_(n))
#else
#  if !defined (_RWSTD_NO_NAMESPACE)
    numpunct<charT>(refs,__RWSTD::numpunct_data<charT>::get_init_by_name_(n))
#  else
    numpunct<charT>(refs,numpunct_data<charT>::get_init_by_name_(n))
#  endif
#endif // _MSC_VER
{ }

template <class charT>
numpunct_byname<charT>::~numpunct_byname()
{ }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __NUMERAL_CC */
