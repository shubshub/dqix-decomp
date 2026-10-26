#include <globaldefs.h>

// The camera's perspective: field of view (+0x58), then Camera::frustum (sine, cosine, aspect, near, far).
// Main, originally GetPtrField0x58_0202ed6c (USA 0x0202ed6c, EUR 0x0202ed7c, JPN 0x0202e8dc)
extern "C" ARM void* Camera_GetPerspective(void* camera) {
    return (char*)camera + 0x58;
}
