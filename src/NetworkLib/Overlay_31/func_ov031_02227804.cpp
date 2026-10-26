#include <globaldefs.h>

extern "C" int func_ov031_0223a5bc(void);
extern "C" void func_ov031_0223e2c0(int, void*);
extern char* data_ov031_02290c44;

// USA: func_ov031_02227804
extern "C" ARM void func_ov031_02227804(void* a0) {
	if (func_ov031_0223a5bc() == 0) return;
	*(char*)(data_ov031_02290c44 + 0x1e000 + 0x2a1) = 1;
	func_ov031_0223e2c0(0, a0);
}
