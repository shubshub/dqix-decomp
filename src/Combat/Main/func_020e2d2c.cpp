#include <globaldefs.h>

struct Struct_020439b0_3 {
    unsigned char pad[0x14];
    int f14;
    int f18;
    int f1c;
    int f20;
};

// USA: func_020e2d2c
extern "C" ARM void func_020e2d2c(struct Struct_020439b0_3* s, int a, int b, int c, int d) {
    s->f14 = a;
    s->f18 = b;
    s->f1c = a + c;
    s->f20 = b + d;
}
