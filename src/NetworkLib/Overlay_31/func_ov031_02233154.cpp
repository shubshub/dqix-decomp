#include <globaldefs.h>

extern "C" int func_ov031_02237eb0(void);
extern "C" void func_ov031_02222e80(void);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_02232844(void);

// USA: func_ov031_02233154
extern "C" ARM void func_ov031_02233154(void) {
	if (func_ov031_02237eb0() != 0) return;
	func_ov031_02222e80();
	func_ov031_022274c0((int)func_ov031_02232844);
}
