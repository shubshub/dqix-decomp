#include <globaldefs.h>
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/LoadToVRAM.h"

// The CachedTextTable
struct PaletteState0203c35c {
    #if defined(jpn)
    unsigned char unknown_0_[0x604];
    #else
    unsigned char unknown1_0_[0x504];
    #endif
    int engine;                  // 0 main, 1 sub
    int bitmapStorage;
    unsigned int paletteOffset;  // byte offset of the text palettes in OBJ palette memory
    #if defined(jpn)
    unsigned char unknown_610_[4];
    unsigned short unknown_614_[112];
    #endif
};
// The MessageSystem's 0x800-byte tile scratch buffer at +0x60
struct PaletteWork0203c35c {
    unsigned char padding[0x60];
    unsigned short* tileBuffer;
};
struct Struct_020e78c4 {
    float unknown_0_;
    float unknown_4_;
    float unknown_8_;
};
#if defined(jpn)
extern Struct_0203c35c* data_02105244;
#define data_020e78c4 data_020e8220
#define data_020e78b0 data_020e81ec
#define data_020e78a0 data_020e81dc
#else
int MessageSystem_GetInstance();
#endif
// Per palette: the RGB scale of its shades, colours 2-6 (white for palettes 0-3, then (1, 0.8, 0), (1, 0.5, 0.2), red)
extern PaletteColor0203c35c data_020e78c4[] __attribute__((aligned(4)));
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
    var4 = data_02105244->unknown_614_;
#else
    palette = ((PaletteWork0203c35c*)MessageSystem_GetInstance())->tileBuffer;
#endif
    unsigned short paletteBytes = 0xe0;
    memset(palette, 0, paletteBytes);
    for (i = 0; i < kTextPaletteCount; i++) {
        colors[1] = 0x294a;
        if (i == 6) colors[1] = 0x18c6;
        const PaletteColor0203c35c* color = &data_020e78c4[i];
        const float& redScale = color->red;
        const float& greenScale = color->green;
        for (shade = 0, weights = data_020e78b0; shade < kShadeCount; shade++) {
            float factor = weights[shade];
            factor *= redScale;
            red = (int)factor;
            factor = weights[shade];
            factor *= greenScale;
            green = (int)factor;
            factor = weights[shade];
            factor *= color->blue;
            blue = (int)factor;
            int redBits = red >> 3;
            int greenBits = green >> 3;
            int blueBits = blue >> 3;
            int packed = greenBits << 5;
            packed |= redBits;
            packed |= blueBits << 10;
            colors[shade + kFirstShadeIndex] = packed;
        }
        colors[kTextColorIndex] = data_020e78a0[i];
        memcpy(palette + i * 16, colors, 0x20);
    }
    CleanInvalidateCacheRange(palette, 0xe0);
    if (table->engine == 0) LoadToMainObjStandardPalette(palette, table->paletteOffset, 0xe0);
    else if (table->engine == 1) LoadToSubObjStandardPalette(palette, table->paletteOffset, 0xe0);
}
