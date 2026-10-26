#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

#define REG_DIV_NUMER (*(uint64_t*)0x04000290)
#define REG_DIV_DENOM (*(uint64_t*)0x04000298)

static inline void inline_020c28a0(uint64_t arg0, unsigned long arg1)
{
    REG_DIV_NUMER = arg0;
    REG_DIV_DENOM = arg1;
}

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c28a0
extern "C" ARM void Mat4x4_MaybeWriteFrustum(fix32_t arg0, fix32_t arg1, fix32_t arg2, fix32_t arg3, fix32_t arg4,
                                             fix32_t scaleW, Matrix4x4* out)
{
    long var0;
    int64_t inverse;

    var0 = fix32_Divide(arg1, arg0);
    inline_020c28a0((uint64_t)0x1000 << 32, arg3 - arg4);
    if (scaleW != 0x1000)
    {
        var0 = (var0 * scaleW) / 0x1000;
    }

    out->entries[1] = 0;
    out->entries[2] = 0;
    out->entries[3] = 0;
    out->entries[4] = 0;
    out->entries[5] = var0;
    out->entries[6] = 0;
    out->entries[7] = 0;
    out->entries[8] = 0;
    out->entries[9] = 0;
    out->entries[11] = -scaleW;
    out->entries[12] = 0;
    out->entries[13] = 0;
    out->entries[15] = 0;

    inverse = GetHardwareDividerResult();
    inline_020c28a0((uint64_t)var0 << 32, arg2);
    if (scaleW != 0x1000)
    {
        inverse = (inverse * scaleW) / 0x1000;
    }
    out->entries[10] = (long)(((arg4 + arg3) * inverse + 0x80000000LL) >> 32);
    out->entries[14] = (long)(((long)(((int64_t)(arg3 << 1) * arg4 + 0x800) >> 12) * inverse + 0x80000000LL) >> 32);
    out->entries[0] = fix32_GetDivisionResult();
}
