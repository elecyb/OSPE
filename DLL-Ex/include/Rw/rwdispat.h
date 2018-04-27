#ifndef __RWDISPAT_H
#define __RWDISPAT_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * rwdispatch.h - functions used for method selection in containers
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

#ifndef __RWDISPATCH__
#define __RWDISPATCH__

template <class _T>
inline bool _RW_is_integral_type(_T)
{ return false; }

inline bool _RW_is_integral_type(int)
{ return true; }

inline bool _RW_is_integral_type(unsigned int)
{ return true; }

inline bool _RW_is_integral_type(short)
{ return true; }

inline bool _RW_is_integral_type(unsigned short)
{ return true; }

inline bool _RW_is_integral_type(long)
{ return true; }

inline bool _RW_is_integral_type(unsigned long)
{ return true; }

inline bool _RW_is_integral_type(char)
{ return true; }

inline bool _RW_is_integral_type(unsigned char)
{ return true; }

#ifndef _RWSTD_NO_BOOL
inline bool _RW_is_integral_type(bool)
{ return true; }
#endif

#ifndef _RWSTD_NO_OVERLOAD_WCHAR
inline bool _RW_is_integral_type(wchar_t)
{ return true; }
#endif

struct _RW_is_integer {};
struct _RW_is_not_integer {};

template <class _T>
struct _RWdispatch {
  typedef _RW_is_not_integer _RWtype;
};

_RWSTD_TEMPLATE
struct _RWdispatch<int> {
  typedef _RW_is_integer _RWtype;
};

_RWSTD_TEMPLATE
   struct _RWdispatch<unsigned int> {
	typedef _RW_is_integer _RWtype;
};

_RWSTD_TEMPLATE
   struct _RWdispatch<long> {
	typedef _RW_is_integer _RWtype;
};

_RWSTD_TEMPLATE
   struct _RWdispatch<unsigned long> {
	typedef _RW_is_integer _RWtype;
};

_RWSTD_TEMPLATE
   struct _RWdispatch<short> {
	typedef _RW_is_integer _RWtype;
};

_RWSTD_TEMPLATE
   struct _RWdispatch<unsigned short> {
	typedef _RW_is_integer _RWtype;
};

_RWSTD_TEMPLATE
   struct _RWdispatch<char> {
	typedef _RW_is_integer _RWtype;
};

_RWSTD_TEMPLATE
   struct _RWdispatch<unsigned char> {
	typedef _RW_is_integer _RWtype;
};

#ifndef _RWSTD_NO_BOOL
_RWSTD_TEMPLATE
   struct _RWdispatch<bool> {
	typedef _RW_is_integer _RWtype;
};
#endif

#ifndef _RWSTD_NO_OVERLOAD_WCHAR
_RWSTD_TEMPLATE
   struct _RWdispatch<wchar_t> {
	typedef _RW_is_integer _RWtype;
};
#endif

#endif //__RWDISPATCH__

#pragma option pop
#endif /* __RWDISPAT_H */
