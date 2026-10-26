#include <globaldefs.h>

struct Struct_02055660_2 {
    char pad[0x28];
    int f28;
    int unknown_2c_;
    int unknown_30_;
};

// USA: func_020556cc
extern "C" ARM void func_020556cc(struct Struct_02055660_2* p, int a, int b, int c) {
    p->unknown_30_ = a;
    p->unknown_2c_ = b;
    p->f28 = c;
}
