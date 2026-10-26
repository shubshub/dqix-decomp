#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_02053ec8(void*, int);

// USA: func_ov023_021f50fc
extern "C" ARM void func_ov023_021f50fc(void) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned char* list = (unsigned char*)GameState_GetParty(battleStruct);
    for (int i = 0; i < list[0xf7c]; i++) {
        unsigned char* p = list + i;
        GameObject* combatant = func_0200ff1c(battleStruct, p[0xf78]);
        if (combatant != 0) {
            func_02053ec8(combatant, 2);
        }
    }
}
