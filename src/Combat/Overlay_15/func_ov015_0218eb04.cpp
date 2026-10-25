#include <globaldefs.h>
#include <std_library_functions.h>
#include "World/Object3D.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"

extern "C" void __clear(void* arg0, unsigned long arg1);

struct Struct_02099d34
{
    unsigned short unknown_0_[10][2];
    unsigned short unknown_28_[8][2];
    unsigned short unknown_48_[8][4];
    unsigned short unknown_88_[8][8];
    unsigned short unknown_108_[8][2];
    unsigned short unknown_128_;
};

struct Struct_ov015_0218c03c_2
{
    char unknown_0_[0x24];
    Object3D* unknown_24_;
    char unknown_28_[0x34 - 0x28];
    unsigned short unknown_34_;
    unsigned short unknown_36_;
};

struct Struct_ov015_02193d9c
{
    int unknown_0_[9];
};

struct Struct_ov015_02193ee8
{
    char unknown_0_[9][0x14];
};

CharacterColors* CharacterColors_GetInstance();
int G3X_SetEdgeColorTable(int a);
ModelRenderContext* GetModel3DContext(Model3D* model);

extern const Struct_ov015_02193ee8 data_ov015_02193ee8;
extern const Struct_ov015_02193d9c data_ov015_02193d9c;

// USA: func_ov015_0218eb04
extern "C" ARM void func_ov015_0218eb04(Struct_ov015_0218c03c_2* arg0)
{
    unsigned short edge = CharacterColors_GetInstance()->edge_;
    unsigned short edges[8] = {edge, edge, edge, edge, edge, edge, edge, edge};
    G3X_SetEdgeColorTable((int)edges);
    self->quads_ = 0;
    self->triangles_ = 0;
    Model3D* model = self->objects_->pModel_;
    if (model == NULL)
        return;
    ModelRenderContext* var3 = GetModel3DContext(var2);
    if (var3 == NULL)
        return;
    Object3D* var4[10];
    __clear(var4, sizeof(var4));
    var4[0] = &arg0->unknown_24_[0];
    var4[1] = &arg0->unknown_24_[2];
    var4[2] = &arg0->unknown_24_[3];
    var4[3] = &arg0->unknown_24_[7];
    var4[4] = &arg0->unknown_24_[8];
    var4[5] = &arg0->unknown_24_[9];
    var4[6] = &arg0->unknown_24_[6];
    var4[7] = &arg0->unknown_24_[5];
    var4[8] = &arg0->unknown_24_[1];
    Struct_ov015_02193ee8 var5 = data_ov015_02193ee8;
    Struct_ov015_02193d9c var6 = data_ov015_02193d9c;
    for (int var7 = 0; var4[var7] != NULL; var7++)
    {
        Object3D* var8 = var4[var7];
        if (var8->unknown_2_ >= 0)
        {
            if (strlen(var5.unknown_0_[var7]) != 0)
            {
                GetModelBonePositionAndDirectionMatrices(var3, NULL, NULL, var2->GetBoneIndex(var5.unknown_0_[var7]));
                var8->EnableFlag(0x4000);
            }
            if (var6.unknown_0_[var7])
                arg0->unknown_24_->ApplyAnimations(var8);
            var8->Draw(true);
        }
    }
}
