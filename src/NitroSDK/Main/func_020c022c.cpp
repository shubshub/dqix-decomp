#include <globaldefs.h>

struct Struct_020bc180_2 { int f0; int f4; int f8; int fc; };

// USA: func_020c022c
extern "C" ARM int func_020c022c(struct Struct_020bc180_2* t) {
    if (t->f8 >= t->fc) {
        return t->f4;
    }
    return t->f0 + t->f8 * (t->f4 - t->f0) / t->fc;
}
