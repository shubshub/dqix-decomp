#include <globaldefs.h>

extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_0209cd50(int key);
struct Actor0209c3b4;
extern "C" void func_0209c3b4(struct Actor0209c3b4* actor, int val);
extern void* g_bgmPlayer;

// USA: func_ov001_02163aec
extern "C" ARM int func_ov001_02163aec(void) {
    unsigned short key = *(unsigned short*)Zone3D_GetInstance();
    int v = func_0209cd50(key);
    func_0209c3b4((struct Actor0209c3b4*)&g_bgmPlayer, v);
    return 1;
}
