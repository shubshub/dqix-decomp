#include <globaldefs.h>

void* Vec3Ease_Clear(void*);

// Stops the camera's position ease (Camera::positionEase).
// Main, originally CallFunc020a0d58AtField0x16c_0202ee84 (USA 0x0202ee84, EUR 0x0202ee94, JPN 0x0202e9f4)
ARM void* Camera_StopPositionEase(char* camera) {
    return Vec3Ease_Clear(camera + 0x16c);
}
