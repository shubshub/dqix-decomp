#include <globaldefs.h>
#include "World/Object3D.h"
#include "Input/Input.h"

extern "C" void func_ov015_0218d50c(void* obj);

struct Struct_ov015_0218e4f8 {
    char pad0[0x24];
    char* unknown_24_;
    char pad1[0x2c - 0x24 - 4];
    unsigned char unknown_2c_;
    char pad2[0x3a - 0x2c - 1];
    unsigned char unknown_3a_;
};

// USA: func_ov015_0218e4f8
extern "C" ARM void func_ov015_0218e4f8(struct Struct_ov015_0218e4f8* obj) {
    unsigned char var0;
    unsigned char var1 = obj->unknown_2c_;
    if (var1 != 0) {
        func_ov015_0218d50c(obj);
    }
    var0 = obj->unknown_3a_;
    char* sub;
    int result = 0;
    char* base = obj->unknown_24_;
    sub = base + 8;
    if (var0 != 0) {
        if (g_keyManager.TestKeysPressed(0x100)) result = 1;
    } else {
        result = 1;
    }
    if (!result) return;
    ((Object3D*)base)->AdvanceEffects();
    ((Object3D*)(sub + 0x400))->AdvanceEffects();
    ((Object3D*)(base + 0x35c))->AdvanceEffects();
    ((Object3D*)(base + 0xac))->AdvanceEffects();
}
