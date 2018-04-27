#ifndef __VENDOR_H
#define __VENDOR_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * vendor -- Vendor-supplied declarations for the Standard Library locale
 *           classes.
 *
 * $Id: vendor,v 1.10 1996/10/02 01:48:00 smithey Exp $
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
 ***************************************************************************
 *
 *
 **************************************************************************/

#ifndef __STD_LOC_VENDOR
#define __STD_LOC_VENDOR

#include <rw/ctype>
#include <rw/numeral>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

// --------------------------------------------------------
// Implementation function template -- create_native_facet.
// --------------------------------------------------------

// Vendors must specialize this inline function template for each facet of the
// vendor-default native ("") locale that is different from the same facet of
// the classic locale.  Each specialization should construct and return a new
// instance of the requested native-behavior facet with an initial reference
// count of 1 (not the default 0!).

// Note that a specialization for ctype<char> must always be provided, because
// ctype<char> lacks a constructor with the signature used in the template.

inline _RW_STD::ctype<char>* create_native_facet (_RW_STD::ctype<char>*) {
  return new _RW_STD::ctype<char>(NULL,false,1);
}

inline _RW_STD::numpunct<char>* create_native_facet (_RW_STD::numpunct<char>*) {
  return new _RW_STD::numpunct_byname<char>("",1);
}

// The default template function for Facets not specialized above returns a
// facet with classic-locale behavior.

template <class Facet>
inline Facet* create_native_facet (Facet*) {
  return create_named_facet((Facet*)0,"",(size_t)1);
}

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // __STD_LOC_VENDOR

#pragma option pop
#endif /* __VENDOR_H */
