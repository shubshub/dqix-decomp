#include <globaldefs.h>

struct Struct_02087d78 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 18;
    int stage : 3;
};

extern "C" void func_02087df0(void* obj);

// USA: func_02087d78
extern "C" ARM int func_02087d78(struct Struct_02087d78* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_02087df0(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x74) = 5;
    *((unsigned char*)p + 0x97) = 0;
    p->flags |= 0x10000;
    return p->stage;
}
