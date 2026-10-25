#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov003_02160c58 {
    char unknown_0_[0xf70];
    unsigned int unknown_f70_;
    char unknown_f74_[0x2c8c - 0xf74];
    unsigned char unknown_2c8c_;
};

// USA: func_ov003_02160c58
extern "C" ARM void func_ov003_02160c58(int id, short* outTotal, short* outRemaining) {
    short total = 12;
    unsigned char used = ((PartyData02160c58*)GameState_GetParty(GameState::GetInstance()))->memberCount;
    total -= 4;
    PartyData02160c58* data = (PartyData02160c58*)GameState_GetParty(GameState::GetInstance());
    if (data->extraSlots > 4) {
        data->extraSlots = 4;
    }
    var0 += var2->unknown_f70_;
    if (var0 > 12) {
        var0 = 12;
    }
    *arg1 = var0;
    *arg2 = var0 - var1;
}
