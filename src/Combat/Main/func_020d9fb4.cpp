#include <globaldefs.h>

struct Struct_02061c04_16 { unsigned int unknown_0_; unsigned int w4; unsigned short flags; };

// USA: func_020d9fb4
extern "C" ARM void func_020d9fb4(struct Struct_02061c04_16* s, int bit) {
    s->flags |= 1 << bit;
}
