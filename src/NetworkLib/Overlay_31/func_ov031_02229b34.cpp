#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" void func_ov031_02236878(int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02229b5c(void);

// USA: func_ov031_02229b34
extern "C" ARM void func_ov031_02229b34(void) {
	if (func_ov031_02222e0c() != 0) return;
	func_ov031_02236878(6);
	func_ov031_022274c0((int)func_ov031_02229b5c);
}
