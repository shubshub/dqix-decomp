#include <globaldefs.h>

// USA: func_ov011_021863ec
extern "C" ARM int func_ov011_021863ec(int priority) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x400000c;
    int value = (*var0 & ~3) | priority;
    *var0 = value;
    return value;
}
