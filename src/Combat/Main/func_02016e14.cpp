#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "Graphics/Model3D.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Graphics/Vector.h"
#include "NitroSDK/Matrix.h"
#include "NitroSDK/Graphics.h"
#include "World/Object3D.h"

struct Struct_02016e14_2 { unsigned char unknown_0_; unsigned char unknown_1_; };

struct Struct_02016e14_3 { char unknown_0_[0xc]; unsigned char unknown_c_0_ : 4; unsigned char unknown_c_4_ : 4; };

struct Struct_02016e14_4 { short unknown_0_; short unknown_2_; Model3D* unknown_4_; };

struct Struct_02016e14_5 { short unknown_0_; short unknown_2_; short unknown_4_; unsigned short unknown_6_; };

struct Struct_02016e14_6 {
    char unknown_0_[0x8];
    struct Struct_02016e14_3* unknown_8_;
#if defined(jpn)
    char unknown_c_[0x852 - 0xc];
#else
    char unknown1_c_[0x832 - 0xc];
#endif
    unsigned char unknown_832_;
    unsigned char unknown_833_;
#if defined(jpn)
    char unknown_854_[0x281c - 0x854];
#else
    char unknown_834_[0x27dc - 0x834];
#endif
    struct Struct_02016e14_2 unknown_27dc_[0x20];
    unsigned char unknown_281c_;
};

struct Struct_02016e14 {
    unsigned short unknown_0_;
    unsigned short unknown_2_;
    signed char unknown_4_0_ : 7;
    signed char unknown_4_7_ : 1;
    char unknown_5_;
    short unknown_6_;
    Vector3i unknown_8_;
    Vector3i unknown_14_;
    struct Struct_02016e14_5* unknown_20_;
    struct Struct_02016e14_4* unknown_24_;
    char unknown_28_[0x4];
    struct Struct_02016e14* unknown_2c_;
    struct Struct_02016e14* unknown_30_;
    char unknown_34_[0x4];
    short unknown_38_;
    char unknown_3a_[0x54 - 0x3a];
    Object3D* unknown_54_;
};

void RenderConfig_SetObjectRotation(void* arg0);
extern "C" void Mat3x3_WriteRotationY(Matrix3x3* out, int sine, int cosine);

// USA: func_02016e14
extern "C" ARM void func_02016e14(struct Struct_02016e14_6* arg0, void* arg1, struct Struct_02016e14* arg2, int arg3) {
    GameState::GetInstance();
    LightingManager* var0 = LightingManager::GetInstance();
    struct Struct_02016e14_4* var1 = arg2->unknown_24_;
    struct Struct_02016e14_5* var2 = arg2->unknown_20_;
    int var3 = var0->timeOfDayIndex_;

    if ((arg0->unknown_832_ != 0 || arg0->unknown_833_ != 0) && arg0->unknown_8_ != NULL) {
        unsigned int var4 = arg0->unknown_8_->unknown_c_0_;
        if (var4 == 0 || var4 == 7 || arg0->unknown_833_ != 0) {
            if (!(var2->unknown_6_ & 0x10)) {
                if (var2->unknown_6_ & (1 << var3)) {
                    arg2->unknown_2_ &= ~4;
                } else {
                    arg2->unknown_2_ |= 4;
                }
            }
        }
    }

    GXFIFO_DIFFUSE_AMBIENT = 0x7fff7fff;

    Model3D* var5 = NULL;
    Object3D* var6 = NULL;
    int var7 = 0;
    if (arg3 == 0 && !(arg2->unknown_2_ & 4) && var1 != NULL) {
        if (var1->unknown_0_ == 0) {
            var5 = var1->unknown_4_;
        } else if (var1->unknown_0_ == 2) {
            var6 = arg2->unknown_54_;
            if (var6 != NULL) {
                var5 = var6->pModel_;
            }
        }
    }

    if (var5 != NULL) {
        RenderConfig::SetObjectPosition(&arg2->unknown_8_);

        int var8 = arg2->unknown_6_;
        if (arg2->unknown_38_ != 0) {
            var8 = fix32ReduceAngle0To2Pi(var8 + arg2->unknown_38_);
        }
        fix32_t cosine = fix32cos(angle);
        fix32_t sine = fix32sin(angle);
        Matrix3x3 rotation;
        Mat3x3_WriteRotationY(&rotation, sine, cosine);
        RenderConfig_SetObjectRotation(&rotation);

        Vector3i var12;
        var12.x = arg2->unknown_14_.x;
        var12.y = arg2->unknown_14_.y;
        var12.z = arg2->unknown_14_.z;
        RenderConfig::SetObjectScale(&var12);

        if ((arg2->unknown_2_ & 8) || arg2->unknown_4_7_ != 0) {
            var5->SetAlpha(arg2->unknown_4_0_);
        }

        if (var5->rawInternalModel_ != NULL) {
            LightingManager* var13 = LightingManager::GetInstance();
            var13->ApplyAmbientColorToModel(var5->rawInternalModel_);

            int var14 = 0;
            if (var1->unknown_0_ == 0) {
                RenderConfig::SubmitToFifo();
                var14 = var5->Draw(true);
            } else if (var1->unknown_0_ == 2) {
                var6->AdvanceEffects();
                var14 = var6->DrawSimple(true);
            }

            if (var14) {
                arg0->unknown_27dc_[arg0->unknown_281c_].unknown_0_ = (unsigned char)var2->unknown_2_;
                arg0->unknown_27dc_[arg0->unknown_281c_].unknown_1_ = (unsigned char)*(int*)arg1;
                arg0->unknown_281c_++;
            }
        }
    } else {
        var7 = 1;
    }
    if (arg2->unknown_2c_ != NULL) {
        func_02016e14(arg0, arg1, arg2->unknown_2c_, var7);
    }
    if (arg2->unknown_30_ != NULL) {
        func_02016e14(arg0, arg1, arg2->unknown_30_, arg3);
    }
}
