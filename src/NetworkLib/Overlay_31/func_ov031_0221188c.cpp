#include <globaldefs.h>

extern "C" void* func_ov031_022123d4(void);
extern "C" void func_ov031_02211138(void);

// USA: func_ov031_0221188c
extern "C" ARM void* func_ov031_0221188c(void) {
	void* result = func_ov031_022123d4();
	if (result == NULL) {
		func_ov031_02211138();
	}
	return result;
}
