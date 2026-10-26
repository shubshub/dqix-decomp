#include "World/ZoneObjectResourceLoading.h"
#include <globaldefs.h>

// Main, originally func_020151cc (USA 0x020151cc, EUR 0x020151dc, JPN 0x02014f98)
extern "C" ARM int Zone3D_LoadElementObject(Zone3D *zone, Struct02012ff0 *tracker, Src02015134 *source) {
    GameState *gameState      = GameState::GetInstance();
    SafeAllocator *allocator  = zone->pAllocator_68_;
    char *pairTables          = static_cast<char *>(zone->vramState_);
    LightingManager *lighting = LightingManager::GetInstance();
    int applyLighting         = static_cast<ZoneLoadState *>(GameState_GetZoneTransition(gameState))->unknown20 < 0;
    zone->unknown_834_        = applyLighting;
    char filename[0x50];
    unsigned int size;
    Zone3D_FormatElementFilePath(source->id, data_020ef1e8, filename);
    const void *file = GetFileFromNARCInMemory(filename);
    Object3D *object;
    if (file != NULL) {
        tracker->field4    = static_cast<Object3D*>(allocator->Allocate(sizeof(Object3D)));
        void *decompressed = DecompressLZ77FileIntoAllocatedSpace(*allocator, file, size);
        if (decompressed != NULL && tracker->field4 != 0) {
            Object3D *object = tracker->field4;
            object->Initialize();
            VramState_Restore(pairTables);
            object = tracker->field4;
            object->SetModelFromFile(allocator, decompressed, size, Model3D::TextureStagingMode_Normal);
            VramState_Save(pairTables);
            Model3D *model = tracker->field4->pModel_;
            if (model != NULL) {
                NSBXXTex *texture = model->GetTEX0();
                if (texture != NULL) {
                    zone->textureImageMemory_ += NSBXX_Tex_GetBlock1Length(texture);
                    zone->texturePaletteMemory_ += NSBXX_Tex_GetBlock4Length(texture);
                }
                if (!(static_cast<unsigned char>(source->pad[2]) & 0x20) && applyLighting) {
                    lighting->ModelTransformTintBrightnessContrast(model->rawInternalModel_);
                }
                for (Zone3D::Model3DListNode *node = zone->firstModel_418_; node != NULL; node = node->pNext_) {
                    model->ApplyTexturesFromModel(&node->model_);
                    model->SetTEX0(node->model_.GetTEX0());
                }
            }
        }
        object = tracker->field4;
        if (object == NULL || object->pModel_ == NULL) {
            tracker->field0 = -1;
            return 0;
        }
    } else {
        tracker->field0 = -1;
        return 0;
    }
    if (object != NULL) {
        Struct_020e6f48 resources = data_020e6f48;
        for (Struct_020151cc *resource = resources.entries; resource->mask != 0; resource++) {
            if (resource->mask & static_cast<unsigned char>(source->pad[2])) {
                Zone3D_FormatElementFilePath(source->id, resource->extension, filename);
                const void *var16 = GetFileFromNARCInMemory(filename);
                if (var16 != NULL) {
                    void *var17 = DecompressLZ77FileIntoAllocatedSpace(*allocator, var16, size);
                    if (var17 != NULL) {
                        if (resource->slot < 0) {
                            object->LoadType0AnimationPackageFromBCFGScript(allocator, var17, size);
                        } else {
                            object->LoadType0AnimationFromPersistentMemory(resource->slot, allocator, var17, size);
                        }
                    }
                }
            }
        }
    }
    tracker->field0 = 2;
    return 1;
}
