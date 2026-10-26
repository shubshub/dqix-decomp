#include <globaldefs.h>

void* Vec3Ease_Clear(void*);

// Stops the camera's target ease (Camera::targetEase).
// Main, originally CallFunc020a0d58AtField0x194_0202ee94 (USA 0x0202ee94, EUR 0x0202eea4, JPN 0x0202ea04)
ARM void* Camera_StopTargetEase(void* camera) {
    return Vec3Ease_Clear((char*)camera + 0x194);
}
