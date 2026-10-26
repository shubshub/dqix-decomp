#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" void func_ov031_02206a68(void);
extern void* data_ov031_0224e230;

// USA: func_ov031_02206c08
extern "C" ARM void func_ov031_02206c08(void) {
	int state = DisableIRQInterrupts();
	if (data_ov031_0224e230 != 0) {
		do {
			func_ov031_02206a68();
		} while (data_ov031_0224e230 != 0);
	}
	SetIRQInterruptState(state);
}
