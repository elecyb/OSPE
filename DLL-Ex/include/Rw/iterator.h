#ifndef __RW_ITERATOR_H
#define __RW_ITERATOR_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_RW_ITERATOR__
#define __STD_RW_ITERATOR__

/***************************************************************************
 *
 * iterator - iterator declarations for the Standard Library
 *
 ***************************************************************************
 *
 * Copyright (c) 1994
 * Hewlett-Packard Company
 *
 * Permission to use, copy, modify, distribute and sell this software
 * and its documentation for any purpose is hereby granted without fee,
 * provided that the above copyright notice appear in all copies and
 * that both that copyright notice and this permission notice appear
 * in supporting documentation.  Hewlett-Packard Company makes no
 * representations about the suitability of this software for any
 * purpose.  It is provided "as is" without express or implied warranty.
 *
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
#else
#include <stddef.h>
#endif

#ifdef _RWSTD_NO_BASE_CLASS_MATCH
#define _RWSTD_VALUE_TYPE(a) __value_type(*(a))
#else
#define _RWSTD_VALUE_TYPE(a) __value_type(a)
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

//
// Standard iterator tags.
//
  
  struct input_iterator_tag
  {
    input_iterator_tag() {;}
  };

  struct output_iterator_tag
  {
    output_iterator_tag() {;}
  };

  struct forward_iterator_tag : public input_iterator_tag
  {
    forward_iterator_tag() {;}
  };

  struct bidirectional_iterator_tag : public forward_iterator_tag
  {
    bidirectional_iterator_tag() {;}
  };

  struct random_access_iterator_tag : public bidirectional_iterator_tag
  {
    random_access_iterator_tag() {;}
  };
//
// Basic iterators.
//

//
// Note that _RWSTD_SIMPLE_DEFAULT(x)
// will expand to: ' = x', or nothing,
// depending on your compiler's capabilities and/or
// flag settings (see stdcomp.h).
//
  template <class Category, class T,  
    class Distance _RWSTD_SIMPLE_DEFAULT(ptrdiff_t),
    class Pointer _RWSTD_SIMPLE_DEFAULT(T*),
    class Reference _RWSTD_SIMPLE_DEFAULT(T&)>
  struct iterator
  {
    typedef T value_type;
    typedef Distance difference_type;
    typedef Pointer pointer;
    typedef Reference reference;
    typedef Category iterator_category;
  };

#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC

  template <class Iterator> struct iterator_traits
  {
    typedef _TYPENAME Iterator::value_type value_type;
    typedef _TYPENAME Iterator::difference_type difference_type;
    typedef _TYPENAME Iterator::pointer pointer;
    typedef _TYPENAME Iterator::reference reference;
    typedef _TYPENAME Iterator::iterator_category iterator_category;
  };
  template <class T> struct iterator_traits<T*>
  {
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef T* pointer;
    typedef T& reference;
    typedef random_access_iterator_tag iterator_category;
  };
  template <class T> struct iterator_traits<const T*>
  {
    typedef T value_type;
    typedef ptrdiff_t difference_type;
    typedef const T* pointer;
    typedef const T& reference;
    typedef random_access_iterator_tag iterator_category;
  };

  template <class ForwardIterator>
  inline _TYPENAME iterator_traits<ForwardIterator>::difference_type
  distance (ForwardIterator first, ForwardIterator last)
  {
    _TYPENAME iterator_traits<ForwardIterator>::difference_type n = 0;
    __distance(first, last, n, 
               iterator_traits<ForwardIterator>::iterator_category());
    return n;
  }

  template <class ForwardIterator, class Distance>
  inline void advance (ForwardIterator& i, Distance n)
  {
    __advance(i, n, 
          iterator_traits<ForwardIterator>::iterator_category());
  }

#endif /* _RWSTD_NO_CLASS_PARTIAL_SPEC */

//
// __iterator_category returns the category of an iterator
//

  template <class T>
  inline random_access_iterator_tag 
  __iterator_category (const T*)
  {
    return random_access_iterator_tag();
  }

/*
  template <class T>
  inline _TYPENAME T::iterator_category
  __iterator_category (const T&)
  {
    _TYPENAME T::iterator_category tmp;
    return tmp;
  }
*/
  template <class Category, class T, class Distance, 
            class Pointer, class Reference> 
  inline Category
  __iterator_category (const iterator<Category, T, Distance,Pointer,Reference>&)
  {
    _TYPENAME iterator<Category, T, Distance,T*,T&>::iterator_category tmp;
    return tmp;
  }

//
// Special implementation function for determining whether
// or not we can back up an iterator
//
  template <class _TAG>
  inline bool __is_input_iterator(_TAG)
  { return false; }

  template <class _TAG>
  inline bool __is_bidirectional_iterator(_TAG)
  { return false; }

  template <class _TAG>
  inline bool __is_random_access_iterator(_TAG)
  { return false; }

  inline bool __is_input_iterator(input_iterator_tag)
  { return true; }

  inline bool __is_bidirectional_iterator(bidirectional_iterator_tag)
  { return true; }

  inline bool __is_bidirectional_iterator(random_access_iterator_tag)
  { return true; }

  inline bool __is_random_access_iterator(random_access_iterator_tag)
  { return true; }

//
// __value_type returns the type of value held by an iterator
//
  template <class Category,class T, class Distance,
            class Pointer, class Reference>
  inline T* __value_type (const iterator<Category,T, Distance,Pointer,Reference>&)
  {
    return _RWSTD_STATIC_CAST(T*,0);
  }
/*
  template <class T>
  inline _TYPENAME T::value_type*
  __value_type (const T&)
  {
    return _RWSTD_STATIC_CAST(_TYPENAME T::value_type*,0);
  }
*/
  template <class T>
  inline T* 
  __value_type (const T*)
  {
    return _RWSTD_STATIC_CAST(T*,0);
  }

//
// __distance_type returns the difference type of an iterator
//
  template <class Category,class T, class Distance, 
            class Pointer, class Reference>
  inline Distance* 
  __distance_type (const iterator<Category,T, Distance,Pointer,Reference>&)
  {
    return _RWSTD_STATIC_CAST(Distance*,0);
  }
/*
  template <class T>
  inline _TYPENAME T::difference_type*
  __distance_type(const T&)
  {
    return _RWSTD_STATIC_CAST(_TYPENAME T::difference_type*,0);
  }
*/
  template <class T>
  inline ptrdiff_t* 
  __distance_type (const T*)
  { 
    return _RWSTD_STATIC_CAST(ptrdiff_t*,0);
  }

//
// Implementation specific iterator operations.
//

  template <class InputIterator, class Distance>
  void __advance (InputIterator& i, Distance n, input_iterator_tag);

  template <class ForwardIterator, class Distance>
  void __advance (ForwardIterator& i, Distance n, forward_iterator_tag);

  template <class BidirectionalIterator, class Distance>
  void __advance (BidirectionalIterator& i, Distance n, 
                  bidirectional_iterator_tag);

  template <class InputIterator, class Distance>
  void __distance (InputIterator first, InputIterator last, Distance& n, 
                   input_iterator_tag);

  template <class ForwardIterator, class Distance>
  void __distance (ForwardIterator first, ForwardIterator last, Distance& n, 
                   forward_iterator_tag);

  template <class BidirectionalIterator, class Distance>
  void __distance (BidirectionalIterator first, BidirectionalIterator last, 
                   Distance& n, bidirectional_iterator_tag);

  template <class RandomAccessIterator, class Distance>
  inline void __distance (RandomAccessIterator first, RandomAccessIterator last, 
                          Distance& n, random_access_iterator_tag)
  {
    n = last - first;
  }

  template <class RandomAccessIterator, class Distance>
  inline void __advance (RandomAccessIterator& i, Distance n, 
                         random_access_iterator_tag)
  {
    i += n;
  }

//
// End of implemention specific functions
//

  template <class ForwardIterator, class Distance>
  inline void distance (ForwardIterator first, ForwardIterator last, Distance& n)
  {
#ifndef _RWSTD_NO_BASE_CLASS_MATCH
    __distance(first, last, n, __iterator_category(first));
#else
    __distance(first, last, n, input_iterator_tag());
#endif
  }
#ifdef _RWSTD_NO_CLASS_PARTIAL_SPEC
  template <class ForwardIterator, class Distance>
  inline void advance (ForwardIterator& i, Distance n)
  {
#ifndef _RWSTD_NO_BASE_CLASS_MATCH
    __advance(i, n, __iterator_category(i));
#else
    __advance(i, n, input_iterator_tag());
#endif
  }
#endif /* _RWSTD_NO_CLASS_PARTIAL_SPEC */

//
// Reverse iterator.     
//

//
//  Macros for reverse iterator to accomodate non-standard compilers
//
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
#define _RWSTD_REVERSE_ITERATOR_TEMPLATE template <class Iterator>
#define _RWSTD_REVERSE_ITERATOR_TYPE reverse_iterator<Iterator>
#else
#define _RWSTD_REVERSE_ITERATOR_TEMPLATE \
template <class Iterator, class Category, class T, class Reference,  class Pointer, class Distance>
#define _RWSTD_REVERSE_ITERATOR_TYPE \
 reverse_iterator<Iterator,Category,T,Reference,Pointer,Distance>
#endif
//
// Forward Declarations.
//
#ifdef _RWSTD_NO_UNDEFINED_FRIEND
  _RWSTD_REVERSE_ITERATOR_TEMPLATE class reverse_iterator;

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator== (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_ITERATOR_TYPE& y);

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator< (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                         const _RWSTD_REVERSE_ITERATOR_TYPE& y);

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline 
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
  _TYPENAME iterator_traits<Iterator>::difference_type
#else
  Distance
#endif // _RWSTD_NO_CLASS_PARTIAL_SPEC 
  operator- (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
             const _RWSTD_REVERSE_ITERATOR_TYPE& y);

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline _RWSTD_REVERSE_ITERATOR_TYPE
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
  operator+ (_TYPENAME iterator_traits<Iterator>::difference_type n, 
             const _RWSTD_REVERSE_ITERATOR_TYPE& x);
#else
  operator+ (Distance n, const _RWSTD_REVERSE_ITERATOR_TYPE& x);
#endif // _RWSTD_NO_CLASS_PARTIAL_SPEC 
#endif // _RWSTD_NO_UNDEFINED_FRIEND

#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
  template <class Iterator>
  class reverse_iterator
   : public iterator<typename iterator_traits<Iterator>::iterator_category,
            typename iterator_traits<Iterator>::value_type,
            typename iterator_traits<Iterator>::difference_type,           
            typename iterator_traits<Iterator>::pointer,
            typename iterator_traits<Iterator>::reference>
  {
    typedef reverse_iterator<Iterator> self;
  public:
    typedef typename iterator_traits<Iterator>::difference_type difference_type;
    typedef typename iterator_traits<Iterator>::value_type value_type;
    typedef typename iterator_traits<Iterator>::pointer pointer;
    typedef typename iterator_traits<Iterator>::reference reference;
  private:
#else
  template <class Iterator, class Category, class T, 
            class Reference _RWSTD_COMPLEX_DEFAULT(T&),
            class Pointer _RWSTD_COMPLEX_DEFAULT(T*), 
            class Distance _RWSTD_COMPLEX_DEFAULT(ptrdiff_t) >
  class reverse_iterator
   : public iterator<Category,T, Distance,Pointer,Reference>

  {
    typedef reverse_iterator<Iterator,Category,T,Reference,Pointer,Distance> self;
  public:
    typedef Distance difference_type;
    typedef T value_type;
    typedef Reference reference;
    typedef Pointer pointer;
  private:
#endif
#ifdef __TURBOC__
    friend inline bool (std::operator==)    (const self& x, const self& y);
    friend inline bool (std::operator<)     (const self& x, const self& y);
    friend inline difference_type (std::operator-) (const self& x, const self& y);
    friend inline self (std::operator+)     (difference_type n, const self& x);
#else
    friend inline bool operator==    (const self& x, const self& y);
    friend inline bool operator<     (const self& x, const self& y);
    friend inline difference_type operator- (const self& x, const self& y);
    friend inline self operator+     (difference_type n, const self& x);
#endif        
  protected:

    Iterator current;

  public:
    typedef Iterator iterator_type;

    reverse_iterator() {}
    _EXPLICIT reverse_iterator (Iterator x) : current(x) {}
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
    template <class U>
    reverse_iterator (const reverse_iterator<U>& x) : current(x.base()) {}
#endif
    Iterator base () const { return current; }
    reference operator* () const 
    { Iterator tmp = current; return *--tmp; }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
    pointer operator->() const 
    { reference tmp = operator*(); return (pointer)&tmp; }
#endif

    self& operator++ ()    { --current; return *this;                 }
    self  operator++ (int) { self tmp = *this; --current; return tmp; }
    self& operator-- ()    { ++current; return *this;                 }
    self  operator-- (int) { self tmp = *this; ++current; return tmp; }

    self  operator+  (difference_type n) const 
    {  self tmp(current - n); return tmp; }
    self& operator+= (difference_type n)       { current -= n; return *this;        }
    self  operator-  (difference_type n) const { self tmp(current + n); return tmp; }
    self& operator-= (difference_type n)       { current += n; return *this;        }

    reference operator[] (difference_type n) const { return *(*this + n); }
  };
  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator== (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_ITERATOR_TYPE& y)
  {
    return x.current == y.current;
  }

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator< (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                         const _RWSTD_REVERSE_ITERATOR_TYPE& y)
  {
    return y.current < x.current;
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator!= (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_ITERATOR_TYPE& y)
  {
    return !(x == y);
  }

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator> (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                         const _RWSTD_REVERSE_ITERATOR_TYPE& y)
  {
    return y < x;
  }

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator<= (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_ITERATOR_TYPE& y)
  {
    return !(y < x);
  }

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator>= (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_ITERATOR_TYPE& y)
  {
    return !(x < y);
  }
#endif // _RWSTD_NO_NAMESPACE) || _RWSTD_NO_PART_SPEC_OVERLOAD

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline 
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
  _TYPENAME iterator_traits<Iterator>::difference_type
#else
  Distance
#endif
  operator- (const _RWSTD_REVERSE_ITERATOR_TYPE& x, 
                             const _RWSTD_REVERSE_ITERATOR_TYPE& y)
  {
    return y.current - x.current;
  }

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline _RWSTD_REVERSE_ITERATOR_TYPE
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
  operator+ (_TYPENAME iterator_traits<Iterator>::difference_type n, 
             _RWSTD_REVERSE_ITERATOR_TYPE& x)
#else
  operator+ (Distance n, _RWSTD_REVERSE_ITERATOR_TYPE& x)
#endif
  {
    return _RWSTD_REVERSE_ITERATOR_TYPE(x.current - n);
  }
#ifdef _RWSTD_NO_CLASS_PARTIAL_SPEC
//
// Reverse bidirectional iterator.       
// This is needed to get around non-standard compilers that insist
// on instantiating all members of a class whether they're used 
// or not.
//

//
//  Macros for reverse iterator to accomodate non-standard compilers
//
#define _RWSTD_REVERSE_BI_ITERATOR_TYPE \
 __reverse_bi_iterator<Iterator,Category,T,Reference,Pointer,Distance>
//
// Forward Declarations.
//
#ifdef _RWSTD_NO_UNDEFINED_FRIEND

  _RWSTD_REVERSE_ITERATOR_TEMPLATE class __reverse_bi_iterator;

  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator== (const _RWSTD_REVERSE_BI_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_BI_ITERATOR_TYPE& y);

#endif // _RWSTD_NO_UNDEFINED_FRIEND

  template <class Iterator, class Category, class T, 
            class Reference _RWSTD_COMPLEX_DEFAULT(T&),
            class Pointer _RWSTD_COMPLEX_DEFAULT(T*), 
            class Distance _RWSTD_COMPLEX_DEFAULT(ptrdiff_t) >
  class __reverse_bi_iterator
   : public iterator<Category,T, Distance,Pointer,Reference>

  {
    typedef __reverse_bi_iterator<Iterator,Category,T,Reference,Pointer,Distance> self;
    typedef Distance difference_type;
    typedef T value_type;
    typedef Reference reference;
    typedef Pointer pointer;

    friend inline bool operator==    (const self& x, const self& y);
        
  protected:

    Iterator current;

  public:
    typedef Iterator iterator_type;

    __reverse_bi_iterator() {}
    _EXPLICIT __reverse_bi_iterator (Iterator x) : current(x) {}
#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
    template <class U>
    _EXPLICIT __reverse_bi_iterator (const reverse_iterator<U>) : current(x) {}
#endif
    Iterator base () const { return current; }
    reference operator* () const 
    { Iterator tmp = current; return *--tmp; }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
    pointer operator->() const 
    { reference tmp = operator*(); return (pointer)&tmp; }
#endif

    self& operator++ ()    { --current; return *this;                 }
    self  operator++ (int) { self tmp = *this; --current; return tmp; }
    self& operator-- ()    { ++current; return *this;                 }
    self  operator-- (int) { self tmp = *this; ++current; return tmp; }
  };
  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator== (const _RWSTD_REVERSE_BI_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_BI_ITERATOR_TYPE& y)
  {
    return x.current == y.current;
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  _RWSTD_REVERSE_ITERATOR_TEMPLATE
  inline bool operator!= (const _RWSTD_REVERSE_BI_ITERATOR_TYPE& x, 
                          const _RWSTD_REVERSE_BI_ITERATOR_TYPE& y)
  {
    return !(x == y);
  }

#endif  // _RWSTD_NO_NAMESPACE || _RWSTD_NO_PART_SPEC_OVERLOAD
#endif // _RWSTD_NO_CLASS_PARTIAL_SPEC

//
// Back insert iterator.
//

  template <class Container>
  class back_insert_iterator 
    : public iterator<output_iterator_tag, void, void, void, void>
  {
  protected:

    Container* container;

  public:
    typedef Container container_type;

    _EXPLICIT back_insert_iterator (Container& x) : container(&x) {}
    back_insert_iterator<Container>&
    operator= (const _TYPENAME Container::const_reference value)
    {
      container->push_back(value); return *this;
    }
    back_insert_iterator<Container>& operator*  ()    { return *this; }
    back_insert_iterator<Container>& operator++ ()    { return *this; }
    back_insert_iterator<Container> operator++ (int) { return *this; }
  };

  template <class Container>
  inline back_insert_iterator<Container> back_inserter (Container& x)
  {
    return back_insert_iterator<Container>(x);
  }

//
// Front insert iterator.
//

  template <class Container>
  class front_insert_iterator 
    : public iterator<output_iterator_tag,
                      _TYPENAME Container::value_type,
                      _TYPENAME Container::difference_type,
                      _TYPENAME Container::pointer,
                      _TYPENAME Container::reference> 
  {
  protected:

    Container* container;

  public:
    typedef Container container_type;
    typedef _TYPENAME Container::value_type value_type;

    _EXPLICIT front_insert_iterator (Container& x) : container(&x) {}
    front_insert_iterator<Container>&
    operator= (const _TYPENAME Container::value_type& value)
    { 
      container->push_front(value); return *this;
    }
    front_insert_iterator<Container>& operator*  ()    { return *this; }
    front_insert_iterator<Container>& operator++ ()    { return *this; }
    front_insert_iterator<Container> operator++ (int) { return *this; }
  };

  template <class Container>
  inline front_insert_iterator<Container> front_inserter (Container& x)
  {
    return front_insert_iterator<Container>(x);
  }

//
// Insert iterator.
//

  template <class Container>
  class insert_iterator
    : public iterator<output_iterator_tag,
                      _TYPENAME Container::value_type,
                      _TYPENAME Container::difference_type,
                      _TYPENAME Container::pointer,
                      _TYPENAME Container::reference> 
  {
  private:
    _TYPENAME Container::iterator iter;

  protected:
    Container*                   container;

  public:
    typedef Container container_type;
    typedef _TYPENAME Container::value_type value_type;

    insert_iterator (Container& x, _TYPENAME Container::iterator i)
      : container(&x), iter(i) {}
    insert_iterator<Container>&
    operator= (const _TYPENAME Container::value_type& value)
    { 
      iter = container->insert(iter, value); ++iter; return *this;
    }
    insert_iterator<Container>& operator*  ()    { return *this; }
    insert_iterator<Container>& operator++ ()    { return *this; }
    insert_iterator<Container>& operator++ (int) { return *this; }
  };

  template <class Container, class Iterator>
  inline insert_iterator<Container> inserter (Container& x, Iterator i)
  {
    _TYPENAME Container::iterator c(i);
    insert_iterator<Container> tmp(x, c);
    return tmp;
  }

#ifndef __RW_TRAITS
  template <class charT> struct _RWSTDExportTemplate char_traits;
  _RWSTD_TEMPLATE struct _RWSTDExport char_traits<char>;
#ifndef _RWSTD_NO_WIDE_CHAR
  _RWSTD_TEMPLATE struct _RWSTDExport char_traits<wchar_t>;
#endif
#endif // __RW_TRAITS

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RW_STD_IOSTREAM
//#include <iostream>
#else
#include <iostream.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

#ifndef _RW_STD_IOSTREAM
//
// Stream iterators.
//

#ifdef _RWSTD_NO_UNDEFINED_FRIEND
  template <class T, class charT, class traits, class Distance>
  class istream_iterator;

  template <class T, class charT, class traits, class Distance>
  bool operator== (const istream_iterator<T, charT,traits,Distance>& x,
                   const istream_iterator<T, charT,traits,Distance>& y);
#endif

  template <class T, class charT = char, 
            class traits = char_traits<charT>, 
            class Distance = ptrdiff_t>
  class istream_iterator 
    : public iterator<input_iterator_tag,T,Distance,const T*,const T&>
  {
    friend inline bool operator== (const istream_iterator<T, charT,traits,Distance>& x,
                            const istream_iterator<T, charT,traits,Distance>& y);
  protected:

    istream* stream;
    T        value;
    bool     end_marker;

    void read ()
    {
      end_marker = (*stream) ? true : false;
      if (end_marker) *stream >> value;
      end_marker = (*stream) ? true : false;
    }
  public:
    typedef T value_type;
    typedef charT char_type;
    typedef traits traits_type;
    typedef istream istream_type;

    istream_iterator () : stream(&cin), end_marker(false) {}
    istream_iterator (istream& s) : stream(&s) { read(); }
    istream_iterator ( const istream_iterator<T,charT,traits,Distance>& x )
      :stream(x.stream) , value(x.value) , end_marker(x.end_marker)
    { }
    const T& operator* () const { return value; }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
    const T* operator->() const { return &value; }
#endif
    istream_iterator<T, charT,traits,Distance>& operator++ ()
    { 
      read(); return *this;
    }
    istream_iterator<T, charT,traits,Distance> operator++ (int)
    {
      istream_iterator<T, charT,traits,Distance> tmp = *this; 
      read(); 
      return tmp;
    }
  };

  template <class T, class charT, class traits, class Distance>
  inline bool operator== (const istream_iterator<T, charT,traits,Distance>& x,
                          const istream_iterator<T, charT,traits,Distance>& y)
  {
    return x.stream == y.stream && x.end_marker == y.end_marker ||
    x.end_marker == false && y.end_marker == false;
  }

#if !defined(_RWSTD_NO_NAMESPACE) || !defined(_RWSTD_NO_PART_SPEC_OVERLOAD)
  template <class T, class charT, class traits, class Distance>
  inline bool operator!= (const istream_iterator<T, charT,traits,Distance>& x,
                          const istream_iterator<T, charT,traits,Distance>& y)
  {
    return !(x == y);
  }
#endif

#ifndef _RWSTD_NO_COMPLEX_DEFAULT_TEMPLATES
  template <class T, class charT = char, 
  class traits = char_traits<charT> >
#else
  template <class T, class charT, class traits>
#endif
  class ostream_iterator : public iterator<output_iterator_tag,T,ptrdiff_t,T*,T&>
  {
  protected:

    ostream* stream;
    const char*    str;

  public:
    typedef T value_type;
    typedef charT char_type;
    typedef traits traits_type;
    typedef ostream istream_type;

    ostream_iterator (ostream& s) : stream(&s), str(0) { ; }
    ostream_iterator (ostream& s,const char* c) 
      : stream(&s), str((char *)c)  { ; }
    ostream_iterator ( const ostream_iterator<T,charT,traits>& x )
      :stream(x.stream) , str(x.str)
    { ; }
    ostream_iterator<T,charT,traits>& operator= (const T& value)
    { 
      *stream << value;
      if (str) *stream << str;
      return *this;
    }
    ostream_iterator<T,charT,traits>& operator*  ()    { return *this; }
    ostream_iterator<T,charT,traits>& operator++ ()    { return *this; } 
    ostream_iterator<T,charT,traits>& operator++ (int) { return *this; }
  };

#endif /* _RW_STD_IOSTREAM */
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_NO_TEMPLATE_REPOSITORY
#include <rw/iterator.cc>
#endif

#endif /* __STD_RW_ITERATOR__ */

#pragma option pop
#endif /* __RW_ITERATOR_H */
