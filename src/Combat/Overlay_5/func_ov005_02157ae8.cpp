#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int* LinkSession_GetInstance(GameState* gs);
int LinkSession_IsActive(int* p);
int GameState_GetProtagonistIndex(GameState* gs);
void* GetCombatantWithFlag0x1000_0200ff58(GameState* gs, int idx);
int GetSignedByte0x2d0_020546a8(void* p);

// USA: func_ov005_02157ae8
extern "C" ARM int func_ov005_02157ae8(void* self, int member) {
    GameState* gameState = GameState::GetInstance();
    if (LinkSession_IsActive(LinkSession_GetInstance(gameState))) {
        GameObject* object = gameState->GetGameObjectByIndex(member);
        if (object == NULL)
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
