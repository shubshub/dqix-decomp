#include <globaldefs.h>

extern "C" unsigned short func_ov017_021d60f4(int a);
int ScaleAndNotify0203ad88(void* obj, void* target, int arg2);
extern void* g_bgmPlayer;

// USA: func_ov001_02163540
ARM int ScaleAndNotifyFromField_02163540(int a) {
    unsigned short v = func_ov017_021d60f4(a);
    ScaleAndNotify0203ad88(&g_bgmPlayer, NULL, v);
    return 1;
}
