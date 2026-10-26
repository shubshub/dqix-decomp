#include <globaldefs.h>

#include "GameState/GameState.h"

struct SearchStruct;

extern "C" void* LinkSession_GetInstance(void);

extern "C" int LinkSession_IsSlotMember(struct SearchStruct* obj, int value);
extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);
extern "C" void func_02079710(unsigned char* obj, int bit, int cond);

// USA: func_0207973c
extern "C" ARM int func_0207973c(unsigned char* obj) {
    GameState* battleStruct = GameState::GetInstance();
    struct SearchStruct* search = (struct SearchStruct*)LinkSession_GetInstance();
    int i;
    for (i = 0; i < 4; i++) {
        if (!LinkSession_IsSlotMember(search, i) || func_0200ff58(battleStruct, i) != 0) {
            func_02079710(obj, i, 1);
        }
    }
    return (obj[0x17e] & 0xf) == 0xf ? 1 : 0;
}
