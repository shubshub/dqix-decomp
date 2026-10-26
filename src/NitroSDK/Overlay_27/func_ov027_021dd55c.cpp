#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int func_ov027_021dd3b0();
extern "C" void func_ov027_021dd3f8(void *a, int b, int c, int d);

struct Struct_ov027_021e3420_4 {
	void *field0;
};

extern struct Struct_ov027_021e3420_4 data_ov027_021e3420;

// USA: func_ov027_021dd55c
extern "C" ARM void func_ov027_021dd55c(int value) {
	int state = DisableIRQInterrupts();
	int r = func_ov027_021dd3b0();
	if (r != 0) {
		func_ov027_021dd3f8((char *)data_ov027_021e3420.field0 + 0xc4, 0, value, 0);
	}
	SetIRQInterruptState(state);
}
