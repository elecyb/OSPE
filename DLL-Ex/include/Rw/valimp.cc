#ifndef __VALIMP_CC
#define __VALIMP_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig

/***************************************************************************
 *
 * valimp.cc - Declarations for the Standard Library valarray
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

#ifdef __BORLANDC__
#pragma option -w-ccc
#pragma option -w-rch
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif
/*****************************************************************
 *                                                                *
 *                _RW_array<T> MEMBER FUNCTIONS                    *
 *                                                                *
 ******************************************************************/

  template <class T>
  void 
  _RW_array<T>::_initialize_with_value(const T& value, size_t size)
  {
    if ( _RW_length < size )
      _RW_resize_without_copy(size);

    for(size_t cpt=0; cpt<size; cpt++)
      _RW_storage[cpt] = value;
  }

  template <class T>
  void 
  _RW_array<T>::_initialize_with_array(const T* pointer, size_t size)
  {
    if ( _RW_length < size )
      _RW_resize_without_copy(size);

    if ( valarray_traits_optimize<T>::optimize_copy() )
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE)
      std::memcpy((void *)_RW_storage,(void*)pointer,size*sizeof(T));
#else
      memcpy((void *)_RW_storage,(void*)pointer,size*sizeof(T));
#endif
    else
    {
      for(size_t cpt=0; cpt<size; cpt++)
        _RW_storage[cpt] = pointer[cpt];
    }
  }

  template <class T>
  void 
  _RW_array<T>::_copy_memory_array(const _RW_array<T>& array)
  {
    if ( array._get_length() != _RW_length )
      _RW_resize_without_copy(array._get_length());

    if ( valarray_traits_optimize<T>::optimize_copy() )
      array._RW_copy(_RW_storage);
    else
    {
      for(size_t tmp=0; tmp<_RW_length; tmp++)
        _RW_storage[tmp]= array[tmp];
    }
  }
#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#pragma option pop
#endif /* __VALIMP_CC */
