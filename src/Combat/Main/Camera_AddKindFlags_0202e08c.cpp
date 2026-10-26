#include <globaldefs.h>

// Every caller passes a camera: this ORs bits into its kind flags (Camera::field0, Camera_GetKindFlags).
// Main, originally SetBitsInField0_0202e08c (USA 0x0202e08c, EUR 0x0202e09c, JPN 0x0202dbfc)
ARM void Camera_AddKindFlags(unsigned int* cameraKindFlags, unsigned int bits) {
    *cameraKindFlags |= bits;
}
