#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);
extern "C" int func_ov000_02156038(GameObject* combatant);
extern "C" int func_020882f8(unsigned char* obj);
extern "C" int func_ov000_02156050(GameObject* combatant);
extern "C" int func_ov000_021543f4(GameObject* combatant);

// USA: func_ov000_02155f9c
extern "C" ARM int func_ov000_02155f9c(void* unused, int combatantId, int arg2) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(combatantId);
    if (c == 0) {
        return 1;
    }
    if (func_02010088((struct S_10088*)c) ||
        func_ov000_02153c0c(c) ||
        func_ov000_02156038(c) ||
        func_020882f8((unsigned char*)c->currentStats_) ||
        func_ov000_02156050(c)) {
        return 1;
    }
    if (arg2 != 0 && func_ov000_021543f4(c)) {
        return 1;
    }
    return 0;
}
