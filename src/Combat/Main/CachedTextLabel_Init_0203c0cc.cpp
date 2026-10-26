#include <globaldefs.h>
#if defined(jpn)
#include "std_library_functions.h"
#endif

// A text label drawn from the CachedTextTable (CachedTextLabel_Draw's Struct0203c1c8)
struct State0xc0cc {
#if defined(jpn)
    short textSlots[10];          // cached entry per 3 characters, -1 none
    int x;
    int y;
    int lineHeight;
    int characterAdvance;
    int paletteOffset;
    int alignment;
    int priority;
    unsigned int affineIndex : 16;
    unsigned int unknown32 : 8;
    unsigned int unknown33 : 8;
    int affineMode;
#else
    int x;
    int y;
    int paletteOffset;
    int alignment;
    int priority;
    short entryIndex;             // cached entry, -1 none
#endif
};

// Main, originally InitFields0x0_0203c0cc (USA 0x0203c0cc, EUR 0x0203c0dc, JPN 0x0203bbe4)
ARM void CachedTextLabel_Init(struct State0xc0cc* label) {
#if defined(jpn)
    memset(label->textSlots, -1, sizeof(label->textSlots));
    label->y = 0;
    label->x = 0;
    label->lineHeight = 16;
    label->characterAdvance = 12;
    label->paletteOffset = 0;
    label->priority = 0;
    label->affineIndex = 0;
    label->unknown32 = 0;
    label->affineMode = 0;
    label->alignment = 0;
#else
    label->y = 0;
    label->x = 0;
    label->paletteOffset = 0;
    label->priority = 0;
    label->alignment = 0;
    label->entryIndex = -1;
#endif
}
