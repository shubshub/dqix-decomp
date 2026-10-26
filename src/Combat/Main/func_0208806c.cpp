#include <globaldefs.h>

struct Struct_0208806c {
    char pad18[0x18];
    unsigned int unknown_18_;
    char pad2[0x3c];
    int : 24;
    int stage : 3;
};

extern "C" void func_020880e4(void* obj);

// USA: func_0208806c
extern "C" ARM int func_0208806c(struct Struct_0208806c* p, int delta) {
    int var0 = p->stage + delta;
    if (var0 > 2) var0 = 2;
    if (var0 < -2) var0 = -2;
    if (var0 == 0) {
        func_020880e4(p);
        return 0;
    }
    p->stage = var0;
    *((unsigned char*)p + 0x76) = 5;
    *((unsigned char*)p + 0x99) = 0;
    p->unknown_18_ |= 0x1;
    return p->stage;
}
