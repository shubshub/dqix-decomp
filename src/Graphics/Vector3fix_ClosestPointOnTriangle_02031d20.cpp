#include <globaldefs.h>
#include "Graphics/Vector.h"

static inline fix32_t inline_02031d20(fix32_t a, fix32_t b)
{
    int64_t var0 = (int64_t)a * (int64_t)b;
    return (fix32_t)((var0 + (int64_t)0x800) >> 12);
}

// Keep widened dot products: their spill/reload behavior is present in the original.
// Main, originally func_02031d20 (USA 0x02031d20, EUR 0x02031d30, JPN 0x02031858)
extern "C" ARM Vector3fix Vector3fix_ClosestPointOnTriangle(const Vector3fix* point, const Vector3fix* a,
                                        const Vector3fix* b, const Vector3fix* c)
{
    Vector3fix var0, ac, var2;
    Vector3fix_Subtract(b, a, &var0);
    Vector3fix_Subtract(c, a, &ac);
    Vector3fix_Subtract(point, a, &var2);
    fix32_t var3 = Vector3fix_InnerProduct(&var0, &var2);
    fix32_t var4 = Vector3fix_InnerProduct(&ac, &var2);
    if (var3 <= 0 && var4 <= 0)
        return *a;
    Vector3fix var5;
    Vector3fix_Subtract(point, b, &var5);
    fix32_t var6 = Vector3fix_InnerProduct(&var0, &var5);
    fix32_t var7 = Vector3fix_InnerProduct(&ac, &var5);
    if (var6 >= 0 && var7 <= var6)
        return *b;
    fix32_t vc = inline_02031d20(var3, var7) - inline_02031d20(var6, var4);
    if (vc <= 0 && var3 >= 0 && var6 <= 0) {
        fix32_t v = fix32_Divide((fix32_t)var3, (fix32_t)(var3 - var6));
        Vector3fix result;
        Vector3fixMultiplyScalar(&var0, v, &result);
        Vector3fix_Add(a, &result, &result);
        return result;
    }
    Vector3fix cp;
    Vector3fix_Subtract(point, c, &cp);
    fix32_t var12 = Vector3fix_InnerProduct(&var0, &cp);
    fix32_t var13 = Vector3fix_InnerProduct(&ac, &cp);
    if (var13 >= 0 && var12 <= var13)
        return *c;
    fix32_t var14 = inline_02031d20(var12, var4) - inline_02031d20(var3, var13);
    if (var14 <= 0 && var4 >= 0 && var13 <= 0) {
        fix32_t w = fix32_Divide((fix32_t)var4, (fix32_t)(var4 - var13));
        Vector3fix result;
        Vector3fixMultiplyScalar(&ac, w, &result);
        Vector3fix_Add(a, &result, &result);
        return result;
    }
    fix32_t var17 = inline_02031d20(var6, var13) - inline_02031d20(var12, var7);
    if (var17 <= 0 && var7 - var6 >= 0 && var12 - var13 >= 0) {
        fix32_t w = fix32_Divide((fix32_t)(var7 - var6), (fix32_t)((var7 - var6) + (var12 - var13)));
        Vector3fix result;
        Vector3fix_Subtract(c, b, &result);
        Vector3fixMultiplyScalar(&result, w, &result);
        Vector3fix_Add(b, &result, &result);
        return result;
    }
    return *point;
}
