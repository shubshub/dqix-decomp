#include <globaldefs.h>
#include "GameState/GameState.h"

struct S_10088;
extern "C" int func_02010088(struct S_10088* obj);

struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);

struct Struct_ov024_021da670_8;
extern "C" int func_ov024_021da9c8(struct Struct_ov024_021da670_8* obj);

struct Struct_ov024_021de124;
extern "C" int func_ov024_021de25c(struct Struct_ov024_021de124* obj);

extern "C" int func_020882f8(unsigned char* obj);
extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);

struct Struct_ov024_021eb1ec {
    char unk[0x3a];
    unsigned char unknown_3a_;
    unsigned char unknown_3b_0_:3;
    unsigned char unknown_3b_3_:1;
    unsigned char unknown_3b_4_:4;
};

// USA: func_ov024_021eb1ec
extern "C" ARM int func_ov024_021eb1ec(void* unused, int combatantId) {
    GameState* battle = GameState::GetInstance();
    GameObject* combatant = func_0200ff1c(battle, combatantId);
    if (combatant == NULL) {
        return 0;
    }
    if (((struct Struct_ov024_021eb1ec*)combatant->currentStats_)->unknown_3a_ != 0) {
        ((struct Struct_ov024_021eb1ec*)combatant->currentStats_)->unknown_3a_ = 0;
        return 0;
    }
    if (GameObject_GetPartyMemberLevel(combatant) < 10) {
        return 0;
    }
    if (func_ov024_021da9c8((struct Struct_ov024_021da670_8*)combatant)) {
        return 0;
    }
    if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)combatant)) {
        return 0;
    }
    if (func_ov024_021de25c((struct Struct_ov024_021de124*)combatant)) {
        return 0;
    }
    if (func_020882f8((unsigned char*)combatant->currentStats_)) {
        return 0;
    }
    if (func_02010088((struct S_10088*)combatant)) {
        return 0;
    }
    return ((struct Struct_ov024_021eb1ec*)combatant->currentStats_)->unknown_3b_3_ == 0;
}
