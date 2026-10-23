#include <globaldefs.h>

// Main, originally SetFields0x10To0x18_0202e5c8 (USA 0x0202e5c8, EUR 0x0202e5d8, JPN 0x0202e138)
ARM void Camera_SetTarget(unsigned char* obj, int a, int b, int c) {
    *(int*)(obj + 0x10) = a;
    *(int*)(obj + 0x14) = b;
    *(int*)(obj + 0x18) = c;
}
