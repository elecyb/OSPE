/* Limits.h - stub redirector for either _lim.h or limits.stl
*/

#if !defined(__cplusplus)
#  include <_lim.h>
#else /* __cplusplus */
#  include <_lim.h>
#  if defined(__USING_STD_NAMES__)
#    include <limits.stl>
#  endif /* __USING_STD_NAMES__ */
#endif /* __cplusplus */
