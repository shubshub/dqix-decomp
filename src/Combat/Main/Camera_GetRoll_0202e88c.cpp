#include <globaldefs.h>

// The camera's roll (+0x7c, Camera::roll).
// Main, originally GetField0x7c_0202e88c (USA 0x0202e88c, EUR 0x0202e89c, JPN 0x0202e3fc)
ARM short Camera_GetRoll(void* camera) {
    return *(short*)((char*)camera + 0x7c);
}
