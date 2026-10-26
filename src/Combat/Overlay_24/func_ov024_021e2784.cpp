#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;
struct Struct_ov024_021e2784_4 { int lo; int hi; };

struct Struct_ov024_021da670_7;
extern "C" int func_ov024_021da9b0(struct Struct_ov024_021da670_7* obj);
extern "C" void func_020882dc(void* obj);
struct Struct_020885b4;
extern "C" int func_020885b4(struct Struct_020885b4* obj);
struct Struct_02088514;
extern "C" int func_02088514(struct Struct_02088514* obj);
struct Struct_02088644;
extern "C" void func_02088644(struct Struct_02088644* obj);
extern "C" short func_ov000_0215a16c(void* unused, int id, int delta, short* arg3);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* ctx);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct Struct_ov024_021e2784_4* words, int effect);
extern "C" void func_ov000_0215ccbc(
    int unused, struct Struct_ov000_021584e8* out, GameObject* combatant, short arg3, short valA, short valB,
    struct Struct_ov024_021e2784_4 words, unsigned char arg7);

struct Struct_ov024_021e2784 { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Struct_ov024_021e2784_2 {
    char pad0[0xc];
    struct Struct_ov024_021e2784* action;
    void* ctx;
    int count;
};
struct Struct_ov024_021e2784_3 { unsigned char bit0 : 1; unsigned char rest : 7; };

static inline unsigned short inline_ov024_021dc700(GameObject* c) { return c->currentStats_->primaryStats.maxHP; }

// USA: func_ov024_021e2784
extern "C" ARM struct Struct_ov000_021584e8* func_ov024_021e2784(struct Struct_ov024_021e2784_2* obj, int unused, int id, int arg3, int amount) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    struct Struct_ov000_021584e8* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    struct Struct_ov024_021e2784_4 words;
    words.lo = 0;
    words.hi = 0;
    short hp = c->currentStats_->primaryStats.currHP;
    short var4 = 0;
    unsigned short maxHP = inline_ov024_021dc700(c);
    if (c->currentStats_->primaryStats.currHP < maxHP) {
        hp = func_ov000_0215a16c(obj->ctx, id, amount, &var4);
        func_ov000_02159eac(obj->ctx, &words, 0x25);
        func_ov000_0215a88c(obj->ctx, entry, 0x16);
        obj->count++;
    }
    if (func_ov024_021da9b0((struct Struct_ov024_021da670_7*)c)) {
        func_020882dc(c->currentStats_);
        ((struct Struct_ov024_021e2784_3*)((char*)c->currentStats_ + 0x3b))->bit0 = 1;
        func_ov000_02159eac(obj->ctx, &words, 0x1a);
        func_ov000_0215a88c(obj->ctx, entry, 0x1f9);
        obj->count++;
    }
    if (func_020885b4((struct Struct_020885b4*)c->currentStats_) || func_02088514((struct Struct_02088514*)c->currentStats_)) {
        func_02088644((struct Struct_02088644*)c->currentStats_);
        func_ov000_02159eac(obj->ctx, &words, 0x11);
        func_ov000_0215a88c(obj->ctx, entry, 0x54);
        obj->count++;
    }
    unsigned short mp = c->currentStats_->primaryStats.currMP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    func_ov000_0215ccbc((int)obj->ctx, entry, c, -var4,
        hp, mp, words, flag);
    return entry;
}
