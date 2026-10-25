#include <globaldefs.h>
#include <World/Zone3D.h>
#include <NitroSDK/NSBXX/RenderConfig.h>

extern Vector3i Zone3D_chestScale;
extern Vector3i Zone3D_chestLidOffset;
void RenderConfig_SetObjectRotation(void* rotation);

// Main, originally func_02017540 (USA 0x02017540, EUR 0x02017550, JPN 0x020172e0)
extern "C" ARM void Zone3D_DrawChests(Zone3D* zone) {
    if (zone->chestRenderingEnabled_274c_ == 0) return;
    NSBXXInternalModel* models[3] = {};
    models[0] = zone->models_498_[0].rawInternalModel_;
    models[1] = zone->models_498_[1].rawInternalModel_;
    NSBXXTex* textures[3] = {};
    textures[0] = zone->models_498_[0].GetTEX0();
    textures[1] = zone->models_498_[1].GetTEX0();
    Vector3i scale = Zone3D_chestScale;
    RenderConfig::SetObjectScale(&scale);
    int* palette = zone->chestPaletteOffsets_5f0_;
    for (int pass = 0; pass < 2; pass++) {
        NSBXXTex** texture;
        NSBXXInternalModel** model;
        model = models;
        texture = textures;
        while (*texture != NULL && *model != NULL) {
            int paletteOffset = *palette;
            palette++;
            NSBXX_Tex_WritePaletteVRAMOffset(*texture, paletteOffset);
            NSBXX_DetachTexturePaletteFromModel(*model);
            NSBXXInternalModel* currentModel = *model++;
            NSBXXTex* currentTexture = *texture++;
            NSBXX_AttachTexturePaletteToModel(currentModel, currentTexture);
        }
        ZoneChestRenderRecord* chest = zone->chests_;
        for (int i = 0; i < zone->numChests_; chest++, i++) {
            if (chest->state != ZoneChestState_Gone && ((pass == 0 && chest->kind == ZoneChestKind_Red) || (pass == 1 && chest->kind != ZoneChestKind_Red))) {
                Vector3i position = chest->position;
                short angleY = chest->angleY;
                short lidAngle = chest->lidAngle;
                RenderConfig::SetObjectPosition(&position);
                Matrix3x3 rotationY;
                fix32_t cosineY = fix32cos(angleY);
                fix32_t sineY = fix32sin(angleY);
                Mat3x3_WriteRotationY(&rotationY, sineY, cosineY);
                RenderConfig_SetObjectRotation(&rotationY);
                RenderConfig::SubmitToFifo();
                zone->models_498_[0].DrawMeshWithMaterial(true, 0, 0, 1);
                Vector3i lidOffset = Zone3D_chestLidOffset;
                Mat3x3_ApplyToVector(&lidOffset, &rotationY, &lidOffset);
                Vector3fix_Add(&position, &lidOffset, &position);
                RenderConfig::SetObjectPosition(&position);
                Matrix3x3 rotationX;
                fix32_t cosineX = fix32cos(lidAngle);
                fix32_t sineX = fix32sin(lidAngle);
                Mat3x3_WriteRotationX(&rotationX, sineX, cosineX);
                Matrix3x3 rotation;
                Mat3x3_Multiply(&rotationX, &rotationY, &rotation);
                RenderConfig_SetObjectRotation(&rotation);
                RenderConfig::SubmitToFifo();
                arg0->models_498_[1].DrawMeshWithMaterial(true, 0, 0, 1);
            }
        }
    }
}
