#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_02153c0c(GameObject* combatant);

// USA: func_ov000_02153cc0
extern "C" ARM void func_ov000_02153cc0(int unused, int newVal, int* arg2) {
    short id = (short)(*(int*)arg2);
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(id);
    if (c != NULL && func_02010088((struct S_10088*)c) == 0 && func_ov000_02153c0c(c) == 0) return;
    *arg2 = newVal;
}
