#include <globaldefs.h>
#include "NitroSDK/Memory/HPXEAllocator.h"
#include "NitroSDK/Interrupts.h"


extern "C" void HaltSystem(void);
extern HPXEAllocator* data_ov031_02290d3c;

// USA: func_ov031_0223cf00
ARM void* AllocateFromMainAllocator_0223cf00(unsigned int len, int align) {
	void* p;
	unsigned int irq;
	irq = DisableSpecificInterrupts(1);
	p = data_ov031_02290d3c->Allocate(len, align);
	if (p == NULL) {
		HaltSystem();
	}
	EnableSpecificInterrupts(var1);
	return var0;
}
