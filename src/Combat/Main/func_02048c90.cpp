#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_02048c90_2 {
    char unknown_0_[0x10];
    Vector3i unknown_10_;
    char unknown_1c_[0x4];
    unsigned int unknown_20_;
    char pad24[0x10];
    unsigned char unknown_34_;
    char unknown_35_[0x3];
    int unknown_38_;
    unsigned short unknown_3c_;
    char unknown_3e_[0x2];
    Vector3i unknown_40_;
};

struct Struct_02048c90 {
    char unknown_0_[0x13c];
    struct Struct_02048c90_2* ptr;
};

// USA: func_02048c90
extern "C" ARM void func_02048c90(struct Struct_02048c90* obj) {
    if (obj->ptr == NULL) return;
    obj->ptr->unknown_34_ = 0;
    obj->ptr->unknown_38_ = 0;
    obj->ptr->unknown_3c_ = 0;
    obj->ptr->unknown_40_ = obj->ptr->unknown_10_;
    obj->ptr->unknown_20_ &= ~0x10;
    obj->ptr->unknown_20_ &= ~0x40;
}
