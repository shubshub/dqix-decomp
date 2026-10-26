#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);

struct Struct_ov000_02159d94 {
    char pad[0x10];
    unsigned int unknown_10_0_ : 3;
    unsigned int val : 2;
    unsigned int unknown_10_5_ : 27;
};

// USA: func_ov000_02159d94
extern "C" ARM int func_ov000_02159d94(void* unused, int id) {
    GameState* bs = GameState::GetInstance();
    GameObject* combatant = func_0200fea4(bs, id);
    struct Struct_ov000_02159d94* field148 = *(struct Struct_ov000_02159d94**)((char*)combatant + 0x148);
    return field148->val;
}
