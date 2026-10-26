#include <globaldefs.h>
#include "World/ZoneLootableRecord.h"

// A window frame: its eight .spr pieces (ARC:win0-7.spr, Foo02048004 each), then +0x440 its rect (position, size,
// open state, scale, colour) and +0x444 the allocator the pieces load into.
enum { kFramePieceCount = 8 };

// Main, originally InitEightSubStructs_0202f1a4 (USA 0x0202f1a4, EUR 0x0202f1b4, JPN 0x0202ed14)
extern "C" ARM void WindowFrame_Init(char* frame) {
    int i;
    for (i = 0; i < kFramePieceCount; i++) {
        SprSprite_Init(frame + i * sizeof(Foo02048004));
    }
    *(int*)(frame + 0x440) = 0;
    *(int*)(frame + 0x444) = 0;
}
