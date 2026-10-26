#include <globaldefs.h>

// Main, originally SetSubBgMode_020c3984 (USA 0x020c3984, EUR 0x020c3994, JPN 0x020c5450)
extern "C" ARM void GXS_SetGraphicsMode(unsigned int mode) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4001000;
    *dispcnt = (*dispcnt & ~7) | mode;
}
