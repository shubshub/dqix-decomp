#include <globaldefs.h>

#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

extern "C" void func_020a0cc4(unsigned int);
struct Struct02012dd0;
extern "C" unsigned int AllocatorUnion_GetMaxPossibleAllocation(Struct02012dd0* self);
extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

// USA: func_020a36cc
extern "C" ARM int func_020a36cc(void** allocation, unsigned int requestedBytes) {
    GameResources* resources = GetGameResources();
    unsigned int availableBytes = AllocatorUnion_GetMaxPossibleAllocation((Struct02012dd0*)&g_mainAllocator);
    if (availableBytes < requestedBytes) {
        func_020a0cc4(requestedBytes);
        resources->unknown_4490_[0] = 1;
    }
    *allocation = AllocatorUnion_AllocateRounded(&g_mainAllocator, requestedBytes);
    return 1;
}
