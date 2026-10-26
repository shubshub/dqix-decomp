#include <globaldefs.h>
#include "Graphics/Camera.h"

int Vec3Ease_IsRunning(int*);

// Main, originally AnySubObjectField0NonZero_0202eeb4 (USA 0x0202eeb4, EUR 0x0202eec4, JPN 0x0202ea24)
ARM int Camera_IsEasing(Camera* camera) {
    int easing = 1;
    int positionOrTargetEasing = 1;
    if (Vec3Ease_IsRunning((int*)camera->positionEase) == 0) {
        if (Vec3Ease_IsRunning((int*)camera->targetEase) == 0) positionOrTargetEasing = 0;
    }
    if (positionOrTargetEasing == 0) {
        if (Vec3Ease_IsRunning((int*)camera->unknownEase) == 0) easing = 0;
    }
    return easing;
}
