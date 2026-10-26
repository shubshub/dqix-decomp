#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define func_ov023_021e6de4 func_ov023_021e7148
#endif

struct Obj_0205da38;
extern "C" int Window_IsSelectionTouched(struct Obj_0205da38* obj, int key);

// USA: func_ov023_021e6de4
extern "C" ARM int func_ov023_021e6de4(char* obj) {
    int a = g_keyManager.TestKeysPressed(0x601);
    int b = Window_IsSelectionTouched((struct Obj_0205da38*)(obj +
#if defined(jpn)
        0x90
#else
        0xac
#endif
        ), 0x14);
    return (a | b) != 0;
}
