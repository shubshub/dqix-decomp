#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState* battleStruct);
extern "C" GameObject* func_0200ff1c(GameState* battleStruct, int combatantId);
extern "C" int func_02053c6c(unsigned char* obj);

struct Struct_ov017_021d00c8 {
    int id;
    unsigned char idx;
    unsigned char count;
    short arr[6];
};

// USA: func_ov017_021d00c8
extern "C" ARM void func_ov017_021d00c8(int unused0, char* arg1, GameState* bs) {
    struct Struct_ov017_021d00c8* p1 = (struct Struct_ov017_021d00c8*)(arg1 + 4);
    int id = p1->id;
    unsigned char* list = (unsigned char*)GameState_GetParty(bs);
    int i;
    for (i = 0; i < list[0xf7c]; i++) {
        unsigned char* row = list + i;
        if (id == row[0xf78]) return;
    }

    GameObject* c = func_0200ff1c(bs, id);
    if (!c) return;
    int field150 = func_02053c6c((unsigned char*)c);
    if (!field150) return;

    char* dst = (char*)field150 + 0x454;
    unsigned char idx = p1->idx;
    unsigned char cnt = p1->count;
    for (int j = 0; j < cnt; j++) {
        *(short*)(dst + (idx + j) * 2) = p1->arr[j];
    }
}
