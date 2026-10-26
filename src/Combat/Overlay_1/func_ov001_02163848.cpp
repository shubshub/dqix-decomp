#include <globaldefs.h>

extern "C" void SePlayer_UnloadExtraArchiveA(void* obj);

extern int g_sePlayer;

// USA: func_ov001_02163848
extern "C" ARM int func_ov001_02163848(void) {
    SePlayer_UnloadExtraArchiveA(&g_sePlayer);
    return 1;
}
