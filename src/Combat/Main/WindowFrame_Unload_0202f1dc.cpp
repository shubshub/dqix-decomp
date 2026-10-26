#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/AllocatorUnion.h"

extern void WindowFrame_Init(char* frame);
extern void AllocatorUnion_Free(AllocatorUnion* alloc, void* data);

extern AllocatorUnion g_mainAllocator;

// A window frame: eight .spr pieces, +0x440 its rect, +0x444 the allocator WindowFrame_Load made for the pieces.
enum { kFramePieceCount = 8 };

// Main, originally ReinitEightSubStructsAndAllocator_0202f1dc (USA 0x0202f1dc, EUR 0x0202f1ec, JPN 0x0202ed4c)
ARM void WindowFrame_Unload(char* frame) {
    char* piece;
    int i;
    piece = frame;
    for (i = 0; i < kFramePieceCount; i++) {
        SprSprite_Unload((Foo02048004*)piece);
        piece += sizeof(Foo02048004);
    }

    if (*(SafeAllocator**)(frame + 0x444) != NULL) {
        SignedAllocatorHeader* buffer = (*(SafeAllocator**)(frame + 0x444))->GetSignedAllocator();
        (*(SafeAllocator**)(frame + 0x444))->Destroy();
        AllocatorUnion_Free(&g_mainAllocator, buffer);
        AllocatorUnion_Free(&g_mainAllocator, *(SafeAllocator**)(frame + 0x444));
    }

    WindowFrame_Init(frame);
}
