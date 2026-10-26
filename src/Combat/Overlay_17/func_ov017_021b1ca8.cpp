#include <globaldefs.h>

// USA: func_ov017_021b1ca8
extern "C" ARM int func_ov017_021b1ca8(int enable) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x4000304;
    int value = (*var0 & ~0x8000) | (enable << 15);
    *var0 = value;
    return value;
}
