#include <globaldefs.h>
#include "GameState/GameState.h"
#include "GameState/Field3b0.h"
#include "Input/Input.h"

extern "C" void FollowCamera_EnableFollow(void* obj);
extern "C" void FollowCamera_DisableFollow(void* obj);

// USA: func_ov015_021925a8
extern "C" ARM int func_ov015_021925a8() {
    GameState* battle = GameState::GetInstance();
    if (!battle) return 0;
    void* field = battle->GetCamera();
    if (!field) return 0;
    if (g_keyManager.TestKeysHeld(0xc00)) {
        FollowCamera_EnableFollow(field);
        return 1;
    }
    FollowCamera_DisableFollow(field);
    return 0;
}
