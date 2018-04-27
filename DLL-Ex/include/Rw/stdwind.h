#ifndef __STDWIND_H
#define __STDWIND_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
#ifndef __RWSTDWIND_H__
#define __RWSTDWIND_H__

/***************************************************************************
 *
 * stdwind.h - Microsoft Windows related directives.
 *
 * $Id: stdwind.h,v 1.19 1996/09/24 19:42:16 smithey Exp $
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

/*
 * Special stuff for 16-bit Windows (__WIN16__)
 * and Windows NT / Win32s (__WIN32__).
 *
 * Under Windows, these header files can be used in two different modes:
 * as part of a DLL, or as part of a regular (static) library.
 * For each of these two ways, we can either be COMPILING the library,
 * or USING the library.  This makes a matrix of four possible situations.
 *
 *************************************************************************
 ******************************  DLL *************************************
 *************************************************************************
 *
 *                         Creating a DLL
 *
 * The macro __DLL__ should be define when compiling to create a DLL.
 *
 *     The Borland compilers automatically do this if either the -WD or
 *     -WDE switch is being used.  In this situation, the macro
 *     _RWSTDExport expands to _export.
 *
 *     For other compilers, we must define __DLL__ where appropriate
 *     if the compiler doesn't.  See the example for Microsoft below.
 *
 *     _RWSTDExport expands to _export by default.  Massage as
 *     necessary for your compiler; again see below for the Microsoft
 *     specific directives.
 *
 *                       Using the resultant DLL
 *
 * In order to use the resultant DLL, you must define the macro _RWSTDDLL
 * when compiling.  This will communicate to the Rogue Wave header files
 * your intention to use a DLL version of the Rogue Wave library.
 *
 * If you intend to use a DLL version of the Borland RTL as well, then you
 * should also define the macro _RTLDLL, as per Borland's instructions.
 *
 * You must also specify the -WS switch ("smart callbacks") for the 
 * Borland Compiler.
 *
 *
 *************************************************************************
 ***********************  Static Windows Library **************************
 *************************************************************************
 *
 *
 *                Creating a _RW static Windows library
 *
 * If your intention is to create a Rogue Wave library to be used as 
 * as a static Windows library, then one of the macros __WIN16__ or __WIN32__
 * must have been defined in compiler.h (or by the compiler directly).
 *
 * Borland:	__WIN16__ will be defined if both _Windows and __MSDOS__ 
 *              is defined.  _Windows will be defined automatically if 
 *              any -W switch is used.  Borland defines __WIN32__ automatically
 *              in their 32-bit compiler for Windows NT / Win32s.
 *
 * Microsoft:	Microsoft automatically defines _WINDOWS if you use the
 *		/GA (preferred) or /GW switch. 
 *              __WIN32__ will only be defined if either it, or WIN32,
 *              is _EXPLICITly defined on the cl command line.
 *
 * 
 *                 Using a _RW static Windows library
 *
 * Nothing special needs to be done.  Just link compile with the appropriate
 * compile switches and link in the _RW static Windows library.
 *
 */
/*
 * Check for Microsoft C/C++ and massage as necessary.
 */
#if defined(_MSC_VER)
#  if defined(_WINDLL) && !defined(__DLL__)
#    define __DLL__ 1
#  endif
#  if !defined(_export)
#    define _export __export
#  endif
#endif

#ifdef  __TURBOC__
#  if __TURBOC__ > 0x468
#    define _RWSTD_EXPORT_TEMPLATE
#  endif
#endif
/* For backwards compatibility: */
#if defined(_RWSTDCLASSDLL) && !defined(_RWSTDDLL)
# define _RWSTDDLL 1
#endif

#if defined(_RWSTDDLL)
#  if !defined(__LARGE__) && !defined(__WIN32__)
#    error   Must use large or flat memory model when compiling or using the Standard Library DLL!
#  endif
#  if defined(_MSC_VER) || ( defined(__TURBOC__) && __TURBOC__ >= 0x0530 )
#    define _RWSTD_USE_DECLSPEC
#  endif
#  if defined(_RWSTDBUILDDLL)
     // Compiling the DLL.
#    ifndef _RWSTD_USE_DECLSPEC
#      define _RWSTDExport __declspec(dllexport)    /* Mark classes as exported */
#      if defined (__WIN16__)
#        define _RWSTDHuge huge
#      else
#        define _RWSTDHuge
#      endif
#      ifdef _RWSTD_EXPORT_TEMPLATE
#        define _RWSTDExportTemplate  __declspec(dllexport)	/* Mark template insts as exported */
#      else
#        define _RWSTDExportTemplate 
#      endif
#    else /* Microsoft and recent Borland: */
#      define _RWSTDExport __declspec(dllexport)
#ifdef __BORLANDC__
#      define _RWSTDExportTemplate __declspec(dllexport)
#else
#      define _RWSTDExportTemplate
#endif
#      define _RWSTDHuge
#    endif
#  else
     // Using the DLL.
#    if defined(__WIN16__)
#      define _RWSTDExport huge 	/* Mark classes as huge  */
#      define _RWSTDHuge huge
#    else
#      ifndef _RWSTD_USE_DECLSPEC
#        define _RWSTDExport  __declspec(dllimport)
#        ifdef _RWSTD_EXPORT_TEMPLATE
#          define _RWSTDExportTemplate _import
#        else
#          define _RWSTDExportTemplate
#        endif
#      else
#        define _RWSTDExport __declspec(dllimport)
#ifdef __BORLANDC__
#        define _RWSTDExportTemplate __declspec(dllimport)
#else
#        define _RWSTDExportTemplate
#endif
#      endif
#      define _RWSTDHuge
#    endif

#  endif
#else
   // Neither compiling, nor using the  DLL.
#  define _RWSTDExport
#  define _RWSTDExportTemplate
#  define _RWSTDHuge
#endif
// Borland likes static members of exported template classes to be exported.
// Microsoft forbids it ...

#ifdef __BORLANDC__
#  define _RWSTDExportStatic _RWSTDExport
#else
#  define _RWSTDExportStatic
#endif

//
// Different compilers expect exported functions defined in different ways.
//
#if defined(_MSC_VER) && !defined(__BORLANDC__)
#define _RWSTDExportFunc(ReturnType) _RWSTDExport ReturnType
#else
#define _RWSTDExportFunc(ReturnType) ReturnType _RWSTDExport
#endif

#endif // __RWSTDWIND_H__
#pragma option pop
#endif /* __STDWIND_H */
