#include <globaldefs.h>

struct Actor0209c20c;
extern "C" void func_0209c20c(struct Actor0209c20c* actor);

extern struct Actor0209c20c g_bgmPlayer;

// USA: func_ov001_021637d4
extern "C" ARM int func_ov001_021637d4(void) {
    func_0209c20c(&g_bgmPlayer);
    return 1;
}
