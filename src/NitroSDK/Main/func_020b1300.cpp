#include <globaldefs.h>

typedef unsigned char Type_020b1300;
typedef signed char Type_ov002_0215ab60;
typedef unsigned int u32;
typedef unsigned long long Type_020b11c8_2;

#define CHARACTER_WIDTH 8
#define CHARACTER_HEIGHT 8

struct Struct_020b1300 {
    const Type_020b1300* dst;
    const Type_020b1300* src;
    int unknown_8_;
    int unknown_c_;
    int width;
    int height;
    int unknown_18_;
    int unknown_1c_;
    int unknown_20_;
    u32 unknown_24_;
};

struct Struct_020b1300_2 {
    const Type_020b1300* src;
    Type_ov002_0215ab60 unknown_4_;
    Type_020b1300 bits;
    Type_020b1300 unknown_6_[2];
};

extern "C" u32 func_020b29f8(Struct_020b1300_2* reader, int arg1);

static inline void inline_020b1300(Struct_020b1300_2* reader, const void* src) {
    reader->unknown_4_ = 0;
    reader->src = (const Type_020b1300*)src;
    reader->bits = 0;
}

static inline int inline_020b1300_2(int a, int b) {
    return (a <= b) ? a : b;
}

static inline int inline_020b1300_3(int a, int b) {
    return (a >= b) ? a : b;
}

// USA: func_020b1300
extern "C" ARM void func_020b1300(Struct_020b1300* i) {
    const Type_020b1300* pSrc;
    u32 var1;
    u32 var2;
    u32 var3;
    u32 var4;
    u32 offset;

    {
        u32 var6;

        var1 = (unsigned int)inline_020b1300_3(i->unknown_8_, 0);
        var3 = (unsigned int)inline_020b1300_3(i->unknown_c_, 0);
        var2 = (unsigned int)inline_020b1300_2(CHARACTER_WIDTH, i->unknown_8_ + i->width);
        var4 = (unsigned int)inline_020b1300_2(CHARACTER_HEIGHT, i->unknown_c_ + i->height);

        var6 = (unsigned int)-inline_020b1300_2(i->unknown_c_, 0);
        offset = -inline_020b1300_2(i->unknown_8_, 0) * i->unknown_1c_ + var6 * i->unknown_18_;

        pSrc = i->src;
    }

    {
        u32 x;
        const int var8 = i->unknown_18_;
        const int var9 = i->unknown_1c_;
        const int var10 = i->unknown_20_;

        var1 *= var10;
        var2 *= var10;

        if (var10 == 4) {
            u32* var11 = (u32*)i->dst + var3;
            u32* var12 = (u32*)i->dst + var4;
            u32 var13 = i->unknown_24_;

            for (; var11 < var12; var11++) {
                Struct_020b1300_2 reader;
                u32 var15 = *var11;

                inline_020b1300(&reader, pSrc + offset / 8);
                (void)func_020b29f8(&reader, (int)offset % 8);

                for (x = var1; x < var2; x += 4) {
                    u32 bits = func_020b29f8(&reader, var9);

                    if (bits != 0) {
                        var15 = (var15 & ~(0xF << x)) | ((var13 + bits) << x);
                    }
                }

                *var11 = var15;

                offset += var8;
            }
        } else {
            u32* var17 = (u32*)((Type_020b11c8_2*)i->dst + var3);
            u32* const var18 = (u32*)((Type_020b11c8_2*)i->dst + var4);
            u32 var19 = i->unknown_24_;

            for (; var17 < var18; var17 += 2) {
                Struct_020b1300_2 reader;
                u32 var21 = *var17;
                u32 var22 = *(var17 + 1);

                inline_020b1300(&reader, pSrc + offset / 8);
                (void)func_020b29f8(&reader, (int)offset % 8);

                for (x = var1; x < var2; x += 8) {
                    u32 bits = func_020b29f8(&reader, var9);

                    if (bits != 0) {
                        if (x < 32) {
                            var21 = (var21 & ~((u32)0xFF << x)) | ((u32)(var19 + bits) << x);
                        } else {
                            const u32 var24 = x - 32;
                            var22 = (var22 & ~((u32)0xFF << var24)) | ((u32)(var19 + bits) << var24);
                        }
                    }
                }

                *var17 = var21;
                *(var17 + 1) = var22;

                offset += var8;
            }
        }
    }
}
