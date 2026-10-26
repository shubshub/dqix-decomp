#include <globaldefs.h>
#include "Input/Input.h"

extern "C" int MessageSystem_GetInstance(void);

struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer* obj, int a, int b);
extern struct SePlayer g_sePlayer;

// USA: func_ov023_021f4fc8
extern "C" ARM int func_ov023_021f4fc8(void) {
#if defined(jpn)
 enum {regionalOffset0=0x870, regionalOffset1=0x868};
#else
 enum {regionalOffset0=0x9a0, regionalOffset1=0x998};
#endif
    void* obj = (void*)MessageSystem_GetInstance();
    int state = *(int*)((char*)obj + regionalOffset0);
    int flag = 0;
    if (state == 3 || state == 0) {
        if (g_keyManager.TestKeysPressed(0x1)
            || g_keyManager.TestKeysPressed(0x2)
            || g_keyManager.TestKeysPressed(0x200)
            || g_keyManager.TestKeysPressed(0x100)
            || g_keyManager.TestKeysPressed(0x400)
            || g_keyManager.TestKeysPressed(0x40)
            || g_keyManager.TestKeysPressed(0x80)
            || g_keyManager.TestKeysPressed(0x20)
            || g_keyManager.TestKeysPressed(0x10)) {
            flag = 1;
        }
        if (g_touchInput.released_) flag = 1;
    }
    if (flag) {
        SePlayer_Play(&g_sePlayer, 1, 0);
        return 1;
    }
    int result = *(int*)((char*)obj + regionalOffset1) == 0;
    return result != 0;
}
