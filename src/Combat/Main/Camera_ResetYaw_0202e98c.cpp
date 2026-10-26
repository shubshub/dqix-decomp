#include <globaldefs.h>

// The camera's yaw (Camera::yaw) and its animation: Camera_UpdateAnimations adds yawStep to yaw while yawFrames counts down.
struct HalfwordTriple0202e98c {
    char padding0[0x212];
    unsigned short yaw;
    unsigned short yawStep;
    unsigned short yawFrames;
};

// Main, originally ClearThreeHalfwords (USA 0x0202e98c, EUR 0x0202e99c, JPN 0x0202e4fc)
ARM void Camera_ResetYaw(struct HalfwordTriple0202e98c* camera) {
    camera->yaw = 0;
    camera->yawStep = 0;
    camera->yawFrames = 0;
}
