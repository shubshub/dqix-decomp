#include <globaldefs.h>
#include "GameState/GameState.h"

#if defined(jpn)
enum { Enum_ov003_021727c8_236 = 0xe8 };
#else
enum { Enum_ov003_021727c8_236 = 0xec };
#endif


struct Struct_ov003_021727c8 {
    char unk_0[Enum_ov003_021727c8_236];
    unsigned char state_;
    unsigned char unknown_ed_;
};

typedef void (Struct_ov003_021727c8::*Type_ov003_021727c8)();

struct Struct_ov003_0217fa20 {
    Type_ov003_021727c8 unknown_0_[7];
};

extern "C" const Struct_ov003_0217fa20 data_ov003_0217fa20;
extern "C" const Struct_ov003_0217fa20 data_ov003_0217fa58;
extern "C" Type_ov003_021727c8 __ptmf_null;

// USA: func_ov003_021727c8
extern "C" ARM bool func_ov003_021727c8(Struct_ov003_021727c8* self) {
    GameState::GetInstance()->GetTickCount();
    bool done = false;
    bool var1 = false;
    Struct_ov003_0217fa20 states = data_ov003_0217fa20;
    Type_ov003_021727c8 none = __ptmf_null;
    states.unknown_0_[6] = none;
    Struct_ov003_0217fa20 var4 = data_ov003_0217fa58;
    var4.unknown_0_[6] = none;
    if (states.unknown_0_[self->state_] != 0) {
        (self->*states.unknown_0_[self->state_])();
    } else {
        done = true;
    }
    if (var4.unknown_0_[self->unknown_ed_] != 0) {
        (self->*var4.unknown_0_[self->unknown_ed_])();
    } else {
        var1 = true;
    }
    if (done && var1) {
        return false;
    }
    return true;
}
