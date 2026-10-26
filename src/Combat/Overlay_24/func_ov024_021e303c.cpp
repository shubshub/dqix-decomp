#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>

struct Struct_ov024_021dbaf4_4;
struct Struct_ov024_021e2bd0;
struct Struct_020885e0;
struct Struct_02088624;
struct Struct_ov004_02159fcc { char pad0[0x1c]; unsigned char unused : 7; unsigned char unknown_1c_7_ : 1; };
struct Struct_ov024_021e2bd0_3 { char pad0[0xc]; Struct_ov004_02159fcc* action_; Random* context_; };
struct Struct_ov024_021e2bd0_4 {
    char pad0[0x14];
    unsigned int flags_;
    char pad18[0x35];
    unsigned char unknown_4d_;
};
struct Struct_ov024_021e303c {
    char pad0[0x14];
    unsigned int unknown_14_0_ : 7;
    unsigned int unknown_14_7_ : 7;
    unsigned int unknown_15_6_ : 18;
    char pad18[0x1a];
    short kind_;
};
union Struct_ov024_021e2bd0_6 { struct { int low; int high; }; unsigned long long value; };

extern "C" int func_02088540(unsigned char*);
extern "C" int func_020885e0(Struct_020885e0*);
extern "C" int func_ov024_021e939c(Struct_ov024_021dbaf4_4*, int, int, int);
extern "C" int func_ov024_021eb4b0(int, int, int);
extern "C" void func_ov000_02159eac(void*, Struct_ov024_021e2bd0_6*, int);
extern "C" void func_02088560(unsigned char*);
extern "C" void func_02088624(Struct_02088624*);
extern "C" void* func_ov024_021e8ca0(Struct_ov024_021e2bd0*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);

// USA: func_ov024_021e303c
extern "C" ARM unsigned long long func_ov024_021e303c(Struct_ov024_021e2bd0_3* self, int arg1, int arg2, Struct_ov024_021e303c* arg3, int amount) {
    if (amount <= 0) return 0;
    GameObject* target = GetCombatantByID((int)self->context_, arg2);
    if (!target) return 0;
    if (((Struct_ov024_021e2bd0_4*)target->currentStats_)->unknown_4d_ == 0) return 0;
    if (arg3->kind_ > 0) {
        if (!func_02088540((unsigned char*)target->currentStats_)) return 0;
    } else if (!func_020885e0((Struct_020885e0*)target->currentStats_)) return 0;
    int roll = NextRandomMax(self->context_, 100);
    float var2 = 100.0f;
    if (!self->action_->unknown_1c_7_) {
        int party;
        if (arg1 >= 0 && arg1 <= 3) party = 1; else party = 0;
        if (party) var2 = (float)arg3->unknown_14_7_;
        else var2 = (float)arg3->unknown_14_0_;
        var2 *= (float)((Struct_ov024_021e2bd0_4*)target->currentStats_)->unknown_4d_ / 100.0f;
    }
    int kind = 0;
    if (arg3->kind_ > 0) kind = 1;
    if ((float)roll >= var2) return 0;
    int message = func_ov024_021e939c((Struct_ov024_021dbaf4_4*)self, arg2, kind, 1);
    Struct_ov024_021e2bd0_6 effects;
    effects.low = 0;
    effects.high = 0;
    if (func_ov024_021eb4b0((int)self, ((Struct_ov024_021e2bd0_4*)target->currentStats_)->flags_, 2))
        func_ov000_02159eac(self->context_, &effects, 0x2b);
    if (kind) func_02088560((unsigned char*)target->currentStats_);
    else func_02088624((Struct_02088624*)target->currentStats_);
    func_ov000_02159eac(self->context_, &effects, 0xf);
    void* entry = func_ov024_021e8ca0((Struct_ov024_021e2bd0*)self, message);
    if (entry) func_ov000_0215cd44(self->context_, entry, target, 0, 0, 0, 0);
    return effects.value;
}
