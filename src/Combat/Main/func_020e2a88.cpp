#include <globaldefs.h>

// USA: func_020e2a88
extern "C" ARM void func_020e2a88(int val, int arg1) {
    volatile unsigned short* reg = (volatile unsigned short*)0x4001048;
    int r = (*reg & ~0x3f00) | (val << 8);
    if (arg1) r |= 0x2000;
    *reg = r;
}
