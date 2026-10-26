#include <globaldefs.h>

struct Struct_ov003_0215e898_2 {
    unsigned char b0;
    signed char b1;
    signed char b2;
    signed char b3;
    int w4;
};

struct Struct_ov003_0215e898 {
    char unk0[8];
    struct Struct_ov003_0215e898_2* arr;
    short capacity;
    short count;
};

// USA: func_ov003_0215e898
extern "C" ARM void func_ov003_0215e898(struct Struct_ov003_0215e898* o, struct Struct_ov003_0215e898_2* e) {
    struct Struct_ov003_0215e898_2* dst;
    if (o->arr == 0) {
        return;
    }
    if (o->capacity <= o->count) {
        return;
    }
    dst = &o->arr[o->count];
    dst->b0 = e->b0;
    dst->b1 = e->b1;
    dst->b2 = e->b2;
    dst->b3 = e->b3;
    dst->w4 = e->w4;
    o->count = o->count + 1;
}
