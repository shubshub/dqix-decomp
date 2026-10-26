#include <globaldefs.h>

struct Struct_ov003_0215e510 {
    short f0;
    short f2;
    int f4;
    int f8;
    unsigned char fc;
    unsigned char unknown_d_;
    unsigned char fe;
    unsigned char ff;
    short f10;
    unsigned char f12;
    unsigned char unknown_13_;
};

struct Struct_ov003_0215e790 {
    struct Struct_ov003_0215e510* array;
    short capacity;
    short count;
};

// USA: func_ov003_0215e790
extern "C" ARM void func_ov003_0215e790(struct Struct_ov003_0215e790* self, struct Struct_ov003_0215e510* src) {
    if (self->array == NULL) {
        return;
    }
    if (self->capacity <= self->count) {
        return;
    }
    struct Struct_ov003_0215e510* dst = &self->array[self->count];
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    dst->fc = src->fc;
    dst->unknown_d_ = src->unknown_d_;
    dst->fe = src->fe;
    dst->ff = src->ff;
    dst->f10 = src->f10;
    dst->f12 = src->f12;
    dst->unknown_13_ = src->unknown_13_;
    self->count++;
}
