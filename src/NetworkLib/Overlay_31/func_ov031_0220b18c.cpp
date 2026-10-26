#include <globaldefs.h>

// USA: func_ov031_0220b18c
extern "C" ARM void func_ov031_0220b18c(unsigned char* dst, unsigned int* src, unsigned int arg2) {
	arg2 >>= 2;
	unsigned int i = 0;
	if (arg2 == 0) return;
	do {
		unsigned int v = *src++;
		i++;
		dst[0] = (unsigned char)(v >> 0x18);
		dst[1] = (unsigned char)(v >> 0x10);
		dst[2] = (unsigned char)(v >> 0x8);
		dst[3] = (unsigned char)v;
		dst += 4;
	} while (i < arg2);
}
