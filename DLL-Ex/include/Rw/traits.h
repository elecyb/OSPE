#ifndef __TRAITS_H
#define __TRAITS_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __RW_TRAITS
#define __RW_TRAITS
/***************************************************************************
 *
 * traits - Declarations for char_traits 
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

#ifndef _RWSTD_NO_NEW_HEADER
#include <cstdio>
#include <cstring>
#else
#include <stdio.h>
#include <string.h>
#endif

//
// Temporarily turn off the warnings under the Borland compiler that
// say 'Functions containing ... cannot be inlined'
//
#if defined(__BORLANDC__)
#pragma option -w-inl
#endif

/*
 * this are all necessary for the "traits" class
 */
#ifdef _RW_STD_IOSTREAM
#include <rw/iotraits> 
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

  /*
   *     STRUCT CHAR_TRAITS
   */

  template <class  charT> 
  struct  _RWSTDExportTemplate char_traits 
  {
    typedef charT                    char_type;
    typedef long                     int_type;

#ifdef _RW_STD_IOSTREAM
    typedef wstreamoff               off_type;
    typedef mbstate_t                state_type;
    typedef fpos<state_type>         pos_type;
#endif /* _RW_STD_IOSTREAM */

    static void assign (char_type& c1, const char_type& c2)   
    { c1 = c2;}

    static bool     eq(const char_type& c1,const char_type& c2)
    { return (c1 == c2); }

    static bool lt (const char_type& c1, const char_type& c2) 
    { return c1 < c2;}

    static int compare (const char_type* s1, const char_type* s2, size_t n)
    {
      size_t i=0;

      while ( i < n )
      { 
        if ( !eq( s1[i], s2[i] ) )
        {
          if ( lt( s1[i], s2[i]) )
            return -1;
          else
            return 1;               
        }
        i++;
      }
      return 0;
    }
        
    static size_t length(const char_type *s)
    {
      size_t l = 0;
      while ( !eq(*s++, char_type(0) ) )  ++l;
      return l;
    }
 
    static const char_type* 
    find (const char_type* s, size_t n, const char_type& a)
    {
      while (n-- > 0 && *s != a) 
        ++s;
      return  *s == a ? s : 0;
    }

    static char_type* move (char_type* s1, const char_type* s2, size_t n)
    {
      char_type * s = s1;
      if (s1 < s2)
        copy(s1, s2, n);
      else if (s1 > s2)
      {
        s1 += n;
        s2 += n;
        for(size_t i = 0; i < n; ++i) 
          assign(*--s1, *--s2);
      }
      return s1;
    }

    static char_type * copy(char_type *dst,const char_type *src, size_t n)
    {
      memcpy((char *)dst,(char *)src,n*sizeof(char_type));
      return dst;
    }

    static char_type*  assign (char_type* s, size_t n, char_type a)
    {
      char_type* tmp = s;
      while (n-- > 0) 
        *tmp++ = a;
      return s;
    }

    static int_type not_eof(const int_type& c)
    {
      if(c == EOF)
        return 0;
      else
        return c;
    }

    static char_type to_char_type(const int_type& c)
    { return c; }
    static int_type to_int_type(const char_type& c)
    { return c; }

    static bool     eq_int_type(const int_type& c1,const int_type& c2)
    { return (c1 == c2); }

#ifdef _RW_STD_IOSTREAM
    static state_type get_state(pos_type pos)
    { return pos.state(); }
#endif 

    static int_type             eof()
    { return EOF; }
  };
/*
 *
 *     STRUCT CHAR_TRAITS SPECIALIZED FOR CHAR
 *
 */

  _RWSTD_TEMPLATE  
  struct _RWSTDExport char_traits<char> 
  {

    typedef char                      char_type;
    typedef int                       int_type;
       
#ifdef _RW_STD_IOSTREAM
    typedef streamoff                 off_type; 
    typedef streampos                 pos_type;
    typedef mbstate_t                 state_type;
#endif 

    static void assign (char_type& c1, const char_type& c2)   
    { c1 = c2; }

    static bool eq(const char_type& c1,const char_type& c2)
    { return (c1 == c2); }

    static bool lt (const char_type& c1, const char_type& c2) 
    { return c1 < c2; }

    static int compare (const char_type* s1, const char_type* s2, size_t n)
    { return memcmp(s1, s2, n); }

    static const char_type* find (const char_type* s,
                                  size_t n, const char_type& a)
    { return (char_type*) memchr(s,a,n); }

    static size_t length(const char_type *s)
    { return strlen(s); }

    static char_type * move (char_type* s1, const char_type* s2, size_t n)
    {
#ifndef _RWSTD_NO_MEMMOVE
      memmove(s1, s2, n);
#else
      char_type * s = s1;
      if (s1 < s2)
        copy(s1, s2, n);
      else if (s1 > s2)
      {
        s1 += n;
        s2 += n;
        for(size_t i = 0; i < n; ++i)
          assign(*--s1, *--s2);
      }
#endif
      return s1;
    }

    static char_type  *copy(char_type *dst,const char_type *src, size_t n)
    { 
      memcpy(dst, src, n); 
      return dst;
    }

    static char_type* assign (char_type* s, size_t n, char_type a)
    {
      memset(s,a,n);
      return s;
    }

    static int_type not_eof(const int_type& c)
    {
      if ( c == EOF )
        return 0;
      else
        return c;
    }
                        
    static char_type to_char_type(const int_type& c)
    { return (char)c; }
    static int_type to_int_type(const char_type& c)
    { return (unsigned char)c; }

    static bool eq_int_type(const int_type& c1,const int_type& c2)
    { return (c1 == c2); }

#ifdef _RW_STD_IOSTREAM
    static state_type get_state(pos_type pos)
    { return pos.state(); }
#endif 

    static int_type eof()
    { return EOF; }
  };
/*
 *
 *     STRUCT CHAR_TRAITS SPECIALIZED FOR WCHAR_T
 *
 */
#ifndef _RWSTD_NO_WIDE_CHAR

  _RWSTD_TEMPLATE  
  struct _RWSTDExport char_traits<wchar_t> 
  {
    typedef wchar_t                   char_type;

#ifndef _RWSTD_NO_WINT_TYPE
    typedef wint_t                    int_type;
#else
    typedef long                      int_type;
#endif

#ifndef WEOF
#define WEOF (-1)
#endif

#ifdef _RW_STD_IOSTREAM
    typedef wstreamoff                off_type;
    typedef wstreampos                pos_type;
    typedef mbstate_t                 state_type;
#endif /* _RW_STD_IOSTREAM */        

    static void assign (char_type& c1, const char_type& c2)   
    { c1 = c2;}

    static bool eq(const char_type& c1,const char_type& c2)
    { return (c1 == c2); }

    static bool lt (const char_type& c1, const char_type& c2) 
    { return c1 < c2;}

    static int compare (const char_type* s1, const char_type* s2, size_t n)
    {
#ifndef _RWSTD_NO_WSTR
      return memcmp(s1, s2, n*sizeof(char_type));
#else
      size_t i=0;

      while ( i < n )
      { 
        if ( !eq( s1[i], s2[i] ) )
        {
          if ( lt( s1[i], s2[i]) )
            return -1;
          else
            return 1;               
        }
        i++;
      }
      return 0;
#endif
    }
    static size_t length(const char_type *s)
    {
#ifndef _RWSTD_NO_WSTR   
      return wcslen(s);
#else
      size_t l = 0;
      while ( !eq(*s++, char_type(0) ) )  ++l;
      return l;
#endif
    }
 
    static const char_type* find (const char_type* s, size_t n,
                                  const char_type& a)
    {
#ifndef _RWSTD_NOT_ALL_WSTR_CFUNCTIONS
      return (char_type*) wmemchr(s,a,n);
#else
      while (n-- > 0 && *s != a) 
        ++s;
      return  *s == a ? s : 0;
#endif
    }

    static char_type * move (char_type* s1, const char_type* s2, size_t n)
    {
#ifndef _RWSTD_NO_MEMMOVE
      memmove(s1, s2, n*sizeof(char_type));
#else
      char_type * s = s1;
      if (s1 < s2)
        copy(s1, s2, n);
      else if (s1 > s2)
      {
        s1 += n;
        s2 += n;
        for(size_t i = 0; i < n; ++i) assign(*--s1, *--s2);
      }
#endif
      return s1;
    }

    static char_type * copy(char_type *dst,const char_type *src, size_t n)
    {
      memcpy((char *)dst,(char *)src, n*sizeof(char_type));
      return dst;
    }

    static char_type* assign (char_type* s, size_t n, char_type a)
    {
#ifndef _RWSTD_NOT_ALL_WSTR_CFUNCTIONS
      wmemset(s,a,n);
#else
      char_type* tmp = s;
      while (n-- > 0) 
        *tmp++ = a;
#endif
      return s;
    }

    static int_type not_eof(const int_type& c)
    {
      if(c == WEOF)
        return 0;
      else
        return c;
    }

    static char_type to_char_type(const int_type& c)
    { return c; }
    static int_type to_int_type(const char_type& c)
    { return c; }

    static bool eq_int_type(const int_type& c1,const int_type& c2)
    { return (c1 == c2); }

#ifdef _RW_STD_IOSTREAM
    static state_type get_state(pos_type pos)
    { return pos.state(); }
#endif 

    static int_type             eof()
    { return WEOF; }
  };

#endif
#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif
//
// Implementation traits class, rw_traits, provides specialized
// algorithms to speed up find operations on char and wchar_t strings
//

  template <class charT, class traits> 
  struct _RWSTDExportTemplate rw_traits
  {
    static const charT* find(const charT* s, const charT* v)
    { 
      size_t slen = traits::length(s);
      size_t vlen = traits::length(v);
      for (size_t xpos = 0; (xpos + vlen) <= slen ; xpos++)
      {
        bool found = true;
        for (size_t i = 0; i < vlen ; i++)
        {
          if (!traits::eq(s[xpos + i], v[i]))
          {
            found = false;
            break;
          }
        }
        if (found)
          return &s[xpos];
      }
      return NULL;
    }

    static const charT* rfind(const charT* s, charT v, size_t pos)
    {
      const charT* p = s + pos;
      while (p >= s)
      {
        if (traits::eq(*p,v))
          return p;
        p--;
      }
      return NULL;       
    }

    static size_t find_first_of(const charT* s, const charT* v)
    {
      const charT* p = s;
      for (; *p; p++)
      {
        for (const charT* q = v; *q; q++)
          if (traits::eq(*p, *q))
            return p-s;
      }
      return  p-s;
    }

    static size_t find_first_not_of(const charT* s, const charT* v)
    {
      const charT* p = s;
      for (; *p; p++)
      {
        for (const charT* q = v; *q; q++)
          if (!traits::eq(*p, *q))
            return p-s;
      }
      return  p-s;
    }
  };

  _RWSTD_TEMPLATE 
  struct _RWSTDExport rw_traits<char,_RW_STD::char_traits<char> >
  {
    static const char* find(const char* s, const char* v)
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE)
    { return std::strstr(s,v); }
#else
    { return strstr(s,v); }
#endif
    static const char* rfind(const char* s, char v, size_t pos)
    { 
      const char* p = s + pos;
      while (p >= s)
      {
        if (_RW_STD::char_traits<char>::eq(*p,v))
          return p;
        p--; 
      }
      return NULL;       
    }
    static size_t find_first_of(const char* s, const char* v)
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE)
    { return std::strcspn(s,v); }
#else
    { return strcspn(s,v); }
#endif
    static size_t find_first_not_of(const char* s, const char* v)
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE)
    { return std::strspn(s,v); }
#else
    { return strspn(s,v); }
#endif
  };

#ifndef _RWSTD_NO_WSTR
  _RWSTD_TEMPLATE 
  struct _RWSTDExport rw_traits<wchar_t,_RW_STD::char_traits<wchar_t> >
  {
    static const wchar_t* find(const wchar_t* s, const wchar_t* v)
#ifndef _HPACC_
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE)
    { return std::wcsstr(s,v); }
#else
    { return wcsstr(s,v); }
#endif
#else
  // Having _HPACC_ defined sufficiently indicates both function name
  // and that said function is not in namespace std.
  { return wcswcs(s,v); }
#endif //_HPACC_
    static const wchar_t* rfind(const wchar_t* s, wchar_t v, size_t pos)
    { 
      const wchar_t* p = s + pos;
      while (p >= s)
      {
        if (_RW_STD::char_traits<wchar_t>::eq(*p,v))
          return p;
        p--;
      }
      return NULL;       
    }
    static size_t find_first_of(const wchar_t* s, const wchar_t* v)
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE) && !defined(_HPACC_)
    { return std::wcscspn(s,v); }
#else
    { return wcscspn(s,v); }
#endif
    static size_t find_first_not_of(const wchar_t* s, const wchar_t* v)
#if !defined(_RWSTD_NO_NEW_HEADER) && !defined(_RWSTD_NO_NAMESPACE) && !defined(_HPACC_)
    { return std::wcsspn(s,v); }
#else
    { return wcsspn(s,v); }
#endif
  };
#endif // _RWSTD_NO_WSTR

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#endif // __RW_TRAITS
#pragma option pop
#endif /* __TRAITS_H */
