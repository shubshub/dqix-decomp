#include <globaldefs.h>

// USA: func_020dc020
extern "C" ARM int func_020dc020(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    return (*dispcnt & 0x1f00) >> 8;
}
