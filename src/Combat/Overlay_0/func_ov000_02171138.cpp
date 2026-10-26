#include <globaldefs.h>

#if defined(jpn)
#define REGION_OFFSET_0 0x88
#define REGION_OFFSET_1 0x78
#define REGION_OFFSET_2 0x8b8
#define REGION_OFFSET_3 0x480
#define REGION_OFFSET_4 0x47f
#define REGION_OFFSET_5 0xc2
#define REGION_OFFSET_6 0xc4
#define REGION_OFFSET_7 0xc6
#else
#define REGION_OFFSET_0 0x68
#define REGION_OFFSET_1 0x5c
#define REGION_OFFSET_2 0x950
#define REGION_OFFSET_3 0x440
#define REGION_OFFSET_4 0x43f
#define REGION_OFFSET_5 0x82
#define REGION_OFFSET_6 0x84
#define REGION_OFFSET_7 0x86
#endif

#include "GameState/GameState.h"

extern "C" int func_02053c6c(unsigned char* arg0);

struct Obj0203c108;
void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" void func_ov000_0216fe9c(void* arg0);

int GameState_GetProtagonistIndex(GameState* battleStruct);

// USA: func_ov000_02171138
extern "C" ARM void func_ov000_02171138(void* arg0) {
    char* var0 = (char*)arg0;
    int var1 = *(int*)(var0 + 0x4c);
    if (var1 < 0) {
        return;
    }
    GameState* var2 = GameState::GetInstance();
    var1 = *(int*)(var0 + 0x4c);
    GameObject* var3 = func_0200ff1c(var2, var1);
    if (!var3) {
        return;
    }
    char* var4 = (char*)(int)func_02053c6c((unsigned char*)var3);
    if (!var4) {
        return;
    }
    int off134 = *(int*)((char*)c + 0x134);
    CachedTextLabel_SetText((struct Obj0203c108*)(obj + REGION_OFFSET_0), (char*)off134);
    *(int*)(obj + REGION_OFFSET_1) = 2;
    int idx950 = *(int*)(field150 + REGION_OFFSET_2);
    *(unsigned char*)(obj + REGION_OFFSET_3) = (unsigned char)idx950;
    idx950 = *(int*)(field150 + REGION_OFFSET_2);
    char* p = field150 + idx950 * 2 + 0x100;
    unsigned short val = *(unsigned short*)(p + 0x6c);
    *(unsigned char*)(obj + REGION_OFFSET_4) = (unsigned char)val;

    short var9 = *(short*)(var0 + 0xc);
    short var10 = *(short*)(var0 + 0x8);
    short var11 = *(short*)(var0 + 0xe);
    short var12 = *(short*)(var0 + 0xa);
    func_ov000_0216fe9c(var0 + 8);
    *(short*)(var0 + 0xc) = var9;
    *(short*)(var0 + 0x8) = var10;
    *(short*)(var0 + 0xe) = var11;
    *(short*)(var0 + 0xa) = var12;

    *(int*)(obj + 0x28) = *(int*)(field150 + 0xa8);
    *(unsigned char*)(obj + 0x1c) = 0;
    *(unsigned short*)(obj + REGION_OFFSET_5) = 0;
    *(unsigned short*)(obj + REGION_OFFSET_6) = 0;
    *(unsigned char*)(obj + REGION_OFFSET_7) = 0;
    int fieldVal = GameState_GetProtagonistIndex(bs);
    if (*(int*)(obj + 0x4c) == fieldVal) {
        *(unsigned char*)(obj + 0x24) |= 2;
    }
    *(unsigned char*)(var0 + 0x24) &= ~1;
}
