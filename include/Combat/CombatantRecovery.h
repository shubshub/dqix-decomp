#pragma once

#include "GameState/GameState.h"

struct Struct_020200c0 {
    unsigned int flags;
    unsigned short hp;
    unsigned short mp;
    unsigned char status;
    unsigned int inline_ov017_021bd5d0() const { return flags; }
    unsigned short inline_ov017_021bd5d0_2() const { return mp; }
    unsigned char inline_ov017_021bd5d0_3() const { return status; }
};

// The recovery flag is in the combatant extension, beyond the common GameObject.
// Keep the common base size unchanged: several other object types embed it.
struct CombatantRecovery : GameObject {
#if defined(jpn)
    unsigned char unknown_13c_[0x180 - 0x13c];
#else
    unsigned char unknown1_13c_[0x18c - 0x13c];
#endif
    unsigned int recoveryFlags;
};

extern "C" void func_02048150(GameObject* object, int hp, int notify);
extern "C" void func_02053fe4(GameObject* object, int hp, int notify);

#if defined(jpn)
#else
#endif
