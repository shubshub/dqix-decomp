#include <globaldefs.h>

#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Resource/GameResources.h"

extern "C" void func_020a0cc4(unsigned int);
struct Struct02012dd0;
unsigned int GetMaxAlloc02012dd0(Struct02012dd0* self);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern AllocatorUnion g_mainAllocator;

// USA: func_020a36cc
ARM int AllocateIndexedSlot020a36cc(void** allocation, unsigned int requestedBytes) {
    GameResources* resources = GetGameResources();
    unsigned int availableBytes = GetMaxAlloc02012dd0((Struct02012dd0*)&g_mainAllocator);
    if (availableBytes < requestedBytes) {
        func_020a0cc4(requestedBytes);
        resources->unknown_4490[0] = 1;
    }
    *allocation = AllocatorUnion_AllocateRounded(&g_mainAllocator, requestedBytes);
    return 1;
}
