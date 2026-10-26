#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

// USA: func_ov000_02163c0c
#pragma optimize_for_size off
extern "C" ARM int func_ov000_02163c0c(void* unused, int id) {
    GameState* battle = GameState::GetInstance();
    int var1 = (id >= 0xc0 && id <= 0xc7);
    GameObject* c;
    int x;
    short state;
    if (!var1) goto fail;
    c = func_0200fea4(battle, id);
    if (!c) goto fail;
    x = 0x1fd;
    state = c->obj3D_.unknown_2_;
    if (state == x || state == x + 1 || (unsigned int)(state - 0x308) <= 3) return 1;
fail:
    return 0;
}
