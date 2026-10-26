#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Filesystem/FileIO.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"
#include "NitroSDK/Memory.h"


void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
char* FindEntryAndGetNext_020467c0(void* a, char* b, unsigned int* outSize);
int GetCharBlock_020b01a4(void* file, void** out);
struct Hdr02b0288;
int FindPlttChunkAndRelocate_020b01f0(struct Hdr02b0288* h, void** out);
extern "C" void HaltSystem(void);

extern AllocatorUnion g_mainAllocator;
extern unsigned char g_fileLoadBuffer[0x30000];
extern const char data_020f290c;
extern const char data_020f2925;
extern const char data_020f2936;

struct CharBlockData020db0f0 {
    char pad[0x10];
    unsigned int size;
    void* data;
};

struct PlttChunkData020db0f0 {
    char pad[0xc];
    void* data;
};

struct Manager020db0f0 {
    SafeAllocator allocator;
    char pad[0x40 - sizeof(SafeAllocator)];
    void* charBuf;
    unsigned int charBufSize;
    void* plttBuf;
    unsigned int plttBufSize;
};

// USA: func_020db0f0
ARM void LoadObjLoadingGraphicsResources(Manager020db0f0* mgr) {
    unsigned int fileLength;
    unsigned int characterFileLength;
    unsigned int paletteFileLength;
    char* ncgrEntry;
    Hdr02b0288* nclrEntry;
    CharBlockData020db0f0* charBlock;
    PlttChunkData020db0f0* plttChunk;
    void* buf;

    mgr->allocator.CreateTypeA(AllocatorUnion_AllocateRounded(&g_mainAllocator, 0x300), 0x300);
    mgr->allocator.Reset();
    BackgroundLoader::AddLockGlobal();

    buf = g_fileLoadBuffer;

    fileLength = 0;
    LoadFileIntoMemory(&data_020f290c, buf, &fileLength);

    characterFileLength = 0;
    paletteFileLength = 0;
    ncgrEntry = FindEntryAndGetNext_020467c0(buf, (char*)&data_020f2925, &characterFileLength);
    nclrEntry = (Hdr02b0288*)FindEntryAndGetNext_020467c0(buf, (char*)&data_020f2936, &paletteFileLength);

    charBlock = NULL;
    if (!GetCharBlock_020b01a4(ncgrEntry, (void**)&charBlock)) {
        HaltSystem();
    }

    mgr->charBufSize = charBlock->size;
    mgr->charBuf = mgr->allocator.Allocate(mgr->charBufSize);
    VectorizedInvertedMemcpy(charBlock->data, mgr->charBuf, mgr->charBufSize);

    plttChunk = NULL;
    if (!FindPlttChunkAndRelocate_020b01f0(nclrEntry, (void**)&plttChunk)) {
        HaltSystem();
    }

    mgr->plttBufSize = 0x20;
    mgr->plttBuf = mgr->allocator.Allocate(mgr->plttBufSize);
    VectorizedInvertedMemcpy(plttChunk->data, mgr->plttBuf, mgr->plttBufSize);

    BackgroundLoader::RemoveLockGlobal();
}
