#include <globaldefs.h>
#include "GameState/GameState.h"

int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
GameObject* GetCombatantWithFlag0x100_0200ff1c(GameState* battleStruct, int combatantId);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void* LinkSession_GetInstance(void);
void* GameState_GetParty(GameState* battleStruct);
extern "C" int func_ov023_021f44d0(void* obj);

// USA: func_ov023_021f5150
extern "C" ARM int func_ov023_021f5150(void* arg0, unsigned char* arg1, int* arg2, int* arg3) {
#if defined(jpn)
 enum {Enum_ov023_021f5150_2384=0x8b8};
#else
 enum {Enum_ov023_021f5150_2384=0x950};
#endif
    GameState* bs = GameState::GetInstance();
    char* g = (char*)GameState_GetParty(bs);
    LinkSession_GetInstance();

    int var2 = 0;
    int var3;
    for (var3 = 0; var3 < 4; var3++) {
        if (!func_020a35e0(arg1, var3)) continue;
        var2 += arg2[var3];
        GameObject* var4 = func_0200ff1c(var0, var3);
        if (var4 == 0) continue;
        int var5 = func_02053c6c((unsigned char*)var4);
        if (var5 == 0) continue;
        int* var6 = (int*)var5;
        int var7 = *(int*)((char*)var6 + Enum_ov023_021f5150_2384);
        int* var8 = (int*)((char*)var6 + 0x138);
        var8[var7] += arg2[var3];
    }

    int var9 = func_ov023_021f44d0(arg0);
    *arg3 = var9;

    unsigned int var10 = 0x98967f;
    if (var10 - *(unsigned int*)(var1 + 0xf6c) < (unsigned int)var9) {
        *(unsigned int*)(var1 + 0xf6c) = var10;
    } else {
        *(unsigned int*)(var1 + 0xf6c) += var9;
    }

    return (var2 == 0 && *arg3 == 0) ? 1 : 0;
}
