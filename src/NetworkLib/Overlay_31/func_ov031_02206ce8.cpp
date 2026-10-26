#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

struct Struct_ov031_02206ce8 { char unknown_0_[0x70]; short flags; char unknown_72_[0xa]; Struct_ov031_02206ce8* next; };

extern "C" void func_ov031_02206900(void* a);
extern void* data_ov031_0224e1cc;
extern Struct_ov031_02206ce8* data_ov031_0224e22c;
extern void* data_ov031_0224e230;

// USA: func_ov031_02206ce8
extern "C" ARM int func_ov031_02206ce8(void* g) {
	Struct_ov031_02206ce8* n;
	for (;;) {
		int state = DisableIRQInterrupts();
		n = data_ov031_0224e22c;
		if (n != 0) {
			void* cur = data_ov031_0224e1cc;
			for (;;) {
				if (n != cur) {
					if ((n->flags & 0x10) == 0) break;
				}
				n = n->next;
				if (n == 0) break;
			}
		}
		SetIRQInterruptState(state);
		if (n == 0) break;
		func_ov031_02206900(n);
	}
	if (data_ov031_0224e22c != 0) {
		if (data_ov031_0224e22c != data_ov031_0224e1cc) goto FAIL;
		if (data_ov031_0224e22c->next != 0) goto FAIL;
	}
	if (data_ov031_0224e230 != 0) goto FAIL;
	return 0;
FAIL:
	return -26;
}
