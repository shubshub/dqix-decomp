#include <globaldefs.h>
#include "GameState/GameState.h"
#include "NitroSDK/Matrix.h"
#include "Resource/Brightness.h"

struct Struct_020fdd44 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 2;
};

struct Struct_ov017_021a1d98_2 {
#if defined(jpn)
    char unknown_0_[0x58];
#else
    char unknown1_0_[0x38];
#endif
    unsigned short unknown_38_;
    unsigned int unknown_3c_;
};

struct Struct_ov017_021a1d98 {
    char unknown_0_[0x12];
    short unknown_12_;
};

struct Struct_ov017_021a1d98_3 : GameObject {
    char unknown_13c_[0x180 - 0x13c];
    Struct_ov017_021a1d98* unknown_180_;
};

struct Struct_ov017_021a1d98_4 {
    int unknown_0_;
    unsigned char unknown_4_;
    Struct_ov017_021a1d98_4() : unknown_0_(0x0270f000), unknown_4_(0) {}
};

Entry_02028bd0* ZoneRecords_GetInstance();
Entry_02028bd0* ZoneRecords_Find(Entry_02028bd0*, int);
extern "C" SpawnParams* Zone3D_GetInstance();
int TickActorFlagStateAndDispatch02076bec(GameObject*, void*);
struct BitField0203402c;
int GameObject_IsSinking(BitField0203402c*);
void SyncBattleState0208f87c(const void* self, int b, int c, int d, int polygonId);

// USA: func_ov017_021a1d98
extern "C" ARM void func_ov017_021a1d98(unsigned int* flags, int id) {
    GameState* state = GameState::GetInstance();
    Entry_02028bd0* entry = ZoneRecords_Find(ZoneRecords_GetInstance(), id);
    if (!entry) return;
    SpawnParams* params = Zone3D_GetInstance();
    unsigned short field38 = params->field_38;
    unsigned int field3c = params->field_3c;
    int arg = 1;
    if (TestFlags04((GameResources*)flags, 0x1000)) arg = 0;
    int partyCount = 0;
    for (int i = 0; i < 4; i++) {
        GameObject* member = state->GetPartyMemberByIndex(i);
        if (member && id == member->obj3D_.GetField06()) partyCount++;
    }
    int remaining = 7 - partyCount;
    Vector3fix origin = state->GetLeader()->obj3D_.position_;
    DistanceSlot slots[12];
    for (int j = 0; j < 12; j++) {
        FieldMonster* monster = (FieldMonster*)state->GetFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + j);
        if (monster && monster->obj3D_.IsVisible()) {
            Vector3fix position = monster->obj3D_.position_;
            slots[j].distance = Vector3fix_Distance(&origin, &position);
        }
    }
    int var15, var16, var17;
    for (var16 = 0; var16 < var9; var16++) {
        var17 = -1;
        var15 = 0x0270f000;
        for (int var18 = 0; var18 < 12; var18++) {
            if (!var11[var18].unknown_4_ && var11[var18].unknown_0_ <= var15) {
                var15 = var11[var18].unknown_0_;
                var17 = var18;
            }
        }
        if (var17 != -1) var11[var17].unknown_4_ = 1;
    }
    for (int j = 0; j < 12; j++) {
        if (!slots[j].selected) continue;
        FieldMonster* monster = (FieldMonster*)state->GetFieldMonsterByIndex(entry->slotGroup * 12 + 0x70 + j);
        if (monster && monster->obj3D_.IsVisible()
            && TickActorFlagStateAndDispatch02076bec(monster, (void*)arg)
            && !GameObject_IsSinking((BitField0203402c*)monster)) {
            int alpha = monster->obj3D_.GetCombinedAlpha();
            int value = (int)((float)field3c / 31.0f * (float)alpha);
            int shadowScale = monster->shadowInfo_ ? monster->shadowInfo_->scale : 0x1000;
            fix32_t size = FIX32_MULTIPLY(shadowScale, monster->obj3D_.GetScale().x * 15);
            const Vector3fix& shadow = monster->obj3D_.MaybeGetShadowSource();
            SyncBattleState0208f87c(&shadow, field38, size, value, 8);
        }
    }
}
