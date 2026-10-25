#include <globaldefs.h>

extern int g_bgmPlayer;
void ResetAndDispatchActorContext0209c6d8(void*, int);

// USA: func_ov025_021e8008  (semantic: Trans_021e8008)
extern "C" ARM int func_ov025_021e8008(void* self) {
    ResetAndDispatchActorContext0209c6d8(&g_bgmPlayer, *(int*)((char*)self + 0x8));
    return 1;
}
