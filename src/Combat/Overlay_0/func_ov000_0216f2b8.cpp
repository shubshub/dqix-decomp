#include <globaldefs.h>
#include "NitroSDK/Matrix.h"
#include "Graphics/Vector.h"

struct Struct_ov000_0216f2b8 {
    unsigned char unknown_0_[4];
    Vector3fix unknown_4_;
    unsigned char unknown_10_[0x220 - 0x10];
    unsigned char unknown_220_;
    unsigned char unknown_221_[0x258 - 0x221];
    fix32_t unknown_258_;
    unsigned char unknown_25c_[4];
    unsigned char unknown_260_;
};

extern "C" fix32_t func_ov000_0216f210(struct Camera0216f2b8* self, fix32_t* outLength);
extern "C" void Camera_SetOrbitFromPosition(struct Camera0216f2b8* self);

// USA: func_ov000_0216f2b8
extern "C" ARM void func_ov000_0216f2b8(struct Struct_ov000_0216f2b8* arg0) {
    if (arg0->unknown_220_ == 3) {
        return;
    }
    Vector3fix var0 = arg0->unknown_4_;
    fix32_t var1;
    bool var2 = false;
    fix32_t var3 = func_ov000_0216f210(arg0, &var1);
    if (var1 > 0x11000) {
        Vector3fix var4 = var0;
        var4.y = 0;
        Vector3fix_Normalize(&var4, &var4);
        Vector3fixMultiplyScalar(&var4, 0x11000, &var4);
        var0.x = var4.x;
        var0.z = var4.z;
        var2 = true;
    }
    var3 = FIX32_MULTIPLY(var3 - arg0->unknown_258_, 0x333);
    arg0->unknown_258_ += var3;
    if (arg0->unknown_260_) {
        if (var0.y < arg0->unknown_258_) {
            var0.y = arg0->unknown_258_;
            var2 = true;
        }
    }
    if (var0.y > 0x5000) {
        var0.y = 0x5000;
        var2 = true;
    }
    if (changed) {
        self->pos = pos;
        Camera_SetOrbitFromPosition(self);
    }
}
