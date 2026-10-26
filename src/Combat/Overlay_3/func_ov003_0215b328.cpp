#include <globaldefs.h>
#include "Input/Input.h"

struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);

// USA: func_ov003_0215b328
extern "C" ARM int func_ov003_0215b328(char* obj) {
    int a = Window_IsSelectionTouched((struct Obj_0205da38*)(obj + 0xf4), 0x14);
    int b = g_keyManager.TestKeysPressed(1);
    int c = g_keyManager.TestKeysPressed(0x400);
    return (a | (b | c)) != 0;
}
