#include <globaldefs.h>


// Main, originally func_0206df6c (USA 0x0206df6c, EUR 0x0206df7c, JPN 0x0206f0c0)
extern "C" ARM void Scenario_SetFlag(void* unused, unsigned char* array, int bit, int value) {
    int i = bit / 8;
    unsigned char mask = 1 << (bit % 8);
    unsigned int v = array[i];
    if (value != 0) {
        v |= mask;
    } else {
        v &= ~mask;
    }
    array[i] = v;
}
