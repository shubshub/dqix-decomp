#include <globaldefs.h>

extern "C" void* func_ov000_02161318(int, int);
extern "C" int func_ov000_02170c7c(void*);

// USA: func_ov000_02174e34
extern "C" ARM int func_ov000_02174e34(int a, int b) {
    void* p = func_ov000_02161318(a, b);
    if (!p) return -1;
    return func_ov000_02170c7c(p);
}
