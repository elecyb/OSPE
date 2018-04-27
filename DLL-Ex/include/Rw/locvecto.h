#ifndef __LOCVECTO_H
#define __LOCVECTO_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
#ifndef __LOCALE_VECTOR
#define __LOCALE_VECTOR
/***************************************************************************
 *
 * locvector - Declarations for locales local vector class
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

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifdef __TURBOC__
#pragma option -w-inl
#pragma option -w-par
#endif

// Minute vector class
template <class T>
class locale_vector
{
public:
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
    typedef T value_type;
    typedef T& reference;
    typedef T* pointer;
    typedef T* iterator;

private:
  iterator first_;
  size_type size_;

public:
  locale_vector() : first_(0), size_(0) {;}
  locale_vector(size_type n) : first_(0), size_(n) 
  {
    if (n)
      first_ = new T[n];
  }
  locale_vector(size_type n, const T& v) : first_(0), size_(n) 
  {
    if (n)
      first_ = new T[n];
    while (n)
      first_[--n] = v;
  }
  locale_vector(const locale_vector<T>& lv) : first_(0), size_(0)
  {
    size_type n = size_ = lv.size();
    if (n)
      first_ = new T[n];
    while (n--)
      first_[n] = lv[n];
  }    
  ~locale_vector() { if (first_) delete [] first_;}
  const locale_vector& operator= (const locale_vector& lv) 
  {
    size_type n = size_ = lv.size();
    if (first_)
      delete [] first_;
    if (n)
      first_ = new T[n];
    while (n--)
      first_[n] = lv[n];
    return *this;
  }
  iterator begin() const { return iterator(first_); }
  iterator end() const { return iterator(first_+size_); }    
  size_type size() const { return size_; }

  T& operator[] (size_t i) { return first_[i]; }
  const T& operator[] (size_t i) const { return first_[i]; }

  // Resize array and copy old contents to new buffer. 
  iterator resize(size_t s)
  { 
     return resize(s,T()); 
  }
  iterator resize(size_t s, T v)
  {
    T *new_buf = new T[s];
    iterator j,k;
    size_type d = size_ < s ? size_ : s;

    for (j = first_, k = new_buf; j != first_+d; j++,k++)
      *k =  *j;

    while (d < s)
      new_buf[d++] = v;

    if (first_)
      delete [] first_;    
    first_ = new_buf;
    size_ = s;
    return first_;
  }
};

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif
#endif // __LOCALE_VECTOR

#pragma option pop
#endif /* __LOCVECTO_H */
