#include <globaldefs.h>
#if defined(jpn)
#include "Resource/FontGlyphTable.h"
#endif

struct Rect0205b1ac { int offset; short x, y, width, height; };
struct GlyphEntry0205b36c { const char* text; signed char width; unsigned char flags; short unknown_6_; };
struct Struct_0205b36c_2 { int field_0; unsigned short width; unsigned short height; int field_8; unsigned char* unknown_c_; };
struct GlyphDestination0205b36c { unsigned char* pixels; Rect0205b1ac* rectangles; unsigned char rectangleCount; };
extern "C" int func_02042638(int);
extern "C" Rect0205b1ac* func_0205b1ac(Rect0205b1ac*, unsigned int, int, int);

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
    short height = table->unknown_3_;
    unsigned int count = destination->rectangleCount;
    Rect0205b1ac* rectangles = destination->rectangles;
    unsigned char var7 = color << 4;
    unsigned char var8 = color & 15;
    for (; row < height; ++row) {
        short var9 = y + row;
        for (short column = 0; column < width; ++column) {
            if (*source & (1 << shift)) {
                short var11 = x + column;
                Rect0205b1ac* var12 = func_0205b1ac(rectangles, count, var11, var9);
                if (var12) {
                    unsigned char* pixels = destination->pixels + var12->offset;
                    short var14 = var11 - var12->x;
                    short var15 = var9 - var12->y;
                    short tileX = var14 >> 3;
                    short tileY = var15 >> 3;
                    short tileWidth = var12->width >> 3;
                    short tile = tileY * tileWidth + tileX;
                    pixels += tile << 5;
                    short var20 = var14 & 7;
                    short var21 = var15 & 7;
                    int var22 = (var21 << 2) + (var20 >> 1);
                    unsigned char* var23 = pixels + var22;
                    if (var11 & 1) {
                        *var23 &= 15;
                        *var23 |= var7;
                    } else {
                        *var23 &= 240;
                        *var23 |= var8;
                    }
                }
            }
            ++shift;
            if (shift >= 8) { ++source; shift = 0; }
        }
    }
}
#else
extern "C" ARM void GlyphDestination_DrawCharacter(GlyphDestination0205b36c* destination, GlyphEntry0205b36c* glyph, short x, short y, unsigned char color, unsigned char font) {
    Struct_0205b36c_2* var24 = (Struct_0205b36c_2*)func_02042638(font);
    short var25 = glyph->unknown_6_;
    unsigned char var26 = color << 4;
    unsigned char var27 = color & 15;
    int pitch = var24->width >> 3;
    signed char var29 = 7 - (glyph->unknown_6_ & 7);
    unsigned int count = destination->rectangleCount;
    Rect0205b1ac* rectangles = destination->rectangles;
    for (int row = 0; row < 12; ++row) {
        short var33 = y + row;
        signed char shift = var29;
        unsigned char* source = var24->unknown_c_ + pitch * row + (var25 >> 3);
        for (int column = 0; column < glyph->width; ++column) {
            if (*source & (1 << shift)) {
                short var37 = x + column;
                Rect0205b1ac* var38 = func_0205b1ac(rectangles, count, var37, var33);
                if (var38) {
                    unsigned char* pixels = destination->pixels + var38->offset;
                    short var40 = var37 - var38->x;
                    short var41 = var33 - var38->y;
                    short tileX = var40 >> 3;
                    short tileY = var41 >> 3;
                    short tileWidth = var38->width >> 3;
                    short tile = tileY * tileWidth + tileX;
                    pixels += tile << 5;
                    short var46 = var40 & 7;
                    short var47 = var41 & 7;
                    int var48 = (var47 << 2) + (var46 >> 1);
                    unsigned char* var49 = pixels + var48;
                    if (var37 & 1) {
                        *var49 &= 15;
                        *var49 |= var26;
                    } else {
                        *var49 &= 240;
                        *var49 |= var27;
                    }
                }
            }
            --shift;
            if (shift < 0) { shift = 7; ++source; }
        }
    }
}
#endif
