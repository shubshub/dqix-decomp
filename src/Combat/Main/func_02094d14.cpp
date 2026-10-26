#include <globaldefs.h>

struct Struct_02094d14 { unsigned int v[3]; };
struct Struct_0201afd0_7 {
    unsigned short a;
    unsigned short b;
    unsigned short c;
    unsigned short d;
    struct Struct_02094d14 unknown_8_;
};
struct Struct_0201afd0_6 { struct Struct_0201afd0_7* base; };

// USA: func_02094d14
extern "C" ARM void func_02094d14(struct Struct_0201afd0_6* c, struct Struct_0201afd0_7* src, int idx) {
    struct Struct_0201afd0_7* dst = &c->base[idx];
    dst->a = src->a;
    dst->b = src->b;
    dst->c = src->c;
    dst->d = src->d;
    dst->unknown_8_ = src->unknown_8_;
}
