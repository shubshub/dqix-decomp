#include <globaldefs.h>

struct Struct_0205c77c {
    unsigned char pad[0x13];
    unsigned char unknown_13_;
    unsigned char f14;
    unsigned char f15;
    unsigned char unknown_16_;
};

// USA: func_0205c77c
extern "C" ARM void func_0205c77c(struct Struct_0205c77c* p, int val) {
    p->unknown_13_ = 0;
    p->f15 = 0;
    p->unknown_16_ = val;
}
