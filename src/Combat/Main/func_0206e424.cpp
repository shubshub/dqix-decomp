#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_0206e424 {
    unsigned int field_0x0;
    unsigned int unknown_4_;
    unsigned int kind : 4;
    unsigned int unknown_8_4_ : 28;
    unsigned int unknown_c_0_ : 12;
    unsigned int spellId : 11;
    unsigned int unknown_e_7_ : 9;
    unsigned int field_0x10[4];
};
struct Struct_0206e424_2 {
    unsigned char unknown_0_[0x194];
    Struct_0206e424 slots[9];
};
struct Struct_0206e424_3 {
    unsigned char unknown_0_[0x8c];
    unsigned char bits[1];
};
struct Struct_020e87b4 {
    signed char slots[9];
};
struct Struct_0206e424_4 {
    unsigned char unknown_0_[0x14];
    unsigned int unknown_14_0_ : 18;
    unsigned int count : 11;
    unsigned int unknown_17_5_ : 3;
    unsigned char unknown_18_[0xb0 - 0x18];
};
extern Struct_020e87b4 data_020e87b4;
extern "C" int func_02053c6c(unsigned char*);
extern "C" int Scenario_TestFlag(int, unsigned char*, int);
extern "C" void Scenario_SetFlag(void*, unsigned char*, int, int);
extern "C" void func_020ac4c0(void*);
extern "C" void func_020a04c8(Struct_0206e424_4*, unsigned int);
extern "C" void func_020ac494(void*);

static inline int inline_0206e424(Struct_0206e424* slot) {
    return slot->kind <= 7;
}

// USA: func_0206e424
extern "C" ARM void func_0206e424(Struct_0206e424_3* owner, int combatantId) {
    int inParty;
    if (combatantId >= 0 && combatantId <= 3) inParty = 1;
    else inParty = 0;
    if (!inParty) return;
    GameObject* combatant = GameState::GetInstance()->GetPartyMemberByIndex(combatantId);
    if (!combatant) return;
    Struct_0206e424_2* var2 = (Struct_0206e424_2*)func_02053c6c((unsigned char*)combatant);
    if (!var2) return;
    Struct_020e87b4 order = data_020e87b4;
    Struct_0206e424* slots = var2->slots;
    unsigned char var5 = 0;
    unsigned char index = 0;
    while (order.slots[index] >= 0) {
        Struct_0206e424* slot = &slots[order.slots[index]];
        if (inline_0206e424(slot)) {
            unsigned short spellId = slot->spellId;
            if (spellId) {
                if (!Scenario_TestFlag((int)owner, owner->bits, spellId + 0xc76)) {
                    Scenario_SetFlag(owner, owner->bits, spellId + 0xc76, 1);
                    var5++;
                }
            }
        }
        index++;
    }
    Struct_0206e424_4 block;
    func_020ac4c0(&block);
    func_020a04c8(&block, var5);
    func_020ac494(&block);
}
