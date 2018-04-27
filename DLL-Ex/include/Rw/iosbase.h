#ifndef __IOSBASE_H
#define __IOSBASE_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_IOSBASE__
#define __STD_IOSBASE__
/***************************************************************************
 *
 * iosbase - Declarations for the Standard Library basic stream I/O
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
#include <cstdio>
#include <cstdlib>
#include <cstring>
#ifdef _HPACC_
#include <wchar.h>
#else
#ifndef _RWSTD_NO_WIDE_CHAR
#include <cwchar>
#ifndef _RWSTD_NO_WCTYPE_H
#include <cwctype>
#endif 
#endif // _RWSTD_NO_WIDE_CHAR
#endif // _HPACC_
#include <cstddef>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifndef _RWSTD_NO_WIDE_CHAR
#ifndef _RWSTD_NO_WCHAR_H
#include <wchar.h>
#endif
#ifndef _RWSTD_NO_WCTYPE_H
#include <wctype.h>
#endif
#endif // _RWSTD_NO_WIDE_CHAR
#include <stddef.h>
#endif // _RWSTD_NO_NEW_HEADER

#include <rw/stdmutex.h> 

#ifndef _RWSTD_NO_EXCEPTIONS
#ifdef _RW_STD_EXCEPT
#include <exception>
#endif
#endif // _RWSTD_NO_EXCEPTIONS

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  typedef long         SZ_T;       
  typedef SZ_T         streamsize;

  class _RWSTDExportTemplate __Wide_Init
  {
    static int    __initcnt;
  public:
    static int    getinit_cnt_() { return __initcnt;}
    __Wide_Init();
    ~__Wide_Init();
  };

  /*
   *     Class ios_base
   */

  class _RWSTDExport ios_base
  {
  public:

#ifndef _RWSTD_NO_EXCEPTIONS
#ifdef  _RW_STD_EXCEPT
    class _RWSTDExport failure : public exception
    {
    public:
      _EXPLICIT failure(const string& msg);
      virtual ~failure() _RWSTD_THROW_SPEC_NULL;
      virtual const char* what() const _RWSTD_THROW_SPEC_NULL;

    private:
      string __str;
    };
#endif // _RW_STD_EXCEPT
#endif // _RWSTD_NO_EXCEPTIONS
    typedef int      fmtflags;
    
    enum fmt_flags {
      boolalpha   = 0x0001,
      dec         = 0x0002,
      fixed       = 0x0004,
      hex         = 0x0008,
      internal    = 0x0010,
      left        = 0x0020,
      oct         = 0x0040,
      right       = 0x0080,
      scientific  = 0x0100,
      showbase    = 0x0200, 
      showpoint   = 0x0400, 
      showpos     = 0x0800, 
      skipws      = 0x1000, 
      unitbuf     = 0x2000, 
      uppercase   = 0x4000, 
      adjustfield = left | right | internal,
      basefield   = dec | oct | hex,
      floatfield  = scientific | fixed
    };
    
    typedef int      iostate;

    enum io_state {
      goodbit     = 0x00,   
      badbit      = 0x01,   
      eofbit      = 0x02,  
      failbit     = 0x04  
    };

    typedef int      openmode;

    enum open_mode {
      app         = 0x01,   
      binary      = 0x02,  
      in          = 0x04, 
      out         = 0x08,   
      trunc       = 0x10,                  
#ifdef _RWSTD_STRICT_ANSI
      ate         = 0x20
#else
      ate         = 0x20,
      nocreate    = 0x40,
      noreplace   = 0x80
#endif
    };

    typedef int      seekdir;

    enum seek_dir {
      beg         = 0x0,    
      cur         = 0x1,    
      end         = 0x2   
    };  

    enum EmptyCtor {emptyctor};      // enum type used for empty constructors in derived classes

    class _RWSTDExportTemplate Init {
      static int    __initcnt;
    public:
      static int    getinit_cnt_() { return __initcnt;}
      Init();
      ~Init();
    };

    inline fmtflags flags() const;
    inline fmtflags flags(fmtflags fmtfl);
    inline fmtflags setf(fmtflags fmtfl);
    inline fmtflags setf(fmtflags fmtfl, fmtflags mask);
    inline void unsetf(fmtflags mask);

    inline streamsize precision() const;
    inline streamsize precision(streamsize prec);
    inline streamsize width() const;
    inline streamsize width(streamsize wide);

    locale imbue(const locale& loc);
    locale getloc() const
    { return __loc; }

    static int xalloc();
    long&  iword(int index);
    void*& pword(int index);

    enum event { 
      erase_event   = 0x0001,
      imbue_event   = 0x0002,
      copyfmt_event = 0x0004
    };

    typedef void (*event_callback) (event, ios_base&, int index);
    void register_callback( event_callback fn, int index);
    
    ios_base& copyfmt(const ios_base& rhs);
    ios_base& _RW_UNSAFE_copyfmt(const ios_base& rhs);

    bool is_synch() 
    { return __sync_with_stdio; }

    static bool sync_with_stdio(bool sync = true)
    { 
      bool tmp =__sync_with_stdio;
      __sync_with_stdio = sync;
      return tmp;
    }

    virtual ~ios_base();    

  protected:

    ios_base();
    ios_base(int) {} // empty constructor for creating uninitialized stream

    fmtflags           __fmtfl; 
    streamsize         __prec;   
    streamsize         __wide;   
    
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDMutex __stream_mutex;
#endif

  private:

    void usersize(int);
    locale             __loc;

    union ios_user_union {
      long         __lword;
      void        *__pword;
    };

    struct register_call {
      int             __index;
      event_callback  __fn;
    }; 

    static int                  __index;
    int                         __index_cp;
    int                         __index_callback;  
    union  ios_user_union      *__userwords; 
    struct register_call       *__registered_call;
    static bool                 __sync_with_stdio;
  };
 
  /*
   *     inline definitions
   */
 
  /*
   * fmtflags flags() const
   */

  inline ios_base::fmtflags 
  ios_base::flags() const
  {
    return __fmtfl;
  }

  /*
   * fmtflags flags(fmtflags)
   */

  inline ios_base::fmtflags 
  ios_base::flags(ios_base::fmtflags flgs)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    ios_base::fmtflags      f = __fmtfl;
    __fmtfl = flgs;
    return f;
  }

  /*
   * fmtflags setf(fmtflags)
   */

  inline ios_base::fmtflags 
  ios_base::setf(ios_base::fmtflags flgs)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    ios_base::fmtflags       f = __fmtfl;
    __fmtfl |= flgs;
    return f;
  }

  /*
   * fmtflags setf(fmtflags, fmtflags)
   */

  inline ios_base::fmtflags 
  ios_base::setf(ios_base::fmtflags flgs, ios_base::fmtflags mask)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    ios_base::fmtflags      old = __fmtfl;
    __fmtfl &= ~mask;
    __fmtfl |= (flgs & mask);
    return old;
  }

  /*
   * void unsetf(fmtflags)
   */

  inline void 
  ios_base::unsetf(ios_base::fmtflags fg)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    __fmtfl &= ~fg;
  }

  /*
   * streamsize precision() const
   */

  inline streamsize 
  ios_base::precision() const
  {
    return __prec;
  }

  /*
   * streamsize precision(streamsize)
   */
  inline streamsize 
  ios_base::precision(streamsize p)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    streamsize    temp = __prec;
    __prec = p;
    return temp;
  }

  /*
   * streamsize width() const
   */

  inline streamsize 
  ios_base::width() const
  {
    return __wide;
  }

  /*
   * streamsize width(streamsize)
   */

  inline streamsize 
  ios_base::width(streamsize w)
  {
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDGuard guard(this->__stream_mutex);
#endif
    streamsize      i = __wide;
    __wide = w;
    return i;
  }

  /*
   *     External declarations for manipulators
   */

  inline ios_base& unitbuf(ios_base& strm)
  {
    strm.setf(ios_base::unitbuf);
    return strm;
  }

  /*
   * unset the unitbuf mode
   */

  inline ios_base& nounitbuf(ios_base& strm)
  {
    strm.unsetf(ios_base::unitbuf);
    return strm;
  }

  /*
   * says that bool will be inserted/extracted as
   * false/true depending on locale
   */

  inline ios_base& boolalpha(ios_base& strm)
  {
    strm.setf(ios_base::boolalpha);
    return strm;
  }

  /*
   * bool is inserted/extraced as 0/1
   v   */

  inline ios_base& noboolalpha(ios_base& strm)
  {
    strm.unsetf(ios_base::boolalpha);
    return strm;
  }

  /*
   * shows the base of the number e.g. 0777 for oct, 0x for hex
   */

  inline ios_base& showbase(ios_base& strm)
  {
    strm.setf(ios_base::showbase);
    return strm;
  }

  /*
   * does not show the base
   */

  inline ios_base& noshowbase(ios_base& strm)
  {
    strm.unsetf(ios_base::showbase);
    return strm;
  }

  /*
   * shows the decimal point on floating insertion even if not necessary
   */

  inline ios_base& showpoint(ios_base& strm)
  { 
    strm.setf(ios_base::showpoint);
    return strm;
  }

  /*
   * does not show the decimal point if not necessary
   */

  inline ios_base& noshowpoint(ios_base& strm)
  {
    strm.unsetf(ios_base::showpoint);
    return strm;
  }

  /*
   * prints the sign of the number.  will also print '+' for positive #'s
   */

  inline ios_base& showpos(ios_base& strm)
  {
    strm.setf(ios_base::showpos);
    return strm;
  }

  /*
   * only shows the sign for negative values
   */

  inline ios_base& noshowpos(ios_base& strm)
  {
    strm.unsetf(ios_base::showpos);
    return strm;
  }

  /*
   * skips the white space when reading characters
   */

  inline ios_base& skipws(ios_base& strm)
  {
    strm.setf(ios_base::skipws);
    return strm;
  }

  /*
   * doesn't skip white space when reading characters
   */

  inline ios_base& noskipws(ios_base& strm)
  {
    strm.unsetf(ios_base::skipws);
    return strm;
  }

  /*
   * prints floating point and hex values in uppercase.
   * e.g. 1.234E05, 0X1B
   */

  inline ios_base& uppercase(ios_base& strm)
  {
    strm.setf(ios_base::uppercase);
    return strm;
  }

  /*
   * uses lowercase for floating point and hex values
   */

  inline ios_base& nouppercase(ios_base& strm)
  {
    strm.unsetf(ios_base::uppercase);
    return strm;
  }

  inline ios_base& internal(ios_base& strm)
  {
    strm.setf(ios_base::internal, ios_base::adjustfield);
    return strm;
  }

  /*
   * does left justifying
   */

  inline ios_base& left(ios_base& strm)
  {
    strm.setf(ios_base::left, ios_base::adjustfield);
    return strm;
  }

  /*
   * does right justifying
   */

  inline ios_base& right(ios_base& strm)
  {
    strm.setf(ios_base::right, ios_base::adjustfield);
    return strm;
  }

  /*
   * prints integer values in decimal
   */

  inline ios_base& dec(ios_base& strm)
  {
    strm.setf(ios_base::dec, ios_base::basefield);
    return strm;
  }

  /*
   * prints integer values in hexadecimal
   */

  inline ios_base& hex(ios_base& strm)
  {
    strm.setf(ios_base::hex, ios_base::basefield);
    return strm;
  }

  /*
   * prints integer values in octal
   */

  inline ios_base& oct(ios_base& strm)
  {
    strm.setf(ios_base::oct, ios_base::basefield);
    return strm;
  }

  /*
   * generate floating point numbers in fixed-point notation
   */

  inline ios_base& fixed(ios_base& strm)
  {
    strm.setf(ios_base::fixed, ios_base::floatfield);
    return strm;
  }

  /*
   * generates floating-point numbers in scientific notation
   */

  inline ios_base& scientific(ios_base& strm)
  {
    strm.setf(ios_base::scientific, ios_base::floatfield);
    return strm;
  }

  // end inlining

#if defined ( __SUNPRO_CC )
  static ios_base::Init      __rwStreamInit;
#endif

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif // __STD_IOSBASE__ 
#pragma option pop
#endif /* __IOSBASE_H */
