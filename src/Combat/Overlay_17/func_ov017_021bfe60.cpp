#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void GameObject_EnableControl(void* obj);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27ac(void* obj);

// USA: func_ov017_021bfe60
extern "C" ARM int func_ov017_021bfe60(unsigned char* self) {
    GameState* battle = GameState::GetInstance();
    int value = battle->GetEffectiveDeltaTime();
    unsigned short* field8 = (unsigned short*)(self + 8);
    if ((unsigned int)value < (unsigned int)*field8) {
        *field8 = *field8 - value;
        return 5;
    }

    *field8 = 0;
    GameObject* combatant = battle->GetLeader();
    if (combatant != NULL) {
        GameObject_EnableControl(combatant);
    }
    void* ov = GetGameResources();
    int flag = GameState_GetFollowCamera((char*)battle);
    if (flag != 0) {
        func_020a27ac((void*)flag);
    }
    if (ov != NULL) {
        ClearFlags04((GameResources*)ov, 0x80);
    }
    *field8 = 0x12c;
    return 6;
}
