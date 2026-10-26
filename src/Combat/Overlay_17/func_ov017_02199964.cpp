#include <globaldefs.h>

// USA: func_ov017_02199964
extern "C" ARM void func_ov017_02199964(int size, int colorMode, int arg2, int arg3, int wrap) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x400000a;
    unsigned short v = (*var0 & 0x43) | (size << 14) | (colorMode << 7) | (arg2 << 8) | (arg3 << 2) | (wrap << 13);
    *var0 = v;
}
