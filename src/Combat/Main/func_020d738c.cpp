#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020d738c {
    unsigned short unused0 : 2;
    unsigned short unknown_0_2_ : 4;
    unsigned short unused1 : 10;
};

extern "C" void func_020d6f9c(void* param0, int combatantId, int arg2);

// USA: func_020d738c
extern "C" ARM void func_020d738c(void* param0) {
    GameState* battleStruct = GameState::GetInstance();
    int id;
    for (id = 0; id < 0xc; id++) {
        int combatantId = id;
        if (id > 3) {
            combatantId = id + 0xbc;
        }
        GameObject* combatant = battleStruct->GetCombatantByIndex(combatantId);
        struct ModifiableCombatStats* currentStats;
        unsigned short flags;
        int var6;
        unsigned short hp;
        if (combatant == NULL) {
            continue;
        }
        currentStats = combatant->currentStats_;
        flags = *(unsigned int*)currentStats->unk1;
        var6 = ((struct Struct_020d738c*)(currentStats->unk1 + 0xE))->unknown_0_2_;
        hp = currentStats->primaryStats.currHP;
        if (flags & 1) {
            continue;
        }
        if (hp == 0) {
            continue;
        }
        if (flags & 2) {
            func_020d6f9c(param0, combatantId, 0);
            continue;
        }
        if (flags & 0x10) {
            func_020d6f9c(param0, combatantId, 1);
            continue;
        }
        if (flags & 8) {
            func_020d6f9c(param0, combatantId, 3);
            continue;
        }
        if (flags & 0x20) {
            func_020d6f9c(param0, combatantId, 4);
            continue;
        }
        if ((flags & 0x80000) && var6 == 6) {
            func_020d6f9c(param0, combatantId, 2);
        }
    }
}
