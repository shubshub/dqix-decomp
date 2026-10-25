#include <globaldefs.h>

int MessageSystem_GetInstance();

#if defined(jpn)
struct S02160b2c { char pad[0x28c]; unsigned int flags464; };
#else
struct S02160b2c { char pad[0x464]; unsigned int flags464; };
#endif

// USA: func_ov003_02160b2c
ARM void ClearGlobalField9ae_02160b2c(S02160b2c* obj) {
	if (!(obj->flags464 & 0x20000)) {
#if defined(jpn)
		*(unsigned char*)(MessageSystem_GetInstance() + 0x1000 + 0x7de) = 0;
#else
		*(unsigned char*)(MessageSystem_GetInstance() + 0x1000 + 0x9ae) = 0;
#endif
	}
}
