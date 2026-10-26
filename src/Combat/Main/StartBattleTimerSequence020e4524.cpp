#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

int MessageSystem_GetInstance(void);
void MessageSystem_Reset(char* obj);
int GameState_GetFollowCamera(char* obj);
void ApplyVecFromField0x246_020a2718(char* actor);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" void FieldTask_EndGrottoBossIntro(char* obj);

// USA: func_020e4524
ARM void StartBattleTimerSequence020e4524(char* obj) {
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    ApplyVecFromField0x246_020a2718((char*)GameState_GetFollowCamera((char*)GameState::GetInstance()));
    SetMainBrightness(GetGameResources(), 0, 0x3c);
    FieldTask_EndGrottoBossIntro(obj);
}
