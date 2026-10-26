#if defined(jpn)
enum { RegionOffset36fc = 0x34ec, Enum_ov017_0218dba0_56 = 0x58, Enum_ov017_0218dba0_60 = 0x5c };
#else
enum { RegionOffset36fc = 0x36fc, Enum_ov017_0218dba0_56 = 0x38, Enum_ov017_0218dba0_60 = 0x3c };
#endif

#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);

struct BitField0203402c;
extern "C" int GameObject_IsSinking(struct BitField0203402c* p);

extern "C" void* GameState_GetZoneTransition(GameState* battleStruct);

struct HeadNode02046b24;
extern "C" int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

struct Struct_ov017_0218dba0;

extern "C" void func_0208f87c(const void* self, int b, int c, int d, int polygonId);

// USA: func_ov017_0218dba0
extern "C" ARM void func_ov017_0218dba0(int combatantId) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = battle->GetPartyMemberByIndex(combatantId);
    if (combatant == 0) {
        return;
    }
    if (GameObject_IsSinking((struct BitField0203402c*)combatant) != 0) {
        return;
    }

    unsigned short tag;
    int var3;
    void* headArr;

    void* ovBase = GetGameResources();
    headArr = *(void**)((char*)ovBase + RegionOffset36fc);
    void* misc = Zone3D_GetInstance();
    tag = *(unsigned short*)((char*)misc + Enum_ov017_0218dba0_56);
    var3 = *(int*)((char*)misc + Enum_ov017_0218dba0_60);

    Vector3fix var7 = combatant->obj3D_.MaybeGetShadowSource();

    int var8 = ((Object3D*)((struct Struct_ov017_0218dba0*)combatant))->GetCombinedAlpha();
    float t = (float)var3 / 31.0f;
    int d = (int)(t * (float)var8);

    if (combatant != 0) {
        SubBlock02038508* base = GameObject_GetLadderClimb(combatant);
        if (base->active != 0) {
            base = GameObject_GetLadderClimb(combatant);
            unsigned char mode = base->command;
            if (mode == 1 || mode == 4) {
                d = base->unknown50;
            }
            if (mode == 2 || mode == 6) {
                d = base->unknown50;
                var7.y = base->unknown4c;
            }
        }
    }

    if (*(short*)((char*)GameState_GetZoneTransition(battle) + 0x6c) == 0x270f) {
        if (FieldTaskQueue_GetCurrentKind((struct HeadNode02046b24**)headArr) == 3) {
            d = 0;
        }
    }

    if (combatant->obj3D_.GetFlag(0x10) == 0) {
        int c = (int)(0.9f * (float)((Object3D*)((unsigned char*)combatant))->GetRadius());
        func_0208f87c(&var7, tag, c, d, 8);
    } else {
        RenderConfig::SubmitToFifo();
    }
}
