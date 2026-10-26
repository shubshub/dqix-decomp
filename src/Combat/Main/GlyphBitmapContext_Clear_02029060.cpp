#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"
#include "std_library_functions.h"

// A 4bpp 256x192 bitmap
enum { kBitmapSize = 256 * 192 / 2 };

// Main, originally ClearBuffer02029060 (USA 0x02029060, EUR 0x02029070, JPN 0x020288b0)
ARM void GlyphBitmapContext_Clear() {
    if (glyphBitmapContext.buffer == NULL) return;
    memset(glyphBitmapContext.buffer, 0, kBitmapSize);
}
