#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

// The CachedTextTable
struct PaletteState0203c35c {
    #if defined(jpn)
    unsigned char padding[0x604];
    #else
    unsigned char padding[0x504];
    #endif
    int engine;                  // 0 main, 1 sub
    int bitmapStorage;
    unsigned int paletteOffset;  // byte offset of the text palettes in OBJ palette memory
    #if defined(jpn)
    unsigned char unknown_610_[4];
    unsigned short palette[112];
    #endif
};
// The MessageSystem's 0x800-byte tile scratch buffer at +0x60
struct PaletteWork0203c35c {
    unsigned char padding[0x60];
    unsigned short* tileBuffer;
};
struct Struct_020e78c4 {
    float red;
    float green;
    float blue;
};
#if defined(jpn)
extern PaletteState0203c35c* data_02105244;
#define data_020e78c4 data_020e8220
#define data_020e78b0 data_020e81ec
#define data_020e78a0 data_020e81dc
#else
extern "C" int MessageSystem_GetInstance();
#endif
// Per palette: the RGB scale of its shades, colours 2-6 (white for palettes 0-3, then (1, 0.8, 0), (1, 0.5, 0.2), red)
extern Struct_020e78c4 data_020e78c4[] __attribute__((aligned(4)));
// The five shade levels {196, 204, 212, 223, 255}
extern float data_020e78b0[];
// Per palette: colour 15, the text colour (0x7fff white, ...)
extern unsigned short data_020e78a0[];

// Seven 16-colour OBJ palettes (0xe0 bytes)
enum { kTextPaletteCount = 7, kShadeCount = 5, kTextColorIndex = 15, kFirstShadeIndex = 2 };

// Main, originally func_0203c35c (USA 0x0203c35c, EUR 0x0203c36c, JPN 0x0203c4b4)
extern "C" ARM void CachedTextTable_LoadPalettes(PaletteState0203c35c* table) {
    int green;
    int blue;
    int red;
    const float* weights;
    unsigned short* palette;
    unsigned int i;
    int shade;
    unsigned short colors[16] = {};
#if defined(jpn)
    palette = data_02105244->palette;
#else
    palette = ((PaletteWork0203c35c*)MessageSystem_GetInstance())->tileBuffer;
#endif
    unsigned short paletteBytes = 0xe0;
    memset(palette, 0, paletteBytes);
    for (i = 0; i < kTextPaletteCount; i++) {
        colors[1] = 0x294a;
        if (i == 6) colors[1] = 0x18c6;
        const Struct_020e78c4* color = &data_020e78c4[i];
        const float& var10 = color->red;
        const float& var11 = color->green;
        for (shade = 0, weights = data_020e78b0; shade < kShadeCount; shade++) {
            float var12 = weights[shade];
            var12 *= var10;
            red = (int)var12;
            var12 = weights[shade];
            var12 *= var11;
            green = (int)var12;
            var12 = weights[shade];
            var12 *= color->blue;
            blue = (int)var12;
            int var13 = red >> 3;
            int var14 = green >> 3;
            int var15 = blue >> 3;
            int packed = var14 << 5;
            packed |= var13;
            packed |= var15 << 10;
            colors[shade + kFirstShadeIndex] = packed;
        }
        colors[kTextColorIndex] = data_020e78a0[i];
        memcpy(palette + i * 16, colors, 0x20);
    }
    CleanInvalidateCacheRange(palette, 0xe0);
    if (table->engine == 0) LoadToMainObjStandardPalette(palette, table->paletteOffset, 0xe0);
    else if (table->engine == 1) LoadToSubObjStandardPalette(palette, table->paletteOffset, 0xe0);
}
