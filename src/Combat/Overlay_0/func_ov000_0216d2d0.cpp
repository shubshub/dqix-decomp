#include <globaldefs.h>
#include "std_library_functions.h"

struct Struct_ov000_0216d2d0 {
    char pad[0x21c];
    int unknown_21c_;
    unsigned char unknown_220_;
    unsigned char unknown_221_;
    char pad2[2];
    int unknown_224_;
    int unknown_228_;
    int unknown_22c_;
    int unknown_230_;
    int unknown_234_;
    int unknown_238_;
    int unknown_23c_;
    int unknown_240_;
    int unknown_244_;
    int unknown_248_;
    int unknown_24c_;
    int unknown_250_;
    int unknown_254_;
    int unknown_258_;
    int unknown_25c_;
    unsigned char unknown_260_[4];
    unsigned char unknown_264_[0x14];
    char pad3[0x278 - 0x278];
    unsigned char unknown1_278_;
    char pad4[3];
    int unknown_27c_;
};

struct Struct_0204a120_2;
extern "C" void func_020a2cf0(Struct_0204a120_2*);
extern "C" void Camera_AddKindFlags(unsigned int*, unsigned int);

// USA: func_ov000_0216d2d0
extern "C" ARM void func_ov000_0216d2d0(struct Struct_ov000_0216d2d0* obj) {
    func_020a2cf0((Struct_0204a120_2*)obj);
    Camera_AddKindFlags((unsigned int*)obj, 8);
    obj->unknown_21c_ = 0;
    obj->unknown_220_ = 0;
    obj->unknown_221_ = 0;
    obj->unknown_224_ = -1;
    obj->unknown_228_ = 0x1000;
    obj->unknown_22c_ = 0x1000;
    obj->unknown_230_ = 0x1000;
    obj->unknown_234_ = 0x1000;
    obj->unknown_238_ = 0;
    obj->unknown_23c_ = 0;
    obj->unknown_240_ = 0;
    obj->unknown_244_ = 0;
    obj->unknown_248_ = 0;
    obj->unknown_24c_ = 0;
    obj->unknown_250_ = 0;
    obj->unknown_254_ = 0;
    obj->unknown_25c_ = 0;
    obj->unknown_258_ = 0;
    memset(obj->unknown_260_, 0, 4);
    memset(obj->unknown_264_, 0, 0x14);
    obj->unknown1_278_ = 0;
    obj->unknown_27c_ = 0;
}
