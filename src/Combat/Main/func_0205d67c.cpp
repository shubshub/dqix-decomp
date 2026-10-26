#include <globaldefs.h>

struct Struct_0205d67c {
    char pad0[0x98];
    int field98;
    int unknown_9c_;
    char pad1[0x14];
    unsigned char fieldB4;
};

// USA: func_0205d67c
extern "C" ARM int func_0205d67c(struct Struct_0205d67c* p) {
    if (p->field98 == 0) return 0;
    return p->unknown_9c_ != 0 ? p->fieldB4 : 0;
}
