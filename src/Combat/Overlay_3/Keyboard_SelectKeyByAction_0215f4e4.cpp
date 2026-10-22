#include <globaldefs.h>

struct KeyboardKey;
struct Keyboard {
    KeyboardKey* key_;
};

extern "C" KeyboardKey* Keyboard_FindKeyByAction(Keyboard* keyboard, int id);

// Overlay 3, originally StoreResultIfNonZero_0215f4e4 (USA/EUR 0x0215f4e4; JPN not identified)
ARM void Keyboard_SelectKeyByAction(Keyboard* keyboard, int id) {
    KeyboardKey* key = Keyboard_FindKeyByAction(keyboard, id);
    if (key != 0) {
        keyboard->key_ = key;
    }
}
