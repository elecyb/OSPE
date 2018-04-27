#ifndef __COLLATE_H
#define __COLLATE_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
/***************************************************************************
 *
 * collate - Declarations for the Standard Library character collation facet
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

#ifndef __STD_COLLATE__
#define __STD_COLLATE__

#ifndef __STD_RWLOCALE__
#include <rw/rwlocale> 
#endif

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

// ------------------------------------------------------
// Implementation class template -- collate_table<charT>.
// ------------------------------------------------------

// Data structure that drives the collate<charT> process.  It contains a
// binary tree of nodes, each of which defines the collation treatment to be
// applied to a range of characters.

template <class charT>
class _RWSTDExportTemplate collate_table {
 public:
  struct node {
    node *left;             // Node for charT values that are too small (resp.
    node *right;            //  too large) for this node
    const charT *table;     // Translate table or NULL
    charT minC,maxC;        // Range of charT-s covered by this node
    charT offset;           // Amount to add to charT if table is NULL
  };

  long length;              // Length of memory block containing all the nodes
  node root;                // Root node of table
};

// -----------------------------------------------------
// Implementation class template -- collate_data<charT>.
// -----------------------------------------------------

// collate<charT> derives from this (via rwstd::collate_impl) to get its
// private data members.

template <class charT>
class _RWSTDExportTemplate collate_data
{
 public:
  typedef collate_table<charT> table;
  typedef _TYPENAME table::node node;

  const table *__table;

  collate_data (const table &t): __table(&t) { }
  charT __coll_order (charT) const;
};

template <class charT>
inline charT collate_data<charT>::__coll_order (charT c) const
{
  const node *t=&__table->root;
  while (t)
    if (c < t->minC)
      t=t->left;
    else if (c > t->maxC)
      t=t->right;
    else {
      if (t->table)
        c=t->table[size_t(c-t->minC)];
      else
        c+=t->offset;
      break;
    }

  return c;
}

// -----------------------------------------------------
// Implementation class template -- collate_impl<charT>.
// -----------------------------------------------------

// Facet collate<charT> derives from this to get the part of its behavior that
// is specialized for char and wchar_t.

template <class charT>
class _RWSTDExportTemplate collate_impl :
    public collate_data<charT>
{
  static collate_table<charT> __default_table;
 public:
  collate_impl (void):
      collate_data<charT>(__default_table) { }
};

// Specialization for char.
_RWSTD_TEMPLATE
class _RWSTDExport collate_impl<char>:
    public collate_data<char>
{
  static collate_table<char> _RWSTDExportStatic __default_table;
 public:
  collate_impl (void):
      collate_data<char>(__default_table) { }
};

// Specialization for wchar_t.
#ifndef _RWSTD_NO_WIDE_CHAR
_RWSTD_TEMPLATE
class _RWSTDExport collate_impl<wchar_t>:
    public collate_data<wchar_t>
{
  static collate_table<wchar_t> _RWSTDExportStatic __default_table;

 public:
  collate_impl (void):
      collate_data<wchar_t>(__default_table) { }
};
#endif

#ifndef _RWSTD_NO_NAMESPACE
} namespace std {
#endif

// -----------------------------------------------------
// Standard character collation facet -- collate<charT>.
// -----------------------------------------------------

template <class charT>
class _RWSTDExportTemplate collate: public locale::facet,
    public __RWSTD::collate_impl<charT>
{
 public:
  typedef charT char_type;
  typedef basic_string<charT,char_traits<charT>,allocator<charT> > string_type;

  _EXPLICIT collate (size_t refs=0):
      locale::facet(refs,locale::__rw_collate_category)
    { }

  int compare (const charT* low1, const charT* high1,
               const charT* low2, const charT* high2) const
    { return do_compare(low1, high1, low2, high2); }

  string_type transform (const charT* low, const charT* high) const
    { return do_transform(low, high); }

  long hash (const charT* low, const charT* high) const
    { return do_hash(low, high); }

  static locale::id id;

  // Implementation:
  enum { __facet_cat = locale::__rw_collate_category, __ok_implicit = 1 };

 protected:
  virtual ~collate();

  virtual int do_compare (const charT* low1, const charT* high1,
                          const charT* low2, const charT* high2) const;
  virtual string_type do_transform (const charT* low, const charT* high) const;
  virtual long do_hash (const charT* low, const charT* high) const;

 private:
  #ifdef _RWSTD_NO_MEMBER_TEMPLATES
  locale::id &__get_id (void) const { return id; }
  #endif
};

// ------------------------------------------------------
// Standard facet specialization -- collate_byname<char>.
// ------------------------------------------------------

template <class charT>
class collate_byname;

_RWSTD_TEMPLATE
class _RWSTDExport collate_byname<char>: public collate<char> {
 public:
  _EXPLICIT collate_byname (const char*, size_t refs=0);
 protected:
  virtual ~collate_byname ();

  // Virtual member functions, override functions in collate<char>.
  virtual int do_compare (const char* low1, const char* high1,
                          const char* low2, const char* high2) const;
  virtual string do_transform (const char* low, const char* high) const;

  // Virtual member functions inherited from collate<char>:
  // virtual long do_hash (const char* low, const char* high) const;

 private:
  // Implementation.
  string __collate_name;
};

// ------------------------------------------------
// Standard derived facet -- collate_byname<charT>.
// ------------------------------------------------

template <class charT>
class  collate_byname: public collate<charT> {
 public:
  typedef basic_string<charT,char_traits<charT>,
                                allocator<charT> > string_type;

  _EXPLICIT collate_byname (const char*, size_t refs=0);

 protected:
  virtual ~collate_byname();

  // Virtual member functions overridden from collate<charT>.
  virtual int do_compare (const charT* low1, const charT* high1,
                          const charT* low2, const charT* high2) const;
  virtual string_type do_transform (const charT* low, const charT* high) const;

  // Virtual member functions inherited from collate<charT>:
  // virtual long do_hash (const charT* low, const charT* high) const;

 private:
  // Implementation.
  string_type __collate_name;
};

#ifndef _RWSTD_NO_NAMESPACE
} namespace __rwstd {
#endif

#ifndef _RWSTD_NO_FUNC_PARTIAL_SPEC
template <class charT>
inline _RW_STD::collate<charT>* create_named_facet
    (_RW_STD::collate<charT>*,const char *name,size_t refs)
{ return new _RW_STD::collate_byname<charT>(name,refs); }
#else

inline _RW_STD::collate<char>* create_named_facet
    (_RW_STD::collate<char>*,const char *name,size_t refs)
{ return new _RW_STD::collate_byname<char>(name,refs); }
#ifndef _RWSTD_NO_WIDE_CHAR

inline _RW_STD::collate<wchar_t>* create_named_facet
    (_RW_STD::collate<wchar_t>*,const char *name,size_t refs)
{ return new _RW_STD::collate_byname<wchar_t>(name,refs); }
#endif
#endif

#ifndef _RWSTD_NO_NAMESPACE
} 
#endif

#ifdef _RWSTD_COMPILE_INSTANTIATE
#include <rw/collate.cc>
#endif

#endif // __STD_COLLATE__

#pragma option pop
#endif /* __COLLATE_H */
