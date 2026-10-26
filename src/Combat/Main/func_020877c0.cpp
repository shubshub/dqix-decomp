#include <globaldefs.h>

struct Struct_020877c0 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int stage : 3;
};

extern "C" void func_02087838(void* obj);

// USA: func_020877c0
extern "C" ARM int func_020877c0(struct Struct_020877c0* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_02087838(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x6e) = 5;
    *((unsigned char*)p + 0x91) = 0;
    p->flags |= 0x400;
    return p->stage;
}
