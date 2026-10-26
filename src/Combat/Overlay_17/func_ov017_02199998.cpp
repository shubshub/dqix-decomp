#include <globaldefs.h>

// USA: func_ov017_02199998
extern "C" ARM int func_ov017_02199998(int priority) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x400000a;
    int value = (*var0 & ~3) | priority;
    *var0 = value;
    return value;
}
