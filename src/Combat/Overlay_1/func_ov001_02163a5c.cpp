#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void*);
extern int g_sePlayer;
extern int g_bgmPlayer;
extern "C" void func_0205e92c(void* obj);
extern "C" void func_0209c278(void* obj);
extern "C" int func_0209c2b8(void* ctx);
extern "C" int BgmPlayer_LoadArchive(void* ctx);
extern "C" void SePlayer_LoadArchive(void* objRaw, int mode);

// USA: func_ov001_02163a5c
extern "C" ARM int func_ov001_02163a5c(void* self) {
    int cond = func_ov017_021d60f4(self);
    if (cond != 0) {
        func_0205e92c(&g_sePlayer);
        func_0209c278(&g_bgmPlayer);
        func_0209c2b8(&g_bgmPlayer);
    } else {
        func_0209c278(&g_bgmPlayer);
        BgmPlayer_LoadArchive(&g_bgmPlayer);
        SePlayer_LoadArchive(&g_sePlayer, 0x64);
    }
    return 1;
}
