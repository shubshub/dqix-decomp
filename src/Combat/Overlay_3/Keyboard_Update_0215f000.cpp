#include <globaldefs.h>
#include "Input/Input.h"
#include "Resource/Keyboard.h"

// One key, with Keyboard_FindKeyByText's field names.
struct KeyboardKey {
    short x;
    short y;
    const char* text;
    const char* shiftedText;
    unsigned char pages;            // the KeyboardPage bits it shows on
    unsigned char action;
    unsigned char sizeClass;        // Keyboard_GetKeySize
    unsigned char disabled;
    short id;                       // what the page grids list
    char unk_12[0x14 - 0x12];
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
    unsigned short repeatDir;
    unsigned char page;
    unsigned char font;
    unsigned char shift;
    unsigned char wrap;
    unsigned char allowAlt;
    unsigned char allowCancel;
    unsigned char autoRepeat;
};

// A page's key grid (8 bytes: pages mask, columns, rows, cell count, key ids), built by the layout script.
struct KeyboardPageGrid;

struct KeyboardPageGrid* Keyboard_GetPageGrid(struct Keyboard* self);
extern "C" int KeyboardPageGrid_FindKeyCell(struct KeyboardPageGrid* table, short id, signed char* col, signed char* row);
extern "C" void Keyboard_MoveCursor(struct Keyboard* self, int dx, int dy);
extern "C" int Keyboard_HandleKey(struct Keyboard* self);
extern "C" int Keyboard_DeleteCharacter(struct Keyboard* self);
extern "C" void Keyboard_GetKeySize(int shape, short* w, short* h);

// Overlay 3, originally func_ov003_0215f000 (USA/EUR 0x0215f000; JPN not identified)
extern "C" ARM int Keyboard_Update(struct Keyboard* keyboard, int elapsed) {
    struct KeyboardKey* previousKey = keyboard->key;
    int i;
    short count;
    struct KeyboardKey* touchedKey;
    unsigned char page;
    int result;

    if (keyboard->key == 0) {
        result = KeyboardResult_None;
        keyboard->repeatTimer = 0;
        keyboard->repeatDir = 0;
    } else {
        if (g_keyManager.TestKeysPressed(KEY_UP)) {
            Keyboard_MoveCursor(keyboard, 0, -1);
            keyboard->repeatTimer = KeyboardRepeat_InitialDelay;
            keyboard->repeatDir = KEY_UP;
        } else if (g_keyManager.TestKeysPressed(KEY_DOWN)) {
            Keyboard_MoveCursor(keyboard, 0, 1);
            keyboard->repeatTimer = KeyboardRepeat_InitialDelay;
            keyboard->repeatDir = KEY_DOWN;
        } else if (g_keyManager.TestKeysPressed(KEY_LEFT)) {
            Keyboard_MoveCursor(keyboard, -1, 0);
            keyboard->repeatTimer = KeyboardRepeat_InitialDelay;
            keyboard->repeatDir = KEY_LEFT;
        } else if (g_keyManager.TestKeysPressed(KEY_RIGHT)) {
            Keyboard_MoveCursor(keyboard, 1, 0);
            keyboard->repeatTimer = KeyboardRepeat_InitialDelay;
            keyboard->repeatDir = KEY_RIGHT;
        }

        if (keyboard->autoRepeat) {
            unsigned short dir = keyboard->repeatDir;
            if (dir != 0 && g_keyManager.TestKeysHeld(KEY_UP | KEY_DOWN | KEY_LEFT | KEY_RIGHT)) {
                int timer = keyboard->repeatTimer - elapsed;
                if (timer <= 0) {
                    timer = KeyboardRepeat_Delay;
                    switch (dir) {
                    case KEY_UP:
                        Keyboard_MoveCursor(keyboard, 0, -1);
                        break;
                    case KEY_DOWN:
                        Keyboard_MoveCursor(keyboard, 0, 1);
                        break;
                    case KEY_LEFT:
                        Keyboard_MoveCursor(keyboard, -1, 0);
                        break;
                    case KEY_RIGHT:
                        Keyboard_MoveCursor(keyboard, 1, 0);
                        break;
                    }
                    if (keyboard->autoRepeat) {
                        signed char curRow;
                        signed char curCol;
                        signed char prevRow;
                        signed char prevCol;
                        struct KeyboardPageGrid* grid = Keyboard_GetPageGrid(keyboard);
                        struct KeyboardKey* currentKey = keyboard->key;
                        if (KeyboardPageGrid_FindKeyCell(grid, previousKey->id, &prevCol, &prevRow) == 0
                            && KeyboardPageGrid_FindKeyCell(grid, currentKey->id, &curCol, &curRow) == 0) {
                            switch (dir) {
                            case KEY_UP:
                                if (prevRow < curRow) keyboard->key = previousKey;
                                break;
                            case KEY_DOWN:
                                if (prevRow > curRow) keyboard->key = previousKey;
                                break;
                            case KEY_LEFT:
                                if (prevCol < curCol) keyboard->key = previousKey;
                                break;
                            case KEY_RIGHT:
                                if (prevCol > curCol) keyboard->key = previousKey;
                                break;
                            }
                        }
                    }
                }
                keyboard->repeatTimer = timer;
            } else {
                keyboard->repeatTimer = 0;
                keyboard->repeatDir = 0;
            }
        }
        if (previousKey == keyboard->key) {
            result = KeyboardResult_None;
        } else {
            result = KeyboardResult_CursorMoved;
        }
    }

    if (result == KeyboardResult_None) {
        unsigned char allowAlt = keyboard->allowAlt;
        unsigned char allowCancel = keyboard->allowCancel;
        if (g_keyManager.TestKeysPressed(KEY_A)
            || (allowAlt && g_keyManager.TestKeysPressed(KEY_L))) {
            result = Keyboard_HandleKey(keyboard);
        } else if (allowCancel && g_keyManager.TestKeysPressed(KEY_B)) {
            result = Keyboard_DeleteCharacter(keyboard);
        } else {
            result = KeyboardResult_None;
        }

        if (result == KeyboardResult_None) {
            page = keyboard->page;
            if (g_touchInput.pressed_) {
                int touchY;
                int touchX;
                g_touchInput.GetTouchPoint(&touchX, &touchY);
                struct KeyboardLayout* layout = keyboard->layout;
                touchedKey = layout->keys;
                count = layout->count;
                for (i = 0; i < count; i++, touchedKey++) {
                    if (touchedKey->pages & page) {
                        short height;
                        short width;
                        Keyboard_GetKeySize(touchedKey->sizeClass, &width, &height);
                        if (touchedKey->y <= touchY && touchY < touchedKey->y + height && touchedKey->x <= touchX && touchX < touchedKey->x + width) {
                            goto found;
                        }
                    }
                }
            }
            touchedKey = 0;
        found:
            if (touchedKey != 0) {
                keyboard->key = touchedKey;
                result = Keyboard_HandleKey(keyboard);
            }
        }
    }
    return var5;
}
