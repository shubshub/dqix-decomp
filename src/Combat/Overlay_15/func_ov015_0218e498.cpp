#include <globaldefs.h>
#include "World/Object3D.h"
#include "Input/Input.h"

struct Struct_ov015_0218e498 {
    unsigned char pad0[0x24];
    unsigned char* field24;
    unsigned char pad1[0x2c - 0x24 - 4];
    unsigned char unknown_2c_;
    unsigned char pad2[0x3a - 0x2c - 1];
    unsigned char unknown_3a_;
};

extern "C" void func_ov015_0218cc24(struct Struct_ov015_0218e498* obj);

// USA: func_ov015_0218e498
extern "C" ARM void func_ov015_0218e498(struct Struct_ov015_0218e498* obj) {
    if (obj->unknown_2c_ != 0) {
        func_ov015_0218cc24(obj);
    }

    unsigned char cond = obj->unknown_3a_;
    unsigned char* p = obj->field24;
    int flag = 0;
    if (cond != 0) {
        if (g_keyManager.TestKeysPressed(0x100) != 0) {
            flag = 1;
        }
    } else {
        flag = 1;
    }
    if (flag) {
        ((Object3D*)p)->AdvanceEffects();
    }
}
