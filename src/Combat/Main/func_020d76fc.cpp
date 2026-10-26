#include <globaldefs.h>

struct Struct_020d76fc {
    unsigned char pad[0xa24];
    unsigned short src;
    unsigned short dst;
};

// USA: func_020d76fc
extern "C" ARM void func_020d76fc(struct Struct_020d76fc* s) {
    s->dst |= (unsigned short)(s->src & 0xf);
}
