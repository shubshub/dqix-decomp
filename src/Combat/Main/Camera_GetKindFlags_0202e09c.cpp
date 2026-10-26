#include <globaldefs.h>

// Main, originally GetFlags_0202e09c (USA 0x0202e09c, EUR 0x0202e0ac, JPN 0x0202dc0c)
ARM int Camera_GetKindFlags(int camera) {
    return *(int*)camera;
}
