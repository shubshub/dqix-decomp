#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215641c_2 {
    char unk_0[0xc];
    unsigned int unknown_c_0_ : 10;
};

struct Struct_ov000_0215641c {
    char unk_0[0x134];
    BaseCombatStats* baseStats;
    ModifiableCombatStats* currentStats;
#if defined(jpn)
    char unknown_13c_[0x144 - 0x13c];
#else
    char unknown1_13c_[0x150 - 0x13c];
#endif
    Struct_ov000_0215641c_2* extra;

    unsigned short inline_ov000_0215641c() { return currentStats->primaryStats.charm; }
    unsigned short inline_ov000_0215641c_2() { return baseStats->primaryStats.charm; }
};

// USA: func_ov000_0215641c
extern "C" ARM float func_ov000_0215641c(int unused, int id) {
    GameState* gs = GameState::GetInstance();
    float result = 0.0f;
    int var2 = (id >= 0 && id <= 3);
    if (var2) {
        Struct_ov000_0215641c* c = (Struct_ov000_0215641c*)func_0200ff1c(gs, id);
        if (c == NULL) {
            return 0.0f;
        }
        int charm = c->inline_ov000_0215641c_2();
        charm = c->inline_ov000_0215641c() - charm;
        charm +=(unsigned short)c->extra->unknown_c_0_;
        result = (charm - 100) * 0.02f;
    }
    return result;
}
