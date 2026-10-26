#include <globaldefs.h>
#include "NitroSDK/Memory/HMRFAllocator.h"

extern "C" int func_020bdc24(void* obj);

struct Obj020bdac0 {
    HMRFAllocator* allocator;   /* 0x00 */
    SignedAllocatorList list;   /* 0x04 */
};

// Main, originally SaveStateAndAllocateChild020bdac0 (USA 0x020bdac0, EUR 0x020bdad0, JPN 0x020bf58c)
extern "C" ARM int NNS_SndHeapSaveState(struct Obj020bdac0* obj) {
    if (!obj->allocator->SaveCurrentState(obj->list.numElements)) return -1;
    if (func_020bdc24(obj)) return obj->list.numElements - 1;
    obj->allocator->RestoreState(0);
    return -1;
}
