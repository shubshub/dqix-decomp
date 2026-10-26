#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

unsigned int DisableIRQInterrupts(void);
unsigned int SetIRQInterruptState(int mask);

extern SafeAllocator data_ov031_02291e3c;

// USA: func_ov031_022434e8
extern "C" ARM void func_ov031_022434e8(void* unused, void* ptr) {
    if (ptr) {
        unsigned int mask = DisableIRQInterrupts();
        data_ov031_02291e3c.Free(ptr);
        SetIRQInterruptState(mask);
    }
}
