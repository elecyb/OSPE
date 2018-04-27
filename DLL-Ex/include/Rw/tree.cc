#ifndef __TREE_CC
#define __TREE_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig

/***************************************************************************
 *
 * tree.cc - Non-nline tree definitions for the Standard Library
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

#include <stdcomp.h>

#ifndef _RWSTD_NO_NAMESPACE
namespace __rwstd {
#endif

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  void __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::__deallocate_buffers ()
  {
    while (__buffer_list.data())
    {
      __buffer_pointer tmp = __buffer_list;
      __buffer_list        = (__buffer_pointer)(__buffer_list.data()->next_buffer);
      __node_alloc_type(__buffer_list).deallocate(tmp->buffer,tmp->size);
      __buffer_alloc_type(__buffer_list).deallocate(tmp,1);
    }
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::
  operator= (const __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>& x)
  {
    if (!(this == &x))
    {
      //
      // Can't be done as in list because _Key may be a constant type.
      //
      erase(begin(), end());
      __root() = __copy(x.__root(), __header);
      if (__isNil(__root()))
      {
        __leftmost()  = __header; __rightmost() = __header;
      }
      else
      {
        __leftmost()  = __minimum(__root()); __rightmost() = __maximum(__root());
      }
      __node_count = x.__node_count;
    }
    return *this;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::iterator
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::
  __insert (__link_type x, __link_type y, const _Val& v)
  {
    __link_type z = __get_node(v);
    ++__node_count;
    if (y == __header || !__isNil(x) || __key_compare(_KeyOf()(v), __key(y)))
    {
      __left(y) = z;  // Also makes __leftmost() = z when y == __header.
      if (y == __header)
      {
        __root() = z; __rightmost() = z;
      }
      else if (y == __leftmost())
        __leftmost() = z;   // Maintain __leftmost() pointing to minimum node.
    }
    else
    {
      __right(y) = z;
      if (y == __rightmost())
        __rightmost() = z;  // Maintain __rightmost() pointing to maximum node.
    }
    __parent(z) = y;
    x = z;  // Recolor and rebalance the tree.
    while (x != __root() && __color(__parent(x)) == __rb_red) 
    {
      if (__parent(x) == __left(__parent(__parent(x))))
      {
        y = __right(__parent(__parent(x)));
        if (!__isNil(y) && __color(y) == __rb_red)
        {
          __color(__parent(x))         = __rb_black;
          __color(y)                 = __rb_black;
          __color(__parent(__parent(x))) = __rb_red;
          x                        = __parent(__parent(x));
        }
        else
        {
          if (x == __right(__parent(x)))
          {
            x = __parent(x); 
            __rotate_left(x);
          }
          __color(__parent(x)) = __rb_black;
          __color(__parent(__parent(x))) = __rb_red;
          __rotate_right(__parent(__parent(x)));
        }
      }
      else
      {
        y = __left(__parent(__parent(x)));
        if (!__isNil(y) && __color(y) == __rb_red)
        {
          __color(__parent(x))         = __rb_black;
          __color(y)                 = __rb_black;
          __color(__parent(__parent(x))) = __rb_red;
          x                        = __parent(__parent(x));
        }
        else
        {
          if (x == __left(__parent(x)))
          {
            x = __parent(x); 
            __rotate_right(x);
          }
          __color(__parent(x))         = __rb_black;
          __color(__parent(__parent(x))) = __rb_red;
          __rotate_left(__parent(__parent(x)));
        }
      }
    }
    __color(__root()) = __rb_black;
    return iterator(z);
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::pair_iterator_bool
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::insert (const _Val& v)
  {
    __link_type y = __header;
    __link_type x = __root();
    bool _RWSTD_COMP   = true;
    while (!__isNil(x))
    {
      y    = x;
      _RWSTD_COMP = __key_compare(_KeyOf()(v), __key(x));
      x    = _RWSTD_COMP ? __left(x) : __right(x);
    }
    if (__insert_always)
    {
      pair_iterator_bool tmp(__insert(x, y, v), true); return tmp;
    }
    iterator j = iterator(y);   
    if (_RWSTD_COMP)
    {
      if (j == begin())  
      {
        pair_iterator_bool tmp(__insert(x, y, v), true); return tmp;
      }
      else
        --j;
    }
    if (__key_compare(__key(j.node), _KeyOf()(v)))
    {
      pair_iterator_bool tmp(__insert(x, y, v), true); return tmp;
    }
    pair_iterator_bool tmp(j, false);
    return tmp;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::iterator 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::insert (iterator position,
                                                        const _Val& v)
  {
    if (position == iterator(begin()))
    {
      if (size() > 0 && __key_compare(_KeyOf()(v), __key(position.node)))
        return __insert(position.node, position.node, v);
      //
      // First argument just needs to be non-NIL.
      //
      else
        return insert(v).first;
    }
    else if (position == iterator(end()))
    {
      if (__key_compare(__key(__rightmost()), _KeyOf()(v)))
        return __insert(__nil(), __rightmost(), v);
      else
        return insert(v).first;
    }
    else
    {
      iterator before = --position;
      if (__key_compare(__key(before.node), _KeyOf()(v))
          && __key_compare(_KeyOf()(v), __key(position.node)))
      {
        if (__isNil(__right(before.node)))
          return __insert(__nil(), before.node, v); 
        else
          return __insert(position.node, position.node, v);
        //
        // First argument just needs to be non-NIL.
        //
      }
      else
        return insert(v).first;
    }
  }

#ifndef _RWSTD_NO_MEMBER_TEMPLATES
  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  template<class Iterator>
  void __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::insert (Iterator first, 
                                                             Iterator last)
  {
    while (first != last) insert(*first++);
  }
#else
  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  void __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::insert (const_iterator first, 
                                                             const_iterator last)
  {
    while (first != last) insert(*first++);
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  void __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::insert (const _Val* first, 
                                                             const _Val* last)
  {
    while (first != last) insert(*first++);
  }
#endif
         
  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::iterator 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::erase (iterator position)
  {
    iterator tmp = position; // Retain 'next' position for return
    if (tmp != end())
      tmp++;

    __link_type z;
    _RW_STD::__initialize(z, __link_type(position.node));
    __link_type y = z;
    __link_type x;
    bool __deleted = false;
    if (__isNil(__left(y)))
    {
      if (__isNil(__right(y)))
      {
        x = __parent(y);
        __erase_leaf(y);
        __deleted = true;
      }
      else
        x = __right(y); 
    }
    else
    {
      if (__isNil(__right(y))) 
        x = __left(y);
      else
      {
        y = __right(y);
        while (!__isNil(__left(y))) y = __left(y);
        x = __right(y);
      }
    }
    if (!__deleted && y != z)
    {
      //
      // Relink y in place of z.
      //
      __parent(__left(z)) = y; 
      __left(y) = __left(z);
      if (y != __right(z))
      {
        if (!__isNil(x))
          __parent(x)        = __parent(y);
        __left(__parent(y))  = x;         // Y must be a left child.
        __right(y)         = __right(z);
        __parent(__right(z)) = y;
      }
      else if (!__isNil(x))
        __parent(x) = y;  

      if (__root() == z)
        __root() = y;
      else if (__left(__parent(z)) == z)
        __left(__parent(z)) = y;
      else 
        __right(__parent(z)) = y;

      __parent(y) = __parent(z);
      if (__isNil(x))
        x = y;       // Don't want to start balancing with nil
#ifndef _RWSTD_NO_NAMESPACE
      std::swap(__color(y), __color(z));
#else
      ::swap(__color(y), __color(z));
#endif
      y = z;        // y points to node to be actually deleted.
    }
    else if (!__deleted)
    {
      //
      // y == z
      //
      __parent(x) = __parent(y);   
      if (__root() == z)
        __root() = x;
      else 
      {
        if (__left(__parent(z)) == z)
          __left(__parent(z)) = x;
        else
          __right(__parent(z)) = x;
      }
      if (__leftmost() == z) 
      {
        if (__isNil(__right(z)))  // __left(z) must be NIL also.
          __leftmost() = __parent(z);
        else
          __leftmost() = __minimum(x);
      }
      if (__rightmost() == z)  
      {
        if (__isNil(__left(z))) // __right(z) must be NIL also.
          __rightmost() = __parent(z);
        else
          __rightmost() = __maximum(x);
      }
    }
    if (x != __header && __color(y) != __rb_red)
    { 
      while (x != __root() && __color(x) == __rb_black)
      {
        if (x == __left(__parent(x)))
        {
          __link_type w = __right(__parent(x));
          if (__isNil(w))
          {
            __color(x) = __rb_red;
            x = __parent(x);
          }
          else
          {
            if (__color(w) == __rb_red)
            {
              __color(w)         = __rb_black;
              __color(__parent(x)) = __rb_red;
              __rotate_left(__parent(x));
              w = __right(__parent(x));
            }
            if (__isNil(w))
            {
              __color(x) = __rb_red;
              x = __parent(x);
            }
            else if ((__isNil(__left(w)) || __color(__left(w)) == __rb_black) && 
                (__isNil(__right(w)) || __color(__right(w)) == __rb_black))
            {
              __color(w) = __rb_red;
              x = __parent(x);
            }
            else
            {
              if (__isNil(__right(w)) || __color(__right(w)) == __rb_black)
              {
                if (!__isNil(__left(w)))
                  __color(__left(w)) = __rb_black;
                __color(w)       = __rb_red;
                __rotate_right(w);
                w = __right(__parent(x));
              }
              if (!__isNil(w))
              {
                __color(w) = __color(__parent(x));
                __color(__parent(x)) = __rb_black;
                if (!__isNil(__right(w)))
                  __color(__right(w))  = __rb_black;
                __rotate_left(__parent(x));
              }          
              break;
            }
          }
        }
        else
        {
          //
          // Same as then clause with "right" and "left" exchanged.
          //
          __link_type w = __left(__parent(x));
          if (__isNil(w))
          {
            __color(x) = __rb_red;
            x = __parent(x);
          }
          else
          {
            if (__color(w) == __rb_red)
            {
              __color(w)         = __rb_black;
              __color(__parent(x)) = __rb_red;
              __rotate_right(__parent(x));
              w = __left(__parent(x));
            }
            if (__isNil(w))
            {
              __color(x) = __rb_red;
              x = __parent(x);
            }
            else if ((__isNil(__right(w)) || __color(__right(w)) == __rb_black) &&
              (__isNil(__left(w)) || __color(__left(w)) == __rb_black))
            {
              __color(w) = __rb_red; x = __parent(x);
            }
            else
            {
              if (__isNil(__left(w)) || __color(__left(w)) == __rb_black)
              {
                if (!__isNil(__right(w)))
                  __color(__right(w)) = __rb_black;
                __color(w)        = __rb_red;
                __rotate_left(w);
                w = __left(__parent(x));
              }
              if (!__isNil(w))
              {
                __color(w) = __color(__parent(x));
                __color(__parent(x)) = __rb_black;
                if (!__isNil(__left(w)))
                  __color(__left(w))   = __rb_black;
                __rotate_right(__parent(x));
              }
              break;
            }
          }
        }
      }
      __color(x) = __rb_black;
    }
    __put_node(y);
    --__node_count;
    return tmp;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::size_type 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::erase (const _Key& x)
  {
    pair_iterator_iterator p = equal_range(x);
    size_type n;
    _RW_STD::__initialize(n, size_type(0));
    _RW_STD::distance(p.first, p.second, n);
    erase(p.first, p.second);
    return n;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::__link_type 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::__copy (__link_type x, __link_type p)
  {
    //
    // Structural copy.
    // 
    __link_type r = x;
    while (!__isNil(x))
    {
      __link_type y = __get_node(__value(x));
      if (r == x) r = y;  // Save for return value.
      __left(p)   = y;
      __parent(y) = p;
      __color(y)  = __color(x);
      __right(y)  = __copy(__right(x), y);
      p         = y;
      x         = __left(x);
    }
    __left(p) = __nil();
    return r;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  void __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::__erase (__link_type x)
  {
    //
    // Erase without rebalancing.
    //
    while (!__isNil(x))
    {
      __erase(__right(x));
      __link_type y = __left(x);
      __put_node(x);
      x = y;
    }
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::iterator 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::erase (iterator first, 
                                                       iterator locallast)
  {
    iterator tmp = end();
    if (first == begin() && locallast == end() && __node_count != 0)
    {
      __erase(__root());
      __leftmost()  = __header;
      __root()      = __nil();
      __rightmost() = __header;
      __node_count  = 0;
      tmp = end();
    } else
    {
      while (first != locallast) 
        tmp =  erase(first++);
    }
    return tmp;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  void __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::erase (const _Key* first, 
                                                            const _Key* last)
  {
    while (first != last) erase(*first++);
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::iterator 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::find (const _Key& k) const
  {
    __link_type y = __header;  // Last node that is not less than k.
    __link_type x = __root();  // Current node.

    while (!__isNil(x))
    {
      if (!__key_compare(__key(x), k))
        y = x, x = __left(x);
      else
        x = __right(x);
    }
    iterator j = iterator(y);
    return (j == end() || __key_compare(k, __key(j.node))) ? end() : j;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::size_type 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::count (const _Key& k) const
  {
    _RW_STD::pair<iterator, iterator> p = equal_range(k);
    size_type n;
    _RW_STD::__initialize(n, size_type(0));
    _RW_STD::distance(p.first, p.second, n);
    return n;
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::iterator 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::lower_bound (const _Key& k) const
  {
    __link_type y = __header;  // Last node that is not less than k.
    __link_type x = __root();  // Current node.

    while (!__isNil(x))
    {
      if (!__key_compare(__key(x), k))
        y = x, x = __left(x);
      else
        x = __right(x);
    }

    return iterator(y);
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::iterator 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::upper_bound (const _Key& k) const
  {
    __link_type y = __header;  // Last node that is greater than k.
    __link_type x = __root();  // Current node.

    while (!__isNil(x))
    {
      if (__key_compare(k, __key(x)))
        y = x, x = __left(x);
      else
        x = __right(x);
    }

    return iterator(y);
  }

  template <class _Key, class _Val, class _KeyOf, class _Comp, class _Alloc>
  _TYPENAME __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::pair_iterator_iterator 
  __rb_tree<_Key, _Val, _KeyOf, _Comp, _Alloc>::equal_range (const _Key& k) const
  {
    pair_iterator_iterator tmp(lower_bound(k), upper_bound(k));
    return tmp;
  }

#ifndef _RWSTD_NO_NAMESPACE
}
#endif
#pragma option pop
#endif /* __TREE_CC */
