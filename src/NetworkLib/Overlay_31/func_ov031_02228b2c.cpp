#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02228b78(void);

// USA: func_ov031_02228b2c
extern "C" ARM void func_ov031_02228b2c(void) {
	if (func_ov031_0223c054(1) != 0) return;
	func_ov031_0223c078(3, 1, 0x3f, 0x40);
	func_ov031_0223c078(3, 0, 0x3f, 0x40);
	func_ov031_022274c0((int)func_ov031_02228b78);
}
