#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"
#include "Resource/CharacterCreationUI.h"

struct Struct_0205d81c;
struct Elem_0205d81c {
    unsigned char unknown0[0xac];
    short x, y;
};
extern "C" Elem_0205d81c* func_0205d81c(Struct_0205d81c* s, int key);
extern "C" void SpriteContext_DrawSprite(SpriteContext0205ac40*, B174Outer*);

#if defined(jpn)
enum { SelectionOffset = 0x1340, WindowOffset = 0x90, Enum_ov023_021e6b04_4956 = 0x1334, Enum_ov023_021e6b04_4964 = 0x133c };
#else
enum { SelectionOffset = 0x1370, WindowOffset = 0xac, Enum_ov023_021e6b04_4956 = 0x135c, Enum_ov023_021e6b04_4964 = 0x1364 };
#endif

namespace {
struct Struct_ov023_021e6b04 {
    short x, y;
    unsigned char unknown4[0xe - 4];
    unsigned char spriteIndex;
};
struct Struct_ov023_021e6b04_2 {
    Struct_ov023_021e6b04* coordinates;
};
struct Struct_ov023_021e6b04_3 {
    Struct_ov023_021e6b04_2* selectedEntry;
    unsigned char unknown4[WindowOffset - 4];
    CreationWindow window;
    unsigned char unknown_168_[Enum_ov023_021e6b04_4956 - WindowOffset - sizeof(CreationWindow)];
    SpriteContext0205ac40* renderer;
    unsigned char unknown_1360_[Enum_ov023_021e6b04_4964 - Enum_ov023_021e6b04_4956 - 4];
    B174Outer* sprites;
#if !defined(jpn)
    unsigned char unknown_1368_[SelectionOffset - Enum_ov023_021e6b04_4964 - 4];
#endif
    unsigned char selection;
    unsigned char key;
#if defined(jpn)
    unsigned char unknown_1342_[0x13b8 - SelectionOffset - 2];
    int selected;
#endif
};
}

// USA: func_ov023_021e6b04
// JPN: func_ov023_021e7074
extern "C" ARM void func_ov023_021e6b04(char* base) {
    Struct_ov023_021e6b04_3* state = ((Struct_ov023_021e6b04_3*)(base));
    if (state->key != 0xe) return;
    if (state->selection >= 0xa) return;

    Elem_0205d81c* elem = func_0205d81c(((Struct_0205d81c*)(&state->window)), 0xe);
    if (elem == NULL) return;

#if defined(jpn)
    short var2 = elem->x;
    short var3 = elem->y;
    int selected = state->selected;
    int column = selected / 7;
    int x = column * 16 + 14;
    int y = selected % 7 * 16 + 28;
    if (column >= 5) x += 8;
    if (column >= 10) x += 16;
    B174Outer* entry;
    if (column >= 10) entry = state->sprites + 16;
    else entry = state->sprites + 15;
    short offsetX = var2 << 3;
    int cursorX = x + offsetX;
    short offsetY = var3 << 3;
    int cursorY = y + offsetY;
    entry->position[0] = cursorX << 12;
    entry->position[1] = cursorY << 12;
    entry->priority = 2;
#else
    Struct_ov023_021e6b04_2* p1 = state->selectedEntry;
    Struct_ov023_021e6b04* p2 = p1->coordinates;
    if (p2 == NULL) return;

    unsigned char var14 = p2->spriteIndex;
    B174Outer* sprites = state->sprites;
    B174Outer* entry = sprites + (var14 + 15);
    short v0 = p2->x;
    short v2 = p2->y;
    entry->position[0] = v0 << 12;
    entry->position[1] = v2 << 12;
    entry->priority = 0;
#endif
    SpriteContext_DrawSprite(state->renderer, entry);
}
