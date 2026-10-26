#include <globaldefs.h>
#include "Graphics/SpriteAffineTransform.h"

extern const fix16_t data_020e9450[4096 * 2];

static inline fix32_t inline_0205b0d8(int sample) {
    return data_020e9450[sample * 2];
}

static inline fix32_t inline_0205b0d8_2(int sample) {
    return data_020e9450[sample * 2 + 1];
}

extern "C" ARM void func_0205b0d8(SpriteContext0205ac40* context, Struct_0205ac40_3* transform,
                                  Struct_0205ac40_3* arg2, B174Outer* sprite) {
    Struct_0205ac40_3 rotation;
    if (sprite != NULL && transform != NULL && arg2 != NULL) {
        func_020c111c(&rotation, inline_0205b0d8(sprite->angle >> 4), inline_0205b0d8_2(sprite->angle >> 4));
        func_020c1128(&rotation, transform, sprite->scaleX, sprite->scaleY);
        func_020c1128(&rotation, arg2,
                              fix32_Divide(0x1000, sprite->scaleX),
                              fix32_Divide(0x1000, sprite->scaleY));
    }
}
