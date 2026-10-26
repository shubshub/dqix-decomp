#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;
struct Struct_ov024_021ddf5c_4 { int lo; int hi; };

extern "C" short func_ov000_0215a1d4(void* unused, int id, int delta, short* arg3);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* ctx);
extern "C" void func_ov000_0215a88c(void* objRaw, void* arg1, int c);
extern "C" void func_ov000_02159eac(void* ctx, struct Struct_ov024_021ddf5c_4* words, int effect);
extern "C" void func_ov000_0215ccbc(
    int unused, struct Struct_ov000_021584e8* out, GameObject* combatant, short arg3, short valA, short valB,
    struct Struct_ov024_021ddf5c_4 words, unsigned char arg7);

struct Struct_ov024_021ddf5c_5 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};
struct Struct_ov024_021ddf5c_6 { unsigned int code : 12; unsigned int rest : 20; };
struct Struct_ov024_021ddf5c { char pad[0x1c]; unsigned char unk : 7; unsigned char flag : 1; };
struct Struct_ov024_021ddf5c_2 {
    char pad0[0xc];
    struct Struct_ov024_021ddf5c* action;
    void* ctx;
    int unknown_14_;
};
struct Struct_ov024_021ddf5c_3 {
    char pad0[4];
    struct Struct_ov024_021ddf5c_6 f4;
    char pad8[0x18];
    struct Struct_ov024_021ddf5c_5 f20;
    struct Struct_ov024_021ddf5c_5 f24;
};

static inline int inline_ov024_021ddf5c(int id) {
    return id >= 0 && id <= 3;
}

// USA: func_ov024_021ddf5c
extern "C" ARM struct Struct_ov000_021584e8* func_ov024_021ddf5c(struct Struct_ov024_021ddf5c_2* obj, int unused, int id, struct Struct_ov024_021ddf5c_3* range, int amount) {
    GameObject* c = GetCombatantByID((int)obj->ctx, id);
    if (!c) return 0;
    unsigned short code = range->f4.code;
    if (code == 0x19b || code == 0x22e) amount = c->currentStats_->primaryStats.maxMP;
    short var2 = 0;
    short mp = func_ov000_0215a1d4(obj->ctx, id, amount, &var2);
    int full = 0;
    if (!inline_ov024_021ddf5c(id) && c->currentStats_->primaryStats.currMP >= 0xff) full = 1;
    unsigned short sel;
    if (var2 > 0 || full) {
        sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
        obj->unknown_14_++;
    } else {
        sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
    }
    struct Struct_ov000_021584e8* entry = func_ov000_0215e958(obj->ctx);
    if (!entry) return 0;
    func_ov000_0215a88c(obj->ctx, entry, sel);
    struct Struct_ov024_021ddf5c_4 words;
    words.lo = 0;
    words.hi = 0;
    func_ov000_02159eac(obj->ctx, &words, 0x22);
    unsigned short hp = c->currentStats_->primaryStats.currHP;
    unsigned char flag;
    if (obj->action->flag) flag = 1; else flag = 0;
    func_ov000_0215ccbc((int)obj->ctx, entry, c, -var2, hp, mp, words, flag);
    return entry;
}
