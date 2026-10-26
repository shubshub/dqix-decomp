#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

struct Struct02012dd0;
unsigned int AllocatorUnion_GetMaxPossibleAllocation(struct Struct02012dd0* self);
void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);
unsigned int LoadROMFilesystemFileTables(void* where, unsigned int capacity);
void CacheMainFileAccessors();

extern AllocatorUnion g_mainAllocator;
extern void* data_02109d90;

// Main, originally func_020a0c0c (USA 0x020a0c0c, EUR 0x020a0c1c, JPN 0x020a2984)
extern "C" ARM void ROMFilesystem_InitFileTables() {
    unsigned int max;
    void* tmp;
    BackgroundLoader* loader;
    unsigned int size;

    if (data_02109d90 != NULL)
        return;

    size = LoadROMFilesystemFileTables(NULL, 0);
    max = AllocatorUnion_GetMaxPossibleAllocation((Struct02012dd0*)&g_mainAllocator);
    if (size + 0x10 > max)
        return;

    var2 = BackgroundLoader::GetInstance();
    if (var2 != NULL)
        var2->AddLock();

    tmp = AllocatorUnion_AllocateRounded(&g_mainAllocator, max - (size + 0x10));
    data_02109d90 = AllocatorUnion_AllocateRounded(&g_mainAllocator, size);
    AllocatorUnion_Free(&g_mainAllocator, tmp);

    if (data_02109d90 != NULL)
        LoadROMFilesystemFileTables(data_02109d90, var3);

    if (var2 != NULL)
        var2->RemoveLock();

    CacheMainFileAccessors();
}
