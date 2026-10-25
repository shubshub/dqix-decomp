#include <globaldefs.h>
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/Graphics.h"

ModelRenderContext* GetModel3DContext(Model3D* model);
extern "C" void G3_RotateY(int angle);

struct Struct_ov015_0218e810
{
    char* unknown_0_;
    Struct_ov015_0218bcb0_2* unknown_4_;
    SafeAllocator* unknown_8_;
    const char* unknown_c_;
    void* unknown_10_;
    void* unknown_14_;
    unsigned int unknown_18_;
    unsigned char unknown_1c_;
    char unknown_1d_[3];
    int* unknown_20_;
    Object3D* unknown_24_;
    Struct_0205563c* unknown_28_;
    char unknown_2c_[8];
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    short unknown_38_;
    unsigned char unknown_3a_;
    unsigned char unknown_3b_;
    char unknown_3c_[0xc];
    int unknown_48_;
    char unknown_4c_[8];
    int unknown_54_;
    char unknown_58_[4];
};

struct Struct_ov015_0218e810_2
{
    int unknown_0_;
    int unknown_4_;
};

struct Struct_ov015_02193dc0
{
    Struct_ov015_0218e810_2 unknown_0_[6];
};

extern const Struct_ov015_02193dc0 data_ov015_02193dc0;
extern const char data_ov015_0219416b[];
extern const char data_ov015_021940e7[];
extern const char data_ov015_021940e1[];
extern const char data_ov015_02194170[];
extern const char data_ov015_02194176[];

// USA: func_ov015_0218e810
extern "C" ARM void func_ov015_0218e810(void* arg0)
{
    int var0;
    ModelRenderContext* var1;
    int var2;
    int var3;
    Model3D* var4;
    Object3D* var5;
    Struct_ov015_0218e810* var6;
    var6 = (Struct_ov015_0218e810*)arg0;
    var6->unknown_34_ = var6->unknown_36_ = 0;
    var5 = var6->unknown_24_;
    var4 = var6->unknown_24_->pModel_;
    if (var4 == NULL)
        return;
    var1 = GetModel3DContext(var4);
    if (var1 == NULL)
        return;
    GXFIFO_MATRIX_PUSH = 0;
    var5->Draw(true);
    if (var5->pModel_ != NULL && var5->pModel_->rawInternalModel_ != NULL)
    {
        var6->unknown_34_ += var5->pModel_->rawInternalModel_->numTriangles_;
        var6->unknown_36_ += var5->pModel_->rawInternalModel_->numQuads_;
    }
    GXFIFO_MATRIX_POP = 1;
    var0 = var4->GetBoneIndex(data_ov015_0219416b);
    var2 = var4->GetBoneIndex(data_ov015_021940e7);
    var3 = var4->GetBoneIndex(data_ov015_021940e1);
    var4->GetBoneIndex(data_ov015_02194170);
    var4->GetBoneIndex(data_ov015_02194176);
    Struct_ov015_02193dc0 var7 = data_ov015_02193dc0;
    var7.unknown_0_[0].unknown_4_ = var0;
    var7.unknown_0_[1].unknown_4_ = var0;
    var7.unknown_0_[2].unknown_4_ = var0;
    var7.unknown_0_[3].unknown_4_ = var2;
    var7.unknown_0_[4].unknown_4_ = var3;
    for (Struct_ov015_0218e810_2* var8 = var7.unknown_0_; var8->unknown_0_ >= 0; var8++)
    {
        Object3D* var9 = &var6->unknown_24_[var8->unknown_0_];
        int var10 = var8->unknown_4_;
        if (var9->unknown_2_ >= 0)
        {
            GetModelBonePositionAndDirectionMatrices(var1, NULL, NULL, var10);
            GXFIFO_MATRIX_PUSH = 0;
            var9->DrawSimple3(false);
            if (var9->pModel_ != NULL && var9->pModel_->rawInternalModel_ != NULL)
            {
                var6->unknown_34_ += var9->pModel_->rawInternalModel_->numTriangles_;
                var6->unknown_36_ += var9->pModel_->rawInternalModel_->numQuads_;
            }
            GXFIFO_MATRIX_POP = 1;
        }
    }
    if (var6->unknown_54_ != 0)
    {
        Object3D* var11 = &var6->unknown_24_[8];
        if (var11->unknown_2_ >= 0)
        {
            GetModelBonePositionAndDirectionMatrices(var1, NULL, NULL, var2);
            GXFIFO_MATRIX_PUSH = 0;
            G3_RotateY(0x3244);
            part->DrawSimple2(false);
            if (part->pModel_ != NULL && part->pModel_->rawInternalModel_ != NULL)
            {
                var6->unknown_34_ += var11->pModel_->rawInternalModel_->numTriangles_;
                var6->unknown_36_ += var11->pModel_->rawInternalModel_->numQuads_;
            }
            GXFIFO_MATRIX_POP = 1;
        }
    }
    GXFIFO_MATRIX_PUSH = 0;
    if (var5[1].unknown_2_ >= 0)
    {
        var5->ApplyAnimations(&var5[1]);
        var5[1].Draw(false);
        if (var5[1].pModel_ != NULL && var5[1].pModel_->rawInternalModel_ != NULL)
        {
            var6->unknown_34_ += var5->pModel_->rawInternalModel_->numTriangles_;
            var6->unknown_36_ += var5->pModel_->rawInternalModel_->numQuads_;
        }
    }
    GXFIFO_MATRIX_POP = 1;
}
