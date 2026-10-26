#include <globaldefs.h>
#include "Graphics/Camera.h"

struct Vec3PairRecord020a0db8;
int Vec3Ease_StartProportional(struct Vec3PairRecord020a0db8*, int*, int*, int);

// Main, originally CallFunc020a0db8AtField0x16c_0202ee38 (USA 0x0202ee38, EUR 0x0202ee48, JPN 0x0202e9a8)
ARM int Camera_EasePositionTo(Camera* camera, int target, int steps) {
    return Vec3Ease_StartProportional((struct Vec3PairRecord020a0db8*)camera->positionEase, (int*)&camera->position, (int*)target, steps);
}
