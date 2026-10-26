#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov003_021538f4
extern "C" ARM void func_ov003_021538f4(void* obj, int arg1) {
    unsigned char* o = (unsigned char*)obj;
    if (*(unsigned char*)(o + 0x5a) == 0) return;
    signed char b = *(signed char*)(o + 0x59);
    int ok = 0;
    if (b < 0) goto check;
    if (b <= 3) ok = 1;
check:
    if (!ok) return;
    if (arg1 <= 0) return;
    if (arg1 >= 0xd) return;
    if (*(int*)(o + 0x14) == arg1) return;

    int var3 = (int)BackgroundLoader::GetInstance();
    int var4 = *(int*)(o + 0x50);
    if (var4 >= 0) ((BackgroundLoader*)(var3))->RemoveTask((int)(var4));
    int var5 = *(int*)(o + 0x54);
    if (var5 >= 0) ((BackgroundLoader*)(var3))->RemoveTask((int)(var5));
    *(int*)(o + 0x50) = -1;
    *(int*)(o + 0x54) = -1;
    *(int*)(o + 0x14) = arg1;
    *(unsigned char*)(o + 0x5b) = 0;
    *(unsigned char*)(o + 0x5c) = 0;
    *(unsigned char*)(o + 0x5d) |= 1;
}
