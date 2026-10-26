#include <globaldefs.h>
#include "GameState/Field3b0.h"
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"
#include "NitroSDK/NSBXX/GeometryFifo.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "NitroSDK/Graphics.h"
#include "Resource/Brightness.h"

struct Struct_0205faf4_11;

struct Struct_ov017_0218eafc {
#if defined(jpn)
    unsigned char unknown_0_[0x34b8];
#else
    unsigned char unknown1_0_[0x36c8];
#endif
    Model3D* unknown_36c8_;
};

extern "C" void* func_02057924(void);
extern "C" void func_02057ab8(void* list, int id);
int CheckByteFlagsAt4488_021922ac(void* self, unsigned int idx);
int GameObject_IsHidden(unsigned char* obj);
int IsField0x1b4Or0x1b8Positive_02053cdc(int* obj);
int GetFieldAt0x1b8_02053cd4(unsigned char* obj);
extern "C" int GameObject_Draw(void* obj, int clip, Vector3i* out);
int CheckField0x56bLowNibble(Obj02061bd8* obj);
unsigned char GetByteFieldAt0x1a0_02053eb4(void* obj, int extra);
extern "C" void G3_RotateY(int angle);
extern "C" Object3D* func_ov017_021bdbcc(void* obj);
Object3D* GetField4334_021bdbc0(unsigned char* ov);
extern "C" void func_ov017_0218dba0(int id);

// USA: func_ov017_0218eafc
extern "C" ARM void func_ov017_0218eafc(Battle0218eafc* battle, int idx) {
    GameState* gs = GameState::GetInstance();
    void* list = func_02057924();
    int flagged = CheckByteFlagsAt4488_021922ac(battle, (unsigned char)idx);
    if (flagged) func_02057ab8(list, idx);
    if (gs->GetCamera() == 0) return;

    CombatantRecovery* member = (CombatantRecovery*)gs->GetPartyMemberByIndex(idx);
    int shadowId = idx * 12 + 0x13;
    Object3D* shadow = (Object3D*)gs->GetGameObjectByIndex(shadowId);
    if (member->obj3D_.GetFlag(0x200)) return;
    if (GameObject_IsHidden((unsigned char*)member)) return;
    if (member->obj3D_.IsChild()) return;
    Model3D* model = member->obj3D_.pModel_;
    if (model == NULL) return;
    ModelRenderContext* context = model->loaded_ ? &model->renderContext_ : NULL;
    if (context == NULL) return;

    bool var8 = true;
    if (TestFlags04((GameResources*)arg0, 0x1000)) var8 = false;
    int var9 = var3->obj3D_.GetCombinedAlpha();
    fix32_t var10 = var3->obj3D_.GetAlphaScaleFactor();

    Vector3i var11;
    if (func_02053cdc((int*)var3)) {
        var11 = var3->obj3D_.position_;
        Vector3i var12 = var11;
        var12.y += func_02053cd4((unsigned char*)var3);
        var3->obj3D_.position_ = var12;
        if (var5) var5->position_ = var12;
    }

    if ((var3->unknown_18c_ & 1) && !(var3->unknown_18c_ & 2) && var3->obj3D_.IsVisible()) {
        var3->obj3D_.PopulateRenderConfigWorld();
        RenderConfig::SubmitToFifo();
        arg0->unknown_36c8_->SetAlpha(var9);
        arg0->unknown_36c8_->Draw(var8);
        if (!var2) func_02057ab8(var1, arg1);
        return;
    }

    member->obj3D_.EnableFlag(0x20000);
    Vector3i shadowPos;
    if (GameObject_Draw(member, clip, &shadowPos)) {
        int weaponId = idx * 12 + 0x14;
        int shieldId = idx * 12 + 0x15;
        int headId = idx * 12 + 0x1b;
        int accessoryId = idx * 12 + 0x1c;
        int extraId = idx * 12 + 0x1d;
        unsigned char ids[6] = {
            (unsigned char)(idx * 12 + 0x13), (unsigned char)weaponId, (unsigned char)shieldId,
            (unsigned char)headId, (unsigned char)accessoryId, (unsigned char)extraId
        };
        for (unsigned int var20 = 0; var20 < 6; var20++) {
            Object3D* var21 = (Object3D*)var0->GetGameObjectByIndex(var19[var20]);
            if (var21) {
                var21->SetInheritedAlpha(var9);
                var21->SetAlphaScaleFactor((fix16_t)var10);
            }
        }

        if (!func_02061bd8((Struct_0205faf4_11*)var3)) {
            int var22 = func_02053eb4(var3, 0);
            GetModelBonePositionAndDirectionMatrices(var7, NULL, NULL, var22);
            Object3D* var23 = (Object3D*)var0->GetGameObjectByIndex(var14);
            if (var23) {
                Vector3fix var24 = var23->GetScale();
                GXFIFO_MATRIX_SCALE = var24.x;
                GXFIFO_MATRIX_SCALE = var24.y;
                GXFIFO_MATRIX_SCALE = var24.z;
                var23->EnableFlag(0x8000);
                var23->Draw(false);
            }
            var23 = (Object3D*)var0->GetGameObjectByIndex(var15);
            if (var23) {
                var23->EnableFlag(0x8000);
                var23->Draw(false);
            }
            var23 = (Object3D*)var0->GetGameObjectByIndex(var16);
            if (var23 && var23->unknown_2_ >= 0) {
                var23->EnableFlag(0x8000);
                var23->Draw(false);
            }
            GetModelBonePositionAndDirectionMatrices(var7, NULL, NULL, func_02053eb4(var3, 3));
            var23 = (Object3D*)var0->GetGameObjectByIndex(var18);
            if (var23 && var23->unknown_2_ > 0) {
                var23->EnableFlag(0x8000);
                var23->Draw(false);
            }
            if (member->recoveryFlags & 0x20) {
                part = (Object3D*)gs->GetGameObjectByIndex(accessoryId);
                if (part) {
                    part->EnableFlag(0x8000);
                    G3_RotateY(0x3244);
                    part->Draw(false);
                    part->DisableFlag(0x8000);
                }
            }
            if (arg1 == 0) {
                Object3D* var25 = func_ov017_021bdbcc(arg0);
                if (var25) {
                    GetModelBonePositionAndDirectionMatrices(var7, NULL, NULL, var22);
                    var25->EnableFlag(0x8000);
                    var25->Draw(false);
                }
            }
            if (var3->obj3D_.IsParent()) var3->obj3D_.DrawChildren(&var3->obj3D_);
            if (arg1 == 0) {
                Object3D* var26 = func_ov017_021bdbc0((unsigned char*)arg0);
                if (var26) {
                    GetModelBonePositionAndDirectionMatrices(var7, NULL, NULL, func_02053eb4(var3, 2));
                    var26->EnableFlag(0x8000);
                    var26->Draw(false);
                }
            }
            if (var5) {
                var5->position_ = var13;
                var5->rotation_ = var3->obj3D_.rotation_;
                var5->Draw(false);
            }
        }
        func_ov017_0218dba0(arg1);
        if (!var2) func_02057ab8(var1, arg1);
    }

    if (func_02053cdc((int*)var3)) {
        var3->obj3D_.position_ = var11;
        if (var5) var5->position_ = var11;
    }
}
