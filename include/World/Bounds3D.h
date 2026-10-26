#pragma once

#include "NitroSDK/Matrix.h"

struct Struct_02018fbc {
    Vector3fix unknown_0_;
    Vector3fix unknown_c_;
};


extern "C" int Bounds3D_ContainsPoint(const Vector3fix* point, const Bounds3D* bounds);
extern "C" int Bounds3D_ContainsPointRotated(const Vector3fix* point, const Bounds3D* bounds,
                            int angle, const Vector3fix* pivot, int radiusSquared);
