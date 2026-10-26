#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"

struct Struct_ov024_021e4910_3 {
    unsigned char unknown_0_[0x8e02];
    unsigned char unknown_8e02_;
};
struct Struct_ov024_021e4910 {
    unsigned char unknown_0_[0xc];
    void* unknown_c_;
    Struct_ov024_021e4910_3* battle;
};
struct Struct_ov024_021e4910_2 {
    unsigned char unknown_0_[0x32];
    short delta;
};
struct Struct_02087860;
struct Struct_02087954;
extern "C" int func_02087860(Struct_02087860*, unsigned char);
extern "C" int func_02087954(Struct_02087954*, int);
extern "C" int func_020878b4(ModifiableCombatStats*, int);
extern "C" int func_020879a8(ModifiableCombatStats*, int);
void UpdateCombatantDefense(int, int);
void UpdateCombatantAgility(int, int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" int func_ov024_021e95d4(Struct_ov024_021e4910*, int, Struct_ov024_021e4910_2*, unsigned char, signed char, unsigned char, unsigned char);
extern "C" int func_ov024_021e96e4(Struct_ov024_021e4910*, int, Struct_ov024_021e4910_2*, unsigned char, signed char, unsigned char, unsigned char);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);
extern "C" void func_ov000_0215ffc4(void*, void*, int);

// USA: func_ov024_021e4910
extern "C" ARM unsigned long long func_ov024_021e4910(Struct_ov024_021e4910* action, int unused, short id, Struct_ov024_021e4910_2* parameters) {
    GameObject* combatant = GetCombatantByID((int)action->battle, id);
    if (!combatant) return 0;
    int delta = parameters->delta;
    if (delta < -2) delta = -2;
    if (delta > 2) delta = 2;
    int var2 = 0;
    if (delta < 0) var2 = 1;
    int var3 = 0;
    int result = 0;
    void* entry = func_ov000_0215e958(action->battle);
    if (!entry) return 0;
    if (func_02087860((Struct_02087860*)combatant->currentStats_, var2)) {
        result = func_020878b4(combatant->currentStats_, (signed char)delta);
        UpdateCombatantDefense((int)action->battle, id);
        var3 = 1;
    }
    if (var3) {
        int code = func_ov024_021e95d4(action, id, parameters, (unsigned char)var2, (signed char)result, 1, 1);
        func_ov000_0215a88c(action->battle, entry, code);
    }
    int var7 = 0;
    if (func_02087954((Struct_02087954*)combatant->currentStats_, var2 & 0xff)) {
        result = func_020879a8(combatant->currentStats_, (signed char)delta);
        UpdateCombatantAgility((int)action->battle, id);
        var7 = 1;
    }
    if (var7) {
        int code = func_ov024_021e96e4(action, id, parameters, (unsigned char)var2, (signed char)result, 1, 1);
        func_ov000_0215a88c(action->battle, entry, code);
    }
    union { struct { int low; int high; }; unsigned long long value; } effects;
    effects.low = 0;
    effects.high = 0;
    if (var3 || var7) {
        func_ov000_02159eac(action->battle, &effects, 0x1e);
        func_ov000_02159eac(action->battle, &effects, 0x1f);
        func_ov000_0215cd44(action->battle, entry, combatant, 0, 0, 0, 0);
        func_ov000_0215ffc4(action->unknown_c_, entry, 1);
        action->battle->unknown_8e02_++;
    }
    return effects.value;
}
