#pragma once

#include <globaldefs.h>

struct Struct_020429e4 {
    unsigned char first;
    unsigned char second;
};

struct FontGlyphTable {
    unsigned short unknown_0_;
    unsigned char glyphWidth;
    unsigned char unknown_3_;
    char unknown4[2];
    short glyphCount;
    Struct_020429e4* keys;
    char* glyphs;
};

typedef FontGlyphTable FontGlyphTable;

extern "C" FontGlyphTable* Font_GetGlyphTable(int pixelSize);
#if defined(jpn)
extern "C" char* func_02043060(FontGlyphTable* table, const unsigned char* encodedCharacter);
#define func_020429e4 func_02043060
#else
extern "C" char* func_020429e4(FontGlyphTable* table, const unsigned char* encodedCharacter);
#endif
extern "C" char* Font_FindGlyph(int pixelSize, const char* encodedCharacter);
