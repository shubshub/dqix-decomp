#include <globaldefs.h>

extern "C" int func_ov031_0221a780();
extern "C" void func_ov031_0221a4cc();

// USA: func_ov031_02212598
extern "C" ARM int func_ov031_02212598(void) {
	int r = func_ov031_0221a780();
	unsigned int t = r - 3;
	if (t <= 2) func_ov031_0221a4cc();
	return r;
}
