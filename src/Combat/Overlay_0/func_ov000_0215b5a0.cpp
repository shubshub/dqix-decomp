#include <globaldefs.h>
#include "std_library_functions.h"
#include "GameState/GameState.h"
#include "Util/Random.h"

struct Struct_ov000_0215b5a0 {
    char pad0[0x14];
    unsigned int flags;
    char pad18[0x22 - 0x18];
    unsigned short unknown_22_0_ : 14;
    unsigned short pending : 1;
    unsigned short unknown_23_7_ : 1;
    unsigned char level;
};

struct Struct_ov000_0215b5a0_2 {
    Random rng;
    char pad20[0x8e00 - sizeof(Random)];
    unsigned char tableCount;
    unsigned char unknown_8e01_;
    unsigned char unknown_8e02_;
    char unknown_8e03_[0x8e24 - 0x8e03];
    int unknown_8e24_;
};

struct Struct_ov000_0215b5a0_3 { unsigned short kind; char pad2[0xb - 2]; unsigned char flags; };
struct Struct_ov000_0215b5a0_4 { char pad0[0x1c]; short unknown_1c_; short pad1e; unsigned short id, hp, mp; char unknown_26_[0x30 - 0x26]; int tail; };
struct Struct_ov000_0215b5a0_5 { char pad0[0xe]; short ids[4]; char pad16; unsigned char count; };
struct Struct_ov000_021584e8 { char pad0[0x20]; int tail; };
struct Struct_ov000_0215440c { unsigned short kind; char pad2[9 - 2]; unsigned char count; };

struct S_10088;
extern "C" Struct_ov000_0215b5a0_5* func_ov000_021600f8(Struct_ov000_0215440c*, int);
extern "C" int func_02010088(S_10088*);
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" int func_020882f8(unsigned char*);
extern "C" int func_ov000_02156038(GameObject*);
extern "C" int func_ov000_02156050(GameObject*);
extern "C" int func_020881c4(unsigned char*);
extern "C" Struct_ov000_0215b5a0_3* func_ov000_0215e9d8(void*);
extern "C" void func_ov000_02160030(void*);
extern "C" Struct_ov000_0215b5a0_4* func_ov000_0215e918(void*);
extern "C" Struct_ov000_0215b5a0_5* func_ov000_0215e938(void*);
extern "C" void func_ov000_02157cdc(void*);
extern "C" void func_02088150(void*);
extern "C" void func_02088220(void*, int);
extern "C" void func_ov000_0215ffc4(void*, void*, int);
extern "C" void func_ov000_0215a88c(void*, void*, int);
struct Struct_ov000_0215767c_7; struct Struct_ov000_0215767c_6; struct Struct_ov000_0215767c_5; struct Struct_ov000_0215767c_4;
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*, Struct_ov000_0215767c_6*);
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" void func_ov000_0215ccbc(int, Struct_ov000_021584e8*, GameObject*, short, short, short, unsigned long long, unsigned char);
extern "C" Struct_ov000_021584e8* func_ov000_0215e958(void*);
extern "C" int func_ov000_02159f18(void*, unsigned long long, int);

static inline Struct_ov000_0215b5a0* inline_ov000_0215b5a0(GameObject* c) { return (Struct_ov000_0215b5a0*)c->currentStats_; }
static inline short inline_ov000_021584e8(GameObject* c) { return c->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_021584e8_2(GameObject* c) { return c->currentStats_->primaryStats.currMP; }
static inline bool inline_ov000_021537b8(short id) { return id >= 0 && id <= 3; }

// USA: func_ov000_0215b5a0
extern "C" ARM void func_ov000_0215b5a0(Struct_ov000_0215b5a0_2* self, Struct_ov000_0215440c* list) {
    short ids[8] = {-1};
    static const int sSleepChance[4] = {100, 50, 25, 25};
    short n = 0;
    for (int i = 0; i < list->count; i++) {
        Struct_ov000_0215b5a0_5* node = func_ov000_021600f8(list, i);
        if (!node) continue;
        short id = node->ids[(signed char)(node->count - 1)];
        bool found = false;
        for (int j = 0; j < n; j++) {
            if (id == ids[j]) { found = true; break; }
        }
        if (!found) ids[n++] = id;
    }
    for (int k = 0; k < n; k++) {
        Struct_ov000_0215b5a0_3* work; Struct_ov000_0215b5a0_4* entry; Struct_ov000_0215b5a0_5* target; Struct_ov000_021584e8* out;
        GameState* gs = GameState::GetInstance();
        short id = ids[k];
        GameObject* unit = gs->GetCombatantByIndex(id);
        if (!unit) continue;
        if (!inline_ov000_0215b5a0(unit)->pending) continue;
        inline_ov000_0215b5a0(unit)->pending = 0;
        if (func_02010088((S_10088*)unit)) continue;
        if (func_ov000_02153c0c(unit)) continue;
        if (func_020882f8((unsigned char*)unit->currentStats_)) continue;
        if (func_ov000_02156038(unit)) continue;
        if (func_ov000_02156050(unit)) continue;
        if (inline_ov000_0215b5a0(unit)->flags & 0x1000000) continue;
        if (!func_020881c4((unsigned char*)unit->currentStats_)) continue;
        int level = inline_ov000_0215b5a0(unit)->level;
        if (NextRandomMax(&self->rng, 100) >= sSleepChance[level]) continue;

        work = func_ov000_0215e9d8(self);
        if (!work) continue;
        func_ov000_02160030(work);
        entry = func_ov000_0215e918(self);
        if (!entry) continue;
        memset(entry, 0, 0x30); entry->unknown_1c_ = -1; entry->tail = 0;
        target = func_ov000_0215e938(self);
        if (!target) continue;
        func_ov000_02157cdc(target);
        out = func_ov000_0215e958(self);
        if (!out) continue;
        memset(out, 0, 0x20); out->tail = 0;
        work->kind = 0x3a0;
        unsigned long long bits = 0;
        bits |= 1ULL << 36;
        if (level + 1 >= 4) {
            func_02088150(unit->currentStats_);
            bits |= 1ULL << 7;
        } else {
            func_02088220(unit->currentStats_, level + 1);
        }
        int msg = 0;
        switch (level + 1) {
        case 1: msg = 0x31; break;
        case 2: msg = 0x32; break;
        case 3: msg = 0x33; break;
        case 4: msg = 0x34; break;
        }
        entry->id = ids[k];
        entry->hp = unit->currentStats_->primaryStats.currHP;
        entry->mp = unit->currentStats_->primaryStats.currMP;
        {
            short mp = inline_ov000_021584e8_2(unit);
            short hp = inline_ov000_021584e8(unit);
            func_ov000_0215ccbc((int)self, out, unit, level + 1, hp, mp, bits, 0);
        }
        func_ov000_0215a88c(self, out, msg);
        target->ids[0] = ids[k];
        target->count = 1;
        func_ov000_0215ffc4(target, out, 0);
        func_ov000_02160068((Struct_ov000_0215767c_7*)work, (Struct_ov000_0215767c_6*)entry);
        func_ov000_021600cc((Struct_ov000_0215767c_5*)work, (Struct_ov000_0215767c_4*)target);
        work->flags |= 4;
        self->unknown_8e24_++; self->tableCount++; self->unknown_8e01_++; self->unknown_8e02_++;

        if (!func_ov000_02159f18(self, bits, 7)) continue;
        work = func_ov000_0215e9d8(self);
        if (!work) continue;
        func_ov000_02160030(work);
        entry = func_ov000_0215e918(self);
        if (!entry) continue;
        memset(entry, 0, 0x30); entry->unknown_1c_ = -1; entry->tail = 0;
        target = func_ov000_0215e938(self);
        if (!target) continue;
        func_ov000_02157cdc(target);
        out = func_ov000_0215e958(self);
        if (!out) continue;
        memset(out, 0, 0x20); out->tail = 0;
        int party = inline_ov000_021537b8(id);
        work->kind = party ? 0x39c : 0x39d;
        entry->id = ids[k];
        entry->hp = unit->currentStats_->primaryStats.currHP;
        entry->mp = unit->currentStats_->primaryStats.currMP;
        work->flags |= 4;
        {
            short mp = inline_ov000_021584e8_2(unit);
            short hp = inline_ov000_021584e8(unit);
            func_ov000_0215ccbc((int)self, out, unit, 0, hp, mp, 0, 0);
        }
        func_ov000_0215a88c(self, out, 0x35);
        target->ids[0] = ids[k];
        target->count = 1;
        func_ov000_0215ffc4(target, out, 0);
        self->unknown_8e02_++;
        func_ov000_02160068((Struct_ov000_0215767c_7*)work, (Struct_ov000_0215767c_6*)entry);
        func_ov000_021600cc((Struct_ov000_0215767c_5*)work, (Struct_ov000_0215767c_4*)target);
        self->unknown_8e24_++; self->tableCount++; self->unknown_8e01_++; self->unknown_8e02_++;
    }
}
