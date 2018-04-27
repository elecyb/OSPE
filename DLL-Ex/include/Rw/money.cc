#ifndef __MONEY_CC
#define __MONEY_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * money.cc - Definitions for the Standard Library money facets
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

// -------------------------------------------------
// Template moneypunct_data<charT> member templates.
// -------------------------------------------------

template <class charT>
moneypunct_data<charT>::moneypunct_data
    (moneypunct_init<charT> *init)
{
  if (!init) {
    this->dp_=charT('.');
    this->ts_=charT(',');
    fd_=0;
  } else {
    this->dp_=init->dp_;
    this->ts_=init->ts_;
    this->gr_=init->gr_;
    cs_=init->cs_;
    ps_=init->ps_;
    ns_=init->ns_;
    fd_=init->fd_;
    pf_=init->pf_;
    nf_=init->nf_;

    if (init->del_)
      delete[] (char*) init;
  }
}

template <class charT>
void moneypunct_data<charT>::__initfacetbase (const locale*) { }

template <class charT>
moneypunct_init<charT>*
_RWSTDExportTemplate fixup_moneypunct_init
    (moneypunct_init<char> *init,charT*)
{
  moneypunct_init<charT> *result = NULL;
#if !defined (_RWSTD_NO_NAMESPACE) && !defined (_RWSTD_NO_NEW_HEADER)
  using std::mbstate_t;
#endif

  if (init) {
    const _RW_STD::codecvt<charT,char,mbstate_t> &cvt =
        #ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
        _RW_STD::use_facet<_RW_STD::codecvt<charT,char,mbstate_t> >(_RW_STD::locale::classic());
        #else
        _RW_STD::use_facet(_RW_STD::locale::classic(),(_RW_STD::codecvt<charT,char,mbstate_t>*)0);
        #endif

    typedef _RW_STD::basic_string<charT,_RW_STD::char_traits<charT>,_RW_STD::allocator<charT> > s_type;
    s_type cs_=cvt.in(init->cs_);
    s_type ps_=cvt.in(init->ps_);
    s_type ns_=cvt.in(init->ns_);

    size_t extra_chars = _RW_STD::char_traits<char>::length(init->gr_);

    size_t extra_charTs = cs_.length()+ps_.length()+ns_.length()+3;

    result=(moneypunct_init<charT>*)
        new char[sizeof(*result)+extra_chars+extra_charTs*sizeof(charT)];

    result->del_=true;
    result->dp_=charT(init->dp_);
    result->ts_=charT(init->ts_);
    result->fd_=init->fd_;
    result->pf_=init->pf_;
    result->nf_=init->nf_;

    size_t n;
    charT *p=(charT*) (result+1);
    result->cs_=_RW_STD::char_traits<charT>::copy(p,cs_.c_str(),n=cs_.length());
    *(p+=n)++=0;
    result->ps_=_RW_STD::char_traits<charT>::copy(p,ps_.c_str(),n=ps_.length());
    *(p+=n)++=0;
    result->ns_=_RW_STD::char_traits<charT>::copy(p,ns_.c_str(),n=ns_.length());
    *(p+=n)++=0;

    result->gr_= _RW_STD::char_traits<char>::copy((char*)(p+n),init->gr_,
                     _RW_STD::char_traits<char>::length(init->gr_));
  }

  if (init->del_)
    delete[] (char*) init;

  return result;
}

template <class charT>
moneypunct_init<charT>*
moneypunct_data<charT>::get_init_by_name_
    (const char *name,bool intl)
{
  return fixup_moneypunct_init (__get_named_init(name,intl),(charT*)0);
}

// ------------------------------------------------------------
// Template class money_handler_base_1<charT> member templates.
// ------------------------------------------------------------

template <class charT>
const moneypunct_data<charT>&
money_handler_base_1<charT>::get_punct_data
    (const _RW_STD::locale &loc,bool intl)
{
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
  if (intl)
    return _RW_STD::use_facet<_RW_STD::moneypunct<charT,true> >(loc);
  else
    return _RW_STD::use_facet<_RW_STD::moneypunct<charT,false> >(loc);
#else
  if (intl) // casts required for some compilers
#if defined(__TURBOC__) && (__TURBOC__ > 0x540)
    return moneypunct_data<charT>( _RW_STD::use_facet(loc,(_RW_STD::moneypunct<charT,true>*)0));
#else
    return _RW_STD::use_facet(loc,(_RW_STD::moneypunct<charT,true>*)0);
#endif
  else
#if defined(__TURBOC__) && (__TURBOC__ > 0x540)
    return moneypunct_data<charT>(_RW_STD::use_facet(loc,(_RW_STD::moneypunct<charT,false>*)0));
#else
    return _RW_STD::use_facet(loc,(_RW_STD::moneypunct<charT,false>*)0);
#endif
#endif
}

// -----------------------------------------------------------
// Template class money_reader_base_1<charT> member templates.
// -----------------------------------------------------------

template <class charT>
money_reader_base_1<charT>::
money_reader_base_1 (digit_reader_base_1<charT> &r,
                     const moneypunct_data<charT> &mp) 
 : money_handler_base_1<charT>(mp), reader(r)
{ }

template <class charT>
void money_reader_base_1<charT>::get_money_string
    (string_type &result,const char *eod)
{
  int len=eod-reader.digits;
  if (reader.negative)
    len++;

  result.resize(0);
  result.reserve(len);

  if (reader.negative)
    result+=reader.dmap.punct_chars[digit_map_base::minus];

  const char *d=reader.digits;
  const char *end=eod-1;
  while (d<end && *d==0) d++;
  for ( ; d<=end; d++)
    result+=reader.dmap.digit_chars[*d];
}

// -------------------------------------------------------------------------
// Template class money_reader_base_2<charT,InputIterator> member templates.
// -------------------------------------------------------------------------

template <class charT,class InputIterator>
money_reader_base_2<charT,InputIterator>::
money_reader_base_2 (InputIterator &i,InputIterator &e,
                     _RW_STD::ios_base &b,const moneypunct_data<charT> &mp)
 :  digit_reader<charT,InputIterator>(i,e,b,mp),
    money_reader_base_1<charT>(this_as_digit_reader(),mp)
{
  this->radix=10;
  this->is_signed=false;
}

template <class charT,class InputIterator>
char* money_reader_base_2<charT,InputIterator>::
    get_money_digits (void)
{
  charT c;
  // Always parse input according to negative format.
  const _RW_STD::money_base::pattern &patt=this->get_neg_format();

  // If this ends up non-NULL, it points to trailing sign char(s) that are
  // required at the end of the pattern.
  const charT *sign=NULL;

  bool need_curr=(this->io.flags()&_RW_STD::ios_base::showbase)? true : false;
  bool got_curr=false;
  int fracs=this->get_frac_digits();

  char *eod=this->digits;
  const char *p=patt.field,*pend=p+sizeof patt.field-1;

  for ( ; !this->error && p<=pend; p++) {
    switch (*p) {
     case _RW_STD::money_base::space:
     case _RW_STD::money_base::none:
      while (!this->at_end() && this->ctyp.is(_RW_STD::ctype_base::space,*this->in))
        this->in++;
      break;

     case _RW_STD::money_base::symbol:
      if (!this->at_end()) {
        const charT *curr=this->get_curr_symbol().c_str();
        if ((c=*this->in)==*curr) {
          // We ate a character, so rest of symbol must be present.
          need_curr=true;
          do {
            this->in++;
            if (*++curr==charT('\0')) {
              got_curr=true;
              break;
            }
          } while (!this->at_end() && (c=*this->in)==*curr);
        }
      }
      if (need_curr && !got_curr)
        this->error|=this->bad_curr_symbol;
      break;

     case _RW_STD::money_base::sign:
      if (!this->at_end()) {
        sign=this->get_negative_sign().c_str();
        if ((c=*this->in)==*sign) {
          this->negative=true;
          sign++;
          this->in++;
        } else {
          sign=this->get_positive_sign().c_str();
          if (c==*sign) {
            sign++;
            this->in++;
          } else
            sign=NULL;
        }
      }
      break;

     case _RW_STD::money_base::value:
      eod=this->get_int_digits();
      if (!this->error && fracs && !this->at_end() &&
          *this->in==this->get_decimal_point())
      {
        this->in++;
        char *frac_start=eod;
        eod=this->get_digit_string(eod);
        if (!this->error) {
          fracs-=(eod-frac_start);
          if (fracs<0) {
            // Too many fractional digits in input.  We truncate.  The
            // alternative would be to return an error.
            eod+=fracs;
            fracs=0;
          }
        }
      }
      if (eod==this->digits)
        this->error|=this->no_digits;
      else if (!this->error && fracs>0) {
        // Add trailing zeros until the correct number of fractional digits
        // is reached.
        if (this->digits+sizeof this->digits-eod < fracs)
          this->error|=this->too_many_digits;
        else {
          do *eod++=0;
          while (--fracs);
        }
      }
      break;
    }
  }

  if (sign && !this->error)
    // We ate one charT of a sign earlier, rest of sign must be present at end.
    while (*sign)
      if (!this->at_end() && *this->in==*sign++)
        this->in++;
      else {
        this->error|=this->bad_sign;
        break;
      }

  this->frac_beg=this->exp_beg=eod;
  return eod;
}

// ------------------------------------------------------------
// Template money_reader<charT,InputIterator> member templates.
// ------------------------------------------------------------

template <class charT,class InputIterator>
money_reader<charT,InputIterator>::
money_reader (InputIterator &i,InputIterator &e,
    _RW_STD::ios_base &b,bool intl):
    money_reader_base_2<charT,InputIterator>
        (i,e,b,money_handler_base_1<charT>::
         get_punct_data(b.getloc(),intl))
{ }

// -----------------------------------------------------
// Template money_writer_base_1<charT> member templates.
// -----------------------------------------------------

template <class charT>
money_writer_base_1<charT>::money_writer_base_1
    (digit_writer_base_1<charT> &w,
     const moneypunct_data<charT> &mp)
 : money_handler_base_1<charT>(mp), writer(w)
{ }

template <class charT>
void money_writer_base_1<charT>::put_money (charT fill)
{
  bool negative;
  if (*writer.start=='-') {
    negative=true;
    writer.start++;
  } else {
    negative=false;
    if (*writer.start=='+' || *writer.start==' ')
      writer.start++;
  }

  charT wide_digits[sizeof writer.buffer];
  writer.ctyp.widen(writer.start,writer.end,wide_digits);
  put_money_sub(wide_digits,wide_digits+(writer.end-writer.start),
      negative,fill);
}

template <class charT>
void money_writer_base_1<charT>::put_money
    (const string_type& digits,charT fill)
{
  const charT *punct =
      digit_map<charT>::get_digit_map(writer.ctyp)
      .get_punct();

  const charT *start=digits.c_str();
  bool negative;
  if (*start==punct[digit_map_base::minus]) {
    negative=true;
    start++;
  } else
    negative=false;

  const charT *end=writer.ctyp.scan_not(_RW_STD::ctype_base::digit,start,
      digits.c_str()+digits.length());

  put_money_sub(start,end,negative,fill);
}

// --------------------------------------------------------------------
// Template money_writer_base_2<charT,OutputIterator> member templates.
// --------------------------------------------------------------------

template <class charT,class OutputIterator>
money_writer_base_2<charT,OutputIterator>::money_writer_base_2
    (OutputIterator &os,_RW_STD::ios_base &io,
     const moneypunct_data<charT> &mp)
 : digit_writer<charT,OutputIterator> (os,io,mp),
   money_writer_base_1<charT> (this_as_digit_writer(),mp)
{ }

template <class charT, class OutputIterator>
void money_writer_base_2<charT,OutputIterator>::put_money_sub
    (const charT *start,const charT *end,bool negative,charT fill)
{
  const _RW_STD::money_base::pattern *patt;
  const string_type *sign;
  if (negative) {
    patt=&this->get_neg_format();
    sign=&this->get_negative_sign();
  } else {
    patt=&this->get_pos_format();
    sign=&this->get_positive_sign();
  }

  int frac_digits=this->get_frac_digits();
  int int_digits=end-start-frac_digits;
  int unGrouped,zero_pad;

  if (int_digits<0) {
    zero_pad=-int_digits;
    int_digits=0;
  } else
    zero_pad=0;

  charT sep;
  if (int_digits>0) {
    unGrouped=calc_groups(int_digits,this->get_grouping());
    if (this->num_groups)
      sep=this->get_thousands_sep();
  } else
    unGrouped=0;

  const char *p,*pend=patt->field+sizeof patt->field;
  int leftFill=0,internalFill=0,rightFill=0;

  if (this->width) {
    int n=0;
    for (p=patt->field; p<pend; p++) {
      switch (*p) {
       case _RW_STD::money_base::space:
        n++;
        break;
       case _RW_STD::money_base::symbol:
        if (this->flags& _RW_STD::ios_base::showbase)
          n+=this->get_curr_symbol().length();
        break;
       case _RW_STD::money_base::sign:
        n+=sign->length();
        break;
       case _RW_STD::money_base::value:
        n+=int_digits+this->num_groups;
        if (frac_digits)
          n+=frac_digits+1;
        break;
      }
    }

    if ((n-=this->width)>0) {
      switch (this->adjust) {
       case digit_writer_base::left:
        rightFill=n;
        break;
       case digit_writer_base::internal:
        internalFill=n;
        break;
       default:
        leftFill=n;
      }
    }

    this->width=0;
  }

  if (leftFill)
    do *this->out++=fill;
    while (--leftFill);

  const charT *schar=sign->c_str();
  for (p=patt->field; p<pend; p++)
    switch (*p) {
     case _RW_STD::money_base::symbol:
      if (this->flags& _RW_STD::ios_base::showbase)
        put_keyword(this->get_curr_symbol(),fill);
      break;
     case _RW_STD::money_base::sign:
      if (*schar)
        *this->out++=*schar++;
      break;
     case _RW_STD::money_base::value:
      while (unGrouped--)
        *this->out++=*start++;
      while (this->num_groups--) {
        *this->out++=sep;
        while ((*this->group)--)
          *this->out++=*start++;
        this->group++;
      }
      if (frac_digits) {
        *this->out++=this->get_decimal_point();
        while (zero_pad--) {
          frac_digits--;
          *this->out++=this->ctyp.widen('0');
        }
        while (frac_digits-->0)
          *this->out++=*start++;
      }
      break;
     case _RW_STD::money_base::space:
      if (!internalFill) {
        *this->out++=this->ctyp.widen(' ');
        break;
      }
      // Fall through ...
     case _RW_STD::money_base::none:
      if (internalFill)
        do *this->out++=fill;
        while (--internalFill);
      break;
    }

  while (*schar)
    *this->out++=*schar++;

  if (rightFill+=internalFill) {
    do *this->out++=fill;
    while (--rightFill);
  }
}

// -------------------------------------------------------------
// Template money_writer<charT,OutputIterator> member templates.
// -------------------------------------------------------------

template <class charT,class OutputIterator>
money_writer<charT,OutputIterator>::money_writer 
(OutputIterator &os,_RW_STD::ios_base &io,bool intl)
 : money_writer_base_2<charT,OutputIterator>
        (os,io,money_handler_base_1<charT>::
         get_punct_data(io.getloc(),intl))
{ }
#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// ------------------------------------------------------
// Facet money_get<charT,InputIterator> member templates.
// ------------------------------------------------------

template <class charT, class InputIterator>
locale::id money_get<charT,InputIterator>::id;

template <class charT, class InputIterator>
money_get<charT,InputIterator>::~money_get() { }

// Warning -- these functions do not input actual monetary value; they just
// input numbers that represent monetary value.

template <class charT, class InputIterator>
InputIterator money_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, bool intl, ios_base& io,
     ios_base::iostate& err, long double& units) const
{
  __RWSTD::money_reader<charT,InputIterator> reader(in,end,io,intl);
  long double v=reader.to_long_double(reader.get_money_digits());
  err=ios_base::goodbit;

  if (reader.error)
    err=ios_base::failbit;
  else
    units=v;

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

template <class charT, class InputIterator>
InputIterator money_get<charT,InputIterator>::do_get
    (InputIterator in, InputIterator end, bool intl, ios_base &io,
     ios_base::iostate &err, string_type &digit_string) const
{
  __RWSTD::money_reader<charT,InputIterator> reader(in,end,io,intl);
  const char *eod=reader.get_money_digits();
  err=ios_base::goodbit;

  if (reader.error)
    err=ios_base::failbit;
  else
    reader.get_money_string(digit_string,eod);

  if (reader.reached_end)
    err|=ios_base::eofbit;

  return in;
}

// -------------------------------------------------------
// Facet money_put<charT,OutputIterator> member templates.
// -------------------------------------------------------

template <class charT, class OutputIterator>
locale::id money_put<charT,OutputIterator>::id;

template <class charT, class OutputIterator>
money_put<charT,OutputIterator>::~money_put() { }

template <class charT, class OutputIterator>
OutputIterator money_put<charT,OutputIterator>::do_put
    (OutputIterator out, bool intl, ios_base& io, charT fill,
#ifndef _RWSTD_NO_LONG_DOUBLE
     long double quant) const
#else
     double quant) const
#endif

{
  __RWSTD::money_writer<charT,OutputIterator> writer(out,io,intl);
  writer.digitize(quant);
  writer.put_money(fill);
  return out;
}

template <class charT, class OutputIterator>
OutputIterator money_put<charT,OutputIterator>::do_put
    (OutputIterator out, bool intl, ios_base& io, charT fill,
     const string_type& digits) const
{
  __RWSTD::money_writer<charT,OutputIterator> writer(out,io,intl);
  writer.put_money(digits,fill);
  return out;
}

// ----------------------------------------------
// Facet moneypunct<charT,Intl> member templates.
// ----------------------------------------------

template <class charT, bool Intl>
locale::id moneypunct<charT,Intl>::id;

#ifndef _RWSTD_NO_STI_SIMPLE
template <class charT, bool Intl>
const bool moneypunct<charT,Intl>::intl;
#endif

template <class charT, bool Intl>
moneypunct<charT,Intl>::~moneypunct () { }

template <class charT, bool Intl>
charT moneypunct<charT,Intl>::do_decimal_point () const
     { return this->dp_; }

template <class charT, bool Intl>
charT moneypunct<charT,Intl>::do_thousands_sep () const
     { return this->ts_; }

template <class charT, bool Intl>
string moneypunct<charT,Intl>::do_grouping () const
     { return this->gr_; }

template <class charT, bool Intl>
_TYPENAME moneypunct<charT,Intl>::string_type
moneypunct<charT,Intl>::do_curr_symbol () const
     { return this->cs_; }

template <class charT, bool Intl>
_TYPENAME moneypunct<charT,Intl>::string_type
moneypunct<charT,Intl>::do_positive_sign () const
     { return this->ps_; }

template <class charT, bool Intl>
_TYPENAME moneypunct<charT,Intl>::string_type
moneypunct<charT,Intl>::do_negative_sign () const
     { return this->ns_; }

template <class charT, bool Intl>
int moneypunct<charT,Intl>::do_frac_digits () const
     { return this->fd_; }

template <class charT, bool Intl>
money_base::pattern
moneypunct<charT,Intl>::do_pos_format () const
     { return this->pf_; }

template <class charT, bool Intl>
money_base::pattern
moneypunct<charT,Intl>::do_neg_format () const
     { return this->nf_; }

template <class charT, bool Intl>
void moneypunct<charT,Intl>::__initfacet (const locale* loc) {
  this->dp_=do_decimal_point();
  this->ts_=do_thousands_sep();
  this->gr_=do_grouping();
  this->cs_=do_curr_symbol();
  this->ps_=do_positive_sign();
  this->ns_=do_negative_sign();
  this->fd_=do_frac_digits();
  this->pf_=do_pos_format();
  this->nf_=do_neg_format();
  this->__initfacetbase(loc);
}

// --------------------------------------------------------------------------
// Money punctuation by-name member templates: moneypunct_byname<charT,Intl>
// --------------------------------------------------------------------------

template <class charT, bool Intl>
moneypunct_byname<charT,Intl>::moneypunct_byname (const char *n,size_t refs):
    moneypunct<charT,Intl>(refs,get_init_by_name_(n,moneypunct<charT,Intl>::intl))
{ }

template <class charT, bool Intl>
moneypunct_byname<charT,Intl>::~moneypunct_byname()
{ }
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __MONEY_CC */
