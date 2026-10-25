#include <globaldefs.h>

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

struct Keyboard {
    struct KeyboardKey* key;
    struct KeyboardLayout* layout;
};

// Overlay 3, originally func_ov003_0215f4a4 (USA/EUR 0x0215f4a4; JPN not identified)
extern "C" ARM struct KeyboardKey* Keyboard_FindKeyByAction(struct Keyboard* keyboard, int action) {
    struct KeyboardLayout* layout = keyboard->layout;
    short count = layout->count;
    struct KeyboardKey* key = layout->keys;
    short i = 0;
    while (i < count) {
        if (key->action == action) return key;
        i = (short)(i + 1);
        key = (struct KeyboardKey*)((char*)key + sizeof(struct KeyboardKey));
    }
    return 0;
}
