#include <globaldefs.h>
#include "Combat/CombatantRecovery.h"
#include "GameState/GameState.h"

struct PartySlots { char pad0[0xf78]; signed char ids[4]; unsigned char count; };
struct BattleContext { int field0; void* controller; };
extern BattleContext data_ov017_021d82e0;
void CopyByteField0x253To0x252_02039830(void*);
unsigned char GetByteField0x252_02039820(void*);
unsigned char GameState_GetLeaderIndex(GameState*);
void TryClearFlags0x130_02048418(unsigned char*, unsigned short);
extern "C" void func_ov017_021c9e00(int, int, int, int);
extern "C" void func_ov017_02191108(void*, int, int, int, int);
void GameObject_EnableControl(void*);
struct Obj020397cc;
void GameObject_DisableControl(Obj020397cc*, int);

// USA: func_ov017_0218d2f0
extern "C" ARM void func_ov017_0218d2f0(unsigned char revive, unsigned char cure, int amount, unsigned char all) {
    GameState* game = GameState::GetInstance();
    PartySlots* party = (PartySlots*)GameState_GetParty(game);
    int active = 1;
    unsigned char count = party->count;
    GameObject* leader = game->GetUnknownGameObject();
    if (leader) {
        CopyByteField0x253To0x252_02039830(leader);
        active = GetByteField0x252_02039820(leader) != 0;
    }
    for (unsigned char i = 0; i < count; ++i) {
        short index = party->ids[i];
        GameObject* combatant = GetCombatantWithFlag0x100_0200ff1c(game, index);
        if (!combatant || (!all && index != GameState_GetLeaderIndex(game))) continue;
        if (revive) {
            if (combatant->combatFields_.savedState_130_->flags & 1) {
                ClearFieldBit02053fe4(combatant, 1, 1);
                TryClearFlags0x130_02048418((unsigned char*)combatant, 1);
            }
        }
        if (arg1 && !(var7->unknown_ac_.unknown_84_->unknown_0_ & 1)) {
            if (var7->unknown_ac_.unknown_84_->unknown_0_) var7->unknown_ac_.unknown_84_->unknown_0_ &= 4;
        }
        if (arg2 && !(var7->unknown_ac_.unknown_84_->unknown_0_ & 1)) {
            int var8 = var7->unknown_ac_.unknown_84_->unknown_4_ + arg2;
            if (var7->baseStats_->primaryStats.maxHP < var8) var8 = var7->baseStats_->primaryStats.maxHP;
            var7->unknown_ac_.unknown_84_->unknown_4_ = var8;
            var8 = var7->unknown_ac_.unknown_84_->unknown_6_ + arg2;
            if (var7->baseStats_->primaryStats.maxMP < var8) var8 = var7->baseStats_->primaryStats.maxMP;
            var7->unknown_ac_.unknown_84_->unknown_6_ = var8;
        }
        func_ov017_021c9e00(var6, 1, 0, 1);
        func_ov017_02191108(data_ov017_021d82e0.unknown_4_, 1, 1, 1, 1);
    }
    leader = game->GetUnknownGameObject();
    if (leader) {
        if (active) GameObject_EnableControl(leader);
        else GameObject_DisableControl((Obj020397cc*)leader, 1);
    }
}
