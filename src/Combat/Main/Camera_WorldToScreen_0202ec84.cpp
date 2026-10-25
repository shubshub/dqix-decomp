#include <globaldefs.h>

struct Vector3i;
int ConvertWorldToScreenCoordinates(Vector3i const*, int*, int*);

struct Vec3copy0202ec84 {
    unsigned int v[3];
};

// Main, originally ComputeTwoFromVec3_0202ec84 (USA 0x0202ec84, EUR 0x0202ec94, JPN 0x0202e7f4)
ARM int Camera_WorldToScreen(void* obj, struct Vec3copy0202ec84* src, int* out1, int* out2) {
    struct Vec3copy0202ec84 local = *src;
    int a, b;
    int result = ConvertWorldToScreenCoordinates((Vector3i const*)&local, &a, &b);
    *out1 = a;
    *out2 = b;
    return result;
}
