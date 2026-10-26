#include <globaldefs.h>

// USA: func_ov031_0221b258
extern "C" ARM int func_ov031_0221b258(unsigned char *p) {
	unsigned char b = *p;
	if (b == 0x7f) return 0;
	if (b < 1) return 0;
	return b <= 0xdf;
}
