#include <globaldefs.h>
#include "World/Object3D.h"

struct Struct_0204a3f0_3;

struct Struct_0204a3f0_4 {
    unsigned int unknown_0_;
    char pad4[0xa4];
    signed int bit0 : 1;
};

struct Struct_0204a3f0 {
    char pad0[0x8];
    struct Struct_0204a3f0_4* node;
};

struct Struct_0204a3f0_2 {
    char pad0[0x21c];
    struct Struct_0204a3f0* holder;
};

// USA: func_0204a3f0
extern "C" ARM void func_0204a3f0(struct Struct_0204a3f0_2* owner, struct Struct_0204a3f0* h) {
    struct Struct_0204a3f0_4* s;
    owner->holder = h;
    ((Object3D*)((struct Struct_0204a3f0_3*)h))->EnableBoneTracking();
    s = owner->holder->node;
    if (s == NULL) return;
    if (!s->bit0) s = NULL;
    if (s != NULL) {
        s->unknown_0_ |= 4;
    }
}
