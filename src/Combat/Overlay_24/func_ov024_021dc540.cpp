#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021dc540 {
    unsigned int a : 10;
    unsigned int b : 10;
    unsigned int c : 10;
    unsigned int hi : 2;
};

struct Struct_ov024_021dc540_2 {
    char pad[0x20];
    struct Struct_ov024_021dc540 f20;
    struct Struct_ov024_021dc540 f24;
};

struct Struct_ov024_021dc540_3 { unsigned char pad : 7; unsigned char flag : 1; };

struct Struct_ov024_021dc540_4 {
    char pad0[0xc];
    void* fc;
    void* f10;
};

struct Struct_ov000_021584e8;

extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* world);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int msg);
extern "C" short func_ov000_0215a1d4(void* world, int id, int delta, short* arg3);
extern "C" void func_ov000_02159eac(void* world, unsigned long long* bits, int bit);
extern "C" int func_ov000_0215a124(void* world, int id, int amount);
extern "C" void func_ov000_0215ccbc(void* world, struct Struct_ov000_021584e8* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long words, unsigned char arg7);

static inline int inline_ov024_021dc540(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }

static inline unsigned short inline_ov024_021dc540_2(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.maxMP; }

// USA: func_ov024_021dc540
extern "C" ARM struct Struct_ov000_021584e8* func_ov024_021dc540(struct Struct_ov024_021dc540_4* obj, int arg1, int id, struct Struct_ov024_021dc540_2* range, int amount, int unused, unsigned char arg6) {
    GameObject* src = GetCombatantByID((int)obj->f10, arg1);
    if (!src) return 0;
    GameObject* tgt = GetCombatantByID((int)obj->f10, id);
    if (!tgt) return 0;
    int var2 = src->currentStats_->primaryStats.currMP;
    if (var2 == 0) amount = 0;
    if (tgt->currentStats_->primaryStats.currMP >= inline_ov024_021dc540_2(tgt)) amount = 0;
    if (arg1 == id) amount = 0;
    if (amount > var2) amount = var2;
    unsigned short sel;
    if (arg6 && amount > 0) {
        sel = func_ov024_021da644(id, range->f20.c, range->f24.a);
    } else {
        amount = 0;
        sel = func_ov024_021da644(id, range->f24.b, range->f24.c);
    }
    struct Struct_ov000_021584e8* entry = func_ov000_0215e958(obj->f10);
    if (!entry) return 0;
    func_ov000_0215a88c(obj->f10, entry, sel);
    unsigned long long bits = 0;
    short var6 = 0;
    short delta = func_ov000_0215a1d4(obj->f10, id, amount, &var6);
    if (var6 != 0) {
        func_ov000_02159eac(obj->f10, &bits, 0x22);
    }
    func_ov000_0215a124(obj->f10, arg1, var6);
    struct Struct_ov024_021dc540_3* var8 = (struct Struct_ov024_021dc540_3*)((char*)obj->fc + 0x1c);
    func_ov000_0215ccbc(obj->f10, entry, tgt, -var6, inline_ov024_021dc540(tgt), delta, bits, var8->flag != 0);
    return entry;
}
