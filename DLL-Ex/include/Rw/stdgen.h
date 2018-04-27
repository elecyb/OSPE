#ifndef __RWSTDGENERIC_H__
#define __RWSTDGENERIC_H__
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig

/***************************************************************************
 *
 * stdgen.h - Standardizes what various compilers see of the generic.h
 *    facility
 *
 * $Id: stdgen.h,v 7.5 1995/08/14 22:30:13 smithey Exp $
 *
 ***************************************************************************
 *
 * (c) Copyright 1994, 1995 Rogue Wave Software, Inc.
 * ALL RIGHTS RESERVED *
 * The software and information contained herein are proprietary to, and
 * comprise valuable trade secrets of, Rogue Wave Software, Inc., which
 * intends to preserve as trade secrets such software and information.
 * This software is furnished pursuant to a written license agreement and
 * may be used, copied, transmitted, and stored only in accordance with
 * the terms of such license and with the inclusion of the above copyright
 * notice.  This software and information or any other copies thereof may
 * not be provided or otherwise made available to any other person.
 *
 * Notwithstanding any other lease or license that may pertain to, or
 * accompany the delivery of, this computer software and information, the
 * rights of the Government regarding its use, reproduction and disclosure
 * are as set forth in Section 52.227-19 of the FARS Computer
 * Software-Restricted Rights clause.
 * 
 * Use, duplication, or disclosure by the Government is subject to
 * restrictions as set forth in subparagraph (c)(1)(ii) of the Rights in
 * Technical Data and Computer Software clause at DFARS 252.227-7013.
 * Contractor/Manufacturer is Rogue Wave Software, Inc.,
 * P.O. Box 2328, Corvallis, Oregon 97339.
 *
 * This computer software and information is distributed with "restricted
 * rights."  Use, duplication or disclosure is subject to restrictions as
 * set forth in NASA FAR SUP 18-52.227-79 (April 1985) "Commercial
 * Computer Software-Restricted Rights (April 1985)."  If the Clause at
 * 18-52.227-74 "Rights in Data General" is specified in the contract,
 * then the "Alternate III" clause applies.
 *
 **************************************************************************/

#include "rw/defs.h"

#if defined(__ZTC__) && !defined(THINK_CPLUS)
#  include <generic.hpp>
#else
#  ifdef __GLOCK__
#    include <generic.hxx>
#  else
#    if defined(_MSC_VER) || defined(__GNUC__) 	/* Microsoft C/C++ or GNU? */
#      define NO_NATIVE_GENERIC_H 1
#    else
#      include <generic.h>
#    endif
#  endif
#endif


#ifdef NO_NATIVE_GENERIC_H

/*
 * If the compiler did not supply a generic.h, then we will have to
 * do so:
 *
 * Here is the functionality we need:
 *
 *  MACROS:
 **   name2(one,Two)  (we use the name2 macro directly)
 *       result: oneTwo
 **   declare(Class,type)
 *       result: Classdeclare(type)
 **   implement(Class,type)
 *       result: Classimplement(type)
 **   callerror(Class,type,intarg,charsplatarg)
 *       result: (*errorhandler(Class,type))(intarg,charsplatarg)
 **   set_handler(Class,type,handlerRetType)
 *       result: set_typeClass_handler(handlerRetType)
 *    errorhandler(Class,type)
 *       result: typeClasshandler
 *  Declarations and typedefs:
 *    extern genericerror(int,char*)
 *    typedef int(*GPT)(int,char)
 */

extern rwexport genericerror(int,char*);
typedef int (*GPT)(int,char*);

#define name2(a,b) _rwname2(a,b) /* to force the args to be evaluated here */
#define _rwname2(a,b) a##b
#define name3(a,b,c) _rwname3(a,b,c)
#define _rwname3(a,b,c) a##b##c
#define name4(a,b,c,d) _rwname4(a,b,c,d)
#define _rwname4(a,b,c,d) a##b##c##d

#define declare(Class,type)     name2(Class,declare)(type)
#define implement(Class,type)   name2(Class,implement)(type)
#define callerror(Class,type,iarg,csarg) \
	       (*errorhandler(Class,type))(iarg,csarg)
#define set_handler(Class,type,hrt) name4(set_,type,Class,_handler)(hrt)
#define errorhandler(Class,type) name3(type,Class,handler)

#undef NO_NATIVE_GENERIC_H

#endif // NO_NATIVE_GENERIC_H

#pragma option pop
#endif // __RWSTDGENERIC_H__
