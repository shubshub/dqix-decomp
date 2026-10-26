#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Combat/CombatantRecovery.h"

struct SearchStruct0202c1a4;
struct Struct_ov017_021c9f18 {
    unsigned char tag;
    unsigned char padding[3];
    unsigned char index : 3;
    unsigned char unknown_4_3_ : 1;
    unsigned char resetEffect : 1;
    unsigned char special : 1;
    unsigned char unused : 2;
    unsigned char unknown_5_;
    unsigned short hp;
    unsigned short maxHP;
    unsigned short mp;
    unsigned short maxMP;
    unsigned short padding2;
    unsigned int flags;
};
struct Struct_ov017_021c9f18_2 {
    unsigned char padding[2];
    unsigned char enabled;
};
extern "C" void* func_02053c6c(unsigned char*);
extern "C" void PartyMember_RecalculateStats(void*, int);
extern "C" unsigned short func_ov017_021b8480(void*);
extern "C" void func_02054224(void*);
extern "C" void func_02054234(void*);
extern "C" void func_ov017_0218b5f8(int);
extern "C" void func_02026f08(unsigned char*, int, int);
extern "C" void func_02026f20(int, int);
extern "C" int func_020546a8(void*);
extern "C" int GameState_GetLeaderIndex(GameState*);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4*);
extern "C" void func_ov017_021907dc(int, int, int, int, int);
extern "C" void Party_ReformLine(void*, int, int, int, int);

// USA: func_ov017_021c9f18
extern "C" ARM void func_ov017_021c9f18(void* unused, const Struct_ov017_021c9f18* event, GameState* game, GameResources* controller, SearchStruct0202c1a4* search) {
    int memberIndex;
    CombatantRecovery* member;
    int changed;
    int var3;
    int index = event->index;
    int var5 = index >= 0 && index <= 3;
    if (var5 == 0) return;
    member = static_cast<CombatantRecovery*>(game->GetPartyMemberByIndex(index));
    if (member == NULL) return;
    void* effect = func_02053c6c((unsigned char*)member);
    if (effect == NULL) return;
    changed = 0;
    int var7 = member->combatFields_.savedState_130_->flags & 1;
    if ((var7 != 0 && (event->flags & 1) == 0) || (var7 == 0 && (event->flags & 1) != 0)) changed = 1;
    unsigned short var8 = member->combatFields_.savedState_130_->hp;
    unsigned short var9 = member->combatFields_.savedState_130_->mp;
    member->combatFields_.savedState_130_->hp = event->hp;
    member->combatFields_.savedState_130_->mp = event->mp;
    member->baseStats_->primaryStats.maxHP = event->maxHP;
    member->baseStats_->primaryStats.maxMP = event->maxMP;
    member->combatFields_.savedState_130_->flags = event->flags & 0xffff;
    member->combatFields_.savedState_130_->status = event->unknown_5_;
    if (event->resetEffect != 0) PartyMember_RecalculateStats(effect, 0);
    Struct_ov017_021c9f18_2* var10 = static_cast<Struct_ov017_021c9f18_2*>(controller->unknown_ptr_3718);
    var3 = 1;
    if (var10->enabled != 0 && func_ov017_021b8480(var10) == 0) var3 = 0;
    if (event->unknown_4_3_ != 0) {
        if (var3 != 0) {
            if (event->hp == 0) member->recoveryFlags |= 1;
            else member->recoveryFlags &= ~1;
        } else {
            if (event->hp == 0) func_02054224(member);
            else func_02054234(member);
        }
    }
    if (event->special != 0) func_ov017_0218b5f8(-1);
    MapDisplay* var11 = controller->unknown_ptr_36d0;
    if (var11 != NULL) {
        func_02026f08((unsigned char*)var11, (unsigned char)index, event->special);
        if (event->special != 0 && (var8 != event->hp || var9 != event->mp)) func_02026f20((int)var11, index & 0xff);
    }
    if (changed == 0) return;
    memberIndex = index;
    if ((member->obj3D_.unknown_0_ & 0x1000) != 0) memberIndex = func_020546a8(member);
    GameState_GetLeaderIndex(game);
    if (memberIndex != LinkSession_GetOwnSlot(search)) func_ov017_021907dc((int)controller, memberIndex, 1, 1, 1);
    else Party_ReformLine(controller, 1, 1, 1, 1);
}
