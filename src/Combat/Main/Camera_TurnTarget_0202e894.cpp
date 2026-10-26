#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

struct Struct_0202e5d8 { unsigned int v[12]; };
struct Struct_0202e5d8 RotationMatrixY(int angle);

extern "C" void Camera_SetOrbitFromPosition(void* obj);

struct Struct_0202e894 {
    unsigned int v[3];
};

static inline void inline_0202e894(struct Struct_0202e894* arg0, struct Struct_0202e894* arg1, int angle) {
    struct Struct_0202e894 diff;
    Vector3fix_Subtract((Vector3fix*)arg0, (Vector3fix*)arg1, (Vector3fix*)&diff);

    struct Struct_0202e5d8 mtxCopy = RotationMatrixY(angle);

    Mat4x3_ApplyToVector((Vector3fix*)&diff, (Matrix4x3*)&mtxCopy, (Vector3fix*)&diff);

    Vector3fix_Add((Vector3fix*)arg1, (Vector3fix*)&diff, (Vector3fix*)arg0);
}

// Main, originally RotateOffsetAndAdvance0202e894 (USA 0x0202e894, EUR 0x0202e8a4, JPN 0x0202e404)
extern "C" ARM void Camera_TurnTarget(void* obj, int angle) {
    struct Struct_0202e894 var0;
    struct Struct_0202e894 var1;
    var0 = *(struct Struct_0202e894*)((char*)obj + 0x4);
    var1 = *(struct Struct_0202e894*)((char*)obj + 0x10);

    inline_0202e894(&var1, &var0, angle);

    *(Vector3i*)((char*)obj + 0x10) = *(Vector3i*)&var1;

    Camera_SetOrbitFromPosition(obj);
}
