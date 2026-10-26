#include <globaldefs.h>

struct Struct_020b16d8_2 {
    unsigned char* charBase;
    int areaWidth;
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char padD[3];
    unsigned int param;
};

struct Struct_020b10b4 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    signed char unknown_4_;
    unsigned char unknown_5_;
    unsigned char bpp;
    unsigned char flags;
};

struct Struct_020b10b4_2 {
    unsigned char fontType;
    signed char unknown_1_;
    unsigned short unknown_2_;
    unsigned char defaultWidth[3];
    unsigned char unknown_7_;
    struct Struct_020b10b4* unknown_8_;
};

struct Struct_020b16d8_3 {
    struct Struct_020b10b4_2* unknown_0_;
};

struct Struct_020b16d8_4 {
    signed char left;
    unsigned char glyphWidth;
    signed char unknown_2_;
};

struct Struct_020b16d8_5 {
    const struct Struct_020b16d8_4* unknown_0_;
    const unsigned char* image;
};

struct Struct_020b16d8_6 {
    const unsigned char* dst;
    const unsigned char* src;
    int unknown_8_;
    int unknown_c_;
    int width;
    int height;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    unsigned int unknown_24_;
};

union Struct_020b16d8 {
    unsigned int packed;
    struct {
        unsigned unknown_0_0_ : 8;
        unsigned unknown_1_0_ : 8;
    } s;
};

extern "C" unsigned int func_020b10b4(unsigned int cx, unsigned int arg1, unsigned int areaWidth, unsigned int arg3, unsigned int arg4, unsigned int arg5);
extern "C" void func_020b1300(struct Struct_020b16d8_6* i);

static inline int inline_020b1540(const struct Struct_020b16d8_2* arg0) {
    return 8 * 8 * arg0->unknown_c_ / 8;
}

static inline unsigned char inline_020b16d8(const struct Struct_020b16d8_3* arg0) {
    return arg0->unknown_0_->unknown_8_->unknown_1_;
}

static inline unsigned char inline_020b16d8_2(const struct Struct_020b16d8_3* arg0) {
    return arg0->unknown_0_->unknown_8_->unknown_0_;
}

static inline unsigned char inline_020b16d8_3(const struct Struct_020b16d8_3* arg0) {
    return arg0->unknown_0_->unknown_8_->bpp;
}

// USA: func_020b16d8
extern "C" ARM void func_020b16d8(const struct Struct_020b16d8_2* arg0, const struct Struct_020b16d8_3* arg1, int x, int y, int arg4, const struct Struct_020b16d8_5* arg5) {
    int var0;
    int var1;
    int var2;
    int var3;
    int var4;
    int cx, var6;
    int var7;
    unsigned char glyphWidth;
    unsigned char var9;
    int var10;

    var10 = inline_020b1540(arg0);

    {
        int var11;
        int var12;

        unsigned int areaWidth = (unsigned int)arg0->areaWidth;
        unsigned int var14 = (unsigned int)arg0->unknown_8_;

        unsigned int var15;
        unsigned int var16;
        unsigned int var17;
        unsigned int var18;

        glyphWidth = arg5->unknown_0_->glyphWidth;
        var9 = inline_020b16d8(arg1);

        if (glyphWidth <= 0) {
            return;
        }

        if ((x + glyphWidth < 0) || (y + var9) < 0) {
            return;
        }

        var15 = (x <= 0) ? 0 : ((unsigned int)x / 8);
        var17 = (y <= 0) ? 0 : ((unsigned int)y / 8);

        var16 = (unsigned int)(x + glyphWidth + 7) / 8;
        if (var16 >= areaWidth) {
            var16 = areaWidth;
        }

        var18 = (unsigned int)(y + var9 + 7) / 8;
        if (var18 >= var14) {
            var18 = var14;
        }

        var11 = (int)(var16 - var15);
        var12 = (int)(var18 - var17);

        if ((var11 < 0) || (var12 < 0)) {
            return;
        }

        var6 = (int)var15;
        var7 = (int)var17;

        var0 = (x < 0) ? x : x & 0x7;
        var2 = (y < 0) ? y : y & 0x7;
        var3 = var0 - 8 * var11;
        var4 = var2 - 8 * var12;
    }

    {
        struct Struct_020b16d8_6 i;
        unsigned char* const var20 = arg0->charBase;
        union Struct_020b16d8 p;

        i.src = arg5->image;
        i.width = glyphWidth;
        i.height = var9;
        i.unknown_24_ = (unsigned int)(arg4 - 1);
        i.unknown_1c_ = inline_020b16d8_3(arg1);
        i.unknown_20_ = arg0->unknown_c_;
        i.unknown_18_ = inline_020b16d8_2(arg1) * i.unknown_1c_;

        p.packed = arg0->param;

        {
            const unsigned int areaWidth = (unsigned int)arg0->areaWidth;
            const unsigned int var23 = (unsigned int)arg0->unknown_8_;
            const unsigned int var24 = p.s.unknown_0_0_;
            const unsigned int var25 = p.s.unknown_1_0_;

            for (; var2 > var4; var2 -= 8) {
                i.unknown_c_ = var2;
                cx = var6;
                for (var1 = var0; var1 > var3; var1 -= 8) {
                    const unsigned int var26 = func_020b10b4((unsigned int)cx, (unsigned int)var7, areaWidth, var23, var24, var25);

                    i.unknown_8_ = var1;
                    i.dst = var20 + var26 * var10;

                    func_020b1300(&i);
                    cx++;
                }
                var7++;
            }
        }
    }
}
