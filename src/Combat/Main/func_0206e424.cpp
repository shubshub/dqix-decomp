#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_0206e424 {
    unsigned int unknown_0_;
    unsigned int unknown_4_;
    unsigned int unknown_8_0_ : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned int unknown_c_0_ : 12;
    unsigned int unknown_d_4_ : 11;
    unsigned int unknown_e_7_ : 9;
    unsigned int unknown_10_[4];
};
struct Struct_0206e424_2 {
    unsigned char unknown_0_[0x194];
    Struct_0206e424 unknown_194_[9];
};
struct Struct_0206e424_3 {
    unsigned char unknown_0_[0x8c];
    unsigned char unknown_8c_[1];
};
struct Struct_020e87b4 {
    signed char unknown_0_[9];
};
struct Struct_0206e424_4 {
    unsigned char unknown_0_[0x14];
    unsigned int unknown_14_0_ : 18;
    unsigned int unknown_16_2_ : 11;
    unsigned int unknown_17_5_ : 3;
    unsigned char unknown_18_[0xb0 - 0x18];
};
extern SlotOrder0206e424 data_020e87b4;
int GetFieldAt0x150_02053c6c(unsigned char*);
int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
void LoadBattleBlock020ac4c0(void*);
void AddClamped11BitFieldAt0x14_020a04c8(S_a04c8*, unsigned int);
void CopyInBattleField0x7540_020ac494(void*);

static inline int inline_0206e424(Struct_0206e424* arg0) {
    return arg0->unknown_8_0_ <= 7;
}

// USA: func_0206e424
extern "C" ARM void func_0206e424(LearnedSpellFlags0206e424* owner, int combatantId) {
    int inParty;
    if (combatantId >= 0 && combatantId <= 3) inParty = 1;
    else inParty = 0;
    if (!inParty) return;
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
    if (!combatant) return;
    SpellData0206e424* spellData = (SpellData0206e424*)GetFieldAt0x150_02053c6c((unsigned char*)combatant);
    if (!spellData) return;
    SlotOrder0206e424 order = data_020e87b4;
    SpellSlot0206e424* slots = spellData->slots;
    unsigned char learned = 0;
    unsigned char index = 0;
    while (order.slots[index] >= 0) {
        SpellSlot0206e424* slot = &slots[order.slots[index]];
        if (IsUsableSlot0206e424(slot)) {
            unsigned short spellId = slot->spellId;
            if (spellId) {
                if (!Scenario_TestFlag((int)owner, owner->bits, spellId + 0xc76)) {
                    Scenario_SetFlag(owner, owner->bits, spellId + 0xc76, 1);
                    learned++;
                }
            }
        }
        var6++;
    }
    Struct_0206e424_4 var9;
    func_020ac4c0(&var9);
    func_020a04c8(&var9, var5);
    func_020ac494(&var9);
}
