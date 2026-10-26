#include <globaldefs.h>

struct Struct_020b1540 {
    signed char left;
    unsigned char glyphWidth;
    signed char unknown_2_;
};

struct Struct_020b27c8_2 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned short unknown_2_;
    signed char unknown_4_;
    unsigned char unknown_5_;
    unsigned char bpp;
    unsigned char flags;
};

struct Struct_020b27c8 {
    unsigned char fontType;
    signed char unknown_1_;
    unsigned short unknown_2_;
    Struct_020b1540 defaultWidth;
    unsigned char unknown_7_;
    Struct_020b27c8_2* unknown_8_;
};

struct Struct_020b1020 {
    Struct_020b27c8* unknown_0_;
};

struct Struct_020b1540_2 {
    const Struct_020b1540* unknown_0_;
    const unsigned char* image;
};

struct Struct_020b1540_3 {
    unsigned char* charBase;
    int areaWidth;
    int unknown_8_;
    unsigned char unknown_c_;
    unsigned char reserved[3];
    unsigned int param;
};

struct Struct_020b1300 {
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

extern "C" void func_020b1300(Struct_020b1300* i);

static inline int inline_020b1540(const Struct_020b1540_3* arg0) {
    return 8 * 8 * arg0->unknown_c_ / 8;
}

static inline unsigned char inline_020b1540_2(const Struct_020b1020* arg0) {
    return arg0->unknown_0_->unknown_8_->unknown_1_;
}

static inline unsigned char inline_020b1540_3(const Struct_020b1020* arg0) {
    return arg0->unknown_0_->unknown_8_->unknown_0_;
}

static inline unsigned char inline_020b1540_4(const Struct_020b1020* arg0) {
    return arg0->unknown_0_->unknown_8_->bpp;
}

// USA: func_020b1540
extern "C" ARM void func_020b1540(const Struct_020b1540_3* arg0, const Struct_020b1020* arg1, int x, int y, int arg4, const Struct_020b1540_2* arg5) {
    int var0;
    int var1;
    int var2;
    int var3;
    int var4;
    unsigned int var5;
    unsigned char* pChar;
    unsigned char glyphWidth;
    unsigned char var8;
    int var9;

    var9 = inline_020b1540(arg0);

    {
        int var10;
        int var11;
        const unsigned int areaWidth = (unsigned int)arg0->areaWidth;
        const unsigned int var13 = (unsigned int)arg0->unknown_8_;
        unsigned char* const charBase = arg0->charBase;
        const Struct_020b1540* const var15 = arg5->unknown_0_;

        unsigned int var16;
        unsigned int var17;
        unsigned int var18;
        unsigned int var19;

        glyphWidth = var15->glyphWidth;
        var8 = inline_020b1540_2(arg1);

        if (glyphWidth <= 0) {
            return;
        }

        if ((x + glyphWidth < 0) || (y + var8) < 0) {
            return;
        }

        var16 = (x <= 0) ? 0 : ((unsigned int)x / 8);
        var18 = (y <= 0) ? 0 : ((unsigned int)y / 8);

        var17 = (unsigned int)(x + glyphWidth + (8 - 1)) / 8;
        if (var17 >= areaWidth) {
            var17 = areaWidth;
        }
        var19 = (unsigned int)(y + var8 + (8 - 1)) / 8;
        if (var19 >= var13) {
            var19 = var13;
        }

        var10 = (int)(var17 - var16);
        var11 = (int)(var19 - var18);

        if ((var10 < 0) || (var11 < 0)) {
            return;
        }

        pChar = charBase + (arg0->param * var18 + var16) * var9;

        var5 = (arg0->param - var10) * var9;

        var0 = (x < 0) ? x : x & 0x7;
        var2 = (y < 0) ? y : y & 0x7;
        var3 = var0 - 8 * var10;
        var4 = var2 - 8 * var11;
    }

    {
        Struct_020b1300 i;

        i.src = arg5->image;
        i.width = glyphWidth;
        i.height = var8;
        i.unknown_24_ = (unsigned int)(arg4 - 1);
        i.unknown_1c_ = inline_020b1540_4(arg1);
        i.unknown_20_ = arg0->unknown_c_;
        i.unknown_18_ = inline_020b1540_3(arg1) * i.unknown_1c_;

        for (; var2 > var4; var2 -= 8) {
            i.unknown_c_ = var2;
            for (var1 = var0; var1 > var3; var1 -= 8) {
                i.dst = pChar;
                i.unknown_8_ = var1;
                func_020b1300(&i);
                pChar += var9;
            }
            pChar += var5;
        }
    }
}
