#include <globaldefs.h>

extern "C" short func_ov017_021d60f4(void* obj);
struct Actor0209c20c;
extern "C" void func_0209c20c(struct Actor0209c20c* actor);
extern "C" void func_0209c6d8(void* actor, int arg);
extern struct Actor0209c20c g_bgmPlayer;

// USA: func_ov001_021637a8
extern "C" ARM int func_ov001_021637a8(void* obj) {
    short v = func_ov017_021d60f4(obj);
    func_0209c20c(&g_bgmPlayer);
    func_0209c6d8(&g_bgmPlayer, v);
    return 1;
}
