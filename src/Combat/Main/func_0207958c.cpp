#include <globaldefs.h>

struct Struct_0207958c {
    unsigned char pad[0x17d];
    unsigned char flags;
};

// USA: func_0207958c
extern "C" ARM void func_0207958c(struct Struct_0207958c* s) {
    s->flags &= ~0x38;
}
