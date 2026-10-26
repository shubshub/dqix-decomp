#include <globaldefs.h>
#include "NitroSDK/Memory/HPXEAllocator.h"

unsigned int DisableSpecificInterrupts(unsigned int mask);
ARM unsigned int EnableSpecificInterrupts(unsigned int mask);

extern HPXEAllocator* data_ov031_02290d3c;

// USA: func_ov031_0223cf70
extern "C" ARM unsigned int func_ov031_0223cf70(void** a) {
    unsigned int prev = DisableSpecificInterrupts(1);
    void* p = *a;
    if (p == NULL) {
        return prev;
    }
    data_ov031_02290d3c->Free(p);
    EnableSpecificInterrupts(prev);
    *a = NULL;
    return 0;
}
