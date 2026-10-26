#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" void* func_02053c6c(unsigned char* obj);
extern "C" int RandomIntBelow(int max);

struct RandomTargetTable021970a0 {
    char pad[0xf78];
    unsigned char ids[4];
    unsigned char count;
};

struct Struct_ov017_021970a0_2 {
    unsigned int unknown_0_0_ : 10;
    unsigned int rest : 22;
};

// USA: func_ov017_021970a0
extern "C" ARM int func_ov017_021970a0(int mode) {
    GameState* battleStruct = GameState::GetInstance();
    GetBTRandom();
    struct RandomTargetTable021970a0* table = (struct RandomTargetTable021970a0*)GameState_GetParty(battleStruct);

    int var2 = 0;
    for (int i = 0; i < table->count; i++) {
        GameObject* c = func_0200ff1c(battleStruct, table->ids[i]);
        if (c == NULL) continue;
        int* var5 = *(int**)((char*)c + 0x130);
        if (*var5 & 1) continue;
        void* fp = func_02053c6c((unsigned char*)c);
        if (fp == NULL) continue;
        unsigned int v = ((struct Struct_ov017_021970a0_2*)((char*)fp + 4))->unknown_0_0_;
        if (var2 < v) var2 = v;
    }

    if (mode != 2) {
        float extra = (mode == 1) ? 10.0f : 0.0f;
        float threshold = 2.0f + 0.05f * (float)var2 + extra;
        int t = (int)threshold;
        if (RandomIntBelow(100) < t) return 1;
    }
    if (mode == 1) goto ret0;

    {
        float var11 = (mode == 2) ? 10.0f : 0.0f;
        float var12 = 2.0f + var11;
        int t2 = (int)var12;
        if (RandomIntBelow(100) < t2) return 2;
    }
ret0:
    return 0;
}
