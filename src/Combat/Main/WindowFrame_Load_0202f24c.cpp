#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Filesystem/NarcHandle.h"

void* AllocatorUnion_AllocateRounded(AllocatorUnion* alloc, unsigned int size);
void* LoadFileIntoMemory(const char*, void*, unsigned int*);
void WindowFrame_LoadPieces(char*, void*, void*);

extern AllocatorUnion g_mainAllocator;
extern char data_020ef7ac[]; // "data/bin/icon.nsarc"
extern char g_fileLoadBuffer[];
extern char data_020ef7c0[]; // "ARC"

// A window frame: eight .spr pieces, its rect, and the allocator the pieces load into.
struct WindowFrame {
    char pieces[0x440];
    void* rect;
    class SafeAllocator* allocator;
};

enum { kPieceBufferSize = 0xf08 }; // the allocator's buffer for the eight pieces

// Main, originally func_0202f24c (USA 0x0202f24c, EUR 0x0202f25c, JPN 0x0202edbc)
extern "C" ARM void WindowFrame_Load(struct WindowFrame* frame) {
    if (frame->allocator == 0) {
        frame->allocator = (class SafeAllocator*)AllocatorUnion_AllocateRounded(&g_mainAllocator, sizeof(SafeAllocator));
        frame->allocator->ResetAllocatorPointer();
        void* buffer = AllocatorUnion_AllocateRounded(&g_mainAllocator, kPieceBufferSize);
        frame->allocator->CreateTypeA(buffer, kPieceBufferSize);
        frame->allocator->Reset();
    } else {
        frame->allocator->Reset();
    }
    BackgroundLoader::AddLockGlobal();

    unsigned int size;
    void* archive = LoadFileIntoMemory(data_020ef7ac, g_fileLoadBuffer, &size);
    if (archive != 0) {
        NarcHandle handle;
        if (handle.Initialize(data_020ef7c0, (const unsigned char*)archive)) {
            WindowFrame_LoadPieces((char*)frame, frame->allocator, archive);
            handle.Destroy();
        }
    }
    BackgroundLoader::RemoveLockGlobal();
}
