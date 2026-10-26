#include <globaldefs.h>

// Main, originally SetVBlankIrqEnable_020c3864 (USA 0x020c3864, EUR 0x020c3874, JPN 0x020c5330)
extern "C" ARM int SetVBlankIrqEnable(int enable) {
    volatile unsigned short* var0 = (volatile unsigned short*)0x4000004;
    int prev = *var0 & 8;
    if (enable != 0) {
        *var0 |= 8;
    } else {
        *var0 &= ~8;
    }
    return prev;
}
