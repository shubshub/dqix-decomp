#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" int GameState_GetProtagonistIndex(GameState* battleStruct);
extern "C" void GameObject_ResetTrail(unsigned char* obj);

struct PartyRoster02161480 {
    char pad0[0xf78];
    unsigned char memberIds[4];
    unsigned char memberCount;
};

// USA: func_ov003_02161480
extern "C" ARM void func_ov003_02161480(void) {
    GameState* bs = GameState::GetInstance();
    struct PartyRoster02161480* roster = (struct PartyRoster02161480*)GameState_GetParty(bs);
    unsigned char activeId = GameState_GetProtagonistIndex(bs);
    for (unsigned char i = 0; i < roster->memberCount; i++) {
        if (activeId != roster->memberIds[i]) {
            GameObject* c = bs->GetPartyMemberByIndex(roster->memberIds[i]);
            if (c != NULL) {
                GameObject_ResetTrail((unsigned char*)c);
            }
        }
    }
}
