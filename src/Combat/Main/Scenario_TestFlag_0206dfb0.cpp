#include <globaldefs.h>

// Main, originally TestBitInByteArray_0206dfb0 (USA 0x0206dfb0, EUR 0x0206dfc0, JPN 0x0206f104)
extern "C" ARM int Scenario_TestFlag(int unused, unsigned char* arr, int index) {
    unsigned char mask;
    if (index < 0) {
        return 0;
    }
    mask = 1 << (index % 8);
    return mask & arr[index / 8];
}
