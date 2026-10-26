#include <globaldefs.h>

// USA: func_ov003_0217063c
extern "C" ARM void func_ov003_0217063c(unsigned char* obj, unsigned short* out1, unsigned short* out2) {
	signed char b1 = (signed char)obj[1];
	unsigned short flags;
	if (b1 == 5) {
		flags = *(unsigned short*)(obj + 0x20);
		if ((flags & 0x10) || (flags & 0x4)) {
			signed char b8;
			*out1 = 0x2c;
			b8 = (signed char)obj[8];
			*out2 = b8 + (b8 << 4) + 0x3a;
			return;
		}
	}
	*out1 = 0;
	*out2 = 0;
}
