#include <globaldefs.h>

// USA: func_0204a698
extern "C" ARM int func_0204a698(int priority) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x400000c;
    int value = (*var0 & ~3) | priority;
    *var0 = value;
    return value;
}
