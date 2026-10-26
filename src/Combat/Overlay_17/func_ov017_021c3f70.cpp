#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" void* GameState_GetParty(GameState*);
extern "C" void func_ov017_021cbeb0(unsigned char a, unsigned short b);

struct PartyIdList_021c3f70 {
    char pad[0xf78];
    signed char id[4];
    unsigned char count;
};

// USA: func_ov017_021c3f70
extern "C" ARM void func_ov017_021c3f70(unsigned short tag) {
    GameState* battleStruct = GameState::GetInstance();
    struct PartyIdList_021c3f70* p = (struct PartyIdList_021c3f70*)GameState_GetParty(battleStruct);
    int i;
    for (i = 0; i < p->count; i++) {
        ((void (*)(int, unsigned short))func_ov017_021cbeb0)(p->id[i], tag);
    }
}
