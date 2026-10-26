#include <globaldefs.h>

// USA: func_ov001_02162678
extern "C" ARM void func_ov001_02162678(int a, int b, int c, int d) {
    unsigned short *reg = (unsigned short*)0x400000e;
    *reg = (unsigned short)((*reg & 0x43) | (a << 14) | (b << 7) | (c << 8) | (d << 2));
}
