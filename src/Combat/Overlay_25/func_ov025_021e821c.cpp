#include <globaldefs.h>

extern "C" void* func_ov000_02160130();
extern "C" void func_ov000_02163440(void*, short, unsigned short, unsigned short);

struct Struct_ov025_021e821c {
    char pad[8];
    short a;
    unsigned short b;
    unsigned short c;

    short inline_ov025_021e821c() const { return a; }
    unsigned short inline_ov025_021e821c_2() const { return b; }
    unsigned short inline_ov025_021e821c_3() const { return c; }
};

// USA: func_ov025_021e821c
extern "C" ARM int func_ov025_021e821c(Struct_ov025_021e821c* arg) {
    short a = arg->inline_ov025_021e821c();
    unsigned short b = arg->inline_ov025_021e821c_2();
    unsigned short c = arg->inline_ov025_021e821c_3();
    func_ov000_02163440(func_ov000_02160130(), a, b, c);
    return 1;
}
