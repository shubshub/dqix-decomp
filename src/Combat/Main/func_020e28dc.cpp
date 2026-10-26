#include <globaldefs.h>

struct Struct_020e28dc_2 {
    char pad[0x3f];
    unsigned char flag : 1;
};

struct Struct_020e28dc {
    char pad[0xc];
    struct Struct_020e28dc_2* inner;
};

// USA: func_020e28dc
extern "C" ARM int func_020e28dc(struct Struct_020e28dc* o) {
    return o->inner->flag;
}
