#include <globaldefs.h>

extern "C" void func_0209c5e8(void*);
extern "C" void func_0209c2e0(void*, int, int);
extern void* g_bgmPlayer;

// USA: func_ov001_021636a8
extern "C" ARM int func_ov001_021636a8(void) {
    func_0209c5e8(&g_bgmPlayer);
    func_0209c2e0(&g_bgmPlayer, 0x7f, 0);
    return 1;
}
