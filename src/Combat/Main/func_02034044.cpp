#include <globaldefs.h>
#include "World/Object3D.h"

extern "C" unsigned short* Zone3D_GetInstance(void);
struct SePlayer;
extern "C" void SePlayer_Play(struct SePlayer*, int, int);
extern int g_sePlayer;

// USA: func_02034044
extern "C" ARM void func_02034044(unsigned char* obj, int val) {
    unsigned short cur = *Zone3D_GetInstance();
    if (cur == ((Object3D*)((struct U16Field0x6_020375f8*)(obj)))->GetField06()) {
        SePlayer_Play((struct SePlayer*)&g_sePlayer, 0x60, 0);
    }
    *(unsigned short*)(obj + 0xc4) = (*(unsigned short*)(obj + 0xc4) & 0xFFFF8000) | (val & 0x7FFF);
}
