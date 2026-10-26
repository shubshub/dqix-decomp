#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance();

#if defined(jpn)
struct Struct_ov003_0215fce8_2 { char pad[0x28c]; unsigned int unknown_464_; };
#else
struct Struct_ov003_0215fce8_2 { char pad[0x464]; unsigned int unknown_464_; };
#endif

// USA: func_ov003_02160b2c
extern "C" ARM void func_ov003_02160b2c(Struct_ov003_0215fce8_2* obj) {
	if (!(obj->unknown_464_ & 0x20000)) {
#if defined(jpn)
		*(unsigned char*)(MessageSystem_GetInstance() + 0x1000 + 0x7de) = 0;
#else
		*(unsigned char*)(MessageSystem_GetInstance() + 0x1000 + 0x9ae) = 0;
#endif
	}
}
