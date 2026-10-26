#include <globaldefs.h>
#include "Input/Input.h"

struct Struct_ov003_0217c74c {
    char pad0[0x140];
    unsigned char unknown_140_;
    unsigned char unknown_141_;
};

// USA: func_ov003_0217c74c
extern "C" ARM void func_ov003_0217c74c(struct Struct_ov003_0217c74c* obj) {
    if (!g_keyManager.TestKeysPressed(0xc0f)) {
        if (g_touchInput.isRepeatValid_ == 0) return;
        if (g_touchInput.currentReading_.isHeld == 0) return;
    }
    obj->unknown_140_ = 4;
    obj->unknown_141_ = 0;
}
