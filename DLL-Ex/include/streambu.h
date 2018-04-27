#ifndef __STREAMBU_H
#define __STREAMBU_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_STREAMBUF__
#define __STD_STREAMBUF__

/***************************************************************************
 *
 * streambuf - Declarations for the Standard Library stream buffers
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

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstdlib>
#else
#include <stdlib.h>
#endif

#include <ios>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  template<class charT, class traits>
  class _RWSTDExportTemplate basic_streambuf {

  public:
    //
    // Types:
    //
    typedef charT                                       char_type;
    typedef _TYPENAME traits::int_type                  int_type;
    typedef _TYPENAME traits::pos_type                  pos_type;
    typedef _TYPENAME traits::off_type                  off_type;
    typedef traits                                      traits_type;

    virtual ~basic_streambuf();

    locale pubimbue( const locale& loc);
    locale getloc() const; 

    inline  basic_streambuf<char_type, traits> *
    pubsetbuf(char_type *s, streamsize n);

    inline pos_type pubseekoff(off_type off, ios_base::seekdir way,
                               ios_base::openmode which =
                               ios_base::in | ios_base::out);

    inline pos_type pubseekpos(pos_type sp, ios_base::openmode which =
                               ios_base::in | ios_base::out);

    inline int pubsync( );
    inline ios_base::openmode which_open_mode();
    inline streamsize   in_avail();

    inline int_type snextc();
    inline int_type sbumpc();
    inline int_type sgetc();
    inline streamsize sgetn(char_type *s, streamsize n);

    inline int_type sputbackc(char_type c);
    inline int_type sungetc();

    inline int_type sputc(char_type c);
    inline streamsize sputn(const char_type *s, streamsize n);

#ifdef _RWSTD_MULTI_THREAD
    _RWSTDMutex buffer_mutex_;

    void _RW_lock_buffer()
    {
      _RWSTDGuard* tmp = new _RWSTDGuard(buffer_mutex_);
      if ( tmp )
        __buffer_guard = tmp;
      else
        __buffer_guard = 0;
    }

    void _RW_unlock_buffer()
    {
      if ( __buffer_guard )
      {
        _RWSTDGuard* tmp = __buffer_guard;
        __buffer_guard = 0;
        delete tmp;
      }
    }
#endif // _RWSTD_MULTI_THREAD

  protected:
    basic_streambuf();

    ios_base::openmode mode_;
     
    inline char_type *eback() const;  
    inline char_type *gptr() const;
    inline char_type *egptr() const;
    inline void gbump(int n);
    inline void setg(char_type *gbeg_arg,char_type *gnext_arg,char_type *gend_arg);

    inline char_type *pbase() const;  
    inline char_type *pptr() const;   
    inline char_type *epptr() const;
    inline void pbump(int n);
    inline void setp(char_type *pbeg_arg,char_type *pend_arg);

    virtual void imbue( const locale& loc);

    virtual basic_streambuf<charT, traits> *
    setbuf(char_type *s, streamsize n);

    virtual pos_type seekoff(off_type off,
                             ios_base::seekdir way, ios_base::openmode which = 
                             ios_base::in | ios_base::out);

    virtual pos_type seekpos(pos_type sp,
                             ios_base::openmode which = 
                             ios_base::in | ios_base::out);

    virtual streamsize showmanyc();
    virtual streamsize xsgetn(char_type *s, streamsize n);
    virtual int_type underflow();
    virtual int_type uflow();
    virtual int_type overflow(int_type c = traits::eof());
      
    virtual int_type pbackfail(int_type c = traits::eof());      
    virtual streamsize xsputn(const char_type *s, streamsize n);

    virtual int sync( );
    void streambuf_init(bool set_mode= true);

  private:

    char_type       *__gbeg;    
    char_type       *__gnext;  
    char_type       *__gend;    

    char_type       *__pbeg;   
    char_type       *__pnext;   
    char_type       *__pend;  

    locale          __loc_buf; 

#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard *__buffer_guard; 
#endif // _RWSTD_MULTI_THREAD
  };
  /* 
   * inline functions
   */

  /*
   * int_type snextc()
   * returns the next character
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::snextc()
  {
    if( traits::eq_int_type(sbumpc(),traits::eof()) )
      return traits::eof();

    return sgetc();
  }

  /*
   * int_type sbumpc()
   * returns the current character and increments the pointer
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::sbumpc()
  { 
    char_type c;

    if( gptr()>= egptr()) {
      return uflow();
    } 
    c=*gptr();  
    gbump(1); 
    return traits::to_int_type(c);
  }

  /*
   * int_type sgetc()
   * returns the current character
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::sgetc()
  {

    if(gptr() >= egptr()) {  
      return underflow();
    }

    return traits::to_int_type(*gptr());
  }

  /*
   * streamsize sgetn(char_type *, streamsize)
   * reads in 'n' characters into 's'
   */

  template<class charT, class traits>
  inline streamsize basic_streambuf<charT, traits>::
  sgetn(char_type *s, streamsize n)
  {
    return xsgetn(s, n);
  }

  /*
   * int_type sputbackc(char_type)
   * puts the character back into the sequence if possible
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::sputbackc(char_type c)
  {
    if( gptr() > eback())
    { 
      gbump(-1);
      if( !traits::eq(*gptr(),c) )
      { 
        gbump(1); 
        return pbackfail(traits::to_int_type(c));
      }

      return traits::to_int_type(*gptr());
    }

    return pbackfail(traits::to_int_type(c)); 
  }

  /*
   * int sungetc()
   * puts the character back into the sequence. The putback character doesn't
   * have to already be there.  Similar to sputbackc(...)
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::sungetc()
  {
    if(gptr() > eback())
    {
      gbump(-1);
      return traits::to_int_type(*gptr());
    } 
    return pbackfail();
  }

  /*
   * int sputc(char_type)
   * puts the character into the sequence
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::int_type
  basic_streambuf<charT, traits>::sputc(char_type c)
  {
  
    if( pptr() >= epptr() )
    {
      return overflow(traits::to_int_type(c));
    }
    *__pnext++ =c; 
    return traits::to_int_type(c);
  }

  /*
   * streamsize sputn(const char_type *, streamsize)
   * writes n characters from s into the sequence
   */

  template<class charT, class traits>
  inline streamsize
  basic_streambuf<charT, traits>::sputn(const char_type *s, streamsize n)
  {
    return xsputn(s, n);
  }

  /*
   * void gbump(int)
   * increments the get pointer by n.  Does no checking to see if this
   * is a valid operation
   */

  template<class charT, class traits>
  inline void 
  basic_streambuf<charT, traits>::gbump(int n)
  {
    __gnext += n;
  }

  /*
   * void setg(char_type *, char_type *, char_type *)
   * sets the get pointers
   */

  template<class charT, class traits>
  inline void 
  basic_streambuf<charT, traits>::
  setg(char_type *gbeg, char_type *gnext, char_type *gend)
  {
    __gbeg  = gbeg;
    __gnext = gnext;
    __gend  = gend;
  }

  /*
   * void pbump(int)
   * increments the put pointer.  No checking to see if this is valid
   */

  template<class charT, class traits>
  inline void 
  basic_streambuf<charT, traits>::pbump(int n)
  {
    __pnext += n;
  }

  /*
   * void setp(char_type *, char_type *)
   * sets up the put pointers
   */

  template<class charT, class traits>
  inline void 
  basic_streambuf<charT, traits>::
  setp(char_type *pbeg, char_type *pend)
  {
    __pbeg = pbeg;
    __pnext = pbeg;
    __pend = pend;
  }

  /*
   * char_type *eback() const
   * returns the beginning of the get sequence
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::char_type *
  basic_streambuf<charT, traits>::eback() const
  {
    return __gbeg;
  }

  /*
   * char_type *gptr() const
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::char_type *
  basic_streambuf<charT, traits>::gptr() const
  {
    return __gnext;
  }

  /*
   * char_type *egptr() const
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::char_type *
  basic_streambuf<charT, traits>::egptr() const
  {
    return __gend;
  }

  /*
   * char_type *pbase() const
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::char_type *
  basic_streambuf<charT, traits>::pbase() const
  {
    return __pbeg;
  }

  /*
   * char_type *pptr() const
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::char_type *
  basic_streambuf<charT, traits>::pptr() const
  {
    return __pnext;
  }

  /*
   * char_type *epptr() const
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::char_type *
  basic_streambuf<charT, traits>::epptr() const
  {
    return __pend;
  }

  /*
   * streamsize in_avail()
   * returns how many characters are available
   */

  template<class charT, class traits>
  inline streamsize 
  basic_streambuf<charT, traits>::in_avail()
  {
    if(gptr() >= egptr())
      return showmanyc();

    return ( (streamsize)(egptr() - gptr()) );
  }
 
  /*
   * int pubsync()
   */

  template<class charT, class traits>
  inline int 
  basic_streambuf<charT, traits>::pubsync()
  {
    return sync();
  }

  /*
   * pos_type pubseekoff(off_type, ios_base::seekdir, ios_base::openmode)
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::pos_type
  basic_streambuf<charT, traits>::
  pubseekoff(off_type off, ios_base::seekdir way, ios_base::openmode which)
  {
    return seekoff(off, way, which);
  }

  /*
   * pos_type pubseekpos(pos_type, ios_base::openmode)
   */

  template<class charT, class traits>
  inline _TYPENAME basic_streambuf<charT, traits>::pos_type
  basic_streambuf<charT, traits>::
  pubseekpos(pos_type sp,
             ios_base::openmode which)
  {
    return seekpos(sp, which);
  }

  /*
   * basic_streambuf *pubsetbuf(char_type *, streamsize)
   */

  template<class charT, class traits>
  inline  basic_streambuf<charT, traits> *
  basic_streambuf<charT, traits>::
  pubsetbuf(char_type *s, streamsize n)
  {
    return setbuf(s, n);
  }

  /*
   * ios_base::openmode which_open_mode()
   */

  template<class charT, class traits>
  inline ios_base::openmode
  basic_streambuf<charT, traits>::which_open_mode()
  {
    return mode_; 
  }

  /*
   *   streambuf iterators
   */

  /*
   *  ostreambuf_iterator
   */

  template<class charT, class traits >
  class _RWSTDExportTemplate ostreambuf_iterator 
    : public iterator<output_iterator_tag,charT, 
  _TYPENAME traits::off_type,charT*,charT&>
  {

  public:
    //
    // Types:
    //
    typedef charT                          char_type;
    typedef traits                         traits_type;
    typedef basic_streambuf<charT, traits> streambuf_type;
    typedef basic_ostream<charT, traits>   ostream_type;

    ostreambuf_iterator(ostream_type& s) _RWSTD_INLINE_NO_THROW
    : __sbuf(s.rdbuf())
    {
      if ( s.rdbuf() ) __failed_flag = false;
      else 
        __failed_flag = true; 
    }

    ostreambuf_iterator(streambuf_type *s) _RWSTD_INLINE_NO_THROW
    : __sbuf(s)
    { 
      if ( s ) __failed_flag = false;
      else 
        __failed_flag = true;
    }

    ostreambuf_iterator<charT,traits>& operator*()
    { return *this; }
    ostreambuf_iterator<charT,traits>& operator++()
    { return *this; }
    ostreambuf_iterator<charT,traits> operator++(int)
    { return *this; }

    ostreambuf_iterator<charT,traits>& operator=(charT c)
    { 
      if ( !__failed_flag )
      {
        if ( traits::eq_int_type(__sbuf->sputc(c),traits::eof()) )
          __failed_flag=true;
      }
      return *this;
    }

    bool failed( ) const _RWSTD_INLINE_NO_THROW
    { return __failed_flag; }

  protected:

  private:
    streambuf_type        *__sbuf;
    bool                   __failed_flag;
  };

  /*
   * istreambuf_iterator 
   */

  template<class charT, class traits >
  class _RWSTDExportTemplate istreambuf_iterator
    : public iterator<input_iterator_tag,charT,
  _TYPENAME traits::off_type,charT*,charT&>
  {

  public:
    //
    // Types:
    //
    typedef charT                          char_type;
    typedef _TYPENAME traits::int_type      int_type;
    typedef traits                         traits_type;

    typedef basic_streambuf<charT, traits> streambuf_type;
    typedef basic_istream<charT, traits>   istream_type;

    // class to maintain a character and an associated streambuf
    class proxy {
      char_type                       __keep;
      streambuf_type                  *__sbuf;

      proxy(char_type c, streambuf_type *sbuf)
        : __keep(c), __sbuf(sbuf)
      { ; }

    public:

      char_type operator*()
      { return __keep; }

      friend class istreambuf_iterator<charT, traits>;
    };

  public:

    istreambuf_iterator()  _RWSTD_INLINE_NO_THROW
    : __sbuf(0)
    { __failed_flag = true; }
    istreambuf_iterator(istream_type& s)  _RWSTD_INLINE_NO_THROW
    : __sbuf(s.rdbuf())
    { 
      if ( s.rdbuf() ) __failed_flag = false;
      else 
        __failed_flag = true; 
    }
    istreambuf_iterator(streambuf_type *s) _RWSTD_INLINE_NO_THROW
    : __sbuf(s)
    {
      if ( s ) __failed_flag = false;
      else 
        __failed_flag = true;
    }
    istreambuf_iterator(const proxy& p) _RWSTD_INLINE_NO_THROW
    : __sbuf(p.__sbuf)
    { ; }
    inline char_type operator*();
    inline istreambuf_iterator<charT, traits>& operator++();
    inline proxy operator++(int);
    inline bool equal(istreambuf_iterator<charT, traits>& b);

    bool failed( ) const _RWSTD_INLINE_NO_THROW
    { return __failed_flag; }

  protected:

  private:
    streambuf_type     *__sbuf;
    bool                __failed_flag;
  };

  /*
   * inline functions
   */

  /*
   * char_type operator*()
   */

  template<class charT, class traits>
  inline _TYPENAME istreambuf_iterator<charT, traits>::char_type
  istreambuf_iterator<charT, traits>::operator*()
  {
    int_type c;

    if ( __sbuf && !__failed_flag )
    {
      c= __sbuf->sgetc();
      if ( traits::eq_int_type(c,traits::eof()) ) 
      {
        __sbuf = 0;
        __failed_flag = true;
      }
    }
    else return traits::eof();
 
    return traits::to_char_type(c);
  }

  /*
   * istreambuf_iterator& operator++()
   */

  template<class charT, class traits>
  inline istreambuf_iterator<charT, traits>&
  istreambuf_iterator<charT, traits>::operator++()
  {
    if (__sbuf && !__failed_flag )
    { 
      __sbuf->sbumpc();
      if ( traits::eq_int_type(__sbuf->sgetc(),traits::eof()) ) 
      {
        __sbuf = 0;
        __failed_flag = true;
      } 
    }
    return *this;
  }

  /*
   * proxy operator++(int)
   */

  template<class charT, class traits>
  inline _TYPENAME istreambuf_iterator<charT, traits>::proxy 
  istreambuf_iterator<charT, traits>::operator++(int)
  {

    if (__sbuf && !__failed_flag )
    {
      proxy     prev(__sbuf->sgetc(), __sbuf);
      __sbuf->sbumpc();
      if ( traits::eq_int_type(__sbuf->sgetc(),traits::eof()) ) 
      {
        __sbuf = 0;
        __failed_flag = true;
      }  
      return prev;
    }
    
    charT     c=traits::to_char_type(traits::eof());
    return proxy(c, __sbuf);
  }

  /*
   * bool equal(istreambuf_iterator&)
   */

  template<class charT, class traits>
  inline bool
  istreambuf_iterator<charT, traits>::
  equal(istreambuf_iterator<charT, traits>& b)
  {
    if( ((__sbuf ==0) && (b.__sbuf==0)) || ((__sbuf !=0) && (b.__sbuf !=0)) )
      return true;  
    else
      return false;
  }

  /*
   * bool operator==(istreambuf_iterator& a, istreambuf_iterator& b)
   */

  template<class charT, class traits>
  inline bool _RWSTDExportTemplate operator==(istreambuf_iterator<charT, traits>& a,
                                              istreambuf_iterator<charT, traits>& b)
  {
    return a.equal(b);
  }

  /*
   * bool operator!=(istreambuf_iterator& a, istreambuf_iterator& b)
   */

  template<class charT, class traits>
  inline bool _RWSTDExportTemplate operator!=(istreambuf_iterator<charT, traits>& a,
                                              istreambuf_iterator<charT, traits>& b)
  {
    return !(a.equal(b));
  }

  // end inlining
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_streambuf<char>                             streambuf;
#else
  typedef basic_streambuf<char, char_traits<char> >         streambuf;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
 
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  typedef basic_streambuf<wchar_t>                          wstreambuf;
#else
  typedef basic_streambuf<wchar_t, char_traits<wchar_t> >   wstreambuf;
#endif // _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
#endif // _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <streambu.cc> 
#endif

#endif // __STD_STREAMBUF__ 

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif

#pragma option pop
#endif /* __STREAMBU_H */
