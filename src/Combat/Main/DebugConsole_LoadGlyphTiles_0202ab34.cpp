#include <globaldefs.h>
#include <std_library_functions.h>
#include <NitroSDK/Cache.h>
#include <NitroSDK/LoadToVRAM.h>
#include "Resource/FontGlyphTable.h"

// One 8x8 4bpp tile: 8 rows of 4 bytes, two pixels per byte.
enum { kTileBytes = 32 };

extern unsigned char data_020fe9ac[kTileBytes];

// Main, originally func_0202ab34 (USA 0x0202ab34, EUR 0x0202ab44, JPN 0x0202a6ec)
extern "C" ARM void DebugConsole_LoadGlyphTiles(void* firstCharacter, int count, int tileIndex) {
    char character[3] = {};
    memcpy(character, firstCharacter, 2);
    for (int i = 0; i < count; i++) {
        unsigned char* glyph = (unsigned char*)Font_FindGlyph(8, character);
        if (glyph != NULL) {
            unsigned char* destination = data_020fe9ac;
            memset(destination, 0, kTileBytes);
            int bit = 0;
            short row = 0;
            while (row < 8) {
                for (short column = 0; column < 8; column++) {
                    if (*glyph & (1 << bit)) {
                        if (column & 1) {
                            destination[column >> 1] = (destination[column >> 1] & 0x0f) | 0x10;
                        } else {
                            destination[column >> 1] &= 0xf0;
                            destination[column >> 1] |= 0x01;
                        }
                    }
                    var4++;
                    if (var4 >= 8) {
                        var4 = 0;
                        var2++;
                    }
                }
                var5++;
                var3 += 4;
            }
            CleanInvalidateCacheRange(data_020fe9ac, kTileBytes);
            LoadToMainBG1CharacterData(data_020fe9ac, tileIndex * kTileBytes, kTileBytes);
            CleanCacheRange(data_020fe9ac, kTileBytes);
        }
        tileIndex = (tileIndex + 1) & 255;
        character[1]++;
    }
}
