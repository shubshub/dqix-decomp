#include <globaldefs.h>


// USA: func_020c56b0
extern "C" ARM int func_020c56b0(int* out) {
    volatile unsigned int* var0 = (volatile unsigned int*)0x4000600;
    if (*var0 & 0x1) return -1;
    *out = *var0 & 0x2;
    return 0;
}
