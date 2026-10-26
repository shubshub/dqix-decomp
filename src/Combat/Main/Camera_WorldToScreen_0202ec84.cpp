#include <globaldefs.h>

struct Vector3i;
int ConvertWorldToScreenCoordinates(Vector3i const*, int*, int*);

struct Vec3copy0202ec84 {
    unsigned int v[3];
};

// Main, originally ComputeTwoFromVec3_0202ec84 (USA 0x0202ec84, EUR 0x0202ec94, JPN 0x0202e7f4)
extern "C" ARM int Camera_WorldToScreen(void* camera, struct Vec3copy0202ec84* world, int* outX, int* outY) {
    struct Vec3copy0202ec84 position = *world;
    int screenX, screenY;
    int result = ConvertWorldToScreenCoordinates((Vector3i const*)&position, &screenX, &screenY);
    *outX = screenX;
    *outY = screenY;
    return result;
}
