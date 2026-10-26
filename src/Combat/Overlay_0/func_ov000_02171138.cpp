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

extern "C" int func_02053c6c(unsigned char* obj);

struct Obj0203c108;
extern "C" void CachedTextLabel_SetText(struct Obj0203c108* obj, char* fmt);

extern "C" void func_ov000_0216fe9c(void* obj);

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);

// USA: func_ov000_02171138
extern "C" ARM void func_ov000_02171138(void* objRaw) {
    char* obj = (char*)objRaw;
    int combatantId = *(int*)(obj + 0x4c);
    if (combatantId < 0) {
        return;
    }
    GameState* bs = GameState::GetInstance();
    combatantId = *(int*)(obj + 0x4c);
    GameObject* c = func_0200ff1c(bs, combatantId);
    if (!c) {
        return;
    }
    char* field150 = (char*)(int)func_02053c6c((unsigned char*)c);
    if (!field150) {
        return;
    }
    int off134 = *(int*)((char*)c + 0x134);
    CachedTextLabel_SetText((struct Obj0203c108*)(obj + REGION_OFFSET_0), (char*)off134);
    *(int*)(obj + REGION_OFFSET_1) = 2;
    int var6 = *(int*)(field150 + REGION_OFFSET_2);
    *(unsigned char*)(obj + REGION_OFFSET_3) = (unsigned char)var6;
    var6 = *(int*)(field150 + REGION_OFFSET_2);
    char* p = field150 + var6 * 2 + 0x100;
    unsigned short val = *(unsigned short*)(p + 0x6c);
    *(unsigned char*)(obj + REGION_OFFSET_4) = (unsigned char)val;

    short var9 = *(short*)(obj + 0xc);
    short var10 = *(short*)(obj + 0x8);
    short var11 = *(short*)(obj + 0xe);
    short var12 = *(short*)(obj + 0xa);
    func_ov000_0216fe9c(obj + 8);
    *(short*)(obj + 0xc) = var9;
    *(short*)(obj + 0x8) = var10;
    *(short*)(obj + 0xe) = var11;
    *(short*)(obj + 0xa) = var12;

    *(int*)(obj + 0x28) = *(int*)(field150 + 0xa8);
    *(unsigned char*)(obj + 0x1c) = 0;
    *(unsigned short*)(obj + REGION_OFFSET_5) = 0;
    *(unsigned short*)(obj + REGION_OFFSET_6) = 0;
    *(unsigned char*)(obj + REGION_OFFSET_7) = 0;
    int fieldVal = GameState_GetProtagonistIndex(bs);
    if (*(int*)(obj + 0x4c) == fieldVal) {
        *(unsigned char*)(obj + 0x24) |= 2;
    }
    *(unsigned char*)(obj + 0x24) &= ~1;
}
