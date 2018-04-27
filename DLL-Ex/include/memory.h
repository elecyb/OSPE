/* Memory.h - stub redirector for either mem.h or memory.stl
*/

#if !defined(__cplusplus)
#  include <mem.h>
#else /* __cplusplus */
#  if !defined(__USING_STD_NAMES__)
#    include <mem.h>
#  else /* __USING_STD_NAMES__ */
#    include <memory.stl>
#  endif /* __USING_STD_NAMES__ */
#endif /* __cplusplus */
