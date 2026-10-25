#include <globaldefs.h>

struct Actor0209c20c;
void InitActorContext0209c20c(struct Actor0209c20c* actor);

extern struct Actor0209c20c g_bgmPlayer;

// USA: func_ov001_021637d4
ARM int InitActorContextWrapper_021637d4(void) {
    InitActorContext0209c20c(&g_bgmPlayer);
    return 1;
}
