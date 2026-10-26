#include <globaldefs.h>

struct Struct_02072560_2 {
    unsigned short v[18];
};

struct Struct_02072398 {
    short f0;
    short f2;
    struct Struct_02072560_2 unknown_4_;
    unsigned short f28;
    unsigned char unknown_2a_;
    unsigned char unknown_2b_;
};

struct Struct_02072560 {
    struct Struct_02072398* entries;
    short capacity;
    short count;
};

// USA: func_02072560
extern "C" ARM void func_02072560(struct Struct_02072560* list, struct Struct_02072398* src) {
    struct Struct_02072398* dst;
    if (list->capacity <= list->count) {
        return;
    }
    dst = &list->entries[list->count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->unknown_4_ = src->unknown_4_;
    dst->f28 = src->f28;
    dst->unknown_2a_ = src->unknown_2a_;
    dst->unknown_2b_ = src->unknown_2b_;
    list->count++;
}
