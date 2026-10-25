#include <globaldefs.h>
#include "GameState/GameState.h"

int GameState_GetProtagonistIndex(GameState* battleStruct);
void ClearBytesAndZeroBlock02039d24(unsigned char* obj);

struct Struct_ov003_02161480 {
    char unknown_0_[0xf78];
    unsigned char unknown_f78_[4];
    unsigned char unknown_f7c_;
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
                ClearBytesAndZeroBlock02039d24((unsigned char*)c);
            }
        }
    }
}
