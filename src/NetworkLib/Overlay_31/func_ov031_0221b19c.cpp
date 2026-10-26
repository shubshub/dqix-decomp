#include <globaldefs.h>

// USA: func_ov031_0221b19c
extern "C" ARM void func_ov031_0221b19c(int arg0, unsigned char *buf) {
	unsigned int var0 = ~0u;
	unsigned int mask = var0 ^ (var0 >> arg0);
	int i = 0;
	int var3 = 0;
	do {
		buf[i] = mask >> (0x18 - var3);
		i++;
		var3 += 8;
	} while (i < 4);
}
