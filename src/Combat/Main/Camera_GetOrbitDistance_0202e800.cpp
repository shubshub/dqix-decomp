#include <globaldefs.h>

// The camera's orbit distance.
// Main, originally GetField0x78_0202e800 (USA 0x0202e800, EUR 0x0202e810, JPN 0x0202e370)
extern "C" ARM int Camera_GetOrbitDistance(void* camera) {
    return *(int*)((char*)camera + 0x78);
}
