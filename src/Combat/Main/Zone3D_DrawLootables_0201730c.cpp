#include <globaldefs.h>
#include "GameState/Field3b0.h"

#include "GameState/GameState.h"
#include "Graphics/LightingManager.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/Graphics.h"

#include "World/ZoneLootableRecord.h"

struct Obj0204724C;
struct StructAt020472e4;

// The break sprite shows for this many ticks of a breaking lootable's breakTimer
enum { kBreakSpriteTicks = 12 };

struct ZoneLootableRecord0201730c {
    short id;
    short state;                // ZoneLootableState
    short breakTimer;
    char reserved6[0x8 - 6];
    Foo02048004 primary[2];
    Foo02048004 fragments[4];
    Vector3i fragmentVelocities[4];
};

struct Zone3D0201730c {
#if defined(jpn)
    char unknown0[0x496];
#else
    char unknown0[0x476];
#endif
    unsigned char numLootables_;
    unsigned char numChests_;
    ZoneLootableRecord0201730c* lootables_;
#if defined(jpn)
    char unknown49c[0x2790 - 0x49c];
#else
    char unknown47c[0x2750 - 0x47c];
#endif
    void* lootableRenderingEnabled_2750_;
};

extern "C" void* Camera_GetInverseRotation(void* obj);
extern "C" void RenderConfig_SetObjectRotation(void* arg);
extern "C" int func_020c56b0(int* out);
extern "C" void func_02047648(unsigned char* obj, int idx, int something);
extern "C" void func_0204724c(Obj0204724C* obj);
extern "C" void func_020472e4(StructAt020472e4* obj, int param);

extern Vector3i data_020e6e20;
extern int data_020e6e64[4];

// Main, originally func_0201730c (USA 0x0201730c, EUR 0x0201731c, JPN 0x020170ac)
extern "C" ARM void Zone3D_DrawLootables(Zone3D0201730c* zone) {
    if (zone->lootableRenderingEnabled_2750_ == NULL) return;

    GameState* gameState = GameState::GetInstance();
    void* camera = gameState->GetCamera();
    if (camera == NULL) return;
    gameState->GetTickCount();
    unsigned short diffuseColor = LightingManager::GetInstance()->maybePotBarrelDiffuseColor_;
    RenderConfig_SetObjectRotation(Camera_GetInverseRotation(camera));

    for (int i = 0; i < zone->numLootables_; i++) {
        ZoneLootableRecord0201730c* lootable = &zone->lootables_[i];
        if (lootable->state == ZoneLootableState_Searched) continue;

        RenderConfig::SetObjectPosition(&lootable->primary[0].position);

        Vector3i scale = data_020e6e20;
        RenderConfig::SetObjectScale(&scale);
        RenderConfig::SubmitToFifo();

        union {
            struct {
                short xMin;
                short unknown_2_;
                short zMin;
                short unknown_6_;
                short unknown_8_;
                short unknown_a_;
            } box;
            struct {
                unsigned int a;
                unsigned int b;
                unsigned int c;
            } unknown1_0_;
        } var6;
        var6.box.xMin = -0x800;
        var6.box.unknown_2_ = 0;
        var6.box.zMin = -0x800;
        var6.box.unknown_6_ = 0x1000;
        var6.box.unknown_8_ = 0x1000;
        var6.box.unknown_a_ = 0x1000;
        GXFIFO_TEST_BOX = var6.unknown1_0_.a;
        GXFIFO_TEST_BOX = var6.unknown1_0_.b;
        GXFIFO_TEST_BOX = var6.unknown1_0_.c;

        int visible;
        while (func_020c56b0(&visible) != 0) {}
        if (visible == 0) continue;

        scale = lootable->primary[0].scale;
        RenderConfig::SetObjectScale(&scale);
        RenderConfig::SubmitToFifo();

        lootable->primary[0].color = diffuseColor;
        lootable->primary[1].color = diffuseColor;
        for (int j = 0; j < 4; j++) lootable->fragments[j].color = diffuseColor;

        if (lootable->state != ZoneLootableState_Breaking) {
            func_02047648((unsigned char*)&lootable->primary[0], 0, 1);
        } else if (lootable->state == ZoneLootableState_Breaking) {
            if (lootable->breakTimer < kBreakSpriteTicks) {
                func_0204724c((Obj0204724C*)&lootable->primary[1]);
                func_020472e4((StructAt020472e4*)&lootable->primary[1], 1);
            }
            for (int j = 0; j < 4; j++) {
                Foo02048004* fragment = &lootable->fragments[j];
                RenderConfig::SetObjectPosition(&fragment->position);
                Matrix3x3* billboard = (Matrix3x3*)Camera_GetInverseRotation(camera);
                Matrix3x3 rotation;
                Matrix3x3 transformed;
                fix32_t angle = data_020e6e64[j];
                fix32_t cosine = fix32cos(angle);
                fix32_t sine = fix32sin(angle);
                Mat3x3_WriteRotationY(&rotation, sine, cosine);
                Mat3x3_Multiply(billboard, &rotation, &transformed);
                RenderConfig_SetObjectRotation(&transformed);
                RenderConfig::SubmitToFifo();
                func_02047648((unsigned char*)fragment, 0, 1);
            }
        }
    }
}
