#include <globaldefs.h>

struct Struct_020bec80 { char pad[0x14c]; int unknown_14c_; };
struct Struct_020bec80_2 { struct Struct_020bec80 *f0; };

// USA: func_020bec80
extern "C" ARM void func_020bec80(struct Struct_020bec80_2 *p) {
    struct Struct_020bec80 *inner = p->f0;
    if (inner != NULL) {
        inner->unknown_14c_ = 0;
        p->f0 = NULL;
    }
}
