#include <globaldefs.h>

// Main, originally GetSharedWordDc4_020c8520 (USA 0x020c8520, EUR 0x020c8530, JPN 0x020c9fec)
extern "C" ARM int GetArenaHigh(int index) {
    return ((volatile int*)0x27ffdc4)[index];
}
