#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

struct Struct_020424e4;
struct Struct_0205b234_2 { unsigned char* unknown_0_; Struct_020424e4* unknown_4_; unsigned char unknown_8_; };

int Font_GetFallbackWidth(int);
int Font_FindCharacterIndex(int, int);
int Font_GetKerning(int, int, int);
FontCharacter* Font_GetCharacter(int index, int fontIndex);
extern "C" void GlyphDestination_DrawCharacter(GlyphDestination0205b234* destination, FontCharacter* glyph, short x, short y, unsigned char color, unsigned char font);

// Main, originally func_0205b234 (USA 0x0205b234, EUR 0x0205b244, JPN 0x0205c5d0)
extern "C" ARM int GlyphDestination_DrawText(GlyphDestination0205b234* destination, short x, short y, const char* text, unsigned char color, unsigned char font) {
    if (destination->pixels == 0) return 0;
    if (destination->rectangles == 0) return 0;
    if (destination->rectangleCount == 0) return 0;
    if (text == 0) return 0;
    unsigned char fallbackWidth = Font_GetFallbackWidth(font);
    int previousCharacter = 0xff;
    short cursorX = x;
    while (*text != 0) {
        int index;
        signed char advance = fallbackWidth + 1;
        index = Font_FindCharacterIndex((int)text, font) & 0xff;
        cursorX += Font_GetKerning(previousCharacter, index, font);
        int length = 1;
        if (index != 0xff) {
            FontCharacter* character = Font_GetCharacter(index, font);
            GlyphDestination_DrawCharacter(destination, character, cursorX, y, color, font);
            advance = character->width_ + 1;
            length = character->byteLength_;
        }
        var4 = var6;
        arg3 += var8;
        var5 += var7;
    }
    return var5 - arg1;
}
#endif
