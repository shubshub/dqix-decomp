#include <globaldefs.h>

struct Struct_020a825c {
    unsigned int v[4];
};

struct Struct_020a7f88_2 {
    unsigned char b0;
    unsigned char b1;
    unsigned char b2;
    unsigned char b3;
    unsigned int w4;
    struct Struct_020a825c block;
    unsigned short unknown_18_;
    unsigned short unknown_1a_;
    unsigned short unknown_1c_;
    unsigned short unknown_1e_;
    unsigned int unknown_20_;
    unsigned int unknown_24_;
    unsigned int unknown_28_;
};

struct Struct_020a825c_2 {
    struct Struct_020a7f88_2* base;
    unsigned short cap;
    unsigned short count;
};

// USA: func_020a825c
extern "C" ARM void func_020a825c(struct Struct_020a825c_2* list, struct Struct_020a7f88_2* src) {
    struct Struct_020a7f88_2* dst;
    unsigned short count;
    unsigned short cap;
    if (src == 0) {
        return;
    }
    count = list->count;
    cap = list->cap;
    if (cap <= count) {
        return;
    }
    dst = &list->base[count];
    dst->b0 = src->b0;
    dst->b1 = src->b1;
    dst->b2 = src->b2;
    dst->b3 = src->b3;
    dst->w4 = src->w4;
    dst->block = src->block;
    dst->unknown_18_ = src->unknown_18_;
    dst->unknown_1a_ = src->unknown_1a_;
    dst->unknown_1c_ = src->unknown_1c_;
    dst->unknown_20_ = src->unknown_20_;
    dst->unknown_24_ = src->unknown_24_;
    dst->unknown_28_ = src->unknown_28_;
    list->count++;
}
