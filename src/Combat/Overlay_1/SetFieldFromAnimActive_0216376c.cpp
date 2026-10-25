#include <globaldefs.h>

int IsAnimationActive0209ca2c(void* obj);
extern "C" void func_ov017_021d6134(void*, unsigned int);
extern void* g_bgmPlayer;

// USA: func_ov001_0216376c
ARM int SetFieldFromAnimActive_0216376c(void* obj) {
    if (IsAnimationActive0209ca2c(&g_bgmPlayer)) {
        func_ov017_021d6134(obj, 1);
    } else {
        func_ov017_021d6134(obj, 0);
    }
    return 1;
}
