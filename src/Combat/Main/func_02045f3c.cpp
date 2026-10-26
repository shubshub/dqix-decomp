#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

#if !defined(jpn)

extern "C" int Font_GetKerning(int a, int b, int fontIndex);
extern "C" void func_020654b8(void* obj, void* context, Struct_0204166c* glyph, short x, short y, int mode);
extern "C" void func_020417b0(Struct_0204166c* glyph, int color, void* palette, int alpha);

extern const int data_020e7a94[];

struct Struct_02045f3c {
    char pad0[0x34];
    void* context;
    char unknown_38_[0x980];
    Struct_0204166c glyphs[0x80];
    char unknown_17b8_[0x1f8];
    unsigned char enabled;
};

// USA: func_02045f3c
extern "C" ARM void func_02045f3c(Struct_02045f3c* renderer, unsigned short* text, int x, int y, unsigned short color,
                                  int arg5, int arg6, unsigned char arg7, unsigned char fontIndex, int lineHeight) {
    if (text == NULL || renderer->enabled == 0 || text[0] == 0xffff) {
        return;
    }
    int same = 1;
    unsigned short first = text[0];
    for (int j = 1; j < 10; j++) {
        if (first != text[j]) {
            same = 0;
            break;
        }
    }
    if (same) {
        return;
    }
    Struct_0204166c* glyph;
    int i;
    int cx;
    unsigned short ch;
    *(volatile int*)0x04000444 = 0;
    int var7 = data_020e7a94[fontIndex] & 0xff;
    i = 0;
    unsigned char previousCharacter = 0xff;
    ch = text[0];
    cx = x;
    while (ch != 0xff01) {
        ch = text[i];
        i++;
        if ((ch & 0xff00) == 0xff00) {
            if (ch == 0xff18) {
                cx = x;
                y += lineHeight;
                previousCharacter = 0xff;
                continue;
            }
            if (ch == 0xff19) {
                cx += var7 + 1;
                previousCharacter = 0xff;
                continue;
            }
            break;
        }
        if (ch >= 0x80) {
            break;
        }
        glyph = &renderer->glyphs[ch];
        if (glyph->unknown_8_ < 0) {
            break;
        }
        unsigned char characterIndex = glyph->characterIndex;
        cx += Font_GetKerning(previousCharacter, characterIndex, fontIndex);
        previousCharacter = characterIndex;
        glyph->x = cx;
        glyph->y = y;
        glyph->depth = 0;
        if (arg7) {
            int mode = 15;
            if (color != 0x7fff) {
                mode = 5;
            }
            func_020654b8(renderer, renderer->context, glyph, cx, y, mode);
        } else {
            func_020417b0(glyph, color, 0, 31);
        }
        if (glyph->character) {
            cx += glyph->character->width_ + 1;
        }
    }
    *(volatile int*)0x04000448 = 1;
}
#endif
