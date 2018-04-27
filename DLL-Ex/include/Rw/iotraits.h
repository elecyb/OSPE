#ifndef __IOTRAITS_H
#define __IOTRAITS_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __RWSTD_IOTRAITS
#define __RWSTD_IOTRAITS
/***************************************************************************
 *
 * iotraits - Declarations for traits 
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

#include <iosfwd>
#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  /*
   * Class mbstate_t
   */

#ifdef _RWSTD_NO_MBSTATE_T
  struct _RWSTDExport mbstate_t
  { 
    mbstate_t( long state=0 ) 
      : __mbstate(state) { ; }

    mbstate_t(const mbstate_t& state) 
      : __mbstate(state.__mbstate) { ; }
              
    mbstate_t& operator=(const mbstate_t& state)
    {
      if ( &state != this )
        __mbstate= state.__mbstate;              
      return *this;
    }

    mbstate_t& operator=(const long state)
    {
      __mbstate= state;              
      return *this;
    } 

    bool operator==(const mbstate_t& state) const
    {
      return ( __mbstate == state.__mbstate );
    }

    bool operator!=(const mbstate_t& state) const
    {
      return ( !(__mbstate == state.__mbstate) );
    }
                   
    long __mbstate;                
  };          

#endif // _RWSTD_NO_MBSTATE_T 

  /*
   * Class fpos
   */

  /* It maintains all the information necessary to restore an arbitrary
   * sequence, controlled by the Standard C++ library, to a previous stream
   * position and conversion state.
   */

  template <class stateT>
  class _RWSTDExportTemplate fpos
  {
  public:
    //
    // Types:
    //
    typedef stateT  state_type;
      
    inline fpos(long off = 0);

#ifdef _RWSTD_NO_MBSTATE_T
    inline _EXPLICIT fpos(state_type);
#endif
    inline operator long() const;

    inline fpos(const fpos<stateT>&);
    inline fpos<stateT>& operator= (const fpos<stateT>&);

    inline state_type   state () const;
    inline state_type   state (state_type);

    inline fpos<stateT>& operator+=(const fpos<stateT> &off);
    inline fpos<stateT>  operator+(const fpos<stateT> &off) const;

    inline fpos<stateT>& operator-=(const fpos<stateT> &off);
    inline fpos<stateT>  operator-(const fpos<stateT> &off) const;

    inline fpos<stateT>& operator+=(int off);
    inline fpos<stateT>  operator+(int off) const;

    inline fpos<stateT>& operator-=(int off);
    inline fpos<stateT>  operator-(int off) const;

    inline fpos<stateT>& operator+=(long off);
    inline fpos<stateT>  operator+(long off) const;

    inline fpos<stateT>& operator-=(long off);
    inline fpos<stateT>  operator-(long off) const;

    inline bool operator==(const fpos<stateT>& rhs) const;
    inline bool operator!=(const fpos<stateT>& rhs) const;

    inline bool operator< (const fpos<stateT>& rhs) const;
    inline bool operator> (const fpos<stateT>& rhs) const;

    inline bool operator<= (const fpos<stateT>& rhs) const;
    inline bool operator>= (const fpos<stateT>& rhs) const;

    inline bool operator==(const int& rhs) const;
    inline bool operator!=(const int& rhs) const;

    inline bool operator< (const int& rhs) const;
    inline bool operator> (const int& rhs) const;

    inline bool operator<= (const int& rhs) const;
    inline bool operator>= (const int& rhs) const;

    inline bool operator==(const long& rhs) const;
    inline bool operator!=(const long& rhs) const;

    inline bool operator< (const long& rhs) const;
    inline bool operator> (const long& rhs) const;

    inline bool operator<= (const long& rhs) const;
    inline bool operator>= (const long& rhs) const;
                      
  private:

    long               __pos;     // signed displacement
    state_type         __state;   // conversion state
    bool               __status;  // status
  };
  /*
   *     Class fpos member functions
   */

  /*
   * fpos(long)
   */

  template <class stateT>
  inline
  fpos<stateT>::fpos(long off)
  : __pos(off)
  , __state(stateT()) 
  , __status(true)
  {
    if ( off == -1 ) __status = false;
  }

  /*
   * fpos(stateT)
   */

#ifdef _RWSTD_NO_MBSTATE_T
  template <class stateT>
  inline
  fpos<stateT>::fpos(stateT state)
  : __pos(0)
  , __state(state)
  , __status(true)
  {;}
#endif // _RWSTD_NO_MBSTATE_T 

  /*
   * fpos(const fpos&)
   */

  template <class stateT> 
  inline
  fpos<stateT>::fpos(const fpos<stateT>& str_pos)
  {
    __pos   = str_pos.__pos;
    __state = str_pos.__state;
    __status = str_pos.__status;      
  }

  /*
   * state_type state(state_type)
   */

  template <class stateT>
  inline _TYPENAME fpos<stateT>::state_type 
  fpos<stateT>::state(state_type state)
  {
    state_type var=__state; 
    __state = state;
    return var;
  }

  /*
   * operator long ( )
   */
 
  template <class stateT>
  inline fpos<stateT>::operator long() const
  {
    return (long) __pos;
  }

  /*
   * fpos& operator=(const fpos&)
   */

  template <class stateT>
  inline fpos<stateT>& 
  fpos<stateT>::operator=(const fpos<stateT>& str_pos)
  {
    if ( &str_pos != this )
    {
      __pos    = str_pos.__pos;
      __state  = str_pos.__state;
      __status = str_pos.__status;
    }
    return *this;
  }

  /*
   * state_type state() const
   */

  template <class stateT>
  inline _TYPENAME fpos<stateT>::state_type 
  fpos<stateT>::state() const
  {
    return __state;
  }
 
  /*
   * fpos& operator+=(const fpos&)
   */

  template <class stateT>
  inline fpos<stateT>& 
  fpos<stateT>::operator+=(const fpos<stateT>& off)
  {
    __pos += off.__pos;
    return *this;
  }

  /*
   * fpos operator+(const fpos&) const
   */

  template <class stateT>
  inline fpos<stateT> 
  fpos<stateT>::operator+(const fpos<stateT>& off) const
  {
    fpos<stateT> temp(*this);
    temp.__pos += off.__pos; 
    return temp;
  }

  /*
   * fpos operator-(const fpos<stateT>& off) const
   */

  template <class stateT>
  inline fpos<stateT> 
  fpos<stateT>::operator-(const fpos<stateT>& off) const
  {
    fpos<stateT> temp(*this);
    temp.__pos -= off.__pos; 
    return temp;
  }

  /*
   * fpos& operator-=(const fpos&)
   */

  template <class stateT>
  inline fpos<stateT>& 
  fpos<stateT>::operator-=(const fpos<stateT>& off)
  {
    __pos -= off.__pos;
    return *this;
  }

  /*
   * fpos& operator+=(int)
   */

  template <class stateT>
  inline fpos<stateT>& 
  fpos<stateT>::operator+=(int off)
  {
    __pos += off;
    return *this;
  }

  /*
   * fpos operator+(int) const
   */

  template <class stateT>
  inline fpos<stateT> 
  fpos<stateT>::operator+(int off) const
  {
    fpos<stateT> temp(*this);
    temp.__pos += off; 
    return temp;
  }

  /*
   * fpos operator-(int off) const
   */

  template <class stateT>
  inline fpos<stateT> 
  fpos<stateT>::operator-(int off) const
  {
    fpos<stateT> temp(*this);
    temp.__pos -= off; 
    return temp;
  }

  /*
   * fpos& operator-=(int)
   */

  template <class stateT>
  inline fpos<stateT>& 
  fpos<stateT>::operator-=(int off)
  {
    __pos -= off;
    return *this;
  }

  /*
   * fpos& operator-=(long)
   */

  template <class stateT>
  inline fpos<stateT>& 
  fpos<stateT>::operator-=(long off)
  {
    __pos -= off;
    return *this;
  }

  /*
   * fpos operator-(long off) const
   */

  template <class stateT>
  inline fpos<stateT> 
  fpos<stateT>::operator-(long off) const
  {
    fpos<stateT> temp(*this);
    temp.__pos -= off; 
    return temp;
  }

  /*
   * fpos& operator+=(long)
   */

  template <class stateT>
  inline fpos<stateT>& 
  fpos<stateT>::operator+=(long off)
  {
    __pos += off;
    return *this;
  }

  /*
   * fpos operator+(long) const
   */

  template <class stateT>
  inline fpos<stateT> 
  fpos<stateT>::operator+(long off) const
  {
    fpos<stateT> temp(*this);
    temp.__pos += off; 
    return temp;
  }
 
  /*
   * bool operator==(const fpos&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator==(const fpos<stateT>& pos) const
  { 
    if ( !(__status || pos.__status) ) return true;
    return ( ( __pos == pos.__pos ) 
#ifndef _RWSTD_NO_MBSTATE_COMPARE
             && ( __state == pos.__state )
#endif 
             &&  ( __status == pos.__status ) );
  }

  /*
   * bool operator!=(const fpos&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator!=(const fpos<stateT>& pos) const
  {
    return !(*this == pos);
  }

  /*
   * bool operator< (const fpos&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator< (const fpos<stateT>& pos) const
  {
    return ( __pos < pos.__pos );
  }

  /*
   * bool operator> (const fpos&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator> (const fpos<stateT>& pos) const
  {
    return ( __pos > pos.__pos );
  }

  /*
   * bool operator<= (const fpos&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator<= (const fpos<stateT>& pos) const
  {
    return ( __pos <= pos.__pos );
  }

  /*
   * bool operator>= (const fpos&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator>= (const fpos<stateT>& pos) const
  {
    return ( __pos >= pos.__pos );
  }

  /*
   * bool operator==(const int&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator==(const int& pos) const
  { 
    return (  __pos == pos );
  }

  /*
   * bool operator!=(const int&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator!=(const int& pos) const
  {
    return !(*this == pos);
  }

  /*
   * bool operator< (const int&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator< (const int& pos) const
  {
    return ( __pos < pos );
  }

  /*
   * bool operator> (const int&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator> (const int& pos) const
  { 
    return ( __pos > pos );
  }

  /*
   * bool operator<= (const int&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator<= (const int& pos) const
  { 
    return ( __pos <= pos );
  }

  /*
   * bool operator>= (const int&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator>= (const int& pos) const
  {
    return ( __pos >= pos );
  }

  /*
   * bool operator==(const long&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator==(const long& pos) const
  { 
    return (  __pos == pos );
  }

  /*
   * bool operator!=(const long&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator!=(const long& pos) const
  {
    return !(*this == pos);
  }

  /*
   * bool operator< (const long&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator< (const long& pos) const
  {
    return ( __pos < pos );
  }

  /*
   * bool operator> (const long&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator> (const long& pos) const
  { 
    return ( __pos > pos );
  }

  /*
   * bool operator<= (const long&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator<= (const long& pos) const
  { 
    return ( __pos >= pos );
  }

  /*
   * bool operator>= (const long&) const
   */

  template <class stateT>
  inline bool 
  fpos<stateT>::operator>= (const long& pos) const
  {
    return ( __pos <= pos );
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif // __RWSTD_IOTRAITS
#pragma option pop
#endif /* __IOTRAITS_H */
