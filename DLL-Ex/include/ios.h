#ifndef __IOS_H
#define __IOS_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_IOS__
#define __STD_IOS__

/***************************************************************************
 *
 * ios - Declarations for the Standard Library basic stream I/O
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

#include <rw/rwstderr.h>        // error messages
#include <rw/rwlocale>          // locale class
#include <rw/ctype>             // facets
#include <rw/codecvt>           // code coversion facet
#include <rw/numeral>           // numeric facet 
#include <rw/vendor>            // standard xxx_byname facets & vendor-defined extensions
#include <rw/usefacet>          // usefacet and hasfacet
#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifdef _RWSTD_LOCALIZED_ERRORS
  extern const unsigned int _RWSTDExport rwse_failbit_set;
  extern const unsigned int _RWSTDExport rwse_badbit_set;
  extern const unsigned int _RWSTDExport rwse_eofbit_set;
#else
  extern const char _RWSTDExportFunc(*) rwse_failbit_set;
  extern const char _RWSTDExportFunc(*) rwse_badbit_set;
  extern const char _RWSTDExportFunc(*) rwse_eofbit_set;
#endif // _RWSTD_LOCALIZED_ERRORS
#ifndef _RWSTD_NO_NAMESPACE
}
namespace std {
#endif
 
  /*
   *    Class basic_ios
   */

  template<class charT, class traits>
  class _RWSTDExportTemplate basic_ios : public ios_base
  { 

  public:
    //
    // Types:
    //
    typedef _TYPENAME traits::char_type        char_type;
    typedef _TYPENAME traits::int_type         int_type;
    typedef _TYPENAME traits::pos_type         pos_type;
    typedef _TYPENAME traits::off_type         off_type;
    typedef traits                             traits_type;
      
    typedef basic_ios<charT, traits>           ios_type;
    typedef basic_streambuf<charT, traits>     streambuf_type; 
    typedef basic_ostream<charT, traits>       ostream_type;

    inline operator void*() const;
    inline bool operator! () const;
    inline iostate rdstate() const;
    inline void clear(iostate state = goodbit);
    inline void setstate(iostate state);

    inline bool good() const;
    inline bool eof()  const;
    inline bool fail() const;
    inline bool bad()  const;
      
    inline iostate exceptions() const;
    inline void exceptions(iostate excpt);
      
    _EXPLICIT basic_ios(basic_streambuf<charT, traits> *sb_arg);
    virtual ~basic_ios();

    inline ostream_type *tie() const;
    ostream_type *tie(ostream_type *tie_arg);

    inline streambuf_type *rdbuf() const;
    streambuf_type *rdbuf( streambuf_type *sb);

    ios_type& copyfmt(const ios_type& rhs);
      
    char_type fill() const
    {
      return __fillch;
    }
    char_type fill(char_type ch)
    {
#ifdef _RWSTD_MULTI_THREAD
      _RWSTDGuard guard(this->__stream_mutex);
#endif
      char_type    temp = __fillch;
      __fillch = ch;
      return temp;
    }
    locale imbue(const locale& loc);

    inline char  narrow(charT, char) const;
    inline charT widen(char) const;

  protected:
    basic_ios();
    basic_ios(int) : ios_base(1) {} // empty contructor for creating unitialized stream
    void init(basic_streambuf<charT, traits> *sb);
      
    inline void _RW_UNSAFE_clear(iostate state = goodbit);

  private:
    basic_ios(const basic_ios& );       //  not defined
    basic_ios& operator=(const basic_ios&);     //  not defined

    streambuf_type       *__sb;    
    ostream_type         *__tiestr;   
    char_type            __fillch; 
    iostate              __state;   
    iostate              _Except; 

  };

  /*
   * basic_streambuf *rdbuf() const
   */

  template<class charT, class traits>
  inline basic_streambuf<charT, traits> *
  basic_ios<charT, traits>::rdbuf() const
  {
    return __sb;
  }

  /*
   * basic_ostream *tie() const
   */

  template<class charT, class traits>
  inline basic_ostream<charT, traits> *
  basic_ios<charT, traits>::tie() const
  {
    return __tiestr;
  }

  /*
   * void exceptions(iostate)
   */

  template<class charT, class traits>
  inline void 
  basic_ios<charT, traits>::exceptions(ios_base::iostate st)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    _Except = st;

#ifdef _RWSTD_MULTI_THREAD
    _RW_UNSAFE_clear(rdstate()); 
#else
    clear(rdstate());
#endif //  _RWSTD_MULTI_THREAD
  }

  /*
   * iostate exceptions() const
   */

  template<class charT, class traits>
  inline ios_base::iostate 
  basic_ios<charT, traits>::exceptions() const
  { 
    return _Except;
  }

  /*
   * void clear(iostate )
   */

  template<class charT, class traits>
  inline void 
  basic_ios<charT, traits>::clear(iostate st)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif 
    _RW_UNSAFE_clear(st); 
  }

  /*
   * void setstate(iostate)
   */

  template<class charT, class traits>
  inline void
  basic_ios<charT, traits>::setstate(iostate st)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif // _RWSTD_MULTI_THREAD

#ifdef _RWSTD_MULTI_THREAD
    _RW_UNSAFE_clear(__state | st); 
#else
    clear(__state | st);
#endif // _RWSTD_MULTI_THREAD
  }

  /*
   * iostate rdstate() const
   */

  template<class charT, class traits>
  inline ios_base::iostate 
  basic_ios<charT, traits>::rdstate() const
  {
    return __state;
  }

  /*
   * operator bool() const
   */

  template<class charT, class traits>
  inline basic_ios<charT, traits>::operator void*() const
  {
    return fail() ? (void*)0 : (void*)1;
  }

  /*
   * bool operator!() const
   */

  template<class charT, class traits>
  inline bool 
  basic_ios<charT, traits>::operator!() const
  {
    return fail();
  }

  /*
   * bool good() const
   */

  template<class charT, class traits>
  inline bool 
  basic_ios<charT, traits>::good() const
  {
    return (__state == ios_base::goodbit);
  }

  /*
   * bool eof() const
   */

  template<class charT, class traits>
  inline bool 
  basic_ios<charT, traits>::eof() const
  {
    return (__state & ios_base::eofbit);
  }

  /*
   * bool fail() const
   */

  template<class charT, class traits>
  inline bool 
  basic_ios<charT, traits>::fail() const
  {
    return (__state & (ios_base::failbit | ios_base::badbit));
  }

  /*
   * bool bad() const
   */

  template<class charT, class traits>
  inline bool 
  basic_ios<charT, traits>::bad() const
  {
    return (__state & ios_base::badbit);
  }

  /*
   * void _RW_UNSAFE_clear(iostate )
   */

  template<class charT, class traits>
  inline void 
  basic_ios<charT, traits>::_RW_UNSAFE_clear(iostate st)
  {
    if ( !__sb ) 
    {
      st |= ios_base::badbit;
      __state |= ios_base::badbit; 
    }

    __state = st;

    if( rdstate() & exceptions() )
    {
#ifdef _RW_STD_EXCEPT
#ifndef _RWSTD_NO_EXCEPTIONS
      if ( rdstate() & exceptions() & ios_base::failbit )
      { 
        __state=st;
        throw ios_base::failure( string(__RWSTD::except_msg_string(__RWSTD::rwse_failbit_set).msgstr()) );
      }

      if ( rdstate() & exceptions() & ios_base::badbit )
      { 
        __state=st;
        throw ios_base::failure( string(__RWSTD::except_msg_string(__RWSTD::rwse_badbit_set).msgstr()) );
      }
      if ( rdstate() & exceptions() & ios_base::eofbit )
      { 
        __state=st;
        throw ios_base::failure( string(__RWSTD::except_msg_string(__RWSTD::rwse_eofbit_set).msgstr()) );
      }
#endif //  _RWSTD_NO_EXCEPTIONS
#endif //  _RW_STD_EXCEPT
    }
  }

  /*
   * char narrow(charT, char) const
   */

  template<class charT, class traits>
  inline char 
  basic_ios<charT, traits>::narrow(charT c, char dfault) const
  {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    return use_facet< ctype<charT> >(getloc()).narrow(c,dfault);
#else
    return use_facet(getloc(),(ctype<charT>*)0).narrow(c,dfault);
#endif
     
  }

  /*
   * charT widen(char) const
   */

  template<class charT, class traits>
  inline charT 
  basic_ios<charT, traits>::widen(char c) const
  {
#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
    return use_facet< ctype<charT> >(getloc()).widen(c);
#else
    return use_facet(getloc(),(ctype<charT>*)0).widen(c);
#endif
     
  }

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_ios<char>                          ios;
#else
  typedef basic_ios<char, char_traits<char> >      ios;
#endif

#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_ios<wchar_t>                         wios;
#else
  typedef basic_ios<wchar_t, char_traits<wchar_t> >  wios;
#endif //  _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
#endif //  _RWSTD_NO_WIDE_CHAR

  /*
   *     external declarations for manipulators
   */

#ifdef _RWSTD_MULTI_THREAD
  template <class charT, class traits>
  basic_ios<charT,traits>& __lock(basic_ios<charT,traits>&);

  template <class charT, class traits>
  basic_ios<charT,traits>& __unlock(basic_ios<charT,traits>&);
#endif // _RWSTD_MULTI_THREAD
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <ios.cc>
#endif // _RWSTD_COMPILE_INSTANTIATE
#endif // __STD_IOS_
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __IOS_H */
