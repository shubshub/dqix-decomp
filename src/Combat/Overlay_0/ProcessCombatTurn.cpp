#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"

struct CombatStats {
    char pad0[0xc];
    unsigned short power;
    char pad1[0x2a - 0xe];
    short unknown_2a_;
    short unknown_2c_;
    char pad2[0x36 - 0x2e];
    short unknown_36_;
    char pad3[0x3b - 0x38];
    unsigned char unknown_3b_0_ : 1;
    unsigned char flag1 : 1;
    unsigned char flag2 : 1;
};

struct Struct_ov000_0215ab88 {
    char pad0[0x138];
    CombatStats* stats;
    char pad1[0x184 - 0x13c];
    unsigned char busy;
};

struct ActionEntry {
    char pad0[0x1c];
    short f1c;
    short pad1e;
    unsigned short id;
    char unknown_22_[0x30 - 0x22];
    int unknown_30_;
};

struct Struct_ov000_0215767c_9 {
    char pad0[0xe];
    short id;
    char pad10[0x17 - 0x10];
    unsigned char active;
    char pad18[0x24 - 0x18];
};

struct Struct_ov000_0215767c_10 {
    unsigned short action;
    char pad2[6];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char unknown_a_[6];
    ActionEntry* entry;
    char unknown_14_[0x28 - 0x14];
};

struct Struct_ov000_0215767c {
    char pad0[4];
    unsigned int kind : 12;
    char pad8[0x10 - 8];
    unsigned int flags;
    char unknown_14_[0x18 - 0x14];
    unsigned int unknown_18_0_ : 5;
    unsigned int type : 7;
    char unknown_1a_[0x30 - 0x1c];
    short linked;
};

struct PartyInfo {
    unsigned short action;
    unsigned char target;
    char pad3;
    unsigned char flags;
};

struct Struct_ov000_0215767c_2 {
    char pad0[0x8e00];
    unsigned char tableCount;
    char unknown_8e01_[0x8e14 - 0x8e01];
    signed char unknown_8e14_;
    char unknown_8e15_[0x8e18 - 0x8e15];
    char* unknown_8e18_;
    char unknown_8e1c_[4];
    int unknown_8e20_;
    int unknown_8e24_;
    char unknown_8e28_[0x8e49 - 0x8e28];
    unsigned char mode;
    char unknown_8e4a_[0x8e70 - 0x8e4a];
    ActionEntry* entries;
    Struct_ov000_0215767c_9* targets;
    Struct_ov000_0215767c_10* actions;
    int unknown_8e7c_;
    unsigned char unknown_8e80_;
    unsigned char unknown_8e81_;
};

struct Struct_ov000_02182c74 { short v[16]; };
struct Struct_ov000_02182b04 { short v[8]; };
struct PartyList { signed char v[4]; };
struct Struct_020749ac { int id; float weight; };
struct Struct_ov000_0215d63c_3 { char buf[0x7c]; };
struct Struct_ov000_0215767c_3 { char buf[0x678]; };

extern "C" int func_ov000_02153e40(void* obj, short* buf, int max, int start);
void UpdateCombatantAttack(int, int);
void UpdateCombatantDefense(int, int);
void UpdateCombatantAgility(int, int);
void UpdateCombatantCharm(int, int);
void UpdateCombatantMagicalMight(int, int);
void UpdateCombatantMagicalMending(int, int);
extern "C" void func_ov024_021f67f8(void);
extern "C" void __clear(void* buf, int n);
struct Random;
int NextRandomMax(Random*, int);
extern "C" int func_ov000_0215fc60(char*);
float NextRandomFloatBetween(Random*, float, float);
extern "C" void func_020749ac(void* arr, int lo, int hi, int mode);
extern "C" void* memset(void* dst, int c, unsigned int n);
extern "C" Struct_ov000_0215ab88* func_0200fea4(GameState*, int);
struct Struct_02053dc0;
extern "C" PartyInfo* func_02053dc0(Struct_02053dc0*);
extern "C" void func_020dc548(signed char id, signed char* out, signed char* count);
extern "C" void func_ov000_02160030(void* obj);
struct Struct_ov000_02157d14;
extern "C" void func_ov000_02157d14(Struct_ov000_02157d14*);
extern "C" void func_ov000_02157cdc(void* obj);
extern "C" int func_ov000_02155f9c(void* self, int id, int arg2);
extern "C" void func_ov024_021f73b8(Struct_ov000_0215767c_3* b);
extern "C" void func_ov024_021f9030(Struct_ov000_0215767c_3* b, void* self, int id, Struct_ov000_0215767c_10* node);
extern "C" int func_ov000_02159d94(void*, int);
extern "C" void func_0208a910(int* out);
extern "C" int func_0208a91c(int* p0, void* self, int id, int* outCount, short* arg4);
extern "C" Struct_ov000_0215767c* func_02079e2c(char* data, int id);
struct Struct_02070b6c_3;
extern "C" void* func_02070fd0(Struct_02070b6c_3*, int);
struct Struct_0204887c;
extern "C" void func_0204887c(Struct_0204887c*, char*);
struct Struct_ov000_0215767c_4;
struct Struct_ov000_0215767c_5;
extern "C" void func_ov000_021600cc(Struct_ov000_0215767c_5*, Struct_ov000_0215767c_4*);
struct Struct_ov000_0215767c_6;
struct Struct_ov000_0215767c_7;
extern "C" void func_ov000_02160068(Struct_ov000_0215767c_7*, Struct_ov000_0215767c_6*);
extern "C" int func_ov000_0215f57c(void* self, int id);
extern "C" void func_ov000_0215f110(char*);
extern "C" void func_ov000_0215f1ac(void* self);
struct S_10088;
extern "C" int func_02010088(S_10088*);
struct GameObject;
extern "C" int func_ov000_02153c0c(GameObject*);
extern "C" int func_ov000_021599dc(GameObject*);
extern "C" Struct_ov000_0215767c_10* func_ov000_0215e9d8(void* self);
extern "C" ActionEntry* func_ov000_0215e918(void* self);
struct Struct_ov000_0215440c;
extern "C" Struct_ov000_0215767c_9* func_ov000_021600f8(Struct_ov000_0215440c*, int);
struct Struct_ov000_0215440c_2;
extern "C" ActionEntry* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" void func_ov000_0215767c(void* self, Struct_ov000_0215767c_10* src, Struct_ov000_0215767c_10* dst);
extern "C" void func_ov024_021eb510(void*);
extern "C" void func_ov024_021eb5d0(Struct_ov000_0215d63c_3* s, void* self, Struct_ov000_0215767c_10* a, Struct_ov000_0215767c_10* b, int mode);
extern "C" void func_ov000_02157d3c(void* self, Struct_ov000_0215767c_10* a, int flag);
extern "C" void func_ov000_0215bf5c(void* self, Struct_ov000_0215767c_10* a);
extern "C" void func_ov000_0215bbbc(void* self, Struct_ov000_0215767c_10* a);
extern "C" void func_ov000_0215c2d0(void* self, Struct_ov000_0215767c_10* a);
extern "C" void func_ov000_0215b278(void* self, Struct_ov000_0215767c_10* a);
extern "C" void func_ov000_0215ae80(void* self);
extern "C" void func_ov000_0215b5a0(void* self, Struct_ov000_0215767c_10* a);
extern "C" void func_ov000_0215ab88(void* self);
extern "C" void func_ov000_0215b198(void* self);
extern "C" void func_ov000_0215c4cc(void* self);

extern Struct_ov000_02182c74 data_ov000_02182d34;
extern PartyList data_ov000_02182a60;
extern Struct_ov000_02182b04 data_ov000_02182ba4;
extern Struct_ov000_02182b04 data_ov000_02182b04;

static inline Struct_ov000_0215ab88* inline_ov000_02153aa4(int id) {
    GameState* bs = GameState::GetInstance();
    return (Struct_ov000_0215ab88*)bs->GetCombatantByIndex(id);
}

static inline Struct_ov000_0215ab88* inline_ov000_0215d63c(int id) {
    GameState* bs = GameState::GetInstance();
    return func_0200fea4(bs, id);
}

// USA: func_ov000_0215d63c
extern "C" ARM void ProcessCombatTurn(Struct_ov000_0215767c_2* self, SafeAllocator* alloc) {
    long j;
    void* gs = GameState::GetInstance();
    ActionDataTables* data = func_020797dc();
    Struct_ov000_02182c74 ids = data_ov000_02182d34;
    long count = func_ov000_02153e40(self, ids.v, 0x10, 1);

    for (long i = 0; i < count; i++) {
        int id = ids.v[i];
        UpdateCombatantAttack((int)self, id);
        UpdateCombatantDefense((int)self, id);
        UpdateCombatantAgility((int)self, id);
        UpdateCombatantCharm((int)self, id);
        UpdateCombatantMagicalMight((int)self, id);
        UpdateCombatantMagicalMending((int)self, id);
    }

    func_ov024_021f67f8();

    Struct_020749ac var7[16];
    __clear(var7, sizeof(var7));
    unsigned char n = 0;
    for (long i = 0; i < count; i++) {
        short id = ids.v[i];
        Struct_ov000_0215ab88* c = inline_ov000_02153aa4(id);
        if (c == 0) {
            continue;
        }
        if (self->unknown_8e20_ == 0) {
            if (self->mode == 2) {
                int party = 0;
                if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                    party = 1;
                }
                if (party) {
                    continue;
                }
                if (n != 0 && NextRandomMax((Random*)self, 100) >= 0x43) {
                    continue;
                }
            } else if (self->mode == 1) {
                int party = 0;
                if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                    party = 1;
                }
                if (!party) {
                    continue;
                }
            }
        }
        if (func_ov000_0215fc60((char*)self) != 0) {
            int id = ids.v[i];
            int party = 0;
            if (!(id < 0 || id > 3)) {
                party = 1;
            }
            if (party && id != 0) {
                continue;
            }
        }
        var7[n].id = ids.v[i];
        unsigned int power = c->stats->power;
        var7[n].weight = (float)power * NextRandomFloatBetween((Random*)self, 0.51f, 1.0f);
        n++;
    }

    count = n;
    func_020749ac(var7, 0, n - 1, 1);
    memset(&ids, 0, sizeof(ids));
    for (j = 0; j < count; j++) {
        ids.v[j] = var7[j].id;
    }

    self->entries = (ActionEntry*)alloc->Allocate(0x48 * sizeof(ActionEntry));
    self->unknown_8e80_ = 0;
    self->targets = (Struct_ov000_0215767c_9*)alloc->Allocate(0x88 * sizeof(Struct_ov000_0215767c_9));
    self->unknown_8e81_ = 0;
    self->actions = (Struct_ov000_0215767c_10*)alloc->Allocate(0x48 * sizeof(Struct_ov000_0215767c_10));
    self->unknown_8e7c_ = 0;

    for (long i = 0; i < count; i++) {
        int party = 0;
        if (ids.v[i] >= 0 && ids.v[i] <= 3) {
            party = 1;
        }
        if (party) {
            Struct_ov000_0215ab88* c = (Struct_ov000_0215ab88*)func_0200ff1c((GameState*)gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = func_02053dc0((Struct_02053dc0*)c);
                if (info != 0 && (info->flags & 1)) {
                    PartyList members = data_ov000_02182a60;
                    signed char var22 = 0;
                    func_020dc548(ids.v[i], members.v, &var22);
                    for (unsigned int j = 0; j < var22; j++) {
                        Struct_ov000_0215ab88* m = (Struct_ov000_0215ab88*)func_0200ff1c((GameState*)gs, members.v[j]);
                        if (m != 0) {
                            PartyInfo* var25 = func_02053dc0((Struct_02053dc0*)m);
                            if (var25 != 0) {
                                var25->flags |= 1;
                            }
                        }
                    }
                }
            }
        }
    }

    for (long i = 0; i < count; i++) {
        Struct_ov000_0215767c_10* node = &self->actions[self->unknown_8e7c_];
        func_ov000_02160030(node);
        node->unknown_8_ = 1;
        node->entry = &self->entries[self->unknown_8e80_];
        func_ov000_02157d14((Struct_ov000_02157d14*)node->entry);
        node->entry->id = ids.v[i];

        Struct_ov000_02182b04 targets = data_ov000_02182ba4;
        int var29 = 0;
        int party = 0;
        if (ids.v[i] >= 0 && ids.v[i] <= 3) {
            party = 1;
        }
        if (party) {
            Struct_ov000_0215ab88* c = (Struct_ov000_0215ab88*)func_0200ff1c((GameState*)gs, ids.v[i]);
            if (c != 0) {
                PartyInfo* info = func_02053dc0((Struct_02053dc0*)c);
                if (info != 0 && (info->flags & 1)) {
                    continue;
                }
            }
        }

        if (func_ov000_02155f9c(self, ids.v[i], 1) != 0) {
            node->action = 0x1f7;
        } else {
            node->action = 2;
            int party = 0;
            if (ids.v[i] >= 0 && ids.v[i] <= 3) {
                party = 1;
            }
            if (party) {
                Struct_ov000_0215ab88* c = (Struct_ov000_0215ab88*)func_0200ff1c((GameState*)gs, ids.v[i]);
                if (c != 0) {
                    PartyInfo* info = func_02053dc0((Struct_02053dc0*)c);
                    if (info != 0) {
                        node->action = info->action;
                    }
                    if (node->action == 0) {
                        continue;
                    }
                    Struct_ov000_0215767c_3 big;
                    func_ov024_021f73b8(&big);
                    func_ov024_021f9030(&big, self, ids.v[i], node);
                    if (node->action == 0x92) {
                        int target = info->target;
                        Struct_ov000_0215ab88* t = inline_ov000_02153aa4(target);
                        if (t != 0) {
                            t->stats->unknown_2c_ = ids.v[i];
                        }
                        c->stats->unknown_2a_ = info->target;
                        var29 = 1;
                        targets.v[0] = info->target;
                    }
                }
            } else {
                int kind = func_ov000_02159d94(self, (short)node->entry->id);
                int var40 = (short)node->entry->id;
                Struct_ov000_0215ab88* me = inline_ov000_0215d63c(var40);
                if (kind != 2) {
                    int work;
                    func_0208a910(&work);
                    node->action = func_0208a91c(&work, self, (unsigned short)node->entry->id, &var29, targets.v);
                    Struct_ov000_0215767c* var43 = func_02079e2c((char*)data, (short)node->action);
                    if (var43 != 0) {
                        while (var43->type == 0x22) {
                            void* e = func_02070fd0((Struct_02070b6c_3*)(self->unknown_8e18_ + 0x684), var43->linked);
                            if (e != 0) {
                                func_0204887c((Struct_0204887c*)me, (char*)e);
                                me->stats->unknown_36_ = var43->linked;
                            }
                            memset(targets.v, -1, sizeof(targets));
                            var29 = 0;
                            node->action = func_0208a91c(&work, self, (unsigned short)node->entry->id, &var29, targets.v);
                            var43 = func_02079e2c((char*)data, (short)node->action);
                            if (var43 == 0) {
                                break;
                            }
                        }
                    }
                }
                if (node->action == 0x92 || node->action == 0x3a1) {
                    Struct_ov000_0215ab88* t = inline_ov000_02153aa4(targets.v[0]);
                    if (t != 0) {
                        t->stats->unknown_2c_ = ids.v[i];
                    }
                    me->stats->unknown_2a_ = targets.v[0];
                }
            }
        }

        node->unknown_9_ = 0;
        for (int j = 0; j < var29; j++) {
            Struct_ov000_0215767c_9* var47 = &self->targets[self->unknown_8e81_];
            func_ov000_02157cdc(var47);
            var47->id = targets.v[j];
            var47->active = 1;
            func_ov000_021600cc((Struct_ov000_0215767c_5*)node, (Struct_ov000_0215767c_4*)var47);
            self->unknown_8e81_++;
        }
        self->unknown_8e7c_++;
        self->unknown_8e80_++;

        int extra = func_ov000_0215f57c(self, ids.v[i]);
        for (int k = 0; k < extra; k++) {
            Struct_ov000_0215767c_10* node2 = &self->actions[self->unknown_8e7c_];
            func_ov000_02160030(node2);
            node2->unknown_8_ = 1;
            node2->entry = &self->entries[self->unknown_8e80_];
            func_ov000_02157d14((Struct_ov000_02157d14*)node2->entry);
            node2->entry->id = ids.v[i];

            Struct_ov000_02182b04 var51 = data_ov000_02182b04;
            int var52 = 0;
            if (func_ov000_02155f9c(self, ids.v[i], 1) != 0) {
                node2->action = 0x1f7;
            } else {
                node2->action = 2;
                int kind = func_ov000_02159d94(self, (short)node2->entry->id);
                Struct_ov000_0215ab88* me = func_0200fea4((GameState*)gs, node2->entry->id);
                if (kind != 2) {
                    int work2;
                    func_0208a910(&work2);
                    node2->action = func_0208a91c(&work2, self, (unsigned short)node2->entry->id, &var52, var51.v);
                    Struct_ov000_0215767c* var56 = func_02079e2c((char*)data, (short)node2->action);
                    if (var56 != 0) {
                        while (var56->type == 0x22) {
                            void* e = func_02070fd0((Struct_02070b6c_3*)(self->unknown_8e18_ + 0x684), var56->linked);
                            if (e != 0) {
                                func_0204887c((Struct_0204887c*)me, (char*)e);
                                me->stats->unknown_36_ = var56->linked;
                            }
                            memset(var51.v, -1, sizeof(var51));
                            var52 = 0;
                            node2->action = func_0208a91c(&work2, self, (unsigned short)node2->entry->id, &var52, var51.v);
                            var56 = func_02079e2c((char*)data, (short)node2->action);
                            if (var56 == 0) {
                                break;
                            }
                        }
                    }
                }
                if (node2->action == 0x92 || node2->action == 0x3a1) {
                    Struct_ov000_0215ab88* t = inline_ov000_02153aa4(var51.v[0]);
                    if (t != 0) {
                        t->stats->unknown_2c_ = node2->entry->id;
                    }
                    me->stats->unknown_2a_ = var51.v[0];
                }
            }

            node2->unknown_9_ = 0;
            for (int j = 0; j < var52; j++) {
                Struct_ov000_0215767c_9* var60 = &self->targets[self->unknown_8e81_];
                func_ov000_02157cdc(var60);
                var60->id = var51.v[j];
                var60->active = 1;
                func_ov000_021600cc((Struct_ov000_0215767c_5*)node2, (Struct_ov000_0215767c_4*)var60);
                self->unknown_8e81_++;
            }
            self->unknown_8e7c_++;
            self->unknown_8e80_++;
        }
    }

    func_ov000_0215f110((char*)self);
    func_ov000_0215f1ac(self);

    for (j = 0; j < self->unknown_8e7c_; j++) {
        Struct_ov000_0215767c_10* node = &self->actions[j];
        int id = (short)node->entry->id;
        Struct_ov000_0215ab88* c = inline_ov000_02153aa4(id);
        if (c == 0) {
            continue;
        }
        if (func_02010088((S_10088*)c) != 0) {
            continue;
        }
        if (c->stats->flag2) {
            continue;
        }
        if (func_ov000_02153c0c((GameObject*)c) != 0) {
            continue;
        }
        if (c->stats->unknown_3b_0_) {
            continue;
        }
        int party = (node->entry->id >= 0 && node->entry->id <= 3) ? 1 : 0;
        if (!party) {
            Struct_ov000_0215ab88* m = inline_ov000_0215d63c((short)node->entry->id);
            if (m != 0 && m->busy != 0) {
                continue;
            }
        }

        int var66 = func_ov000_021599dc((GameObject*)c);
        Struct_ov000_0215767c_10* w = func_ov000_0215e9d8(self);
        if (w == 0) {
            break;
        }
        func_ov000_02160030(w);
        func_ov000_0215767c(self, node, w);
        Struct_ov000_0215d63c_3 var68;
        func_ov024_021eb510(&var68);
        func_ov024_021eb510(&var68);
        func_ov024_021eb5d0(&var68, self, w, node, 0);
        if (func_ov000_02155f9c(self, ids.v[j], 1) != 0) {
            var66 = 0;
        }
        func_ov000_02157d3c(self, w, var66);
        self->unknown_8e24_++;
        if (self->unknown_8e14_ != 0) {
            func_ov000_0215bf5c(self, w);
            func_ov000_0215bbbc(self, w);
            func_ov000_0215c2d0(self, w);
            break;
        }

        func_ov000_0215b278(self, w);
        if (var66 == 0) {
            func_ov000_0215bf5c(self, w);
        }
        func_ov000_0215ae80(self);
        func_ov000_0215b5a0(self, w);
        func_ov000_0215ab88(self);
        func_ov000_0215b198(self);
        if (var66 == 0) {
            func_ov000_0215bbbc(self, w);
            func_ov000_0215c2d0(self, w);
        }
        func_ov000_0215c4cc(self);
        if (var66 == 0) {
            continue;
        }

        Struct_ov000_0215767c* var69 = func_02079e2c((char*)func_020797dc(), (short)w->action);
        int var70 = 1;
        if (var69 != 0 && (var69->flags & 0x400) && var69->kind != 0x1c) {
            Struct_ov000_0215767c_10* var71 = &self->actions[0x47];
            Struct_ov000_0215767c_10* w2 = func_ov000_0215e9d8(self);
            if (w2 != 0) {
                func_ov000_02160030(w2);
                func_ov000_02160030(var71);
                w2->action = var71->action = w->action;
                for (int j = 0; j < w->unknown_9_; j++) {
                    Struct_ov000_0215767c_9* src = func_ov000_021600f8((Struct_ov000_0215440c*)w, j);
                    int var75 = src->id;
                    Struct_ov000_0215ab88* t = inline_ov000_02153aa4(var75);
                    if (t == 0) {
                        continue;
                    }
                    if (func_02010088((S_10088*)t) != 0) {
                        continue;
                    }
                    if (func_ov000_02153c0c((GameObject*)t) != 0) {
                        break;
                    }
                    Struct_ov000_0215767c_9* var77 = &self->targets[self->unknown_8e81_];
                    func_ov000_02157cdc(var77);
                    var77->id = src->id;
                    var77->active = 1;
                    func_ov000_021600cc((Struct_ov000_0215767c_5*)var71, (Struct_ov000_0215767c_4*)var77);
                    self->unknown_8e81_++;
                }
                for (int k = 0; k < w->unknown_8_; k++) {
                    ActionEntry* src = func_ov000_02160094((Struct_ov000_0215440c_2*)w, k);
                    int var80 = (short)src->id;
                    Struct_ov000_0215ab88* t = inline_ov000_02153aa4(var80);
                    if (t == 0) {
                        break;
                    }
                    if (func_02010088((S_10088*)t) != 0) {
                        break;
                    }
                    if (func_ov000_02153c0c((GameObject*)t) != 0) {
                        break;
                    }
                    ActionEntry* e = func_ov000_0215e918(self);
                    if (e == 0) {
                        break;
                    }
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->unknown_30_ = 0;
                    e->id = src->id;
                    func_ov000_02160068((Struct_ov000_0215767c_7*)w2, (Struct_ov000_0215767c_6*)e);
                    self->tableCount++;
                    e = &self->entries[self->unknown_8e80_];
                    memset(e, 0, 0x30);
                    e->f1c = -1;
                    e->unknown_30_ = 0;
                    e->id = src->id;
                    func_ov000_02160068((Struct_ov000_0215767c_7*)var71, (Struct_ov000_0215767c_6*)e);
                    self->unknown_8e80_++;
                }
                if (var71->unknown_9_ != 0 && w->unknown_8_ == w2->unknown_8_) {
                    var70 = 0;
                    Struct_ov000_0215d63c_3 var83;
                    func_ov024_021eb510(&var83);
                    func_ov024_021eb510(&var83);
                    func_ov024_021eb5d0(&var83, self, w2, var71, 1);
                    func_ov000_02157d3c(self, w2, 0);
                    self->unknown_8e24_++;
                    if (self->unknown_8e14_ == 0) {
                        func_ov000_0215b278(self, w);
                    }
                    func_ov000_0215bf5c(self, w);
                    if (self->unknown_8e14_ == 0) {
                        func_ov000_0215ae80(self);
                        func_ov000_0215b5a0(self, w2);
                        func_ov000_0215ab88(self);
                        func_ov000_0215b198(self);
                    }
                    func_ov000_0215bbbc(self, w2);
                    func_ov000_0215c2d0(self, w2);
                    if (self->unknown_8e14_ == 0) {
                        func_ov000_0215c4cc(self);
                    }
                }
            }
        }
        if (var70) {
            func_ov000_02157d3c(self, w, 0);
            func_ov000_0215bf5c(self, w);
            func_ov000_0215bbbc(self, w);
            func_ov000_0215c2d0(self, w);
        }
        if (self->unknown_8e14_ != 0) {
            break;
        }
    }

    alloc->Free(self->actions);
    alloc->Free(self->targets);
    alloc->Free(self->entries);
    self->entries = 0;
    self->unknown_8e80_ = 0;
    self->targets = 0;
    self->unknown_8e81_ = 0;
    self->actions = 0;
    self->unknown_8e7c_ = 0;
}
