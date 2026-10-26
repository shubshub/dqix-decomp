#include <globaldefs.h>
#include "GameState/GameState.h"

struct Struct_ov000_0215c2d0 {
    char pad0[0x20];
    int f20;
};

struct ActionEntry {
    char pad0[4];
    int f4;
    char pad8[0x1c - 8];
    short f1c;
    short unknown_1e_;
    unsigned short id;
    char unknown_22_[0x27 - 0x22];
    unsigned char unknown_27_;
    char pad28[0x30 - 0x28];
    int unknown_30_;
};

struct Struct_ov000_0215767c_9 {
    char pad0[0xe];
    short id;
    char pad10[0x17 - 0x10];
    unsigned char active;
};

struct Struct_ov000_0215767c_10 {
    unsigned short action;
    char pad2[6];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_;
    unsigned char flags;
};

struct Struct_ov000_0215767c_2 {
    char pad0[0x8e00];
    unsigned char tableCount;
    unsigned char unknown_8e01_;
    unsigned char unknown_8e02_;
    char unknown_8e03_[0x8e24 - 0x8e03];
    int unknown_8e24_;
};

struct Struct_ov000_0215440c_2;
extern "C" ActionEntry* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" Struct_ov000_0215767c_10* func_ov000_0215e9d8(void* self);
extern "C" ActionEntry* func_ov000_0215e918(void* self);
extern "C" Struct_ov000_0215767c_9* func_ov000_0215e938(void* self);
extern "C" void func_ov000_02160030(void* obj);
extern "C" void func_ov000_02157cdc(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" void* memcpy(void* dst, const void* src, unsigned int n);
struct Struct_ov000_0215767c_6;
struct Struct_ov000_0215767c_7;
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*, Struct_ov000_0215767c_6*);
struct Struct_ov000_0215767c_4;
struct Struct_ov000_0215767c_5;
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" Struct_ov000_0215c2d0* func_ov000_0215e958(void* self);
struct Struct_ov000_021584e8;
extern "C" void func_ov000_0215ccbc(int, Struct_ov000_021584e8*, GameObject*, short, short, short, unsigned long long, unsigned char);
extern "C" void func_ov000_0215ffc4(void* node, void* entry, int v);

static inline GameObject* inline_ov000_02153aa4(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

static inline short inline_ov000_021584e8(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_021584e8_2(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov000_0215c2d0
extern "C" ARM void func_ov000_0215c2d0(Struct_ov000_0215767c_2* self, Struct_ov000_0215767c_10* src) {
    for (int i = 0; i < src->unknown_8_; i++) {
        ActionEntry* e = func_ov000_02160094((Struct_ov000_0215440c_2*)src, i);
        if (e == 0) {
            continue;
        }
        GameObject* c = inline_ov000_02153aa4((short)e->id);
        if (c == 0) {
            continue;
        }
        int var3 = e->unknown_27_;
        if (var3 <= 0) {
            continue;
        }
        Struct_ov000_0215767c_10* work = func_ov000_0215e9d8(self);
        if (work == 0) {
            continue;
        }
        func_ov000_02160030(work);
        ActionEntry* entry = func_ov000_0215e918(self);
        if (entry == 0) {
            continue;
        }
        memset(entry, 0, 0x30);
        entry->f1c = -1;
        entry->unknown_30_ = 0;
        Struct_ov000_0215767c_9* var6 = func_ov000_0215e938(self);
        if (var6 == 0) {
            continue;
        }
        func_ov000_02157cdc(var6);
        Struct_ov000_0215c2d0* out = func_ov000_0215e958(self);
        if (out == 0) {
            continue;
        }
        memset(out, 0, 0x20);
        out->f20 = 0;
        work->action = 0x3b0;
        memcpy(entry, e, sizeof(ActionEntry));
        e->f4 = 0;
        e->unknown_27_ = 0;
        e->f1c = -1;
        e->unknown_1e_ = 0;
        func_ov000_0215ccbc((int)self, (Struct_ov000_021584e8*)out, c, 0, inline_ov000_021584e8(c), inline_ov000_021584e8_2(c), 0, 0);
        var6->id = e->id;
        var6->active = 1;
        func_ov000_0215ffc4(var6, out, 0);
        work->flags |= 4;
        func_ov000_02160068((Struct_ov000_0215767c_7*)work, (Struct_ov000_0215767c_6*)entry);
        func_ov000_021600cc((Struct_ov000_0215767c_5*)work, (Struct_ov000_0215767c_4*)var6);
        self->unknown_8e24_++;
        self->tableCount++;
        self->unknown_8e01_++;
        self->unknown_8e02_++;
    }
}
