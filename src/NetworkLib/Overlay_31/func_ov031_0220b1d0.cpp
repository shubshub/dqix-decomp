#include <globaldefs.h>

// USA: func_ov031_0220b1d0
extern "C" ARM void func_ov031_0220b1d0(unsigned int* dst, unsigned char* src, unsigned int len) {
	unsigned int i = 0;
	if (i < len) {
		do {
			unsigned char* p = src + i;
			*dst++ = (p[0] << 0x18) | (p[1] << 0x10) | (p[2] << 8) | p[3];
			i += 4;
		} while (i < len);
	}
}
