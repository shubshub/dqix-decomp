#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Struct_ov000_021584e8;

struct Struct_ov000_0215767c {
    char pad0[0x20];
    unsigned int category : 10;
};

struct ActionEntry {
    char pad0[0x1c];
    short f1c;
    short pad1e;
    unsigned short id;
    unsigned short hp;
    unsigned short mp;
    char unknown_26_[0x30 - 0x26];
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
    char pad2[0x18 - 2];
    unsigned short category;
};

struct Struct_ov000_0215767c_2 {
    char pad0[0x8e00];
    unsigned char tableCount;
    unsigned char unknown_8e01_;
    unsigned char unknown_8e02_;
    char unknown_8e03_[0x8e24 - 0x8e03];
    int unknown_8e24_;
};

extern "C" Struct_ov000_0215767c_10* func_ov000_0215e9d8(void* self);
extern "C" ActionEntry* func_ov000_0215e918(void* self);
extern "C" Struct_ov000_0215767c_9* func_ov000_0215e938(void* self);
extern "C" void func_ov000_02160030(void* obj);
extern "C" void func_ov000_02157cdc(void* obj);
extern "C" void* memset(void* dst, int c, unsigned int n);

extern "C" Struct_ov000_0215767c* func_02079e2c(char* data, int id);
struct Struct_ov000_0215767c_6;
struct Struct_ov000_0215767c_7;
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*, Struct_ov000_0215767c_6*);
struct Struct_ov000_0215767c_4;
struct Struct_ov000_0215767c_5;
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
extern "C" Struct_ov000_021584e8* func_ov000_0215e958(void* self);
extern "C" void func_ov000_0215ccbc(int, Struct_ov000_021584e8*, GameObject*, short, short, short, unsigned long long, unsigned char);
extern "C" void func_ov000_0215ffc4(void* node, void* entry, int v);
extern "C" void func_ov000_0215a88c(void* self, void* entry, int value);

static inline GameObject* inline_ov000_02153aa4(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

static inline short inline_ov000_021584e8(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currHP; }
static inline short inline_ov000_021584e8_2(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov000_0215cac8
extern "C" ARM void func_ov000_0215cac8(Struct_ov000_0215767c_2* self, short* ids, int count, short action,
                                        unsigned short* values, unsigned char* arg5) {
    Struct_ov000_0215767c_10* work = func_ov000_0215e9d8(self);
    ActionEntry* entry = func_ov000_0215e918(self);
    if (work == 0 || entry == 0) {
        return;
    }
    func_ov000_02160030(work);
    memset(entry, 0, 0x30);
    entry->f1c = -1;
    entry->unknown_30_ = 0;
    work->action = action;
    Struct_ov000_0215767c* var2 = func_02079e2c((char*)func_020797dc(), (short)work->action);
    if (var2 != 0) {
        work->category = var2->category;
    }
    GameObject* c = inline_ov000_02153aa4(ids[0]);
    entry->id = ids[0];
    if (c != 0) {
        entry->hp = c->currentStats_->primaryStats.currHP;
        entry->mp = c->currentStats_->primaryStats.currMP;
    }
    func_ov000_02160068((Struct_ov000_0215767c_7*)work, (Struct_ov000_0215767c_6*)entry);

    for (int i = 0; i < count; i++) {
        Struct_ov000_0215767c_9* var5 = func_ov000_0215e938(self);
        if (var5 == 0) {
            continue;
        }
        func_ov000_02157cdc(var5);
        GameObject* target = inline_ov000_02153aa4(ids[i]);
        Struct_ov000_021584e8* out = func_ov000_0215e958(self);
        if (out == 0) {
            continue;
        }
        func_ov000_0215ccbc((int)self, out, target, 0, inline_ov000_021584e8(target), inline_ov000_021584e8_2(target), 0, 0);
        var5->id = ids[i];
        var5->active = 1;
        func_ov000_0215ffc4(var5, out, 0);
        for (int j = 0; j < arg5[i]; j++) {
            func_ov000_0215a88c(self, out, *values++);
        }
        func_ov000_021600cc((Struct_ov000_0215767c_5*)work, (Struct_ov000_0215767c_4*)var5);
        self->unknown_8e01_++;
        self->unknown_8e02_++;
    }
    self->unknown_8e24_++;
    self->tableCount++;
}
