#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

// Sets the camera's target (+0x10, Camera::target) from a vector.
// Main, originally CopyVec3ToField0x10_0202e938 (USA 0x0202e938, EUR 0x0202e948, JPN 0x0202e4a8)
ARM void Camera_SetTargetVector(void* camera, int* target) {
    *(Vector3i*)((char*)camera + 0x10) = *(const Vector3i*)target;
}
