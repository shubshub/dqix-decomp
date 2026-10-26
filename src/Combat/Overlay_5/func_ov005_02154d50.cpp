#include <globaldefs.h>

struct Struct_ov005_02154d50 {
    char pad0[8];
    int unknown_8_;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
    char pad4[8];
    int f20;
    int f24;
};

// USA: func_ov005_02154d50
extern "C" ARM void func_ov005_02154d50(Struct_ov005_02154d50* obj, int a, int b) {
    obj->f20 = obj->unknown_c_ + (a - obj->unknown_8_);
    obj->f24 = obj->unknown_14_ + (b - obj->unknown_10_);
}
