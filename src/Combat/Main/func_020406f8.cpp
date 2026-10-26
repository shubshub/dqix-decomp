#include <globaldefs.h>

struct Struct_0203de84 {
    unsigned int v[3];
};

struct Struct_020406f8 {
    char pad4[4];
    struct Struct_0203de84 vec;
};

struct Struct_020406f8_2 {
    char unknown_0_[0x44];
    struct Struct_0203de84 vec;
};

struct Node020406f8 {
    char pad[0x14];
    struct Struct_020406f8* f14;
    struct Struct_020406f8_2* f18;
    struct Struct_020406f8_2* f1c;
};

// USA: func_020406f8
extern "C" ARM void func_020406f8(struct Struct_0203de84* dst, struct Node020406f8* n) {
    if (n->f14 != NULL) {
        *dst = n->f14->vec;
        return;
    }
    if (n->f18 != NULL) {
        *dst = n->f18->vec;
        return;
    }
    if (n->f1c != NULL) {
        *dst = n->f1c->vec;
        return;
    }
    {
        struct Struct_0203de84 zero;
        zero.v[0] = 0;
        zero.v[1] = 0;
        zero.v[2] = 0;
        *dst = zero;
    }
}
