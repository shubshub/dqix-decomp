#include <globaldefs.h>
#include "Graphics/Vector.h"

void Camera_SetOrbitVector(void* obj, int* vec);

struct Struct_ov000_0216f0d0 {
    char unknown_0_[0x70];
    Vector3i unknown_70_;
    char unknown_7c_[0x264 - 0x7c];
    Vector3i unknown_264_;
    int unknown_270_;
};

// USA: func_ov000_0216f0d0
extern "C" ARM void func_ov000_0216f0d0(Struct_ov000_0216f0d0* arg0) {
    if (arg0->unknown_270_ <= 0) {
        return;
    }
    Vector3i var0 = arg0->unknown_70_;
    fix32_t var1 = fix32SignedAngleDistance(var0.x, arg0->unknown_264_.x);
    fix32_t var2 = arg0->unknown_264_.y - var0.y;
    fix32_t var3 = arg0->unknown_264_.z - var0.z;
    if (fix32abs(var1) < 0x28 && fix32abs(var2) < 0x28 && fix32abs(var3) < 0x28) {
        var0 = arg0->unknown_264_;
        arg0->unknown_270_ = 0;
    } else {
        fix32_t var4 = 0x1000 - arg0->unknown_270_;
        var1 = FIX32_MULTIPLY(var1, var4);
        var0.x = fix32ReduceAngle0To2Pi(var0.x + var1);
        var2 = FIX32_MULTIPLY(var2, var4);
        var0.y += var2;
        var3 = FIX32_MULTIPLY(var3, var4);
        var0.z += var3;
    }
    Camera_SetOrbitVector(obj, (int*)&rot);
}
