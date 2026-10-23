#include <globaldefs.h>

struct Vec3Target0202e5c0 {
    char pad[4];
    int x;
    int y;
    int z;
};

// Main, originally SetVec3At0x4 (USA 0x0202e5c0, EUR 0x0202e5d0, JPN 0x0202e130)
ARM void Camera_SetPosition(struct Vec3Target0202e5c0* obj, int x, int y, int z) {
    obj->x = x;
    obj->y = y;
    obj->z = z;
}
