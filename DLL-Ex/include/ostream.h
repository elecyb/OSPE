#ifndef __OSTREAM_H
#define __OSTREAM_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_OSTREAM__
#define __STD_OSTREAM__

/***************************************************************************
 *
 * ostream - Declarations for the Standard Library ostream classes
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

#ifndef __STD_RWCOMPILER_H__ 
#include <stdcomp.h>
#endif

#ifdef _RW_STD_IOSTREAM

#include <ios>
#include <streambuf>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  extern ostream _RWSTDExport cout;
  extern ostream _RWSTDExport cerr;

#ifndef _RWSTD_NO_WIDE_CHAR
  extern wostream _RWSTDExport wcout;
  extern wostream _RWSTDExport wcerr;
#endif

template <class charT, class traits>
inline bool __rw_is_out(basic_ostream<charT,traits>* s);
inline bool __rw_is_out(basic_ostream<char,char_traits<char> >* s);
#ifndef _RWSTD_NO_WIDE_CHAR
inline bool __rw_is_out(basic_ostream<wchar_t,char_traits<wchar_t> >* s);
#endif
template <class charT, class traits>
inline bool __rw_is_err(basic_ostream<charT,traits>* s);
inline bool __rw_is_err(basic_ostream<char,char_traits<char> >* s);
#ifndef _RWSTD_NO_WIDE_CHAR
inline bool __rw_is_err(basic_ostream<wchar_t,char_traits<wchar_t> >* s);
#endif

  /*
   *  Class basic_ostream
   */
  
  template<class charT, class traits>
  class _RWSTDExportTemplate basic_ostream : virtual public basic_ios<charT, traits>
  {

  public:
    //
    // Types:
    //
    typedef charT                                  char_type;
    typedef _TYPENAME traits::int_type             int_type;
    typedef _TYPENAME traits::pos_type             pos_type;
    typedef _TYPENAME traits::off_type             off_type;
    typedef traits                                 traits_type;
      
    typedef basic_ostream<charT, traits>           ostream_type;
    typedef basic_ios<charT, traits>               ios_type;

    _EXPLICIT basic_ostream(basic_streambuf<charT, traits> *sb);
#if defined ( __SUNPRO_CC )
    _EXPLICIT basic_ostream(EmptyCtor) : basic_ios<charT, traits>(1) {}
#endif
    virtual ~basic_ostream();

    class sentry {
    public:
      inline _EXPLICIT
      sentry(basic_ostream<charT,traits>& stream)
        : __stream(stream)                  
      {  
                      
#ifdef _RWSTD_MULTI_THREAD
        if ( stream.rdbuf() ) {
          __guard = new _RWSTDGuard(stream.rdbuf()->buffer_mutex_);
        }
#ifndef _RWSTD_NO_EXCEPTIONS
        try {
#endif
#endif // _RWSTD_MULTI_THREAD
          if (stream.tie()) 
            stream.tie()->flush();

          if ( stream.is_synch() )
          {
            if ( __rw_is_out(&stream) )
            {
              fflush(stdout);
            }
            if ( __rw_is_err(&stream) )
            {
              fflush(stderr);
            }
          }

          if ( stream.rdbuf() )
          {
            if ( stream.rdbuf()->which_open_mode( ) & ios_base::app )
              stream.rdbuf()->pubseekoff(0,ios_base::end,ios_base::out);
          }

          ok_ = stream.good(); 

          if ( !ok_ ) 
            stream.setstate(ios_base::badbit);

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
        if( __stream.flags() & ios_base::unitbuf)
        {
          if ( __stream.rdbuf()->pubsync() == -1 )
            __stream.setstate(ios_base::badbit);
        }

        if ( __stream.is_synch() )
        {

          if ( __rw_is_out(&__stream) ||  __rw_is_err(&__stream) )
          {
            if ( __stream.rdbuf()->pubsync() == -1 )
              __stream.setstate(ios_base::badbit);
          }
        }

#ifdef _RWSTD_MULTI_THREAD
        if ( __stream.rdbuf() ) {
          delete __guard;
        }
#endif // _RWSTD_MULTI_THREAD
      }
      operator bool () const { return ok_; }

    private:
      sentry(const sentry&); //   not defined
      sentry& operator=(const sentry&); //   not defined
      basic_ostream<charT,traits>& __stream;
      bool ok_;
#ifdef _RWSTD_MULTI_THREAD
      _RWSTDGuard* __guard;
#endif
    };

    ostream_type& operator<<(ostream_type& (*pf)(ostream_type&));
    ostream_type& operator<<(ios_base& (*pf)(ios_base&));
    ostream_type& operator<<(ios_type& (*pf)(ios_type&));

#ifndef _RWSTD_NO_BOOL
    ostream_type& operator<<(bool n);
#endif
    ostream_type& operator<<(short n);
    ostream_type& operator<<(unsigned short n);
    ostream_type& operator<<(int n);
    ostream_type& operator<<(unsigned int n);
    ostream_type& operator<<(long n);
    ostream_type& operator<<(unsigned long n);
    ostream_type& operator<<(float f);
    ostream_type& operator<<(double f);
    ostream_type& operator<<(long double f); 
#ifdef _RWSTD_LONG_LONG
    ostream_type& operator<<(unsigned _RWSTD_LONG_LONG n); 
    ostream_type& operator<<(_RWSTD_LONG_LONG n); 
#endif
    ostream_type& operator<<(const void *p);
   
    ostream_type& operator<<(basic_streambuf<char_type, traits>& sb)
    {
      ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
      try {
#endif
        if ( !(sb.which_open_mode() & ios_base::in) )
          err = ios_base::failbit;
        else
        {
          _TYPENAME basic_ostream<charT, traits>::sentry opfx(*this);

          if(opfx)
          {
		    if ( traits::eq_int_type(sb.sgetc(),traits::eof()))
			  err = ios_base::failbit;
            else {
              int_type    c;
              while( !traits::eq_int_type( (c = sb.sbumpc()),traits::eof()) )
              {
                if( traits::eq_int_type(this->rdbuf()->sputc(c),traits::eof()) )
                {
                  err = ios_base::failbit;
                  break;
                }
              }
            }
          }
        }

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
#endif
      if ( err ) this->setstate(err);
      return *this;
    }

    ostream_type& operator<<(basic_streambuf<char_type, traits> *sb)
    {
      ios_base::iostate err = 0; 

#ifndef _RWSTD_NO_EXCEPTIONS
      try {
#endif
        if (sb)
        {
          if ( !(sb->which_open_mode() & ios_base::in) )
            err = ios_base::failbit;
          else
          {
            _TYPENAME basic_ostream<charT, traits>::sentry opfx(*this);

            if(opfx)
            {
  		      if ( traits::eq_int_type(sb->sgetc(),traits::eof()))
			    err = ios_base::failbit;
			  else {
                int_type    c;
                while( !traits::eq_int_type( (c = sb->sbumpc()),traits::eof()))
                {
                  if( traits::eq_int_type(this->rdbuf()->sputc(c),traits::eof()))
                  {
                    err = ios_base::failbit;
                    break;
                 }
                }
              }
            }
          }
        }
        else 
          err = ios_base::badbit;  

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
#endif
      if ( err ) this->setstate(err);
      return *this;
    }

    ostream_type& put(char_type c);
    ostream_type& write(const char_type *s, streamsize n);
    ostream_type& flush();

    ostream_type& seekp(pos_type pos)
    {
#ifdef _RWSTD_MULTI_THREAD
      if ( this->rdbuf() ) {
#  ifndef __TURBOC__
        _RWSTDGuard guard(this->rdbuf()->buffer_mutex_);
#  else
      STDGUARD(this->rdbuf()->buffer_mutex_);
#  endif // __TURBOC__
#endif // _RWSTD_MULTI_THREAD

      if ( this->fail() ) return *this;

      this->rdbuf()->pubseekpos(pos, ios_base::out);

#ifdef _RWSTD_MULTI_THREAD
	  }
#endif // _RWSTD_MULTI_THREAD
      return *this; // RW_BUG: fix for bts-75631
    }

    ostream_type& seekp(off_type , ios_base::seekdir );
    pos_type tellp();
    
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard *ostream_sentry_guard;
#endif
  protected:
    basic_ostream();
#ifdef _RWSTD_PROTECTED_OSTREAM_COPY_CONSTRUCTOR
    basic_ostream(const basic_ostream&);
#endif
  };

  inline bool __rw_is_out(basic_ostream<char,char_traits<char> >* s)
  { return (void*)s == (void*)&cout; }
#ifndef _RWSTD_NO_WIDE_CHAR
  inline bool __rw_is_out(basic_ostream<wchar_t,char_traits<wchar_t> >* s)
  { return (void*)s == (void*)&wcout; }
#endif

  inline bool __rw_is_err(basic_ostream<char,char_traits<char> >* s)
  { return (void*)s == (void*)&cerr; }
#ifndef _RWSTD_NO_WIDE_CHAR
  inline bool __rw_is_err(basic_ostream<wchar_t,char_traits<wchar_t> >* s)
  { return (void*)s == (void*)&wcerr; }
#endif

  template <class charT, class traits>
  inline bool __rw_is_out(basic_ostream<charT,traits>* s)
  { return false; }

  template <class charT, class traits>
  inline bool __rw_is_err(basic_ostream<charT,traits>* s)
  { return false; }
  //
  // Class ostream_iterator
  //

#if !defined(_MSC_VER) || defined(__BORLANDC__)
  template <class T, class charT, class traits>
#else
  template <class T, class charT=char, class traits=char_traits<charT> >
#endif
  class _RWSTDExportTemplate ostream_iterator
    : public iterator<output_iterator_tag,T,_TYPENAME traits::off_type,T*,T&>
  {
  protected:

    basic_ostream<charT,traits>* __stream;
    const charT*    __str;

  public:
    //
    //Types:
    //
    typedef T value_type;
    typedef charT char_type;
    typedef traits traits_type;
    typedef basic_ostream<charT,traits> ostream_type;

    ostream_iterator (basic_ostream<charT,traits>& s) 
      : __stream(&s),__str(0) 
    { ; }
    ostream_iterator (basic_ostream<charT,traits>& s,const charT* c) 
      : __stream(&s), __str((charT *)c)  
    { ; }
    ostream_iterator ( const ostream_iterator<T,charT,traits>& x )
      : __stream(x.__stream) , __str(x.__str)
    { ; }
    ostream_iterator<T,charT,traits>& operator= (const T& value)
    { 
      *__stream << (T)value;
      if (__str) *__stream << __str;
      return *this;
    }
    ostream_iterator<T,charT,traits>& operator*  ()    { return *this; }
    ostream_iterator<T,charT,traits>& operator++ ()    { return *this; } 
    ostream_iterator<T,charT,traits>& operator++ (int) { return *this; }
  };
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_ostream<char>                            ostream;
#else
  typedef basic_ostream<char, char_traits<char> >        ostream;
#endif
 
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_ostream<wchar_t>                         wostream;
#else
  typedef basic_ostream<wchar_t, char_traits<wchar_t> >  wostream;
#endif
#endif

  // charT and charT* insertors

  template<class charT, class traits>
  basic_ostream<charT, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<charT, traits>&, 
                                                                  charT );

#ifndef _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION

  template<class charT, class traits>
  basic_ostream<charT, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<charT, traits>&, 
                                                                  char );

#ifndef _RWSTD_NO_FUNC_PARTIAL_SPEC
  template <class traits>
  basic_ostream<char, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<char, traits>&, 
                                                                 char );
#else
  ostream& _RWSTDExport operator<< ( ostream&, char );
#endif // _RWSTD_NO_FUNC_PARTIAL_SPEC
#endif // _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION
  template<class charT, class traits>
  basic_ostream<charT, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<charT, traits>&, 
                                                                  const charT* );

#ifndef _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION

  template<class charT, class traits>
  basic_ostream<charT, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<charT, traits>&, 
                                                                  const char* );

#ifndef _RWSTD_NO_FUNC_PARTIAL_SPEC
  template <class traits>
  basic_ostream<char, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<char, traits>&, 
                                                                 const char* );
#else
  ostream& _RWSTDExport operator<< ( ostream&, const char* );
#endif // _RWSTD_NO_FUNC_PARTIAL_SPEC
#endif // _RWSTD_NO_OVERLOAD_OF_TEMPLATE_FUNCTION

  /*
   * signed and unsigned insertors
   */
  
#ifndef _RWSTD_NO_SIGNED_CHAR_IN_STREAMS
  template <class traits>
  basic_ostream<char, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<char, traits>&, 
                                                                 unsigned char );

  template <class traits>
  basic_ostream<char, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<char, traits>&, 
                                                                 signed char );

  template <class traits>
  basic_ostream<char, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<char, traits>&,
                                                                 const unsigned char* );

  template <class traits>
  basic_ostream<char, traits>& _RWSTDExportTemplate operator<< ( basic_ostream<char, traits>&,
                                                                 const signed char* );
#endif // _RWSTD_NO_SIGNED_CHAR_IN_STREAMS

  /*
   * String insertor
   */
  template<class charT, class traits, class Allocator>
  inline basic_ostream<charT, traits>&
  operator<< (basic_ostream<charT,traits>& os,
	      const basic_string<charT,traits,Allocator>& s)
  {
    ios_base::iostate err = 0;

#ifndef _RWSTD_NO_EXCEPTIONS
    try {
#endif
  
      _TYPENAME basic_ostream<charT, traits>::sentry opfx(os);
      if (opfx)
      {
	int   dlen =s.length();
	int   pad = os.width() - dlen;

	// place right padding
	if( !(os.flags() & ios_base::adjustfield) ||  os.flags() & ios_base::right )
	{
	  while(--pad >= 0)
	  {
	    if( traits::eq_int_type(os.rdbuf()->sputc(os.fill()),traits::eof())) {
	      err = ios_base::badbit;
	      break;
	    }
	  }
	}
         
	// output internal padding
	if(os.good() && (os.flags() & ios_base::internal))
	{
	  while(--pad >= 0)
	  {
	    if( traits::eq_int_type(os.rdbuf()->sputc(os.fill()),traits::eof()))
	    {
	      err = ios_base::badbit;
	      break;
	    }
	  }
	}

	if(os.good() && dlen) {
	  if(os.rdbuf() && (os.rdbuf()->sputn(s.c_str(), dlen) != dlen))
	    err = ios_base::badbit;
	}

	// output left padding. 
	if(os.good() && (os.flags() & ios_base::left))
	{
	  while(--pad >= 0)
	  {
	    if( traits::eq_int_type(os.rdbuf()->sputc(os.fill()),traits::eof()))
	    {
	      err = ios_base::badbit;
	      break;
	    }
	  }
	}

	os.width(0);
      }

#ifndef _RWSTD_NO_EXCEPTIONS
    }
#endif

#ifndef _RWSTD_NO_EXCEPTIONS
    catch(...)
    {
      bool flag = false;
      try {
        os.setstate(ios_base::badbit);
      }
      catch( ios_base::failure ) { flag= true; }
      if ( flag ) throw;
    }
#endif

    if ( err ) os.setstate(err);  

    return os;
  }

  extern ostream _RWSTDExport cout;
  extern ostream _RWSTDExport cerr;
  extern ostream _RWSTDExport clog;

  /*
   * declare a couple of standard manipulators
   * global functions
   */
  
  template<class charT, class traits>
  inline basic_ostream<charT, traits>&
  endl(basic_ostream<charT, traits>& os)
  {
    os.put( charT('\n') );
    os.flush(); 
    return os;
  }

  template<class charT, class traits>
  inline basic_ostream<charT, traits>&
  ends(basic_ostream<charT, traits>& os)
  {
    os.put( charT(0) );
    return os;
  }

  template<class charT, class traits>
  inline basic_ostream<charT, traits>&
  flush(basic_ostream<charT, traits>& os)
  {
    os.flush();
    return os;
  }
 
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <ostream.cc>
#endif

#endif //_RW_STD_IOSTREAM

#endif //__STD_OSTREAM__ 
#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __OSTREAM_H */
