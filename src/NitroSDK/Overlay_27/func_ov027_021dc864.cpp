#include <globaldefs.h>

// USA: func_ov027_021dc864
extern "C" ARM int func_ov027_021dc864(unsigned int a, unsigned int b, int c) {
	if (a > 0x1fe || a < 0xe4) return 0;
	if (b > 0x10 || b < 0x8) return 0;
	return ((int)(c * ((b + 0x20) * 4 + 0x70) + ((a + 0x26) * 4 + 0x4a + 0x100)) < 0x15e0) ? 1 : 0;
}
