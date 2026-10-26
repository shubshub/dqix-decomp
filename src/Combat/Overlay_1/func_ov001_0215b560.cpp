#include <globaldefs.h>

extern "C" void func_ov001_0215b598(int flag);

// USA: func_ov001_0215b560
extern "C" ARM int func_ov001_0215b560(void) {
	volatile unsigned short* reg = (volatile unsigned short*)0x4000304;
	int bit = (*reg & 0x8000) >> 0xf;
	if (!bit) {
		func_ov001_0215b598(1);
	} else {
		func_ov001_0215b598(0);
	}
	return 1;
}
