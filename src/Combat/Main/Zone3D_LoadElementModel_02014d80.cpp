#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "World/ZoneObjectResourceLoading.h"
#include "Filesystem/FileIO.h"
#include "NitroSDK/Filesystem/NarcHandle.h"

// The element's BmdjElementResource (this file's copy): kind 0 (a model) once loaded, -1 if it failed
struct Struct_02014d80_2 {
    short kind, field2;
    Model3D* model;
    Animation3D* animations[4];     // nsbtp, nsbta, nsbma, nsbca (data_020e6fa8's entries in reverse)
};
// One of the script node's resource records; next links the variants for other times of day
struct Struct_02014d80_3 {
    short timeOfDay;                // LightingManager::timeOfDayIndex_ this variant is for
    unsigned char flags, textureMask; // flags: data_020e6fa8's animation masks, 0x20 not tinted
    int name;                       // the file name (Zone3D_FormatElementFilePath prints it with %s)
    Struct_02014d80_3* next;
};
struct Container_1f368 { unsigned char padding[0x18]; const char* entries[8]; unsigned char count; };
struct Struct_02014d80_4 { int field0; Container_1f368 names; };
struct Struct_02014d80_5 {
    unsigned int mask;
    char extension[8];
    Animation3D** destination;
    int field10;
};
struct AnimationTable14D { Struct_02014d80_5 entries[5]; };
#if defined(jpn)
#define data_020e6fa8 data_020e784c
#endif
extern const AnimationTable14D data_020e6fa8;  // ROM: masks 1 nsbca, 2 nsbma, 4 nsbta, 8 nsbtp
extern "C" const char* BmdjScriptState_GetTextureName(Container_1f368*, int);
extern "C" void func_020e2fc0(RenderCommandHandler*);

// Main, originally func_02014d80 (USA 0x02014d80, EUR 0x02014d90, JPN 0x02014b4c)
extern "C" ARM int Zone3D_LoadElementModel(Zone3D* zone, void* nodeData, Struct02012ff0* trackerData, Src02015134* recordData) {
    Struct_02014d80_4* node = (Struct_02014d80_4*)nodeData;
    Struct_02014d80_2* tracker = (Struct_02014d80_2*)trackerData;
    Struct_02014d80_3* record = (Struct_02014d80_3*)recordData;
    GameState* game = GameState::GetInstance();
    char* tables = (char*)zone->vramState_;
    SafeAllocator* allocator = zone->pAllocator_68_;
    LightingManager* lighting = LightingManager::GetInstance();
    int timeOfDay = lighting->timeOfDayIndex_;
    Zone3D::Model3DListNode* alternate = 0;
    int tinted = ((ZoneLoadState*)GameState_GetZoneTransition(game))->unknown20 < 0;
    zone->unknown_834_ = tinted;
    for (Struct_02014d80_3* candidate = record->next; candidate; candidate = candidate->next) {
        if (candidate->timeOfDay == timeOfDay) { record = candidate; break; }
    }
    char filename[80];
    unsigned int fileLength;
    Zone3D_FormatElementFilePath(record->name, data_020ef1e8, filename);  // "nsbmd"
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
            if (context) SetModelRenderContextRenderCommandHook(context, func_020e2fc0, 0, 8, 1);
            if (!(record->flags & 0x20) && tinted) lighting->ModelTransformTintBrightnessContrast(tracker->model->rawInternalModel_);
            for (Zone3D::Model3DListNode* model = zone->firstModel_418_; model; model = model->pNext_) {
                tracker->model->ApplyTexturesFromModel(&model->model_);
                tracker->model->SetTEX0(model->model_.GetTEX0());
            }
            Zone3D::Model3DListNode* first = zone->firstModel_418_;
            const char* name;
            int index;
            for (index = 0; index < 8; index++) {
                if (record->textureMask & (1 << index)) {
                    name = BmdjScriptState_GetTextureName(&node->names, index);
                    if (name) {
                        alternate = first;
                        while (alternate) {
                            if (strstr(alternate->filename_, name)) goto selected;
                            alternate = alternate->pNext_;
                        }
                    }
                }
            }
            alternate = 0;
    selected:
            int flags = 0;
            if (!(record->flags & 1)) flags |= 1;
            if (flags) tracker->model->CreateBoneMatrixAndMaterialArrays(allocator, flags);
        }
        if (!tracker->model) { tracker->kind = -1; return 0; }
    } else { tracker->kind = -1; return 0; }
    if (tracker->model) {
        AnimationTable14D animations;
        animations = data_020e6fa8;
        animations.entries[0].destination = &tracker->animations[3];
        animations.entries[1].destination = &tracker->animations[2];
        animations.entries[2].destination = &tracker->animations[1];
        animations.entries[3].destination = &tracker->animations[0];
        Struct_02014d80_5* entry = animations.entries;
        while (entry->mask) {
            if (entry->mask & record->flags) {
                Zone3D_FormatElementFilePath(record->name, entry->extension, filename);
                file = GetFileFromNARCInMemory(filename);
                if (file) {
                    Animation3D* animation = static_cast<Animation3D*>(allocator->Allocate(sizeof(Animation3D)));
                    void* var25 = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, fileLength);
                    if (var25 && animation) {
                        animation->DefaultInitialize();
                        animation->SetRawFile((NSBXXContainer*)var25);
                        if (alternate) {
                            animation->CreateData(tracker->model, allocator, &alternate->model_);
                            tracker->model->AddAnimation(animation);
                            *entry->destination = animation;
                        } else {
                            animation->CreateData(tracker->model, allocator, 0);
                            tracker->model->AddAnimation(animation);
                            *entry->destination = animation;
                        }
                    }
                }
            }
            entry++;
        }
    }
    tracker->kind = 0;
    return 1;
}
