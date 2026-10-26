#include <globaldefs.h>

// Local copies of NitroSDK/Matrix.h's Vector3i and Matrix4x3 (the header's Vector3i declares operator=).
struct Vector3Local {
    int x;
    int y;
    int z;
};
struct Matrix4x3Local { unsigned int entries[12]; };

int fix32ReduceAngle0To2Pi(int);
extern "C" int fix32_Sqrt(int value);
extern "C" void Vector3fix_Add(struct Vector3Local* a, struct Vector3Local* b, struct Vector3Local* out);
struct Matrix4x3Local RotationMatrixY(int angle);
extern "C" void Mat4x3_ApplyToVector(struct Vector3Local* v, struct Matrix4x3Local* m, struct Vector3Local* out);

static inline int FixedMulRound(int a, int b) {
    return (int)(((long long)a * b + 0x800) >> 12);
}

// The camera (include/Graphics/Camera.h) as far as its orbit, which the header still leaves as padding70:
// the position circles the target at orbitYaw, orbitHeight above it and orbitDistance away.
struct CameraOrbitView {
    unsigned int field0;
    struct Vector3Local position;
    struct Vector3Local target;
    unsigned char padding1c[0x54];
    int orbitYaw;
    int orbitHeight;
    int orbitDistance;
};

// Main, originally func_0202e5d8 (USA 0x0202e5d8, EUR 0x0202e5e8, JPN 0x0202e148)
extern "C" ARM void Camera_SetOrbit(struct CameraOrbitView* camera, int yaw, int height, int distance) {
    int reducedYaw;
    int heightSquared, distanceSquared, horizontalSquared;
    struct Vector3Local offset;
    struct Matrix4x3Local rotation;

    reducedYaw = fix32ReduceAngle0To2Pi(yaw);
    camera->orbitYaw = reducedYaw;
    camera->orbitHeight = height;
    camera->orbitDistance = distance;

    heightSquared = FixedMulRound(height, height);
    distanceSquared = FixedMulRound(distance, distance);
    horizontalSquared = distanceSquared - heightSquared;

    offset.x = 0;
    offset.y = height;
    offset.z = fix32_Sqrt(horizontalSquared);

    rotation = RotationMatrixY(reducedYaw);

    Mat4x3_ApplyToVector(&offset, &rotation, &offset);

    Vector3fix_Add(&camera->target, &offset, &camera->position);
}
