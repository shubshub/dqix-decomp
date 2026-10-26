#include <globaldefs.h>

// USA: func_02008da4
extern "C" ARM double func_02008da4(double x, double y) {
    unsigned int var0 = ((unsigned int*)&x)[1];
    unsigned int var1 = ((unsigned int*)&y)[1];
    ((unsigned int*)&x)[1] = (var0 & 0x7fffffffu) | (var1 & 0x80000000u);
    return x;
}
