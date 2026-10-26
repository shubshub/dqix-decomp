#include <globaldefs.h>

struct Struct_ov005_02154d34 {
    char pad0[8];
    int unknown_8_;
    char pad2[4];
    int unknown_10_;
    char pad3[0x14];
    int f28;
    int unknown_2c_;
};

// USA: func_ov005_02154d34
extern "C" ARM void func_ov005_02154d34(Struct_ov005_02154d34* obj, int a, int b) {
    obj->f28 = a + obj->unknown_8_;
    obj->unknown_2c_ = b + obj->unknown_10_;
}
