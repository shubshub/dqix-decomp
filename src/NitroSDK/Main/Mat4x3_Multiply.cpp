#include <globaldefs.h>
#include <NitroSDK/Matrix.h>

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_020c1d60
extern "C" ARM void Mat4x3_Multiply(const Matrix4x3* arg0, const Matrix4x3* arg1, Matrix4x3* out)
{
    Matrix4x3 tmp;
    Matrix4x3* p;
    register long x, y, z, var5, var6, var7;

    if (out == arg1)
    {
        p = &tmp;
    }
    else
    {
        p = out;
    }

    x = arg0->rows[0].x;
    y = arg0->rows[0].y;
    z = arg0->rows[0].z;

    p->rows[0].x = (long)(((int64_t)x * arg1->rows[0].x + (int64_t)y * arg1->rows[1].x + (int64_t)z * arg1->rows[2].x) >> 12);
    p->rows[0].y = (long)(((int64_t)x * arg1->rows[0].y + (int64_t)y * arg1->rows[1].y + (int64_t)z * arg1->rows[2].y) >> 12);

    var5 = arg1->rows[0].z;
    var6 = arg1->rows[1].z;
    var7 = arg1->rows[2].z;

    p->rows[0].z = (long)(((int64_t)x * var5 + (int64_t)y * var6 + (int64_t)z * var7) >> 12);

    x = arg0->rows[1].x;
    y = arg0->rows[1].y;
    z = arg0->rows[1].z;

    p->rows[1].z = (long)(((int64_t)x * var5 + (int64_t)y * var6 + (int64_t)z * var7) >> 12);
    p->rows[1].y = (long)(((int64_t)x * arg1->rows[0].y + (int64_t)y * arg1->rows[1].y + (int64_t)z * arg1->rows[2].y) >> 12);

    var5 = arg1->rows[0].x;
    var6 = arg1->rows[1].x;
    var7 = arg1->rows[2].x;

    p->rows[1].x = (long)(((int64_t)x * var5 + (int64_t)y * var6 + (int64_t)z * var7) >> 12);

    x = arg0->rows[2].x;
    y = arg0->rows[2].y;
    z = arg0->rows[2].z;

    p->rows[2].x = (long)(((int64_t)x * var5 + (int64_t)y * var6 + (int64_t)z * var7) >> 12);
    p->rows[2].y = (long)(((int64_t)x * arg1->rows[0].y + (int64_t)y * arg1->rows[1].y + (int64_t)z * arg1->rows[2].y) >> 12);
    var5 = arg1->rows[0].z;
    var6 = arg1->rows[1].z;
    var7 = arg1->rows[2].z;

    p->rows[2].z = (long)(((int64_t)x * var5 + (int64_t)y * var6 + (int64_t)z * var7) >> 12);

    x = arg0->rows[3].x;
    y = arg0->rows[3].y;
    z = arg0->rows[3].z;

    p->rows[3].z = (long)((((int64_t)x * var5 + (int64_t)y * var6 + (int64_t)z * var7) >> 12) + arg1->rows[3].z);
    p->rows[3].y = (long)((((int64_t)x * arg1->rows[0].y + (int64_t)y * arg1->rows[1].y + (int64_t)z * arg1->rows[2].y) >> 12)
                          + arg1->rows[3].y);
    p->rows[3].x = (long)((((int64_t)x * arg1->rows[0].x + (int64_t)y * arg1->rows[1].x + (int64_t)z * arg1->rows[2].x) >> 12)
                          + arg1->rows[3].x);

    if (p == &tmp)
    {
        *out = tmp;
    }
}
