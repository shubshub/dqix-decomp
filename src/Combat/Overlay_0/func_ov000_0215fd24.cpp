#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" int func_020546a8(void* obj);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);

// USA: func_ov000_0215fd24
extern "C" ARM int func_ov000_0215fd24(int unused, int id) {
    GameState* bs = GameState::GetInstance();
    if (id == GameState_GetProtagonistIndex(bs)) return 1;
    GameObject* c = func_0200ff58(bs, id);
    if (c != NULL) {
        int signedByte = func_020546a8(c);
        if (signedByte == GameState_GetProtagonistIndex(bs)) return 1;
    }
    return 0;
}
