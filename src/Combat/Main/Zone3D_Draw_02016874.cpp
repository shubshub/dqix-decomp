#include <globaldefs.h>
#include "World/Zone3D.h"
#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/NSBXX/RenderConfig.h"

struct Struct_02016874_3;
struct Struct_020ef0dc {
    float unknown_0_;
    float unknown_4_;
    float unknown_8_;
    int unknown_c_;
    float unknown_10_;
};
extern RenderFlags02016874 data_020ef0dc;
extern "C" void Zone3D_DrawLootables(CombatEntryList*);
extern "C" void Zone3D_DrawChests(Zone3D*);
int ZoneId_IsMainGrottoFloor(int);
void RenderConfig_SetObjectRotation(void*);
void Zone3D_DrawScriptNode(void*, void*);
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
    data_020ef0dc.normalPending = 1;
    if (ZoneId_IsMainGrottoFloor(self->currentZoneID_)) {
        if (((unsigned char*)self->unk_23bc)[0] == 0) return;
        ProcessNode0201aedc(self);
        int environment;
        int minX;
        int z;
        GrottoTileMapRecord* tile;
        int mapWidth;
        environment = self->grotto_.GetActiveGrottoEnviron();
        mapWidth = self->grotto_.floorWidth_;
        GameObject* player = GameState::GetInstance()->GetLeader();
        int playerX = (int)(((float)(player->obj3D_.position_.x + 0x4000) / 4096.0f) / 8.0f);
        int playerZ = (int)(((float)(player->obj3D_.position_.z + 0x4000) / 4096.0f) / 8.0f);
        int x;
        int maxX, minZ;
        int maxZ = 1;
        maxZ += playerZ;
        if (environment == GrottoEnviron_Fire) {
            minX = playerX - 4;
            maxX = playerX + 4;
            minZ = playerZ - 4;
        } else {
            var1 = var6 - 2;
            var9 = var6 + 2;
            var10 = var7 - 2;
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
                        var13->Draw(true);
                    }
                }
            }
        }
        if (environment != GrottoEnviron_Fire) return;
        Model3D* model = Zone3D_GetScriptNode(self, 12)->elements->resource->model;
        LightingManager* manager = LightingManager::GetInstance();
        manager->ApplyAmbientColorToModel(model->rawInternalModel_);
        if (playerZ < 4) {
            for (int z = playerZ - 4; z < playerZ; z++) {
                if (z < 0) {
                    for (int x = playerX - 4; x < playerX + 5; x++) {
                        Vector3i position;
                        position.x = (int)(4096.0f * (8.0f * (float)x));
                        position.y = 0;
                        position.z = (int)(4096.0f * (8.0f * (float)z));
                        RenderConfig::SetObjectPosition(&position);
                        RenderConfig::SubmitToFifo();
                        var17->Draw(true);
                    }
                }
            }
        }
        if (var6 < 4) {
            for (int var22 = var7 - 4; var22 < var7 + 2; var22++) {
                for (int var23 = var6 - 4; var23 < var6; var23++) {
                    if (var23 < 0) {
                        Vector3i var24;
                        var24.x = (int)(4096.0f * (8.0f * (float)var23));
                        var24.y = 0;
                        var24.z = (int)(4096.0f * (8.0f * (float)var22));
                        RenderConfig::SetObjectPosition(&var24);
                        RenderConfig::SubmitToFifo();
                        var17->Draw(true);
                    }
                }
            }
        }
        if (var6 > var4 - 5) {
            for (int var25 = var10; var25 < var11; var25++) {
                for (int var26 = var6; var26 < var6 + 5; var26++) {
                    if (var26 >= var4) {
                        Vector3i var27;
                        var27.x = (int)(4096.0f * (8.0f * (float)var26));
                        var27.y = 0;
                        var27.z = (int)(4096.0f * (8.0f * (float)var25));
                        RenderConfig::SetObjectPosition(&var27);
                        RenderConfig::SubmitToFifo();
                        var17->Draw(true);
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
        arg0->unk_830[3] = 0;
    }
}
