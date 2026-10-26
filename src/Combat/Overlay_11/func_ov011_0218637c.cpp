#include <globaldefs.h>

// USA: func_ov011_0218637c
extern "C" ARM int func_ov011_0218637c(int priority) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x400100c;
    int value = (*var0 & ~3) | priority;
    *var0 = value;
    return value;
}
