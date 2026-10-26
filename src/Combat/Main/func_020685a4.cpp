#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_020685a4 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_020685a4
extern "C" ARM int func_020685a4(GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetPartyMemberByIndex(0);
    if (combatant != 0) {
        struct Struct_020685a4* sub = *(struct Struct_020685a4**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
