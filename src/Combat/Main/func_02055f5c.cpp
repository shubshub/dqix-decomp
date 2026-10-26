#include <globaldefs.h>
#include "NitroSDK/Memory/SignedAllocator.h"

#include "World/Object3D.h"

struct Struct_02055f5c_2;
struct Struct_02055f5c_3;
struct Struct_02055ed0_3;

extern "C" int rand(void);
extern "C" Struct_02055f5c_2* func_02055ed0(Struct_02055f5c_3*);
extern "C" void func_02058d40(Struct_02055f5c_2*, void*, Object3D*, int);
extern "C" void* __clear(void*, unsigned);
extern "C" void MI_Copy36B(const void*, Matrix3x3*);
extern "C" void func_02059720(Particle02055f5c*);

struct Struct_020546c8 {
    unsigned char unknown_0_[0x11c];
    SignedAllocatorList unknown_11c_;
};
extern "C" void* func_02055090(Struct_020546c8*);
extern "C" void* func_020550c0(Struct_020546c8*);
extern "C" void func_02058c88(Struct_02055ed0_3*);

#define ToBamAngle(degF) ((int)(4096.0f * (3.14159274f * ((degF) / 180.0f))))

struct Struct_02055f5c_4 {
    int unknown_0_;
    float unknown_4_, unknown_8_, unknown_c_;
    float unknown_10_, unknown_14_, unknown_18_;
};

struct Struct_02055f5c_5 {
    Struct_02055f5c_4* unknown_0_;
};

struct Struct_02055f5c_6 {
    char unknown_0_[5];
    unsigned char unknown_5_;
};

struct Struct_02055f5c {
    char unknown_0_[0xc];
    unsigned short unknown_c_;
};

struct Struct_02055f5c_2 {
    char unknown_0_[0x10];
    Vector3fix unknown_10_;
    char unknown_1c_[0x2c - 0x1c];
    unsigned char unknown_2c_;
    unsigned char unknown_2d_;
    unsigned char unknown_2e_;
    char unknown_2f_;
    char unknown_30_[0x6c - 0x30];
    float unknown_6c_, unknown_70_, unknown_74_;
    float unknown_78_;
};

struct Struct_02055f5c_3 {
    char unknown_0_[0x4];
    int unknown_4_;
    char unknown_8_[0x2c - 0x8];
    Object3D* unknown_2c_;
    Struct_020546c8* unknown_30_;
    char unknown_34_[0x3a - 0x34];
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    unsigned short unknown_3c_;
    char unknown_3e_[0x40 - 0x3e];
    Vector3fix unknown_40_;
    char unknown_4c_[0x70 - 0x4c];
    float unknown_70_, unknown_74_, unknown_78_, unknown_7c_, unknown_80_, unknown_84_;
    char unknown_88_[0xa8 - 0x88];
    float unknown_a8_;
    char unknown_ac_[0xb0 - 0xac];
    float unknown_b0_, unknown_b4_, unknown_b8_;
    char unknown_bc_[0xe8 - 0xbc];
    unsigned int unknown_e8_[9];
    int unknown_10c_, unknown_110_, unknown_114_;
    float unknown_118_, unknown_11c_, unknown_120_;
    char unknown_124_[4];
    float unknown_128_, unknown_12c_, unknown_130_;
    float unknown_134_, unknown_138_, unknown_13c_;
    float unknown_140_, unknown_144_, unknown_148_;
    float unknown_14c_;
    int unknown_150_;
    char unknown_154_[0x15c - 0x154];
    float unknown_15c_;
    float unknown_160_;
    float unknown_164_, unknown_168_, unknown_16c_;
};

// USA: func_02055f5c
extern "C" ARM void func_02055f5c(struct Struct_02055f5c_3* arg0, int arg1, int arg2) {
    struct Struct_02055f5c* var0 = (struct Struct_02055f5c*)func_02055090(arg0->unknown_30_);

    if (var0->unknown_c_ != 0) {
        if (arg0->unknown_3c_ >= var0->unknown_c_) return;

        struct SignedAllocatorHeader* var1 = arg0->unknown_30_->unknown_11c_.GetNthElement(arg0->unknown_3c_);

        struct Struct_02055f5c_2* var2 = func_02055ed0(arg0);
        if (var2 == 0) return;

        if (arg0->unknown_2c_ != 0 && arg0->unknown_40_.x == 0 && arg0->unknown_40_.y == 0 && arg0->unknown_40_.z == 0) {
            arg0->unknown_40_ = arg0->unknown_2c_->GetScale();
        }

        func_02058c88((struct Struct_02055ed0_3*)var2);

        Vector3fix var3;
        var3.x = (int)((((Struct_02055f5c_5*)var1)->unknown_0_)->unknown_4_ * 4096.0f);
        var3.y = (int)((((Struct_02055f5c_5*)var1)->unknown_0_)->unknown_8_ * 4096.0f);
        var3.z = (int)((((Struct_02055f5c_5*)var1)->unknown_0_)->unknown_c_ * 4096.0f);
        var2->unknown_10_ = var3;

        struct Struct_02055f5c_4* var4 = ((Struct_02055f5c_5*)var1)->unknown_0_;
        int var5 = (int)(var4->unknown_10_ * 4096.0f);
        int var6 = (int)(var4->unknown_14_ * 4096.0f);
        int var7 = (int)(var4->unknown_18_ * 4096.0f);

        Vector3fix var8 = arg0->unknown_40_;
        Vector3fix var9;
        int var10;
        var10 = (int)(((long long)var5 * var8.x + 0x800) >> 12);
        var9.x = var10;
        var10 = (int)(((long long)var6 * var8.y + 0x800) >> 12);
        var9.y = var10;
        var10 = (int)(((long long)var7 * var8.z + 0x800) >> 12);
        var9.z = var10;
        arg0->unknown_2c_->SetScale(&var9);

        func_02058d40(var2, arg0->unknown_30_, arg0->unknown_2c_, arg0->unknown_4_);
        var2->unknown_2c_ = 1;

        arg0->unknown_3c_ = arg0->unknown_3c_ + 1;
        if (arg0->unknown_3c_ >= var0->unknown_c_) return;

        struct SignedAllocatorHeader* var11 = arg0->unknown_30_->unknown_11c_.GetNthElement(arg0->unknown_3c_);
        arg0->unknown_150_ = ((Struct_02055f5c_5*)var11)->unknown_0_->unknown_0_;
        if (arg0->unknown_150_ != 0) return;

        func_02055f5c(arg0, arg1, arg2);
        return;
    }

    Struct_02055f5c_6* var12 = (Struct_02055f5c_6*)func_020550c0(arg0->unknown_30_);
    int var13 = var12->unknown_5_;
    int var14 = rand() % (var13 * 2);
    float var15 = (float)(var14 - var13) / 100.0f;
    int var16 = (int)(arg0->unknown_14c_ * var15);
    int var17 = (int)(arg0->unknown_14c_ + (float)var16);

    int var18;
    int var19;
    Struct_02055f5c_2* var20;
    for (var19 = 0; var19 < arg2; var19++) {
        var18 = 0;

        for (; var18 < var17; var18++) {
            var20 = func_02055ed0(arg0);
            if (var20 == 0) continue;

            func_02058c88((struct Struct_02055ed0_3*)var20);

            int var21 = rand() % 90;
            float var22 = (float)(var21 + 10) / 100.0f;
            int var23 = rand() % 90;
            float var24 = (float)(var23 + 10) / 100.0f;
            int var25 = rand() % 360;

            Vector3fix var26;
            __clear(&var26, 0xc);
            var26.x = (int)(4096.0f * var22);
            int var27 = ToBamAngle((float)var25);

            Matrix4x3 var28;
            var28 = RotationMatrixY(var27);
            Matrix4x3 var29 = var28;
            Mat4x3_ApplyToVector(&var26, &var29, &var26);

            float var30 = arg0->unknown_118_ * arg0->unknown_128_;
            float var31 = arg0->unknown_11c_ * arg0->unknown_12c_;
            float var32 = arg0->unknown_120_ * arg0->unknown_130_;

            float var33 = (float)var26.x;
            float var34 = var33 / 4096.0f;
            float var35 = var34 * var30;
            float var36 = arg0->unknown_140_ + var35;
            float var37 = arg0->unknown_7c_ * (float)arg1;
            float var38 = var37 / (float)(arg2 - var19);
            float var39 = var36;
            var39 += var38;

            float var40 = var24 * var31;
            float var41 = arg0->unknown_144_ + var40;
            float var42 = arg0->unknown_80_ * (float)arg1;
            float var43 = var42 / (float)(arg2 - var19);
            float var44 = var41;
            var44 += var43;

            float var45 = (float)var26.z;
            float var46 = var45 / 4096.0f;
            float var47 = var46 * var32;
            float var48 = arg0->unknown_148_ + var47;
            float var49 = arg0->unknown_84_ * (float)arg1;
            float var50 = var49 / (float)(arg2 - var19);
            float var51 = var48;
            var51 += var50;

            float var52 = var31 / 2.0f;
            float var53 = var44 - var52;

            Vector3fix var54;
            var54.x = (int)(4096.0f * var39) + arg0->unknown_10c_;
            var54.y = (int)(4096.0f * var53) + arg0->unknown_110_;
            var54.z = (int)(4096.0f * var51) + arg0->unknown_114_;
            var20->unknown_10_ = var54;

            float var55 = arg0->unknown_134_ + (arg0->unknown_70_ * (float)arg1) / (float)(arg2 - var19);
            if (var55 < 0.0f) var55 = 360.0f + var55;
            float var56 = arg0->unknown_138_ + (arg0->unknown_74_ * (float)arg1) / (float)(arg2 - var19);
            if (var56 < 0.0f) var56 = 360.0f + var56;
            float var57 = arg0->unknown_13c_ + (arg0->unknown_78_ * (float)arg1) / (float)(arg2 - var19);
            if (var57 < 0.0f) var57 = 360.0f + var57;

            int var58 = ToBamAngle(var55);
            Matrix4x3 var59;
            var59 = RotationMatrixX(var58);
            Matrix4x3 var60 = var59;

            int var61 = ToBamAngle(var56);
            Matrix4x3 var62;
            var62 = RotationMatrixY(var61);
            Matrix4x3 var63 = var62;

            int var64 = ToBamAngle(var57);
            Matrix4x3 var65;
            var65 = RotationMatrixZ(var64);
            Matrix4x3 var66 = var65;

            Mat4x3_Multiply(&var60, &var63, &var60);
            Mat4x3_Multiply(&var60, &var66, &var60);

            Vector3fix var67;
            var67.x = (int)(4096.0f * (arg0->unknown_164_ + (arg0->unknown_b0_ * (float)arg1) / (float)(arg2 - var19)));
            var67.y = (int)(4096.0f * (arg0->unknown_168_ + (arg0->unknown_b4_ * (float)arg1) / (float)(arg2 - var19)));
            var67.z = (int)(4096.0f * (arg0->unknown_16c_ + (arg0->unknown_b8_ * (float)arg1) / (float)(arg2 - var19)));

            Mat4x3_ApplyToVector(&var67, &var60, &var67);

            Matrix3x3 orientMtx;
            Mat3x3_WriteIdentity(&orientMtx);
            MI_Copy36B(self->fieldE8, &orientMtx);
            Mat3x3_ApplyToVector(&velVec, &orientMtx, &velVec);

            Matrix3x3 var69;
            Mat3x3_WriteIdentity(&var69);

            int var70;
            int var71 = (int)arg0->unknown_160_;
            if ((float)var71 >= 1.0f) {
                int var72 = rand() % var71;
                var70 = ToBamAngle((float)var72);
                if (rand() % 2) {
                    var70 -= ToBamAngle((float)var71);
                }
                var70 = fix32ReduceAngle0To2Pi(var70);
                int var73 = fix32cos(var70);
                int var74 = fix32sin(var70);
                Matrix3x3 var75;
                Mat3x3_WriteRotationX(&var75, var74, var73);
                Mat3x3_Multiply(&var69, &var75, &var69);

                int var76 = rand() % var71;
                var70 = ToBamAngle((float)var76);
                if (rand() % 2) {
                    var70 -= ToBamAngle((float)var71);
                }
                var70 = fix32ReduceAngle0To2Pi(var70);
                int var77 = fix32cos(var70);
                int var78 = fix32sin(var70);
                Matrix3x3 var79;
                Mat3x3_WriteRotationY(&var79, var78, var77);
                Mat3x3_Multiply(&var69, &var79, &var69);

                int var80 = rand() % var71;
                var70 = ToBamAngle((float)var80);
                if (rand() % 2) {
                    var70 -= ToBamAngle((float)var71);
                }
                var70 = fix32ReduceAngle0To2Pi(var70);
                int var81 = fix32cos(var70);
                int var82 = fix32sin(var70);
                Matrix3x3 var83;
                Mat3x3_WriteRotationZ(&var83, var82, var81);
                Mat3x3_Multiply(&var69, &var83, &var69);

                Mat3x3_ApplyToVector(&var67, &var69, &var67);
            }

            float var84 = (float)var67.z / 4096.0f;
            float var85 = (float)var67.y / 4096.0f;
            float var86 = (float)var67.x / 4096.0f;
            var20->unknown_6c_ = var86;
            var20->unknown_70_ = var85;
            var20->unknown_74_ = var84;

            var20->unknown_78_ = arg0->unknown_15c_ + (arg0->unknown_a8_ * (float)arg1) / (float)(arg2 - var19);

            if (arg0->unknown_3a_ != 0) {
                var20->unknown_2d_ = 1;
            } else if (arg0->unknown_3b_ != 0) {
                var20->unknown_2e_ = 1;
            }

            func_02058d40(var20, arg0->unknown_30_, arg0->unknown_2c_, arg0->unknown_4_);
            var20->unknown_2c_ = 1;

            for (int var87 = 0; var87 < var19; var87++) {
                func_02059720(var20);
            }
        }
    }
}
