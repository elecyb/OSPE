#ifndef __LOCHELP_H
#define __LOCHELP_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * rw/lochelp - Declarations for the Standard Library locale helper classes.
 *
 * $Id: lochelp,v 1.5 1996/10/02 01:48:00 smithey Exp $
 *
 * This header defines some classes that are used by some of the source (cpp)
 * files in src/locale, mainly for manipulating the C library locale.  This
 * header is not included by any other header, and never ends up in user code.
 * See locale.cpp for implementation.
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

#ifndef __STD_RW_LOCHELP__
#define __STD_RW_LOCHELP__

#ifndef _RWSTD_NO_NEW_HEADER
#include <clocale>
#else
#include <locale.h>
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

// ------------------------------------------------
// Implementation helper class -- use_Clib_locale.
// ------------------------------------------------

class _RWSTDExport use_Clib_locale {
  int saved_cat;
  char *previous_locale_name;
 public:
  use_Clib_locale (const char *name=NULL,int cat=LC_ALL);
 ~use_Clib_locale (void);

  operator bool (void) const { return previous_locale_name!=NULL; }
};

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd
#endif

#endif // __STD_RW_LOCHELP__
#pragma option pop
#endif /* __LOCHELP_H */
