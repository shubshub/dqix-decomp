#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "Filesystem/FileIO.h"

extern "C" void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
extern "C" void ItemTable_Init(void* obj);

extern "C" void* ItemTable_LoadIds(void* a, void* b, void* c, unsigned int d, int e, unsigned int f);

#if defined(jpn)
extern "C" void func_020e0484(void*, SafeAllocator*, char*, int, unsigned int, int);
#endif
extern AllocatorUnion g_mainAllocator;
extern char* g_itemDataArchive;
extern char* g_itemDataFile;

// USA: func_0207d6dc
extern "C" ARM void* func_0207d6dc(SafeAllocator* self, int param1, int param2) {
    unsigned int allocSize = (unsigned int)param2 << 8;
    void* mem = AllocatorUnion_AllocateRounded(&g_mainAllocator, allocSize);
    self->CreateTypeA(mem, allocSize);
    self->Reset();
    ItemTable_Init((char*)self + 0x14);
#if defined(jpn)
    func_020e0484((char*)self + 0x14, self, g_itemDataArchive, param1, (unsigned int)param2 & 0xffff, 1);
#else
    BackgroundLoader::AddLockGlobal();
    unsigned int fileSize = 0;
    void* fileData = ExtractFileFromGP2(g_itemDataArchive, g_itemDataFile, &fileSize);
    if (fileData != NULL) {
        ItemTable_LoadIds((char*)self + 0x14, self, fileData, fileSize, param1, (unsigned int)param2 & 0xffff);
    }
    BackgroundLoader::RemoveLockGlobal();
#endif
    *(void**)((char*)self + 0x2c) = (char*)self + 0x14;
    return (char*)self + 0x14;
}
