#include <globaldefs.h>

// USA: func_ov001_0215b598
extern "C" ARM void func_ov001_0215b598(int on) {
	volatile unsigned short* var0 = (volatile unsigned short*)0x4000304;
	*var0 = (*var0 & ~0x8000) | (on << 15);
}
