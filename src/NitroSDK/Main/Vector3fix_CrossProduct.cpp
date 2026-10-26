#include <globaldefs.h>

#include "NitroSDK/Matrix.h"

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c2e34
extern "C" ARM void Vector3fix_CrossProduct(const Vector3fix* a, const Vector3fix* b, Vector3fix* out) {
    fix32_t x, y, z;

    x = (fix32_t)(((long long)a->y * b->z - (long long)a->z * b->y + 0x800) >> 12);
    y = (fix32_t)(((long long)a->z * b->x - (long long)a->x * b->z + 0x800) >> 12);
    z = (fix32_t)(((long long)a->x * b->y - (long long)a->y * b->x + 0x800) >> 12);

    out->x = x;
    out->y = y;
    out->z = z;
}
