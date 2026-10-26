#include <globaldefs.h>

// Main, originally GetSharedWordDa0_020c8534 (USA 0x020c8534, EUR 0x020c8544, JPN 0x020ca000)
extern "C" ARM int GetArenaLow(int index) {
    return ((volatile int*)0x27ffda0)[index];
}
