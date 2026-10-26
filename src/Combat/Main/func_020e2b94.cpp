#include <globaldefs.h>

// USA: func_020e2b94
extern "C" ARM void func_020e2b94(int val) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    *dispcnt = (*dispcnt & ~0xe000) | (val << 13);
}
