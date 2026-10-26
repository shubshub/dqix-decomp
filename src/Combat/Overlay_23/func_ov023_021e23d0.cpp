#include <globaldefs.h>

extern "C" void* func_ov023_021e2418(void* obj, int val);

struct Struct_ov023_021e23d0 {
    char pad0[3];
    unsigned char unknown_3_0_ : 4;
    unsigned char unknown_3_4_ : 4;
    char pad1[0xc - 4];
    int unknown_c_;
};

// USA: func_ov023_021e23d0
extern "C" ARM void func_ov023_021e23d0(void* obj, int val, int f0xc, unsigned char arg3, unsigned char arg4) {
    struct Struct_ov023_021e23d0* e = (struct Struct_ov023_021e23d0*)func_ov023_021e2418(obj, val);
    if (e == NULL) return;
    e->unknown_c_ = f0xc;
    e->unknown_3_0_ = arg3;
    e->unknown_3_4_ = arg4;
}
