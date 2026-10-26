#include <globaldefs.h>

struct Struct_02087c30 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int unknown_58_0_ : 3;
    int unknown_58_3_ : 3;
    int unknown_58_6_ : 3;
    int unknown_59_1_ : 3;
    int unknown_59_4_ : 3;
    int unknown_59_7_ : 3;
};

// USA: func_02087c30
extern "C" ARM int func_02087c30(Struct_02087c30* p, unsigned char arg1) {
    if (p->flags & 1) return 0;
    if (arg1 == 0) {
        if (p->unknown_59_7_ < 2) return 1;
    } else {
        if (p->unknown_59_7_ > -2) return 1;
    }
    return 0;
}
