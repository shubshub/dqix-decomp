#include <globaldefs.h>

extern "C" void func_ov031_0221ae00(void* buf);
extern "C" void func_ov031_02217604(void* a, void* buf);

// USA: func_ov031_022175dc
extern "C" ARM void func_ov031_022175dc(void* a) {
	unsigned int buf[5];
	func_ov031_0221ae00(buf);
	func_ov031_02217604(a, buf);
}
