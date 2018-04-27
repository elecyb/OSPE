#ifndef __RWCATS_H
#define __RWCATS_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
#ifndef _RWCATS_H
#define _RWCATS_H
/***************************************************************************
 *
 * rwcats.h - Declarations for XPG4 messages
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
#include <stddef.h>
#include <rw/locvector>
#include <map>
#include <string>

#ifdef __WIN32__
#define _RWSTD_USE_RC 1
#endif

#ifndef LC_MESSAGES
#define LC_MESSAGES LC_MAX + 1
#endif

#define NL_SETD                 1    /* XPG3 Conformant Default set number. */
#define NL_CAT_LOCALE           (-1) /* XPG4 requirement */
#define NL_CAT_LOCALE           (-1) /* XPG4 requirement */

#define _RWCAT_COOKIE            0xAB34BC56

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifndef _RWSTD_USE_RC
  // NULL implementation (does nothing)
  class __rwcat
  {
    public:
      __rwcat(const char* fname, int oflag) { ; }
      ~__rwcat() { ; }
      __rwcat* id() { return this; }
      bool good() { return false; }
      char * catgets(int set_num, int msg_num, const char* s) { return s; }
  };

#else

#ifndef _RWSTD_NO_NAMESPACE
} // namespace __rwstd // RW_BUG
#endif
#include <windows.h>
#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {    // RW_BUG
#endif

#ifndef _RWSTD_NO_NAMESPACE
  using namespace std;
#endif
#define NL_TEXTMAX 8024 
  // Catalog type hold relationship between cat id and file
  class __rwcat
  {
    public:
      typedef map<int,string,less<int>,allocator<pair<const int, string> > >__cat_type;
      typedef __cat_type::value_type __msg_type;
      
    protected:
      HINSTANCE __cat;
      __cat_type __msgs;

    public:
      __rwcat(const char* fname, int oflag);
      ~__rwcat();
      __rwcat* id() { return this; }
      bool good() { return __cat ? true : false; }      
      HINSTANCE cat() { return __cat; }
      char * catgets(int set_num, int msg_num, const char* s);
  };

#endif //_RWSTD_USE_RC

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

typedef  __RWSTD::__rwcat* nl_catd;
typedef int nl_item;

int     catclose(nl_catd);
char    *catgets(nl_catd, int, int, const char *);
nl_catd catopen(const char *, int);
#endif  /* _RWCATS_H */

#pragma option pop
#endif /* __RWCATS_H */
