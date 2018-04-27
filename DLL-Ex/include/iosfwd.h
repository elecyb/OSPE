#ifndef __IOSFWD_H
#define __IOSFWD_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_IOSFWD__
#define __STD_IOSFWD__

/***************************************************************************
 *
 * iosfwd - forward declarations for the iostreams
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

#include <stdcomp.h>
#include <rw/stdmutex.h>
#ifndef _RWSTD_NO_WCHAR_H
#include <wchar.h>
#endif // _RWSTD_NO_WCHAR_H

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  template<class charT> struct _RWSTDExportTemplate char_traits;

  template <class T> class _RWSTDExportTemplate allocator;

  template <class stateT> class _RWSTDExportTemplate fpos;

#ifdef _RWSTD_NO_MBSTATE_T
  class _RWSTDExportTemplate mbstate_t;
#endif

  typedef fpos<mbstate_t> streampos;
  typedef fpos<mbstate_t> wstreampos;

  typedef long streamoff;
  typedef long wstreamoff;

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#include <rw/traits>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif 

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  template<class charT, class traits = char_traits<charT> > class _RWSTDExportTemplate basic_ios;
  template<class charT, class traits = char_traits<charT> > class _RWSTDExportTemplate basic_streambuf;
  template<class charT, class traits = char_traits<charT> > class _RWSTDExportTemplate basic_istream;
  template<class charT, class traits = char_traits<charT> > class _RWSTDExportTemplate basic_ostream;
  template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT> > 
  class _RWSTDExportTemplate basic_stringbuf;
  template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>  > 
  class _RWSTDExportTemplate basic_istringstream;
  template<class charT, class traits = char_traits<charT>, class Allocator = allocator<charT>  > 
  class _RWSTDExportTemplate basic_ostringstream;
  template<class charT, class traits = char_traits<charT> > class _RWSTDExportTemplate basic_filebuf;
  template<class charT, class traits = char_traits<charT> > class _RWSTDExportTemplate basic_ifstream;
  template<class charT, class traits = char_traits<charT> > class _RWSTDExportTemplate basic_ofstream;
  template<class T, class charT = char, class traits=char_traits<charT> > 
  class _RWSTDExportTemplate ostream_iterator;
  template<class T, class charT = char, class traits=char_traits<charT>,
  class Distance = ptrdiff_t > 
  class _RWSTDExportTemplate istream_iterator;
  template<class charT, class traits=char_traits<charT> > 
  class _RWSTDExportTemplate ostreambuf_iterator;
  template<class charT, class traits=char_traits<charT> > 
  class _RWSTDExportTemplate istreambuf_iterator;
  template<class charT, class traits= char_traits<charT> > class
  _RWSTDExportTemplate basic_iostream;
  template<class charT, class traits= char_traits<charT> > class
  _RWSTDExportTemplate basic_fstream;
  template<class charT, class traits= char_traits<charT>, class Allocator = allocator<charT>  > 
  class _RWSTDExportTemplate basic_stringstream;
#else
  template<class charT, class traits > class _RWSTDExportTemplate basic_ios;
  template<class charT, class traits > class _RWSTDExportTemplate basic_streambuf;
  template<class charT, class traits > class _RWSTDExportTemplate basic_istream;
  template<class charT, class traits > class _RWSTDExportTemplate basic_ostream;
  template<class charT, class traits, class Allocator > class _RWSTDExportTemplate basic_stringbuf;
  template<class charT, class traits, class Allocator > class _RWSTDExportTemplate basic_istringstream;
  template<class charT, class traits, class Allocator > class _RWSTDExportTemplate basic_ostringstream;
  template<class charT, class traits > class _RWSTDExportTemplate basic_filebuf;
  template<class charT, class traits > class _RWSTDExportTemplate basic_ifstream;
  template<class charT, class traits > class _RWSTDExportTemplate basic_ofstream;
  template<class T, class charT, class traits > class _RWSTDExportTemplate ostream_iterator;
  template<class T, class charT, class traits, class Distance > class _RWSTDExportTemplate istream_iterator;
  template<class charT, class traits > class _RWSTDExportTemplate ostreambuf_iterator;
  template<class charT, class traits > class _RWSTDExportTemplate istreambuf_iterator;
  template<class charT, class traits > class _RWSTDExportTemplate basic_iostream;
  template<class charT, class traits > class _RWSTDExportTemplate basic_fstream;
  template<class charT, class traits, class Allocator > class _RWSTDExportTemplate basic_stringstream;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_ios<char>                                    ios;
  typedef basic_streambuf<char>                              streambuf;
  typedef basic_istream<char>                                istream;
  typedef basic_ostream<char>                                ostream;
  typedef basic_stringbuf<char>                              stringbuf;
  typedef basic_istringstream<char>                          istringstream;
  typedef basic_ostringstream<char>                          ostringstream;
  typedef basic_filebuf<char>                                filebuf;
  typedef basic_ifstream<char>                               ifstream;
  typedef basic_ofstream<char>                               ofstream;
  typedef basic_fstream<char>                                fstream;
  typedef basic_iostream<char>                               iostream;
  typedef basic_stringstream<char>                           stringstream;
#ifndef _RWSTD_NO_WIDE_CHAR
  typedef basic_ios<wchar_t>                                 wios;
  typedef basic_streambuf<wchar_t>                           wstreambuf;
  typedef basic_istream<wchar_t>                             wistream;
  typedef basic_ostream<wchar_t>                             wostream;
  typedef basic_stringbuf<wchar_t>                           wstringbuf;
  typedef basic_istringstream<wchar_t>                       wistringstream;
  typedef basic_ostringstream<wchar_t>                       wostringstream;
  typedef basic_filebuf<wchar_t>                             wfilebuf;
  typedef basic_ifstream<wchar_t>                            wifstream;
  typedef basic_ofstream<wchar_t>                            wofstream;
  typedef basic_fstream<wchar_t>                             wfstream;
  typedef basic_iostream<wchar_t>                            wiostream;
  typedef basic_stringstream<wchar_t>                        wstringstream;
#endif // _RWSTD_NO_WIDE_CHAR
#else
  typedef basic_ios<char, char_traits<char> >                 ios;
  typedef basic_streambuf<char, char_traits<char> >           streambuf;
  typedef basic_istream<char, char_traits<char> >             istream;
  typedef basic_ostream<char, char_traits<char> >             ostream;
  typedef basic_stringbuf<char, char_traits<char>, allocator<char> >           stringbuf;
  typedef basic_istringstream<char, char_traits<char>, allocator<char> >       istringstream;
  typedef basic_ostringstream<char, char_traits<char>, allocator<char> >       ostringstream;
  typedef basic_filebuf<char, char_traits<char> >             filebuf;
  typedef basic_ifstream<char, char_traits<char> >            ifstream;
  typedef basic_ofstream<char, char_traits<char> >            ofstream;
  typedef basic_fstream<char, char_traits<char> >             fstream;
  typedef basic_iostream<char, char_traits<char> >            iostream;
  typedef basic_stringstream<char, char_traits<char>, allocator<char> >        stringstream;
#ifndef _RWSTD_NO_WIDE_CHAR
  typedef basic_ios<wchar_t, char_traits<wchar_t> >           wios;
  typedef basic_streambuf<wchar_t, char_traits<wchar_t> >     wstreambuf;
  typedef basic_istream<wchar_t, char_traits<wchar_t> >       wistream;
  typedef basic_ostream<wchar_t, char_traits<wchar_t> >       wostream;
  typedef basic_stringbuf<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >     wstringbuf;
  typedef basic_istringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wistringstream;
  typedef basic_ostringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wostringstream;
  typedef basic_filebuf<wchar_t, char_traits<wchar_t> >       wfilebuf;
  typedef basic_ifstream<wchar_t, char_traits<wchar_t> >      wifstream;
  typedef basic_ofstream<wchar_t, char_traits<wchar_t> >      wofstream;
  typedef basic_fstream<wchar_t,char_traits<wchar_t> >        wfstream;
  typedef basic_iostream<wchar_t, char_traits<wchar_t> >      wiostream;
  typedef basic_stringstream<wchar_t,char_traits<wchar_t>, allocator<wchar_t> >   wstringstream;
#endif // _RWSTD_NO_WIDE_CHAR
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#endif // __STD_IOSFWD__

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __IOSFWD_H */
