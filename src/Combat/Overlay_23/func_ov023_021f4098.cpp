#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);

struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* arg0);

extern "C" int func_02053c6c(unsigned char* arg0);

extern "C" void __clear(void* arg0, int arg1);

extern "C" int func_020a35e0(unsigned char* arg0, unsigned char arg1);

struct Struct_02053dfc;
extern "C" int func_02053dfc(struct Struct_02053dfc* arg0);

unsigned short GameObject_GetPartyMemberLevel(void* obj);

int LinkSession_IsActive(int* obj);

struct SearchStruct;
int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);

extern "C" int func_ov023_021f5578(void* arg0, void* arg1, int arg2);

extern "C" int func_0208538c(unsigned char* arg0);

struct Struct_ov023_021f4098 { void* unknown_0_; int unknown_4_; };
extern "C" struct Struct_ov023_021f4098 _ZZ21inline_ov023_021f4c04vE1s;

// USA: func_ov023_021f4098
extern "C" ARM int func_ov023_021f4098(void* arg0, int arg1, int arg2) {
#if defined(jpn)
 enum {Enum_ov023_021f4098_2240=0xab0, Enum_ov023_021f4098_22528=0x5a00, Enum_ov023_021f4098_204=0xbc, Enum_ov023_021f4098_672=0x21c, Enum_ov023_021f4098_336=0x144};
#else
 enum {Enum_ov023_021f4098_2240=0x8c0, Enum_ov023_021f4098_22528=0x5800, Enum_ov023_021f4098_204=0xcc, Enum_ov023_021f4098_672=0x2a0, Enum_ov023_021f4098_336=0x150};
#endif
    GameState* battleStruct = GameState::GetInstance();
    struct SearchStruct* p = (struct SearchStruct*)LinkSession_GetInstance();
    GameObject* c9 = GetCombatantWithFlag0x100_0200ff1c(battleStruct, id);
    if (c9 == 0 || CheckField0x56bLowNibble((struct Obj02061bd8*)c9) != 0) {
        return 0;
    }
    if (func_02053c6c((unsigned char*)var2) == 0) {
        return 0;
    }

    float var3 = (float)(unsigned int)*(unsigned int*)((char*)arg0 + 0x5000 + Enum_ov023_021f4098_2240);
    float var4 = (float)(unsigned short)*(unsigned short*)((char*)arg0 + Enum_ov023_021f4098_22528 + Enum_ov023_021f4098_204);
    float var5[4];
    float var6[4];
    __clear(var5, 0x10);
    __clear(var6, 0x10);

    int i;
    for (i = 0; i < 4; i++) {
        if (TestBitAt0x34_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), i)) {
            GameObject* ci = GetCombatantWithFlag0x100_0200ff1c(battleStruct, i);
            if (ci != 0 && CheckField0x56bLowNibble((struct Obj02061bd8*)ci) == 0) {
                arrC[i] = (float)(unsigned int)GetField8FromField19c_02053dfc((struct Obj53dfc*)ci);
                arrB[i] = (float)(unsigned int)GameObject_GetPartyMemberLevel(ci);
            }
        }
    }

    float countF = 1.0f;
    if (LinkSession_IsActive((int*)p)) {
        countF = 0.0f;
        for (i = 0; i < 4; i++) {
            if (TestBitAt0x34_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), i) && LinkSession_IsSlotMember(p, i)) {
                countF += 1.0f;
            }
        }
    }

    if (arg2 != 0) {
        var3 = (float)(unsigned int)arg2;
    }

    float var10 = var3 * (1.0f + (var9 - 1.0f) / 10.0f);
    int var11 = (int)var10;
    int var12 = func_ov023_021f5578((char*)_ZZ21inline_ov023_021f4c04vE1s.unknown_0_ + 0xf4, (void*)var11, 4);

    float var13 = var6[3] * (var5[3] + (float)var12);
    float var14 = var6[2] * (var5[2] + (float)var12);
    float var15 = var6[0] * (var5[0] + (float)var12);
    float var16 = var6[1] * (var5[1] + (float)var12);
    float var17 = var13 + ((var15 + var16) + var14);

    if (var17 == 0.0f) {
        var17 = 1.0f;
    }

    float var18 = var3 * (1.0f + (var9 - 1.0f) / 10.0f);
    float var19 = ((float)var12 + var5[arg1]) * var6[arg1] / var17;
    float var20 = var18 * var19;

    if (func_0208538c(*(unsigned char**)((char*)var2 + Enum_ov023_021f4098_336))) {
        var20 *= 1.05f;
    }

    int var21 = (int)var20;
    float var22 = var20 - (float)var21;
    if (0.0f < var22) {
        var20 += 1.0f;
    }

    if (arg2 == 0) {
        for (arg2 = 0; arg2 < 4; arg2++) {
            if (func_020a35e0(*(unsigned char**)((char*)arg0 + Enum_ov023_021f4098_672), arg2)) {
                func_0200ff1c(var0, arg2);
            }
        }
    }

    return (int)var20;
}
