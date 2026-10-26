#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov024_021d923c { void* field0; };

// USA: func_ov024_021d923c
extern "C" ARM int func_ov024_021d923c(struct Struct_ov024_021d923c* param1, int arg1, int arg2, int unused4, int arg4, int arg5) {
    GameState* bs = GameState::GetInstance();
    GameObject* attacker = bs->GetCombatantByIndex(arg1);
    GameObject* var2 = bs->GetCombatantByIndex(arg2);
    if (attacker == NULL || var2 == NULL) {
        return arg5;
    }
    int var3 = (int)((float)attacker->currentStats_->primaryStats.currHP * 0.8f);
    *(int*)((char*)param1->field0 + 0x8e38) = var3 + 2;
    int var4 = (int)((float)var2->currentStats_->primaryStats.currHP * 0.8f);
    return var4;
}
