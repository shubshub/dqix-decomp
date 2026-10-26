#include <globaldefs.h>
#include "Graphics/GlyphBitmapContext.h"

// Main, originally SetBuffer02028ddc (USA 0x02028ddc, EUR 0x02028dec, JPN 0x0202862c)
ARM void GlyphBitmapContext_SetBuffer(void* buffer) {
    glyphBitmapContext.buffer = buffer;
}
