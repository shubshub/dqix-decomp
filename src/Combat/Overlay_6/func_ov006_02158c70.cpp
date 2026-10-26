#include <globaldefs.h>
#include "Input/Input.h"

// USA: func_ov006_02158c70
extern "C" ARM int func_ov006_02158c70() {
    int result = 0;
    int b = g_touchInput.pressed_;
    if (g_keyManager.TestKeysPressed(0x7f3) || b) {
        result = 1;
    }
    return result;
}
