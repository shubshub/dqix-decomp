#include <globaldefs.h>
#include "Graphics/Camera.h"

// Main, originally SetVec3At0x4 (USA 0x0202e5c0, EUR 0x0202e5d0, JPN 0x0202e130)
ARM void Camera_SetPosition(Camera* camera, int x, int y, int z) {
    camera->position.x = x;
    camera->position.y = y;
    camera->position.z = z;
}
