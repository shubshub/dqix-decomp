#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_020886b0;
struct Struct_020886f8;
struct Struct_02088740;
struct Struct_02088788;
struct Struct_020887d0;

struct Struct_02000c9c_28 {
    char pad0[0x3e];
    unsigned char unknown_3e_[21];
};

extern "C" int func_ov000_02156c94(GameObject* combatant);
extern "C" int func_ov000_02156cac(GameObject* combatant);
extern "C" int func_020886b0(struct Struct_020886b0* obj);
extern "C" int func_020886f8(struct Struct_020886f8* obj);
extern "C" int func_02088740(struct Struct_02088740* obj);
extern "C" int func_02088788(struct Struct_02088788* obj);
extern "C" int func_020887d0(struct Struct_020887d0* obj);

static inline unsigned char* inline_ov000_02156b38(ModifiableCombatStats* stats) {
    return ((struct Struct_02000c9c_28*)stats)->unknown_3e_;
}

// USA: func_ov000_02156b38
extern "C" ARM float func_ov000_02156b38(void* self, int arg1, int element) {
    float var0, var1, var2, var3, var4;
    float bonus;
    GameObject* combatant = GameState::GetInstance()->GetCombatantByIndex(arg1);
    if (combatant == NULL) {
        return 1.0f;
    }

    bonus = 0.0f;
    if (func_ov000_02156c94(combatant)) {
        bonus = -25.0f;
    } else if (func_ov000_02156cac(combatant)) {
        bonus = 25.0f;
    }

    var0 = 0.0f;
    if (func_020886b0((struct Struct_020886b0*)combatant->currentStats_)) {
        var0 = -50.0f;
    }
    var1 = 0.0f;
    if (func_020886f8((struct Struct_020886f8*)combatant->currentStats_)) {
        var1 = -50.0f;
    }
    var2 = 0.0f;
    if (func_02088740((struct Struct_02088740*)combatant->currentStats_)) {
        var2 = -50.0f;
    }
    var3 = 0.0f;
    if (func_02088788((struct Struct_02088788*)combatant->currentStats_)) {
        var3 = -50.0f;
    }
    var4 = 0.0f;
    if (func_020887d0((struct Struct_020887d0*)combatant->currentStats_)) {
        var4 = -50.0f;
    }

    unsigned char idx = element - 1;
    if (element < 1 || element > 21) {
        return 1.0f;
    }
    if (element == 8) {
        bonus = 0.0f;
    } else if (element >= 1 && element <= 7) {
        float var8[7] = {var0, var1, var2, var2, var3, var3, var4};
        bonus = var8[idx];
    }

    float value = inline_ov000_02156b38(combatant->currentStats_)[idx];
    value += bonus;
    if (value < 0.0f) {
        value = 0.0f;
    }
    return value / 100.0f;
}
