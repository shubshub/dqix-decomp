#include <globaldefs.h>

struct Struct_ov031_0220527c;
struct Struct_ov031_02205814_2 {
    char unknown_0_[0x64];
    void* inner;
    char unknown_68_[8];
    short flags;
    signed char kind;
    signed char state;
    unsigned short unknown_74_;
    unsigned short unknown_76_;
    unsigned int unknown_78_;
};
struct Struct_ov031_02205814 {
    char padding[0x10];
    unsigned short unknown_10_;
    unsigned short unknown_12_;
    unsigned int unknown_14_;
};
extern "C" void* func_ov031_02205134(void*, void*, int);
extern "C" int func_ov031_0220527c(Struct_ov031_0220527c*, void*);
extern "C" int func_ov031_0220586c(void*);

// USA: func_ov031_02205814
extern "C" ARM int func_ov031_02205814(Struct_ov031_02205814_2* object) {
    Struct_ov031_02205814* result = (Struct_ov031_02205814*)func_ov031_02205134((void*)func_ov031_0220586c, object, object->kind);
    if (!result) return -33;
    result->unknown_10_ = object->unknown_74_;
    result->unknown_12_ = object->unknown_76_;
    result->unknown_14_ = object->unknown_78_;
    object->flags |= 2;
    return func_ov031_0220527c((Struct_ov031_0220527c*)object, result);
}
