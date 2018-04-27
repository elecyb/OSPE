#ifndef __NUMBRW_CC
#define __NUMBRW_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/****************************************************************************
 *
 * rw/numbrw.cc - Internal classes for numeric formatting and parsing.
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

#ifndef __STD_RW_NUMBRW_CC__
#define __STD_RW_NUMBRW_CC__

#ifndef _RWSTD_NO_NEW_HEADER
#include <clocale>
#else
#include <locale.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#if !defined (_RWSTD_NO_NEW_HEADER) && !defined (_RWSTD_NO_NAMESPACE)
  using std::tm;
  using std::setlocale;
  using std::strftime;
  using std::mktime;
  using std::strlen;
#endif

// ------------------------------------------------
// Template timepunct_data<charT> member templates.
// ------------------------------------------------

template <class charT>
timepunct_data<charT>::timepunct_data
    (const timepunct_loc<charT> &init)
{
  int i;
  for (i=0; i<7; i++) {
    dn_[i][0]=init.get_day(i,false);
    dn_[i][1]=init.get_day(i,true);
  }
  for (i=0; i<12; i++) {
    mn_[i][0]=init.get_month(i,false);
    mn_[i][1]=init.get_month(i,true);
  }
  ampm_[0]=init.get_ampm(false);
  ampm_[1]=init.get_ampm(true);
  bad_=init.get_bad();
  for (i=0; i<100; i++)
    ord_[i]=init.get_ord(i);
  for (i=0; i<sizeof pat_/sizeof pat_[0]; i++)
    pat_[i]=init.get_pattern(i);
}

// struct for storing formatting information in map
struct __fmt {
  __fmt () {}
  __fmt (int p, int l, char f) : position(p), length(l), fmtChar(f) {}
  int position;
  int length;
  char fmtChar;
  bool operator < (const __fmt& f) {
    return position < f.position;
  }
};

// initialize data member pat_ which holds formatting strings
template <class charT>
void timepunct_data<charT>::__initpat (const locale* loc)
{
  const _RW_STD::string timeFmtChars("YyjSMIHmBbAapdZUWw");
  tm tmb;
  char buf[256];
  __fmt fmtArray[20];

  // set up tmp
  tmb.tm_sec = 56;
  tmb.tm_min = 54;
  tmb.tm_hour = 22;
  tmb.tm_mday = 30;
  tmb.tm_mon = 10;
  tmb.tm_year = 90;
  tmb.tm_wday = 5;
  tmb.tm_yday = -1;
  tmb.tm_isdst = -1;
  (void) mktime(&tmb);
  const _RW_STD::ctype<charT>& ct =
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    _RW_STD::use_facet<_RW_STD::ctype<charT> >(*loc);
#else
    _RW_STD::use_facet(*loc, (_RW_STD::ctype<charT>*)0);
#endif

  // Set up passed in locale
  _RW_STD::string oldlocale = setlocale(LC_ALL, 0);
#ifdef __BORLANDC__
  _RW_STD::string::size_type posd = loc->name().find('=')+1;
  setlocale(LC_ALL, _RW_STD::string(loc->name(),posd,loc->name().find('\n')-posd).c_str());
#else
    setlocale(LC_ALL, loc->name().c_str());
#endif // __BORLANDC__

  // for each composite format character create format string
  const char do_as_pattern[] = "xXcDrT";
  for (unsigned int j = 0; j < strlen(do_as_pattern); j++) {
    // create format string to parse
    _RW_STD::string timeFmtStr("% ");
    timeFmtStr[1] = do_as_pattern[j];
    strftime(buf, sizeof(buf), timeFmtStr.c_str(), &tmb);
    _RW_STD::string timeFmt(buf);

    // starting at the beginning of the formatted string find each component
    // and save in an ordered structure
    int pos;
    int fmtArrayIndex = 0;
    for (unsigned int i=0; i < timeFmtChars.length(); i++) {
      _RW_STD::string fmtChar("% ");
      fmtChar[1] = timeFmtChars[i];
      strftime(buf, sizeof(buf), fmtChar.data(), &tmb);
      if ((pos = timeFmt.find(buf)) != -1) {
        if (strlen(buf) > 0) {
          fmtArray[fmtArrayIndex++] = __fmt(pos, strlen(buf), timeFmtChars[i]);
          timeFmt.replace(pos, strlen(buf), strlen(buf), ' ');
        }
      }
    }

    // sort format items
    for (int top = fmtArrayIndex; top > 0; --top) {
      int large = 0;
      for (int i = 0; i < top; ++i) {
	if (fmtArray[i] < fmtArray[large])
	  large = i;
      }
      __fmt temp = fmtArray[large];
      fmtArray[large] = fmtArray[top-1];
      fmtArray[top-1] = temp;
    }

    // put format characters into formatting string
    for (__fmt *p = fmtArray; p < fmtArray + fmtArrayIndex; ++p) {
      timeFmt.replace((*p).position, (*p).length,
		      (_RW_STD::string("%").append(1,(*p).fmtChar)));
    }

    // convert to string_type and insert in array pat_
    string_type cnvt;
    for (unsigned int k = 0; k < timeFmt.length(); k++)
      cnvt = _RW_STD::operator + (cnvt, ct.widen(timeFmt[k]));
    pat_[j] = cnvt;

  }

  setlocale(LC_ALL, oldlocale.c_str());
}

template <class charT>
void timepunct_data<charT>::__initfacet (const locale* loc) {
  int i;
  for (i=0; i<7; i++) {
    dn_defs_[i][0].s=dn_[i][0].c_str();
    dn_defs_[i][0].v=i;
    dn_defs_[i][1].s=dn_[i][1].c_str();
    dn_defs_[i][1].v=i;
  }

  for (i=0; i<12; i++) {
    mn_defs_[i][0].s=mn_[i][0].c_str();
    mn_defs_[i][0].v=i;
    mn_defs_[i][1].s=mn_[i][1].c_str();
    mn_defs_[i][1].v=i;
  }

  ampm_defs_[0].s=ampm_[0].c_str();
  ampm_defs_[0].v= 0;
  ampm_defs_[1].s=ampm_[1].c_str();
  ampm_defs_[1].v= 1;

  dn_map_.num_defs_=7*2;
  dn_map_.defs_=&(dn_defs_[0][0]);
  mn_map_.num_defs_=12*2;
  mn_map_.defs_=&(mn_defs_[0][0]);
  ampm_map_.num_defs_=2;
  ampm_map_.defs_=&(ampm_defs_[0]);
  __initpat(loc);
}
// -----------------------------------------------
// Facet rwstd::timepunct<charT> member templates.
// -----------------------------------------------

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd { // Leave std, enter __rwstd
#endif

template <class charT>
_RW_STD::locale::id timepunct<charT>::id;

template <class charT>
void timepunct<charT>::__initfacet (const locale* loc) {
  int n;
  for (n=0; n<7; n++) {
    this->dn_[n][false]=do_dayname(n,false);
    this->dn_[n][true]=do_dayname(n,true);
  }
  for (n=0; n<12; n++) {
    this->mn_[n][false]=do_monthname(n,false);
    this->mn_[n][true]=do_monthname(n,true);
  }
  for (n=0; n<100; n++)
    this->ord_[n]=do_ordinal(n);

  timepunct_impl<charT>::__initfacet(loc);
}

template <class charT>
_TYPENAME timepunct<charT>::string_type
timepunct<charT>::do_dayname (int day, bool abbr) const {
  return this->dn_[day][abbr];
}

template <class charT>
_TYPENAME timepunct<charT>::string_type
timepunct<charT>::do_monthname (int mon, bool abbr) const {
  return this->mn_[mon][abbr];
}

template <class charT>
_TYPENAME timepunct<charT>::string_type
timepunct<charT>::do_ordinal (int number) const {
  return (number<0 || number>99) ? this->bad_ : this->ord_[number];
}

// -----------------------------------------------
// Template digit_handler_base_1 member templates.
// -----------------------------------------------

template <class charT>
digit_handler_base_1<charT>::
digit_handler_base_1 (const _RW_STD::locale &loc):
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    ctyp(_RW_STD::use_facet<_RW_STD::ctype<charT> >(loc)),
    dmap(digit_map<charT>::get_digit_map(ctyp)),
    punct(_RW_STD::use_facet<_RW_STD::numpunct<charT> >(loc))
#else
    ctyp(_RW_STD::use_facet(loc,(_RW_STD::ctype<charT>*)0)),
    dmap(digit_map<charT>::get_digit_map(ctyp)),
    punct(_RW_STD::use_facet(loc,(_RW_STD::numpunct<charT>*)0))
#endif
{ }

template <class charT>
digit_handler_base_1<charT>::
digit_handler_base_1
    (const _RW_STD::locale &loc, const punct_data<charT> &pun):
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    ctyp(_RW_STD::use_facet<_RW_STD::ctype<charT> >(loc)),
    dmap(digit_map<charT>::get_digit_map(ctyp)),
#else
    ctyp(_RW_STD::use_facet(loc,(_RW_STD::ctype<charT>*)0)),
    dmap(digit_map<charT>::get_digit_map(ctyp)),
#endif
    punct(pun)
{ }

// ----------------------------------------------
// Template digit_reader_base_1 member templates.
// ----------------------------------------------

template <class charT>
digit_reader_base_1<charT>::
digit_reader_base_1 (const _RW_STD::locale &loc):
    digit_handler_base_1<charT>(loc)
{ }

template <class charT>
digit_reader_base_1<charT>::
digit_reader_base_1 (const _RW_STD::locale &loc,
    const punct_data<charT> &mp):
    digit_handler_base_1<charT>(loc,mp)
{ }

// ---------------------------------------
// Template digit_reader member templates.
// ---------------------------------------

template <class charT,class InputIterator>
digit_reader<charT,InputIterator>::
digit_reader(InputIterator& i,InputIterator& e,_RW_STD::ios_base &b):
    digit_reader_base_1<charT>(b.getloc()),
    io(b), in(i), end(e)
{ }

template <class charT,class InputIterator>
digit_reader<charT,InputIterator>::
digit_reader(InputIterator& i,InputIterator& e,_RW_STD::ios_base &b,
    const punct_data<charT> &mp):
    digit_reader_base_1<charT>(b.getloc(),mp),
    io(b), in(i), end(e)
{ }

template <class charT,class InputIterator>
char* digit_reader<charT,InputIterator>::
    get_digit_string (char *dpos)
{
  char *eod=dpos;
  int i;

  while (!at_end() && (i=this->dmap.eval(*in))>=0 && i<this->radix) {
    if (eod==this->digits+sizeof this->digits)
      this->error|=this->too_many_digits;
    else
      *eod++=(char) i;
    ++in;
  }

  return eod;
}

template <class charT,class InputIterator>
char* digit_reader<charT,InputIterator>::
    get_int_digits (void)
{
  charT c;
  char *eod=this->digits;
  const charT* ctype_punct=this->dmap.get_punct();

  if (!at_end() && this->is_signed)
    // If a sign is present, set negative if it's a minus sign.
    do {
      if ((c=*in)==ctype_punct[this->minus])
        this->negative=true;
      else if (c!=ctype_punct[this->plus])
        break;
      // Eat white space after the sign.  Standard seems to mandate this
      // regardless of whether ios_base::skipws is set.
      do
        ++in;
      while (!at_end() && this->ctyp.is(_RW_STD::ctype_base::space,*in));
      this->advanced=true;
    } while (0);

  if (!this->radix) {
    bool noradix = false;
    switch (io.flags() & _RW_STD::ios_base::basefield) {
     case _RW_STD::ios_base::dec:
      this->radix=10;
      break;
     case _RW_STD::ios_base::hex:
      this->radix=16;
      break;
     case _RW_STD::ios_base::oct:
      this->radix=8;
      break;
     default:
      noradix = true;
    }
    if (noradix || (io.flags() & _RW_STD::ios_base::showbase))
    {
      // No radix was forced by the ios_base flags, so poke around for a radix
      // specifier on the front of the input value.
      if (noradix)
        this->radix=10;
      if (!at_end() && *in==ctype_punct[this->zero]) {
        this->radix=8;
        ++in;
        *eod++=0;
        this->advanced=true;
        if (!at_end() &&
            ((c=*in)==ctype_punct[this->x] || c==ctype_punct[this->X]))
        {
          this->radix=16;
          ++in;
          eod--; // Leading 0 was not a digit after all.
        }
      }
    }
  }

  grouping=this->get_grouping();
  if (!*grouping)
    eod=get_digit_string(eod);
  else {
    gpos=groups;
    thousands_sep=this->get_thousands_sep();
    eod=get_digit_groups(eod);
    if (!this->error && --gpos>groups) {
      // Digit grouping is optional, but if present it must be right.
      const char *gdef=grouping;
      do {
        if (*gdef!=*gpos && *gdef!=CHAR_MAX)
          break;
        else
          if (gdef[1])
            gdef++;
      } while (--gpos>groups);

      if (gpos>groups || *gpos>*gdef)
        this->error|=this->bad_grouping;
    }
  }

  if (eod>this->digits)
    this->advanced=true;
  return eod;
}

template <class charT,class InputIterator>
char* digit_reader<charT,InputIterator>::
    get_float_digits (void)
{
  charT c;
  this->radix=10;
  char *eod=get_int_digits();

  const charT *ctyp_punct=this->dmap.get_punct();

  this->frac_beg=eod;
  if (!this->error && !at_end() && *in==this->get_decimal_point()) {
    in++;
    eod=get_digit_string(eod);
  }

  if (eod==this->digits)
    this->error|=this->no_digits;

  this->exp_beg=eod;
  this->exp_negative=false;
  if (!this->error && !at_end() &&
      ((c=*in)==ctyp_punct[this->e] || c==ctyp_punct[this->E]))
  {
    in++;
    if (at_end())
      this->error|=this->bad_exponent;
    else {
      if ((c=*in)==ctyp_punct[this->plus])
        in++;
      else if (c==ctyp_punct[this->minus]) {
        this->exp_negative=true;
        in++;
      }

      int save_radix=this->radix;
      this->radix=10;
      eod=get_digit_string(eod);
      this->radix=save_radix;
      if (eod==this->exp_beg)
        this->error|=this->bad_exponent;
    }
  }

  return eod;
}

template <class charT,class InputIterator>
char *digit_reader<charT,InputIterator>::
    get_pointer_digits (void)
{
  this->radix=16;
  char *eod=get_int_digits();
  return eod;
}

template <class charT,class InputIterator>
char* digit_reader<charT,InputIterator>::
    get_digit_groups (char *dpos)
{
  char *eod=get_digit_string(dpos);

  if (gpos==groups+sizeof groups)
    this->error|=this->too_many_groups;
  else {
    int i=eod-dpos;
    if (i >= CHAR_MAX)
      this->error|=this->group_too_long;
    else {
      *gpos++=i;
      if (i!=0 && !at_end() && *in==thousands_sep) {
        ++in;
        eod=get_digit_groups(eod);
      }
    }
  }

  return eod;
}

template <class charT,class InputIterator>
int digit_reader<charT,InputIterator>::
    get_keyword (const keyword_map<charT> &mapit)
{
  const keyword_def<charT> *canp=mapit.defs_;
  const keyword_def<charT> *endp=mapit.defs_+mapit.num_defs_;
  keyword_def<charT> cans[40],*ansp=cans;

  charT c;
  const charT *p;
  int result;

  while (1) {
    if (at_end()) {
      for ( ; canp<endp; canp++)
        if (!*canp->s)
          return canp->v;
      return -1;
    }
    c=*in;
    result=-1;
    for ( ; canp<endp; canp++) {
      p=canp->s;
      if (c==*p) {
        ansp->s=++p;
        ansp->v=canp->v;
        ansp++;
      } else if (*p==0)
        result=ansp->v; // abbreviation
    }

    if (ansp==cans)
      return result;
    in++;
    if (ansp==cans+1) {
      for (p=cans[0].s; *p; p++) {
        if (at_end() || *in!=*p)
          return -1;
        in++;
      }
      return cans[0].v;
    }

    endp=ansp;
    ansp=cans;
    canp=cans;
  }
}

// ----------------------------------------------
// Template digit_writer_base_1 member templates.
// ----------------------------------------------

template <class charT>
digit_writer_base_1<charT>::
digit_writer_base_1(_RW_STD::ios_base &b,const _RW_STD::locale &loc) 
 : digit_writer_base(b), digit_handler_base_1<charT>(loc)
{ }

template <class charT>
digit_writer_base_1<charT>::
digit_writer_base_1(_RW_STD::ios_base &b,const punct_data<charT> &mp)
 : digit_writer_base(b),digit_handler_base_1<charT>(b.getloc(),mp)
{
  flags&=~(_RW_STD::ios_base::floatfield | _RW_STD::ios_base::showpos);
  flags|=_RW_STD::ios_base::fixed;
  radix=10;
  precision=0;
}

// ---------------------------------------
// Template digit_writer member templates.
// ---------------------------------------

template <class charT,class OutputIterator>
digit_writer<charT,OutputIterator>::
digit_writer (OutputIterator &o, _RW_STD::ios_base &b)
 : digit_writer_base_1<charT>(b,b.getloc()), out(o) 
{ }

template <class charT,class OutputIterator>
digit_writer<charT,OutputIterator>::
digit_writer (OutputIterator &o, _RW_STD::ios_base &b,
    const punct_data<charT> &mp)
 : digit_writer_base_1<charT>(b,mp), out(o) 
{ }

template <class charT, class OutputIterator>
void digit_writer<charT,OutputIterator>::put_digits (charT fill)
{
  char *p=this->start;
  bool has_sign=false,has_point=false;
  if (p<this->end && (*p==' ' || *p=='-' || *p=='+'))
    has_sign=true;

  // Locate the end of the integral digits.
  char *dec;
  if (!this->fractional)
    dec=this->end;
  else {
    dec=this->start;
    if (has_sign) dec++;
    for ( ; dec<this->end; dec++)
      if (*dec<'0' || *dec>'9') {
        if (*dec!='e' && *dec!='E')
          has_point=true;
        break;
      }
  }

  // Calculate the number and pattern of separators needed if any.
  charT separator;
  int unGrouped=dec-this->start;
  if (has_sign)
    unGrouped--;
  if (this->radix==10 && this->separable) {
    unGrouped=calc_groups(unGrouped,this->get_grouping());
    if (this->num_groups)
      separator=this->get_thousands_sep();
  }

  // Compute the number of fill charT-s needed, and where they should be put.
  int leftFill=0,internalFill=0,rightFill=0;
  if (this->width>0) {
    int w=this->width - (this->end - this->start) - this->num_groups;
    this->width=0;
    if (w>0) {
      switch (this->adjust) {
       case digit_writer_base::left:
        rightFill=w;
        break;
       case digit_writer_base::internal:
        internalFill=w;
        break;
       default:
        leftFill=w;
      }
    }
  }

  // Widen the sign + digits + exponent string.
//charT wide_digits[sizeof digit_writer_base::buffer];
  charT wide_digits[400];
  this->ctyp.widen(this->start,this->end,wide_digits);

  // Write the widened string with fill and decorations to output.
  charT *digit_pos=wide_digits;
  while (leftFill--)
    *out++=fill;
  if (has_sign)
    *out++=*digit_pos++;    // the widened sign
  while (internalFill--)
    *out++=fill;
  while (unGrouped--)
    *out++=*digit_pos++;
  while (this->num_groups--) {
    *out++=separator;
    while (this->group[0]--)
      *out++=*digit_pos++;
    this->group++;
  }

  if (has_point) {
    *out++=this->get_decimal_point();
    digit_pos++;
  }

  unGrouped=this->end-dec;
  if (has_point)
    unGrouped--;
  while (unGrouped-->0)
    *out++=*digit_pos++;

  while (rightFill--)
    *out++=fill;
}

template <class charT, class OutputIterator>
void digit_writer<charT,OutputIterator>::
    put_keyword (const string_type &k, charT fill)
{
  int leftFill=0,rightFill=0;
  int n=this->width-k.length();
  if (n>0) {
    switch (this->adjust) {
     case digit_writer_base::left:
      rightFill=n;
      break;
     case digit_writer_base::internal:
     default:
      leftFill=n;
    }
    if (leftFill)
      do *out++=fill;
      while (--leftFill);
  }

  const charT *p=k.c_str(),*end=p+k.length();
  while (p<end)
    *out++=*p++;

  if (rightFill)
    do *out++=fill;
    while (--rightFill);
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // __STD_RW_NUMBRW_CC__

#pragma option pop
#endif /* __NUMBRW_CC */
