#include <globaldefs.h>
#include "GameState/GameState.h"

// USA: func_ov017_021a20c0
extern "C" ARM int func_ov017_021a20c0(int unused, int mult, int limit) {
    GameState* battleStruct = GameState::GetInstance();
    if (limit > 0xc) limit = 0xc;
    int base = mult * 0xc;
    base = base + 0x70;
    for (int i = 0; i < limit; i++) {
        GameObject* combatant = battleStruct->GetGameObjectByIndex(i + base);
        if (combatant != NULL) {
            short v = combatant->obj3D_.unknown_2_;
            if (v < 0) return i + base;
        }
    }
    return -1;
}
