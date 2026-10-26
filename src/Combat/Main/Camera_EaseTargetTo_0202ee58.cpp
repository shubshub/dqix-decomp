#include <globaldefs.h>
#include "Graphics/Camera.h"

struct Vec3PairRecord020a0db8;
extern "C" int Vec3Ease_StartProportional(struct Vec3PairRecord020a0db8*, int*, int*, int);

// Main, originally CallFunc020a0db8AtField0x194AndClearFlag2_0202ee58 (USA 0x0202ee58, EUR 0x0202ee68, JPN 0x0202e9c8)
extern "C" ARM void Camera_EaseTargetTo(Camera* camera, int target, int steps) {
    Vec3Ease_StartProportional((struct Vec3PairRecord020a0db8*)camera->targetEase, (int*)&camera->target, (int*)target, steps);
    camera->flags &= ~0x2;
}
