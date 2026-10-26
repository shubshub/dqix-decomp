#include <globaldefs.h>
#include <GameState/GameState.h>
#include <Combat/Overlay_0/GetCombatantByID.h>
#include <Util/Random.h>

struct Struct_ov024_021e2bd0;
struct Struct_ov024_021dd028_5;
struct Struct_ov024_021da670_6;
struct Struct_ov024_021e2bd0_2;
struct Struct_02088418;
struct Struct_ov004_02159fcc { char pad0[0x1c]; unsigned char unused : 7; unsigned char unknown_1c_7_ : 1; };
struct Struct_ov024_021e2bd0_3 { char pad0[0xc]; Struct_ov004_02159fcc* action_; Random* context_; };
struct Struct_ov024_021e2bd0_4 {
    char pad0[0x14];
    unsigned int flags_;
    char pad18[0x34];
    unsigned char unknown_4c_;
};
struct Struct_ov024_021e2bd0_5 {
    char pad0[4];
    unsigned int id_ : 12;
    unsigned int unknown_5_4_ : 20;
    char pad8[0xc];
    unsigned int unknown_14_0_ : 7;
    unsigned int unknown_14_7_ : 7;
    unsigned int unknown_15_6_ : 18;
    unsigned int unknown_18_0_ : 5;
    unsigned int category_ : 7;
    unsigned int unknown_19_4_ : 20;
    char unknown_1c_[0x16];
    short kind_;
};
union Struct_ov024_021e2bd0_6 { struct { int low; int high; }; unsigned long long value; };

extern "C" int func_ov024_021e8fa4(struct Struct_ov024_021e2bd0_2*, int, int);
extern "C" void func_ov000_02159eac(void*, Struct_ov024_021e2bd0_6*, int);
extern "C" int func_02088418(Struct_02088418*, int, int);
extern "C" int func_ov024_021eb4b0(int, int, int);
extern "C" int func_ov024_021dd260(Struct_ov024_021dd028_5*);
extern "C" int func_ov024_021da998(Struct_ov024_021da670_6*);
extern "C" void func_02088474(void*, int, int);
extern "C" void* func_ov024_021e8ca0(Struct_ov024_021e2bd0*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);
extern "C" void func_ov024_021e8cfc(Struct_ov024_021e2bd0_3*, GameObject*, int, int);

// USA: func_ov024_021e2bd0
extern "C" ARM unsigned long long func_ov024_021e2bd0(Struct_ov024_021e2bd0_3* self, int arg1, int arg2, Struct_ov024_021e2bd0_5* params, int amount) {
    GameObject* target = GetCombatantByID((int)self->context_, arg2);
    if (!target) return 0;
    if (params->category_ != 10) {
        if (amount <= 0) return 0;
        if (((Struct_ov024_021e2bd0_4*)target->currentStats_)->unknown_4c_ == 0) return 0;
        int roll = NextRandomMax(self->context_, 100);
        float var2 = 100.0f;
        if (!self->action_->unknown_1c_7_) {
            int party;
            if (arg1 >= 0 && arg1 <= 3) party = 1; else party = 0;
            if (party) var2 = (float)params->unknown_14_7_;
            else var2 = (float)params->unknown_14_0_;
            if (params->id_ != 0x239 && params->id_ != 0x1fc)
                var2 *= (float)((Struct_ov024_021e2bd0_4*)target->currentStats_)->unknown_4c_ / 100.0f;
        }
        if ((float)roll >= var2) return 0;
    }
    int kind = func_ov024_021e8fa4((Struct_ov024_021e2bd0_2*)self, arg2, params->kind_);
    if (!kind) return 0;
    Struct_ov024_021e2bd0_6 effects;
    effects.low = 0;
    effects.high = 0;
    func_ov000_02159eac(self->context_, &effects, (unsigned char)kind);
    if (!func_02088418((Struct_02088418*)target->currentStats_, (unsigned char)params->kind_, (unsigned short)params->id_)) return 0;
    if (func_ov024_021eb4b0((int)self, ((Struct_ov024_021e2bd0_4*)target->currentStats_)->flags_, 0x80000)) {
        if (kind == 0x12 || kind == 0x15 || kind == 0x1b || kind == 0x1c)
            func_ov000_02159eac(self->context_, &effects, 0x2b);
    }
    int var6 = func_ov024_021dd260((Struct_ov024_021dd028_5*)target);
    int special = func_ov024_021da998((Struct_ov024_021da670_6*)target);
    func_02088474(target->currentStats_, (unsigned char)params->kind_, (unsigned short)params->id_);
    if (params->category_ != 10) {
        int message = 0;
        switch (params->kind_) {
        case 2: message = 0x150; break;
        case 5: message = 0x5e; break;
        }
        void* entry = func_ov024_021e8ca0((Struct_ov024_021e2bd0*)self, message);
        if (entry) func_ov000_0215cd44(self->context_, entry, target, 0, 0, 0, 0);
    }
    if (special) {
        func_ov024_021e8cfc(self, target, 0, 0);
    } else if (var6) {
        if (!func_ov024_021dd260((Struct_ov024_021dd028_5*)target))
            func_ov024_021e8cfc(self, target, 8, 0);
    }
    return effects.value;
}
