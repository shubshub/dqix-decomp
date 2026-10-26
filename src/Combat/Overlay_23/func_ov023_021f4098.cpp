#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* LinkSession_GetInstance(void);

struct Struct_0205faf4_11;
extern "C" int func_02061bd8(struct Struct_0205faf4_11* obj);

extern "C" int func_02053c6c(unsigned char* obj);

extern "C" void __clear(void* buf, int len);

extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);

struct Struct_02053dfc;
extern "C" int func_02053dfc(struct Struct_02053dfc* obj);

extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);

extern "C" int LinkSession_IsActive(int* obj);

struct SearchStruct;
extern "C" int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);

extern "C" int func_ov023_021f5578(void* a, void* b, int arg2);

extern "C" int func_0208538c(unsigned char* obj);

struct Struct_ov023_021f4098 { void* field0; int field4; };
extern "C" struct Struct_ov023_021f4098 _ZZ21inline_ov023_021f4c04vE1s;

// USA: func_ov023_021f4098
extern "C" ARM int func_ov023_021f4098(void* obj, int id, int flag) {
#if defined(jpn)
 enum {regionalOffset0=0xab0, regionalOffset1=0x5a00, regionalOffset2=0xbc, regionalOffset3=0x21c, regionalOffset4=0x144};
#else
 enum {regionalOffset0=0x8c0, regionalOffset1=0x5800, regionalOffset2=0xcc, regionalOffset3=0x2a0, regionalOffset4=0x150};
#endif
    GameState* battleStruct = GameState::GetInstance();
    struct SearchStruct* p = (struct SearchStruct*)LinkSession_GetInstance();
    GameObject* var2 = func_0200ff1c(battleStruct, id);
    if (var2 == 0 || func_02061bd8((struct Struct_0205faf4_11*)var2) != 0) {
        return 0;
    }
    if (func_02053c6c((unsigned char*)var2) == 0) {
        return 0;
    }

    float var3 = (float)(unsigned int)*(unsigned int*)((char*)obj + 0x5000 + regionalOffset0);
    float var4 = (float)(unsigned short)*(unsigned short*)((char*)obj + regionalOffset1 + regionalOffset2);
    float arrB[4];
    float var6[4];
    __clear(arrB, 0x10);
    __clear(var6, 0x10);

    int i;
    for (i = 0; i < 4; i++) {
        if (func_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), i)) {
            GameObject* ci = func_0200ff1c(battleStruct, i);
            if (ci != 0 && func_02061bd8((struct Struct_0205faf4_11*)ci) == 0) {
                var6[i] = (float)(unsigned int)func_02053dfc((struct Struct_02053dfc*)ci);
                arrB[i] = (float)(unsigned int)GameObject_GetPartyMemberLevel(ci);
            }
        }
    }

    float var9 = 1.0f;
    if (LinkSession_IsActive((int*)p)) {
        var9 = 0.0f;
        for (i = 0; i < 4; i++) {
            if (func_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), i) && LinkSession_IsSlotMember(p, i)) {
                var9 += 1.0f;
            }
        }
    }

    if (flag != 0) {
        var3 = (float)(unsigned int)flag;
    }

    float var10 = var3 * (1.0f + (var9 - 1.0f) / 10.0f);
    int var11 = (int)var10;
    int var12 = func_ov023_021f5578((char*)_ZZ21inline_ov023_021f4c04vE1s.field0 + 0xf4, (void*)var11, 4);

    float var13 = var6[3] * (arrB[3] + (float)var12);
    float temp2 = var6[2] * (arrB[2] + (float)var12);
    float var15 = var6[0] * (arrB[0] + (float)var12);
    float var16 = var6[1] * (arrB[1] + (float)var12);
    float total = var13 + ((var15 + var16) + temp2);

    if (total == 0.0f) {
        total = 1.0f;
    }

    float var18 = var3 * (1.0f + (var9 - 1.0f) / 10.0f);
    float normalized = ((float)var12 + arrB[id]) * var6[id] / total;
    float result = var18 * normalized;

    if (func_0208538c(*(unsigned char**)((char*)var2 + regionalOffset4))) {
        result *= 1.05f;
    }

    int var21 = (int)result;
    float var22 = result - (float)var21;
    if (0.0f < var22) {
        result += 1.0f;
    }

    if (flag == 0) {
        for (flag = 0; flag < 4; flag++) {
            if (func_020a35e0(*(unsigned char**)((char*)obj + regionalOffset3), flag)) {
                func_0200ff1c(battleStruct, flag);
            }
        }
    }

    return (int)result;
}
