#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_02068580 {
    char pad[0x49c];
    unsigned char bit0 : 1;
};

// USA: func_02068580
extern "C" ARM int func_02068580(GameState* battleStruct) {
    GameObject* combatant = battleStruct->GetProtagonist();
    if (combatant != 0) {
        struct Struct_02068580* sub = *(struct Struct_02068580**)((char*)combatant + 0x150);
        return sub->bit0;
    }
    return 0;
}
