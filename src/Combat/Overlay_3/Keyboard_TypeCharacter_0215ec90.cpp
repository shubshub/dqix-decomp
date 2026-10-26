#include <globaldefs.h>
#include "Resource/Font.h"
#include "Resource/Keyboard.h"

// One key, with Keyboard_FindKeyByText's field names.
struct KeyboardKey {
    short x;
    short y;
    int text;
    int shiftedText;
    unsigned char pages;
    unsigned char action;
    unsigned char sizeClass;
    unsigned char disabled;
};

// The keyboard, with CharacterCreationUI_HandleNameEntry's field names.
struct Keyboard {
    struct KeyboardKey* key;
    void* layout;
    char* text;
    int widthLimit;
    int textSize;
    int maxLen;
    int repeatTimer;
    short repeatDir;
    unsigned char page;
    unsigned char font;
    unsigned char shift;
};

extern "C" void __clear(void* buf, int size);
extern "C" int Font_FindCharacterIndex(int key, int tableIdx);
extern "C" int Font_EncodeText(void* src, void* dst, int flag);
extern "C" void Font_DecodeText(void* src, void* dst, int flag);
extern "C" int Font_GetTextWidth(void* str, int flag);
extern "C" struct FontCharacter* Font_FindCharacter(int key, int tableIdx);

// By shift: the page on which a key types its shiftedText ({KeyboardPage_Uppercase, KeyboardPage_Lowercase} in the ROM).
extern unsigned char Keyboard_shiftedTextPages[];

// Overlay 3, originally func_ov003_0215ec90 (USA/EUR 0x0215ec90; no JPN match, its keyboard differs)
extern "C" ARM int Keyboard_TypeCharacter(struct Keyboard* keyboard) {
    unsigned char encoded[0x100];
    unsigned char decoded[0x100];
    unsigned char* slot;
    int keyText;
    int characterIndex;
    struct FontCharacter* character;
    int width;
    int i;
    int length;
    char* text;
    int widthLimit;
    int font;
    int maxLen;
    struct KeyboardKey* key = keyboard->key;
    if (key != 0) {
        if (key->disabled != 0) {
            return KeyboardResult_KeyDisabled;
        }

        font = keyboard->font;
        text = keyboard->text;
        keyText = key->text;
        if (Keyboard_shiftedTextPages[keyboard->shift] == keyboard->page) {
            keyText = key->shiftedText;
        }
        widthLimit = keyboard->widthLimit;
        maxLen = keyboard->maxLen;

        __clear(encoded, sizeof(encoded));
        characterIndex = Font_FindCharacterIndex(keyText, font);
        length = Font_EncodeText(text, encoded, font);
        slot = encoded;
        for (i = 0; i < maxLen; i++, slot++) {
            if (i == maxLen - 1) {
                unsigned char previous = *slot;
                *slot = characterIndex;
                if (widthLimit != 0) {
                    __clear(decoded, sizeof(decoded));
                    Font_DecodeText(encoded, decoded, font);
                    if (widthLimit < Font_GetTextWidth(decoded, 0)) {
                        *slot = previous;
                        break;
                    }
                }
                Font_DecodeText(encoded, text, font);
                keyboard->shift = 0;
                return (maxLen <= length + 1) ? KeyboardResult_TypedFull : KeyboardResult_Typed;
            }
            if (*slot == 0) {
                if (widthLimit != 0) {
                    width = Font_GetTextWidth(text, 0);
                    character = Font_FindCharacter(keyText, 0);
                    if (character != 0) {
                        width += character->width_ + 1;
                    }
                    if (widthLimit < width) {
                        break;
                    }
                }
                *slot = characterIndex;
                Font_DecodeText(encoded, text, font);
                keyboard->shift = 0;
                return (maxLen <= length + 1) ? KeyboardResult_TypedFull : KeyboardResult_Typed;
            }
        }
    }
    return KeyboardResult_None;
}
