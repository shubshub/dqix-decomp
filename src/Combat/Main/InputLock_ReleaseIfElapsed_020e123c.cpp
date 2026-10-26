#include <globaldefs.h>
#include "Input/Input.h"

int IsElapsedTicksBelowThreshold_020e11e4(void);

struct Ctx02153628 { void* field0; unsigned int field4; unsigned int field8; };
extern Ctx02153628 data_02153628;

// Main, originally func_020e123c (USA 0x020e123c, EUR 0x020e124c, JPN 0x020e2e34)
extern "C" ARM void InputLock_ReleaseIfElapsed(void) {
    if (IsElapsedTicksBelowThreshold_020e11e4()) {
        return;
    }
    data_02153628.field4 = 0;
    data_02153628.field8 = 0;
    data_02153628.field0 = 0;
    g_keyManager.SetInputEnabled(true);
    g_touchInput.SetInputEnabled(true);
}
