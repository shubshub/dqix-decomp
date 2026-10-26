#include <globaldefs.h>

extern int data_021015a0[];

// Main, originally GetGlobalField0x48_0202d6b8 (USA 0x0202d6b8, EUR 0x0202d6c8, JPN 0x0202d228)
extern "C" ARM int WH_GetLastError(void) {
    return data_021015a0[0x12];
}
