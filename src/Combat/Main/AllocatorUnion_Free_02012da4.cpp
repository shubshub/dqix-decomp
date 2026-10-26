#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

// Main, originally TailForward02012da4 (USA 0x02012da4, EUR 0x02012db4, JPN 0x02012b6c)
extern "C" ARM void AllocatorUnion_Free(AllocatorUnion* alloc, void* data) {
    alloc->Free(data);
}
