#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" int func_ov031_0220d60c(void);

// USA: func_ov031_0220f040
extern "C" ARM int func_ov031_0220f040(void) {
	int result = 0;
	int base = func_ov031_0220d60c();
	unsigned int state = DisableIRQInterrupts();
	if (base != 0) {
		if (*(int*)((char*)base + 0x2260) == 9 && *(unsigned char*)((char*)base + 0x226b) == 0) {
			result = (int)((char*)base + 0x2144);
		}
	}
	SetIRQInterruptState(state);
	return result;
}
