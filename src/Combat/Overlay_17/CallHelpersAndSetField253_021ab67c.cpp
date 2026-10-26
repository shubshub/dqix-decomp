#include <globaldefs.h>
#include "GameState/GameState.h"

void GameObject_EnableControl(void* obj);

// USA: func_ov017_021ab67c
ARM void CallHelpersAndSetField253_021ab67c(unsigned char* obj) {
    obj[1] = 1;
    GameObject_EnableControl(GameState::GetInstance()->GetLeader());
}
