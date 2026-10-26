#include <globaldefs.h>

#if defined(jpn)
struct Struct_ov003_0215fce8 { char pad[0x2cb]; unsigned char unknown_4a3_; };
#else
struct Struct_ov003_0215fce8 { char pad[0x4a3]; unsigned char unknown_4a3_; };
#endif

extern "C" void func_ov003_0216052c(Struct_ov003_0215fce8* obj);
extern "C" void func_ov003_02160678(Struct_ov003_0215fce8* obj);

// USA: func_ov003_021604d0
extern "C" ARM void func_ov003_021604d0(Struct_ov003_0215fce8* obj) {
	if (obj->unknown_4a3_ != 0) {
		func_ov003_0216052c(obj);
		func_ov003_02160678(obj);
	}
}
