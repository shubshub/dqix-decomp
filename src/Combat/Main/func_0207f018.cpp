#include <globaldefs.h>

struct Struct_0207ed48 {
    unsigned int unknown_0_;
    unsigned int w4;
    short h8;
    short ha;
    short hc;
    short he;
    short unknown_10_;
    unsigned char unknown_12_;
    unsigned char unknown_13_;
    unsigned char b14;
    unsigned char unknown_15_;
};

struct Struct_0207f018 {
    struct Struct_0207ed48* base;
    short count;
    short capacity;
};

// USA: func_0207f018
extern "C" ARM void func_0207f018(struct Struct_0207f018* arr, struct Struct_0207ed48* src) {
    short count;
    struct Struct_0207ed48* dst;
    if (src == NULL) {
        return;
    }
    count = arr->count;
    if (arr->capacity <= count) {
        return;
    }
    dst = &arr->base[count];
    dst->unknown_0_ = src->unknown_0_;
    dst->w4 = src->w4;
    dst->h8 = src->h8;
    dst->ha = src->ha;
    dst->hc = src->hc;
    dst->he = src->he;
    dst->unknown_10_ = src->unknown_10_;
    dst->unknown_12_ = src->unknown_12_;
    dst->unknown_13_ = src->unknown_13_;
    dst->b14 = src->b14;
    dst->unknown_15_ = src->unknown_15_;
    arr->count = arr->count + 1;
}
