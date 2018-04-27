/* This file is included specially and does not have a normal header guard */
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_EXCEPTION

/***************************************************************************
 *
 * exception - declarations for the Standard Library exception class
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
#include <rw/stddefs.h>

#ifndef __EXCEPT_H // __BORLANDC__
#  include <except.h>
#endif

#if !defined(_HPACC_)
#ifndef __RWSTD_EXCEPTION_SEEN

#ifndef _RWSTD_EXCEPTION_HANDLER_IN_STD

typedef void (*terminate_handler) ();
extern terminate_handler set_terminate(terminate_handler f) _RWSTD_THROW_SPEC_NULL;
extern void terminate( );

typedef void (*unexpected_handler) ();
extern unexpected_handler set_unexpected( unexpected_handler f)  _RWSTD_THROW_SPEC_NULL;
extern void unexpected();
extern bool uncaught_exception();

#endif /* _RWSTD_EXCEPTION_HANDLER_IN_STD */

#ifndef _RWSTD_NO_NAMESPACE 
namespace __rwstd {
#endif

  extern const char _RWSTDExportFunc(*) __rw_stdexcept_NoNamedException;
  extern const char _RWSTDExportFunc(*) __rw_stdexcept_BadException;

#ifndef _RWSTD_NO_NAMESPACE 
}
#endif

//
// Temporarily turn off the warnings under the Borland compiler that
// say 'Functions containing ... cannot be inlined'
//
#if defined(__BORLANDC__)
#pragma option -w-inl
#endif

#ifdef _RWSTD_EXCEPTION_DEFINED

#include <stdexcept.h>

#ifndef _RWSTD_NO_NAMESPACE 
namespace std {
#endif

#else

#ifndef _RWSTD_NO_NAMESPACE 
namespace std {
#endif

  class _RWSTDExport exception     
  {
  public:
    exception () _RWSTD_THROW_SPEC_NULL
    { ; }
    exception (const exception&) _RWSTD_THROW_SPEC_NULL 
    { ; }
#if defined(_MSC_VER) && !defined(__BORLANDC__)
    exception (const char *s) _RWSTD_THROW_SPEC_NULL 
    { ; }
#endif
    exception& operator= (const exception& e)  _RWSTD_THROW_SPEC_NULL
    { return *this; }
    virtual ~exception ()  _RWSTD_THROW_SPEC_NULL;

    virtual const char * what () const  _RWSTD_THROW_SPEC_NULL
    { 
      return __RWSTD::__rw_stdexcept_NoNamedException;
    }
  };

#endif /* _RWSTD_EXCEPTION_DEFINED */

#if !defined(_RWSTD_BAD_EXCEPTION_DEFINED)
  class _RWSTDExport bad_exception : public exception     
  { 
  public:
    bad_exception () _RWSTD_THROW_SPEC_NULL : exception( )
    { ; }
    bad_exception(const bad_exception&) _RWSTD_THROW_SPEC_NULL
    { ; }
    bad_exception& operator=(const bad_exception&) _RWSTD_THROW_SPEC_NULL
    { return *this; }
    virtual ~bad_exception ()  _RWSTD_THROW_SPEC_NULL;

    virtual const char * what () const  _RWSTD_THROW_SPEC_NULL
    { 
      return __RWSTD::__rw_stdexcept_BadException;
    }
  };
#endif  /* _RWSTD_BAD_EXCEPTION_DEFINED */

#define __RWSTD_EXCEPTION_SEEN

#ifndef _RWSTD_NO_NAMESPACE 
} 
#endif

//
// Yes, the exception hierarchy has been seen!
//
#endif /*__RWSTD_EXCEPTION_SEEN*/
#else
#include <exception.h>
#define RWSTD_exception exception
#endif /*!defined _HPACC_ */
//
// Yes, the complete file has been processed!
//
#define __STD_EXCEPTION

#endif /*__STD_EXCEPTION */

#pragma option pop

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif
