#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void FontBankLoader_CancelLoads(void);

extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" int FontBankLoader_GetInstance(void);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a27ac(void* obj);

// USA: func_020d9ab0
extern "C" ARM void func_020d9ab0(void* param) {
    GameState* bs = GameState::GetInstance();
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();
    func_020a27ac((void*)GameState_GetFollowCamera((char*)bs));
    *((unsigned char*)param + 1) = 1;
}
