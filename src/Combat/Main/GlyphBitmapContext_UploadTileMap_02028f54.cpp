#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "Graphics/GlyphMetrics.h"

#include "std_library_functions.h"
#include "NitroSDK/LoadToVRAM.h"

#include "NitroSDK/Cache.h"

// A 4bpp 256x192 bitmap: 32x24 tiles of 8x8 pixels
enum { kScreenColumns = 32, kScreenRows = 24, kBitmapSize = 256 * 192 / 2, kScreenMapSize = kScreenColumns * kScreenRows * sizeof(unsigned short) };

// Main, originally func_02028f54 (USA 0x02028f54, EUR 0x02028f64, JPN 0x020287a4)
extern "C" ARM void GlyphBitmapContext_UploadTileMap(void) {
    if (glyphBitmapContext.buffer == 0) {
        return;
    }

    if (glyphBitmapContext.buffer != 0) {
        memset(glyphBitmapContext.buffer, 0, kBitmapSize);
    }
    unsigned short* var0 = static_cast<unsigned short*>(glyphBitmapContext.buffer);
    unsigned short tile = 0;
    int row;
    int col;
    for (row = 0; row < kScreenRows; row++) {
        for (col = 0; col < kScreenColumns; col++) {
            *var0 = tile;
            var0++;
            tile++;
        }
    }
    int mode = data_020ef74c.displayMode;
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, kScreenMapSize);
    if (mode == 3) {
        LoadToMainBG1ScreenData(glyphBitmapContext.buffer, 0, kScreenMapSize);
        return;
    }
    if (mode == 4) {
        LoadToSubBG0ScreenData(glyphBitmapContext.buffer, 0, kScreenMapSize);
        return;
    }
    if (mode == 5) {
        LoadToMainBG1ScreenData(glyphBitmapContext.buffer, 0, kScreenMapSize);
        return;
    }
    if (mode == 6) {
        LoadToSubBG0ScreenData(glyphBitmapContext.buffer, 0, kScreenMapSize);
        return;
    }
}
