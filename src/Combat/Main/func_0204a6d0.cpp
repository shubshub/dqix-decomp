#include <globaldefs.h>

// USA: func_0204a6d0
extern "C" ARM int func_0204a6d0(int priority) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x4000008;
    int value = (*var0 & ~3) | priority;
    *var0 = value;
    return value;
}
