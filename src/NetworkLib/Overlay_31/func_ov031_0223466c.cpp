#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int arg);
extern "C" int func_ov031_02223568(void* obj);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_022346a8(void);

// USA: func_ov031_0223466c
extern "C" ARM void func_ov031_0223466c(void) {
	if (func_ov031_0223c054(1) != 0) {
		return;
	}
	if (func_ov031_0223c054(0) != 0) {
		return;
	}
	func_ov031_02223568((void*)6);
	func_ov031_022274c0((int)func_ov031_022346a8);
}
