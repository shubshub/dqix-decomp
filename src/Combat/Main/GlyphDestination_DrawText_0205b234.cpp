#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

struct Rect0205b1ac;
struct GlyphDestination0205b234 { unsigned char* pixels; Rect0205b1ac* rectangles; unsigned char rectangleCount; };

#if defined(jpn)
extern "C" FontCharacter* Font_FindGlyph(unsigned char size, const char* text);
extern "C" void GlyphDestination_DrawCharacter(GlyphDestination0205b234* destination, FontCharacter* glyph, short x, short y, int size, int font);

// JPN: GlyphDestination_DrawText (fixed-width_ Shift-JIS text)
extern "C" ARM void GlyphDestination_DrawText(GlyphDestination0205b234* destination, short x, short y, const char* text, unsigned char size, int font) {
    if (destination->pixels == 0 || destination->rectangles == 0 || destination->rectangleCount == 0 || text == 0) return;
    unsigned char w = size;
    while (*text != 0) {
        FontCharacter* character = Font_FindGlyph(w, text);
        if (character != 0) GlyphDestination_DrawCharacter(destination, character, x, y, w & 0xff, font);
        unsigned char lead = *text;
        if ((lead >= 0x81 && lead <= 0x9f) || (lead >= 0xe0 && lead <= 0xea)) text++;
        text++;
        x += w;
    }
}
#else
extern "C" int Font_GetFallbackWidth(int);
extern "C" int Font_FindCharacterIndex(int, int);
extern "C" int Font_GetKerning(int, int, int);
extern "C" FontCharacter* Font_GetCharacter(int index, int fontIndex);
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
        previousCharacter = index;
        text += length;
        cursorX += advance;
    }
    return cursorX - x;
}
#endif
