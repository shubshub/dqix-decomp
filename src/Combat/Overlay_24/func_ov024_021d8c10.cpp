#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov024_021d8c10
extern "C" ARM int func_ov024_021d8c10(char** arg0, int id, int a2, int a3, int a4, int val) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetCombatantByIndex(id);
    if (!c) return val;
    int flags = *(int*)((char*)c->currentStats_ + 0x18);
    if (flags & 0x200) {
        return *(short*)(*arg0 + 0x8e00 + 0x54);
    }
    return (int)((float)(*(short*)(*arg0 + 0x8e00 + 0x54)) * 1.5f);
}
