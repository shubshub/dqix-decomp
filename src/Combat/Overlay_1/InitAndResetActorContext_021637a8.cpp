#include <globaldefs.h>

extern "C" short func_ov017_021d60f4(void* obj);
struct Actor0209c20c;
void InitActorContext0209c20c(struct Actor0209c20c* actor);
void ResetAndDispatchActorContext0209c6d8(void* actor, int arg);
extern struct Actor0209c20c g_bgmPlayer;

// USA: func_ov001_021637a8
ARM int InitAndResetActorContext_021637a8(void* obj) {
    short v = func_ov017_021d60f4(obj);
    InitActorContext0209c20c(&g_bgmPlayer);
    ResetAndDispatchActorContext0209c6d8(&g_bgmPlayer, v);
    return 1;
}
