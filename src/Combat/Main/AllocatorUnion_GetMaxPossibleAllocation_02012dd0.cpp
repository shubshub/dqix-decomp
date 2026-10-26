#include <globaldefs.h>
#include "NitroSDK/Memory/HPXEAllocator.h"

// The head of an AllocatorUnion set up by InitializeTypeB (AllocatorTypeB): every caller passes &g_mainAllocator
struct Struct02012dd0 {
    void* pVTable;
    HPXEAllocator* pHPXEAllocator;
};

// HPXEAllocator::GetMaxPossibleAllocation's alignAndDir: forwards, 4-byte aligned (as AllocatorUnion_InitMainArenaHeap sets up
// g_mainAllocator)
enum { kForwardAlign4 = 4 };

// Main, originally GetMaxAlloc02012dd0 (USA 0x02012dd0, EUR 0x02012de0, JPN 0x02012b98)
extern "C" ARM unsigned int AllocatorUnion_GetMaxPossibleAllocation(Struct02012dd0* allocator) {
    return allocator->pHPXEAllocator->GetMaxPossibleAllocation(kForwardAlign4);
}
