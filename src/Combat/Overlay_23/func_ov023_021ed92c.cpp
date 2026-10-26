#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);

// USA: func_ov023_021ed92c
extern "C" ARM int func_ov023_021ed92c(void) {
    GameState* bs = GameState::GetInstance();
    unsigned char* base = (unsigned char*)GameState_GetParty(bs);
    for (int i = 0; i < base[0xf7c]; i++) {
        unsigned char* p = base + i;
        GameObject* combatant = func_0200ff1c(bs, p[0xf78]);
        if (combatant) {
            if (!func_02010088((struct S_10088*)combatant)) return 0;
        }
    }
    return 1;
}
