#include <globaldefs.h>

// The camera's orbit (include/Graphics/Camera.h leaves it as padding70).
struct Obj0202e71c {
    unsigned char padding0[0x70];
    int orbitYaw;
    int orbitHeight;
    int orbitDistance;
};

extern "C" void Camera_SetOrbit(struct Obj0202e71c* camera, int yaw, int height, int distance);

// Keeps the distance at least 1.0 (0x1000) beyond |height|, and at least 1.0.
// Main, originally SetField78Clamped0202e71c (USA 0x0202e71c, EUR 0x0202e72c, JPN 0x0202e28c)
ARM void Camera_SetOrbitDistance(struct Obj0202e71c* camera, int distance) {
    camera->orbitDistance = distance;
    int height = camera->orbitHeight;
    if (0.0f < (float)height) {
        int limit = height + 0x1000;
        if (camera->orbitDistance < limit) camera->orbitDistance = limit;
    } else {
        int limit = 0x1000 - height;
        if (camera->orbitDistance < limit) camera->orbitDistance = limit;
    }
    if (camera->orbitDistance < 0x1000)
        camera->orbitDistance = 0x1000;
    Camera_SetOrbit(camera, camera->orbitYaw, camera->orbitHeight, camera->orbitDistance);
}
