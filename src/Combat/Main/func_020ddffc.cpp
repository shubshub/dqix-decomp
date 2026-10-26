#include <globaldefs.h>

struct Struct_020ddfb4_2 {
    unsigned char pad0[4];
    unsigned char unknown_4_;
    unsigned char pad5[0xf];
    int field14;
    int field18;
    unsigned char unknown_1c_[4];
    int field20;
};

// USA: func_020ddffc
extern "C" ARM void func_020ddffc(struct Struct_020ddfb4_2* obj) {
    obj->field18 = obj->field18 + obj->field20;
    if (obj->field14 < 0) {
        obj->field14 = obj->field14 + 1;
    }
    if (obj->field18 >= 0x1000) {
        obj->field18 = 0x1000;
        obj->unknown_4_ = 3;
    }
}
