#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_02191fec(int a, int combatantId);

// USA: func_ov017_021c1264
extern "C" ARM void func_ov017_021c1264(void) {
    GameState* battleStruct = GameState::GetInstance();
    int a = ((int)GetGameResources());
    for (int i = 0; i < 4; i++) {
        if (battleStruct->GetPartyMemberByIndex(i) != NULL) {
            func_ov017_02191fec(a, i);
        }
    }
}
