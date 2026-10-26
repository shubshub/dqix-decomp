#include <globaldefs.h>
#include "GameState/GameState.h"

extern "C" GameObject* func_0200ff58(GameState* battleStruct, int combatantId);

struct Struct_ov017_02192548 {
#if defined(jpn)
    unsigned char unknown_0_[0x2c6];
#else
    unsigned char unknown1_0_[0x2d2];
#endif
    unsigned char unknown_2d2_;
};

// USA: func_ov017_02192548
extern "C" ARM int func_ov017_02192548(void) {
    GameState* battle = GameState::GetInstance();
    int var1 = 0;
    for (int partyIndex = 1; partyIndex < 4; ++partyIndex) {
        GameObject* member = func_0200ff58(battle, partyIndex);
        if (member != NULL) {
            unsigned char var4 = ((Struct_ov017_02192548*)member)->unknown_2d2_;
            if (var1 < var4) var1 = var4;
        }
    }
    return var1 + 1;
}
