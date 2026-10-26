#include <globaldefs.h>
#include "Input/Input.h"
#if defined(jpn)
enum { kRegion98 = 0xb0 };
#else
enum { kRegion98 = 0x98 };
#endif

struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);

// USA: func_ov003_0215dcb8
extern "C" ARM int func_ov003_0215dcb8(char* obj) {
    int a = Window_IsSelectionTouched((struct Obj_0205da38*)(obj + kRegion98), 0x14);
    int b = g_keyManager.TestKeysPressed(1);
    int c = g_keyManager.TestKeysPressed(0x400);
    return (a | (b | c)) != 0;
}
