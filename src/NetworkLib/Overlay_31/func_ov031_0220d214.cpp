#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220e694(void*);
extern "C" int func_020d5cc8(int value);
extern void* data_ov031_0224e53c;

// USA: func_ov031_0220d214
extern "C" ARM int func_ov031_0220d214(void) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224e53c == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	int v = *(int*)((char*)data_ov031_0224e53c + 0x2000 + 0x260);
	if (v == 3) goto ret0;
	if (v == 9) goto case9;
	if (v != 0xa) goto ret1;
	SetIRQInterruptState(state);
	return 2;
ret0:
	SetIRQInterruptState(state);
	return 0;
ret1:
	SetIRQInterruptState(state);
	return 1;
case9:
	if (*(unsigned char*)((char*)data_ov031_0224e53c + 0x2000 + 0x26b) == 1) {
		func_ov031_0220da1c(0xa);
		*(unsigned short*)((char*)data_ov031_0224e53c + 0x2200 + 0x80) = 6;
		goto ret3;
	}
	{
		int r = func_020d5cc8((int)func_ov031_0220e694);
		switch (r) {
		case 2:
			func_ov031_0220da1c(0xa);
			*(unsigned short*)((char*)data_ov031_0224e53c + 0x2200 + 0x80) = 6;
			goto ret3;
		case 8:
			SetIRQInterruptState(state);
			return 4;
		case 3:
		default:
			func_ov031_0220da1c(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
	}
ret3:
	SetIRQInterruptState(state);
	return 3;
}
