#include <globaldefs.h>

extern "C" void func_ov031_02230f20(void);
extern "C" void func_ov031_022239f4(void);
extern "C" void func_ov031_02236174(void);
extern "C" void func_ov031_02230fb4(void);
extern "C" void func_ov031_022274c0(int v);

// USA: func_ov031_02230f00
extern "C" ARM void func_ov031_02230f00(void) {
	func_ov031_02230f20();
	func_ov031_022239f4();
	func_ov031_02236174();
	func_ov031_022274c0((int)func_ov031_02230fb4);
}
