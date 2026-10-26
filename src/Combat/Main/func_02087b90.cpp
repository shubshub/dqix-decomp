#include <globaldefs.h>

struct Struct_02087b90 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 12;
    int stage : 3;
};

extern "C" void func_02087c08(void* obj);

// USA: func_02087b90
extern "C" ARM int func_02087b90(struct Struct_02087b90* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_02087c08(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x72) = 5;
    *((unsigned char*)p + 0x95) = 0;
    p->flags |= 0x4000;
    return p->stage;
}
