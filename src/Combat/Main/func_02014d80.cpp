#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneObjectResourceLoading.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/NarcHandle.h"

struct Struct_02014d80_2 {
    short unknown_0_, unknown_2_;
    Model3D* unknown_4_;
    Animation3D* unknown_8_[4];
};
struct Struct_02014d80_3 {
    short unknown_0_;
    unsigned char unknown_2_, unknown_3_;
    int unknown_4_;
    Struct_02014d80_3* unknown_8_;
};
struct Struct_0201f368 { unsigned char unknown_0_[0x18]; const char* unknown_18_[8]; unsigned char unknown_38_; };
struct Struct_02014d80_4 { int unknown_0_; Struct_0201f368 unknown_4_; };
struct Struct_02014d80_5 {
    unsigned int unknown_0_;
    char unknown_4_[8];
    Animation3D** unknown_c_;
    int unknown_10_;
};
struct Struct_020e6fa8 { Struct_02014d80_5 unknown_0_[5]; };
#if defined(jpn)
#define data_020e6fa8 data_020e784c
#endif
extern const Struct_020e6fa8 data_020e6fa8;
extern "C" const char* func_0201f368(Struct_0201f368*, int);
extern "C" void func_020e2fc0(RenderCommandHandler*);

// USA: func_02014d80
extern "C" ARM int func_02014d80(Zone3D* zone, void* nodeData, Struct02012ff0* trackerData, Src02015134* recordData) {
    ResourceNode14D* node = (ResourceNode14D*)nodeData;
    ModelTracker14D* tracker = (ModelTracker14D*)trackerData;
    ResourceRecord14D* record = (ResourceRecord14D*)recordData;
    GameState* game = GameState::GetInstance();
    char* tables = (char*)zone->vramState_;
    SafeAllocator* allocator = zone->pAllocator_68_;
    LightingManager* lighting = LightingManager::GetInstance();
    int lightingIndex = lighting->timeOfDayIndex_;
    Zone3D::Model3DListNode* alternate = 0;
    int tinted = ((ZoneLoadState*)GetField0x3f8Address_0200fd0c(game))->unknown20 < 0;
    zone->unknown_834_ = tinted;
    for (ResourceRecord14D* candidate = record->next; candidate; candidate = candidate->next) {
        if (candidate->lightingIndex == lightingIndex) { record = candidate; break; }
    }
    char filename[80];
    unsigned int fileLength;
    FormatFilenameAndSetExtension02014d18(record->id, data_020ef1e8, filename);
    const void* file = GetFileFromNARCInMemory(filename);
    if (file) {
        tracker->model = static_cast<Model3D*>(allocator->Allocate(sizeof(Model3D)));
        void* raw = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, fileLength);
        if (raw && tracker->model) {
            tracker->model->Clear();
            VramState_Restore(tables);
            tracker->model->SetAndProcessRawFile(raw, fileLength, Model3D::TextureStagingMode_Normal);
            VramState_Save(tables);
            NSBXXTex* texture = tracker->model->GetTEX0();
            if (texture) {
                zone->textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                zone->texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
            }
            ModelRenderContext* context = tracker->model->loaded_ ? &tracker->model->renderContext_ : 0;
            if (context) SetModelRenderContextRenderCommandHook(context, CallHandlerFlag0_020e2fc0, 0, 8, 1);
            if (!(record->flags & 0x20) && tinted) lighting->ModelTransformTintBrightnessContrast(tracker->model->rawInternalModel_);
            for (Zone3D::Model3DListNode* model = zone->firstModel_418_; model; model = model->pNext_) {
                tracker->model->ApplyTexturesFromModel(&model->model_);
                tracker->model->SetTEX0(model->model_.GetTEX0());
            }
            Zone3D::Model3DListNode* var18 = arg0->firstModel_418_;
            const char* var19;
            int var20;
            for (var20 = 0; var20 < 8; var20++) {
                if (var2->unknown_3_ & (1 << var20)) {
                    var19 = func_0201f368(&var0->unknown_4_, var20);
                    if (var19) {
                        var8 = var18;
                        while (var8) {
                            if (strstr(var8->filename_, var19)) goto selected;
                            var8 = var8->pNext_;
                        }
                    }
                }
            }
            var8 = 0;
    selected:
            int var21 = 0;
            if (!(var2->unknown_2_ & 1)) var21 |= 1;
            if (var21) var1->unknown_4_->CreateBoneMatrixAndMaterialArrays(var5, var21);
        }
        if (!var1->unknown_4_) { var1->unknown_0_ = -1; return 0; }
    } else { var1->unknown_0_ = -1; return 0; }
    if (var1->unknown_4_) {
        Struct_020e6fa8 var22;
        var22 = data_020e6fa8;
        var22.unknown_0_[0].unknown_c_ = &var1->unknown_8_[3];
        var22.unknown_0_[1].unknown_c_ = &var1->unknown_8_[2];
        var22.unknown_0_[2].unknown_c_ = &var1->unknown_8_[1];
        var22.unknown_0_[3].unknown_c_ = &var1->unknown_8_[0];
        Struct_02014d80_5* var23 = var22.unknown_0_;
        while (var23->unknown_0_) {
            if (var23->unknown_0_ & var2->unknown_2_) {
                func_02014d18(var2->unknown_4_, var23->unknown_4_, var11);
                var13 = GetFileFromNARCInMemory(var11);
                if (var13) {
                    Animation3D* var24 = static_cast<Animation3D*>(var5->Allocate(sizeof(Animation3D)));
                    void* var25 = DecompressLZ77FileIntoAllocatedSpace(*var5, var13, var12);
                    if (var25 && var24) {
                        var24->DefaultInitialize();
                        var24->SetRawFile((NSBXXContainer*)var25);
                        if (var8) {
                            var24->CreateData(var1->unknown_4_, var5, &var8->model_);
                            var1->unknown_4_->AddAnimation(var24);
                            *var23->unknown_c_ = var24;
                        } else {
                            var24->CreateData(var1->unknown_4_, var5, 0);
                            var1->unknown_4_->AddAnimation(var24);
                            *var23->unknown_c_ = var24;
                        }
                    }
                }
            }
            var23++;
        }
    }
    var1->unknown_0_ = 0;
    return 1;
}
