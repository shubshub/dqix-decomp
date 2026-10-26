#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "NitroSDK/Cache.h"

extern int data_ov031_0224e53c;

extern "C" void func_ov031_0220d73c(int, int, int);
extern "C" void func_ov031_0220da1c(int);
extern "C" void func_ov031_0220defc(void);

struct Struct_02101680;
extern "C" int func_020d5340(int a0, struct Struct_02101680* ctx);

// USA: func_ov031_0220cdf4
extern "C" ARM int func_ov031_0220cdf4(int a, int b, int c) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224e53c == 0) {
		SetIRQInterruptState(state);
		return 1;
	}
	int mode = *(int*)((char*)data_ov031_0224e53c + 0x2260);
	switch (mode) {
	case 5:
		func_ov031_0220d73c(a, b, c);
		SetIRQInterruptState(state);
		return 2;
	case 6:
		func_ov031_0220d73c(a, b, c);
		SetIRQInterruptState(state);
		return 0;
	default:
		SetIRQInterruptState(state);
		return 1;
	case 3: {
		func_ov031_0220d73c(a, b, c);
		InvalidateDataCacheRange(*(void**)((char*)data_ov031_0224e53c + 0x2288), *(unsigned short*)((char*)data_ov031_0224e53c + 0x228c));
		*(int*)((char*)data_ov031_0224e53c + 0x2284) += 1;
		int r = func_020d5340((int)func_ov031_0220defc, (struct Struct_02101680*)((char*)data_ov031_0224e53c + 0x2288));
		switch (r) {
		case 2:
			func_ov031_0220da1c(5);
			*(unsigned short*)((char*)data_ov031_0224e53c + 0x2280) = 3;
			break;
		case 8:
			SetIRQInterruptState(state);
			return 4;
		case 3:
		default:
			func_ov031_0220da1c(0xb);
			SetIRQInterruptState(state);
			return 7;
		}
		SetIRQInterruptState(state);
		return 3;
	}
	}
}
