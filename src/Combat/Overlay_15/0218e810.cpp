#include <globaldefs.h>
#include "World/Object3D.h"
#include "Combat/Overlay15ViewerContext.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/Graphics.h"

ModelRenderContext* GetModel3DContext(Model3D* model);
extern "C" void G3_RotateY(int angle);

struct Struct_ov015_0218e810
{
    char* viewer_;
    Struct_ov015_0218bcb0_2* slot_;
    SafeAllocator* allocators_;
    const char* name_;
    void* unknown_10_;
    void* buffer_;
    unsigned int bufferSize_;
    unsigned char kind_;
    char unknown_1d_[3];
    int* parts_;
    Object3D* objects_;
    Struct205563c* effect_;
    char unknown_2c_[8];
    unsigned short unknown_34_;
    unsigned short unknown_36_;
    short motion_;
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
    int object_;
    int unknown_4_;
};

struct Struct_ov015_02193dc0
{
    Struct_ov015_0218e810_2 entries_[6];
};

extern const Struct_ov015_02193dc0 data_ov015_02193dc0;
extern const char data_ov015_0219416b[];
extern const char data_ov015_021940e7[];
extern const char data_ov015_021940e1[];
extern const char data_ov015_02194170[];
extern const char data_ov015_02194176[];

// USA: func_ov015_0218e810
extern "C" ARM void func_ov015_0218e810(void* object)
{
    int head;
    ModelRenderContext* context;
    int var2;
    int var3;
    Model3D* model;
    Object3D* root;
    Struct_ov015_0218e810* self;
    self = (Struct_ov015_0218e810*)object;
    self->unknown_34_ = self->unknown_36_ = 0;
    root = self->objects_;
    model = self->objects_->pModel_;
    if (model == NULL)
        return;
    context = GetModel3DContext(model);
    if (context == NULL)
        return;
    GXFIFO_MATRIX_PUSH = 0;
    root->Draw(true);
    if (root->pModel_ != NULL && root->pModel_->rawInternalModel_ != NULL)
    {
        self->unknown_34_ += root->pModel_->rawInternalModel_->numTriangles_;
        self->unknown_36_ += root->pModel_->rawInternalModel_->numQuads_;
    }
    GXFIFO_MATRIX_POP = 1;
    head = model->GetBoneIndex(data_ov015_0219416b);
    var2 = model->GetBoneIndex(data_ov015_021940e7);
    var3 = model->GetBoneIndex(data_ov015_021940e1);
    model->GetBoneIndex(data_ov015_02194170);
    model->GetBoneIndex(data_ov015_02194176);
    Struct_ov015_02193dc0 bindings = data_ov015_02193dc0;
    bindings.entries_[0].unknown_4_ = head;
    bindings.entries_[1].unknown_4_ = head;
    bindings.entries_[2].unknown_4_ = head;
    bindings.entries_[3].unknown_4_ = var2;
    bindings.entries_[4].unknown_4_ = var3;
    for (Struct_ov015_0218e810_2* var8 = bindings.entries_; var8->object_ >= 0; var8++)
    {
        Object3D* part = &self->objects_[var8->object_];
        int bone = var8->unknown_4_;
        if (part->unknown_2_ >= 0)
        {
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, bone);
            GXFIFO_MATRIX_PUSH = 0;
            part->DrawWithComposedTransform(false);
            if (part->pModel_ != NULL && part->pModel_->rawInternalModel_ != NULL)
            {
                self->unknown_34_ += part->pModel_->rawInternalModel_->numTriangles_;
                self->unknown_36_ += part->pModel_->rawInternalModel_->numQuads_;
            }
            GXFIFO_MATRIX_POP = 1;
        }
    }
    if (self->unknown_54_ != 0)
    {
        Object3D* part = &self->objects_[8];
        if (part->unknown_2_ >= 0)
        {
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, var2);
            GXFIFO_MATRIX_PUSH = 0;
            G3_RotateY(0x3244);
            part->DrawInCurrentMatrix(false);
            if (part->pModel_ != NULL && part->pModel_->rawInternalModel_ != NULL)
            {
                self->unknown_34_ += part->pModel_->rawInternalModel_->numTriangles_;
                self->unknown_36_ += part->pModel_->rawInternalModel_->numQuads_;
            }
            GXFIFO_MATRIX_POP = 1;
        }
    }
    GXFIFO_MATRIX_PUSH = 0;
    if (root[1].unknown_2_ >= 0)
    {
        root->ApplyAnimations(&root[1]);
        root[1].Draw(false);
        if (root[1].pModel_ != NULL && root[1].pModel_->rawInternalModel_ != NULL)
        {
            self->unknown_34_ += root->pModel_->rawInternalModel_->numTriangles_;
            self->unknown_36_ += root->pModel_->rawInternalModel_->numQuads_;
        }
    }
    GXFIFO_MATRIX_POP = 1;
}
