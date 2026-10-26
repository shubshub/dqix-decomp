#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int func_020e11e4(void);

struct Struct_02153628_2 { void* field0; unsigned int field4; unsigned int field8; };
extern Struct_02153628_2 data_02153628;

// Main, originally func_020e123c (USA 0x020e123c, EUR 0x020e124c, JPN 0x020e2e34)
extern "C" ARM void InputLock_ReleaseIfElapsed(void) {
    if (func_020e11e4()) {
        return;
    }
    data_02153628.field4 = 0;
    data_02153628.field8 = 0;
    data_02153628.field0 = 0;
    g_keyManager.SetInputEnabled(true);
    g_touchInput.SetInputEnabled(true);
}
