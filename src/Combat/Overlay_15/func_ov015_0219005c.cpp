#include <globaldefs.h>

struct Struct_ov015_0219005c { char pad[0x1c]; unsigned char unknown_1c_; char pad2[0xf]; unsigned char unknown_2c_; char pad3[0x13]; short field40; short unknown_42_; };

// USA: func_ov015_0219005c
extern "C" ARM void func_ov015_0219005c(struct Struct_ov015_0219005c* o, short v1, short v2) {
    unsigned char f = o->unknown_1c_;
    if (f != 0 && f != 1)
        return;
    if (o->unknown_42_ != v1 || o->field40 != v2) {
        o->unknown_42_ = v1;
        o->field40 = v2;
        o->unknown_2c_ = 2;
    }
}
