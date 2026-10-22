#include <globaldefs.h>

void ForwardField0xc0_0205eb80(void* obj);

extern int g_sePlayer;

// USA: func_ov001_02163848
ARM int ForwardFieldC0Wrapper_02163848(void) {
    ForwardField0xc0_0205eb80(&g_sePlayer);
    return 1;
}
