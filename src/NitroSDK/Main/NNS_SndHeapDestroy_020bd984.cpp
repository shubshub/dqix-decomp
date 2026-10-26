#include <globaldefs.h>
#include "NitroSDK/Memory/HMRFAllocator.h"

extern "C" void func_020bd99c(void* obj);

struct Obj020bd984 { HMRFAllocator* allocator; };

// Main, originally DestroyAllocator020bd984 (USA 0x020bd984, EUR 0x020bd994, JPN 0x020bf450)
extern "C" ARM void NNS_SndHeapDestroy(struct Obj020bd984* obj) {
    func_020bd99c(obj);
    obj->allocator->RemoveFromTree();
}
