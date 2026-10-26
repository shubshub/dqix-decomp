#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);
extern "C" void* __clear(void* dst, int count);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);

// USA: func_ov023_021e8f28
extern "C" ARM GameObject* func_ov023_021e8f28(int index) {
    GameState* battle = GameState::GetInstance();
    GameObject* result = 0;
    if (index >= 0) {
        int inRange = (index >= 0) && (index <= 3);
        if (inRange) {
            result = func_0200ff1c(battle, index);
        }
    } else {
        if (index == -1) {
            int key = GameState_GetProtagonistIndex(battle);
            result = func_0200ff1c(battle, key);
        } else {
            unsigned char local[4];
            __clear(local, 4);
            unsigned char count = GameState_GetOwnPartyOrder((char*)battle, local);
            int i = -1 - index;
            if (i < count) {
                result = func_0200ff1c(battle, local[i]);
            }
        }
    }
    return result;
}
