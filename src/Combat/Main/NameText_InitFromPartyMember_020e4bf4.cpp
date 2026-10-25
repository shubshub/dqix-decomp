#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"


struct Sub0x150_020e4bf4 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

extern "C" void func_020e4b34(void* obj, struct BaseCombatStats* stats1, struct BaseCombatStats* stats2,
    int p4, int p5, int p6, int p7, int p8, int p9, int p10, int p11, int p12);

// Main, originally InitObjFromCombatantId020e4bf4 (USA 0x020e4bf4, EUR 0x020e4c04; JPN not identified)
ARM void NameText_InitFromPartyMember(void* obj, int combatantId) {
    memset(obj, 0, 0xc);
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(combatantId);
    if (combatant != NULL) {
        struct Sub0x150_020e4bf4* sub = *(struct Sub0x150_020e4bf4**)((char*)combatant + 0x150);
        func_020e4b34(obj, combatant->baseStats_, combatant->baseStats_, 0, 0, 0, 0, sub->bit0, 0, 1, 0, 1);
    }
}
