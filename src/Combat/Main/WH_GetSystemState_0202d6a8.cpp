#include <globaldefs.h>

// The NitroSDK wh library's state (data_021015a0), as far as this function reads it: the system state
// (3 busy, 7 channel measured, 9 error, 10 fatal; SetField0x48UnlessState9Or10_0202c848 keeps the first error
// once it is 9 or 10).
struct WHState_0202d6a8 {
    char padding0[0x10];
    int sysState;
};
extern WHState_0202d6a8 data_021015a0;

// Main, originally GetGlobalField0x10_0202d6a8 (USA 0x0202d6a8, EUR 0x0202d6b8, JPN 0x0202d218)
ARM int WH_GetSystemState(void) {
    return data_021015a0.sysState;
}
