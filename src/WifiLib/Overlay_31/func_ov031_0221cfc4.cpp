#include <globaldefs.h>

// USA: func_ov031_0221cfc4
extern "C" THUMB unsigned int func_ov031_0221cfc4(unsigned int a, unsigned int b) {
    unsigned int var0 = a & b;
    unsigned int var1 = ~b;
    unsigned int t = (a & var1) + 1;
    t = t | var0;
    unsigned int u = var1 | var0;
    if (t < u)
        return t;
    return 1 | var0;
}
