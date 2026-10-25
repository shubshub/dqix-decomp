#include <globaldefs.h>

extern "C" int func_ov017_021d60f4(void* obj);
void SePlayer_LoadExtraArchiveA(void* obj, int arg1, int arg2);
extern char g_sePlayer;

// USA: func_ov001_021637ec  (semantic: DispatchByMode_021637ec)
extern "C" ARM int func_ov001_021637ec(void* obj, int mode) {
    if (mode == 2) {
        int a = func_ov017_021d60f4(obj);
        int b = func_ov017_021d60f4((char*)obj + 8);
        SePlayer_LoadExtraArchiveA(&g_sePlayer, a, b);
    } else if (mode == 1) {
        int v = func_ov017_021d60f4(obj);
        SePlayer_LoadExtraArchiveA(&g_sePlayer, v, v);
    }
    return 1;
}
