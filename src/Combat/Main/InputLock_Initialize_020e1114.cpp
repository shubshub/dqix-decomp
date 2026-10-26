#include <globaldefs.h>
#include "Input/Input.h"

struct Struct02153628_020e1114 { unsigned int field0; unsigned int field4; unsigned int field8; };
extern struct Struct02153628_020e1114 data_02153628;

// Main, originally ResetElapsedState020e1114 (USA 0x020e1114, EUR 0x020e1124, JPN 0x020e2d0c)
ARM void InputLock_Initialize(void) {
    data_02153628.field4 = 0;
    data_02153628.field8 = 0;
    data_02153628.field0 = 0;
    g_keyManager.SetInputEnabled(true);
    g_touchInput.SetInputEnabled(true);
}
