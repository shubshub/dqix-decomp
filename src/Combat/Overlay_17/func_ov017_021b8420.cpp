#include <globaldefs.h>

extern "C" void func_ov000_02160c60(void* work);

// USA: func_ov017_021b8420
extern "C" ARM void func_ov017_021b8420(void* obj) {
	void* p = *(void**)((char*)obj + 0x6ac);
	if (p) func_ov000_02160c60(p);
}
