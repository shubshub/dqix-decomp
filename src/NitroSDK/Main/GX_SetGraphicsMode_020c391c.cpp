#include <globaldefs.h>

extern unsigned short data_020f226c;
extern unsigned short data_02111220;

// Main, originally SetDispcntModeAndFlags020c391c (USA 0x020c391c, EUR 0x020c392c, JPN 0x020c53e8)
ARM void GX_SetGraphicsMode(int mode, int flagsA, int valB) {
    volatile unsigned int* dispcnt = (volatile unsigned int*)0x4000000;
    unsigned int guard = data_020f226c;
    unsigned int dc = *dispcnt;
    data_02111220 = (unsigned short)mode;
    unsigned int modeBits = (guard == 0) ? 0 : mode;
    unsigned int combined = flagsA | ((dc & 0xfff0fff0) | (modeBits << 16));
    combined = combined | (valB << 3);
    *dispcnt = combined;
    if (data_02111220 == 0) {
        data_020f226c = 0;
    }
}
