#pragma once

#include <globaldefs.h>

struct Struct_020429e4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
};

struct Struct_0203bebc {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    char unknown_4_[2];
    short unknown_6_;
    Struct_020429e4* unknown_8_;
    char* unknown_c_;
};

typedef Struct_0203bebc Struct_0203bebc;

FontGlyphTable* Font_GetGlyphTable(int pixelSize);
#if defined(jpn)
extern "C" char* func_02043060(Struct_0203bebc* arg0, const unsigned char* arg1);
#define func_020429e4 func_02043060
#else
extern "C" char* func_020429e4(Struct_0203bebc* arg0, const unsigned char* arg1);
#endif
extern "C" char* Font_FindGlyph(int pixelSize, const char* encodedCharacter);
