#include <globaldefs.h>

// USA: func_020daf54
extern "C" ARM int func_020daf54(void) {
    volatile unsigned int* reg = (volatile unsigned int*)0x4001000;
    return (*reg & 0x1f00) >> 8;
}
