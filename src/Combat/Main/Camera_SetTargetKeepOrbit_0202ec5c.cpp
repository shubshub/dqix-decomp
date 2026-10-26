#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

extern "C" void Camera_SetOrbit(void* camera, int yaw, int height, int distance);

// Moves the camera's target (+0x10) and re-places the position around it with the same orbit
// (+0x70 yaw, +0x74 height, +0x78 distance).
// Main, originally CopyVec3ToField0x10AndCall0202e5d8_0202ec5c (USA 0x0202ec5c, EUR 0x0202ec6c, JPN 0x0202e7cc)
extern "C" ARM void Camera_SetTargetKeepOrbit(char* camera, int* target) {
    *(Vector3i*)(camera + 0x10) = *(Vector3i*)target;
    Camera_SetOrbit(camera, *(int*)(camera + 0x70), *(int*)(camera + 0x74), *(int*)(camera + 0x78));
}
