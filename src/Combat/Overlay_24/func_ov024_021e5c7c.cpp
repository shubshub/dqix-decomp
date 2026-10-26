#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "Util/Random.h"

struct Struct_ov024_021e5c7c {
    unsigned char unknown_0_[0x8e02];
    unsigned char unknown_8e02_;
};
struct Struct_ov024_021e5c7c_2 {
    unsigned char unknown_0_[0x1b];
    unsigned char amount;
};
struct Struct_ov024_021e5c7c_3 {
    unsigned char unknown_0_[8];
    void* unknown_8_;
    Struct_ov024_021e5c7c_2* source;
    Struct_ov024_021e5c7c* battle;
};
struct GoldInventory {
    unsigned char unknown_0_[0xf6c];
    unsigned int unknown_f6c_;
};
struct Struct_ov024_021e5c7c_5 {
    unsigned char unknown_0_[0xc];
    unsigned short unknown_c_;
};
struct Struct_ov024_021e5c7c_6 : GameObject {
    unsigned char unknown_13c_[0xc];
    Struct_ov024_021e5c7c_5* monster;
};
extern "C" GameObject* func_ov000_021536f8(int, int);
extern "C" void* func_ov000_0215e958(void*);
extern "C" int func_ov000_0215ffa0(void*);
extern "C" int func_ov000_0215fd24(int, int);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" void func_ov000_0215cd44(void*, void*, GameObject*, int, int, int, int);
extern "C" void func_ov000_0215fe84(void*, void*, int);
static inline int IsPartyMember(int id) { return id >= 0 && id <= 3; }

// USA: func_ov024_021e5c7c
extern "C" ARM void func_ov024_021e5c7c(Struct_ov024_021e5c7c_3* action, int id, int unused, int arg3) {
    if (arg3 <= 0) return;
    GameObject* combatant = GetCombatantByID((int)action->battle, id);
    if (!combatant) return;
    if ((int)(float)NextRandomMax((Random*)action->battle, 2) <= 0) return;
    void* entry = func_ov000_0215e958(action->battle);
    if (!entry) return;
    GoldInventory* inventory = (GoldInventory*)GameState_GetParty(GameState::GetInstance());
    int other;
    int amount;
    Struct_ov024_021e5c7c_2* source = action->source;
    if (!source) return;
    other = func_ov000_0215ffa0(source);
    if (IsPartyMember(other)) return;
    amount = 0;
    if (IsPartyMember(id)) {
        Struct_ov024_021e5c7c_6* monster = (Struct_ov024_021e5c7c_6*)func_ov000_021536f8((int)action->battle, other);
        if (monster) {
            amount = (int)(0.1f * (float)(unsigned int)monster->monster->unknown_c_);
            if (amount > 100) amount = 100;
            if (amount > 0) {
                if (func_ov000_0215fd24((int)action->battle, id)) {
                    unsigned int total = inventory->unknown_f6c_ + amount;
                    if (total > 9999999) inventory->unknown_f6c_ = 9999999;
                    else inventory->unknown_f6c_ = total;
                }
                source->amount = amount;
                func_ov000_0215a88c(action->battle, entry, 0x172);
            }
        }
    } else {
        amount = (int)(0.1f * (float)inventory->unknown_f6c_);
        if (amount > 100) amount = 100;
        if (amount > 0) {
            if (func_ov000_0215fd24((int)action->battle, other)) inventory->unknown_f6c_ -= amount;
            source->amount = amount;
            func_ov000_0215a88c(action->battle, entry, 0x172);
        }
    }
    if (amount > 0) {
        func_ov000_0215cd44(action->battle, entry, combatant, (short)amount, 0, 0, 0);
        func_ov000_0215fe84(action->unknown_8_, entry, 2);
        action->battle->unknown_8e02_++;
    }
}
