#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "Graphics/GlyphMetrics.h"

#include "std_library_functions.h"
#include "NitroSDK/LoadToVRAM.h"
#include "NitroSDK/Cache.h"

// A 4bpp 256x192 bitmap
enum { kBitmapSize = 256 * 192 / 2 };

// Main, originally func_02028e90 (USA 0x02028e90, EUR 0x02028ea0, JPN 0x020286e0)
extern "C" ARM void GlyphBitmapContext_ClearCharacters(void) {
    if (glyphBitmapContext.buffer == 0) {
        return;
    }

    if (glyphBitmapContext.buffer != 0) {
        memset(glyphBitmapContext.buffer, 0, kBitmapSize);
    }
    int mode = data_020ef74c.displayMode;
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, kBitmapSize);
    if (mode == 3) {
        LoadToMainBG1CharacterData(glyphBitmapContext.buffer, 0, kBitmapSize);
        return;
    }
    if (mode == 4) {
        LoadToSubBG0CharacterData(glyphBitmapContext.buffer, 0, kBitmapSize);
        return;
    }
    if (mode == 5) {
        LoadToMainBG1CharacterData(glyphBitmapContext.buffer, 0, kBitmapSize);
        return;
    }
    if (mode == 6) {
        LoadToSubBG0CharacterData(glyphBitmapContext.buffer, 0, kBitmapSize);
        return;
    }
}
