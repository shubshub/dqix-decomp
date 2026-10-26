#include <globaldefs.h>
#include "Resource/Font.h"

extern "C" struct FontCharacter* Font_FindCharacter(int text, int font);
extern "C" int Font_FindCharacterIndex(int text, int font);

// Main, originally func_020426bc (USA 0x020426bc, EUR 0x020426cc; JPN not identified)
extern "C" ARM int Font_EncodeText(char* text, unsigned char* encoded, int font) {
    if (encoded == 0) return 0;
    if (text == 0) {
        if (encoded != 0) *encoded = 0;
        return 0;
    }
    int count = 0;
    for (;;) {
        signed char firstByte = *text;
        if (firstByte == 0) {
            *encoded = 0;
            break;
        }
        int byteLength = 1;
        int code = 0;
        struct FontCharacter* character = Font_FindCharacter((int)text, font);
        if (character != 0) {
            byteLength = character->byteLength_;
        }
        if (firstByte == ' ') code = 0xff;
        int index = Font_FindCharacterIndex((int)text, font);
        if (index > 0) code = index & 0xff;
        *encoded++ = (unsigned char)code;
        text += byteLength;
        count++;
    }
    return count;
}
