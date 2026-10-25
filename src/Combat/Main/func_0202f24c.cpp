#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Filesystem/NarcHandle.h"

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
extern "C" void func_0202f310(char*, void*, void*);

extern AllocatorUnion g_mainAllocator;
extern char data_020ef7ac[];
extern char g_fileLoadBuffer[];
extern char data_020ef7c0[];

struct Struct_0202f24c {
    char unknown_0_[0x444];
    class SafeAllocator* unknown_444_;
};

// USA: func_0202f24c  (semantic: InitIconArchiveAndLoadEntries_0202f24c)
extern "C" ARM void func_0202f24c(struct EntryTable0202f24c* obj) {
    if (obj->alloc == 0) {
        obj->alloc = (class SafeAllocator*)AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x14);
        obj->alloc->ResetAllocatorPointer();
        void* buf = AllocatorUnion_AllocateRounded(&g_mainAllocator, 0xf08);
        obj->alloc->CreateTypeA(buf, 0xf08);
        obj->alloc->Reset();
    } else {
        arg0->unknown_444_->Reset();
    }
    BackgroundLoader::AddLockGlobal();

    unsigned int size;
    void* fileData = LoadFileIntoMemory(data_020ef7ac, g_fileLoadBuffer, &size);
    if (fileData != 0) {
        NarcHandle handle;
        if (handle.Initialize(data_020ef7c0, (const unsigned char*)fileData)) {
            LoadEightEntriesFromTable_0202f310((char*)obj, obj->alloc, fileData);
            handle.Destroy();
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
