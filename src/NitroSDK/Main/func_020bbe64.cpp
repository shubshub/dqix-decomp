#include <globaldefs.h>

extern "C" int func_020d1fd0(int a, int b);

struct Struct_0210f3c0 { unsigned int f0; unsigned int f4; unsigned int f8; };
extern Struct_0210f3c0 data_0210f3c0;

// USA: func_020bbe64
extern "C" ARM void func_020bbe64(int mask) {
    if (mask == 0) return;
    func_020d1fd0(mask, 0);
    data_0210f3c0.f8 &= ~mask;
}
