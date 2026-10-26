#include <globaldefs.h>

// Main, originally SetVBlankIrqEnable_020c3864 (USA 0x020c3864, EUR 0x020c3874, JPN 0x020c5330)
ARM int SetVBlankIrqEnable(int enable) {
    volatile unsigned short* dispstat = (volatile unsigned short*)0x4000004;
    int prev = *dispstat & 8;
    if (enable != 0) {
        *dispstat |= 8;
    } else {
        *dispstat &= ~8;
    }
    return prev;
}
