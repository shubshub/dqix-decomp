#include <globaldefs.h>

extern "C" int func_020ce648(int a, int b, void (*c)(void), int *d);
extern "C" void func_020ce234(void);
extern void (*data_020f2298)(void);

// USA: func_020ce6d0
extern "C" ARM int func_020ce6d0(int a, int b) {
    int out;
    int r = func_020ce648(a, b, func_020ce234, &out);
    if (r != 0) return r;
    data_020f2298();
    return out;
}
