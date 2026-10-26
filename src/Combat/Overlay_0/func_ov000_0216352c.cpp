#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

// USA: func_ov000_0216352c
extern "C" ARM short func_ov000_0216352c(int id, float a, float b) {
    GameState* bs = GameState::GetInstance();
    int inRange = (id >= 0xc0 && id <= 0xc7);
    if (!(inRange && bs != NULL)) {
        return 0x10a;
    }
    GameObject* c = func_0200fea4(bs, id);
    if (c == NULL) {
        return 0x10a;
    }
    short var3 = *(short*)((char*)c + 0x100 + 0x8e);
    int lo = (int)(a * 4096.0f);
    if (var3 <= lo) {
        return var3;
    }
    int hi = (int)(b * 4096.0f);
    int delta = var3 - lo;
    int rounded = (int)(((long long)delta * hi + 0x800) >> 12);
    return (short)(lo + rounded);
}
