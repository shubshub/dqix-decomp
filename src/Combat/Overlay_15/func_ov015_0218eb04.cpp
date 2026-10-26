#include <globaldefs.h>
#include <std_library_functions.h>
#include "World/Object3D.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"

extern "C" void __clear(void* buffer, unsigned long size);

struct CharacterColors
{
    unsigned short unknown_0_[10][2];
    unsigned short unknown_28_[8][2];
    unsigned short unknown_48_[8][4];
    unsigned short unknown_88_[8][8];
    unsigned short unknown_108_[8][2];
    unsigned short edge_;
};

struct Struct_ov015_0218c03c_2
{
    char unk_0[0x24];
    Object3D* objects_;
    char unk_28[0x34 - 0x28];
    unsigned short unknown_34_;
    unsigned short unknown_36_;
};

struct Struct_ov015_02193d9c
{
    int unknown_0_[9];
};

struct Struct_ov015_02193ee8
{
    char names_[9][0x14];
};

extern "C" CharacterColors* CharacterColors_GetInstance();
extern "C" int G3X_SetEdgeColorTable(int a);
ModelRenderContext* GetModel3DContext(Model3D* model);

extern const Struct_ov015_02193ee8 data_ov015_02193ee8;
extern const Struct_ov015_02193d9c data_ov015_02193d9c;

// USA: func_ov015_0218eb04
extern "C" ARM void func_ov015_0218eb04(Struct_ov015_0218c03c_2* self)
{
    unsigned short edge = CharacterColors_GetInstance()->edge_;
    unsigned short edges[8] = {edge, edge, edge, edge, edge, edge, edge, edge};
    G3X_SetEdgeColorTable((int)edges);
    self->unknown_36_ = 0;
    self->unknown_34_ = 0;
    Model3D* model = self->objects_->pModel_;
    if (model == NULL)
        return;
    ModelRenderContext* context = GetModel3DContext(model);
    if (context == NULL)
        return;
    Object3D* parts[10];
    __clear(parts, sizeof(parts));
    parts[0] = &self->objects_[0];
    parts[1] = &self->objects_[2];
    parts[2] = &self->objects_[3];
    parts[3] = &self->objects_[7];
    parts[4] = &self->objects_[8];
    parts[5] = &self->objects_[9];
    parts[6] = &self->objects_[6];
    parts[7] = &self->objects_[5];
    parts[8] = &self->objects_[1];
    Struct_ov015_02193ee8 var5 = data_ov015_02193ee8;
    Struct_ov015_02193d9c var6 = data_ov015_02193d9c;
    for (int i = 0; parts[i] != NULL; i++)
    {
        Object3D* part = parts[i];
        if (part->unknown_2_ >= 0)
        {
            if (strlen(var5.names_[i]) != 0)
            {
                GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, model->GetBoneIndex(var5.names_[i]));
                part->EnableFlag(0x4000);
            }
            if (var6.unknown_0_[i])
                self->objects_->ApplyAnimations(part);
            part->Draw(true);
        }
    }
}
