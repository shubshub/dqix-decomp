#include <globaldefs.h>
#include "GameState/GameState.h"


// USA: func_ov003_02155fc0
extern "C" ARM int func_ov003_02155fc0(void* unused, int combatantId) {
    GameState* bs = GameState::GetInstance();
    GameObject* c = bs->GetPartyMemberByIndex(combatantId);
    int result;
    if (c != NULL) {
        unsigned int* p = *(unsigned int**)((char*)c + 0x130);
        result = (*p & 1) != 0;
    } else {
        result = 0;
    }
    return result;
}
