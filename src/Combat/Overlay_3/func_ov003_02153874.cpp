#include <globaldefs.h>
#include "Filesystem/BackgroundLoader.h"


// USA: func_ov003_02153874
extern "C" ARM void func_ov003_02153874(void* obj) {
    int v = (int)BackgroundLoader::GetInstance();
    if (*(int*)((char*)obj + 0x50) >= 0) {
        ((BackgroundLoader*)(v))->RemoveTask((int)(*(int*)((char*)obj + 0x50)));
    }
    if (*(int*)((char*)obj + 0x54) >= 0) {
        ((BackgroundLoader*)(v))->RemoveTask((int)(*(int*)((char*)obj + 0x54)));
    }
    *(int*)((char*)obj + 0x14) = 0;
    *(int*)((char*)obj + 0x10) = 0;
    *(int*)((char*)obj + 0x50) = -1;
    *(int*)((char*)obj + 0x54) = -1;
    *(unsigned char*)((char*)obj + 0x5a) = 2;
    *(unsigned char*)((char*)obj + 0x5b) = 0;
    *(unsigned char*)((char*)obj + 0x5c) = 0;
    *(unsigned char*)((char*)obj + 0x5d) &= ~2;
}
