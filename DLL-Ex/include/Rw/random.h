#ifndef __RANDOM_H
#define __RANDOM_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * random.h - Header for the Standard Library random generator
 *
 * $Id: random.h,v 1.6 1996/08/28 01:30:28 smithey Exp $
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
#ifdef _RWSTD_MULTI_THREAD
#include <rw/stdmutex.h> 
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

class _RWSTDExport  __random_generator
{
  protected:

    enum { LENGTH = 55 };

    unsigned long table[LENGTH];
    size_t        index1;
    size_t        index2;
#ifdef _RWSTD_MULTI_THREAD
    _RWSTDMutex    mutex;
#endif

    void seed (unsigned long j);

  public:

    unsigned long operator() (unsigned long limit)
    {
#ifdef _RWSTD_MULTI_THREAD
        _RWSTDGuard guard(mutex);
#endif
        index1 = (index1 + 1) % LENGTH;
        index2 = (index2 + 1) % LENGTH;
        table[index1] = table[index1] - table[index2];
        return table[index1] % limit;
    }

    __random_generator (unsigned long j) { this->seed(j); }
   
};

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __RANDOM_H */
