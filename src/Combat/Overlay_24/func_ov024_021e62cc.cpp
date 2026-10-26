#include <globaldefs.h>
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov000_021584e8;
struct Struct_ov000_0215440c { char pad0[9]; unsigned char count; };
struct Struct_ov024_021e62cc {
    char pad0[0x14];
    unsigned char slots[3];
    unsigned char unknown_17_;
    unsigned char depth;
};
struct Struct_ov024_021e62cc_2 { char pad0[0xc]; short value; };
struct Struct_ov024_021e62cc_3 {
    char pad0[4];
    short id;
};
struct Struct_ov024_021e62cc_4 {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* ext;
};
struct Struct_ov024_021e62cc_5 { char pad0[0x10]; int flags; };
struct Struct_ov024_021e62cc_6 {
    char pad0[4];
    struct Struct_ov000_0215440c* list;
    void* unknown_8_;
    char unknown_c_[4];
    void* ctx;
};
struct Struct_ov024_021e62cc_7 { int id; int total; };

extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov000_0215fc60(char*);
extern "C" int func_ov000_0215ffa0(struct Struct_ov024_021e62cc* node);
extern "C" struct Struct_ov024_021e62cc* func_ov000_021600f8(struct Struct_ov000_0215440c* list, int index);
extern "C" struct Struct_ov024_021e62cc_2* func_ov000_0215fff4(void* obj, int limit, int idx);
extern "C" int func_ov024_021e6798(GameObject* c);
extern "C" int func_ov024_021e67b0(GameObject* c);
extern "C" int func_02085400(unsigned char* p);
extern "C" int func_ov000_02156068(void* battle, int id, int kind, int mode);
extern "C" short func_ov000_0215a004(void* world, int arg1, int id2, int value, unsigned long long* bits, struct Struct_ov024_021e62cc_5* rec, int a6, int a7);
extern "C" struct Struct_ov000_021584e8* func_ov000_0215e958(void* world);
extern "C" int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int msg);
extern "C" void func_ov000_0215ccbc(int unused, struct Struct_ov000_021584e8* out, GameObject* combatant,
                            short arg3, short valA, short valB, unsigned long long words, unsigned char arg7);
extern "C" void func_ov000_0215fe84(void* arg0, void* node, int idx);

static inline short inline_ov024_021e57e0(ModifiableCombatStats* s) {
    return s->primaryStats.currMP;
}

// USA: func_ov024_021e62cc
extern "C" ARM void func_ov024_021e62cc(struct Struct_ov024_021e62cc_6* self, int id, struct Struct_ov024_021e62cc_5* skill) {
    GameState* gs = GameState::GetInstance();
    if (func_ov000_0215fc60((char*)self->ctx) != 0) return;
    if (!(skill->flags & 0x80)) return;
    GameObject* attacker = GetCombatantByID((int)self->ctx, id);
    if (!attacker) return;
    if (func_02010088((struct S_10088*)attacker)) return;

    int count = 0;
    struct Struct_ov024_021e62cc_7 entries[8];
    memset(entries, count, sizeof(entries));
    for (int i = 0; i < self->list->count; i++) {
        struct Struct_ov024_021e62cc* node = func_ov000_021600f8(self->list, i);
        if (!node) continue;
        int found = 0;
        for (int j = 1; j < node->unknown_17_; j++) {
            if (node->slots[j] == 3) found = 1;
        }
        if (found) continue;
        int owner = func_ov000_0215ffa0(node);
        if (id == owner) continue;
        int var9 = 0;
        for (int k = 0; k < count; k++) {
            if (owner == entries[k].id) {
                var9 = 1;
                for (int d = 0; d < node->depth; d++) {
                    struct Struct_ov024_021e62cc_2* p = func_ov000_0215fff4(node, d, 0);
                    if (p) entries[k].total += p->value;
                }
            }
        }
        if (var9) continue;
        entries[count].id = owner;
        for (int d = 0; d < node->depth; d++) {
            struct Struct_ov024_021e62cc_2* p = func_ov000_0215fff4(node, d, 0);
            if (p) entries[count].total += p->value;
        }
        count++;
    }

    for (int k = 0; k < count; k++) {
        GameObject* target = GetCombatantByID((int)self->ctx, (short)entries[k].id);
        if (!target) continue;
        if (func_02010088((struct S_10088*)target)) continue;
        if (func_ov024_021e6798(target)) continue;
        if (entries[k].total <= 0) continue;
        float rate = 0.25f;
        int party = 0;
        if (entries[k].id >= 0 && entries[k].id <= 3) party = 1;
        if (party) {
            GameObject* var19 = func_0200ff1c(gs, entries[k].id);
            if (!var19) continue;
            struct Random* var20 = (struct Random*)self->ctx;
            int ok = 0;
            if (func_ov024_021e67b0(var19)) {
                rate = 0.25f;
                ok = 1;
            } else if (func_02085400(((struct Struct_ov024_021e62cc_4*)var19)->ext)) {
                if (NextRandomMax(var20, 100) < 50) {
                    rate = 0.2f;
                    ok = 1;
                }
            }
            if (!ok) continue;
        } else {
            if (!func_ov024_021e67b0(target)) continue;
        }
        int var22 = rate * entries[k].total;
        if (func_ov000_02156068(self->ctx, id, 0, 1)) {
            var22 = NextRandomMax((struct Random*)self->ctx, 2);
        }
        if (var22 <= 0) continue;
        unsigned long long bits = 0;
        short result = func_ov000_0215a004(self->ctx, ((struct Struct_ov024_021e62cc_3*)target)->id, id, var22, &bits, skill, 0, 0);
        struct Struct_ov000_021584e8* entry = func_ov000_0215e958(self->ctx);
        if (!entry) return;
        func_ov000_0215a88c(self->ctx, entry, func_ov024_021da644(id, 0x1b4, 0x22b));
        func_ov000_0215ccbc((int)self->ctx, entry, attacker, var22, result, inline_ov024_021e57e0(attacker->currentStats_), bits, 0);
        func_ov000_0215fe84(self->unknown_8_, entry, 4);
        ((unsigned char*)self->ctx)[0x8e02]++;
        if (func_ov000_02159f18(self->ctx, bits, 2)) {
            entry = func_ov000_0215e958(self->ctx);
            if (!entry) return;
            func_ov000_0215a88c(self->ctx, entry, func_ov024_021da644(id, 0x1b3, 0x22a));
            func_ov000_0215ccbc((int)self->ctx, entry, attacker, 0, result, inline_ov024_021e57e0(attacker->currentStats_), 0, 0);
            func_ov000_0215fe84(self->unknown_8_, entry, 4);
            ((unsigned char*)self->ctx)[0x8e02]++;
        }
        if (func_ov000_02159f18(self->ctx, bits, 2)) return;
    }
}
