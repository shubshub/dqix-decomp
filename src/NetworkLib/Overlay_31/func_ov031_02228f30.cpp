#include <globaldefs.h>

extern "C" int func_ov031_0223d354(int mask);
extern "C" void func_ov031_02222e20(int v);

// USA: func_ov031_02228f30
extern "C" ARM void func_ov031_02228f30(void) {
	if (func_ov031_0223d354(2) == 0) return;
	func_ov031_02222e20(0);
}
