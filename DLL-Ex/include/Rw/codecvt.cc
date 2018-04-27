#ifndef __CODECVT_CC
#define __CODECVT_CC
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
/***************************************************************************
 *
 * codecvt.cc - Definitions for the Standard Library code conversion facet
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

#ifndef _RWSTD_NO_NAMESPACE
namespace std {
#endif

// -------------------------------------------------------
// Facet codecvt<internT,externT,stateT> member templates.
// -------------------------------------------------------

#ifndef _RWSTD_NO_TEMPLATE_STATIC_ID
template <class internT,class externT,class stateT>
locale::id codecvt<internT,externT,stateT>::id;
#endif

template <class internT,class externT,class stateT>
codecvt<internT,externT,stateT>::~codecvt() {}

template <class internT, class externT, class stateT>
codecvt_base::result
codecvt<internT,externT,stateT>::do_out (stateT&,
    const internT*, const internT*, const internT*&,
    externT*, externT*, externT*&) const
{
  return noconv;
}

template <class internT, class externT, class stateT>
codecvt_base::result
codecvt<internT,externT,stateT>::do_in (stateT&,
    const externT*, const externT*, const externT*&,
    internT*, internT*, internT*&) const
{
  return noconv;
}

template <class internT, class externT, class stateT>
codecvt_base::result
codecvt<internT,externT,stateT>::do_unshift (stateT&,
    externT*, externT*, externT*&) const
{
  return noconv;
}

template <class internT,class externT,class stateT>
int codecvt<internT,externT,stateT>::do_encoding()
    const _RWSTD_THROW_SPEC_NULL
{
  return sizeof(internT) == sizeof(externT);
}

template <class internT,class externT,class stateT>
bool codecvt<internT,externT,stateT>::do_always_noconv ()
    const _RWSTD_THROW_SPEC_NULL
{
  return true;
}

template <class internT,class externT,class stateT>
int codecvt<internT,externT,stateT>::do_length (const stateT&,
    const externT *from, const externT *from_end, size_t max) const
{
  return min (size_t(from_end-from), max);
}

template <class internT,class externT,class stateT>
int codecvt<internT,externT,stateT>::do_max_length ()
    const _RWSTD_THROW_SPEC_NULL
{
  return 1;
}

template <class internT,class externT,class stateT>
_TYPENAME codecvt<internT,externT,stateT>::internal_string_type
codecvt<internT,externT,stateT>::in (const external_string_type &s) const
{
  // Calculate the number of internT's that will be produced.  (I'm not sure
  // what to use for max in the do_length call; too bad char_traits can't tell
  // me.) (This needs to be revised to use separate in and out versions of
  // do_length once someone comes up with the right syntax.)
  int n=1000; // do_length(stateT(0),s.c_str(),s.c_str()+s.length(),
              // numeric_limits<size_t>::max() / do_max_length());

  const externT *unused_from;
  internT *unused_to;

  internT *conversion_buffer=new internT[n];
  stateT stt(0);
  n=do_in(stt,s.c_str(),s.c_str()+s.length(),unused_from,
      conversion_buffer,conversion_buffer+n,unused_to);
  internal_string_type result(conversion_buffer,conversion_buffer+n);
  delete[] conversion_buffer;
  return result;
}

// --------------------------------------------------------------
// Facet codecvt_byname<internT,externT,stateT> member templates.
// --------------------------------------------------------------

template <class internT, class externT, class stateT>
codecvt_byname<internT,externT,stateT>::codecvt_byname
    (const char*, size_t refs):
    codecvt<internT,externT,stateT>(refs)
{ }

template <class internT, class externT, class stateT>
codecvt_byname<internT,externT, stateT>::~codecvt_byname ()
{ }

template <class internT, class externT, class stateT>
codecvt_base::result 
codecvt_byname<internT,externT, stateT>::do_out (stateT&,
    const internT*, const internT*, const internT*&,
          externT*, externT*, externT*&) const
{
  return codecvt_base::error;
}

template <class internT, class externT, class stateT>
codecvt_base::result
codecvt_byname<internT,externT, stateT>::do_in (stateT&,
    const externT*, const externT*, const externT*&,
          internT*, internT*, internT*&) const
{
  return codecvt_base::error;
}

template <class internT, class externT, class stateT>
codecvt_base::result
codecvt_byname<internT,externT,stateT>::do_unshift (stateT&,
          externT*, externT*, externT*&) const
{
  return codecvt_base::error;
}

template <class internT, class externT, class stateT>
int codecvt_byname<internT,externT,stateT>::do_encoding () const
    _RWSTD_THROW_SPEC_NULL
{
  return -1;
}

template <class internT, class externT, class stateT>
bool codecvt_byname<internT,externT,stateT>::do_always_noconv () const
    _RWSTD_THROW_SPEC_NULL
{
  return false;
}
#ifndef _RWSTD_NO_NAMESPACE
}
#endif

#pragma option pop
#endif /* __CODECVT_CC */
