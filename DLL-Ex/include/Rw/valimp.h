#ifndef __VALIMP_H
#define __VALIMP_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __RW_VALIMP__
#define __RW_VALIMP__

/***************************************************************************
 *
 * valimp - Declarations for the Standard Library valarray
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

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstddef>
#include <cstring>
#else
#include <stddef.h>
#include <string.h>
#endif

#include <rw/math.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace std { }
namespace __rwstd {
#define _RW_IMP_SPACE(name) ::__rwstd::name
#else
#define _RW_IMP_SPACE(name) name
#endif
/****************************************************************
 *               IMPLEMENTATION FUNCTIONALITIES                  *
 *                                                               *
 *   - valarray memory model                                     *
 *   - valarray optimization on copy and return                  *
 *                                                               *
 ****************************************************************/
// valarray_traits class
// allow memory optimization 
// for builtin types and user types

  template <class T> 
  class  valarray_traits_optimize 
  {
  public:
    static bool _RWSTDExportTemplate optimize_copy() { return false; }
  };
#ifndef _RWSTD_NO_BOOL
  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<bool>
  {
  public:
    static bool optimize_copy() { return true; }
  };
#endif

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<short>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<unsigned short>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<int>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<unsigned int>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<long>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<unsigned long>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<float>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<double>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<long double>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<char>
  {
  public:
    static bool optimize_copy() { return true; }
  };

  _RWSTD_TEMPLATE
  class _RWSTDExport valarray_traits_optimize<unsigned char>
  {
  public:
    static bool optimize_copy() { return true; }
  };
// for optimization on return of
// valarray<T> values

  template <class T>
  struct _RW_temporary 
  {

    T*      store_adr;
    size_t  length;
  };
// Class _RW_array<T>
// C type array storage class
// responsible for physical representation
// of the valarray in memory and memory operations

  template <class T> class _RW_array {

public:

  _RW_array( )
    : _RW_length(0)
, _RW_storage(0)
  { ; }

  ~_RW_array( )
  { if ( _RW_storage ) delete []_RW_storage; }

  void _initial_size(size_t size)
  {
    _RW_length = size;
    _RW_storage = new T[_RW_length];
  }

  void _initialize_with_value(const T&, size_t);
  void _initialize_with_array(const T*, size_t);
  void _copy_memory_array(const _RW_array<T>&);

  size_t _get_length() const { return _RW_length; }

  T operator[] (size_t ind) const
  { return _RW_storage[ind]; }

  T& operator[] (size_t ind)
  { return _RW_storage[ind]; }

  void _replace(T* tmp_adr, size_t tmp_length )
  {
    _RW_storage = tmp_adr;
    _RW_length = tmp_length;
  }

  T* _RW_get_storage() const { return _RW_storage; }

  void _RW_invalidate()
  {
    _RW_length = 0;
    _RW_storage = 0;
  }

  void _RW_copy( T* pointer ) const
  {
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE)
    std::memcpy( (void*)pointer, (void*)_RW_storage,_RW_length*sizeof(T));
#else
    memcpy( (void*)pointer, (void*)_RW_storage,_RW_length*sizeof(T));
#endif
  }

  void _RW_resize_without_copy( size_t size)
  {
    if ( _RW_storage )
    {
      delete []_RW_storage;
      _RW_storage = 0;
    }
    _RW_length = size;
    if ( size > 0 ) _RW_storage = new T[_RW_length];
  }

private:
  size_t                         _RW_length;
  T*                             _RW_storage;
};
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#ifdef _RWSTD_NO_TEMPLATE_REPOSITORY
#include <rw/valimp.cc>
#endif

#endif /* __RW_VALIMP__ */

#pragma option pop
#endif /* __VALIMP_H */
