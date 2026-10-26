#include <globaldefs.h>


// USA: func_020c5650
extern "C" ARM int func_020c5650(int* out) {
    volatile unsigned int* var0 = (volatile unsigned int*)0x4000600;
    if (*var0 & 0x4000) return -1;
    *out = (*var0 & 0x1f00) >> 8;
    return 0;
}
