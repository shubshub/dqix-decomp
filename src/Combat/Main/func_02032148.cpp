#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_02032148 { fix32_t x, y, z, unknown_c_, unknown_10_; };

// USA: func_02032148
extern "C" ARM int func_02032148(const Vector3fix* anchor, const struct Struct_02032148* s, int e) {
    if (s->y > anchor->y) { return 0; }
    if (s->y + s->unknown_10_ < anchor->y) { return 0; }

    fix32_t dx = anchor->x - s->x;
    fix32_t dz = anchor->z - s->z;
    dz = FIX32_MULTIPLY(dz, dz);
    dx = FIX32_MULTIPLY(dx, dx);
    return FIX32_MULTIPLY(s->unknown_c_, s->unknown_c_) >= dx + dz;
}
