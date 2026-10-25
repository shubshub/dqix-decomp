#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);

struct Actor0209c678;
void BgmPlayer_FadeOut(struct Actor0209c678* actor, int arg);

extern int g_bgmPlayer;

// USA: func_ov001_0216393c
ARM int DispatchContextWithComputedArg_0216393c(void* obj, int val) {
    int arg = 0x1e;
    if (val > 0) arg = func_ov017_021d60f4(obj);
    BgmPlayer_FadeOut((struct Actor0209c678*)&g_bgmPlayer, arg);
    return 1;
}
