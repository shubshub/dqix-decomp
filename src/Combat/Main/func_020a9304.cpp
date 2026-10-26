#include <globaldefs.h>

struct Struct_020a9304 { unsigned char v[24]; };
struct Struct_020a9304_2 { unsigned short v[6]; };

struct Struct_020a8fd0_3 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    unsigned short e;
    unsigned short f;
    unsigned int g;
    struct Struct_020a9304 arr1;
    unsigned int h;
    unsigned int i;
    unsigned char j;
    unsigned char k;
    struct Struct_020a9304_2 arr2;
};

// USA: func_020a9304
extern "C" ARM struct Struct_020a8fd0_3* func_020a9304(struct Struct_020a8fd0_3* dst, struct Struct_020a8fd0_3* src) {
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->e = src->e;
    dst->f = src->f;
    dst->g = src->g;
    dst->arr1 = src->arr1;
    dst->h = src->h;
    dst->i = src->i;
    dst->j = src->j;
    dst->k = src->k;
    dst->arr2 = src->arr2;
    return dst;
}
