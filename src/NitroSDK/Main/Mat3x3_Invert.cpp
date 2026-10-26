#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

extern "C" void MI_Copy36B(const void* pSrc, void* pDest);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c12b4
extern "C" ARM int Mat3x3_Invert(const Matrix3x3* arg0, Matrix3x3* arg1)
{
    Matrix3x3 var0;
    Matrix3x3* var1;
    long var2, var3, var4, var5, var6, var7, var8, var9, var10, var11;

    if (arg0 == arg1)
    {
        var1 = &var0;
    }
    else
    {
        var1 = arg1;
    }

    var3 = (long)(((int64_t)arg0->rows[1].y * arg0->rows[2].z - (int64_t)arg0->rows[1].z * arg0->rows[2].y + (int64_t)0x800) >> 12);
    var4 = (long)(((int64_t)arg0->rows[1].x * arg0->rows[2].z - (int64_t)arg0->rows[1].z * arg0->rows[2].x + (int64_t)0x800) >> 12);
    var5 = (long)(((int64_t)arg0->rows[1].x * arg0->rows[2].y - (int64_t)arg0->rows[1].y * arg0->rows[2].x + (int64_t)0x800) >> 12);

    var2 = (long)(((int64_t)arg0->rows[0].x * var3 - (int64_t)arg0->rows[0].y * var4 + (int64_t)arg0->rows[0].z * var5
                  + (int64_t)0x800) >> 12);

    if (0 == var2)
    {
        return -1;
    }

    fix32_QueueComputeReciprocal(var2);

    var6 = (long)(((int64_t)arg0->rows[0].y * arg0->rows[2].z - (int64_t)arg0->rows[2].y * arg0->rows[0].z) >> 12);
    var7 = (long)(((int64_t)arg0->rows[0].y * arg0->rows[1].z - (int64_t)arg0->rows[1].y * arg0->rows[0].z) >> 12);
    var8 = (long)(((int64_t)arg0->rows[0].x * arg0->rows[2].z - (int64_t)arg0->rows[2].x * arg0->rows[0].z) >> 12);
    var9 = (long)(((int64_t)arg0->rows[0].x * arg0->rows[1].z - (int64_t)arg0->rows[1].x * arg0->rows[0].z) >> 12);

    var2 = fix32_GetDivisionResult();
    var1->rows[0].x = (long)(((int64_t)var2 * var3) >> 12);
    var1->rows[0].y = -(long)(((int64_t)var2 * var6) >> 12);
    var1->rows[0].z = (long)(((int64_t)var2 * var7) >> 12);

    var1->rows[1].x = -(long)(((int64_t)var2 * var4) >> 12);
    var1->rows[1].y = (long)(((int64_t)var2 * var8) >> 12);
    var1->rows[1].z = -(long)(((int64_t)var2 * var9) >> 12);

    var1->rows[2].x = (long)(((int64_t)var2 * var5) >> 12);

    var10 = (long)(((int64_t)arg0->rows[0].x * arg0->rows[2].y - (int64_t)arg0->rows[2].x * arg0->rows[0].y) >> 12);
    var1->rows[2].y = -(long)(((int64_t)var2 * var10) >> 12);

    var11 = (long)(((int64_t)arg0->rows[0].x * arg0->rows[1].y - (int64_t)arg0->rows[1].x * arg0->rows[0].y) >> 12);
    var1->rows[2].z = (long)(((int64_t)var2 * var11) >> 12);

    if (var1 == &var0)
    {
        MI_Copy36B(&tmp, out);
    }

    return 0;
}
