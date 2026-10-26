#include <globaldefs.h>

extern "C" int func_020d1fb0(int a, int b);

struct Struct_0210f3c0 { unsigned int f0; unsigned int f4; unsigned int f8; };
extern Struct_0210f3c0 data_0210f3c0;

// USA: func_020bbe1c
extern "C" ARM int func_020bbe1c(int mask) {
    if (mask == 0) return 1;
    if (mask & data_0210f3c0.f8) return 0;
    func_020d1fb0(mask, 0);
    data_0210f3c0.f8 |= mask;
    return 1;
}
