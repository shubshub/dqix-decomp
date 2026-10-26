#include <globaldefs.h>

extern "C" void* func_ov031_0223cf4c(unsigned int len, int align);
extern "C" ARM void ColorEffect_ConfigureBrightnessAdjust(unsigned short* dst, int flag, int value);
extern void* data_ov031_02290d34;

// USA: func_ov031_0223bff8
extern "C" ARM void func_ov031_0223bff8(void) {
	data_ov031_02290d34 = func_ov031_0223cf4c(0x18, 4);
	ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4000050, 0x3f, 0x10);
	ColorEffect_ConfigureBrightnessAdjust((unsigned short*)0x4001050, 0x3f, 0x10);
}
