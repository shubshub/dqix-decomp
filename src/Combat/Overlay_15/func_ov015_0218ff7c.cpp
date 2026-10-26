#include <globaldefs.h>

struct Struct_ov015_0218ff7c { char pad[0x1c]; unsigned char unknown_1c_; char pad2[3]; int* unknown_20_; char pad3[8]; unsigned char unknown_2c_; };

// USA: func_ov015_0218ff7c
extern "C" ARM void func_ov015_0218ff7c(struct Struct_ov015_0218ff7c* o, int idx, int val) {
    unsigned char f = o->unknown_1c_;
    if (f != 0 && f != 1)
        return;
    if (val != o->unknown_20_[idx]) {
        o->unknown_20_[idx] = val;
        o->unknown_2c_ = 1;
    }
}
