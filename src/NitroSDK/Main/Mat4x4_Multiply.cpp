#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c223c
extern "C" ARM void Mat4x4_Multiply(const Matrix4x4* arg0, const Matrix4x4* arg1, Matrix4x4* out)
{
    Matrix4x4 tmp;
    Matrix4x4* p;
    register long x, y, z, w;
    register long var6, var7, var8, var9;

    if (out == arg1)
    {
        p = &tmp;
    }
    else
    {
        p = out;
    }

    x = arg0->entries[0];
    y = arg0->entries[1];
    z = arg0->entries[2];
    w = arg0->entries[3];

    p->entries[0] = (long)(((int64_t)x * arg1->entries[0] + (int64_t)y * arg1->entries[4] + (int64_t)z * arg1->entries[8]
                            + (int64_t)w * arg1->entries[12]) >> 12);
    p->entries[1] = (long)(((int64_t)x * arg1->entries[1] + (int64_t)y * arg1->entries[5] + (int64_t)z * arg1->entries[9]
                            + (int64_t)w * arg1->entries[13]) >> 12);
    p->entries[3] = (long)(((int64_t)x * arg1->entries[3] + (int64_t)y * arg1->entries[7] + (int64_t)z * arg1->entries[11]
                            + (int64_t)w * arg1->entries[15]) >> 12);

    var6 = arg1->entries[2];
    var7 = arg1->entries[6];
    var8 = arg1->entries[10];
    var9 = arg1->entries[14];

    p->entries[2] = (long)(((int64_t)x * var6 + (int64_t)y * var7 + (int64_t)z * var8 + (int64_t)w * var9) >> 12);

    x = arg0->entries[4];
    y = arg0->entries[5];
    z = arg0->entries[6];
    w = arg0->entries[7];

    p->entries[6] = (long)(((int64_t)x * var6 + (int64_t)y * var7 + (int64_t)z * var8 + (int64_t)w * var9) >> 12);
    p->entries[5] = (long)(((int64_t)x * arg1->entries[1] + (int64_t)y * arg1->entries[5] + (int64_t)z * arg1->entries[9]
                            + (int64_t)w * arg1->entries[13]) >> 12);
    p->entries[7] = (long)(((int64_t)x * arg1->entries[3] + (int64_t)y * arg1->entries[7] + (int64_t)z * arg1->entries[11]
                            + (int64_t)w * arg1->entries[15]) >> 12);

    var6 = arg1->entries[0];
    var7 = arg1->entries[4];
    var8 = arg1->entries[8];
    var9 = arg1->entries[12];

    p->entries[4] = (long)(((int64_t)x * var6 + (int64_t)y * var7 + (int64_t)z * var8 + (int64_t)w * var9) >> 12);

    x = arg0->entries[8];
    y = arg0->entries[9];
    z = arg0->entries[10];
    w = arg0->entries[11];

    p->entries[8] = (long)(((int64_t)x * var6 + (int64_t)y * var7 + (int64_t)z * var8 + (int64_t)w * var9) >> 12);
    p->entries[9] = (long)(((int64_t)x * arg1->entries[1] + (int64_t)y * arg1->entries[5] + (int64_t)z * arg1->entries[9]
                            + (int64_t)w * arg1->entries[13]) >> 12);
    p->entries[11] = (long)(((int64_t)x * arg1->entries[3] + (int64_t)y * arg1->entries[7] + (int64_t)z * arg1->entries[11]
                             + (int64_t)w * arg1->entries[15]) >> 12);

    var6 = arg1->entries[2];
    var7 = arg1->entries[6];
    var8 = arg1->entries[10];
    var9 = arg1->entries[14];

    p->entries[10] = (long)(((int64_t)x * var6 + (int64_t)y * var7 + (int64_t)z * var8 + (int64_t)w * var9) >> 12);

    x = arg0->entries[12];
    y = arg0->entries[13];
    z = arg0->entries[14];
    w = arg0->entries[15];

    p->entries[14] = (long)(((int64_t)x * var6 + (int64_t)y * var7 + (int64_t)z * var8 + (int64_t)w * var9) >> 12);
    p->entries[13] = (long)(((int64_t)x * arg1->entries[1] + (int64_t)y * arg1->entries[5] + (int64_t)z * arg1->entries[9]
                             + (int64_t)w * arg1->entries[13]) >> 12);
    p->entries[12] = (long)(((int64_t)x * arg1->entries[0] + (int64_t)y * arg1->entries[4] + (int64_t)z * arg1->entries[8]
                             + (int64_t)w * arg1->entries[12]) >> 12);
    p->entries[15] = (long)(((int64_t)x * arg1->entries[3] + (int64_t)y * arg1->entries[7] + (int64_t)z * arg1->entries[11]
                             + (int64_t)w * arg1->entries[15]) >> 12);

    if (p == &tmp)
    {
        *out = tmp;
    }
}
