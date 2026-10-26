#include <globaldefs.h>

struct Struct_020bc180_2 { int f0; int f4; int f8; int fc; };

// USA: func_020c0260
extern "C" ARM void func_020c0260(struct Struct_020bc180_2 *t) {
    if (t->f8 < t->fc) {
        t->f8 = t->f8 + 1;
    }
}
