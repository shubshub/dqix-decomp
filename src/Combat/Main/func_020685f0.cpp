#include <globaldefs.h>
#include "GameState/GameState.h"
extern "C" void* GameState_GetParty(GameState*);

struct Struct_020685f0 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

struct Struct_020685f0_2 {
    char pad[0xf78];
    unsigned char id;
};

// USA: func_020685f0
extern "C" ARM int func_020685f0(GameState* battleStruct) {
    unsigned char* p = (unsigned char*)GameState_GetParty(battleStruct);
    int i;
    for (i = 0; i < p[0xf7c]; i++) {
        GameObject* c = battleStruct->GetPartyMemberByIndex(((struct Struct_020685f0_2*)(p + i))->id);
        if (c != 0) {
            struct Struct_020685f0* sub = *(struct Struct_020685f0**)((char*)c + 0x150);
            if (sub->bit0 == 0) {
                return 1;
            }
        }
    }
    return 0;
}
