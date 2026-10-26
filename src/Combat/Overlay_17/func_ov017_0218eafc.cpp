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
    unsigned char pad0[0x34b8];
#else
    unsigned char pad0[0x36c8];
#endif
    Model3D* model;
};

extern "C" void* func_02057924(void);
extern "C" void func_02057ab8(void* list, int id);
extern "C" int func_ov017_021922ac(void* self, unsigned int idx);
extern "C" int GameObject_IsHidden(unsigned char* obj);
extern "C" int func_02053cdc(int* obj);
extern "C" int func_02053cd4(unsigned char* obj);
extern "C" int GameObject_Draw(void* obj, int clip, Vector3i* out);
extern "C" int func_02061bd8(Struct_0205faf4_11* obj);
extern "C" unsigned char func_02053eb4(void* obj, int extra);
extern "C" void G3_RotateY(int angle);
extern "C" Object3D* func_ov017_021bdbcc(void* obj);
extern "C" Object3D* func_ov017_021bdbc0(unsigned char* ov);
extern "C" void func_ov017_0218dba0(int id);

// USA: func_ov017_0218eafc
extern "C" ARM void func_ov017_0218eafc(Struct_ov017_0218eafc* battle, int idx) {
    GameState* gs = GameState::GetInstance();
    void* list = func_02057924();
    int var2 = func_ov017_021922ac(battle, (unsigned char)idx);
    if (var2) func_02057ab8(list, idx);
    if (gs->GetCamera() == 0) return;

    CombatantRecovery* member = (CombatantRecovery*)gs->GetPartyMemberByIndex(idx);
    int var4 = idx * 12 + 0x13;
    Object3D* var5 = (Object3D*)gs->GetGameObjectByIndex(var4);
    if (member->obj3D_.GetFlag(0x200)) return;
    if (GameObject_IsHidden((unsigned char*)member)) return;
    if (member->obj3D_.IsChild()) return;
    Model3D* model = member->obj3D_.pModel_;
    if (model == NULL) return;
    ModelRenderContext* context = model->loaded_ ? &model->renderContext_ : NULL;
    if (context == NULL) return;

    bool clip = true;
    if (TestFlags04((GameResources*)battle, 0x1000)) clip = false;
    int alpha = member->obj3D_.GetCombinedAlpha();
    fix32_t var10 = member->obj3D_.GetAlphaScaleFactor();

    Vector3i saved;
    if (func_02053cdc((int*)member)) {
        saved = member->obj3D_.position_;
        Vector3i raised = saved;
        raised.y += func_02053cd4((unsigned char*)member);
        member->obj3D_.position_ = raised;
        if (var5) var5->position_ = raised;
    }

    if ((member->recoveryFlags & 1) && !(member->recoveryFlags & 2) && member->obj3D_.IsVisible()) {
        member->obj3D_.PopulateRenderConfigWorld();
        RenderConfig::SubmitToFifo();
        battle->model->SetAlpha(alpha);
        battle->model->Draw(clip);
        if (!var2) func_02057ab8(list, idx);
        return;
    }

    member->obj3D_.EnableFlag(0x20000);
    Vector3i shadowPos;
    if (GameObject_Draw(member, clip, &shadowPos)) {
        int weaponId = idx * 12 + 0x14;
        int var15 = idx * 12 + 0x15;
        int headId = idx * 12 + 0x1b;
        int var17 = idx * 12 + 0x1c;
        int var18 = idx * 12 + 0x1d;
        unsigned char ids[6] = {
            (unsigned char)(idx * 12 + 0x13), (unsigned char)weaponId, (unsigned char)var15,
            (unsigned char)headId, (unsigned char)var17, (unsigned char)var18
        };
        for (unsigned int i = 0; i < 6; i++) {
            Object3D* part = (Object3D*)gs->GetGameObjectByIndex(ids[i]);
            if (part) {
                part->SetInheritedAlpha(alpha);
                part->SetAlphaScaleFactor((fix16_t)var10);
            }
        }

        if (!func_02061bd8((Struct_0205faf4_11*)member)) {
            int var22 = func_02053eb4(member, 0);
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, var22);
            Object3D* part = (Object3D*)gs->GetGameObjectByIndex(weaponId);
            if (part) {
                Vector3fix s = part->GetScale();
                GXFIFO_MATRIX_SCALE = s.x;
                GXFIFO_MATRIX_SCALE = s.y;
                GXFIFO_MATRIX_SCALE = s.z;
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            part = (Object3D*)gs->GetGameObjectByIndex(var15);
            if (part) {
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            part = (Object3D*)gs->GetGameObjectByIndex(headId);
            if (part && part->unknown_2_ >= 0) {
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, func_02053eb4(member, 3));
            part = (Object3D*)gs->GetGameObjectByIndex(var18);
            if (part && part->unknown_2_ > 0) {
                part->EnableFlag(0x8000);
                part->Draw(false);
            }
            if (member->recoveryFlags & 0x20) {
                part = (Object3D*)gs->GetGameObjectByIndex(var17);
                if (part) {
                    part->EnableFlag(0x8000);
                    G3_RotateY(0x3244);
                    part->Draw(false);
                    part->DisableFlag(0x8000);
                }
            }
            if (idx == 0) {
                Object3D* effect = func_ov017_021bdbcc(battle);
                if (effect) {
                    GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, var22);
                    effect->EnableFlag(0x8000);
                    effect->Draw(false);
                }
            }
            if (member->obj3D_.IsParent()) member->obj3D_.DrawChildren(&member->obj3D_);
            if (idx == 0) {
                Object3D* effect = func_ov017_021bdbc0((unsigned char*)battle);
                if (effect) {
                    GetModelBonePositionAndDirectionMatrices(context, NULL, NULL, func_02053eb4(member, 2));
                    effect->EnableFlag(0x8000);
                    effect->Draw(false);
                }
            }
            if (var5) {
                var5->position_ = shadowPos;
                var5->rotation_ = member->obj3D_.rotation_;
                var5->Draw(false);
            }
        }
        func_ov017_0218dba0(idx);
        if (!var2) func_02057ab8(list, idx);
    }

    if (func_02053cdc((int*)member)) {
        member->obj3D_.position_ = saved;
        if (var5) var5->position_ = saved;
    }
}
