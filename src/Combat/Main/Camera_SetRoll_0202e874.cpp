#include <globaldefs.h>

// Sets the camera's roll (+0x7c, Camera::roll) and stops its roll animation (+0x1ec step, +0x1ee frames left).
// Main, originally SetField0x7cClearFields0x1ec0x1ee_0202e874 (USA 0x0202e874, EUR 0x0202e884, JPN 0x0202e3e4)
extern "C" ARM void Camera_SetRoll(unsigned char* camera, unsigned short roll) {
    *(unsigned short*)(camera + 0x7c) = roll;
    *(unsigned short*)(camera + 0x1ec) = 0;
    *(unsigned short*)(camera + 0x1ee) = 0;
}
