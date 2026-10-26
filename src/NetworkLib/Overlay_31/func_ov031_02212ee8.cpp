#include <globaldefs.h>

extern "C" int func_ov031_022134b0(void);
extern "C" int func_ov031_02214334(void);
extern "C" int func_ov031_022151d4(void);
extern "C" int func_ov031_02214a04(void);
extern "C" void func_ov031_02213450(int);
extern "C" int func_ov031_02213c9c(void);
extern "C" int func_ov031_02214928(void);
extern "C" int func_ov031_0221525c(void);
extern "C" int func_ov031_022135f4(void);
extern "C" void func_ov031_022135bc(void);
unsigned int DisableIRQInterrupts(void);
void SetIRQInterruptState(int);

// USA: func_ov031_02212ee8
extern "C" ARM int func_ov031_02212ee8(void) {
	unsigned int r5 = func_ov031_022134b0();
	if (r5 == 1) {
		r5 = func_ov031_022151d4();
	} else if (r5 < 7) {
		unsigned int var1 = DisableIRQInterrupts();
		r5 = func_ov031_02214a04();
		func_ov031_02213450(r5);
		SetIRQInterruptState(var1);
	} else if (r5 < 9) {
		r5 = func_ov031_02213c9c();
	} else if (r5 < 0xa) {
		r5 = func_ov031_02214928();
	} else if (r5 < 0x10) {
		r5 = func_ov031_0221525c();
	} else if (r5 == 0x11) {
		r5 = func_ov031_02214334();
	}
	func_ov031_02213450(r5);
	if (r5 == 0x10) {
		int t = func_ov031_022135f4();
		func_ov031_022135bc();
		return t;
	} else if (r5 != 0x12) {
		return 0;
	} else {
		func_ov031_022135bc();
		return -1;
	}
}
