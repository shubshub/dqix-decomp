#include <globaldefs.h>

extern "C" int func_ov031_02222e0c(void);
extern "C" void func_ov031_02222e80(void);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222871c(void);

// USA: func_ov031_022286f4
extern "C" ARM void func_ov031_022286f4(void) {
	if (func_ov031_02222e0c() == -2) return;
	func_ov031_02222e80();
	func_ov031_022274c0((int)func_ov031_0222871c);
}
