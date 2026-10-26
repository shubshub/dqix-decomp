#include <globaldefs.h>

extern "C" int func_ov031_0223c054(int);
extern "C" void func_ov031_022274c0(int v);
extern "C" void func_ov031_0222b550(void);

// USA: func_ov031_0222b52c
extern "C" ARM void func_ov031_0222b52c(void) {
	if (func_ov031_0223c054(0) != 0) return;
	func_ov031_022274c0((int)func_ov031_0222b550);
}
