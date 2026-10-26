#include <globaldefs.h>

struct Struct_02061c04_24 {
    unsigned short f0;
    unsigned char f2;
    unsigned char f3;
};

// USA: func_020643e0
extern "C" ARM void func_020643e0(struct Struct_02061c04_24* dst, struct Struct_02061c04_24* src) {
    dst->f0 = src->f0;
    dst->f2 = src->f2;
    dst->f3 = src->f3;
}
