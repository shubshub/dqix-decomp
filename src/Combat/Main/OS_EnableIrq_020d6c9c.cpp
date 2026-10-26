#include <globaldefs.h>

// Main, originally EnableIMEReturnPrev_020d6c9c (USA 0x020d6c9c, EUR 0x020d6cac, JPN 0x020d86a4)
extern "C" ARM unsigned short OS_EnableIrq(void) {
    volatile unsigned short* ime = (volatile unsigned short*)0x4000208;
    unsigned short old = *ime;
    *ime = 1;
    return old;
}
