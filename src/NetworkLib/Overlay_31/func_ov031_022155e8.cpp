#include <globaldefs.h>

// USA: func_ov031_022155e8
extern "C" ARM unsigned int func_ov031_022155e8(unsigned char *p) {
	unsigned int v = 0;
	v |= p[0] << 0x18;
	v |= p[1] << 0x10;
	v |= p[2] << 8;
	v |= p[3];
	return ((v >> 0x18) & 0xff) | ((v >> 8) & 0xff00) | ((v << 8) & 0xff0000) | ((v << 0x18) & 0xff000000);
}
