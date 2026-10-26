#include <globaldefs.h>
#include "GameState/GameState.h"

struct AngleTrig0202e9a4;
extern "C" void CharacterModel_Destroy(void*);
extern "C" int GameState_GetFollowCamera(char*);
extern "C" void FollowCamera_EnableFollow(void*);
extern "C" void Camera_SetFieldOfView(struct AngleTrig0202e9a4*, int);

// USA: func_ov023_021fc6cc
extern "C" ARM void func_ov023_021fc6cc(void* obj) {
    for (int i = 0; i < 2; i++) {
        CharacterModel_Destroy((char*)obj + 0x20 + i * 0xc20);
    }
    void* p = (void*)GameState_GetFollowCamera((char*)GameState::GetInstance());
    FollowCamera_EnableFollow(p);
    Camera_SetFieldOfView((struct AngleTrig0202e9a4*)p, *(int*)((char*)obj + 0x1000 + 0x860));
}
