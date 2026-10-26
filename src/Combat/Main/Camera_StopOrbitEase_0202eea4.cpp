#include <globaldefs.h>

void* Vec3Ease_Clear(void*);

// Stops the camera's orbit ease (Camera::unknownEase, the third record: it eases the orbit vector).
// Main, originally CallFunc020a0d58AtField0x1bc_0202eea4 (USA 0x0202eea4, EUR 0x0202eeb4, JPN 0x0202ea14)
ARM void* Camera_StopOrbitEase(void* camera) {
    return Vec3Ease_Clear((char*)camera + 0x1bc);
}
