#include <globaldefs.h>
#include "GameState/GameState.h"


// USA: func_020dcc98
extern "C" ARM int func_020dcc98(int combatantId) {
    int result = 15;
    GameState* battle = GameState::GetInstance();
    GameObject* c = battle->GetPartyMemberByIndex(combatantId);
    if (c != 0) {
        float ratio;
        int maxHP = c->baseStats_->primaryStats.maxHP;
        if ((float)maxHP == 0.0f) {
            ratio = 0.0f;
        } else {
            int* p = *(int**)((char*)c + 0x130);
            int cur = *(unsigned short*)((char*)p + 4);
            ratio = (float)cur / (float)maxHP;
        }

        if (ratio <= 0.25f) {
            result = 13;
        }
        if (ratio <= 0.08f) {
            result = 11;
        }
        if (ratio == 0.0f) {
            result = 9;
        }
    }
    return result;
}
