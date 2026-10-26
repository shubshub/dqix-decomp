#include <globaldefs.h>
#include "GameState/GameState.h"


extern "C" void* GameState_FindPartyMemberData(void* obj, int value);
extern "C" void* GameState_FindFreePartyMemberData(char* base);
extern "C" void func_02053c4c(char* obj, char* p);
extern "C" void HaltSystem(void);

// USA: func_02053c74
extern "C" ARM void func_02053c74(char* obj, int idx) {
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
    func_02053c4c(obj, rec);
}
