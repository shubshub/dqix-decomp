#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct Struct_0202c1a4;
struct Struct_ov017_021c9f18 {
    unsigned char unknown_0_;
    unsigned char unknown_1_[3];
    unsigned char unknown_4_0_ : 3;
    unsigned char unknown_4_3_ : 1;
    unsigned char unknown_4_4_ : 1;
    unsigned char unknown_4_5_ : 1;
    unsigned char unknown_4_6_ : 2;
    unsigned char unknown_5_;
    unsigned short unknown_6_;
    unsigned short unknown_8_;
    unsigned short unknown_a_;
    unsigned short unknown_c_;
    unsigned short unknown_e_;
    unsigned int unknown_10_;
};
struct Struct_ov017_021c9f18_2 {
    unsigned char unknown_0_[2];
    unsigned char unknown_2_;
};
void* GetFieldAt0x150_02053c6c(unsigned char*);
extern "C" void PartyMember_RecalculateStats(void*, int);
unsigned short GetField6b4_021b8480(void*);
void SetFlags0x180At0x18c_02054224(void*);
void ClearFlag0x80SetFlag0x100_02054234(void*);
extern "C" void func_ov017_0218b5f8(int);
void SetBoolFlagAt558_02026f08(unsigned char*, int, int);
void SetArrayEntryFlag02026f20(int, int);
int GetSignedByte0x2d0_020546a8(void*);
int GameState_GetLeaderIndex(GameState*);
signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
void CallHelperWithBuf_021907dc(int, int, int, int, int);
extern "C" void Party_ReformLine(void*, int, int, int, int);

// USA: func_ov017_021c9f18
extern "C" ARM void func_ov017_021c9f18(void* unused, const PartyStatsEvent* event, GameState* game, GameResources* controller, SearchStruct0202c1a4* search) {
    int memberIndex;
    CombatantRecovery* member;
    int changed;
    int allowVisibility;
    int index = event->index;
    int valid = index >= 0 && index <= 3;
    if (valid == 0) return;
    member = static_cast<CombatantRecovery*>(game->GetPartyMemberByIndex(index));
    if (member == NULL) return;
    void* effect = GetFieldAt0x150_02053c6c((unsigned char*)member);
    if (effect == NULL) return;
    changed = 0;
    int wasDead = member->combatFields_.savedState_130_->flags & 1;
    if ((wasDead != 0 && (event->flags & 1) == 0) || (wasDead == 0 && (event->flags & 1) != 0)) changed = 1;
    unsigned short oldHP = member->combatFields_.savedState_130_->hp;
    unsigned short oldMP = member->combatFields_.savedState_130_->mp;
    member->combatFields_.savedState_130_->hp = event->hp;
    member->combatFields_.savedState_130_->mp = event->mp;
    member->baseStats_->primaryStats.maxHP = event->maxHP;
    member->baseStats_->primaryStats.maxMP = event->maxMP;
    member->combatFields_.savedState_130_->flags = event->flags & 0xffff;
    member->combatFields_.savedState_130_->status = event->condition;
    if (event->resetEffect != 0) PartyMember_RecalculateStats(effect, 0);
    BattlePolicy* policy = static_cast<BattlePolicy*>(controller->unknown_ptr_3718);
    allowVisibility = 1;
    if (policy->enabled != 0 && GetField6b4_021b8480(policy) == 0) allowVisibility = 0;
    if (event->updateVisibility != 0) {
        if (allowVisibility != 0) {
            if (event->hp == 0) member->recoveryFlags |= 1;
            else member->recoveryFlags &= ~1;
        } else {
            if (arg1->unknown_6_ == 0) func_02054224(var1);
            else func_02054234(var1);
        }
    }
    if (arg1->unknown_4_5_ != 0) func_ov017_0218b5f8(-1);
    Struct_02020554* var11 = arg3->unknown_ptr_36d0;
    if (var11 != NULL) {
        func_02026f08((unsigned char*)var11, (unsigned char)var4, arg1->unknown_4_5_);
        if (arg1->unknown_4_5_ != 0 && (var8 != arg1->unknown_6_ || var9 != arg1->unknown_a_)) func_02026f20((int)var11, var4 & 0xff);
    }
    if (changed == 0) return;
    memberIndex = index;
    if ((member->obj3D_.unknown_0_ & 0x1000) != 0) memberIndex = GetSignedByte0x2d0_020546a8(member);
    GameState_GetLeaderIndex(game);
    if (memberIndex != LinkSession_GetOwnSlot(search)) CallHelperWithBuf_021907dc((int)controller, memberIndex, 1, 1, 1);
    else Party_ReformLine(controller, 1, 1, 1, 1);
}
