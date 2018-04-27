#ifndef __SSTREAM_H
#define __SSTREAM_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_SSTREAM__
#define __STD_SSTREAM__

/***************************************************************************
 *
 * sstream - Declarations for the Standard Library basic streams
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

#include <streambuf>
#include <istream>
#include <ostream>

#ifndef _RWSTD_NO_NAMESPACE
namespace std{
#endif
  
  template<class charT, class traits, class Allocator>
  class _RWSTDExportTemplate basic_stringbuf : public basic_streambuf<charT, traits>
  {

  public:
    //
    // Types:
    //
    typedef charT                                    char_type;
    typedef _TYPENAME traits::int_type               int_type;
    typedef _TYPENAME traits::pos_type               pos_type;
    typedef _TYPENAME traits::off_type               off_type;
    typedef traits                                   traits_type;
  
    typedef basic_ios<charT, traits>                 ios_type;
    typedef basic_string<charT, traits, Allocator >  string_type;

    _EXPLICIT basic_stringbuf(ios_base::openmode which = 
                              ios_base::in | ios_base::out );
     
    _EXPLICIT basic_stringbuf(const string_type& str,
                              ios_base::openmode which = 
                              ios_base::in | ios_base::out );
    
    virtual ~basic_stringbuf();
     
    string_type str() const;
    void str(const string_type& str_arg);

  protected:

    virtual int_type overflow(int_type c = traits::eof());
    virtual int_type pbackfail(int_type c = traits::eof());
    virtual int_type underflow();
    virtual pos_type seekoff(off_type off, ios_base::seekdir way,
                             ios_base::openmode which =
                             ios_base::in | ios_base::out);

    virtual pos_type seekpos(pos_type sp,
                             ios_base::openmode which =
                             ios_base::in | ios_base::out);

    virtual basic_streambuf<charT,traits>* setbuf(char_type* s, streamsize n);
    virtual streamsize xsputn(const char_type *s, streamsize n);

  private:
    charT                   *__data;
    streamsize               __length;
    streamsize               __end_pos;
  };
  template<class charT, class traits, class Allocator>
  class _RWSTDExportTemplate basic_istringstream : public basic_istream<charT, traits>
  {

  public:
    //
    // Types:
    //
    typedef charT                                           char_type;
    typedef _TYPENAME traits::int_type                      int_type;
    typedef _TYPENAME traits::pos_type                      pos_type;
    typedef _TYPENAME traits::off_type                      off_type;
    typedef traits                                          traits_type;
  
    typedef basic_stringbuf<charT, traits, Allocator>       sb_type;
    typedef basic_ios<charT, traits>                        ios_type;
    typedef basic_string<charT, traits, Allocator >         string_type;

    _EXPLICIT basic_istringstream(ios_base::openmode which = ios_base::in);
    _EXPLICIT basic_istringstream(const string_type& str,
                                  ios_base::openmode which = ios_base::in);

    virtual ~basic_istringstream();

    basic_stringbuf<charT, traits, Allocator> *rdbuf() const;
    string_type str() const;

    void str(const string_type& str);

  protected:

  private:
    basic_stringbuf<charT, traits, Allocator>    __sb;
  };
  template<class charT, class traits, class Allocator>
  class _RWSTDExportTemplate basic_ostringstream : public basic_ostream<charT, traits>
  {

  public:
    //
    // Types:
    //
    typedef charT                                             char_type;
    typedef _TYPENAME traits::int_type                        int_type;
    typedef _TYPENAME traits::pos_type                        pos_type;
    typedef _TYPENAME traits::off_type                        off_type;
    typedef traits                                            traits_type;
      
    typedef basic_stringbuf<charT, traits, Allocator>         sb_type;
    typedef basic_ios<charT, traits>                          ios_type;
    typedef basic_string<charT, traits, Allocator>            string_type;

    _EXPLICIT basic_ostringstream(ios_base::openmode which = ios_base::out);
    _EXPLICIT basic_ostringstream(const string_type& str,
                                  ios_base::openmode which = ios_base::out);

    virtual ~basic_ostringstream();
    basic_stringbuf<charT, traits, Allocator> *rdbuf() const;

    string_type str() const;
    void str(const string_type& str);

  protected:

  private:
    sb_type            __sb;
  };
  /*
   *  Class stringstream
   */

  template<class charT, class traits, class Allocator>
  class _RWSTDExportTemplate basic_stringstream : public basic_iostream<charT, traits>
  {

  public:
    //
    // Types:
    //
    typedef charT                                             char_type;
    typedef _TYPENAME traits::int_type                        int_type;
    typedef _TYPENAME traits::pos_type                        pos_type;
    typedef _TYPENAME traits::off_type                        off_type;
    typedef traits                                            traits_type;
      
    typedef basic_stringbuf<charT, traits, Allocator>         sb_type;
    typedef basic_ios<charT, traits>                          ios_type;
    typedef basic_string<charT, traits, Allocator>            string_type;
    _EXPLICIT basic_stringstream(ios_base::openmode which = ios_base::out | 
                                 ios_base::in);

    _EXPLICIT basic_stringstream(const string_type& str,
                                 ios_base::openmode which = 
                                 ios_base::out | ios_base::in);

    virtual ~basic_stringstream();
    basic_stringbuf<charT, traits, Allocator> *rdbuf() const;
    string_type str() const;
    void str(const string_type& str);

  protected:

  private:
    sb_type            __sb;
  };
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_stringbuf<char>                                      stringbuf;
#else
  typedef basic_stringbuf<char, char_traits<char>, allocator<char> > stringbuf;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_stringbuf<wchar_t>                                            wstringbuf;
#else
  typedef basic_stringbuf<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wstringbuf;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
#endif // _RWSTD_NO_WIDE_CHAR

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_istringstream<char>                                      istringstream;
#else
  typedef basic_istringstream<char, char_traits<char>, allocator<char> > istringstream;
#endif
  
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_istringstream<wchar_t>                                            wistringstream;
#else
  typedef basic_istringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wistringstream;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
#endif // _RWSTD_NO_WIDE_CHAR 
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_ostringstream<char>                                         ostringstream;
#else
  typedef basic_ostringstream<char, char_traits<char>, allocator<char> >    ostringstream;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
  
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_ostringstream<wchar_t>                                            wostringstream;
#else
  typedef basic_ostringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> > wostringstream;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES 
#endif // _RWSTD_NO_WIDE_CHAR

#ifndef _RWSTD_NO_DEFAULT_TEMPLATES
  typedef basic_stringstream<char>                                        stringstream;
#else
  typedef basic_stringstream<char, char_traits<char>, allocator<char> >   stringstream;
#endif // _RWSTD_NO_DEFAULT_TEMPLATES 

#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_DEFAULT_TEMPLATES
  typedef basic_stringstream<wchar_t>                                             wstringstream;
#else
  typedef basic_stringstream<wchar_t, char_traits<wchar_t>, allocator<wchar_t> >  wstringstream;
#endif // _RWSTD_NO_DEFAULT_TEMPLATES
#endif // _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <sstream.cc>
#endif
#endif // __STD_SSTREAM__ 
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __SSTREAM_H */
