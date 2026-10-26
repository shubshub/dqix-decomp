#if defined(jpn)
enum { RegionOffset36fc = 0x34ec, RegionOffset38 = 0x58, RegionOffset3c = 0x5c };
#else
enum { RegionOffset36fc = 0x36fc, RegionOffset38 = 0x38, RegionOffset3c = 0x3c };
#endif

#include <globaldefs.h>
#include "Combat/ActorAction.h"
#include "GameState/GameState.h"
#include "NitroSDK/NSBXX/RenderConfig.h"
#include "Resource/GameResources.h"

extern "C" void* Zone3D_GetInstance(void);

struct BitField0203402c;
int GameObject_IsSinking(struct BitField0203402c* p);

void* GameState_GetZoneTransition(GameState* battleStruct);

struct HeadNode02046b24;
int FieldTaskQueue_GetCurrentKind(struct HeadNode02046b24** obj);

struct S02037484;

void SyncBattleState0208f87c(const void* self, int b, int c, int d, int polygonId);

// USA: func_ov017_0218dba0  (semantic: SyncFlaggedCombatantState_0218dba0)
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
    int f8c;
    void* headArr;

    void* ovBase = GetGameResources();
    headArr = *(void**)((char*)ovBase + RegionOffset36fc);
    void* misc = Zone3D_GetInstance();
    tag = *(unsigned short*)((char*)misc + RegionOffset38);
    f8c = *(int*)((char*)misc + RegionOffset3c);

    Vector3fix selfVec = combatant->obj3D_.MaybeGetShadowSource();

    int mulResult = ((Object3D*)((struct S02037484*)combatant))->GetCombinedAlpha();
    float t = (float)f8c / 31.0f;
    int d = (int)(t * (float)mulResult);

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
                selfVec.y = base->unknown4c;
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
        SyncBattleState0208f87c(&selfVec, tag, c, d, 8);
    } else {
        RenderConfig::SubmitToFifo();
    }
}
