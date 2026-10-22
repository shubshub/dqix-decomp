#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_021727c8_236 = 0xe8 };
#else
enum { Enum_ov003_021727c8_236 = 0xec };
#endif


struct Struct_ov003_021727c8 {
    char unknown_0_[Enum_ov003_021727c8_236];
    unsigned char unknown_ec_;
    unsigned char unknown_ed_;
};

typedef void (Struct_ov003_021727c8::*Type_ov003_021727c8)();

struct Struct_ov003_0217fa20 {
    Type_ov003_021727c8 unknown_0_[7];
};

extern "C" const StateTable021727c8 data_ov003_0217fa20;
extern "C" const StateTable021727c8 data_ov003_0217fa58;
extern "C" StateFn021727c8 __ptmf_null;

// USA: func_ov003_021727c8
extern "C" ARM bool func_ov003_021727c8(Struct_ov003_021727c8* arg0) {
    GameState::GetInstance()->GetTickCount();
    bool done = false;
    bool subDone = false;
    StateTable021727c8 states = data_ov003_0217fa20;
    StateFn021727c8 none = __ptmf_null;
    states.functions[6] = none;
    StateTable021727c8 subStates = data_ov003_0217fa58;
    subStates.functions[6] = none;
    if (states.functions[self->state_] != 0) {
        (self->*states.functions[self->state_])();
    } else {
        var0 = true;
    }
    if (var4.unknown_0_[arg0->unknown_ed_] != 0) {
        (arg0->*var4.unknown_0_[arg0->unknown_ed_])();
    } else {
        var1 = true;
    }
    if (var0 && var1) {
        return false;
    }
    return true;
}
