#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"
#include "Graphics/GlyphMetrics.h"

extern int data_020e7a94[];
extern "C" int Font_FindCharacterIndex(int, int);
extern "C" FontCharacter* Font_GetCharacter(int index, int fontIndex);
extern "C" int Font_GetKerning(int previousCharacter, int characterIndex, int fontIndex);

#if defined(jpn)

// USA: Font_GetTextWidth
extern "C" ARM void func_02028ce4(const char* text, int* arg1, int* arg2) {
    if (text == 0) return;
    int var0 = 10;
    int lineHeight = 11;
    int displayMode = data_020ef74c.displayMode;

    if ((unsigned int)(displayMode - 3) <= 1) {
    } else if ((unsigned int)(displayMode - 5) <= 1) {
        var0 = 12;
        lineHeight = 13;
    }
    int var3;
    int var4 = 0;
    var3 = 0;
    int height = lineHeight;
    unsigned char glyphCount = 0;
    const unsigned char* cursor = (const unsigned char*)text;
    while (*cursor != 0 && glyphCount < 25) {
        unsigned int var8 = *cursor;
        if (var8 == 10) {

            if (var4 < var3) {
                var4 = var3;
                var3 = 0;
            }
            height += lineHeight;
            cursor++;
        } else if ((var8 >= 0x81 && var8 <= 0x9f) || (var8 >= 0xe0 && var8 <= 0xea)) {
            var3 += var0;
            cursor += 2;
            glyphCount++;
        } else {
            var3 += var0;
            cursor++;
            glyphCount++;
        }
    }
    if (var4 < var3) var4 = var3;
    *arg1 = var4;
    *arg2 = height;
}
#else

// Main, originally func_020420e8 (USA 0x020420e8, EUR 0x020420f8, JPN 0x020420e8)
extern "C" ARM int Font_GetTextWidth(char* text, int fontIndex) {
    if (text == 0) return 0;
    int var0 = data_020e7a94[fontIndex] & 0xff;
    int var1 = 0xff;
    int previousCharacter = var1;
    int characterIndex;
    int var4 = 0;
    for (;;) {
        if (*text == 0) break;
        int advance = var0 + 1;
        int index = Font_FindCharacterIndex((int)text, fontIndex);
        if (index < 0) {
            previousCharacter = var1;
            text++;
        } else {
            characterIndex = index & 0xff;
            FontCharacter* entry = Font_GetCharacter(index, fontIndex);
            int kerning = Font_GetKerning(previousCharacter, characterIndex, fontIndex);
            previousCharacter = characterIndex;
            advance = (entry->width_ + 1) + kerning;
            text = text + entry->byteLength_;
        }
        var4 += advance;
    }
    return var4 - 1;
}
#endif
