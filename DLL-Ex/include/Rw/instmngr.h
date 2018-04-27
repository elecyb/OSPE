#ifndef __INSTMNGR_H
#define __INSTMNGR_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
#ifndef _RWSTD_INSTANCE_MNGR
#define _RWSTD_INSTANCE_MNGR
/***************************************************************************
 *
 * instmngr.h - Header for the Standard Library DLL Instance Manager
 *              For WIN16 on Borland 5.0
 *
 * $Id: instmngr.h,v 1.3 1996/08/28 01:29:59 smithey Exp $
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

unsigned long _RWSTDExport getDLLRandom(unsigned long limit);
#endif 

#pragma option pop
#endif /* __INSTMNGR_H */
