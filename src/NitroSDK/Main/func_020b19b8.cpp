#include <globaldefs.h>

typedef unsigned char Type_020b1300;
typedef unsigned int u32;

struct Struct_020b1540_3 {
    Type_020b1300 *charBase;
    int areaWidth;
    int unknown_8_;
    Type_020b1300 unknown_c_;
    Type_020b1300 reserved[3];
    u32 param;
};

extern "C" void func_020b11c8(void *pChar, int x, int y, int w, int h, u32 cl8, int bpp);

static inline int inline_020b1540(const Struct_020b1540_3 *arg0) {
    return 8 * 8 * arg0->unknown_c_ / 8;
}

static inline u32 inline_020b19b8(const Struct_020b1540_3 *arg0, int arg1) {
    u32 val = (u32)arg1;

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

// USA: func_020b19b8
extern "C" ARM void func_020b19b8(const Struct_020b1540_3 *arg0, int arg1, int x, int y, int w, int h) {
    int var0, var1;
    int cx, var3, var4, ch;
    const int var6 = x + w;
    const int var7 = y + h;
    u32 cl8;

    cl8 = inline_020b19b8(arg0, arg1);

    {
        const int left = x & ~7;
        const int top = y & ~7;
        const int right = (var6 + 7) & ~7;
        const int bottom = (var7 + 7) & ~7;

        const int var13 = inline_020b1540(arg0);
        const int var14 = (int)(arg0->param * var13);
        const int bpp = arg0->unknown_c_;
        Type_020b1300 *var16;
        Type_020b1300 *pChar;

        var16 = arg0->charBase + ((top / 8) * arg0->param + (left / 8)) * var13;

        for (var1 = top; var1 < bottom; var1 += 8) {
            var3 = (var1 < y) ? y - var1 : 0;
            ch = ((var7 - var1 > 8) ? 8 : var7 - var1) - var3;
            pChar = var16;

            for (var0 = left; var0 < right; var0 += 8) {
                cx = (var0 < x) ? x - var0 : 0;
                var4 = ((var6 - var0 > 8) ? 8 : var6 - var0) - cx;

                func_020b11c8(pChar, cx, var3, var4, ch, cl8, bpp);
                pChar += var13;
            }

            var16 += var14;
        }
    }
}
