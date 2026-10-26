#include <globaldefs.h>

struct Struct_0204a120_2;
extern "C" void Camera_Init(void* obj);
extern "C" void func_020a2cf0(struct Struct_0204a120_2* obj);
extern "C" void func_020a2010(void* obj);

// USA: func_ov004_021633e4
extern "C" ARM void* func_ov004_021633e4(void* obj) {
	Camera_Init(obj);
	func_020a2cf0((struct Struct_0204a120_2*)obj);
	func_020a2010(obj);
	return obj;
}
