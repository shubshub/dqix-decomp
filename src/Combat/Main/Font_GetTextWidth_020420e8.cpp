#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"
#include "Graphics/GlyphMetrics.h"

extern int data_020e7a94[];
int Font_FindCharacterIndex(int, int);
FontCharacter* Font_GetCharacter(int index, int fontIndex);
int Font_GetKerning(int previousCharacter, int characterIndex, int fontIndex);

#if defined(jpn)

// USA: Font_GetTextWidth
extern "C" ARM void func_02028ce4(const char* text, int* widthOut, int* heightOut) {
    if (text == 0) return;
    int glyphAdvance = 10;
    int lineHeight = 11;
    int displayMode = data_020ef74c.displayMode;

    if ((unsigned int)(displayMode - 3) <= 1) {
    } else if ((unsigned int)(displayMode - 5) <= 1) {
        glyphAdvance = 12;
        lineHeight = 13;
    }
    int lineWidth;
    int widestLine = 0;
    lineWidth = 0;
    int height = lineHeight;
    unsigned char glyphCount = 0;
    const unsigned char* cursor = (const unsigned char*)text;
    while (*cursor != 0 && glyphCount < 25) {
        unsigned int leadByte = *cursor;
        if (leadByte == 10) {

            if (widestLine < lineWidth) {
                widestLine = lineWidth;
                lineWidth = 0;
            }
            height += lineHeight;
            cursor++;
        } else if ((leadByte >= 0x81 && leadByte <= 0x9f) || (leadByte >= 0xe0 && leadByte <= 0xea)) {
            lineWidth += glyphAdvance;
            cursor += 2;
            glyphCount++;
        } else {
            lineWidth += glyphAdvance;
            cursor++;
            glyphCount++;
        }
    }
    if (widestLine < lineWidth) widestLine = lineWidth;
    *widthOut = widestLine;
    *heightOut = height;
}
#else

// Main, originally func_020420e8 (USA 0x020420e8, EUR 0x020420f8, JPN 0x020420e8)
extern "C" ARM int Font_GetTextWidth(char* text, int fontIndex) {
    if (text == 0) return 0;
    int fallbackGlyphWidth = data_020e7a94[fontIndex] & 0xff;
    int noPreviousCharacter = 0xff;
    int previousCharacter = noPreviousCharacter;
    int characterIndex;
    int pixelWidth = 0;
    for (;;) {
        if (*text == 0) break;
        int advance = fallbackGlyphWidth + 1;
        int index = Font_FindCharacterIndex((int)text, fontIndex);
        if (index < 0) {
            previousCharacter = noPreviousCharacter;
            text++;
        } else {
            characterIndex = index & 0xff;
            FontCharacter* entry = Font_GetCharacter(index, fontIndex);
            int kerning = Font_GetKerning(previousCharacter, characterIndex, fontIndex);
            previousCharacter = characterIndex;
            advance = (entry->width_ + 1) + kerning;
            text = text + entry->byteLength_;
        }
        pixelWidth += advance;
    }
    return pixelWidth - 1;
}
#endif
