#include <globaldefs.h>
#include "NitroSDK/Memory/HMRFAllocator.h"

struct Struct_020bd914;
extern "C" int func_020bdbf0(Struct_020bd914* obj, HMRFAllocator* allocator);

// Main, originally CreateAllocatorHolderInRegion_020bd914 (USA 0x020bd914, EUR 0x020bd924, JPN 0x020bf3e0)
extern "C" ARM void* NNS_SndHeapCreate(void* start, unsigned int size)
{
    unsigned int end = (unsigned int)start + size;
    unsigned int var1 = ((unsigned int)start + 3) & ~3;

    if (var1 > end)
        return NULL;

    unsigned int var2 = end - var1;
    if (var2 < 0x10)
        return NULL;

    HMRFAllocator* allocator = HMRFAllocator::CreateAtLocation((void*)(var1 + 0x10), var2 - 0x10, 0);
    if (allocator == NULL)
        return NULL;

    if (func_020bdbf0((Struct_020bd914*)var1, allocator))
        return (void*)var1;

    allocator->RemoveFromTree();
    return NULL;
}
