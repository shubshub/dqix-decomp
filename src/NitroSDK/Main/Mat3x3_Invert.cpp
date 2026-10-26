#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

extern "C" void MI_Copy36B(const void* pSrc, void* pDest);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c12b4
extern "C" ARM int Mat3x3_Invert(const Matrix3x3* in, Matrix3x3* out)
{
    Matrix3x3 tmp;
    Matrix3x3* p;
    long var2, var3, var4, var5, var6, var7, var8, var9, var10, var11;

    if (in == out)
    {
        p = &tmp;
    }
    else
    {
        p = out;
    }

    var3 = (long)(((int64_t)in->rows[1].y * in->rows[2].z - (int64_t)in->rows[1].z * in->rows[2].y + (int64_t)0x800) >> 12);
    var4 = (long)(((int64_t)in->rows[1].x * in->rows[2].z - (int64_t)in->rows[1].z * in->rows[2].x + (int64_t)0x800) >> 12);
    var5 = (long)(((int64_t)in->rows[1].x * in->rows[2].y - (int64_t)in->rows[1].y * in->rows[2].x + (int64_t)0x800) >> 12);

    var2 = (long)(((int64_t)in->rows[0].x * var3 - (int64_t)in->rows[0].y * var4 + (int64_t)in->rows[0].z * var5
                  + (int64_t)0x800) >> 12);

    if (0 == var2)
    {
        return -1;
    }

    fix32_QueueComputeReciprocal(var2);

    var6 = (long)(((int64_t)in->rows[0].y * in->rows[2].z - (int64_t)in->rows[2].y * in->rows[0].z) >> 12);
    var7 = (long)(((int64_t)in->rows[0].y * in->rows[1].z - (int64_t)in->rows[1].y * in->rows[0].z) >> 12);
    var8 = (long)(((int64_t)in->rows[0].x * in->rows[2].z - (int64_t)in->rows[2].x * in->rows[0].z) >> 12);
    var9 = (long)(((int64_t)in->rows[0].x * in->rows[1].z - (int64_t)in->rows[1].x * in->rows[0].z) >> 12);

    var2 = fix32_GetDivisionResult();
    p->rows[0].x = (long)(((int64_t)var2 * var3) >> 12);
    p->rows[0].y = -(long)(((int64_t)var2 * var6) >> 12);
    p->rows[0].z = (long)(((int64_t)var2 * var7) >> 12);

    p->rows[1].x = -(long)(((int64_t)var2 * var4) >> 12);
    p->rows[1].y = (long)(((int64_t)var2 * var8) >> 12);
    p->rows[1].z = -(long)(((int64_t)var2 * var9) >> 12);

    p->rows[2].x = (long)(((int64_t)var2 * var5) >> 12);

    var10 = (long)(((int64_t)in->rows[0].x * in->rows[2].y - (int64_t)in->rows[2].x * in->rows[0].y) >> 12);
    p->rows[2].y = -(long)(((int64_t)var2 * var10) >> 12);

    var11 = (long)(((int64_t)in->rows[0].x * in->rows[1].y - (int64_t)in->rows[1].x * in->rows[0].y) >> 12);
    p->rows[2].z = (long)(((int64_t)var2 * var11) >> 12);

    if (p == &tmp)
    {
        MI_Copy36B(&tmp, out);
    }

    return 0;
}
