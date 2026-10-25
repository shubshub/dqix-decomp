#include <globaldefs.h>
#include "Graphics/Camera.h"

int Vec3Ease_IsRunning(int*);

// Main, originally AnySubObjectField0NonZero_0202eeb4 (USA 0x0202eeb4, EUR 0x0202eec4, JPN 0x0202ea24)
ARM int Camera_IsEasing(Camera* camera) {
    int result = 1;
    int inner = 1;
    if (Vec3Ease_IsRunning((int*)camera->positionEase) == 0) {
        if (Vec3Ease_IsRunning((int*)camera->targetEase) == 0) inner = 0;
    }
    if (inner == 0) {
        if (Vec3Ease_IsRunning((int*)camera->unknownEase) == 0) result = 0;
    }
    return result;
}
