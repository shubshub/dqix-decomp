#include <globaldefs.h>
#include "Resource/FontBankLoader.h"
#include "Resource/FontGlyphTable.h"

// Main, originally func_02042a50 (USA 0x02042a50, EUR 0x02042a60, JPN 0x020430d0)
extern "C" ARM char* Font_FindGlyph(int pixelSize, const char* encodedCharacter) {
    if (encodedCharacter == NULL) return NULL;
    char* glyph = FindEntryByKeyPair020429e4(Font_GetGlyphTable(pixelSize),
        reinterpret_cast<const unsigned char*>(encodedCharacter));
    if (glyph != NULL) return glyph;
    return FindEntryByKeyPair020429e4(
        static_cast<FontGlyphTable*>(AlwaysFalse02094b44(FontBankLoader_GetInstance(), pixelSize)),
        reinterpret_cast<const unsigned char*>(encodedCharacter));
}
