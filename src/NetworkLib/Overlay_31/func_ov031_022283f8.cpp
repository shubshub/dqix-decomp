#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_0223c078(int, int, int, int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02228444(void);

// USA: func_ov031_022283f8
extern "C" ARM void func_ov031_022283f8(void) {
	if (func_ov031_0223c054(1) != 0) return;
	func_ov031_0223c078(3, 1, 1, 8);
	func_ov031_0223c078(3, 0, 0x16, 8);
	func_ov031_022274c0((int)func_ov031_02228444);
}
