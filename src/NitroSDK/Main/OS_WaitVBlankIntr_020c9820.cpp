#include "NitroSDK/Interrupts.h"
#include <globaldefs.h>

extern "C" void WaitByLoop(int);

// Main, originally DelayThenSyncBit0_020c9820 (USA 0x020c9820, EUR 0x020c9830, JPN 0x020cb2ec)
extern "C" ARM void OS_WaitVBlankIntr(void) {
    WaitByLoop(1);
    WaitForInterrupt(1, 1);
}
