#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int func_020882f8(unsigned char* obj);

// USA: func_ov024_021d8db4
extern "C" ARM int func_ov024_021d8db4(int a, int b, int id, int c, int d, int arg5) {
    GameState* battleStruct = GameState::GetInstance();
    GameObject* combatant = battleStruct->GetCombatantByIndex(id);
    if (combatant == NULL) {
        return arg5;
    }
    if (func_020882f8((unsigned char*)combatant->currentStats_) ||
        (*(int*)((char*)combatant->currentStats_ + 0x14) & 0x20) != 0) {
        return (int)(arg5 * 2.0f);
    }
    return arg5;
}
