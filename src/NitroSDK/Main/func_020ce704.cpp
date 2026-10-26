#include <globaldefs.h>

extern "C" void func_020cef94(int a);
extern "C" int func_020ce4e8(int a, int b, int c, int d, int e);
extern "C" void func_020ce1d8(void);
extern void (*data_020f2298)(void);

// USA: func_020ce704
extern "C" ARM int func_020ce704(int a, int b) {
    void (*old)(void) = data_020f2298;
    data_020f2298 = func_020ce1d8;
    func_020cef94(a);
    data_020f2298 = old;
    return func_020ce4e8(0xe, 0, 0, a, b);
}
