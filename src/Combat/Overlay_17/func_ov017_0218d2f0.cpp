#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

struct PartySlots { char pad0[0xf78]; signed char ids[4]; unsigned char count; };
struct Struct_ov017_021d82e0 { int field0; void* controller; };
extern Struct_ov017_021d82e0 data_ov017_021d82e0;
extern "C" void GameObject_ApplyPendingControl(void*);
extern "C" unsigned char GameObject_IsControlEnabled(void*);
extern "C" unsigned char GameState_GetLeaderIndex(GameState*);
extern "C" void func_02048418(unsigned char*, unsigned short);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void Party_ReformLine(void*, int, int, int, int);
extern "C" void GameObject_EnableControl(void*);
struct Obj020397cc;
extern "C" void GameObject_DisableControl(Obj020397cc*, int);

// USA: func_ov017_0218d2f0
extern "C" ARM void func_ov017_0218d2f0(unsigned char arg0, unsigned char arg1, int amount, unsigned char all) {
    GameState* game = GameState::GetInstance();
    PartySlots* party = (PartySlots*)GameState_GetParty(game);
    int active = 1;
    unsigned char count = party->count;
    GameObject* leader = game->GetLeader();
    if (leader) {
        GameObject_ApplyPendingControl(leader);
        active = GameObject_IsControlEnabled(leader) != 0;
    }
    for (unsigned char i = 0; i < count; ++i) {
        short index = party->ids[i];
        GameObject* combatant = func_0200ff1c(game, index);
        if (!combatant || (!all && index != GameState_GetLeaderIndex(game))) continue;
        if (arg0) {
            if (combatant->combatFields_.savedState_130_->flags & 1) {
                func_02053fe4(combatant, 1, 1);
                func_02048418((unsigned char*)combatant, 1);
            }
        }
        if (arg1 && !(combatant->combatFields_.savedState_130_->flags & 1)) {
            if (combatant->combatFields_.savedState_130_->flags) combatant->combatFields_.savedState_130_->flags &= 4;
        }
        if (amount && !(combatant->combatFields_.savedState_130_->flags & 1)) {
            int hp = combatant->combatFields_.savedState_130_->hp + amount;
            if (combatant->baseStats_->primaryStats.maxHP < hp) hp = combatant->baseStats_->primaryStats.maxHP;
            combatant->combatFields_.savedState_130_->hp = hp;
            hp = combatant->combatFields_.savedState_130_->mp + amount;
            if (combatant->baseStats_->primaryStats.maxMP < hp) hp = combatant->baseStats_->primaryStats.maxMP;
            combatant->combatFields_.savedState_130_->mp = hp;
        }
        func_ov017_021c9e00(index, 1, 0, 1);
        Party_ReformLine(data_ov017_021d82e0.controller, 1, 1, 1, 1);
    }
    leader = game->GetLeader();
    if (leader) {
        if (active) GameObject_EnableControl(leader);
        else GameObject_DisableControl((Obj020397cc*)leader, 1);
    }
}
