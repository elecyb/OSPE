#ifndef __RWSTDERR_H
#define __RWSTDERR_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
#ifndef __STD_RWSTDERR_H
#define __STD_RWSTDERR_H
/**************************************************************************
 *
 * Declarations for class _RWSTDExport
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
 ***************************************************************************/

#include <stdcomp.h>
#include <rw/stddefs.h> 
#include <stdarg.h>
#include <rw/rwstderr_macros.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#define _RWSTD_ERROR_BUFSIZE 240

  class _RWSTDExport except_msg_string
    {
    public:
    except_msg_string(const char* ...);
    except_msg_string(unsigned int ...);
    const char* msgstr() const {return __msg;}
    private:
    except_msg_string(const except_msg_string&);
    except_msg_string& operator=(const except_msg_string&);
    char __msg[_RWSTD_ERROR_BUFSIZE];
    };

#ifndef _RWSTD_NO_NAMESPACE
} // __rwstd
#endif
         
#endif// __STD_RWSTDERR_H
#pragma option pop
#endif /* __RWSTDERR_H */
