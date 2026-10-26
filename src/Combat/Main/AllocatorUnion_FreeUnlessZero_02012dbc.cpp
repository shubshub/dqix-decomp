#include <globaldefs.h>
#include "NitroSDK/Memory/AllocatorUnion.h"

// Main, originally FreeIfFlag_02012dbc (USA 0x02012dbc, EUR 0x02012dcc, JPN 0x02012b84)
extern "C" ARM void AllocatorUnion_FreeUnlessZero(AllocatorUnion* alloc, void* data, int size) {
    if (size == 0)
        return;
    alloc->Free(data);
}
