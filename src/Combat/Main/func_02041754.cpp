#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"
#include "Graphics/VRAMStaging.h"

struct Struct_0200f3a4_13;
// USA: func_02041754
extern "C" ARM void func_02041754(Struct_0204166c* object) {
    Struct_0204166c* glyph = object;
    if (glyph->unknown_8_ < 0) return;
    if (glyph->unknown_16_0_ && glyph->pixels != 0) {
        StageMemoryToVRAM(VRAMSubregion_TextureImage, glyph->pixels, glyph->unknown_4_, 16 * 16 / 2, true, true);
        glyph->unknown_16_0_ = false;
    }
}
