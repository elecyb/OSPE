#ifndef __ISTREAM_H
#define __ISTREAM_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_ISTREAM__
#define __STD_ISTREAM__

/***************************************************************************
 *
 * istream - Declarations for the Standard Library istreams
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

#include <ios>
#include <ostream>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif
  
  extern istream _RWSTDExport cin;

#ifndef _RWSTD_NO_WIDE_CHAR
  extern wistream _RWSTDExport wcin;
#endif

  template<class charT, class traits>
  class _RWSTDExportTemplate basic_istream : virtual public basic_ios<charT, traits>
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
      
    typedef basic_istream<charT, traits>             istream_type;
    typedef basic_ios<charT, traits>                 ios_type;
    typedef basic_streambuf<charT, traits>           streambuf_type;

    _EXPLICIT basic_istream(basic_streambuf<charT, traits> *sb);
#if defined ( __SUNPRO_CC )
    _EXPLICIT basic_istream(EmptyCtor) : basic_ios<charT, traits>(1) {}
#endif
    virtual ~basic_istream();

    class sentry 
    {
    public:

      inline _EXPLICIT sentry(basic_istream<charT,traits>& stream,
                              bool noskipws = 0)
        : __stream(stream)
      {
#ifdef _RWSTD_MULTI_THREAD
        if ( stream.rdbuf() )
          __guard = new _RWSTDGuard(stream.rdbuf()->buffer_mutex_);
#ifndef _RWSTD_NO_EXCEPTIONS
        try {
#endif
#endif // _RWSTD_MULTI_THREAD

          if(!(stream.good())) 
          {   
            stream.setstate(ios_base::failbit);
            __ok = false;
          }
          else
          {
            if(stream.tie())  
              stream.tie()->flush();

            if(!noskipws && (stream.flags() & ios_base::skipws))  
            {
              int_type        c;

#ifndef _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
              const ctype<charT>& ct = use_facet< ctype<charT> >(stream.getloc());
#else
              const ctype<charT>& ct = use_facet(stream.getloc(),(ctype<charT>*)0);
#endif // _RWSTD_NO_TEMPLATE_ON_RETURN_TYPE
         
              while((c = stream.rdbuf()->sgetc()),
                    ( !traits::eq_int_type(c,traits::eof()) && ct.is(ct.space,c) )) 
              {
                stream.rdbuf()->snextc();
              }
 
              if( traits::eq_int_type(c,traits::eof()) )
              {
                stream.setstate(ios_base::eofbit);
              }
            }

            if(!(stream.good())) 
            { 
              stream.setstate(ios_base::failbit);
              __ok = false;
            }
            else 
              __ok =true;
          }
#if defined (_RWSTD_MULTI_THREAD) && !defined (_RWSTD_NO_EXCEPTIONS)
        } catch(...) 
        {
          if ( __stream.rdbuf() )
            delete __guard;
          throw;
        }          
#endif // _RWSTD_MULTI_THREAD etc.
      }

      ~sentry() { 
#ifdef _RWSTD_MULTI_THREAD
        if ( __stream.rdbuf() )
          delete __guard;
#endif // _RWSTD_MULTI_THREAD
      }
      operator bool () { return __ok; }

    private:
      basic_istream<charT,traits>& __stream;
      bool __ok;
#ifdef _RWSTD_MULTI_THREAD
      _RWSTDGuard* __guard;
#endif

    };

    istream_type& operator>>(istream_type& (*pf)(istream_type&));
    istream_type& operator>>(ios_base& (*pf)(ios_base&));
    istream_type& operator>>(ios_type& (*pf)(ios_type&));

#ifndef _RWSTD_NO_BOOL
    istream_type& operator>>(bool& n);
#endif
    istream_type& operator>>(short& n);
    istream_type& operator>>(unsigned short& n);
    istream_type& operator>>(int& n);
    istream_type& operator>>(unsigned int& n);
    istream_type& operator>>(long& n);
    istream_type& operator>>(unsigned long& n);
    istream_type& operator>>(float& f);
    istream_type& operator>>(double& f);
    istream_type& operator>>(long double& f);
#ifdef _RWSTD_LONG_LONG
    istream_type& operator>>(_RWSTD_LONG_LONG& n);
    istream_type& operator>>(unsigned _RWSTD_LONG_LONG& n);
#endif
    istream_type& operator>>(void*& p);
    istream_type& operator>>(streambuf_type& sb);
    istream_type& operator>>(streambuf_type *sb);

    int_type get()
    {
      ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
      try {
#endif 
        _TYPENAME basic_istream<charT, traits>::sentry ipfx(*this,1);
        __chcount = 0;

        if(ipfx)
        { 
          int_type      c = this->rdbuf()->sbumpc();

          if( traits::eq_int_type(c,traits::eof()) )  
          {
            err = ios_base::eofbit | ios_base::failbit;
          }
          else
          {
            __chcount = 1;
            return c;
          }
        }

#ifndef _RWSTD_NO_EXCEPTIONS
      } // end of try block
      catch(...)
      {
        bool flag = false;
        try {
          this->setstate(ios_base::badbit);
        }
        catch( ios_base::failure ) { flag= true; }
        if ( flag ) throw;
      }
#endif // _RWSTD_NO_EXCEPTIONS

      if ( err ) this->setstate(err);

      return traits::eof();
    }
    istream_type& get(char_type *s, streamsize n, char_type delim);
    istream_type& get(char_type *s, streamsize n)
    { return get(s,n,this->widen('\n')); }

    istream_type& get(char_type& c);

    istream_type& get(streambuf_type& sb, char_type delim);
    istream_type& get(streambuf_type& sb)
    { return get(sb,this->widen('\n')); }

    istream_type& getline(char_type *s, streamsize n, char_type delim);
    istream_type& getline(char_type *s, streamsize n)
    { return getline(s,n,this->widen('\n')); }

    istream_type& ignore(streamsize n = 1, int_type delim = traits::eof());

    istream_type& read(char_type *s, streamsize n);

    streamsize readsome(char_type *s, streamsize n);

    int_type peek();
      
    pos_type tellg();

    //
    // The seekg functions are inlined for portability
    //
    istream_type& seekg(pos_type pos)
    {
      ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
      try {
#endif 
        if ( this->rdstate() & ios_base::eofbit )
          clear( this->rdstate() & ~ios_base::eofbit );

#ifdef _RWSTD_MULTI_THREAD
        if ( this->rdbuf() ) {
          _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#endif // _RWSTD_MULTI_THREAD

		  // using fail will disable seek when at end of char buffer, bad() would work better
		  if ( !this->fail() )
			  this->rdbuf()->pubseekpos(pos, ios_base::in);

#ifdef _RWSTD_MULTI_THREAD
		}
#endif // _RWSTD_MULTI_THREAD

#ifndef _RWSTD_NO_EXCEPTIONS
      } // end of try block
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
      catch(...)
      {
        bool flag = false;
        try {
          this->setstate(ios_base::badbit);
        }
        catch( ios_base::failure ) { flag= true; }
        if ( flag ) throw;
      }
#endif // _RWSTD_NO_EXCEPTIONS

      return *this;
    }

    istream_type& seekg(off_type off, ios_base::seekdir dir)
    {
      ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
      try {
#endif 

#ifdef _RWSTD_MULTI_THREAD
		  if ( this->rdbuf() ) {
			  _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#endif 
			  if ( !this->fail() )
			  {
				  this->rdbuf()->pubseekoff(off, dir, ios_base::in);
			  }

#ifdef _RWSTD_MULTI_THREAD
		  }
#endif 

#ifndef _RWSTD_NO_EXCEPTIONS
      }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
      catch(...)
      {
        bool flag = false;
        try {
          this->setstate(ios_base::badbit);
        }
        catch( ios_base::failure ) { flag= true; }
        if ( flag ) throw;
      }
#endif // _RWSTD_NO_EXCEPTIONS

      return *this;
    }

    int sync();

    istream_type& putback(char_type c);

    istream_type& unget();

    streamsize gcount() const;

#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard *istream_sentry_guard;
#endif
    
  protected:
    basic_istream( );

  private:
    streamsize       __chcount;
  };
  /*
   *  Class basic_iostream
   */

  template<class charT, class traits>
  class _RWSTDExportTemplate basic_iostream : public basic_istream<charT, traits>,
                                              public basic_ostream<charT, traits> 
  {
  public:
    _EXPLICIT basic_iostream(basic_streambuf<charT, traits> *sb);
    virtual ~basic_iostream();
      
  protected:
    _EXPLICIT basic_iostream();
  };

  //
  // istream iterator.
  //

#ifdef _RWSTD_NO_UNDEFINED_FRIEND

  template <class T, class charT, class traits, class Distance>
  class _RWSTDExportTemplate istream_iterator;

  template <class T, class charT, class traits, class Distance>
  bool operator== 
  (const istream_iterator<T,charT,traits,Distance>& x,
   const istream_iterator<T,charT,traits,Distance>& y);

#endif

#if !defined(_MSC_VER) || defined(__BORLANDC__)
  template <class T, class charT, class traits, class Distance>
#else
  template <class T, class charT=char, class traits=char_traits<charT>, class Distance=ptrdiff_t>
#endif
  class _RWSTDExportTemplate istream_iterator
    : public iterator<input_iterator_tag,T,Distance,const T*, const T&>
  {
#ifdef __TURBOC__
    friend inline bool (std::operator==) (
        const istream_iterator<T,charT,traits,Distance>& x,
        const istream_iterator<T,charT,traits,Distance>& y);
#else
    friend inline bool operator== (
        const istream_iterator<T,charT,traits,Distance>& x,
        const istream_iterator<T,charT,traits,Distance>& y);
#endif
  public: 
    typedef charT char_type;
    typedef traits traits_type;
    typedef basic_istream<charT,traits> istream_type;
    typedef T value_type;
    
    istream_iterator () : stream(&cin), end_marker(false) {}
    istream_iterator (basic_istream<charT,traits>& s) : stream(&s) { read(); }
    istream_iterator ( const istream_iterator<T,charT,traits,Distance>& x )
      : stream(x.stream) , value(x.value) , end_marker(x.end_marker)
    { ; }
    const T& operator* () const { return value; }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
    const T* operator->() const { return &value; }
#endif // _RWSTD_NO_NONCLASS_ARROW_RETURN
    istream_iterator<T,charT,traits,Distance>& operator++ ()
    { 
      read(); 
      return *this;
    }
    istream_iterator<T,charT,traits,Distance> operator++ (int)
    {
      istream_iterator<T,charT,traits,Distance> tmp = *this;
      read(); 
      return tmp;
    }
      
  protected:
    basic_istream<charT,traits>* stream;
    T        value;
    bool     end_marker;

    void read ()
    {
      end_marker = (*stream) ? true : false;
      if (end_marker) *stream >> value;
      end_marker = (*stream) ? true : false;
    }

  };

  template <class T, class charT, class traits, class Distance>
  inline bool operator== 
  (const istream_iterator<T,charT,traits,Distance>& x,
   const istream_iterator<T,charT,traits,Distance>& y)
  {
    return x.stream == y.stream && x.end_marker == y.end_marker ||
    x.end_marker == false && y.end_marker == false;
  }

#ifndef _RWSTD_NO_NAMESPACE
  template <class T, class charT, class traits, class Distance>
  inline bool operator!= 
  (const istream_iterator<T,charT,traits,Distance>& x,
   const istream_iterator<T,charT,traits,Distance>& y)
  {
    return !(x == y);
  }
#endif
 
  template<class charT, class traits>
  basic_istream<charT, traits>& _RWSTDExportTemplate
  ws(basic_istream<charT, traits>& is);

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_istream<char>                               istream;
#else
  typedef basic_istream<char, char_traits<char> >           istream;
#endif
 
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_istream<wchar_t>                            wistream;
#else
  typedef basic_istream<wchar_t, char_traits<wchar_t> >     wistream;
#endif
#endif

#ifndef _RWSTD_NO_DEFAULT_TEMPLATES
  typedef basic_iostream<char>                              iostream;
#else
  typedef basic_iostream<char, char_traits<char> >          iostream;
#endif
 
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_DEFAULT_TEMPLATES
  typedef basic_iostream<wchar_t>                           wiostream;
#else
  typedef basic_iostream<wchar_t, char_traits<wchar_t> >    wiostream;
#endif
#endif
  // charT and charT* extractors

  template<class charT, class traits>
  basic_istream<charT, traits>& _RWSTDExportTemplate 
  operator>> ( basic_istream<charT, traits>&, charT& );

  template<class charT, class traits>
  basic_istream<charT, traits>& _RWSTDExportTemplate 
  operator>> ( basic_istream<charT, traits>&, charT* );
  // signed and unsigned extractors

#ifndef _RWSTD_NO_SIGNED_CHAR_IN_STREAMS
  template <class traits>
  basic_istream<char, traits>& _RWSTDExportTemplate 
  operator>> ( basic_istream<char, traits>&, unsigned char& );

  template <class traits>
  basic_istream<char, traits>& _RWSTDExportTemplate 
  operator>> ( basic_istream<char, traits>&, signed char& );

  template <class traits>
  basic_istream<char, traits>& _RWSTDExportTemplate 
  operator>> ( basic_istream<char, traits>&, unsigned char* );

  template <class traits>
  basic_istream<char, traits>& _RWSTDExportTemplate 
  operator>> ( basic_istream<char, traits>&, signed char* );
#endif

  // String extractor and getline

#ifndef _RWSTD_NO_NAMESPACE
}
namespace __rwstd {
#endif

  template <class streamT, class stringT, class traits>
  streamT& rw_extract_string(streamT& is, stringT& s, traits);

#ifndef _RWSTD_NO_NAMESPACE
}
namespace std {
#endif

  template<class charT, class traits, class Allocator>
  inline basic_istream<charT, traits>&
  operator>> (basic_istream<charT,traits>& is,
                                   basic_string<charT,traits,Allocator>& s)
  {
    return __RWSTD::rw_extract_string(is,s,traits());
  }

  template<class charT, class traits, class Allocator>
  basic_istream<charT, traits>& _RWSTDExportTemplate
  getline( basic_istream<charT, traits>&,
           basic_string<charT, traits, Allocator>&,
           charT delim );

  template<class charT, class traits, class Allocator>
  inline basic_istream<charT, traits>& 
  getline( basic_istream<charT, traits>& is,
           basic_string<charT, traits, Allocator>& str )
  { return getline(is,str,is.widen('\n')); }  
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <istream.cc>
#endif
#endif  // __STD__ISTREAM__ 
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __ISTREAM_H */
