#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "std_library_functions.h"
#include "NitroSDK/Cache.h"

// A 4bpp 256x192 bitmap
enum { kBitmapSize = 256 * 192 / 2 };

#if defined(jpn)
extern "C" int func_020429d4(void);

typedef unsigned char Type_02029088[4];
typedef Type_02029088 Type_01ff8b48_18[8];
typedef Type_02029088 Type_02029088_2[32];
typedef Type_02029088_2 Type_02029088_3[8];
#endif

// Main, originally FlushBuffer02029088 (USA 0x02029088, EUR 0x02029098, JPN 0x020288d8)
extern "C" ARM void GlyphBitmapContext_Flush() {
    if (glyphBitmapContext.buffer == NULL) return;
#if defined(jpn)
    unsigned char* var0 = reinterpret_cast<unsigned char*>(func_020429d4());
    unsigned char* image = static_cast<unsigned char*>(glyphBitmapContext.buffer);
    unsigned char* destination;
    const unsigned char* source;
    unsigned int var4;
    unsigned int band;
    unsigned int tile;
    unsigned int row;
    unsigned int var8;
    for (band = 0; band < 24; ++band) {
        var4 = band * sizeof(Type_02029088_3);
        destination = var0;
        var8 = var4;
        for (tile = 0; tile < 32; ++tile) {
            source = image + var4;
            for (row = 0; row < 8; ++row) {
                memcpy(destination, source, sizeof(Type_02029088));
                destination += sizeof(Type_02029088);
                source += sizeof(Type_02029088_2);
            }
            var4 += sizeof(Type_02029088);
        }
        memcpy(image + var8, var0, sizeof(Type_02029088_3));
    }
#endif
    CleanInvalidateCacheRange(glyphBitmapContext.buffer, kBitmapSize);
}
