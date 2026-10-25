#include <globaldefs.h>

void SePlayer_UnloadExtraArchiveA(void* obj);

extern int g_sePlayer;

// USA: func_ov001_02163848
ARM int ForwardFieldC0Wrapper_02163848(void) {
    SePlayer_UnloadExtraArchiveA(&g_sePlayer);
    return 1;
}
