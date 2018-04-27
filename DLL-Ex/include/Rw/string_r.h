#ifndef __STRING_R_H
#define __STRING_R_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * string_ref - Declarations for the Standard Library string_ref classes
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

#ifndef __STD_STRING_REF
#define __STD_STRING_REF

#include <stdcomp.h>
#include <rw/stddefs.h> 
#include <memory>     // For allocator.
#include <rw/traits>

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// Class & Structure Declarations
//
  template< class charT, class traits _RWSTD_COMPLEX_DEFAULT(char_traits<charT>), 
  class Allocator _RWSTD_COMPLEX_DEFAULT(allocator<charT>) >
  class basic_string;

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

  //
  // __string_noref_rep and __string_noref are used to implement a 
  // non-reference counted string.  Use this implementation when the 
  // overhead from the reference counting (including mutex locking) 
  // overwhelms the advantages.  One example of such a situation would 
  // be in an application that infrequently copies short strings and 
  // only very rarely copies long ones.  Another example would be an 
  // application that makes heavy use of iterators from basic_string, 
  // since any outstanding refernece into the string data nullifies 
  // the advantages of reference counting.
  //

  template <class Allocator>
  class _RWSTDExportTemplate __string_noref_rep
  {
  public:
     _EXPLICIT __string_noref_rep(long refs = 0)
      : __refs_((bool)refs), __capacity_(0), __nchars_(0)  {;}
    __string_noref_rep(const __string_noref_rep& r)
      : __refs_((bool)r.__refs_), __capacity_(0), __nchars_(0)  {;}
  
    typedef Allocator                        allocator_type;
    typedef _TYPENAME _RWSTD_ALLOC_SIZE_TYPE size_type;

  protected:

    bool            __refs_;      // true if null ref, else false
    size_type       __capacity_;  // Size of allocated memory
    size_type       __nchars_;    // Number of actual data values stored
  };

  template <class charT, class traits , class Allocator>
  class _RWSTDExportTemplate __string_noref
   : public __string_noref_rep<Allocator>
  {
  public:
    typedef __string_noref_rep<Allocator> __string_ref_rep_type;
    typedef _TYPENAME __string_noref_rep<Allocator>::size_type size_type;
  
    _EXPLICIT __string_noref (long=0) 
    { ; }

  private:
    long __references () const
    { 
      return (long)__string_noref_rep<Allocator>::__refs_; 
    }
    void __setRefCount (long r)
    { ; }
    void __addReference ()
    { ; }
    long  __removeReference ()
    { 
      return (long)__string_noref_rep<Allocator>::__refs_;
    }
    size_type length () const
    { 
      return __string_noref_rep<Allocator>::__nchars_; 
    }
    size_type __getCapac () const
    { 
      return __string_noref_rep<Allocator>::__capacity_;
    }
    charT*    data () const
    {
      return (charT*)(this+1);
    }
    charT&   operator[]     (size_type i)      
    { 
      return (_RWSTD_REINTERPRET_CAST(charT*,(this+1)))[i]; 
    }
    const charT&  operator[]     (size_type i) const
    {
      return ((charT*)(this+1))[i];
    }
#ifndef _RWSTD_NO_NAMESPACE
    friend class std::basic_string<charT, traits, Allocator>;
#else
    friend class basic_string<charT, traits, Allocator>;
#endif
  };
  //
  // __string_ref_rep and __string_ref are used to implement a 
  // reference counted string.  Using this class  basic_string 
  // optimizes copying by sharing data whenever possible.  Copies 
  // are only made when absolutely necessary.
  //
#if defined (_RWSTD_MULTI_THREAD) && defined(_RWSTD_ONE_STRING_MUTEX) && defined(_RWSTD_NO_TEST_AND_SET)
  extern  _RWSTDMutex _RWSTDExport __rw_string_mutex;
#endif /* _RWSTD_MULTI_THREAD */

  template <class Allocator>
  class _RWSTDExportTemplate __string_ref_rep
  {
  public:
    //  the __refs_ are initialized to 1 because of a problem
    //  where the destructor was being called when it
    //  should not be.
  
    __string_ref_rep()
      : __refs_(0), __capacity_(0), __nchars_(0) {;}
    __string_ref_rep(long x)
      : __refs_(x), __capacity_(0), __nchars_(0) {;}
    __string_ref_rep(const __string_ref_rep& r)
      : __refs_(r.__refs_), __capacity_(0), __nchars_(0)  {;}
  
    typedef Allocator                        allocator_type;
    typedef _TYPENAME _RWSTD_ALLOC_SIZE_TYPE size_type;

  protected:

#if defined (_RWSTD_MULTI_THREAD) && !defined(_RWSTD_ONE_STRING_MUTEX) && defined(_RWSTD_NO_TEST_AND_SET)
    _RWSTDMutex __mutex_;
#endif /* _RWSTD_MULTI_THREAD */  

    long   __refs_;               // (1 less than) number of references
                                  // (-2 if reference counting disabled)
    size_type       __capacity_;  // Size of allocated memory
    size_type       __nchars_;    // Number of actual data values stored
  };
  template <class charT, class traits , class Allocator >
  class _RWSTDExportTemplate __string_ref : public __string_ref_rep<Allocator>
  {
  public:
    typedef __string_ref_rep<Allocator> __string_ref_rep_type;
    typedef _TYPENAME __string_ref_rep<Allocator>::size_type size_type;
  
    _EXPLICIT __string_ref (long initRef = 0) 
      :  __string_ref_rep<Allocator>(initRef - 1)
    { ; }

    __string_ref (const __string_ref<charT,traits,Allocator>& ref)
      : __string_ref_rep<Allocator>(ref.__refs_)
    { ; }

  private:
    long __references () const 
    { 
      return __string_ref_rep<Allocator>::__refs_+1; 
    }

    void __setRefCount (long r)       
    { 
      if (this != _RW_STD::basic_string<charT,traits,Allocator>::__getNullRep())
      {
#ifdef _RWSTD_NO_TEST_AND_SET
#ifdef _RWSTD_MULTI_THREAD
#ifdef _RWSTD_ONE_STRING_MUTEX
         _RWSTDGuard guard(__rw_string_mutex);
#else
         _RWSTDGuard guard(this->__mutex_);
#endif
#endif /* _RWSTD_MULTI_THREAD */
#endif /* _RWSTD_NO_TEST_AND_SET */
        _RWSTD_MT_SET(this->__refs_,r-1);
      }
    }

    void __addReference ()
    { 
      if (this != _RW_STD::basic_string<charT,traits,Allocator>::__getNullRep())
      {
#ifdef _RWSTD_NO_TEST_AND_SET
#ifdef _RWSTD_MULTI_THREAD
#ifdef _RWSTD_ONE_STRING_MUTEX
         _RWSTDGuard guard(__rw_string_mutex);
#else
         _RWSTDGuard guard(this->__mutex_);
#endif
#endif /* _RWSTD_MULTI_THREAD */
#endif /* _RWSTD_NO_TEST_AND_SET */
        _RWSTD_MT_INCREMENT(this->__refs_);
      }
    }
    long  __removeReference ()                
    {
      if (this != _RW_STD::basic_string<charT,traits,Allocator>::__getNullRep())
      {
#ifdef _RWSTD_NO_TEST_AND_SET
#ifdef _RWSTD_MULTI_THREAD
#ifdef _RWSTD_ONE_STRING_MUTEX
         _RWSTDGuard guard(__rw_string_mutex);
#else
         _RWSTDGuard guard(this->__mutex_);
#endif
#endif /* _RWSTD_MULTI_THREAD */
#endif /* _RWSTD_NO_TEST_AND_SET */
        return __unSafeRemoveReference();
      }
      else
        return 1;
    }
    long  __unSafeRemoveReference ()                
    {
      if (this != _RW_STD::basic_string<charT,traits,Allocator>::__getNullRep())
      {
        _RWSTD_MT_DECREMENT(this->__refs_);
        return this->__refs_+1;
      }
      else
        return 1;
    }

    size_type length () const
    { return __string_ref_rep<Allocator>::__nchars_; }
    size_type __getCapac () const
    { return __string_ref_rep<Allocator>::__capacity_;}

    charT*    data () const
    {
      return (charT*)(this+1);
    }
    charT&   operator[]     (size_type i)      
    { 
      return (_RWSTD_REINTERPRET_CAST(charT*,(this+1)))[i]; 
    }
    const charT&  operator[]     (size_type i) const
    {
      return ((charT*)(this+1))[i];
    }
#ifndef _RWSTD_NO_NAMESPACE
    friend class std::basic_string<charT, traits, Allocator>;
#else
    friend class basic_string<charT, traits, Allocator>;
#endif
  };
  //
  // __null_string_ref_rep is used to provide a single empty
  // string reference for all instances of empty strings.
  // This makes empty strings much smaller and avoids unecessary
  // allocations of reference objects.
  //

  template <class charT, class traits , class Allocator, 
            class stringRef _RWSTD_COMPLEX_DEFAULT(__string_ref_rep<Allocator>) >
  struct _RWSTDExportTemplate __null_string_ref_rep
  {
    //
    // __ref_hdr_ has to be immediately followed by __eos_char_ !
    //
    stringRef      __ref_hdr_;
    charT          __eos_char_; 

    __null_string_ref_rep ()
      : __ref_hdr_(1), __eos_char_(charT(0)) {;}
    __null_string_ref_rep (const __null_string_ref_rep<charT,traits, 
                                                       Allocator,stringRef>& r)
      : __ref_hdr_(r.__ref_hdr_), __eos_char_(charT(0)) {;}

  };

#ifndef _RWSTD_NO_NAMESPACE
} // End of __rwstd 
#endif

#endif // __STD_STRING_REF

#pragma option pop
#endif /* __STRING_R_H */
