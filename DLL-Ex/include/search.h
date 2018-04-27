/*  search.h

    Definitions for search functions.

*/

/*
 *      C/C++ Run Time Library - Version 10.0
 *
 *      Copyright (c) 1991, 2000 by Inprise Corporation
 *      All Rights Reserved.
 *
 */

/* $Revision:   9.2  $ */

#ifndef __SEARCH_H
#define __SEARCH_H

#ifndef ___STDDEF_H
#include <_stddef.h>
#endif

#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn -nak
#endif

#endif  /* !RC_INVOKED */

#ifdef __cplusplus
namespace std {
extern "C" {
#endif
void *      _RTLENTRYF _EXPFUNC bsearch(const void * __key, const void * __base,
                           _SIZE_T __nelem, _SIZE_T __width,
                           int (_USERENTRY *fcmp)(const void *,
                           const void *));
void *      _RTLENTRY _EXPFUNC lfind(const void * __key, const void * __base,
                                _SIZE_T*__num, _SIZE_T __width,
                                int (_USERENTRY *fcmp)(const void *, const void *));
void *      _RTLENTRY _EXPFUNC lsearch(const void * __key, void * __base,
                                _SIZE_T*__num, _SIZE_T __width,
                                int (_USERENTRY *fcmp)(const void *, const void *));
void        _RTLENTRYF _EXPFUNC qsort(void * __base, _SIZE_T __nelem, _SIZE_T __width,
                         int (_USERENTRY *__fcmp)(const void *, const void *));


#ifdef __cplusplus
}
}
#endif


#if !defined(RC_INVOKED)

#if defined(__STDC__)
#pragma warn .nak
#endif

#endif  /* !RC_INVOKED */


#endif  /* __SEARCH_H */

#if defined(__cplusplus) && !defined(__USING_CNAME__) && !defined(__SEARCH_H_USING_LIST)
#define __SEARCH_H_USING_LIST
    using std::bsearch;
    using std::lfind;
    using std::lsearch;
    using std::qsort;
#endif /* __USING_CNAME__ */