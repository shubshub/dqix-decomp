#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020685cc {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_020685cc
extern "C" ARM int func_020685cc(GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetLeader();
    if (combatant != 0) {
        struct Struct_020685cc* sub = *(struct Struct_020685cc**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
