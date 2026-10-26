#include <globaldefs.h>
#include "Graphics/Vector.h"

// Main, originally StoreThreeWordsAt0x0020130a8 (USA 0x020130a8, EUR 0x020130b8, JPN 0x02012e70)
ARM void Vector3i_Set(Vector3i* vector, int x, int y, int z) {
    vector->x = x;
    vector->y = y;
    vector->z = z;
}
