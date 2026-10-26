#include <globaldefs.h>

extern "C" unsigned short func_ov017_021d60f4(int a);
extern "C" int func_0203ad14(void* obj, int key, void* target, int arg3);
extern void* g_bgmPlayer;

// USA: func_ov001_02163518
extern "C" ARM int func_ov001_02163518(int a) {
    unsigned short v = func_ov017_021d60f4(a);
    func_0203ad14(&g_bgmPlayer, v, NULL, 0);
    return 1;
}
