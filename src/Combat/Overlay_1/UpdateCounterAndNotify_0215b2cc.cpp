#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

extern "C" int func_ov017_021d60f4(void*);
struct GameResources;
void SetBrightness(GameResources*, int, int);

// USA: func_ov001_0215b2cc  (semantic: UpdateCounterAndNotify_0215b2cc)
extern "C" ARM int func_ov001_0215b2cc(void* self, int mode) {
    int frames = func_ov017_021d60f4(self);
    if (mode >= 2) {
        func_ov017_021d60f4((char*)self + 0x8);
    }
    void* battle = GameState::GetInstance();
    void* obj = (void*)((GameState*)battle)->GetResources();
    if (obj != NULL) {
        SetBrightness((GameResources*)obj, 0, frames);
        GetGameResources();
    }
    return 1;
}
