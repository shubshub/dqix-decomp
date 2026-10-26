#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" void* func_ov031_022368e0(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222ac88(void);

// USA: func_ov031_0222ac5c
extern "C" ARM void func_ov031_0222ac5c(void) {
	if (func_ov031_02222e0c() != 0) return;
	func_ov031_022368e0();
	func_ov031_02236878(7);
	func_ov031_022274c0((int)func_ov031_0222ac88);
}
