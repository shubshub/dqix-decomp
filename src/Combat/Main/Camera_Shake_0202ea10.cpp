#include <globaldefs.h>

// Starts a camera shake: Camera::shakeAmplitude (+0x1e4) and shakeRemaining (+0x1e8), which Camera_Update
// decays by 33 a frame. A duration of 0 does nothing.
// Main, originally StoreFields0x1e4And0x1e8IfNonZero_0202ea10 (USA 0x0202ea10, EUR 0x0202ea20, JPN 0x0202e580)
ARM void Camera_Shake(unsigned char* camera, int amplitude, int duration) {
    if (duration != 0) {
        *(int*)(camera + 0x1e4) = amplitude;
        *(int*)(camera + 0x1e8) = duration;
    }
}
