#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int MessageSystem_GetInstance(void);
extern "C" void MessageSystem_Reset(char* obj);
extern "C" int GameState_GetFollowCamera(char* obj);
extern "C" void func_020a2718(char* actor);
struct GameResources;
void SetMainBrightness(GameResources*, int, int);
extern "C" void FieldTask_EndGrottoBossIntro(char* obj);

// USA: func_020e4524
extern "C" ARM void func_020e4524(char* obj) {
    MessageSystem_Reset((char*)MessageSystem_GetInstance());
    func_020a2718((char*)GameState_GetFollowCamera((char*)GameState::GetInstance()));
    SetMainBrightness(GetGameResources(), 0, 0x3c);
    FieldTask_EndGrottoBossIntro(obj);
}
