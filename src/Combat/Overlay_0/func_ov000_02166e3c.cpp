#include <globaldefs.h>

extern "C" void func_ov000_02160fa8(void* work, int mask);

// USA: func_ov000_02166e3c
extern "C" ARM void func_ov000_02166e3c(void* work) {
	func_ov000_02160fa8(work, 2);
	func_ov000_02160fa8(work, 4);
}
