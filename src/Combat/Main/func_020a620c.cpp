#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_020a620c {
    char unknown_0_[0xa];
    unsigned char unknown_a_;
};

typedef void (Obj020a620c::*PMF020a620c)();
struct RawTable020a620c { PMF020a620c e[4]; };
extern struct RawTable020a620c data_020e907c;
extern PMF020a620c __ptmf_null;

// USA: func_020a620c
extern "C" ARM int func_020a620c(Struct_020a620c* arg0) {
    struct Struct_020e907c var0;
    GameState::GetInstance()->GetTickCount();
    table = data_020e907c;
    table.e[3] = __ptmf_null;
    if (table.e[obj->index] == 0) {
        return 0;
    }
    (arg0->*var0.unknown_0_[arg0->unknown_a_])();
    return 1;
}
