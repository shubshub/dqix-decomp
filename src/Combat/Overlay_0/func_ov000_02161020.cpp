#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

struct Struct_020d76b8;

struct Struct_ov000_02161020 {
#if defined(jpn)
    char unknown_0_[0xe20];
#else
    char unknown1_0_[0xea4];
#endif
    Struct_020d76b8* unknown_ea4_;
};

struct Struct_ov000_02161020_2 {
#if defined(jpn)
    char unknown_0_[0x58];
#else
    char unknown1_0_[0x38];
#endif
    unsigned short unknown_38_;
    char unknown_3a_[2];
    int unknown_3c_;
};

struct Struct_ov000_02161020_3 {
    char unknown_0_[0x18e];
    short unknown_18e_;
};

extern "C" void* func_02057924(void);
extern "C" RenderCtx02161020* Zone3D_GetInstance(void);
GameObject* GetCombatantWithFlag0x400_0200fea4(GameState* gameState, int combatantId);
extern "C" int func_02032fdc(GameObject* obj, int a1, int a2);
extern "C" void func_02057ab8(void* g, int id);
void SyncBattleState0208f87c(const void* pos, int color, int scale, int alpha, int polygonId);
void SetRemappedBitAt0xa26_020d76b8(RemapFlagOwner* obj, int index);
void ClearFlagBit_020d76d8(unsigned char* base, int bit);

// USA: func_ov000_02161020
extern "C" ARM void func_ov000_02161020(BattleWork02161020* work) {
    GameState* bs = GameState::GetInstance();
    GameResources* res = GetGameResources();
    void* g = func_02057924();
    RenderCtx02161020* ctx = Zone3D_GetInstance();
    RemapFlagOwner* owner = work->remapOwner;
    unsigned short color = ctx->color;
    for (int i = 0; i < 8; i++) {
        GameObject* c = GetCombatantWithFlag0x400_0200fea4(bs, i + 0xc0);
        if (c == NULL) {
            continue;
        }
        if (!var7->obj3D_.IsVisible()) {
            continue;
        }
        int var8 = 0;
        if (TestFlags04(var1, 0x200) == 0) {
            var8 = func_02032fdc(var7, 1, var8);
        }
        if (var8 != 0) {
            func_02057ab8(var2, var6 + 0xc0);
            int var9 = var3->unknown_3c_;
            int var10 = var7->obj3D_.GetCombinedAlpha();
            int var11 = (int)((float)var9 / 31.0f * (float)var10);
            int var12 = 1;
            Model3D* var13 = var7->obj3D_.pModel_;
            if (var13 != NULL && var13->rawInternalModel_ != NULL) {
                var12 = NSBXX_Model_GetMaterialPolygonID(var13->rawInternalModel_, 0);
            }
            const Vector3fix& var14 = var7->obj3D_.MaybeGetShadowSource();
            func_0208f87c(&var14, var5, ((Struct_ov000_02161020_3*)var7)->unknown_18e_, var11, var12);
            if (var4 != NULL) {
                func_020d76b8(var4, var6 + 0xc0);
            }
        } else {
            if (var4 != NULL) {
                func_020d76d8((unsigned char*)var4, var6 + 0xc0);
            }
        }
    }
}
