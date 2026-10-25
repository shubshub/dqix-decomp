#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int memcmp(const char* a, const char* b, unsigned int n);

// One key (0x14 bytes), with the field names of CharacterCreationUI_HandleSetup's copy.
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

// The key list KeyboardLayout_Init clears: the keys and their count.
struct KeyboardLayout {
    KeyboardKey* keys;
    short unk_4;
    short count;
};

struct Keyboard {
    KeyboardKey* key;
    KeyboardLayout* layout;
};

// Overlay 3, originally func_ov003_0215f4fc (USA/EUR 0x0215f4fc; JPN not identified)
extern "C" ARM KeyboardKey* Keyboard_FindKeyByText(Keyboard* keyboard, const char* text) {
    unsigned int length;
    KeyboardKey* key;
    short i;
    short count;
    length = strlen(text);
    count = keyboard->layout->count;
    key = keyboard->layout->keys;
    for (i = 0; i < count; i++, key++) {
        if (key->text != 0 && memcmp(key->text, text, length) == 0) {
            return key;
        }
    }
    return 0;
}
