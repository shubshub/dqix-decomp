#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Resource/GameResources.h"

unsigned char GetByte0x4_0200fb9c(char* obj);
void SetBrightness(GameResources*, int, int);
struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);
extern int g_bgmPlayer;
extern "C" int _s32_div_f(int a, int b);

// USA: func_ov004_0216da58  (semantic: SyncCountersAndDispatchContext_0216da58)
extern "C" ARM int func_ov004_0216da58() {
    GameState* bs = GameState::GetInstance();
    GameResources* obj = GetGameResources();
    int frames = _s32_div_f(1000, 0x22);
    if (GetByte0x4_0200fb9c((char*)bs) == 8) {
        SetBrightness(obj, 0x10, frames);
    } else {
        SetBrightness(obj, -16, frames);
    }
    if (GetByte0x4_0200fb9c((char*)bs) != 2) {
        BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, 0x10);
    }
    return 0;
}
