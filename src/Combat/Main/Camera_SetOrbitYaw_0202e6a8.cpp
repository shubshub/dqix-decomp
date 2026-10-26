#include <globaldefs.h>

// The camera's orbit (include/Graphics/Camera.h leaves it as padding70).
struct GlobalObj0202e6a8 {
    char padding0[0x70];
    int orbitYaw;
    int orbitHeight;
    int orbitDistance;
};

extern "C" void Camera_SetOrbit(struct GlobalObj0202e6a8* camera, int yaw, int height, int distance);

// Main, originally ApplyField0x70Tail (USA 0x0202e6a8, EUR 0x0202e6b8, JPN 0x0202e218)
extern "C" ARM void Camera_SetOrbitYaw(struct GlobalObj0202e6a8* camera, int yaw) {
    camera->orbitYaw = yaw;
    Camera_SetOrbit(camera, yaw, camera->orbitHeight, camera->orbitDistance);
}
