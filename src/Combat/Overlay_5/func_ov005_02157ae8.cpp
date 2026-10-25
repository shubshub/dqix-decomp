#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int* func_0202ae18(GameState* gs);
int CheckField0NonZero_0202b7d8(int* p);
int GameState_GetProtagonistIndex(GameState* gs);
void* GetCombatantWithFlag0x1000_0200ff58(GameState* gs, int idx);
int GetSignedByte0x2d0_020546a8(void* p);

// USA: func_ov005_02157ae8
extern "C" ARM int func_ov005_02157ae8(void* arg0, int arg1) {
    GameState* var0 = GameState::GetInstance();
    if (func_0202b7d8(func_0202ae18(var0))) {
        GameObject* var1 = var0->GetGameObjectByIndex(arg1);
        if (var1 == NULL)
            return 0;
        unsigned short flags = object->obj3D_.unknown_0_;
        int leader = GameState_GetProtagonistIndex(gameState);
        if (flags & 0x200) {
            if (member != leader)
                return 0;
        } else if (var2 & 0x1000) {
            if (var3 != func_020546a8(func_0200ff58(var0, arg1)))
                return 0;
        }
    }
    return 1;
}
