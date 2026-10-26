#include <globaldefs.h>

struct Struct_020c1264 { unsigned int v[9]; };

// USA: func_020c1264
extern "C" THUMB void Mat3x3_WriteRotationX(struct Struct_020c1264* dst, int s, int c) {
    dst->v[0] = 0x1000;
    dst->v[1] = 0;
    dst->v[2] = 0;
    dst->v[3] = 0;
    dst->v[4] = c;
    dst->v[5] = s;
    dst->v[6] = 0;
    dst->v[7] = -s;
    dst->v[8] = c;
}
