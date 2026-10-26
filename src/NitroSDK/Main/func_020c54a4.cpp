#include <globaldefs.h>

// USA: func_020c54a4
extern "C" ARM void func_020c54a4(int enable, unsigned int arg1, unsigned int arg2, unsigned short arg3) {
    if (enable) {
        *(volatile unsigned short*)0x400035c = arg3;
        *(volatile unsigned short*)0x4000060 =
            (arg2 << 8) | (arg1 << 6) | 0x80 | (*(volatile unsigned short*)0x4000060 & ~0x3f40);
    } else {
        *(volatile unsigned short*)0x4000060 &= 0xcf7f;
    }
}
