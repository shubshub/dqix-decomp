#include <globaldefs.h>

struct Struct_020795e8_2 {
    unsigned short pad0;
    unsigned char b2;
    signed char b3;
    unsigned int f0 : 3;
    unsigned int f1 : 3;
    unsigned int f2 : 3;
    unsigned int f3 : 3;
    unsigned int f4 : 3;
};

struct Struct_020795e8 {
    unsigned char pad[0x138];
    unsigned char f0;
    unsigned char f1;
    unsigned char f2;
    unsigned char f3;
    unsigned char f4;
    unsigned char pad2[3];
    int unknown_140_;
    int unknown_144_;
};

// USA: func_020795e8
extern "C" ARM void func_020795e8(struct Struct_020795e8* dst, struct Struct_020795e8_2* src) {
    dst->f0 = src->f0;
    dst->f1 = src->f1;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
    dst->f4 = src->f4;
    dst->unknown_140_ = src->b2;
    dst->unknown_144_ = src->b3;
}
