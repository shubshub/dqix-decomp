#include <globaldefs.h>
#include "GameState/GameState.h"

union Struct_ov017_021d60f4 { int i; float f; };
struct Struct_ov001_0215f344 { int type; Struct_ov017_021d60f4 value; };
struct Struct_ov001_0216089c { int type; int* ptr; };

extern "C" ARM int func_ov017_021d60f4(Struct_ov001_0215f344* a);
extern "C" ARM void func_ov017_021d6134(Struct_ov001_0216089c* a, int val);
extern "C" GameObject* func_ov023_021e8f28(int index);

struct Struct_ov023_021e94cc {
    Struct_ov001_0215f344 unknown_0_; // offset 0
    Struct_ov001_0215f344 unknown_8_;  // offset 8
    Struct_ov001_0216089c unknown_10_;             // offset 0x10
};

struct Struct_ov023_021e94cc_2 { unsigned int f0 : 10; unsigned int f1 : 10; unsigned int f2 : 10; };

struct Struct_ov023_021e94cc_3 {
    struct Struct_ov023_021e94cc_2 pos;   // offset 0
    struct Struct_ov023_021e94cc_2 rot;   // offset 4
    struct Struct_ov023_021e94cc_2 unknown_8_; // offset 8
    struct Struct_ov023_021e94cc_2 unknown_c_; // offset 0xc
};

// USA: func_ov023_021e94cc
extern "C" ARM int func_ov023_021e94cc(Struct_ov023_021e94cc* args) {
#if defined(jpn)
 enum { Enum_ov023_021e94cc_336=0x144 };
#else
 enum { Enum_ov023_021e94cc_336=0x150 };
#endif
    GameState::GetInstance();
    int var0 = func_ov017_021d60f4(&args->unknown_0_);
    GameObject* combatant = func_ov023_021e8f28(var0);
    if (combatant == 0) {
        return 0;
    }
    int var2 = func_ov017_021d60f4(&args->unknown_8_);
    switch (var2) {
    case 0: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->pos.f0;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 1: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->pos.f1;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 2: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->pos.f2;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 3: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->rot.f0;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 4: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->rot.f1;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 5: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->rot.f2;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 6: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->unknown_8_.f0;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 7: {
        unsigned short v = combatant->baseStats_->primaryStats.maxHP;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 8: {
        unsigned short v = combatant->baseStats_->primaryStats.maxMP;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 9: {
        unsigned short v = combatant->baseStats_->primaryStats.attack;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 10: {
        unsigned short v = combatant->baseStats_->primaryStats.defense;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    case 11: {
        unsigned short v = (*(struct Struct_ov023_021e94cc_3**)((char*)combatant + Enum_ov023_021e94cc_336))->unknown_c_.f0;
        func_ov017_021d6134(&args->unknown_10_, v);
        break;
    }
    }
    return 1;
}
