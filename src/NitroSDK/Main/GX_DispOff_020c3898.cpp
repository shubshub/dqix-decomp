#include <globaldefs.h>

extern unsigned short data_020f226c;
extern unsigned short data_02111220;

// Main, originally SaveAndClearDisplayMode_020c3898 (USA 0x020c3898, EUR 0x020c38a8, JPN 0x020c5364)
extern "C" ARM void GX_DispOff(void) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    unsigned int v = *dispcnt;
    data_020f226c = 0;
    data_02111220 = (unsigned short)((v & 0x30000) >> 16);
    *dispcnt = v & ~0x30000;
}
