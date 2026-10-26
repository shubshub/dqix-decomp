#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(void);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" void GameObject_EnableControl(void* obj);
extern "C" void FieldTask_EndAcquireTreasureMap(int self);

// USA: func_ov017_021a9f58
extern "C" ARM void func_ov017_021a9f58(int selfParam) {
    GameState* battle = GameState::GetInstance();
    MessageSystem_Reset((char*)(long)MessageSystem_GetInstance());
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();
    SetMainBrightness(GetGameResources(), 0, 0x14);
    GameObject_EnableControl(battle->GetLeader());
    FieldTask_EndAcquireTreasureMap(selfParam);
}
