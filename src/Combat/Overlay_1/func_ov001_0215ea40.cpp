#include <globaldefs.h>
#include "Memory/SafeAllocator.h"

extern "C" int func_ov017_021d60f4(void*);
struct AllocatorUnion;
extern "C" void AllocatorUnion_Free(struct AllocatorUnion*, void*);
struct Struct02012dd0;
extern "C" unsigned int AllocatorUnion_GetMaxPossibleAllocation(struct Struct02012dd0*);

extern SafeAllocator* data_ov001_021658b8[8];
extern struct AllocatorUnion g_mainAllocator;

// USA: func_ov001_0215ea40
extern "C" ARM int func_ov001_0215ea40(void* self) {
    int idx = func_ov017_021d60f4(self);
    if (idx < 0 || idx >= 8) return 0;
    SafeAllocator* alloc = data_ov001_021658b8[idx];
    if (alloc == NULL) return 0;
    SignedAllocatorHeader* signedAlloc = alloc->GetSignedAllocator();
    if (signedAlloc != NULL) {
        alloc->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, signedAlloc);
    }
    AllocatorUnion_GetMaxPossibleAllocation((struct Struct02012dd0*)&g_mainAllocator);
    return 1;
}
