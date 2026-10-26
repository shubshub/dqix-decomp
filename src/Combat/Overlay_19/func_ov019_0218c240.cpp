#include <globaldefs.h>
#include "Input/Input.h"

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);

extern struct SePlayer g_sePlayer;

// USA: func_ov019_0218c240
extern "C" ARM int func_ov019_0218c240(void* scene) {
    if (!g_keyManager.TestKeysPressed(0x7f3)) {
        unsigned char v = g_touchInput.pressed_;
        if (v == 0) return 0;
    }
    SePlayer_Play(&g_sePlayer, 1, 0);
    return 1;
}
