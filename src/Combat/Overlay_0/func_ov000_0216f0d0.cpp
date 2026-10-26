#include <globaldefs.h>
#include "Graphics/Vector.h"

extern "C" void Camera_SetOrbitVector(void* obj, int* vec);

struct Struct_ov000_0216f0d0 {
    char pad0[0x70];
    Vector3i rotation;
    char pad1[0x264 - 0x7c];
    Vector3i unknown_264_;
    int remaining;
};

// USA: func_ov000_0216f0d0
extern "C" ARM void func_ov000_0216f0d0(Struct_ov000_0216f0d0* obj) {
    if (obj->remaining <= 0) {
        return;
    }
    Vector3i rot = obj->rotation;
    fix32_t dx = fix32SignedAngleDistance(rot.x, obj->unknown_264_.x);
    fix32_t dy = obj->unknown_264_.y - rot.y;
    fix32_t dz = obj->unknown_264_.z - rot.z;
    if (fix32abs(dx) < 0x28 && fix32abs(dy) < 0x28 && fix32abs(dz) < 0x28) {
        rot = obj->unknown_264_;
        obj->remaining = 0;
    } else {
        fix32_t f = 0x1000 - obj->remaining;
        dx = FIX32_MULTIPLY(dx, f);
        rot.x = fix32ReduceAngle0To2Pi(rot.x + dx);
        dy = FIX32_MULTIPLY(dy, f);
        rot.y += dy;
        dz = FIX32_MULTIPLY(dz, f);
        rot.z += dz;
    }
    Camera_SetOrbitVector(obj, (int*)&rot);
}
