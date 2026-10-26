#include <globaldefs.h>

struct Struct_02087f78 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 27;
    int stage : 3;
};

extern "C" void func_02087ff0(void* obj);

// USA: func_02087f78
extern "C" ARM int func_02087f78(struct Struct_02087f78* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_02087ff0(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x77) = 5;
    *((unsigned char*)p + 0x9a) = 0;
    p->flags |= 0x2000000;
    return p->stage;
}
