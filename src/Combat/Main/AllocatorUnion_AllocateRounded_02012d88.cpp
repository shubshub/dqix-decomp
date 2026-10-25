#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

// Main, originally AllocateAligned4_02012d88 (USA 0x02012d88, EUR 0x02012d98, JPN 0x02012b50)
ARM void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size) {
    void* p = alloc->Allocate((size + 3) & ~3);
    if (p == NULL)
        return NULL;
    return p;
}
