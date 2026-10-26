#include <globaldefs.h>
#include "Input/Input.h"

#if defined(jpn)
#define func_ov013_021864f0 func_ov013_02187820
#define LOW_REGION(j, u) (j)
#else
#define LOW_REGION(j, u) (u)
#endif

extern "C" int MessageSystem_GetInstance();
extern "C" void MessageSystem_Reset(char* obj);

extern "C" void func_ov013_02186c64(void* obj, int a, int b);
extern "C" void func_ov013_02185cc0(void* obj);

// USA: func_ov013_021864f0
extern "C" ARM void func_ov013_021864f0(void* obj) {
    unsigned char* o = (unsigned char*)obj;
    o[LOW_REGION(0x644, 0x6bc)] &= ~1;
    if (o[LOW_REGION(0x5cb, 0x63f)] != 0) o[LOW_REGION(0x5c5, 0x639)] = 1;

    int g = MessageSystem_GetInstance();
    unsigned char* gp = (unsigned char*)g;
    gp[0x1000 + LOW_REGION(0x7ee, 0x9be)] = 1;

    if (!g_keyManager.TestKeysPressed(0x613) && !g_touchInput.IsPressed()) {
        return;
    }

    o[LOW_REGION(0x5c8, 0x63c)] = 1;
    g_keyManager.CancelCurrentKeyRepeat();
    MessageSystem_Reset((char*)gp);
    o[LOW_REGION(0x5c5, 0x639)] = 0;
    func_ov013_02186c64(obj, 0, 0);
    func_ov013_02185cc0(obj);
}
