#include <globaldefs.h>
#include "NitroSDK/ProcessorContext.h"
#include "NitroSDK/Interrupts.h"

void CycleCurrentPriorityContexts();

// USA: func_ov031_02203500
extern "C" ARM int func_ov031_02203500(unsigned int* out, void* obj) {
	if (*(unsigned int*)((char*)obj + 0x44) == 0 && *(unsigned char*)((char*)obj + 8) == 4) {
		int var0 = DisableIRQInterrupts();
		while (*(unsigned int*)((char*)obj + 0x44) == 0 && *(unsigned char*)((char*)obj + 8) == 4) {
			*(unsigned int*)((char*)obj + 4) = 2;
			BlockCurrentContext(NULL);
		}
		SetIRQInterruptState(var0);
	} else {
		CycleCurrentPriorityContexts();
	}
	unsigned int v = *(unsigned int*)((char*)obj + 0x44);
	*out = v;
	return v != 0 ? *(int*)((char*)obj + 0x40) : 0;
}
