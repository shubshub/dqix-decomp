#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern "C" int func_ov017_021d60f4(void*);
struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(struct Struct02012dd0*);

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);

extern SafeAllocator* data_ov001_021658b8[8];
extern AllocatorUnion g_mainAllocator;

// USA: func_ov001_0215e9b0
ARM int AllocateAndCreateAllocator_0215e9b0(void* self) {
    int idx = func_ov017_021d60f4(self);
    if (idx < 0 || idx >= 8) {
        return 0;
    }
    unsigned int maxAlloc = GetMaxAlloc02012dd0((struct Struct02012dd0*)&g_mainAllocator);
    if (data_ov001_021658b8[0] != NULL) {
        if (data_ov001_021658b8[0]->GetMaxPossibleAllocation() <= 0x14) {
            return 0;
        }
    }
    SafeAllocator* buf = (SafeAllocator*)data_ov001_021658b8[0]->Allocate(0x14);
    buf->ResetAllocatorPointer();
    void* p = AllocatorUnion_AllocateRounded(&g_mainAllocator, maxAlloc);
    buf->CreateTypeA(p, maxAlloc);
    return 1;
}
