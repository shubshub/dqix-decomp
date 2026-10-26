#include <globaldefs.h>

// Main, originally ClearFirstThreeWords_02099898 (USA 0x02099898, EUR 0x020998a8, JPN 0x0209b5cc)
extern "C" ARM void ZoneTable_Clear(unsigned int* p) {
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
}
