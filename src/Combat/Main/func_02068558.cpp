#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02068558 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_02068558
extern "C" ARM int func_02068558(GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(0);
    if (combatant != 0) {
        struct Struct_02068558* sub = *(struct Struct_02068558**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
