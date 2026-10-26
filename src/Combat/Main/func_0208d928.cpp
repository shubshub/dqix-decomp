#include <globaldefs.h>

struct Struct_0208d594 {
    short h0;
    int w4;
    int w8;
    int unknown_c_;
    int unknown_10_;
    int unknown_14_;
};

struct Struct_0208d594_2 {
    struct Struct_0208d594* base;
    short count;
    short cap;
};

// USA: func_0208d928
extern "C" ARM void func_0208d928(struct Struct_0208d594_2 *l, struct Struct_0208d594 *e) {
    struct Struct_0208d594 *base = l->base;
    struct Struct_0208d594 *dst;
    if (base == NULL) return;
    if (l->cap <= l->count) return;
    dst = &base[l->count];
    dst->h0 = e->h0;
    dst->w4 = e->w4;
    dst->w8 = e->w8;
    dst->unknown_c_ = e->unknown_c_;
    dst->unknown_10_ = e->unknown_10_;
    dst->unknown_14_ = e->unknown_14_;
    l->count++;
}
