#include <globaldefs.h>

// Camera::inverseRotation, the view rotation's inverse Camera_Update copies from RenderConfig (billboards use it).
// Main, originally GetPtrField0x144_0202ed74 (USA 0x0202ed74, EUR 0x0202ed84, JPN 0x0202e8e4)
extern "C" ARM void* Camera_GetInverseRotation(void* camera) {
    return (char*)camera + 0x144;
}
