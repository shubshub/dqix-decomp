#include <globaldefs.h>

#include "NitroSDK/Matrix.h"

// USA: func_020c2d90
extern "C" ARM void Vector3fix_Add(const Vector3fix* a, const Vector3fix* b, Vector3fix* out) {
    out->x = a->x + b->x;
    out->y = a->y + b->y;
    out->z = a->z + b->z;
}
