#include <globaldefs.h>

struct Struct_020017c0 {
    unsigned char pad0[0x18];
    int f18;
    int f1c;
    int f20;
    int f24;
    int f28;
    int unknown_2c_;
    unsigned char pad2[4];
    int f34;
};

// USA: func_020017c0
extern "C" ARM void func_020017c0(Struct_020017c0* obj) {
    obj->f24 = obj->f1c;
    obj->f28 = obj->f20;
    obj->f28 = obj->f28 - (obj->f18 & obj->unknown_2c_);
    obj->f34 = obj->f18;
}
