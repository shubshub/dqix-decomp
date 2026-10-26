#include <globaldefs.h>

struct Struct_020a1180_2 {
    unsigned int unknown_0_;
    unsigned int w1;
    unsigned int w2;
};

struct Struct_020a1568 {
    struct Struct_020a1180_2* base;
    unsigned short capacity;
    unsigned short count;
};

// USA: func_020a1568
extern "C" ARM void func_020a1568(struct Struct_020a1568* arr, struct Struct_020a1180_2* src) {
    unsigned short count;
    struct Struct_020a1180_2* dst;
    if (src == NULL) {
        return;
    }
    count = arr->count;
    if (arr->capacity <= count) {
        return;
    }
    dst = &arr->base[count];
    dst->unknown_0_ = src->unknown_0_;
    dst->w1 = src->w1;
    dst->w2 = src->w2;
    arr->count++;
}
