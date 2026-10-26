#include <globaldefs.h>

struct Struct_02071874 {
    short f0;
    short f2;
    short f4;
    short unknown_6_;
    short f8;
    unsigned short fa;
    int fc;
    int f10;
    short f14;
    short unknown_16_;
    short f18;
    short unknown_1a_;
    int f1c;
};

struct Struct_02071cc8 {
    char pad0[4];
    struct Struct_02071874* entries;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_02071cc8
extern "C" ARM void func_02071cc8(struct Struct_02071cc8* list, struct Struct_02071874* src) {
    struct Struct_02071874* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->unknown_6_ = src->unknown_6_;
    dst->f8 = src->f8;
    dst->fa = src->fa;
    dst->fc = src->fc;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->unknown_16_ = src->unknown_16_;
    dst->f18 = src->f18;
    dst->unknown_1a_ = src->unknown_1a_;
    dst->f1c = src->f1c;
    list->count++;
}
