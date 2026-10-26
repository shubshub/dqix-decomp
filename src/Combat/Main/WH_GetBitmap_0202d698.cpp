#include <globaldefs.h>

// The NitroSDK wh library's state (data_021015a0), as far as this function reads it. func_0202c958 (starting
// a parent) sets connectBitmap to 1 (aid 0 only); func_0202c9ac ORs in 1 << aid when a child connects and
// clears it when one disconnects.
struct WHState_0202d698 {
    unsigned short myAid;
    char padding2[8];
    unsigned short connectBitmap;
};
extern WHState_0202d698 data_021015a0;

// Main, originally GetField0xa_0202d698 (USA 0x0202d698, EUR 0x0202d6a8, JPN 0x0202d208)
extern "C" ARM unsigned short WH_GetBitmap(void) {
    return data_021015a0.connectBitmap;
}
