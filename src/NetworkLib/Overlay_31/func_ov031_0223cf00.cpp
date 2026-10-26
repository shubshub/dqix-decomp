#include <globaldefs.h>
#include "NitroSDK/Memory/HPXEAllocator.h"
#include "NitroSDK/Interrupts.h"


extern "C" void HaltSystem(void);
extern HPXEAllocator* data_ov031_02290d3c;

// USA: func_ov031_0223cf00
extern "C" ARM void* func_ov031_0223cf00(unsigned int len, int align) {
	void* p;
	unsigned int var1;
	var1 = DisableSpecificInterrupts(1);
	p = data_ov031_02290d3c->Allocate(len, align);
	if (p == NULL) {
		HaltSystem();
	}
	EnableSpecificInterrupts(var1);
	return p;
}
