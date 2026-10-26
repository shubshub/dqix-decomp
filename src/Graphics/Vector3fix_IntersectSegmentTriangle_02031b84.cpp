#include <globaldefs.h>
#include "Graphics/Vector.h"

// Main, originally func_02031b84 (USA 0x02031b84, EUR 0x02031b94, JPN 0x020316bc)
extern "C" ARM int Vector3fix_IntersectSegmentTriangle(const Vector3fix* start, const Vector3fix* end,
                                 const Vector3fix* a, const Vector3fix* b,
                                 const Vector3fix* c, const Vector3fix* arg5,
                                 fix32_t* weightA, fix32_t* weightB, fix32_t* weightC,
                                 fix32_t* parameter)
{
    Vector3fix var0, var1, direction, normal, var4, var5;
    Vector3fix_Subtract(b, a, &var0);
    Vector3fix_Subtract(c, a, &var1);
    Vector3fix_Subtract(start, end, &direction);
    Vector3fix_CrossProduct(&var0, &var1, &normal);
    fix32_t var6 = Vector3fix_InnerProduct(&direction, &normal);
    if (var6 <= 0)
        return 0;
    Vector3fix_Subtract(start, a, &var4);
    *parameter = Vector3fix_InnerProduct(&var4, &normal);
    if (*parameter < 0)
        return 0;
    if (*parameter > var6)
        return 0;
    Vector3fix_CrossProduct(&direction, &var4, &var5);
    *weightB = Vector3fix_InnerProduct(&var1, &var5);
    if (*weightB < 0 || *weightB > var6)
        return -1;
    *weightC = -Vector3fix_InnerProduct(&var0, &var5);
    if (*weightC < 0 || *weightB + *weightC > var6)
        return -1;
    fix32_t var7 = fix32_Divide(0x1000, var6);
    *parameter = FIX32_MULTIPLY(*parameter, var7);
    *weightB = FIX32_MULTIPLY(*weightB, var7);
    *weightC = FIX32_MULTIPLY(*weightC, var7);
    *weightA = 0x1000 - *weightB - *weightC;
    return 1;
}
