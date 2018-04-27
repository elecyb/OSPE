#ifndef __STDMUTEX_H
#define __STDMUTEX_H
#pragma option push -b -a8 -pc -Vx- -Ve- -w-inl -w-aus -w-sig
#ifndef __RWSTD_MUTEX_H__
#define __RWSTD_MUTEX_H__

/*
 * Declarations for class _RWSTDMutex and _RWSTDGuard.
 *
 * $Id: stdmutex.h,v 1.14 1996/08/28 01:30:38 smithey Exp $
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
 ***************************************************************************
 *
 * This class is a portable implementation of a simple mutex lock
 * to be used for synchronizing multiple threads within a single process.
 * It is not suitable for use among threads of different processes.
 * This code was taken from the tools mutex.h.
 * 
 ***************************************************************************/

#include <stdcomp.h>

#ifndef __RWSTDDEFS_H__
#include <rw/stddefs.h> 
#endif

#ifdef _RWSTD_MULTI_THREAD /* This class only relevant in MT situation */

#if defined(_RWSTD_SOLARIS_THREADS)  /* assuming Solaris 2.1 or greater */
#  include <synch.h>
#  include <thread.h>
   typedef mutex_t _RWSTDMutexType;

#elif defined(_RWSTD_POSIX_D10_THREADS)
#  include <pthread.h>
   typedef pthread_mutex_t _RWSTDMutexType;

#elif defined(_RWSTD_DCE_THREADS)
#  if defined(_RWSTD_NO_DCE_PTHREAD_H)
#    include <pthread.h>
#  else
#    include <dce/pthread.h>
#  endif
   typedef pthread_mutex_t _RWSTDMutexType;
#  define _RWSTD_NEEDS_SEM_INIT
	
#elif defined(__WIN32__)
#  include <windows.h>
   typedef CRITICAL_SECTION _RWSTDMutexType;
#  define _RWSTD_NEEDS_SEM_INIT

#elif defined(__OS2__)
#  include <exception>
#  define INCL_DOSSEMAPHORES
#  define _RWSTD_NEEDS_SEM_INIT
#  include <os2.h>
  typedef HMTX _RWSTDMutexType;
  extern const char* __rw_mutex_exception;

  class _RWSTDExport thread_error : public exception
  {
    public:
      thread_error () _RWSTD_THROW_SPEC_NULL : exception( )
      { ; }
      virtual const char * what () const  _RWSTD_THROW_SPEC_NULL
      {
        return __rw_mutex_exception;
      }
  };                            

#else
#  error Class _RWSTDMutex is not yet supported in this environment
#endif

class _RWSTDMutex
{
  private:

    _RWSTDMutexType mutex;
#if defined(_RWSTD_NEEDS_SEM_INIT)
    int initFlag;
#endif

    void init ();
    //
    // Disallow assignment.
    //
    _RWSTDMutex& operator= (const _RWSTDMutex&);

public:

  enum StaticCtor { staticCtor };

  _RWSTDMutex ();             // Construct the mutex.
  _RWSTDMutex (const _RWSTDMutex&); // Construct the mutex
  _RWSTDMutex (StaticCtor);   // Some statics need special handling.
  ~_RWSTDMutex ();            // Destroy the mutex.

  void acquire ();           // Acquire the mutex.
  void release ();           // Release the mutex.
};

class _RWSTDGuard
{
  private:

    _RWSTDMutex& rwmutex;

  public:

    _RWSTDGuard  (_RWSTDMutex& m);  // Acquire the mutex.
    ~_RWSTDGuard ();               // Release the mutex.
};

/*
** For those OSs that require a non-zero mutex, we must treat static 
** mutexes specially; they may not be initialized when we need them.
** For efficiency, we do conditional compilation in several methods
** based on that need.
*/

inline _RWSTDMutex::_RWSTDMutex (_RWSTDMutex::StaticCtor)
{
    //
    // Empty, because acquire() may already have been used.
    //
}

inline _RWSTDMutex::~_RWSTDMutex () 
{ 
#if defined(_RWSTD_NEEDS_SEM_INIT)
    if (0 == initFlag)
        return;
    else
        initFlag = 0;
#endif
#if defined(_RWSTD_SOLARIS_THREADS)
    mutex_destroy(&mutex); 
#elif defined(_RWSTD_POSIX_D10_THREADS) || defined(_RWSTD_DCE_THREADS)
    pthread_mutex_destroy(&mutex); 
#elif defined(__WIN32__)
    DeleteCriticalSection(&mutex);
#elif defined(__OS2__)
    APIRET rv;
    _RWSTD_THROW_NO_MSG(0 != (rv = DosCloseMutexSem(mutex)),
                thread_error);
#endif
}
void inline _RWSTDMutex::init ()
{ 
#if defined(_RWSTD_SOLARIS_THREADS)
    mutex_init(&mutex, USYNC_THREAD, NULL); 
#elif defined(_RWSTD_POSIX_D10_THREADS)
    pthread_mutex_init(&mutex, 0);
#elif defined(_RWSTD_DCE_THREADS)
    pthread_mutex_init(&mutex, pthread_mutexattr_default);
#elif defined(__WIN32__)
    InitializeCriticalSection(&mutex);
#elif defined(__OS2__)
    APIRET rv;
    _RWSTD_THROW_NO_MSG(0 != (rv = DosCreateMutexSem(0,&mutex,DC_SEM_SHARED,FALSE)),
                thread_error);
#endif
#if defined(_RWSTD_NEEDS_SEM_INIT)
    initFlag = 1;
#endif
}  

inline _RWSTDMutex::_RWSTDMutex () 
{ 
  init(); 
}  // Initialize the mutex.   

inline _RWSTDMutex::_RWSTDMutex (const _RWSTDMutex&)
{ 
  init(); 
}  // Initialize the mutex.   

inline void _RWSTDMutex::acquire ()
{ 
#if defined(_RWSTD_NEEDS_SEM_INIT)
    if(0 == initFlag)
        init();
#endif
#if defined(_RWSTD_SOLARIS_THREADS)
    mutex_lock(&mutex);    
#elif defined(_RWSTD_POSIX_THREADS) || defined(_RWSTD_DCE_THREADS)
    pthread_mutex_lock(&mutex);    
#elif defined(__WIN32__)
    EnterCriticalSection(&mutex);
#elif defined(__OS2__)
    APIRET rv;
    _RWSTD_THROW_NO_MSG(0 != (rv = DosRequestMutexSem(mutex, SEM_INDEFINITE_WAIT)),
               thread_error); 
#endif
}

inline void _RWSTDMutex::release ()
{ 
#if defined(_RWSTD_SOLARIS_THREADS)
    mutex_unlock(&mutex);  
#elif defined(_RWSTD_POSIX_D10_THREADS) || defined(_RWSTD_DCE_THREADS)
    pthread_mutex_unlock(&mutex);  
#elif defined(__WIN32__)
    LeaveCriticalSection(&mutex);
#elif defined(__OS2__)
    APIRET rv;
    _RWSTD_THROW_NO_MSG(0 != (rv = DosReleaseMutexSem(mutex)),
                thread_error);
#endif
}

inline _RWSTDGuard::_RWSTDGuard (_RWSTDMutex& m) : rwmutex(m)
{
    rwmutex.acquire();
}

inline _RWSTDGuard::~_RWSTDGuard () { rwmutex.release(); }

#define STDGUARD(a) _RWSTDGuard(a)
#else
#define STDGUARD(a) 
#endif  /*_RWSTD_MULTI_THREAD*/

#if defined(_RWSTD_MULTI_THREAD) && !defined(_RWSTD_NO_TEST_AND_SET)
#ifdef __WIN32__
#define _RWSTD_MT_INCREMENT(v) InterlockedIncrement(&v)
#define _RWSTD_MT_DECREMENT(v) InterlockedDecrement(&v)
#define _RWSTD_MT_SET(v,new) InterlockedExchange(&v,new)
#else
#define _RWSTD_MT_INCREMENT(v) v++
#define _RWSTD_MT_DECREMENT(v) v--
#define _RWSTD_MT_SET(v,new) v = new
#endif // __WIN32__
#else
#define _RWSTD_MT_INCREMENT(v) v++
#define _RWSTD_MT_DECREMENT(v) v--
#define _RWSTD_MT_SET(v,new) v = new
#endif // _RWSTD_MULTI_THREAD

#endif  /*__RWSTD_MUTEX_H__*/

#pragma option pop
#endif /* __STDMUTEX_H */
