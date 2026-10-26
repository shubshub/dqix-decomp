#include <globaldefs.h>
#include "GameState/GameState.h"


struct Struct_020a620c {
    char pad0[0xa];
    unsigned char index;
};

typedef void (Struct_020a620c::*Type_02000c9c)();
struct Struct_020e907c { Type_02000c9c e[4]; };
extern struct Struct_020e907c data_020e907c;
extern Type_02000c9c __ptmf_null;

// USA: func_020a620c
extern "C" ARM int func_020a620c(Struct_020a620c* obj) {
    struct Struct_020e907c table;
    GameState::GetInstance()->GetTickCount();
    table = data_020e907c;
    table.e[3] = __ptmf_null;
    if (table.e[obj->index] == 0) {
        return 0;
    }
    (obj->*table.e[obj->index])();
    return 1;
}
