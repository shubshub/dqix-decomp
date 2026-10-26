#include <globaldefs.h>

struct Struct_02028524_5 {
    short x;
    short y;
    short z;
};

// USA: func_0202861c
extern "C" ARM void func_0202861c(struct Struct_02028524_5* dst, struct Struct_02028524_5* src) {
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}
