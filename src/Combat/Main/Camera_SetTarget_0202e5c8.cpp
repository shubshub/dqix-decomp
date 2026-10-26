#include <globaldefs.h>
#include "Graphics/Camera.h"

// Main, originally SetFields0x10To0x18_0202e5c8 (USA 0x0202e5c8, EUR 0x0202e5d8, JPN 0x0202e138)
extern "C" ARM void Camera_SetTarget(Camera* camera, int x, int y, int z) {
    camera->target.x = x;
    camera->target.y = y;
    camera->target.z = z;
}
