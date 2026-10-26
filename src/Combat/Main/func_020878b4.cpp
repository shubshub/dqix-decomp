#include <globaldefs.h>

struct Struct_020878b4 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 3;
    int stage : 3;
};

extern "C" void func_0208792c(void* obj);

// USA: func_020878b4
extern "C" ARM int func_020878b4(struct Struct_020878b4* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_0208792c(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x6f) = 6;
    *((unsigned char*)p + 0x92) = 0;
    p->flags |= 0x800;
    return p->stage;
}
