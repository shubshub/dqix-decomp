#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov002_02154944 {
    char pad[6];
    unsigned short unknown_6_;
};

// USA: func_ov002_02154944
extern "C" ARM short func_ov002_02154944(void* obj, int combatantId, int delta, unsigned char* status) {
    GameObject* combatant = func_0200ff1c(GameState::GetInstance(), combatantId);
    if (combatant == 0) {
        return 0;
    }

    func_02053c6c((unsigned char*)combatant);

    unsigned short maxMP = combatant->baseStats_->primaryStats.maxMP;
    unsigned short var2 = (*(struct Struct_ov002_02154944**)((char*)combatant + 0x130))->unknown_6_;
    int sum = var2 + delta;
    int amount;

    if (sum >= maxMP) {
        amount = maxMP - var2;
        if (amount == 0) {
            *status = 0;
        } else {
            *status = 3;
        }
    } else {
        *status = 3;
        amount = sum - var2;
    }

    (*(struct Struct_ov002_02154944**)((char*)combatant + 0x130))->unknown_6_ = var2 + amount;
    return (short)amount;
}
