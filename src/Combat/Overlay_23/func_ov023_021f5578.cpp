#include <globaldefs.h>

extern "C" unsigned int* func_ov023_021f5534(void* a, void* b);

// USA: func_ov023_021f5578
extern "C" ARM int func_ov023_021f5578(void* a, void* b, int arg2) {
	unsigned int* p = func_ov023_021f5534(a, b);
	if (p != 0) arg2 = *p >> 0x1a;
	return arg2;
}
