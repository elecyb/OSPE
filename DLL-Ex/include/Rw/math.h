/* Borland Stub since the real MATH.H does all the correct things that Rogue
   Wave needs. */

#ifdef __MFC_COMPAT__
/* When the -VF switch is on, also enabled is the -VI include path scheme for
   <> as well as "" #includes.  Thus we must path our way to the main include
   directory for math.h else the compiler will abort from recursively
   including this math.h too many times. */
#include <..\math.h>
#else
#include <math.h>
#endif