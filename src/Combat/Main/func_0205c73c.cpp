#include <globaldefs.h>

struct Struct_0205c73c {
    unsigned int f0;
    unsigned int f4;
    unsigned int f8;
    unsigned int fc;
    unsigned short f10;
    unsigned char f12;
    unsigned char unknown_13_;
    unsigned char f14;
    unsigned char f15;
    unsigned char unknown_16_;
};

// USA: func_0205c73c
extern "C" ARM void func_0205c73c(struct Struct_0205c73c* p) {
    p->f4 = 0;
    p->f0 = 0;
    p->fc = 0x8000;
    p->f8 = 0x8000;
    p->f10 = 0x7fff;
    p->f12 = 30;
    p->unknown_13_ = 0;
    p->f14 = 30;
    p->f15 = 0;
    p->unknown_16_ = 1;
}
