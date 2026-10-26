#include <globaldefs.h>

extern "C" void* func_020d41d8(void);
extern "C" int func_020d424c(int a, int b);
extern "C" void func_020d404c(int index, int value);
extern "C" int func_020d4168(void* a, unsigned int b);

struct Struct_020d6b34 { short f0, f1, f2, f3, f4; };


// USA: func_020d6b34
extern "C" ARM int func_020d6b34(int a0, short a1, short a2, short a3, unsigned short a4) {
    struct Struct_020d6b34 buf;
    int r;
    func_020d41d8();
    r = func_020d424c(1, 2);
    if (r != 0) {
        return r;
    }
    func_020d404c(0x1e, a0);
    buf.f0 = 0x1e;
    buf.f1 = a1;
    buf.f2 = a2;
    buf.f3 = a3;
    buf.f4 = a4;
    r = func_020d4168(&buf, 10);
    if (r == 0) {
        return 2;
    }
    return r;
}
