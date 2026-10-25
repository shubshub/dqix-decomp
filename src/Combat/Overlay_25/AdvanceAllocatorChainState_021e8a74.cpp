#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

struct State0207dfc8;
void VramState_CopyCurrentTo(State0207dfc8* src, State0207dfc8* dst);

// USA: func_ov025_021e8a74  (semantic: AdvanceAllocatorChainState_021e8a74)
extern "C" ARM void func_ov025_021e8a74(void* arg) {
    unsigned char* obj = (unsigned char*)arg;
    if (obj[0x30] == 3) return;

    unsigned int size = (*(SafeAllocator**)(obj + 0x10 + obj[0x30] * 4))->GetMaxPossibleAllocation();
    void* buf = (*(SafeAllocator**)(obj + 0x10 + obj[0x30] * 4))->Allocate(size);
    (*(SafeAllocator**)(obj + 0x10 + (obj[0x30] + 1) * 4))->CreateTypeB(buf, size, 4);

    unsigned char idx = obj[0x30];
    State0207dfc8* cur = *(State0207dfc8**)(obj + 0x20 + idx * 4);
    State0207dfc8* next = *(State0207dfc8**)(obj + 0x20 + (idx + 1) * 4);
    VramState_CopyCurrentTo(cur, next);

    obj[0x30] = obj[0x30] + 1;
}
