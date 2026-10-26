#include <globaldefs.h>

extern "C" int MessageSystem_GetInstance(void);
extern "C" void func_0204359c(void* obj, int count);
extern "C" void func_020439b0(void* a, int b);

// USA: func_ov017_021acd00
extern "C" ARM void func_ov017_021acd00(void*) {
	void* x = (void*)MessageSystem_GetInstance();
	func_0204359c(x, 2);
	func_020439b0(x, 0);
}
