/* String.h - stub redirector for either _str.h or string.stl
*/

#if !defined(__cplusplus)
#  include <_str.h>
#else /* __cplusplus */
#  include <_str.h>
#  if defined(__USING_STD_NAMES__)
#    include <string.stl>
#  endif /* __USING_STD_NAMES__ */
#endif /* __cplusplus */
