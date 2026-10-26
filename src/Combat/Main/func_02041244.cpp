#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_0203d028_10 {
    char unknown_0_[0xac];
    unsigned short field_ac;
    char unknown_ae_[2];
    int unknown_b0_;
    char unknown_b4_[0xc];
    int unknown_c0_;
    unsigned char field_c4;
    char unknown_c5_[3];
    int unknown_c8_;
    int field_cc;
    int field_d0;
    unsigned char unknown_d4_;
};

// USA: func_02041244
extern "C" ARM void func_02041244(struct Struct_0203d028_10* obj) {
    ((Object3D*)obj)->Initialize();
    obj->field_ac = 0;
    obj->unknown_b0_ = 0;
    obj->unknown_c0_ = 0;
    obj->field_c4 = 0;
    obj->field_cc = 0;
    obj->unknown_c8_ = 0x7a;
    obj->unknown_d4_ &= ~1;
    obj->unknown_d4_ &= ~2;
    obj->field_d0 = 0;
}
