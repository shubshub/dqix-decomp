#include <globaldefs.h>

extern "C" signed char func_ov031_02237e9c(void);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222a890(void);

// USA: func_ov031_0222a86c
extern "C" ARM void func_ov031_0222a86c(void) {
	if (func_ov031_02237e9c() == -2) return;
	func_ov031_022274c0((int)func_ov031_0222a890);
}
