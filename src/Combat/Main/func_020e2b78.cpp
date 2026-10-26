#include <globaldefs.h>

// USA: func_020e2b78
extern "C" ARM void func_020e2b78(int val) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~0xe000) | (val << 13);
}
