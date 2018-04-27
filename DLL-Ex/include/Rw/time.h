#ifndef __BOR_RW__TIME_H
#define __BOR_RW__TIME_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * time - Declarations for the Standard Library time facets
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

#ifndef __STD_TIME__
#define __STD_TIME__

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale> 
#endif

#ifndef __STD_RW_LOCNUMRW__
#include <rw/numbrw>
#endif

#ifndef __STD_RW_LOCHELP__
#include <rw/lochelp>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

struct _RWSTDExport time_base {
   enum dateorder { no_order, dmy, mdy, ymd, ydm };
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

#if !defined (_RWSTD_NO_NEW_HEADER) && !defined (_RWSTD_NO_NAMESPACE)
  using std::tm;
#endif

// ------------------------------------------------------------------
// Implementation class template -- time_reader<charT,InputIterator>.
// ------------------------------------------------------------------

template <class charT,class InputIterator>
class _RWSTDExportTemplate time_reader :
    public digit_reader<charT,InputIterator>
{
 public:
  typedef _TYPENAME timepunct<charT>::string_type string_type;
  const timepunct<charT> &__timp;

  time_reader (InputIterator& in,InputIterator& end,
      _RW_STD::ios_base& io, const timepunct<charT>& timepunct);

  bool get_time_pattern (const string_type& pattern,tm *time);

  static const timepunct<charT>& __idiocy (_RW_STD::ios_base& io) {
    const _RW_STD::locale loc=io.getloc();
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    return _RW_STD::use_facet<timepunct<charT> >(loc);
#else
    return _RW_STD::use_facet(loc,(timepunct<charT>*)0);
#endif //  _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE

  }
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// ----------------------------------------------------------------------
// Standard time and date parsing facet -- time_get<charT,InputIterator>.
// ----------------------------------------------------------------------

template <class charT,class InputIterator>
class _RWSTDExportTemplate time_get: public locale::facet, public time_base {
 public:
  typedef charT char_type;
  typedef InputIterator iter_type;

  _EXPLICIT time_get (size_t refs=0): locale::facet(refs,locale::time) 
  { ; }

  dateorder date_order() const { return do_date_order(); }
  iter_type get_time (iter_type start, iter_type end, ios_base& format,
      ios_base::iostate &err, tm* time) const
        { return do_get_time (start,end,format,err,time); }

  iter_type get_date (iter_type start, iter_type end, ios_base& format,
      ios_base::iostate &err, tm* time) const
        { return do_get_date(start,end,format,err,time); }

  iter_type get_weekday (iter_type start, iter_type end, ios_base& format,
      ios_base::iostate &err, tm* time) const
        { return do_get_weekday(start,end,format,err,time); }

  iter_type get_monthname (iter_type start, iter_type end, ios_base& format,
      ios_base::iostate &err, tm* time) const
        { return do_get_monthname(start,end,format,err,time); }

  iter_type get_year (iter_type start, iter_type end, ios_base& format,
      ios_base::iostate &err, tm* time) const
        { return do_get_year(start,end,format,err,time); }

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::time, __ok_implicit = 1 };

 protected:
  virtual ~time_get();

  virtual dateorder do_date_order()  const;

  virtual iter_type do_get_time
            (iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_date
            (iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_weekday
            (iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_monthname
            (iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;
  virtual iter_type do_get_year
            (iter_type, iter_type, ios_base&, ios_base::iostate&, tm*) const;

  // Implementation:

 protected:
  const __RWSTD::timepunct<charT>* __timp;
  string __name;

 private:
  void __initfacet (const locale* loc)
  { 
    __RWSTD::use_Clib_locale clocale(__name.c_str(),LC_TIME);    
  #ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    __timp = &_RW_STD::use_facet<__RWSTD::timepunct<charT> >(*loc);
  #else
    __timp = &_RW_STD::use_facet(*loc,(__RWSTD::timepunct<charT>*)0);
  #endif
  }

  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// --------------------------------------------------------------------------
// Standard time and date formatting facet -- time_put<charT,OutputIterator>.
// --------------------------------------------------------------------------

template <class charT,class OutputIterator>
class _RWSTDExportTemplate time_put: public locale::facet {
 public:
  typedef charT char_type;
  typedef OutputIterator iter_type;

  _EXPLICIT time_put (size_t refs=0) : locale::facet(refs,locale::time)
  { ; }

  iter_type put (iter_type start, ios_base& format, char_type fill,
      const tm* time, const char_type *pattern, const char_type *pat_end) const;

  iter_type put (iter_type start, ios_base& format, char_type fill,
      const tm* time, char fmt, char modifier = 0) const
        { return do_put(start,format,fill,time,fmt,modifier); }

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::time, __ok_implicit = 1 };

 protected:
  virtual ~time_put();

  virtual iter_type do_put (iter_type, ios_base&, char_type fill,
           const tm* time, char fmt, char modifier) const;

 protected:
  const __RWSTD::timepunct<charT>* __timp;
  string __name;

 private:
  void __initfacet (const locale* loc)
  { 
    __RWSTD::use_Clib_locale clocale(__name.c_str(),LC_TIME);    
  #ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    __timp = &_RW_STD::use_facet<__RWSTD::timepunct<charT> >(*loc);
  #else
    __timp = &_RW_STD::use_facet(*loc,(__RWSTD::timepunct<charT>*)0);
  #endif
  }
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// -------------------------------------------------
// Standard derived facet -- time_get_byname<charT>.
// -------------------------------------------------

template <class charT, class InputIterator>
class  time_get_byname: public time_get<charT,InputIterator> {
 public:
  _EXPLICIT time_get_byname (const char*, size_t refs=0);

 protected:
  virtual ~time_get_byname();

// Virtual member functions inherited from time_get<charT,InputIterator>:
// virtual dateorder do_date_order()  const;
// virtual iter_type do_get_time (iter_type i, iter_type e, ios_base&,
//                                ios_base::iostate &err, tm* t) const;
// virtual iter_type do_get_date (iter_type i, iter_type e, ios_base&,
//                                ios_base::iostate &err, tm* t) const;
// virtual iter_type do_get_weekday (iter_type i, iter_type e, ios_base&,
//                                ios_base::iostate &err, tm* t) const;
// virtual iter_type do_get_monthname (iter_type i, iter_type e, ios_base&,
//                                ios_base::iostate &err, tm* t) const;
// virtual iter_type do_get_year (iter_type i, iter_type e, ios_base&,
//                                ios_base::iostate &err, tm* t) const;
};

// -------------------------------------------------
// Standard derived facet -- time_put_byname<charT>.
// -------------------------------------------------

template <class charT, class OutputIterator>
class  time_put_byname: public time_put<charT,OutputIterator> {
 public:
  _EXPLICIT time_put_byname (const char*, size_t refs=0); 

 protected:
  virtual ~time_put_byname();

// Virtual member functions inherited from time_put<charT,OutputIterator>:
// virtual iter_type do_put (iter_type s, ios_base&, char_type fill,
//                           const tm* t, char format, char modifier) const;
};
#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

#ifndef _RWSTD_NO_FUNC_PARTIAL_SPEC

template <class charT, class InputIterator>
inline _RW_STD::time_get<charT,InputIterator>* create_named_facet
    (_RW_STD::time_get<charT,InputIterator>*,const char *name,size_t refs)
{ return new _RW_STD::time_get_byname<charT,InputIterator>(name,refs); }

template <class charT, class OutputIterator>
inline _RW_STD::time_put<charT,OutputIterator>* create_named_facet
    (_RW_STD::time_put<charT,OutputIterator>*,const char *name,size_t refs)
{ return new _RW_STD::time_put_byname<charT,OutputIterator>(name,refs); }
#else
_RWSTD_TEMPLATE 
inline _RW_STD::time_get<char,_RW_STD::istreambuf_iterator<char,_RW_STD::char_traits<char> > >* create_named_facet
    (_RW_STD::time_get<char,_RW_STD::istreambuf_iterator<char,_RW_STD::char_traits<char> > >*,const char *name,size_t refs)
{ return new _RW_STD::time_get_byname<char,_RW_STD::istreambuf_iterator<char,_RW_STD::char_traits<char> > >(name,refs); }

inline _RW_STD::time_put<char,_RW_STD::ostreambuf_iterator<char,_RW_STD::char_traits<char> > >* create_named_facet
    (_RW_STD::time_put<char,_RW_STD::ostreambuf_iterator<char,_RW_STD::char_traits<char> > >*,const char *name,size_t refs)
{ return new _RW_STD::time_put_byname<char,_RW_STD::ostreambuf_iterator<char,_RW_STD::char_traits<char> > >(name,refs); }

#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
inline _RW_STD::time_get<wchar_t,_RW_STD::istreambuf_iterator<wchar_t,_RW_STD::char_traits<wchar_t> > >* create_named_facet
    (_RW_STD::time_get<wchar_t,_RW_STD::istreambuf_iterator<wchar_t,_RW_STD::char_traits<wchar_t> > >*,const char *name,size_t refs)
{ return new _RW_STD::time_get_byname<wchar_t,_RW_STD::istreambuf_iterator<wchar_t,_RW_STD::char_traits<wchar_t> > >(name,refs); }

inline _RW_STD::time_put<wchar_t,_RW_STD::ostreambuf_iterator<wchar_t,_RW_STD::char_traits<wchar_t> > >* create_named_facet
    (_RW_STD::time_put<wchar_t,_RW_STD::ostreambuf_iterator<wchar_t,_RW_STD::char_traits<wchar_t> > >*,const char *name,size_t refs)
{ return new _RW_STD::time_put_byname<wchar_t,_RW_STD::ostreambuf_iterator<wchar_t,_RW_STD::char_traits<wchar_t> > >(name,refs); }

#endif // _RWSTD_NO_WIDE_CHAR
#endif // _RWSTD_NO_FUNC_PARTIAL_SPEC
#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/time.cc>
#endif
#endif // __STD_TIME__

#pragma option pop
#endif /* __BOR_RW__TIME_H */
