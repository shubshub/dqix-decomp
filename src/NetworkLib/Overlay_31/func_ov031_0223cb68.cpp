#include <globaldefs.h>

// USA: func_ov031_0223cb68
extern "C" ARM void func_ov031_0223cb68(int channel, int mask) {
	if (channel == 1) {
		unsigned int hi = *(volatile unsigned int*)0x4001000 & 0x1f00;
		unsigned int lo = *(volatile unsigned int*)0x4001000 & ~0x1f00;
		*(volatile unsigned int*)0x4001000 = lo | ((mask | (hi >> 8)) << 8);
	} else {
		unsigned int hi = *(volatile unsigned int*)0x4000000 & 0x1f00;
		unsigned int lo = *(volatile unsigned int*)0x4000000 & ~0x1f00;
		*(volatile unsigned int*)0x4000000 = lo | ((mask | (hi >> 8)) << 8);
	}
}
