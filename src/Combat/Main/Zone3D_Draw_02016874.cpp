#include <globaldefs.h>
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/NSBXX/RenderConfig.h"

struct CombatEntryList;
struct Struct_020ef0dc {
    float unknown0;
    float unknown4;
    float unknown8;
    int unknown_c_;
    float unknown10;
};
extern Struct_020ef0dc data_020ef0dc;
extern "C" void Zone3D_DrawLootables(CombatEntryList*);
extern "C" void Zone3D_DrawChests(Zone3D*);
extern "C" int ZoneId_IsMainGrottoFloor(int);
extern "C" void RenderConfig_SetObjectRotation(void*);
extern "C" void Zone3D_DrawScriptNode(void*, void*);
extern "C" void MI_Copy36B(const void*, void*);

// ActiveGrottoClass::GetActiveGrottoEnviron's values used here (DetailedTreasureMapData::environ_: caves, ruins, ice,
// water, fire as 1-5)
enum { GrottoEnviron_Water = 4, GrottoEnviron_Fire = 5 };

// The RenderConfig flags RenderConfig_SetObjectRotation also clears after a new object rotation
#define OBJECT_ROTATION_CACHE_FLAGS \
    ((1 << RENDER_CONFIG_FLAG_2) | (1 << RENDER_CONFIG_FLAG_5) | (1 << RENDER_CONFIG_FLAG_WORLDVIEW_CACHE_VALID))

// Main, originally func_02016874 (USA 0x02016874, EUR 0x02016884, JPN 0x02016614)
extern "C" ARM void Zone3D_Draw(Zone3D* self) {
    if (self->unknown_424_ != 0) return;
    Zone3D_DrawLootables((CombatEntryList*)self);
    Zone3D_DrawChests(self);
    self->unk_276c[0xb0] = 0;
    data_020ef0dc.unknown_c_ = 1;
    if (ZoneId_IsMainGrottoFloor(self->currentZoneID_)) {
        if (((unsigned char*)self->unk_23bc)[0] == 0) return;
        func_0201aedc(self);
        int environment;
        int minX;
        int z;
        GrottoTileMapRecord* tile;
        int mapWidth;
        environment = self->grotto_.GetActiveGrottoEnviron();
        mapWidth = self->grotto_.floorWidth_;
        GameObject* player = GameState::GetInstance()->GetLeader();
        int var6 = (int)(((float)(player->obj3D_.position_.x + 0x4000) / 4096.0f) / 8.0f);
        int var7 = (int)(((float)(player->obj3D_.position_.z + 0x4000) / 4096.0f) / 8.0f);
        int x;
        int maxX, minZ;
        int maxZ = 1;
        maxZ += var7;
        if (environment == GrottoEnviron_Fire) {
            minX = var6 - 4;
            maxX = var6 + 4;
            minZ = var7 - 4;
        } else {
            minX = var6 - 2;
            maxX = var6 + 2;
            minZ = var7 - 2;
        }
        if (minX < 0) minX = 0;
        if (minZ < 0) minZ = 0;
        maxX++;
        if (maxX > 16) maxX = 16;
        maxZ++;
        if (maxZ > 16) maxZ = 16;
        z = minZ;
        for (; z < maxZ; z++) {
            for (x = minX; x < maxX; x++) {
                tile = &self->grottoTileMapData_420_[z * 16];
                tile = &tile[x];
                if (tile->node == 0) continue;
                BmdjSceneElement* element = tile->node->elements;
                if (element->flags & BmdjElementFlag_Hidden) continue;
                Model3D* model;
                model = element->resource->model;
                if (model == 0 || model->rawInternalModel_ == 0) continue;
                LightingManager* manager = LightingManager::GetInstance();
                manager->ApplyAmbientColorToModel(model->rawInternalModel_);
                MI_Copy36B(&tile->rotation, &data_0210a010.objectRotationPosition);
                data_0210a010.flags &= ~OBJECT_ROTATION_CACHE_FLAGS;
                RenderConfig::SetObjectPosition(&tile->position);
                RenderConfig::SubmitToFifo();
                model->Draw(true);
                if (environment == GrottoEnviron_Water) {
                    model = Zone3D_GetScriptNode(self, 11)->elements->resource->model;
                    NSBXXInternalModel* internal = model->rawInternalModel_;
                    if (model != 0 && internal != 0) {
                        Matrix3x3 identity;
                        Mat3x3_WriteIdentity(&identity);
                        RenderConfig_SetObjectRotation(&identity);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
        if (environment != GrottoEnviron_Fire) return;
        Model3D* model = Zone3D_GetScriptNode(self, 12)->elements->resource->model;
        LightingManager* manager = LightingManager::GetInstance();
        manager->ApplyAmbientColorToModel(model->rawInternalModel_);
        if (var7 < 4) {
            for (int z = var7 - 4; z < var7; z++) {
                if (z < 0) {
                    for (int x = var6 - 4; x < var6 + 5; x++) {
                        Vector3i position;
                        position.x = (int)(4096.0f * (8.0f * (float)x));
                        position.y = 0;
                        position.z = (int)(4096.0f * (8.0f * (float)z));
                        RenderConfig::SetObjectPosition(&position);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
        if (var6 < 4) {
            for (int z = var7 - 4; z < var7 + 2; z++) {
                for (int x = var6 - 4; x < var6; x++) {
                    if (x < 0) {
                        Vector3i position;
                        position.x = (int)(4096.0f * (8.0f * (float)x));
                        position.y = 0;
                        position.z = (int)(4096.0f * (8.0f * (float)z));
                        RenderConfig::SetObjectPosition(&position);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
        if (var6 > mapWidth - 5) {
            for (int z = minZ; z < maxZ; z++) {
                for (int x = var6; x < var6 + 5; x++) {
                    if (x >= mapWidth) {
                        Vector3i position;
                        position.x = (int)(4096.0f * (8.0f * (float)x));
                        position.y = 0;
                        position.z = (int)(4096.0f * (8.0f * (float)z));
                        RenderConfig::SetObjectPosition(&position);
                        RenderConfig::SubmitToFifo();
                        model->Draw(true);
                    }
                }
            }
        }
    } else {
        LightingManager* lighting = LightingManager::GetInstance();
        int timeOfDay = lighting->timeOfDayIndex_;
        if (timeOfDay != (unsigned char)self->unk_830[1]) self->unk_830[2] = 1;
        else self->unk_830[2] = 0;
        self->unk_830[1] = timeOfDay;
        BmdjScriptNode* node = self->firstBMDJStruct_41c_;
        while (node != 0) {
            Zone3D_DrawScriptNode(self, node);
            node = node->next;
        }
        self->unk_830[3] = 0;
    }
}
