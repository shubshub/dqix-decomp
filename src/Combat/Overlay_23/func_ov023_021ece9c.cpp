#include <globaldefs.h>
#include "GameState/GameState.h"


// USA: func_ov023_021ece9c
extern "C" ARM void func_ov023_021ece9c(char* obj) {
    unsigned short var0 = *(unsigned short*)(obj + 0x438);
    if (!(var0 & 0x80)) return;

    unsigned char counter = *(unsigned char*)(obj + 0x433);
    if (counter == 0) {
        *(short*)(obj + 0x448) = (short)~0x23;
        *(unsigned char*)(obj + 0x43c) = 0;
        *(unsigned char*)(obj + 0x433) = *(unsigned char*)(obj + 0x433) + 1;
    }
    if (counter != 1) return;

    *(unsigned short*)(obj + 0x438) = *(unsigned short*)(obj + 0x438) | 1;

    GameState* bs = GameState::GetInstance();
    unsigned int scaleCount = bs->GetTickCount();
    int sum = *(unsigned char*)(obj + 0x43c) + scaleCount;
    *(unsigned char*)(obj + 0x43c) = (unsigned char)sum;

    float f1 = (float)(unsigned int)(sum & 0xff);
    float f2 = f1 / 60.0f;
    float f3 = f2 * 292.0f;
    int var8 = (int)f3;
    *(short*)(obj + 0x448) = (short)(var8 - 0x24);

    if (*(short*)(obj + 0x448) > 0x100) {
        unsigned short flags = *(unsigned short*)(obj + 0x438);
        flags &= ~0x80;
        *(unsigned short*)(obj + 0x438) = flags;
        *(short*)(obj + 0x448) = (short)~0x23;
        *(unsigned char*)(obj + 0x43c) = 0;
        *(unsigned short*)(obj + 0x438) = *(unsigned short*)(obj + 0x438) | 2;
        *(unsigned char*)(obj + 0x433) = 0;
    }
}
