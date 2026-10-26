#include <globaldefs.h>

struct Vec3 {
    int x;
    int y;
    int z;
};

// The camera (include/Graphics/Camera.h) as far as its orbit, which the header still leaves as padding70:
// the position circles the target at orbitYaw, orbitHeight above it and orbitDistance away.
struct CameraOrbitView {
    char field0[4];
    struct Vec3 position;
    struct Vec3 target;
    char padding1c[0x70 - 0x1c];
    int orbitYaw;
    int orbitHeight;
    int orbitDistance;
};

struct FloatVector3 {
    float x;
    float y;
    float z;
};

extern "C" float _fflt(int fix32);
extern "C" float _fdiv(float a, float b);
extern "C" float _fsub(float a, float b);
extern "C" float _fadd(float a, float b);
extern "C" float _fmul(float a, float b);
extern "C" int _ffix(float value);
extern "C" float _d2f(double value);
extern "C" double atan2(double a, double b); // atan2
extern "C" float sqrtf(float value);         // sqrtf
extern "C" void Camera_SetOrbit(struct CameraOrbitView* camera, int yaw, int height, int distance);

// Recomputes the orbit from the position and target (in float), then re-places the position from it.
// Main, originally func_0202eab8 (USA 0x0202eab8, EUR 0x0202eac8, JPN 0x0202e628)
extern "C" ARM void Camera_SetOrbitFromPosition(struct CameraOrbitView* camera) {
    struct FloatVector3 offset;
    offset.x = _fsub(_fdiv(_fflt(camera->position.x), 4096.0f), _fdiv(_fflt(camera->target.x), 4096.0f));
    offset.y = _fsub(_fdiv(_fflt(camera->position.y), 4096.0f), _fdiv(_fflt(camera->target.y), 4096.0f));
    offset.z = _fsub(_fdiv(_fflt(camera->position.z), 4096.0f), _fdiv(_fflt(camera->target.z), 4096.0f));

    float offsetZ = offset.z;
    float yaw = _d2f(atan2((double)(offset.x), (double)(offsetZ)));
    if (yaw < 0.0f) {
        yaw = _fadd(yaw, 6.2831855f);
    }
    camera->orbitYaw = _ffix(_fmul(4096.0f, yaw));
    camera->orbitHeight = _ffix(_fmul(4096.0f, offset.y));

    float distance = sqrtf(_fadd(_fmul(offset.z, offset.z),
                                         _fadd(_fmul(offset.x, offset.x), _fmul(offset.y, offset.y))));
    camera->orbitDistance = _ffix(_fmul(4096.0f, distance));

    Camera_SetOrbit(camera, camera->orbitYaw, camera->orbitHeight, camera->orbitDistance);
}
