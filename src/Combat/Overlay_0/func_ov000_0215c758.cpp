#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "GameState/GameState.h"

struct Struct_ov000_021584e8 {
    unsigned long long bits;
};

struct Struct_ov000_0215767c {
    char pad0[0x20];
    unsigned int category : 10;
    unsigned int unknown_21_2_ : 10;
    unsigned int extra : 10;
    char pad24[0x28 - 0x24];
    unsigned int bonus : 10;
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
extern "C" int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
extern "C" void func_ov000_0215ccbc(int, Struct_ov000_021584e8*, GameObject*, short, short, short, unsigned long long, unsigned char);
extern "C" void func_ov000_0215ffc4(void* node, void* entry, int v);
extern "C" void func_ov000_0215a88c(void* self, void* entry, int value);

static inline GameObject* inline_ov000_02153aa4(int id) {
    GameState* gs = GameState::GetInstance();
    return gs->GetCombatantByIndex(id);
}

// USA: func_ov000_0215c758
extern "C" ARM void func_ov000_0215c758(Struct_ov000_0215767c_2* self, short* targets, int count, int kind, short* arg4,
                                        short* arg5, unsigned long long* bits) {
    Struct_ov000_0215767c_10* work = func_ov000_0215e9d8(self);
    ActionEntry* entry = func_ov000_0215e918(self);
    if (work == 0 || entry == 0) {
        return;
    }
    func_ov000_02160030(work);
    memset(entry, 0, 0x30);
    entry->f1c = -1;
    entry->unknown_30_ = 0;
    work->action = 0x3a6;
    if (kind == 0) {
        if (count == 1) {
            work->action = 0x3a2;
        } else {
            work->action = 0x3a3;
        }
    } else if (kind == 1) {
        if (count == 1) {
            work->action = 0x3a4;
        } else {
            work->action = 0x3a5;
        }
    }
    Struct_ov000_0215767c* var2 = func_02079e2c((char*)func_020797dc(), (short)work->action);
    if (var2 != 0) {
        work->category = var2->category;
    }
    GameObject* c = inline_ov000_02153aa4(targets[0]);
    entry->id = targets[0];
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
        GameObject* target = inline_ov000_02153aa4(targets[i]);
        short value = arg5[i];
        unsigned char mode = kind;
        short hp = target->currentStats_->primaryStats.currHP;
        short mp = target->currentStats_->primaryStats.currMP;
        if (mode == 0 || mode == 1) {
            value *= -1;
        }
        if (kind == 0 || kind == 2) {
            hp = arg4[i];
        } else {
            mp = arg4[i];
        }
        Struct_ov000_021584e8* out = func_ov000_0215e958(self);
        if (out == 0) {
            continue;
        }
        func_ov000_0215ccbc((int)self, out, target, value, hp, mp, bits[i], 0);
        var5->id = targets[i];
        var5->active = 1;
        func_ov000_0215ffc4(var5, out, 0);
        self->unknown_8e02_++;
        if (kind == 2) {
            work->category = 0;
            func_ov000_0215a88c(self, out, (unsigned short)var2->category);
            func_ov000_0215a88c(self, out, (unsigned short)var2->extra);
            if (func_ov000_02159f18(self, out->bits, 2)) {
                func_ov000_0215a88c(self, out, (unsigned short)var2->bonus);
            }
        }
        func_ov000_021600cc((Struct_ov000_0215767c_5*)work, (Struct_ov000_0215767c_4*)var5);
        self->unknown_8e01_++;
        self->unknown_8e02_++;
    }
    self->unknown_8e24_++;
    self->tableCount++;
}
