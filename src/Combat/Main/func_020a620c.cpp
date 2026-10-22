#include <globaldefs.h>
#include "GameState/GameState.h"


struct Obj020a620c {
    char pad0[0xa];
    unsigned char index;
};

typedef void (Obj020a620c::*PMF020a620c)();
struct RawTable020a620c { PMF020a620c e[4]; };
extern struct RawTable020a620c data_020e907c;
extern PMF020a620c __ptmf_null;

// USA: func_020a620c
extern "C" ARM int func_020a620c(Obj020a620c* obj) {
    struct RawTable020a620c table;
    GameState::GetInstance()->GetTickCount();
    table = data_020e907c;
    table.e[3] = __ptmf_null;
    if (table.e[obj->index] == 0) {
        return 0;
    }
    (obj->*table.e[obj->index])();
    return 1;
}
