#include <globaldefs.h>

#if defined(jpn)
enum { flagOffset = 0x40c };
#else
enum { flagOffset = 0x3f4 };
#endif
struct Struct_ov003_0215caa4 { char pad[flagOffset]; unsigned char unknown_3f4_; };

// USA: func_ov003_0215caa4
extern "C" ARM void func_ov003_0215caa4(struct Struct_ov003_0215caa4* obj) {
	obj->unknown_3f4_ = 1;
}
