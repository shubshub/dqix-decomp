#include <globaldefs.h>

struct Struct_02087a9c {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 9;
    int stage : 3;
};

extern "C" void func_02087b14(void* obj);

// USA: func_02087a9c
extern "C" ARM int func_02087a9c(struct Struct_02087a9c* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_02087b14(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x71) = 6;
    *((unsigned char*)p + 0x94) = 0;
    p->flags |= 0x2000;
    return p->stage;
}
