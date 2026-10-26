#include <globaldefs.h>

// USA: func_020daf20
extern "C" ARM void func_020daf20(int val) {
    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
    *reg = (*reg & ~0x1f00) | (val << 8);
}
