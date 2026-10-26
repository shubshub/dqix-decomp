#pragma once

#include "NitroSDK/Matrix.h"

struct Bounds3D {
    Vector3fix maximum;
    Vector3fix minimum;
};


extern "C" int Bounds3D_ContainsPoint(const Vector3fix* point, const Bounds3D* bounds);
extern "C" int Bounds3D_ContainsPointRotated(const Vector3fix* point, const Bounds3D* bounds,
                            int angle, const Vector3fix* pivot, int radiusSquared);
