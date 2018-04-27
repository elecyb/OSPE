/* Locale.h - stub redirector for either _loc.h or locale.stl
*/

#if !defined(__cplusplus)
#  include <_loc.h>
#else /* __cplusplus */
#  include <_loc.h>
#  if defined(__USING_STD_NAMES__)
#    include <locale.stl>
#  endif /* __USING_STD_NAMES__ */
#endif /* __cplusplus */
