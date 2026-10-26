#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int func_ov031_0220d60c(void);

struct Struct_ov031_0220eb30 { char pad[0x270]; int* unknown_270_; unsigned int unknown_274_; };

// USA: func_ov031_0220eb30
extern "C" ARM int func_ov031_0220eb30(void) {
	int state = DisableIRQInterrupts();
	int base = func_ov031_0220d60c();
	int result = 0;
	if (base == 0) {
		SetIRQInterruptState(state);
		return result;
	}
	struct Struct_ov031_0220eb30* t = (struct Struct_ov031_0220eb30*)(base + 0x2000);
	if (t->unknown_270_ != NULL) {
		if (t->unknown_274_ > 0xc) {
			result = *t->unknown_270_;
		}
	}
	SetIRQInterruptState(state);
	return result;
}
