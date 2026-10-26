#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" void func_02056b48(void* p);

struct Struct_020556dc {
    unsigned char unknown_0_[0xc];
    unsigned char unknown_c_;
    unsigned char unknown_d_[0x28 - 0xd];
    unsigned int f28;
    unsigned int unknown_2c_;
    unsigned int unknown_30_;
    unsigned int f34;
    unsigned char unknown_38_[0x39 - 0x38];
    unsigned char unknown_39_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned char unknown_3c_[0x40 - 0x3c];
    unsigned int f40;
    unsigned int unknown_44_;
    unsigned int unknown_48_;
    unsigned char unknown_4c_[0xc4 - 0x4c];
    unsigned char blockA[0xc];
    unsigned char blockB[0xc];
    unsigned char unknown_dc_[0xc];
    unsigned char unknown_e8_[0x154 - 0xe8];
    unsigned int f154;
};

// USA: func_02056d10
extern "C" ARM void func_02056d10(struct Struct_020556dc* obj) {
    func_02056b48(obj);
    obj->unknown_30_ = 0;
    obj->unknown_2c_ = 0;
    obj->f28 = 0;
    obj->unknown_c_ = 0;
    obj->unknown_39_ = 0;
    obj->unknown_3a_ = 0;
    obj->unknown_3b_ = 0;
    obj->f40 = 0;
    obj->unknown_44_ = 0;
    obj->unknown_48_ = 0;
    obj->f154 = 0;
    obj->f34 = 0;
    memset(obj->blockA, 0, 0xc);
    memset(obj->blockB, 0, 0xc);
    memset(obj->unknown_dc_, 0, 0xc);
}
