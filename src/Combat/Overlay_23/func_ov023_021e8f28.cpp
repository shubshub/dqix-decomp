#include <globaldefs.h>
#include "GameState/GameState.h"

int GameState_GetProtagonistIndex(GameState* battleStruct);
unsigned char GameState_GetOwnPartyOrder(char* obj, void* dst);
extern "C" void* __clear(void* dst, int count);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);

// USA: func_ov023_021e8f28
extern "C" ARM GameObject* func_ov023_021e8f28(int arg0) {
    GameState* var0 = GameState::GetInstance();
    GameObject* var1 = 0;
    if (arg0 >= 0) {
        int var2 = (arg0 >= 0) && (arg0 <= 3);
        if (var2) {
            var1 = func_0200ff1c(var0, arg0);
        }
    } else {
        if (index == -1) {
            int key = GameState_GetProtagonistIndex(battle);
            result = GetCombatantWithFlag0x100_0200ff1c(battle, key);
        } else {
            unsigned char local[4];
            __clear(local, 4);
            unsigned char count = GameState_GetOwnPartyOrder((char*)battle, local);
            int i = -1 - index;
            if (i < count) {
                result = GetCombatantWithFlag0x100_0200ff1c(battle, local[i]);
            }
        }
    }
    return var1;
}
