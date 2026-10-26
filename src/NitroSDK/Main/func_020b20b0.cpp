#include <globaldefs.h>

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char Type_020b1300;

#define CHARACTER_WIDTH  8
#define CHARACTER_HEIGHT 8

#define GX_OAM_ATTR01_Y_MASK     0x000000ff
#define GX_OAM_ATTR01_X_SHIFT    16
#define GX_OAM_ATTR01_X_MASK     0x01ff0000
#define GX_OAM_ATTR01_CM_SHIFT   13
#define GX_OAM_ATTR01_CM_MASK    0x00002000
#define GX_OAM_ATTR01_SHAPE_MASK 0x0000c000
#define GX_OAM_ATTR01_SIZE_MASK  0xc0000000
#define GX_OAM_ATTR2_NAME_MASK   0x000003ff

enum Enum_020b20b0 {
    Enum_020b20b0_0 = 0,
    Enum_020b20b0_1 = 1
};

typedef int Type_020b20b0;
typedef int Type_020b20b0_2;

struct Struct_020b0a1c_2 {
    union {
        u32 unknown_0_;
        struct {
            u16 unknown1_0_;
            u16 unknown_2_;
        };
    };
    union {
        struct {
            u16 unknown_4_;
            u16 unknown_6_;
        };
        u32 unknown1_4_;
    };
};

struct Struct_020e91e0 {
    Type_020b1300 unknown_0_;
    Type_020b1300 unknown_1_;
};

extern Struct_020e91e0 data_020e91e0[4][4];

extern "C" Type_020b20b0 func_020b11ac(Type_020b1300 *arg0);

static inline u32 inline_020b20b0(u32 x) {
    asm {
        clz x, x
    }
    return x;
}

static inline int inline_020b20b0_2(u32 x) {
    return (int)(31 - inline_020b20b0(x));
}

static inline Struct_020e91e0 *inline_020b20b0_3(int w, int h) {
    int var0 = (w >= 8) ? 3 : inline_020b20b0_2((unsigned long)w);
    int var1 = (h >= 8) ? 3 : inline_020b20b0_2((unsigned long)h);

    return &data_020e91e0[var1][var0];
}

static inline void inline_020b0a1c_15(Struct_020b0a1c_2 *oam, int x, int y) {
    oam->unknown_0_ = ((oam->unknown_0_ & ~(GX_OAM_ATTR01_Y_MASK | GX_OAM_ATTR01_X_MASK)) | (y & GX_OAM_ATTR01_Y_MASK)
                   | ((x & (GX_OAM_ATTR01_X_MASK >> GX_OAM_ATTR01_X_SHIFT)) << GX_OAM_ATTR01_X_SHIFT));
}

static inline void inline_020b20b0_4(Struct_020b0a1c_2 *oam, Type_020b20b0 shape) {
    oam->unknown_0_ = ((oam->unknown_0_ & ~(GX_OAM_ATTR01_SHAPE_MASK | GX_OAM_ATTR01_SIZE_MASK)) | shape);
}

static inline void inline_020b20b0_5(Struct_020b0a1c_2 *oam, int name) {
    oam->unknown_4_ = (u16)((oam->unknown_4_ & ~GX_OAM_ATTR2_NAME_MASK) | name);
}

static inline void inline_020b20b0_6(Struct_020b0a1c_2 *oam, Enum_020b20b0 color) {
    oam->unknown_0_ = ((oam->unknown_0_ & ~GX_OAM_ATTR01_CM_MASK) | (color << GX_OAM_ATTR01_CM_SHIFT));
}

// USA: func_020b20b0
extern "C" ARM int func_020b20b0(Struct_020b0a1c_2 *oam, int areaWidth, int arg2, int x, int y, Enum_020b20b0 color, int arg6, Type_020b20b0_2 arg7) {
    Struct_020e91e0 *const var0    = inline_020b20b0_3(areaWidth, arg2);
    const int var1    = var0->unknown_0_;
    const int var2   = var0->unknown_1_;
    const u32 var3  = (u32)(~0) << var1;
    const u32 var4 = (u32)(~0) << var2;
    const u32 var5       = areaWidth & var3;
    const u32 var6      = arg2 & var4;
    const int var7     = (color == Enum_020b20b0_0) ? 1 : 2;
    int var8               = 0;

    {
        const Type_020b20b0 shape = func_020b11ac(&var0->unknown_0_);
        const int var10         = areaWidth >> var1;
        const int var11         = arg2 >> var2;
        const int var12 = ((var7 << var1) << var2) >> arg7;
        int var13, var14;

        for (var14 = 0; var14 < var11; ++var14) {
            const int var15 = y + (var14 << var2) * CHARACTER_HEIGHT;

            for (var13 = 0; var13 < var10; ++var13) {
                const int px = x + (var13 << var1) * CHARACTER_WIDTH;

                inline_020b0a1c_15(oam, px, var15);
                inline_020b20b0_4(oam, shape);
                inline_020b20b0_5(oam, arg6);
                inline_020b20b0_6(oam, color);

                oam++;
                arg6 += var12;
            }
        }

        var8 += var10 * var11;
    }

    if (var5 < areaWidth) {
        const unsigned int var17  = areaWidth - var5;
        const unsigned int var18 = var6;
        const int px                   = x + (int)var5 * CHARACTER_WIDTH;
        const int var20                   = y;

        const int var21 = func_020b20b0(oam, (int)var17, (int)var18, px, var20, color, arg6, arg7);

        oam += var21;
        var8 += var21;
        arg6 += (var7 * var17 * var18) >> arg7;
    }

    if (var6 < arg2) {
        const unsigned int var22  = var5;
        const unsigned int var23 = arg2 - var6;
        const int px                   = x;
        const int var25                   = y + (int)var6 * CHARACTER_HEIGHT;

        const int var26 = func_020b20b0(oam, (int)var22, (int)var23, px, var25, color, arg6, arg7);

        oam += var26;
        var8 += var26;
        arg6 += (var7 * var22 * var23) >> arg7;
    }

    if (var5 < areaWidth && var6 < arg2) {
        const unsigned int var27  = areaWidth - var5;
        const unsigned int var28 = arg2 - var6;
        const int px                   = x + (int)var5 * CHARACTER_WIDTH;
        const int var30                   = y + (int)var6 * CHARACTER_HEIGHT;

        const int var31 = func_020b20b0(oam, (int)var27, (int)var28, px, var30, color, arg6, arg7);

        var8 += var31;
    }

    return var8;
}
