#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"

extern "C" int func_0209ca2c(void* obj);
extern int g_bgmPlayer;

// USA: func_ov003_0215c510
extern "C" ARM void func_ov003_0215c510(char* obj) {
    if (func_0209ca2c(&g_bgmPlayer) != 0) return;
    if (*(unsigned char*)(obj + 0x59d) != 0) return;

    int x = (int)BackgroundLoader::GetInstance();
    ((BackgroundLoader*)(x))->FreeAllocations();
    ((BackgroundLoader*)(x))->RemoveTask((int)(*(int*)(obj + 0x578)));
    *(int*)(obj + 0x578) = -1;
    *(unsigned char*)(obj + 0x588) = 0xb;
    *(unsigned char*)(obj + 0x580) = 0;
}
