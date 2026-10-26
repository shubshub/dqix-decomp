#include <globaldefs.h>

struct Struct_02089b90_2 {
    unsigned short v[10];
};

struct Struct_02089b90_3 {
    unsigned char v[13];
};

struct Struct_02089b90_4 {
    signed char b0;
    int w4;
    unsigned char b8;
    short ha;
    int unknown_c_;
    unsigned char b10;
    unsigned char unknown_11_;
    unsigned char unknown_12_;
    int unknown_14_;
    int unknown_18_;
    struct Struct_02089b90_2 unknown_1c_;
    struct Struct_02089b90_3 unknown_30_;
    unsigned char unknown_3d_;
    unsigned char unknown_3e_;
    unsigned char unknown_3f_;
};

struct Struct_02089b90_5 {
    struct Struct_02089b90_4* base;
    short count;
    short capacity;
};

// USA: func_02089edc
extern "C" ARM void func_02089edc(struct Struct_02089b90_5* arr, struct Struct_02089b90_4* src) {
    struct Struct_02089b90_4* dst;
    short count;
    if (arr->base == 0) {
        return;
    }
    count = arr->count;
    if (arr->capacity <= count) {
        return;
    }
    dst = &arr->base[count];
    dst->b0 = src->b0;
    dst->w4 = src->w4;
    dst->b8 = src->b8;
    dst->ha = src->ha;
    dst->unknown_c_ = src->unknown_c_;
    dst->b10 = src->b10;
    dst->unknown_11_ = src->unknown_11_;
    dst->unknown_12_ = src->unknown_12_;
    dst->unknown_14_ = src->unknown_14_;
    dst->unknown_18_ = src->unknown_18_;
    dst->unknown_1c_ = src->unknown_1c_;
    dst->unknown_30_ = src->unknown_30_;
    dst->unknown_3d_ = src->unknown_3d_;
    dst->unknown_3e_ = src->unknown_3e_;
    dst->unknown_3f_ = src->unknown_3f_;
    arr->count = arr->count + 1;
}
