#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int func_ov027_021dc864(unsigned int a, unsigned int b, int c);

struct Struct_ov027_021e33e0_7 {
	unsigned char pad0[8];
	unsigned char *ptr;
};

extern Struct_ov027_021e33e0_7 data_ov027_021e33e0;

// USA: func_ov027_021dc8d4
extern "C" ARM int func_ov027_021dc8d4(int a, int b) {
	int var0 = DisableIRQInterrupts();
	if (data_ov027_021e33e0.ptr[0x50d] != 0) {
		SetIRQInterruptState(var0);
		return 0;
	}
	if (!func_ov027_021dc864(a, 8, b)) {
		SetIRQInterruptState(var0);
		return 0;
	}
	*(unsigned short *)(data_ov027_021e33e0.ptr + 0x10) = (unsigned short)b;
	*(unsigned short *)(data_ov027_021e33e0.ptr + 0x500) = (unsigned short)a;
	*(unsigned short *)(data_ov027_021e33e0.ptr + 0x502) = 8;
	SetIRQInterruptState(var0);
	return 1;
}
