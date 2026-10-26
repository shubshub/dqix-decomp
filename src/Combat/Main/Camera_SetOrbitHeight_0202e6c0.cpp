#include <globaldefs.h>

extern "C" void Camera_SetOrbit(void* camera, int yaw, int height, int distance);

// The camera's orbit (include/Graphics/Camera.h leaves it as padding70).
struct CamState0202e6c0 {
    char padding0[0x70];
    int orbitYaw;
    int orbitHeight;
    int orbitDistance;
};

// Keeps |height| at least 1.0 (0x1000) below the distance, so the orbit's horizontal leg stays real.
// Main, originally ClampField74BySign (USA 0x0202e6c0, EUR 0x0202e6d0, JPN 0x0202e230)
extern "C" ARM void Camera_SetOrbitHeight(struct CamState0202e6c0* camera, int height) {
    int limit;
    camera->orbitHeight = height;
    if (0.0f < (float)camera->orbitHeight) {
        limit = camera->orbitDistance - 0x1000;
        if (limit < camera->orbitHeight) camera->orbitHeight = limit;
    } else {
        limit = 0x1000 - camera->orbitDistance;
        if (camera->orbitHeight < limit) camera->orbitHeight = limit;
    }
    Camera_SetOrbit(camera, camera->orbitYaw, camera->orbitHeight, camera->orbitDistance);
}
