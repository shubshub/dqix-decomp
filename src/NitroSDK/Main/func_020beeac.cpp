#include <globaldefs.h>

struct Struct_020beeac { int f0; };
struct Struct_020beeac_2 {
    char pad0[0x110];
    unsigned int f110;
    char pad1[0x38];
    struct Struct_020beeac *unknown_14c_;
};

// USA: func_020beeac
extern "C" ARM void func_020beeac(struct Struct_020beeac_2 *p) {
    struct Struct_020beeac *inner = p->unknown_14c_;
    if (inner != NULL) {
        inner->f0 = 0;
        p->unknown_14c_ = NULL;
    }
    p->f110 &= ~0x1;
    p->f110 &= ~0x4;
    p->f110 &= ~0x2;
}
