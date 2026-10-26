#include <globaldefs.h>
#include "NitroSDK/Matrix.h"

// Sets the camera's position (+4, Camera::position) from a vector.
// Main, originally CopyVec3ToField0x4_0202ef04 (USA 0x0202ef04, EUR 0x0202ef14, JPN 0x0202ea74)
ARM void Camera_SetPositionVector(int* camera, int* position) {
    *(Vector3i*)(camera + 1) = *(const Vector3i*)position;
}
