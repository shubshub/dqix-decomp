#include <globaldefs.h>
#include "Resource/MessageGlyphSlot.h"

struct Struct_020424e4;
struct Struct_0205b234_2 { unsigned char* unknown_0_; Struct_020424e4* unknown_4_; unsigned char unknown_8_; };

int GetWordFromTable02042648(int);
int Font_FindCharacterIndex(int, int);
int LookupKeyValue020425e4(int, int, int);
FontCharacter* Font_GetCharacter(int index, int fontIndex);
extern "C" void func_0205b36c(GlyphDestination0205b234* destination, FontCharacter* glyph, short x, short y, unsigned char color, unsigned char font);

// USA: func_0205b234
extern "C" ARM int func_0205b234(GlyphDestination0205b234* destination, short x, short y, const char* text, unsigned char color, unsigned char font) {
    if (destination->pixels == 0) return 0;
    if (destination->rectangles == 0) return 0;
    if (destination->rectangleCount == 0) return 0;
    if (text == 0) return 0;
    unsigned char fallbackWidth = GetWordFromTable02042648(font);
    int previousCharacter = 0xff;
    short cursorX = x;
    while (*text != 0) {
        int index;
        signed char advance = fallbackWidth + 1;
        index = Font_FindCharacterIndex((int)text, font) & 0xff;
        cursorX += LookupKeyValue020425e4(previousCharacter, index, font);
        int length = 1;
        if (index != 0xff) {
            FontCharacter* character = Font_GetCharacter(index, font);
            func_0205b36c(destination, character, cursorX, y, color, font);
            advance = character->width + 1;
            length = character->byteLength;
        }
        var4 = var6;
        arg3 += var8;
        var5 += var7;
    }
    return var5 - arg1;
}
#endif
