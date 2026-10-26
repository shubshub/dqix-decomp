#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void FontBankLoader_CancelLoads(void);

int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
int FontBankLoader_GetInstance(void);
int GameState_GetFollowCamera(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);

// USA: func_020d9ab0
ARM void InitBattleAndControllerState_020d9ab0(void* param) {
    GameState* bs = GameState::GetInstance();
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();
    SetField0x23cTrue_020a27ac((void*)GameState_GetFollowCamera((char*)bs));
    *((unsigned char*)param + 1) = 1;
}
