#include <globaldefs.h>

struct Struct_020879a8 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 6;
    int stage : 3;
};

extern "C" void func_02087a20(void* obj);

// USA: func_020879a8
extern "C" ARM int func_020879a8(struct Struct_020879a8* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_02087a20(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x70) = 6;
    *((unsigned char*)p + 0x93) = 0;
    p->flags |= 0x1000;
    return p->stage;
}
