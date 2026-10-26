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
// USA: func_020c29ec
extern "C" ARM void Mat4x4_WriteProjectionUnknown(fix32_t top, fix32_t bottom, fix32_t left, fix32_t right, fix32_t arg4,
                                                  fix32_t arg5, fix32_t scaleW, Matrix4x4* out)
{
    int64_t var0;
    int64_t inverseHeight;
    int64_t var2;

    fix32_QueueComputeReciprocal(right - left);

    out->entries[1] = 0;
    out->entries[2] = 0;
    out->entries[3] = 0;
    out->entries[4] = 0;
    out->entries[6] = 0;
    out->entries[7] = 0;
    out->entries[8] = 0;
    out->entries[9] = 0;
    out->entries[11] = 0;
    out->entries[15] = scaleW;

    var0 = GetHardwareDividerResult();
    inline_020c28a0((uint64_t)0x1000 << 32, top - bottom);
    if (scaleW != 0x1000)
    {
        var0 = (var0 * scaleW) / 0x1000;
    }
    out->entries[0] = (long)((0x2000 * var0 + 0x80000000LL) >> 32);

    inverseHeight = GetHardwareDividerResult();
    inline_020c28a0((uint64_t)0x1000 << 32, arg4 - arg5);
    if (scaleW != 0x1000)
    {
        inverseHeight = (inverseHeight * scaleW) / 0x1000;
    }
    out->entries[5] = (long)((0x2000 * inverseHeight + 0x80000000LL) >> 32);

    var2 = GetHardwareDividerResult();
    if (scaleW != 0x1000)
    {
        var2 = (var2 * scaleW) / 0x1000;
    }
    out->entries[10] = (long)((0x2000 * var2 + 0x80000000LL) >> 32);

    out->entries[12] = (long)((-(right + left) * var0 + 0x80000000LL) >> 32);
    out->entries[13] = (long)((-(top + bottom) * inverseHeight + 0x80000000LL) >> 32);
    out->entries[14] = (long)(((arg5 + arg4) * var2 + 0x80000000LL) >> 32);
}
