#include <globaldefs.h>

// One key, with Keyboard_FindKeyByText's field names.
struct KeyboardKey {
    short x;
    short y;
    const char* text;
    const char* shiftedText;
    unsigned char pages;
    unsigned char action;           // KeyboardAction: the slot of the action table it calls
};

struct Keyboard {
    struct KeyboardKey* key;
};

// The key action table, one handler per KeyboardAction (Keyboard_TypeCharacter first).
typedef void* (*KeyboardActionHandler)(void*);

struct KeyboardActionTable {
    KeyboardActionHandler handlers[9];
};

extern struct KeyboardActionTable Keyboard_actionHandlers;

// Overlay 3, originally func_ov003_0215ef54 (USA/EUR 0x0215ef54; JPN not identified)
extern "C" ARM void* Keyboard_HandleKey(void* keyboard) {
    struct KeyboardKey* key = ((struct Keyboard*)keyboard)->key;
    struct KeyboardActionTable table;
    if (key != 0) {
        table = Keyboard_actionHandlers;
        return table.handlers[key->action](keyboard);
    }
    return 0;
}
