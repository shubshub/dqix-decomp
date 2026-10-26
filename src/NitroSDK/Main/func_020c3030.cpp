#include <globaldefs.h>

#include "NitroSDK/Matrix.h"

#define REG_SQRTCNT_020c3030      (*(volatile unsigned short*)0x040002b0)
#define REG_SQRT_RESULT_020c3030  (*(volatile unsigned int*)0x040002b4)
#define REG_SQRTPARAM_LO_020c3030 (*(volatile unsigned int*)0x040002b8)
#define REG_SQRTPARAM_HI_020c3030 (*(volatile unsigned int*)0x040002bc)

// USA: func_020c3030
extern "C" ARM fix32_t Vector3fix_Distance(const Vector3fix* a, const Vector3fix* b) {
    int dx = a->x - b->x;
    long long var1 = (long long)dx * dx;
    int dy = a->y - b->y;
    var1 += (long long)dy * dy;
    int dz = a->z - b->z;
    var1 += (long long)dz * dz;
    REG_SQRTCNT_020c3030 = 1;
    unsigned long long var4 = (unsigned long long)var1 << 2;
    REG_SQRTPARAM_LO_020c3030 = (unsigned int)var4;
    REG_SQRTPARAM_HI_020c3030 = (unsigned int)(var4 >> 32);
    while (REG_SQRTCNT_020c3030 & 0x8000) {}
    return (int)(REG_SQRT_RESULT_020c3030 + 1) >> 1;
}
