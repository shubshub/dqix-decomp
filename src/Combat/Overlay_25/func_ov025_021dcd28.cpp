#include <globaldefs.h>

struct Struct_ov025_021d8c30_11 {
    unsigned int unknown_0_;
    unsigned int w1;
    unsigned int w2;
    unsigned int unknown_c_;
    unsigned int w4;
    unsigned char b;
};

// USA: func_ov025_021dcd28
extern "C" ARM void func_ov025_021dcd28(struct Struct_ov025_021d8c30_11* dst, struct Struct_ov025_021d8c30_11* src) {
    dst->unknown_0_ = src->unknown_0_;
    dst->w1 = src->w1;
    dst->w2 = src->w2;
    dst->unknown_c_ = src->unknown_c_;
    dst->w4 = src->w4;
    dst->b = src->b;
}
