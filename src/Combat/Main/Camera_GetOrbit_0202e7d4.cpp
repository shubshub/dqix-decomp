#include <globaldefs.h>

// The camera's orbit: +0x70 yaw, +0x74 height, +0x78 distance.
// Main, originally ReadFields0x70To0x78_0202e7d4 (USA 0x0202e7d4, EUR 0x0202e7e4, JPN 0x0202e344)
ARM void Camera_GetOrbit(unsigned char* camera, int* outYaw, int* outHeight, int* outDistance) {
    *outYaw = *(int*)(camera + 0x70);
    *outHeight = *(int*)(camera + 0x74);
    *outDistance = *(int*)(camera + 0x78);
}
