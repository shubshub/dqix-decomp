#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

// Main, originally func_020311e8 (USA 0x020311e8, EUR 0x020311f8, JPN 0x02030d20)
extern "C" ARM void Vector3fix_Set(Vector3fix* vector, int x, int y, int z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
