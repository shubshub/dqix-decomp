#include <globaldefs.h>

struct Struct_02087c84 {
    char unknown_0_[0x14];
    unsigned int flags;
    char pad18[0x40];
    int : 15;
    int stage : 3;
};

extern "C" void func_02087cfc(void* obj);

// USA: func_02087c84
extern "C" ARM int func_02087c84(struct Struct_02087c84* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_02087cfc(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x73) = 5;
    *((unsigned char*)p + 0x96) = 0;
    p->flags |= 0x8000;
    return p->stage;
}
