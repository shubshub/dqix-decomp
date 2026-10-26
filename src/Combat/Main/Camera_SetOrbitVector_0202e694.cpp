#include <globaldefs.h>

extern "C" void Camera_SetOrbit(void* camera, int yaw, int height, int distance);

// orbit = { yaw, height, distance }: the camera's orbit ease applies its vector with this.
// Main, originally ApplyVec3Tail_0202e694 (USA 0x0202e694, EUR 0x0202e6a4, JPN 0x0202e204)
extern "C" ARM void Camera_SetOrbitVector(void* camera, int* orbit) {
    Camera_SetOrbit(camera, orbit[0], orbit[1], orbit[2]);
}
