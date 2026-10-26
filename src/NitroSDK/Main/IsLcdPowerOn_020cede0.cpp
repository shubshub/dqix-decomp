#include <globaldefs.h>

// Main, originally IsPowcntBit0Set_020cede0 (USA 0x020cede0, EUR 0x020cedf0, JPN 0x020d08ac)
extern "C" ARM int IsLcdPowerOn(void) {
    return (*(volatile unsigned short*)0x4000304 & 1) != 0;
}
