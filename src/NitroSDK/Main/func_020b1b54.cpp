#include <globaldefs.h>

struct Struct_020b1b54_2 {
    unsigned char* charBase;
    int areaWidth;
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char padD[3];
    unsigned int param;
};

union Struct_020b1b54 {
    unsigned int packed;
    struct {
        unsigned unknown_0_0_ : 8;
        unsigned unknown_1_0_ : 8;
    } s;
};

extern "C" unsigned int func_020b10b4(unsigned int cx, unsigned int arg1, unsigned int areaWidth, unsigned int arg3, unsigned int arg4, unsigned int arg5);
extern "C" void func_020b11c8(void* pChar, int x, int y, int w, int h, unsigned int cl8, int bpp);

static inline int inline_020b1540(const struct Struct_020b1b54_2* arg0) {
    return 8 * 8 * arg0->unknown_c_ / 8;
}

static inline unsigned int inline_020b19b8(const struct Struct_020b1b54_2* arg0, int arg1) {
    unsigned int val = (unsigned int)arg1;

    if (arg0->unknown_c_ == 4) {
        val = (val << 4) | val;
        val |= val << 8;
        val |= val << 16;
    } else {
        val = (val << 8) | val;
        val |= val << 16;
    }

    return val;
}

// USA: func_020b1b54
extern "C" ARM void func_020b1b54(const struct Struct_020b1b54_2* arg0, int arg1, int x, int y, int w, int h) {
    int var0, var1;
    int var2, var3, var4, var5;
    int cx, var7;
    const int var8 = x + w;
    const int var9 = y + h;
    unsigned int cl8;
    union Struct_020b1b54 p;

    cl8 = inline_020b19b8(arg0, arg1);

    p.packed = arg0->param;

    {
        const int left = x & ~7;
        const int top = y & ~7;
        const int right = (var8 + 7) & ~7;
        const int bottom = (var9 + 7) & ~7;

        const int areaWidth = arg0->areaWidth;
        const int var17 = arg0->unknown_8_;
        const int var18 = (int)p.s.unknown_0_0_;
        const int var19 = (int)p.s.unknown_1_0_;

        const int var20 = inline_020b1540(arg0);
        const int var21 = (int)arg0->param * var20;
        const int bpp = arg0->unknown_c_;
        const int var23 = left / 8;
        unsigned char* const var24 = arg0->charBase;
        unsigned char* pChar;

        var7 = top / 8;

        for (var1 = top; var1 < bottom; var1 += 8) {
            var3 = (var1 < y) ? y - var1 : 0;
            var5 = ((var9 - var1 > 8) ? 8 : var9 - var1) - var3;
            pChar = var24;

            cx = var23;
            for (var0 = left; var0 < right; var0 += 8) {
                const unsigned int var26 = func_020b10b4((unsigned int)cx, (unsigned int)var7, (unsigned int)areaWidth, (unsigned int)var17, (unsigned int)var18, (unsigned int)var19);
                var2 = (var0 < x) ? x - var0 : 0;
                var4 = ((var8 - var0 > 8) ? 8 : var8 - var0) - var2;

                pChar = var24 + var26 * var20;

                func_020b11c8(pChar, var2, var3, var4, var5, cl8, bpp);
                cx++;
            }
            var7++;
        }
    }
}
