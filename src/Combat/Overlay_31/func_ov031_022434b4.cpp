#include <globaldefs.h>
#include "NitroSDK/Interrupts.h"
#include "Memory/SafeAllocator.h"

extern SafeAllocator data_ov031_02291e3c;

// USA: func_ov031_022434b4
extern "C" ARM void* func_ov031_022434b4(int unused, unsigned int size) {
	int state = DisableIRQInterrupts();
	void* p = data_ov031_02291e3c.Allocate(size);
	SetIRQInterruptState(state);
	return p;
}
