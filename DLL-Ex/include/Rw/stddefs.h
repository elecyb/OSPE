#ifndef __STDDEFS_H
#define __STDDEFS_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
#ifndef __RWSTDDEFS_H__
#define __RWSTDDEFS_H__

/***************************************************************************
 *
 * stddefs.h - Common definitions
 *
 * $Id: stddefs.h,v 1.19 1996/09/24 19:18:09 smithey Exp $
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

# include <stdcomp.h> 	/* Set compiler-specific flags */

STARTWRAP
#ifndef _RWSTD_NO_NEW_HEADER
#include <cstddef>		/* Looking for size_t */
#else
#include <stddef.h>		/* Looking for size_t */
#endif
ENDWRAP

#define	_RWSTDNIL	-1L

#ifndef _RWSTD_NO_NEW_HEADER
#ifndef _RWSTD_NO_NAMESPACE
using std::size_t;
using std::ptrdiff_t;
#endif
#endif

//
// Macro for determining the number of bits in a word.
// Used by vector<bool>.
//
#define _RWSTD_WORD_BIT (int(CHAR_BIT*sizeof(unsigned int)))  
  
/*
 *     W I N D O W S - S P E C I F I C   C O D E
 *
 * Enable or disable, as necessary, for Microsoft Windows
 */
#if defined(__WIN32__) || defined (__WIN16__) 
#  include <rw/stdwind.h> 
#else
   /* Disable Windows hacks if we are not compiling for Windows: */
#  define _RWSTDExport
#  define _RWSTDExportTemplate
#  define _RWSTDExportFunc(ReturnType) ReturnType
#  define _RWSTDExportTemplate
#  define _RWSTDExportStatic
#endif

#if !defined(_MSC_VER) || defined(__BORLANDC__)
#define _RWSTDGExport _RWSTDExport
#else
#define _RWSTDGExport
#endif
/*************************************************************************
**************************************************************************
**									**
**		From here on, it's pretty much boilerplate		**
**		and rarely requires any tuning.				**
**									**
**************************************************************************
**************************************************************************/

/*
 *     D E B U G G I N G
 *
 * Use -D_RWSTDDEBUG to compile a version of the libraries to debug
 * the user's code.  This will perform pre- and post-condition checks
 * upon entering routines, but will be larger and run more slowly.
 *
 * Use -D_RWMEMCK to add memory checking software.
 *
 * VERY IMPORTANT!  *All* code must be compiled with the same flag.
 */

#if defined(RDEBUG) && !defined(_RWSTDDEBUG)
#  define _RWSTDDEBUG 1
#endif

#if defined(_RWSTDDEBUG)
#  ifndef _RWSTDBOUNDS_CHECK
#    define _RWSTDBOUNDS_CHECK 1	/* Turn on bounds checking when debugging. */
#  endif
STARTWRAP
#ifndef _RWSTD_NO_NEW_HEADER
#  include <cassert>
#else
#  include <assert.h>
#endif
ENDWRAP
#  define _RWSTDPRECONDITION(a)	assert( (a) != 0 ) /* Check pre- and post-conditions */
#  define _RWSTDPOSTCONDITION(a)	assert( (a) != 0 )
#ifdef _RWSTD_NO_NESTED_QUOTES
#  define _RWSTDPRECONDITION2(a,b)	assert( (a) != 0 )
#  define _RWSTDPOSTCONDITION2(a,b)	assert( (a) != 0 )
#else
#  define _RWSTDPRECONDITION2(a,b)	assert((b, (a) !=0))
#  define _RWSTDPOSTCONDITION2(a,b)	assert((b, (a) !=0))
#endif
#  define _RWSTDASSERT(a)		assert( (a) != 0 )
#else
#  define _RWSTDPRECONDITION(a)
#  define _RWSTDPOSTCONDITION(a)
#  define _RWSTDPRECONDITION2(a,b)
#  define _RWSTDPOSTCONDITION2(a,b)
#  define _RWSTDASSERT(a)
#endif

/*
 * The following allows getting the declaration for RTL classes
 * right without having to include the appropriate header file
 * (in particular, istream & ostream).
 */
#ifdef __TURBOC__
#  include <_defs.h>	/* Looking for _CLASSTYPE */
#  define _RWSTDCLASSTYPE _CLASSTYPE
#else
#  define _RWSTDCLASSTYPE
#endif

/* No RCS for MS-DOS (it has enough memory problems already!): */
#ifdef __MSDOS__
#define RCSID(a)
#define _RW_RCSID(a)
#else
#define RCSID(a) static const char rcsid[] = a
#define _RWSTD_RCSID(a) static const char rcsid[] = a
#endif

#ifdef __cplusplus

const size_t _RWSTD_NPOS            = ~(size_t)0;

#ifndef _RW_STD_IOSTREAM
class _RWSTDCLASSTYPE istream;
class _RWSTDCLASSTYPE ostream;
class _RWSTDCLASSTYPE ios;
#endif

#ifdef _RWSTD_MULTI_THREAD
class _RWSTDMutex;
#endif

#ifdef _RWSTD_NO_FRIEND_INLINE_DECL
#  define _RWSTD_INLINE_FRIEND friend
#else
#  define _RWSTD_INLINE_FRIEND inline friend
#endif
#endif // if C++

#endif // __RWSTDDEFS_H__

#pragma option pop
#endif /* __STDDEFS_H */
