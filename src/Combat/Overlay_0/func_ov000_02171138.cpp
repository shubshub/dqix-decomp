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

struct Struct_0203c108_3;
extern "C" void func_0203c108(struct Struct_0203c108_3* arg0, char* arg1);

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
    int var5 = *(int*)((char*)var3 + 0x134);
    func_0203c108((struct Struct_0203c108_3*)(var0 + REGION_OFFSET_0), (char*)var5);
    *(int*)(var0 + REGION_OFFSET_1) = 2;
    int var6 = *(int*)(var4 + REGION_OFFSET_2);
    *(unsigned char*)(var0 + REGION_OFFSET_3) = (unsigned char)var6;
    var6 = *(int*)(var4 + REGION_OFFSET_2);
    char* var7 = var4 + var6 * 2 + 0x100;
    unsigned short var8 = *(unsigned short*)(var7 + 0x6c);
    *(unsigned char*)(var0 + REGION_OFFSET_4) = (unsigned char)var8;

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
