#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;
struct Struct_ov024_021e0bf4 { int lo; int hi; };

extern "C" short func_ov000_0215a124(void* unused, int id, int amount);
extern "C" void func_ov000_02159eac(void* ctx, struct Struct_ov024_021e0bf4* words, int effect);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* ctx);
extern "C" void func_ov000_0215ccbc(
    int unused, struct Struct_ov000_021584e8* out, GameObject* combatant, short arg3, short valA, short valB,
    struct Struct_ov024_021e0bf4 words, unsigned char arg7);

struct Struct_ov024_021e0bf4_2 { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Struct_ov024_021e0bf4_3 {
    char pad0[0xc];
    struct Struct_ov024_021e0bf4_2* action;
    void* ctx;
    int unknown_14_;
};

// USA: func_ov024_021e0bf4
extern "C" ARM struct Struct_ov000_021584e8* func_ov024_021e0bf4(struct Struct_ov024_021e0bf4_3* obj, int unused, int id, int arg3, int amount) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    if (c->currentStats_->primaryStats.currMP < amount) amount = c->currentStats_->primaryStats.currMP;
    short mp = func_ov000_0215a124(obj->ctx, id, amount);
    struct Struct_ov024_021e0bf4 words;
    words.lo = 0;
    words.hi = 0;
    if (amount > 0) {
        func_ov000_02159eac(obj->ctx, &words, 1);
        func_ov000_02159eac(obj->ctx, &words, 0x2a);
    }
    if (amount > 0) obj->unknown_14_++;
    struct Struct_ov000_021584e8* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    unsigned short hp = c->currentStats_->primaryStats.currHP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    func_ov000_0215ccbc((int)obj->ctx, entry, c, amount, hp, mp, words, flag);
    return entry;
}
