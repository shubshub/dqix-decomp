#include <globaldefs.h>
#include "GameState/GameState.h"

struct PartyData02160c58 {
    char pad0[0xf70];
    unsigned int unknown_f70_;
    char unknown_f74_[0x2c8c - 0xf74];
    unsigned char memberCount;
};

// USA: func_ov003_02160c58
extern "C" ARM void func_ov003_02160c58(int id, short* arg1, short* arg2) {
    short total = 12;
    unsigned char used = ((PartyData02160c58*)GameState_GetParty(GameState::GetInstance()))->memberCount;
    total -= 4;
    PartyData02160c58* data = (PartyData02160c58*)GameState_GetParty(GameState::GetInstance());
    if (data->unknown_f70_ > 4) {
        data->unknown_f70_ = 4;
    }
    total += data->unknown_f70_;
    if (total > 12) {
        total = 12;
    }
    *arg1 = total;
    *arg2 = total - used;
}
