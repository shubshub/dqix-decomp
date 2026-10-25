#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern int g_sePlayer;
extern int g_bgmPlayer;
void ShutdownAndReinit0205e92c(void* obj);
void ResetAndReinit0209c278(void* obj);
int Dispatch0203a974With0xA2000_0209c2b8(void* ctx);
int Dispatch0203a974With0x57000_0209c290(void* ctx);
void SetupContextForMode0205ea20(void* objRaw, int mode);

// USA: func_ov001_02163a5c  (semantic: SelectModeAndDispatch_02163a5c)
extern "C" ARM int func_ov001_02163a5c(void* self) {
    int cond = func_ov017_021d60f4(self);
    if (cond != 0) {
        ShutdownAndReinit0205e92c(&g_sePlayer);
        ResetAndReinit0209c278(&g_bgmPlayer);
        Dispatch0203a974With0xA2000_0209c2b8(&g_bgmPlayer);
    } else {
        ResetAndReinit0209c278(&g_bgmPlayer);
        Dispatch0203a974With0x57000_0209c290(&g_bgmPlayer);
        SetupContextForMode0205ea20(&g_sePlayer, 0x64);
    }
    return 1;
}
