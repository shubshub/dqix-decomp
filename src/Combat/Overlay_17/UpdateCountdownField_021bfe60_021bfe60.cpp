#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

void GameObject_EnableControl(void* obj);
int GameState_GetFollowCamera(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);

// USA: func_ov017_021bfe60
ARM int UpdateCountdownField_021bfe60_021bfe60(unsigned char* self) {
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
        SetField0x23cTrue_020a27ac((void*)flag);
    }
    if (ov != NULL) {
        ClearFlags04((GameResources*)ov, 0x80);
    }
    *field8 = 0x12c;
    return 6;
}
