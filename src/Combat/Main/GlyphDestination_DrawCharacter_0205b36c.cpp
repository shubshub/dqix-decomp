#include <globaldefs.h>
#if defined(jpn)
#include "Resource/FontGlyphTable.h"
#endif

struct Struct_0205b1ac { int unknown_0_; short unknown_4_, unknown_6_, unknown_8_, unknown_a_; };
struct Struct_0205b36c { const char* unknown_0_; signed char unknown_4_; unsigned char unknown_5_; short unknown_6_; };
struct Struct_0205b36c_2 { int unknown_0_; unsigned short unknown_4_; unsigned short unknown_6_; int unknown_8_; unsigned char* unknown_c_; };
struct Struct_0205b36c_3 { unsigned char* unknown_0_; Struct_0205b1ac* unknown_4_; unsigned char unknown_8_; };
extern "C" int func_02042638(int);
extern "C" Struct_0205b1ac* func_0205b1ac(Struct_0205b1ac*, unsigned int, int, int);

// USA: GlyphDestination_DrawCharacter
#if defined(jpn)
// JPN: func_0205c68c
// Main, originally func_0205b36c (USA 0x0205b36c, EUR 0x0205b37c, JPN 0x0205c68c)
extern "C" ARM void GlyphDestination_DrawCharacter(GlyphDestination0205b36c* destination, const unsigned char* source, short x, short y, unsigned char font, unsigned char color) {
    if (source == NULL) return;
    FontGlyphTable* table = Font_GetGlyphTable(font);
    if (table == NULL) return;
    unsigned char shift = 0;
    short row = 0;
    short width = table->glyphWidth;
    short height = table->glyphHeight;
    unsigned int count = destination->rectangleCount;
    Rect0205b1ac* rectangles = destination->rectangles;
    unsigned char upperColor = color << 4;
    unsigned char lowerColor = color & 15;
    for (; row < height; ++row) {
        short destinationY = y + row;
        for (short column = 0; column < width; ++column) {
            if (*source & (1 << shift)) {
                short destinationX = x + column;
                Rect0205b1ac* rectangle = FindRectContainingPoint0205b1ac(rectangles, count, destinationX, destinationY);
                if (rectangle) {
                    unsigned char* pixels = destination->pixels + rectangle->offset;
                    short localX = destinationX - rectangle->x;
                    short localY = destinationY - rectangle->y;
                    short tileX = localX >> 3;
                    short tileY = localY >> 3;
                    short tileWidth = rectangle->width >> 3;
                    short tile = tileY * tileWidth + tileX;
                    pixels += tile << 5;
                    short withinX = localX & 7;
                    short withinY = localY & 7;
                    int within = (withinY << 2) + (withinX >> 1);
                    unsigned char* pixel = pixels + within;
                    if (destinationX & 1) {
                        *pixel &= 15;
                        *pixel |= upperColor;
                    } else {
                        *var23 &= 240;
                        *var23 |= var8;
                    }
                }
            }
            ++var1;
            if (var1 >= 8) { ++arg1; var1 = 0; }
        }
    }
}
#else
extern "C" ARM void GlyphDestination_DrawCharacter(GlyphDestination0205b36c* destination, GlyphEntry0205b36c* glyph, short x, short y, unsigned char color, unsigned char font) {
    GlyphSheet0205b36c* sheet = (GlyphSheet0205b36c*)GetWordFromTable02042638(font);
    short bitOffset = glyph->bitOffset;
    unsigned char upperColor = color << 4;
    unsigned char lowerColor = color & 15;
    int pitch = sheet->width >> 3;
    signed char firstShift = 7 - (glyph->bitOffset & 7);
    unsigned int count = destination->rectangleCount;
    Rect0205b1ac* rectangles = destination->rectangles;
    for (int row = 0; row < 12; ++row) {
        short destinationY = y + row;
        signed char shift = firstShift;
        unsigned char* source = sheet->bitmap + pitch * row + (bitOffset >> 3);
        for (int column = 0; column < glyph->width; ++column) {
            if (*source & (1 << shift)) {
                short destinationX = x + column;
                Rect0205b1ac* rectangle = FindRectContainingPoint0205b1ac(rectangles, count, destinationX, destinationY);
                if (rectangle) {
                    unsigned char* pixels = destination->pixels + rectangle->offset;
                    short localX = destinationX - rectangle->x;
                    short localY = destinationY - rectangle->y;
                    short tileX = localX >> 3;
                    short tileY = localY >> 3;
                    short tileWidth = rectangle->width >> 3;
                    short tile = tileY * tileWidth + tileX;
                    pixels += tile << 5;
                    short withinX = localX & 7;
                    short withinY = localY & 7;
                    int within = (withinY << 2) + (withinX >> 1);
                    unsigned char* pixel = pixels + within;
                    if (destinationX & 1) {
                        *pixel &= 15;
                        *pixel |= upperColor;
                    } else {
                        *var49 &= 240;
                        *var49 |= var27;
                    }
                }
            }
            --var34;
            if (var34 < 0) { var34 = 7; ++var35; }
        }
    }
}
#endif
