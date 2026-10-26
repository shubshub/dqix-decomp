#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

int RoundUp(float);
extern "C" short func_ov000_0215a16c(void*, int, int, short*);
extern "C" void* func_ov000_0215e958(void*);
extern "C" void func_ov000_02159eac(void*, void*, int);
extern "C" void func_ov000_0215a88c(void*, void*, int);
extern "C" int func_ov024_021eae14(void*, int);
extern "C" void func_ov000_0215ccbc(void*, void*, GameObject*, short, short, short, unsigned long long, unsigned char);
struct Struct_ov024_021e13e0 { char pad[0x1c]; unsigned char unused:7; unsigned char flag:1; };
struct Struct_ov024_021e13e0_2 { char pad[0xc]; Struct_ov024_021e13e0* action; void* context; };

// USA: func_ov024_021e13e0
extern "C" ARM void* func_ov024_021e13e0(Struct_ov024_021e13e0_2* obj, int unused, int id) {
    GameObject* c = GetCombatantByID((int)obj->context, id);
    if (!c) return 0;
    int amount = RoundUp(0.4f * (float)(unsigned int)c->currentStats_->primaryStats.maxHP);
    if (amount < 75) amount = 75;
    union { struct { int lo; int hi; }; unsigned long long value; } effects;
    effects.lo = 0;
    effects.hi = 0;
    short var3 = 0;
    short hp = func_ov000_0215a16c(obj->context, id, amount, &var3);
    void* entry = func_ov000_0215e958(obj->context);
    if (!entry) return 0;
    int added = 0;
    if (var3 > 0) {
        func_ov000_02159eac(obj->context, &effects, 0x25);
        func_ov000_0215a88c(obj->context, entry, 0x1ba);
        func_ov000_0215a88c(obj->context, entry, 0x16);
        added = 1;
    }
    if (func_ov024_021eae14(obj, id) > 0) {
        if (!added) {
            func_ov000_0215a88c(obj->context, entry, 0x1ba);
            added = 1;
        }
        func_ov000_0215a88c(obj->context, entry, 0x1bb);
    }
    if (!added) func_ov000_0215a88c(obj->context, entry, 0x1f);
    unsigned short mp = c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    func_ov000_0215ccbc(obj->context, entry, c, -var3, hp, mp, effects.value, flag);
    return entry;
}
