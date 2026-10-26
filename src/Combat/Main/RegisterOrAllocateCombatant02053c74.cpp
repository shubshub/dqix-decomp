#include <globaldefs.h>
#include "GameState/GameState.h"


void* GameState_FindPartyMemberData(void* obj, int value);
void* GameState_FindFreePartyMemberData(char* base);
void SetPointerFields02053c4c(char* obj, char* p);
extern "C" void HaltSystem(void);

// KEEP-NAME: the ROM symbol here is the mangled C++ name, not a func_ tag.
// USA: func_02053c74
ARM void RegisterOrAllocateCombatant02053c74(char* obj, int idx) {
    GameState* bs = GameState::GetInstance();
    char* rec = (char*)GameState_FindPartyMemberData(bs, idx);
    if (!rec) {
        rec = (char*)GameState_FindFreePartyMemberData((char*)bs);
        if (rec) {
            *(short*)(rec + 0x568) = idx;
        } else {
            HaltSystem();
        }
    }
    SetPointerFields02053c4c(obj, rec);
}
