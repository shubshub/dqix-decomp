#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/Brightness.h"

extern "C" void func_ov003_0217f118(void* obj);
void GameObject_EnableControl(void* obj);
int GameState_GetFollowCamera(char* obj);
void SetField0x23cTrue_020a27ac(void* obj);
void ClearFlagBits_020a28b0(unsigned char* obj, int mask);

// USA: func_ov003_0217f1b8
ARM void InitObjAndClearFlags_0217f1b8(unsigned char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    unsigned int* p = (unsigned int*)((int)GetGameResources());
    func_ov003_0217f118(obj);
    GameObject_EnableControl(battleStruct->GetLeader());
    int f = GameState_GetFollowCamera((char*)battleStruct);
    SetField0x23cTrue_020a27ac((void*)f);
    ClearFlagBits_020a28b0((unsigned char*)f, 2);
    ClearFlags04((GameResources*)p, 0xc0);
    obj[1] = 1;
}
