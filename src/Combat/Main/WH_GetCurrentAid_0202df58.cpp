#include <globaldefs.h>

// The NitroSDK wh library's state (data_021015a0), as far as this function reads it: this console's wireless
// aid, which func_0202c958 sets to 0 when it starts as the parent.
struct WHState_0202df58 {
    unsigned short myAid;
};
extern WHState_0202df58 data_021015a0;

// Main, originally GetGlobalHalf0x0_0202df58 (USA 0x0202df58, EUR 0x0202df68, JPN 0x0202dac8)
ARM unsigned short WH_GetCurrentAid(void) {
    return data_021015a0.myAid;
}
