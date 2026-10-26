#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

// Main, originally AllocateFromAllocatorUnion_02012db0 (USA 0x02012db0, EUR 0x02012dc0, JPN 0x02012b78)
ARM void* AllocatorUnion_AllocateExact(AllocatorUnion* alloc, unsigned int size) {
    return alloc->Allocate(size);
}
