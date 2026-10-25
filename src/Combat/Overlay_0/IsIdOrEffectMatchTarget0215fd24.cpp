#include <globaldefs.h>
#include "GameState/GameState.h"

int GameState_GetProtagonistIndex(GameState* battleStruct);
int GetSignedByte0x2d0_020546a8(void* obj);
GameObject* GetCombatantWithFlag0x1000_0200ff58(GameState* battleStruct, int combatantId);

// USA: func_ov000_0215fd24
ARM int IsIdOrEffectMatchTarget0215fd24(int unused, int id) {
    GameState* bs = GameState::GetInstance();
    if (id == GameState_GetProtagonistIndex(bs)) return 1;
    GameObject* c = GetCombatantWithFlag0x1000_0200ff58(bs, id);
    if (c != NULL) {
        int signedByte = GetSignedByte0x2d0_020546a8(c);
        if (signedByte == GameState_GetProtagonistIndex(bs)) return 1;
    }
    return 0;
}
