#include <globaldefs.h>

struct Struct_020e29a8 {
    char pad[0x16];
    unsigned char v;
};

// USA: func_020e29a8
extern "C" ARM void func_020e29a8(struct Struct_020e29a8* p, int v) {
    if (v >= 3) {
        v = 2;
    }
    p->v = (unsigned char)v;
}
