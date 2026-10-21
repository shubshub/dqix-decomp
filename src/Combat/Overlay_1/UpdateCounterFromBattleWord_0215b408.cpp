#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void*);
struct GameResources;
void SetSubBrightness(GameResources*, int, int);

// USA: func_ov001_0215b408
ARM int UpdateCounterFromBattleWord_0215b408(void* self, int mode) {
    int frames = func_ov017_021d60f4(self);
    if (mode >= 2) {
        func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = GameState::GetInstance();
    void* obj = (void*)((GameState*)battle)->GetResources();
    if (obj != NULL) {
        SetSubBrightness((GameResources*)obj, 0, frames);
        GetGameResources();
    }
    return 1;
}
