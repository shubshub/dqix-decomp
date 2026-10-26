#include <globaldefs.h>

// USA: func_020e2bc4
extern "C" ARM int func_020e2bc4(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    return (*dispcnt & 0xe000) >> 13;
}
