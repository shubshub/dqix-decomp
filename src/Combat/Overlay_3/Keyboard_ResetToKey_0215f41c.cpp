#include <globaldefs.h>
#include "Resource/Keyboard.h"

int STD_GetStringLength(const char* s);
extern "C" int memcmp(void* a, void* b, int n);

// One key (0x14 bytes), with Keyboard_FindKeyByText's field names.
struct KeyboardKey {
    short x;
    short y;
    const char* text;
    const char* shiftedText;
    unsigned char pages;
    unsigned char action;
    unsigned char sizeClass;
    unsigned char disabled;
    char unk_10[4];
};

// The key list: the keys and their capacity and count (KeyboardLayout_Init's names).
struct KeyboardLayout {
    struct KeyboardKey* keys;
    short keyCapacity;
    short count;
};

// The keyboard, with CharacterCreationUI_HandleNameEntry's field names.
struct Keyboard {
    struct KeyboardKey* key;
    struct KeyboardLayout* layout;
    char* text;
    int widthLimit;
    int textSize;
    int maxLength;
    int repeatTimer;
    short repeatDir;
    unsigned char page;
    unsigned char font;
    unsigned char shift;
};

// Overlay 3, originally func_ov003_0215f41c (USA/EUR 0x0215f41c; JPN not identified)
extern "C" ARM void Keyboard_ResetToKey(struct Keyboard* keyboard, char* text) {
    int length;
    struct KeyboardKey* key;
    short count;
    keyboard->key = 0;
    keyboard->repeatTimer = 0;
    keyboard->repeatDir = 0;
    keyboard->page = KeyboardPage_Lowercase;
    keyboard->shift = 0;
    length = STD_GetStringLength(text);
    struct KeyboardLayout* layout = keyboard->layout;
    count = layout->count;
    key = layout->keys;
    for (short i = 0; i < count; i++, key++) {
        void* keyText = (void*)key->text;
        if (keyText != 0) {
            if (memcmp(keyText, text, length) == 0) {
                keyboard->key = key;
                return;
            }
        }
    }
}
