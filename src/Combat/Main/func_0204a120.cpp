#include <globaldefs.h>

struct Struct_0204a120_2;
extern "C" void func_020a2cf0(struct Struct_0204a120_2*);
extern "C" ARM void Camera_AddKindFlags(unsigned int* obj, unsigned int mask);

struct Struct_0204a120 {
    char pad0[0x21c];
    int unknown_21c_;
    int unknown_220_;
    unsigned char unknown_224_;
    char pad1[0xf];
    unsigned char unknown_234_;
    char pad2[0xf];
    unsigned char unknown_244_;
    char pad3[0xf];
    int unknown_254_;
    int unknown_258_;
    int unknown_25c_;
    int unknown_260_;
    unsigned char unknown_264_;
    unsigned char unknown_265_;
};

// USA: func_0204a120
extern "C" ARM void func_0204a120(struct Struct_0204a120* obj) {
    func_020a2cf0((struct Struct_0204a120_2*)obj);
    Camera_AddKindFlags((unsigned int*)obj, 0x10);
    obj->unknown_21c_ = 0;
    obj->unknown_220_ = 0;
    obj->unknown_224_ = 0;
    obj->unknown_234_ = 0;
    obj->unknown_244_ = 0;
    obj->unknown_254_ = -1;
    obj->unknown_258_ = -1;
    obj->unknown_25c_ = -1;
    obj->unknown_260_ = -1;
    obj->unknown_264_ = 0;
    obj->unknown_265_ = 0;
}
