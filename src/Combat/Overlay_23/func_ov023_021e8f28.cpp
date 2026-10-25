#include <globaldefs.h>
#include "GameState/GameState.h"

int GameState_GetProtagonistIndex(GameState* battleStruct);
unsigned char CopyOutRegion0x5718_02011494(char* obj, void* dst);
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
            unsigned char var4[4];
            __clear(var4, 4);
            unsigned char var5 = func_02011494((char*)var0, var4);
            int var6 = -1 - arg0;
            if (var6 < var5) {
                var1 = func_0200ff1c(var0, var4[var6]);
            }
        }
    }
    return var1;
}
