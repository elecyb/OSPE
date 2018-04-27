/* This file is included specially and does not have a normal header guard */
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_STDEXCEPT

/***************************************************************************
 *
 * stdexcept - declarations for the Standard Library standard exception class
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
#include <string>
#ifndef __RWSTD_EXCEPT_SEEN
#include <exception>

#ifndef _RWSTD_NO_NAMESPACE 
namespace std {
#endif

// MSVC provides its own exception class and logic_error class.  
// In order to allow the use of MSVC classes derived from these
// We have to use them to, instead of our own.  The drawback is 
// that we don't have a logic_error(const string&) constructor any
// more.  Now we have a logic_error(const char *) constructor.

#ifndef _RWSTD_LOGIC_ERROR_DEFINED
  class _RWSTDExport logic_error : public exception
  {
  public:
    logic_error (const string& what_arg)  _RWSTD_THROW_SPEC_NULL       
    : str_(what_arg)
    { ; }

    virtual ~logic_error ()  _RWSTD_THROW_SPEC_NULL;

    virtual const char * what () const  _RWSTD_THROW_SPEC_NULL
    {
      return str_.data();
    }

  private:
    string str_;
  };
#endif

  class _RWSTDExport domain_error : public logic_error
  {
  public:
    domain_error (const string& what_arg) _RWSTD_THROW_SPEC_NULL 
#ifndef _RWSTD_LOGIC_ERROR_DEFINED
    : logic_error(what_arg) {;}
#else
    : logic_error(what_arg.c_str()) {;}
#endif

    virtual ~domain_error ()  _RWSTD_THROW_SPEC_NULL;
  };

  class _RWSTDExport invalid_argument : public logic_error
  {
  public:
    invalid_argument (const string& what_arg) _RWSTD_THROW_SPEC_NULL 
#ifndef  _RWSTD_LOGIC_ERROR_DEFINED
    : logic_error(what_arg) {;}
#else
    : logic_error(what_arg.c_str()) {;}
#endif

    virtual ~invalid_argument ()  _RWSTD_THROW_SPEC_NULL;
  };

  class _RWSTDExport length_error : public logic_error
  {
  public:
    length_error (const string& what_arg) _RWSTD_THROW_SPEC_NULL 
#ifndef  _RWSTD_LOGIC_ERROR_DEFINED
    : logic_error(what_arg) {;}
#else
    : logic_error(what_arg.c_str()) {;}
#endif

    virtual ~length_error ()  _RWSTD_THROW_SPEC_NULL;
  };

  class _RWSTDExport out_of_range : public logic_error
  {
  public:
    out_of_range (const string& what_arg) _RWSTD_THROW_SPEC_NULL 
#ifndef  _RWSTD_LOGIC_ERROR_DEFINED
    : logic_error(what_arg) {;}
#else
    : logic_error(what_arg.c_str()) {;}
#endif

    virtual ~out_of_range ()  _RWSTD_THROW_SPEC_NULL;
  };

  class _RWSTDExport runtime_error : public exception
  {
  public:
    runtime_error (const string& what_arg) _RWSTD_THROW_SPEC_NULL  
    : str_(what_arg)
    { ; }

    virtual ~runtime_error ()  _RWSTD_THROW_SPEC_NULL;

    virtual const char * what () const  _RWSTD_THROW_SPEC_NULL
    {
      return str_.data();
    }

  private:
    string str_;
  };

  class _RWSTDExport range_error : public runtime_error
  {
  public:
    range_error (const string& what_arg) _RWSTD_THROW_SPEC_NULL 
    : runtime_error(what_arg) {;}

    virtual ~range_error ()  _RWSTD_THROW_SPEC_NULL;
  };

  class _RWSTDExport overflow_error : public runtime_error
  {
  public:
    overflow_error (const string& what_arg) _RWSTD_THROW_SPEC_NULL 
    : runtime_error(what_arg) {;}

    virtual ~overflow_error ()  _RWSTD_THROW_SPEC_NULL;
  };

  class _RWSTDExport underflow_error : public runtime_error
  {
  public:
    underflow_error (const string& what_arg) _RWSTD_THROW_SPEC_NULL 
    : runtime_error(what_arg) {;}

    virtual ~underflow_error ()  _RWSTD_THROW_SPEC_NULL;
  };

#ifndef _RWSTD_NO_NAMESPACE 
} 
#endif

#define __RWSTD_EXCEPT_SEEN

#endif //__RWSTD_EXCEPT_SEEN

//
// Yes, the complete file has been processed!
//
#define __STD_STDEXCEPT

#endif //__STD_STDEXCEPT

#pragma option pop

#ifndef __USING_STD_NAMES__
  using namespace std;
#endif
