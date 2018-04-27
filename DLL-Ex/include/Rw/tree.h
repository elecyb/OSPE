#ifndef __TREE_H
#define __TREE_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
// -*- C++ -*-
#ifndef __STD_TREE__
#define __STD_TREE__

/***************************************************************************
 *
 * tree - Declarations for the Standard Library tree classes
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

/*
**
** Red-black tree class, designed for use in implementing STL
** associative containers (set, multiset, map, and multimap). The
** insertion and deletion algorithms are based on those in Cormen,
** Leiserson, and Rivest, Introduction to Algorithms (MIT Press, 1990),
** except that:
** 
** (1) the header cell is maintained with links not only to the root
** but also to the leftmost node of the tree, to enable constant time
** begin(), and to the rightmost node of the tree, to enable linear time
** performance when used with the generic set algorithms (set_union,
** etc.);
** 
** (2) when a node being deleted has two children its successor node is
** relinked into its place, rather than copied, so that the only
** iterators invalidated are those referring to the deleted node.
** 
*/

#include <stdcomp.h>
#include <algorithm>
#include <iterator>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

#ifndef __rb_tree 
#define __rb_tree __rb_tree
#endif

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  class __rb_tree
  {
  protected:

    enum __color_type { __rb_red, __rb_black };

    struct __rb_tree_node;
    friend struct __rb_tree_node;

#ifdef _RWSTD_ALLOCATOR
    typedef _TYPENAME _Alloc::template rebind<_Val>::other  __value_alloc_type;
    typedef _TYPENAME _Alloc::template rebind<_Key>::other  __key_alloc_type;
    typedef _TYPENAME _Alloc::template rebind<__rb_tree_node>::other  __node_alloc_type;
#else
    typedef _RW_STD::allocator_interface<_Alloc,_Val>      __value_alloc_type;
    typedef _RW_STD::allocator_interface<_Alloc,_Key>        __key_alloc_type;
    typedef _RW_STD::allocator_interface<_Alloc,__rb_tree_node> __node_alloc_type;
#endif

    typedef _TYPENAME __node_alloc_type::pointer          __link_type;

    struct __rb_tree_node
    {
      __color_type   color_field; 
      __link_type parent_link;
      __link_type left_link;
      __link_type right_link;
      _Val        value_field;
    };

    typedef _TYPENAME __key_alloc_type::const_reference    const_key_reference;

  public:

    typedef _Key                                    key_type;
    typedef _Val                                    value_type;
    typedef _Alloc                                  allocator_type;
    typedef _TYPENAME __value_alloc_type::pointer          pointer;
    typedef _TYPENAME __value_alloc_type::const_pointer    const_pointer;

#ifndef _RWSTD_NO_COMPLICATED_TYPEDEF
    typedef _TYPENAME _Alloc::size_type                 size_type;
    typedef _TYPENAME _Alloc::size_type                 difference_type;
    typedef _TYPENAME __value_alloc_type::reference       reference;
    typedef _TYPENAME __value_alloc_type::const_reference const_reference;
#else
    typedef size_t             size_type;
    typedef ptrdiff_t          difference_type;
    typedef _Val&              reference;
    typedef const _Val&        const_reference;
#endif  //_RWSTD_NO_COMPLICATED_TYPEDEF

  protected:
    size_type __buffer_size;

    struct __rb_tree_node_buffer;
    friend struct __rb_tree_node_buffer;

#ifdef _RWSTD_ALLOCATOR
    typedef _TYPENAME allocator_type::template rebind<__rb_tree_node_buffer>::other  __buffer_alloc_type;
#else
    typedef _RW_STD::allocator_interface<_Alloc,__rb_tree_node_buffer> __buffer_alloc_type;
#endif
    typedef _TYPENAME __buffer_alloc_type::pointer __buffer_pointer;

    struct __rb_tree_node_buffer
    {
       __buffer_pointer  next_buffer;
      size_type size;
      __link_type buffer;
    };

    __RWSTD::__rw_basis<__buffer_pointer,allocator_type>   __buffer_list;
    __link_type                      __free_list;
    __link_type                      __next_avail;
    __link_type                      __last;

    static bool __isNil(const __link_type& l) 
    {  return l == __nil();  }

    void __add_new_buffer ()
    {
      __buffer_pointer tmp = __buffer_alloc_type(__buffer_list).allocate(_RWSTD_STATIC_CAST(size_type,1),__buffer_list.data());
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        tmp->buffer        = __node_alloc_type(__buffer_list).allocate(__buffer_size,__last);
      } catch(...) {
        __buffer_alloc_type(__buffer_list).deallocate(tmp,1);
        throw;
      } 
#else
      tmp->buffer        = __node_alloc_type(__buffer_list).allocate(__buffer_size,__last);
#endif //  _RWSTD_NO_EXCEPTIONS     
      tmp->next_buffer   = __buffer_list;
      tmp->size          = __buffer_size;
      __buffer_list        = tmp;
      __next_avail         = __buffer_list.data()->buffer;
      __last               = __next_avail + __buffer_size;
    }
    void __deallocate_buffers ();

    // 
    // Return a node from the free list or new storage
    //
    __link_type __get_link()
    {
      __link_type tmp = __free_list;
      __link_type tmp2 = __free_list ? 
        (__free_list = _RWSTD_STATIC_CAST(__link_type,(__free_list->right_link)), tmp) 
        : (__next_avail == __last ? (__add_new_buffer(), __next_avail++) 
          : __next_avail++);
      tmp2->parent_link = __nil();
      tmp2->left_link = __nil();
      tmp2->right_link = __nil();
      tmp2->color_field = __rb_red;
      return tmp2;
    }

    //
    // Return a node from the free list or new storage with
    // the _Val v constructed on it.  Every call to __get_node
    // must eventually be followed by a call to __put_node.
    //
    __link_type __get_node (const _Val& v)
    {
      __link_type tmp2 = __get_link();
      __value_alloc_type va(__buffer_list);
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        va.construct(va.address(__value(tmp2)),v);
      } catch(...) {
        __put_node(tmp2,false);
        throw;
      }      
#else
      va.construct(va.address(__value(tmp2)),v);
#endif // _RWSTD_NO_EXCEPTIONS
      return tmp2;
    }
    __link_type __get_node ()
    {
      return __get_link();
    }

    // 
    // Return a node to the free list and destroy the value in it.
    //
    void __put_node (__link_type p, bool do_destroy = true) 
    { 
      p->right_link = __free_list; 
      if (do_destroy)      
      {
        __value_alloc_type va(__buffer_list);
        va.destroy(va.address(__value(p)));  
      }
      __free_list = p; 
    }

  protected:

    __link_type  __header;  
    __link_type& __root      ()       { return __parent(__header); }
    __link_type& __root      () const { return __parent(__header); }
    __link_type& __leftmost  ()       { return __left(__header);   }
    __link_type& __leftmost  () const { return __left(__header);   }
    __link_type& __rightmost ()       { return __right(__header);  }
    __link_type& __rightmost () const { return __right(__header);  }

    size_type  __node_count;    // Keeps track of size of tree.
    bool       __insert_always; // Controls whether an element already in the
    // tree is inserted again.
    _Comp      __key_compare;

    static __link_type __nil () { return NULL; }

    static __link_type& __left (__link_type x)
    {
      return _RWSTD_REINTERPRET_CAST(__link_type&,((*x).left_link));
    }
    static __link_type& __right (__link_type x)
    {
      return _RWSTD_REINTERPRET_CAST(__link_type&,((*x).right_link));
    }
    static __link_type& __parent (__link_type x)
    {
      return _RWSTD_REINTERPRET_CAST(__link_type&,((*x).parent_link));
    }
    static reference __value (__link_type x) { return (*x).value_field; }
    static const_key_reference __key (__link_type x)
    {
      return _KeyOf()(__value(x));
    }
    static __color_type& __color (__link_type x)
    {
      return _RWSTD_STATIC_CAST(__color_type&,(*x).color_field);
    }
    static __link_type __minimum (__link_type x)
    {
      while (!__isNil(__left(x))) x = __left(x);
      return x;
    }
    static __link_type __maximum (__link_type x)
    {
      while (!__isNil(__right(x))) x = __right(x);
      return x;
    }

    typedef _RW_STD::iterator<_RW_STD::bidirectional_iterator_tag, value_type,
                    difference_type, pointer,reference> __it;
    typedef _RW_STD::iterator<_RW_STD::bidirectional_iterator_tag, value_type, 
                    difference_type, const_pointer, const_reference> __cit;

  public:

    class  iterator;
    friend class iterator;
    class  const_iterator;
    friend class const_iterator;

    class iterator : public __it
    {
      friend class __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>;
      friend class const_iterator;

    protected:

      __link_type node;
      iterator (__link_type x) : node(x) {}        

    public:

      iterator () {}
      bool operator== (const iterator& y) const { return node == y.node; }
      bool operator!= (const iterator& y) const { return node != y.node; }
      reference operator* () const { return __value(node); }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
      pointer operator-> () const { return &(node->value_field); }
#endif
      iterator& operator++ ()
      {
        if (!__isNil(__right(node)))
        {
          node = __right(node);
          while (!__isNil(__left(node))) node = __left(node);
        }
        else
        {
          __link_type y = __parent(node);
          while (node == __right(y))
          {
            node = y; y = __parent(y);
          }
          if (__right(node) != y) // Necessary because of rightmost.
            node = y;
        }
        return *this;
      }
      iterator operator++ (int)
      {
        iterator tmp = *this; ++*this; return tmp;
      }
      iterator& operator-- ()
      {
        if (__color(node) == __rb_red && __parent(__parent(node)) == node)  
          //
          // Check for header.
          //
          node = __right(node);   // Return rightmost.
        else if (!__isNil(__left(node)))
        {
          __link_type y = __left(node);
          while (!__isNil(__right(y))) y = __right(y);
          node = y;
        }
        else
        {
          __link_type y = __parent(node);
          while (node == __left(y))
          {
            node = y; y = __parent(y);
          }
          node = y;
        }
        return *this;
      }
      iterator operator-- (int)
      {
        iterator tmp = *this; --*this; return tmp;
      }

    };  // End of definition of iterator.

    class const_iterator : public __cit
    {
      friend class __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>;
      friend class iterator;

    protected:

      __link_type node;
      const_iterator (__link_type x) : node(x) {}

    public:

      const_iterator () {}
#if !defined(_MSC_VER) || defined(__BORLANDC__)
      const_iterator  (const _TYPENAME __rb_tree<_Key,_Val,_KeyOf,_Comp,_Alloc>::iterator& x) : node(x.node) {}
#else
      const_iterator  (const iterator& x) : node(x.node) {}
#endif

      bool operator== (const const_iterator& y) const
      { 
        return node == y.node; 
      }
      bool operator!= (const const_iterator& y) const
      { 
        return node != y.node; 
      }
      const_reference operator* () const { return __value(node); }
#ifndef _RWSTD_NO_NONCLASS_ARROW_RETURN
      const_pointer operator-> () const { return &(node->value_field); }
#endif
      const_iterator& operator++ ()
      {
        if (!__isNil(__right(node)))
        {
          node = __right(node);
          while (!__isNil(__left(node))) node = __left(node);
        }
        else
        {
          __link_type y = __parent(node);
          while (node == __right(y))
          {
            node = y; y = __parent(y);
          }
          if (__right(node) != y) // Necessary because of rightmost.
            node = y;
        }
        return *this;
      }
      const_iterator operator++ (int)
      {
        const_iterator tmp = *this; ++*this; return tmp;
      }
      const_iterator& operator-- ()
      {
        if (__color(node) == __rb_red && __parent(__parent(node)) == node)  
          //
          // Check for header.
          //
          node = __right(node);   // return rightmost
        else if (!__isNil(__left(node)))
        {
          __link_type y = __left(node);
          while (!__isNil(__right(y))) y = __right(y);
          node = y;
        }
        else
        {
          __link_type y = __parent(node);
          while (node == __left(y))
          {
            node = y; y = __parent(y);
          }
          node = y;
        }
        return *this;
      }
      const_iterator operator-- (int)
      {
        const_iterator tmp = *this; --*this; return tmp;
      }
    };  // End of definition of const_iterator.

#ifndef _RWSTD_NO_CLASS_PARTIAL_SPEC 
    typedef _RW_STD::reverse_iterator<const_iterator> const_reverse_iterator;
    typedef _RW_STD::reverse_iterator<iterator>  reverse_iterator;
#else
    typedef _RW_STD::__reverse_bi_iterator<const_iterator, 
      _RW_STD::bidirectional_iterator_tag, value_type, 
      const_reference, const_pointer, difference_type>
      const_reverse_iterator;
    typedef _RW_STD::__reverse_bi_iterator<iterator, 
      _RW_STD::bidirectional_iterator_tag, value_type,
      reference, pointer, difference_type>
      reverse_iterator;
#endif

  private:

    iterator  __insert (__link_type x, __link_type y, const value_type& v);
    __link_type __copy   (__link_type x, __link_type p);
    void      __erase  (__link_type x);
    inline void      __erase_leaf  (__link_type x);
    void init ()
    {
      __buffer_size = 1;
      __buffer_list = 0;
      __free_list = __next_avail = __last = 0;
      __header        = __get_node();
      __root()        = __nil();
      __leftmost()    = __header;
      __rightmost()   = __header;
      __buffer_size   = 
      1 >__RWSTD::__rw_allocation_size((value_type*)0,(size_type)0,(size_type)0) ? 1 
           : __RWSTD::__rw_allocation_size((value_type*)0,(size_type)0,(size_type)0);
    }

  public:

    __rb_tree (const _Comp& _RWSTD_COMP _RWSTD_DEFAULT_ARG(_Comp()), bool always _RWSTD_DEFAULT_ARG(true),
             const _Alloc& alloc _RWSTD_DEFAULT_ARG(_Alloc())) 
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(always), __buffer_list(0,alloc)
    {
      init();
    }

#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    __rb_tree (void) 
      : __node_count(0), __header(0), __key_compare(_Comp()), 
        __insert_always(true), __buffer_list(0,_Alloc())
    {
      init();
    }

    __rb_tree (const _Comp& _RWSTD_COMP) 
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(true), __buffer_list(0,_Alloc())
    {
      init();
    }

    __rb_tree (const _Comp& _RWSTD_COMP , bool always = true)
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(always), __buffer_list(0,_Alloc())
    {
      init();
    }
#endif

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class InputIterator>
    __rb_tree (InputIterator first, InputIterator last, 
             const _Comp& comp = _Comp(), bool always = true,
             const _Alloc& alloc = _Alloc())
      : __node_count(0), __header(0), __key_compare(comp), 
        __insert_always(always), __buffer_list(0,alloc)
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }
#else
    __rb_tree (const value_type* first, const value_type* last, 
             const _Comp& _RWSTD_COMP _RWSTD_DEFAULT_ARG(_Comp()), bool always _RWSTD_DEFAULT_ARG(true),
             const _Alloc& alloc _RWSTD_DEFAULT_ARG(_Alloc()))
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(always), __buffer_list(0,alloc)
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }
    __rb_tree (const_iterator first, const_iterator last, 
             const _Comp& _RWSTD_COMP _RWSTD_DEFAULT_ARG(_Comp()), bool always _RWSTD_DEFAULT_ARG(true),
             const _Alloc& alloc _RWSTD_DEFAULT_ARG(_Alloc()))
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(always), __buffer_list(0,alloc)
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }
   
#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS
    __rb_tree (const value_type* first, const value_type* last, 
             const _Comp& _RWSTD_COMP _RWSTD_DEFAULT_ARG(_Comp()))
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(true), __buffer_list(0,_Alloc())
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }

    __rb_tree (const value_type* first, const value_type* last, 
             const _Comp& _RWSTD_COMP _RWSTD_DEFAULT_ARG(_Comp()), bool always _RWSTD_DEFAULT_ARG(true))
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(always), the__Alloc(_Alloc())
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }

    __rb_tree (const_iterator first, const_iterator last, 
             const _Comp& _RWSTD_COMP _RWSTD_DEFAULT_ARG(_Comp()))
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(true), __buffer_list(0,_Alloc())
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }

    __rb_tree (const_iterator first, const_iterator last, 
             const _Comp& _RWSTD_COMP _RWSTD_DEFAULT_ARG(_Comp()), bool always _RWSTD_DEFAULT_ARG(true))
      : __node_count(0), __header(0), __key_compare(_RWSTD_COMP), 
        __insert_always(always), __buffer_list(0,_Alloc())
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }
#endif
   
#ifdef _RWSTD_NO_DEFAULT_TEMPLATE_ARGS    
    __rb_tree (const value_type* first, const value_type* last) 
      : __node_count(0), __header(0), __key_compare(_Comp()), 
        __insert_always(true), __buffer_list(0,_Alloc())
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }

    __rb_tree (const_iterator first, const_iterator last) 
      : __node_count(0), __header(0), __key_compare(_Comp()), 
        __insert_always(true), __buffer_list(0,_Alloc())
    { 
      init(); 
#ifndef _RWSTD_NO_EXCEPTIONS
      try {
        insert(first, last);
      } catch(...) {
        __deallocate_buffers();
        throw;
      }
#else
      insert(first, last);
#endif // _RWSTD_NO_EXCEPTIONS
    }

#endif
#endif

    __rb_tree (const __rb_tree<_Key,_Val,_KeyOf,_Comp,_Alloc>& x,
             bool always = true)
      : __node_count(x.__node_count), __header(0), __key_compare(x.__key_compare),
        __insert_always(always), __buffer_list(0,x.get_allocator())
    { 
      __buffer_size   = 1;
      __free_list     = __next_avail = __last = 0;
      __header        = __get_node();
      __buffer_size   = 
      1 >  __RWSTD::__rw_allocation_size((value_type*)0,(size_type)0,(size_type)0) ?
          1 : __RWSTD::__rw_allocation_size((value_type*)0,(size_type)0,(size_type)0);
      __color(__header) = __rb_red;
      __root()        = __copy(x.__root(), __header);
      if (__isNil(__root()))
      {
        __leftmost() = __header; __rightmost() = __header;
      }
      else
      {
        __leftmost() = __minimum(__root()); __rightmost() = __maximum(__root());
      }
    }
    ~__rb_tree ()
    {
      if (__header)
      {
        erase(begin(), end());
        __put_node(__header,false);
        __deallocate_buffers();
      }
    }

    __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& 
    operator= (const __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& x);

    _Comp     key_comp () const { return __key_compare; }
    allocator_type get_allocator() const
    {
      return (allocator_type)__buffer_list;
    }

    iterator begin () const { return __leftmost(); }
    iterator end   () const { return __header;     }

    reverse_iterator rbegin ()
    { 
      reverse_iterator tmp(end()); return tmp;
    }
    reverse_iterator rend ()
    { 
      reverse_iterator tmp(begin()); return tmp;
    } 

    const_reverse_iterator rbegin () const
    { 
      const_reverse_iterator tmp(end()); return tmp;
    }
    const_reverse_iterator rend () const
    { 
      const_reverse_iterator tmp(begin()); return tmp;
    } 

    bool      empty    () const { return __node_count == 0; }
    size_type size     () const { return __node_count;      }
    size_type max_size () const
    { 
      return __node_alloc_type(__buffer_list).max_size(); 
    }
    void swap (__rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& t)
    {
      if((allocator_type)__buffer_list==(allocator_type)t.__buffer_list)
      {
#ifndef _RWSTD_NO_NAMESPACE
        std::swap(__buffer_list, t.__buffer_list);
        std::swap(__free_list, t.__free_list);
        std::swap(__next_avail, t.__next_avail);
        std::swap(__last, t.__last);
        std::swap(__header, t.__header);
        std::swap(__node_count, t.__node_count);
        std::swap(__insert_always, t.__insert_always);
        std::swap(__key_compare, t.__key_compare);
#else
        ::swap(__buffer_list, t.__buffer_list);
        ::swap(__free_list, t.__free_list);
        ::swap(__next_avail, t.__next_avail);
        ::swap(__last, t.__last);
        ::swap(__header, t.__header);
        ::swap(__node_count, t.__node_count);
        ::swap(__insert_always, t.__insert_always);
        ::swap(__key_compare, t.__key_compare);
#endif
      }
      else
      {
        __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc> _x = *this;
        *this = t;
        t = _x;
      } 
    }

    typedef  _RW_STD::pair<iterator, bool> pair_iterator_bool;
    //
    // typedef done to get around compiler bug.
    //

#ifndef _RWSTD_NO_RET_TEMPLATE
    _RW_STD::pair<iterator,bool> insert (const value_type& x);
#else
    pair_iterator_bool  insert (const value_type& x);
#endif

    iterator  insert (iterator position, const value_type& x);

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
    template<class Iterator>
    void      insert (Iterator first, Iterator last);
#else
    void      insert (const_iterator first, const_iterator last);
    void      insert (const value_type* first, const value_type* last);
#endif

    iterator  erase  (iterator position);
    size_type erase  (const key_type& x);
    iterator  erase  (iterator first, iterator last);
    void      erase  (const key_type* first, const key_type* last);

    iterator find        (const key_type& x) const;
    size_type  count     (const key_type& x) const;
    iterator lower_bound (const key_type& x) const;
    iterator upper_bound (const key_type& x) const;

    typedef  _RW_STD::pair<iterator, iterator> pair_iterator_iterator; 
    //
    // typedef done to get around compiler bug.
    //
#ifndef _RWSTD_NO_RET_TEMPLATE
    _RW_STD::pair<iterator,iterator> equal_range (const key_type& x) const;
#else
    pair_iterator_iterator equal_range (const key_type& x) const;
#endif

    inline void __rotate_left  (__link_type x);
    inline void __rotate_right (__link_type x);

    // Query and set the allocation size
    size_type allocation_size() { return __buffer_size; }
    size_type allocation_size(size_type new_size) 
    { 
      size_type tmp = __buffer_size; 
      __buffer_size = 1 > new_size ? 1 : new_size; //max((size_type)1,new_size);
      return tmp;
    }  
  };
//
// Inline functions
//

  template <class _Key, class _Val, class _KeyOf, 
  class _Comp, class _Alloc>
  inline bool operator== (const __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& x, 
                          const __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& y)
  {
    return x.size() == y.size() && _RW_STD::equal(x.begin(), x.end(), y.begin());
  }

  template <class _Key, class _Val, class _KeyOf, 
  class _Comp, class _Alloc>
  inline bool operator< (const __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& x, 
                         const __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& y)
  {
    return _RW_STD::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
  }

  template <class _Key,class _Val,class _KeyOf,class _Comp,class _Alloc>
  inline  void   
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::__erase_leaf (__link_type x)
  {
    // Remove a leaf node from the tree
    __link_type y = __parent(x);
    if (y == __header)
    {
      __leftmost() = __rightmost() = y;
      __root() = __nil();
    }
    else if (__left(y) == x)
    {
      __left(y) = __nil();
      if (__leftmost() == x)
        __leftmost() = y;
    }
    else
    {
      __right(y) = __nil();
      if (__rightmost() == x)
        __rightmost() = y;
    }
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  inline void 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::__rotate_left (__link_type x)
  {
    __link_type y = __right(x);
    __right(x) = __left(y);
    if (!__isNil(__left(y)))
      __parent(__left(y)) = x;
    __parent(y) = __parent(x);
    if (x == __root())
      __root() = y;
    else if (x == __left(__parent(x)))
      __left(__parent(x)) = y;
    else
      __right(__parent(x)) = y;
    __left(y) = x;
    __parent(x) = y;
  }
  template <class _Key, class _Val, class _KeyOf, 
  class _Comp, class _Alloc>
  inline void 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::__rotate_right (__link_type x)
  {
    __link_type y = __left(x);
    __left(x) = __right(y);
    if (!__isNil(__right(y)))
      __parent(__right(y)) = x;
    __parent(y) = __parent(x);
    if (x == __root())
      __root() = y;
    else if (x == __right(__parent(x)))
      __right(__parent(x)) = y;
    else
      __left(__parent(x)) = y;
    __right(y) = x;
    __parent(x) = y;
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#ifdef _RWSTD_NO_TEMPLATE_REPOSITORY
#include <rw/tree.cc>
#endif

#endif /* __STD_TREE__ */

#pragma option pop
#endif /* __TREE_H */
