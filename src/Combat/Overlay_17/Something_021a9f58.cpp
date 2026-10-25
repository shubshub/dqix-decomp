#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
int FontBankLoader_GetInstance(void);
extern "C" void FontBankLoader_CancelLoads(void);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
void GameObject_EnableControl(void* obj);
extern "C" void FieldTask_EndAcquireTreasureMap(int self);

// USA: func_ov017_021a9f58
ARM void Something_021a9f58(int selfParam) {
    GameState* battle = GameState::GetInstance();
    MessageSystem_Reset((char*)(long)MessageSystem_GetInstance());
    FontBankLoader_GetInstance();
    FontBankLoader_CancelLoads();
    SetMainBrightness(GetGameResources(), 0, 0x14);
    GameObject_EnableControl(battle->GetUnknownGameObject());
    FieldTask_EndAcquireTreasureMap(selfParam);
}
