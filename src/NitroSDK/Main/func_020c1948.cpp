#include <globaldefs.h>

extern "C" void Mat3x3_ApplyScale(int* src, int* dst, int scaleX, int scaleY, int scaleZ);

// USA: func_020c1948
extern "C" ARM void Mat4x3_ApplyScale(int* src, int* dst, int scaleX, int scaleY, int scaleZ) {
    Mat3x3_ApplyScale(src, dst, scaleX, scaleY, scaleZ);
    dst[9] = src[9];
    dst[10] = src[10];
    dst[11] = src[11];
}
