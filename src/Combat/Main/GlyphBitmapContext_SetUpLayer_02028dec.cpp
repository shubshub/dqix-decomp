#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"

#include "std_library_functions.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/Cache.h"
#include "NitroSDK/Graphics.h"

extern "C" void GlyphBitmapContext_ClearCharacters();
extern "C" void GlyphBitmapContext_UploadTileMap();

// 16 colours: 0-7 black, then cyan, magenta, yellow, blue, green, red, grey, white
extern unsigned char data_020e7390[0x20];

enum {
    kPaletteSize = 0x20,
    kBgCntPriorityAndMosaic = 0x43,
    kBgCntCharBase1 = 0x4,
};

// Main, originally UploadPendingPalette02028dec (USA 0x02028dec, EUR 0x02028dfc, JPN 0x0202863c)
ARM void GlyphBitmapContext_SetUpLayer(int subScreen) {
    if (glyphBitmapContext.buffer == NULL) {
        return;
    }
    memcpy(glyphBitmapContext.buffer, data_020e7390, kPaletteSize);
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, kPaletteSize);
    if (subScreen == 0) {

        BG1CNT = (BG1CNT & kBgCntPriorityAndMosaic) | kBgCntCharBase1;
        LoadToMainBGStandardPalette(glyphBitmapContext.buffer, 0, kPaletteSize);
    } else {
        BG0CNTSUB = (BG0CNTSUB & kBgCntPriorityAndMosaic) | kBgCntCharBase1;
        LoadToSubBGStandardPalette(glyphBitmapContext.buffer, 0, kPaletteSize);
    }
    GlyphBitmapContext_ClearCharacters();
    GlyphBitmapContext_UploadTileMap();
}
