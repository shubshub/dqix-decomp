#include <globaldefs.h>

// The camera's orbit yaw.
// Main, originally GetField0x70_0202e7f0 (USA 0x0202e7f0, EUR 0x0202e800, JPN 0x0202e360)
extern "C" ARM int Camera_GetOrbitYaw(void* camera) {
    return *(int*)((char*)camera + 0x70);
}
