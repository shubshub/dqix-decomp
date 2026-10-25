#include <globaldefs.h>
#include "Memory/SafeAllocator.h"
#include "NitroSDK/Memory/SignedAllocator.h"
#include "World/Object3D.h"

extern "C" int rand(void);

struct Struct_020546c8;
extern "C" void* func_02055108(struct Struct_020546c8* arg0);
extern "C" void* func_02055120(struct Struct_020546c8* arg0);
extern "C" void* func_020550d8(struct Struct_020546c8* arg0);
extern "C" void* func_02055138(struct Struct_020546c8* arg0);
extern "C" void* func_02055150(struct Struct_020546c8* arg0);

struct Struct_020546c8 {
    SafeAllocator* unknown_0_;
    void* unknown_4_;
    SignedAllocatorList unknown_8_[3];
    SignedAllocatorList unknown_2c_[3];
    SignedAllocatorList unknown_50_[3];
    SignedAllocatorList unknown_74_;
    SignedAllocatorList unknown_80_[3];
    SignedAllocatorList unknown_a4_;
    SignedAllocatorList unknown_b0_[2];
    SignedAllocatorList unknown_c8_[2];
    SignedAllocatorList unknown_e0_;
    SignedAllocatorList unknown_ec_[4];
    SignedAllocatorList unknown_11c_;
};

struct Struct_02058d40_11 {
    unsigned char unknown_0_;
    unsigned char unknown_1_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned char unknown_4_;
    unsigned char unknown_5_;
    unsigned char unknown_6_;
};

struct Struct_02058d40 {
    void* unknown_0_[2];
    unsigned char unknown_8_[2];
};

struct Struct_02058d40_2 {
    char unknown_0_[0x17];
    unsigned char unknown_17_;
};

struct Struct_02058d40_3 {
    short unknown_0_;
    unsigned char unknown_2_;
    char unknown_3_;
    void* unknown_4_;
    unsigned char unknown_8_;
};

struct Struct_02058d40_4 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
};
struct Struct_02058d40_5 {
    Struct_02058d40_4* unknown_0_;
};

struct Struct_02058d40_6 {
    unsigned int unknown_0_;
    float unknown_4_;
    float unknown_8_;
    float unknown_c_;
};
struct Struct_02058d40_7 {
    Struct_02058d40_6* unknown_0_;
};

struct Struct_02058d40_8 {
    int unknown_0_;
    float unknown_4_;
    float unknown_8_;
};
struct Struct_02058d40_9 {
    Struct_02058d40_8* unknown_0_;
};

struct Struct_02058d40_10 {
    char unknown_0_[0x4];
    int unknown_4_;
    int unknown_8_;
    unsigned char unknown_c_;
    char unknown_d_[0x28 - 0xd];
    Struct_020546c8* unknown_28_;
    char unknown_2c_[0x30 - 0x2c];
    float unknown_30_;
    float unknown_34_;
    float unknown_38_;
    float unknown_3c_;
    float unknown_40_;
    float unknown_44_;
    float unknown_48_;
    float unknown_4c_;
    float unknown_50_;
    float unknown_54_;
    float unknown_58_;
    float unknown_5c_;
    float unknown_60_;
    unsigned short unknown_64_;
    unsigned short unknown_66_;
    unsigned short unknown_68_;
    unsigned short unknown_6a_;
    char unknown_6c_[0x78 - 0x6c];
    float unknown_78_;
    Object3D unknown_7c_;
    unsigned int unknown_128_;
    float unknown_12c_;
    float unknown_130_;
    float unknown_134_;
    float unknown_138_;
    float unknown_13c_;
    float unknown_140_;
    float unknown_144_;
};

// USA: func_02058d40
extern "C" ARM void func_02058d40(struct Struct_02058d40_10* arg0, struct Struct_020546c8* arg1, Object3D* arg2, unsigned int arg3) {
    arg0->unknown_28_ = arg1;
    arg0->unknown_7c_.Initialize();
    arg2->ShallowCloneTo(&arg0->unknown_7c_);
    arg0->unknown_7c_.SetFlag16();

    struct Struct_02058d40_11* var0 = (struct Struct_02058d40_11*)func_02055108(arg0->unknown_28_);
    if (var0->unknown_3_ != 0) {
        arg0->unknown_c_ = 1;
    } else {
        unsigned char var1 = var0->unknown_0_;
        int var2 = rand();
        float var3 = (float)var1;
        unsigned char var4 = var0->unknown_1_;
        int var5 = var2 % var4;
        float var6 = (float)(-var5) / 100.0f;
        arg0->unknown_8_ = var1 + (int)(var3 * var6);
        arg0->unknown_4_ = 0;
        arg0->unknown_30_ = (float)(unsigned int)arg0->unknown_8_ / (float)var0->unknown_0_;
    }

    struct Struct_02058d40* var7 = (struct Struct_02058d40*)func_02055120(arg0->unknown_28_);
    struct Struct_02058d40_5* var8 = (struct Struct_02058d40_5*)arg0->unknown_28_->unknown_b0_[0].ElementAfter(NULL);
    arg0->unknown_12c_ = (float)(var8->unknown_0_->unknown_4_ & 0x1f);
    arg0->unknown_130_ = (float)((var8->unknown_0_->unknown_4_ & 0x3e0) >> 5);
    arg0->unknown_134_ = (float)((var8->unknown_0_->unknown_4_ & 0x7c00) >> 0xa);

    if (var7->unknown_8_[0] > 1) {
        arg0->unknown_64_ = 1;
        struct Struct_02058d40_5* var9 = (struct Struct_02058d40_5*)arg0->unknown_28_->unknown_b0_[0].GetNthElement(1);
        if (var9 != NULL) {
            unsigned int var10 = (var9->unknown_0_->unknown_4_ & 0x3e0) >> 5;
            unsigned int var11 = (var9->unknown_0_->unknown_4_ & 0x7c00) >> 0xa;
            unsigned int var12 = var9->unknown_0_->unknown_4_ & 0x1f;
            arg0->unknown_34_ = ((float)var12 - arg0->unknown_12c_) /
                             (float)((int)var9->unknown_0_->unknown_0_ - (int)var8->unknown_0_->unknown_0_);
            arg0->unknown_38_ = ((float)var10 - arg0->unknown_130_) /
                             (float)((int)var9->unknown_0_->unknown_0_ - (int)var8->unknown_0_->unknown_0_);
            arg0->unknown_3c_ = ((float)var11 - arg0->unknown_134_) /
                             (float)((int)var9->unknown_0_->unknown_0_ - (int)var8->unknown_0_->unknown_0_);
        }
    }

    struct Struct_02058d40_5* var13 = (struct Struct_02058d40_5*)arg0->unknown_28_->unknown_b0_[1].ElementAfter(NULL);
    arg0->unknown_138_ = (float)var13->unknown_0_->unknown_4_;

    if (var7->unknown_8_[1] > 1) {
        arg0->unknown_66_ = 1;
        struct Struct_02058d40_5* var14 = (struct Struct_02058d40_5*)arg0->unknown_28_->unknown_b0_[1].GetNthElement(1);
        if (var14 != NULL) {
            float var15 = (float)var13->unknown_0_->unknown_0_ * arg0->unknown_30_;
            float var16 = (float)var14->unknown_0_->unknown_0_ * arg0->unknown_30_;
            float var17 = (float)((int)var14->unknown_0_->unknown_4_ - (int)var13->unknown_0_->unknown_4_);
            arg0->unknown_40_ = var17 / (var16 - var15);
        }
    }

    struct Struct_02058d40* var18 = (struct Struct_02058d40*)func_02055138(arg0->unknown_28_);
    struct Struct_02058d40_7* var19 = (struct Struct_02058d40_7*)arg0->unknown_28_->unknown_c8_[0].ElementAfter(NULL);
    struct Struct_02058d40_7* var20 = NULL;
    if (var19 != NULL) {
        unsigned int var21 = 0;
        int var22 = 0;
        goto checkCurveC8Count;
        for (;;) {
            if (var19->unknown_0_->unknown_0_ >= arg3) break;
            var21 = var21 + 1;
            var20 = var19;
            var19 = (struct Struct_02058d40_7*)arg0->unknown_28_->unknown_c8_[0].GetNthElement((unsigned short)var21);
            if (var19 == NULL) break;
            var22 = var22 + 1;
        checkCurveC8Count:
            if (var22 >= var18->unknown_8_[0]) break;
        }

        float var23, var24, var25, var26;
        if (var19 != NULL) {
            if (var20 != NULL) {
                Struct_02058d40_6* var27 = var20->unknown_0_;
                var23 = var27->unknown_4_;
                var24 = var27->unknown_8_;
                int var28 = rand();
                int var29 = (int)var27->unknown_c_;
                int var30 = (int)var27->unknown_c_;
                int var31 = (var28 & (var29 << 1)) - var30;
                float var32 = (float)var31 / 100.0f;

                Struct_02058d40_6* var33 = var19->unknown_0_;
                var25 = var33->unknown_4_;
                var26 = var33->unknown_8_;
                int var34 = rand();
                int var35 = (int)var33->unknown_c_;
                int var36 = (int)var33->unknown_c_;
                int var37 = (var34 & (var35 << 1)) - var36;
                float var38 = (float)var37 / 100.0f;

                int var39 = (int)var20->unknown_0_->unknown_0_;
                int var40 = (int)var33->unknown_0_;
                int var41 = var40 - var39;
                int var42 = (int)(arg3 - (unsigned int)var39);
                float var43 = (float)var42;
                float var44 = (var38 - var32) / (float)var41;
                float var45 = var32 + var43 * var44;

                float var46 = (float)var42;
                float var47 = (var25 - var23) / (float)var41;
                arg0->unknown_50_ = var23 + var46 * var47;

                float var48 = (float)var42;
                float var49 = (var26 - var24) / (float)var41;
                arg0->unknown_54_ = var24 + var48 * var49;

                arg0->unknown_50_ = arg0->unknown_50_ + arg0->unknown_50_ * var45;
                arg0->unknown_54_ = arg0->unknown_54_ + arg0->unknown_54_ * var45;
            } else {
                Struct_02058d40_6* var50 = var19->unknown_0_;
                float var51 = var50->unknown_4_;
                float var52 = var50->unknown_8_;
                int var53 = rand();
                int var54 = (int)var50->unknown_c_;
                int var55 = (int)var50->unknown_c_;
                int var56 = (var53 & (var54 << 1)) - var55;
                float var57 = (float)var56 / 100.0f;
                arg0->unknown_50_ = var51 + var51 * var57;
                arg0->unknown_54_ = var52 + var52 * var57;
            }
        } else {
            Struct_02058d40_6* var58 = var20->unknown_0_;
            float var59 = var58->unknown_4_;
            float var60 = var58->unknown_8_;
            int var61 = rand();
            int var62 = (int)var58->unknown_c_;
            int var63 = (int)var58->unknown_c_;
            int var64 = (var61 & (var62 << 1)) - var63;
            float var65 = (float)var64 / 100.0f;
            arg0->unknown_50_ = var59 + var59 * var65;
            arg0->unknown_54_ = var60 + var60 * var65;
        }
    }

    struct Struct_02058d40_7* var66 = (struct Struct_02058d40_7*)arg0->unknown_28_->unknown_c8_[1].ElementAfter(NULL);
    if (var66 != NULL) {
        Struct_02058d40_6* var67 = var66->unknown_0_;
        int var68 = rand();
        float var69 = ((float)((int)(var67->unknown_c_ * 2.0f) & var68) - var67->unknown_c_) / 100.0f;
        arg0->unknown_13c_ = var67->unknown_4_ + var67->unknown_4_ * var69;
        arg0->unknown_140_ = var66->unknown_0_->unknown_8_ + var66->unknown_0_->unknown_8_ * var69;

        if (var18->unknown_8_[1] > 1) {
            arg0->unknown_68_ = 1;
            struct Struct_02058d40_7* var70 = (struct Struct_02058d40_7*)arg0->unknown_28_->unknown_c8_[1].GetNthElement(1);
            if (var70 != NULL) {
                Struct_02058d40_6* var71 = var70->unknown_0_;
                int var72 = rand();
                int var73 = (int)var71->unknown_c_;
                int var74 = (int)var71->unknown_c_;
                int var75 = (var72 & (var73 << 1)) - var74;
                float var76 = (float)var75 / 100.0f;
                arg0->unknown_58_ = var71->unknown_4_ + var71->unknown_4_ * var76;
                arg0->unknown_5c_ = var70->unknown_0_->unknown_8_ + var70->unknown_0_->unknown_8_ * var76;

                arg0->unknown_44_ = (arg0->unknown_58_ - arg0->unknown_13c_) / (float)((int)var70->unknown_0_->unknown_0_ - (int)var66->unknown_0_->unknown_0_);
                arg0->unknown_48_ = (arg0->unknown_5c_ - arg0->unknown_140_) / (float)((int)var70->unknown_0_->unknown_0_ - (int)var66->unknown_0_->unknown_0_);
            }
        }
    }

    struct Struct_02058d40_3* var77 = (struct Struct_02058d40_3*)func_02055150(arg0->unknown_28_);
    struct SignedAllocatorHeader* var78 = arg0->unknown_28_->unknown_e0_.ElementAfter(NULL);
    {
        int var79 = (rand() & (var77->unknown_2_ << 1)) - var77->unknown_2_;
        float var80 = (float)var79 / 100.0f;
        short var81 = var77->unknown_0_;
        arg0->unknown_144_ = (float)var81 + (float)var81 * var80;
    }
    if (arg0->unknown_144_ < 0.0f) arg0->unknown_144_ += 360.0f;
    if (arg0->unknown_144_ > 360.0f) arg0->unknown_144_ = arg0->unknown_144_ - 360.0f;

    if (var77->unknown_8_ > 1) {
        arg0->unknown_6a_ = 1;
        struct SignedAllocatorHeader* var82 = arg0->unknown_28_->unknown_e0_.GetNthElement(1);
        if (var82 != NULL) {
            struct Struct_02058d40_9* var83 = (struct Struct_02058d40_9*)var82;
            Struct_02058d40_8* var84 = var83->unknown_0_;
            int var85 = rand();
            int var86 = (int)var84->unknown_8_;
            int var87 = (int)var84->unknown_8_;
            int var88 = (var85 & (var86 << 1)) - var87;
            float var89 = (float)var88 / 100.0f;
            arg0->unknown_60_ = var84->unknown_4_ + var84->unknown_4_ * var89;

            struct Struct_02058d40_9* var90 = (struct Struct_02058d40_9*)var78;
            int var91 = var83->unknown_0_->unknown_0_ - var90->unknown_0_->unknown_0_;
            arg0->unknown_4c_ = arg0->unknown_60_ / (float)var91;

            if (arg0->unknown_4c_ < 0.0f) arg0->unknown_4c_ += 360.0f;
            if (arg0->unknown_4c_ > 360.0f) arg0->unknown_4c_ = arg0->unknown_4c_ - 360.0f;
        }
    }

    struct WeatherFlags14* flags2 = (struct WeatherFlags14*)GetSubField0x14_02055108(self->weatherList);
    if (flags2->field_0x4 != 0) {
        self->object.SetAnimationByIndex(0, 0);
    } else {
        self->object.SetAnimationByIndex(0, 1);
    }

    if (var92->unknown_6_ != 0) {
        if (rand() % 2 != 0) {
            arg0->unknown_4c_ = 0.0f - arg0->unknown_4c_;
        }
    }

    struct Struct_02058d40_2* var93 = (struct Struct_02058d40_2*)func_020550d8(arg0->unknown_28_);
    unsigned char var94 = var93->unknown_17_;
    int var95 = rand() % var94;
    float var96 = (float)(100 - var95) * 0.01f;
    arg0->unknown_78_ = arg0->unknown_78_ * var96;
}
