#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void*, int);

struct Struct_ov023_021e24b0 {
    char pad0[3];
    unsigned char unknown_3_0_ : 4;
    unsigned char unknown_3_4_ : 4;
    char pad1[8];
    int unknown_c_;
    unsigned char unknown_10_0_ : 4;
    unsigned char unknown_10_4_ : 1;
    unsigned char unknown_10_5_ : 1;
    unsigned char unknown_10_6_ : 1;
    unsigned char unknown_10_7_ : 1;
};

// USA: func_ov023_021e24b0
extern "C" ARM void func_ov023_021e24b0(void* obj, int val, int f0xc, unsigned char arg3, unsigned char p5, unsigned char p6, unsigned char p7, unsigned char p8, unsigned char p9) {
    Struct_ov023_021e24b0* e = (Struct_ov023_021e24b0*)func_ov023_021e2418(obj, val);
    if (!e) return;
    e->unknown_c_ = f0xc;
    e->unknown_3_0_ = arg3;
    e->unknown_3_4_ = p5;
    e->unknown_10_4_ = p6;
    e->unknown_10_0_ = p7;
    e->unknown_10_5_ = p8;
    e->unknown_10_6_ = p9;
}
