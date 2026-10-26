#include <globaldefs.h>

struct Struct_02070ee0 {
    unsigned short v[6];
};

struct Struct_02070ee0_2 {
    unsigned int v[22];
};

struct Struct_02070b6c_5 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short f04;
    unsigned short unknown_6_;
    unsigned int f08;
    unsigned short f0c;
    unsigned int f10;
    unsigned int f14;
    struct Struct_02070ee0 f18;
    unsigned int f24;
    unsigned char f28;
    unsigned char unknown_29_;
    unsigned short unknown_2a_;
    struct Struct_02070ee0_2 unknown_2c_;
};

// USA: func_02070ee0
extern "C" ARM struct Struct_02070b6c_5 *func_02070ee0(struct Struct_02070b6c_5 *dst, struct Struct_02070b6c_5 *src) {
    dst->unknown_0_ = src->unknown_0_;
    dst->unknown_2_ = src->unknown_2_;
    dst->unknown_3_ = src->unknown_3_;
    dst->f04 = src->f04;
    dst->unknown_6_ = src->unknown_6_;
    dst->f08 = src->f08;
    dst->f0c = src->f0c;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f24 = src->f24;
    dst->f28 = src->f28;
    dst->unknown_29_ = src->unknown_29_;
    dst->unknown_2a_ = src->unknown_2a_;
    dst->unknown_2c_ = src->unknown_2c_;
    return dst;
}
