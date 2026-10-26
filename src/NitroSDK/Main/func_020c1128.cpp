#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

extern "C" ARM void func_020c1128(const Struct_0205ac40_3* source, Struct_0205ac40_3* destination,
                               fix32_t scaleX, fix32_t scaleY) {
    destination->values[0] = FIX32_MULTIPLY_SIMPLE(scaleX, source->values[0]);
    destination->values[1] = FIX32_MULTIPLY_SIMPLE(scaleX, source->values[1]);
    destination->values[2] = FIX32_MULTIPLY_SIMPLE(scaleY, source->values[2]);
    destination->values[3] = FIX32_MULTIPLY_SIMPLE(scaleY, source->values[3]);
}
