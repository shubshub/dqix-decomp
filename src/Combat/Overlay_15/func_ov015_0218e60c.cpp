#if defined(jpn)
#define R(j,u) (j)
#else
#define R(j,u) (u)
#endif
#include <globaldefs.h>
#include "World/Object3D.h"
#include "Input/Input.h"

extern "C" void func_02055774(int* obj);

struct Struct_ov015_0218e60c {
    char unknown_0_[0xc];
    int unknown_c_;
};

struct Struct_ov015_0218e60c_2 {
    char unknown_0_[0x24];
    void* unknown_24_;
    struct Struct_ov015_0218e60c* unknown_28_;
    char unknown_2c_[0xe];
    unsigned char unknown_3a_;
};

// USA: func_ov015_0218e60c
extern "C" ARM void func_ov015_0218e60c(struct Struct_ov015_0218e60c_2* obj) {
    int ok = 0;
    if (obj->unknown_3a_ != 0) {
        if (g_keyManager.TestKeysPressed(0x100) != 0) {
            ok = 1;
        }
    } else {
        ok = 1;
    }
    if (ok == 0) {
        return;
    }
    struct Struct_ov015_0218e60c* p = obj->unknown_28_;
    if (p->unknown_c_ != 0) {
        func_02055774((int*)p);
    } else {
        ((Object3D*)obj->unknown_24_)->AdvanceEffects();
    }
}
