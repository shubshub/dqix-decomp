#include <globaldefs.h>

extern "C" void G3X_ResetMtxStack(void);

// Main, originally ResetGxEngineState020c52e8 (USA 0x020c52e8, EUR 0x020c52f8, JPN 0x020c6db4)
extern "C" ARM void G3X_Reset(void) {
    while (*(volatile unsigned int*)0x4000600 & 0x8000000);
    *(volatile unsigned int*)0x4000600 |= 0x8000;
    *(volatile unsigned short*)0x4000060 |= 0x2000;
    *(volatile unsigned short*)0x4000060 |= 0x1000;
    G3X_ResetMtxStack();
    *(volatile unsigned int*)0x40004a4 = 0x1f0080;
    *(volatile unsigned int*)0x40004a8 = 0;
    *(volatile unsigned int*)0x40004ac = 0;
}
