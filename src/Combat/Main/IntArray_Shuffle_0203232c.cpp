#include <globaldefs.h>
#include "std_library_functions.h"

extern "C" int _s32_div_f(int num, int den);

// Main, originally func_0203232c (USA 0x0203232c, EUR 0x0203233c, JPN 0x02031e64)
extern "C" ARM void IntArray_Shuffle(int *values, int count) {
    for (int i = 0; i < count / 2; i++) {
        int other = rand() % count;
        int held = values[i];
        values[i] = values[other];
        values[other] = held;
    }
}
