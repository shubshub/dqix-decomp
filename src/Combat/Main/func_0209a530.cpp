#include <globaldefs.h>

struct Struct_0209a104_2 {
    unsigned short f0;
    unsigned short f2;
    int f4;
    unsigned short f8;
    unsigned short fa;
};

// USA: func_0209a530
extern "C" ARM void func_0209a530(struct Struct_0209a104_2* dst, struct Struct_0209a104_2* src) {
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    dst->fa = src->fa;
}
