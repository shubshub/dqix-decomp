#include <globaldefs.h>

// USA: func_020e2b00
extern "C" ARM void func_020e2b00(unsigned int arg0, int arg1) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x4000048;
    unsigned int v = (*var0 & ~0x3f) | arg0;
    if (arg1) v |= 0x20;
    *var0 = v;
}
