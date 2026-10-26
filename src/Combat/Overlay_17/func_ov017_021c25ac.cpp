#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" int LinkSession_IsHostOrSolo(void* p);
extern "C" void func_ov017_021c2380(int a, int b);
extern "C" unsigned char GameObject_IsControlEnabled(void* obj);
extern "C" int GameObject_IsGesturing(signed char* obj);
extern "C" unsigned char GameState_GetLeaderIndex(GameState* battleStruct);

// USA: func_ov017_021c25ac
extern "C" ARM void func_ov017_021c25ac() {
    GameState* bs = GameState::GetInstance();
    void* search = LinkSession_GetInstance();
    GameObject* c = bs->GetLeader();
    if (c != 0 && GameObject_IsControlEnabled(c) != 0 && GameObject_IsGesturing((signed char*)c) == 0) {
        for (int i = 0; i < 4; i++) {
            func_ov017_021c2380(i, GameState_GetLeaderIndex(bs));
        }
    }
    if (LinkSession_IsHostOrSolo(search) != 0) {
        for (int a = 0; a < 4; a++) {
            for (int b = 0; b < 0x30; b++) {
                func_ov017_021c2380(a, b + 0x70);
            }
        }
    } else {
        for (int i = 0; i < 0x30; i++) {
            func_ov017_021c2380(GameState_GetLeaderIndex(bs), i + 0x70);
        }
    }
}
