#include <globaldefs.h>

struct Struct_0207f158 {
    int unknown_0_;
    short f04;
    short unknown_6_;
    short f08;
    short unknown_a_;
    short f0c;
    short unknown_e_;
    unsigned short f10;
    unsigned char f12;
    unsigned char unknown_13_;
    unsigned char f14;
    int f18;
    int f1c;
    int f20;
    int f24;
    short f28;
    unsigned char unknown_2a_;
    unsigned char unknown_2b_;
    unsigned char unknown_2c_;
    unsigned char unknown_2d_;
};

struct Struct_0207f158_2 {
    struct Struct_0207f158* entries;
    short count;
    short max;
};

// USA: func_0207f5d0
extern "C" ARM void func_0207f5d0(struct Struct_0207f158_2* list, struct Struct_0207f158* src) {
    struct Struct_0207f158* base;
    struct Struct_0207f158* dst;
    short count;
    base = list->entries;
    if (base == NULL) {
        return;
    }
    count = list->count;
    if (list->max <= count) {
        return;
    }
    dst = &base[count];
    dst->unknown_0_ = src->unknown_0_;
    dst->f04 = src->f04;
    dst->unknown_6_ = src->unknown_6_;
    dst->f08 = src->f08;
    dst->unknown_a_ = src->unknown_a_;
    dst->f0c = src->f0c;
    dst->unknown_e_ = src->unknown_e_;
    dst->f10 = src->f10;
    dst->f12 = src->f12;
    dst->unknown_13_ = src->unknown_13_;
    dst->f14 = src->f14;
    dst->f18 = src->f18;
    dst->f1c = src->f1c;
    dst->f20 = src->f20;
    dst->f24 = src->f24;
    dst->f28 = src->f28;
    dst->unknown_2a_ = src->unknown_2a_;
    dst->unknown_2b_ = src->unknown_2b_;
    dst->unknown_2c_ = src->unknown_2c_;
    dst->unknown_2d_ = src->unknown_2d_;
    list->count++;
}
