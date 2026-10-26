#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"

extern "C" void func_ov031_02203670(void*);

// USA: func_ov031_02205ebc
extern "C" ARM void* func_ov031_02205ebc(void* obj) {
	void* sub = *(void**)((char*)obj + 0x64);
	int state = DisableIRQInterrupts();
	void* v = *(void**)((char*)sub + 0xf8);
	if (v != NULL) {
		*(void**)((char*)sub + 0xf8) = NULL;
		func_ov031_02203670(v);
	}
	SetIRQInterruptState(state);
	return v;
}
