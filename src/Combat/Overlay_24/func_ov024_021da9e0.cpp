#include <globaldefs.h>
#include "Resource/ActionDataTables.h"
#include "Combat/Overlay_0/GetCombatantByID.h"
#include "GameState/GameState.h"

struct Struct_ov024_021da9e0_3 {
    unsigned char b0 : 1;
    unsigned char b1 : 1;
    unsigned char b2 : 1;
    unsigned char b3 : 1;
    unsigned char unknown_0_4_ : 1;
    unsigned char unknown_0_5_ : 1;
    unsigned char unknown_0_6_ : 1;
    unsigned char unknown_0_7_ : 1;
};

struct Struct_ov024_021da9e0_5 { unsigned int id : 12; unsigned int rest : 20; };
struct Struct_ov024_021da9e0_6 { unsigned int kind : 5; unsigned int rest : 27; };
struct Struct_ov024_021da9e0_7 { unsigned int a : 10; unsigned int b : 10; unsigned int c : 10; unsigned int hi : 2; };

struct Struct_ov024_021da9e0_8 {
    char pad0[4];
    struct Struct_ov024_021da9e0_5 f4;
    char pad8[0x10];
    struct Struct_ov024_021da9e0_6 f18;
    char unknown_1c_[0xc];
    struct Struct_ov024_021da9e0_7 f28;
};

struct Struct_ov024_021da9e0_9 { int f0; struct Struct_ov024_021da9e0_9* next; };

struct Struct_ov024_021da9e0_10 {
    unsigned long long flags;
    struct Struct_ov024_021da9e0_9* unknown_8_;
    char unknown_c_[0xa];
    unsigned short unknown_16_;
    char pad18[7];
    unsigned char unknown_1f_;
    struct Struct_ov024_021da9e0_10* next;
};

struct Struct_ov024_021da9e0 {
    struct Struct_ov024_021da9e0_10* entries[3];
    char unknown_c_[0xc];
    unsigned char counts[3];
    char unknown_1b_;
    struct Struct_ov024_021da9e0_3 f1c;
    struct Struct_ov024_021da9e0_3 unknown_1d_;
    char pad1e[2];
    unsigned short f20;
};

struct Struct_ov024_021da9e0_2 {
    int f0;
    void* list;
    void* f8;
    struct Struct_ov024_021da9e0* fc;
    void* world;
    int count;
    int f18;
    char unknown_1c_[0x2c];
    struct Struct_ov024_021da9e0* slots[8];
    struct Struct_ov024_021da9e0_10* f68;
    char pad6c[2];
    unsigned char unknown_6e_;
    char unknown_6f_;
    unsigned char unknown_70_;
    char unknown_71_[9];
    unsigned char unknown_7a_;
};

extern "C" float func_ov024_021db358(GameObject* c);
extern "C" int func_ov000_0215fc60(char*);
extern "C" int func_ov000_0215ffa0(void* node);
extern "C" void* func_ov000_0215fff4(void* node, int index, int slot);
extern "C" struct Struct_ov024_021da9e0_10* func_ov000_0215e958(void* world);
extern "C" void func_ov000_0215cd44(void* world, void* entry, GameObject* c, int d, unsigned long long e, int g);
extern "C" void func_ov000_0215ffc4(void* node, void* entry, int v);
struct Struct_ov024_021da9e0_4;
extern "C" void func_ov024_021eb4e4(Struct_ov024_021da9e0_4*, int);
extern "C" unsigned long long func_ov024_021e4b14(struct Struct_ov024_021da9e0_2* self, int a, int id, struct Struct_ov024_021da9e0_8* rec, int arg4);
extern "C" int func_ov000_02159f18(void* world, unsigned long long bits, int bit);
struct Struct_ov000_0215440c_2;
extern "C" struct Struct_ov024_021da9e0* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" struct Struct_ov024_021da9e0_8* func_02079e2c(char*, int);
extern "C" short func_ov000_0215a004(void* world, int a, int id, int arg3, void* effects, struct Struct_ov024_021da9e0_8* rec, int flag, int mode);
extern "C" void func_ov000_02159eac(void* world, void* effects, int bit);
extern "C" void func_ov000_0215a88c(void* world, void* entry, int v);
extern "C" int func_ov024_021eb08c(struct Struct_ov024_021da9e0_2* self, int a, int id, int kind);
extern "C" void func_ov000_0215a908(void* world, int id);
extern "C" unsigned short func_ov024_021e9b24(struct Struct_ov024_021da9e0_2* self, int id, struct Struct_ov024_021da9e0_8* rec, int flag);
extern "C" unsigned short func_ov024_021da644(int idx, int a, int b);
extern "C" void func_ov000_0215ccbc(void* world, void* entry, GameObject* c, short a, short b, short d, unsigned long long f, unsigned char h);

static inline int inline_ov024_021da9e0(int id) {
    return id >= 0 && id <= 3;
}

static inline int inline_ov024_021da9e0_2(short id) {
    return id >= 0 && id <= 3;
}

static inline unsigned short inline_ov024_021da9e0_3(GameObject* c) { SDK_NULL_ASSERT(c); return c->currentStats_->primaryStats.currMP; }

// USA: func_ov024_021da9e0
extern "C" ARM struct Struct_ov024_021da9e0_10* func_ov024_021da9e0(struct Struct_ov024_021da9e0_2* obj, short a, int id, struct Struct_ov024_021da9e0_8* rec, int arg4, int* flags, unsigned char cnt) {
    GameObject* c = GetCombatantByID((int)obj->world, id);
    if (!c) return 0;
    float ratio = func_ov024_021db358(c);
    unsigned short code = rec->f4.id;
    if (code == 0x150) arg4 = 0;
    if (func_ov000_0215fc60((char*)obj->world) != 0 && code == 1 && id == 0) {
        GameObject* g = func_0200ff1c(GameState::GetInstance(), 0);
        if (g) {
            if (func_ov000_0215fc60((char*)obj->world) == 1) {
                unsigned short hp = c->currentStats_->primaryStats.currHP;
                arg4 = (int)(0.9f * (float)hp);
                if (hp <= arg4) arg4 = hp - 1;
                if (arg4 <= 0) arg4 = 1;
            } else if (func_ov000_0215fc60((char*)obj->world) == 2) {
                arg4 = g->currentStats_->primaryStats.currHP;
            }
        }
    }
    if (obj->unknown_7a_ != 0 || obj->f18 != 0) {
        int found = 0;
        for (int i = 0; i < 8; i++) {
            struct Struct_ov024_021da9e0* n = obj->slots[i];
            if (!n) continue;
            if (n == obj->fc) {
                obj->slots[i] = 0;
                continue;
            }
            if (n && func_ov000_0215ffa0(n) == id) {
                for (int j = 1; j <= 2; j++) {
                    struct Struct_ov024_021da9e0_10* e = n->entries[j];
                    if (!e) continue;
                    struct Struct_ov024_021da9e0_10** link = &n->entries[j];
                    struct Struct_ov024_021da9e0_10* dst = 0;
                    if (obj->fc->counts[1] != 0)
                        dst = (struct Struct_ov024_021da9e0_10*)func_ov000_0215fff4(obj->fc, obj->fc->counts[1] - 1, 1);
                    while (e) {
                        struct Struct_ov024_021da9e0_9* x = e->unknown_8_;
                        if (x) {
                            if (!dst) {
                                dst = func_ov000_0215e958(obj->world);
                                if (!dst) return 0;
                                func_ov000_0215cd44(obj->world, dst, c, 0, 0, 0);
                                func_ov000_0215ffc4(obj->fc, dst, 1);
                                ((unsigned char*)obj->world)[0x8e02]++;
                            }
                            struct Struct_ov024_021da9e0_9** p = &dst->unknown_8_;
                            while (*p) p = &(*p)->next;
                            *p = x;
                            dst->unknown_1f_ += e->unknown_1f_;
                            e->unknown_8_ = 0;
                            e->unknown_1f_ = 0;
                            if (e->flags == 0 && e->unknown_16_ == 0) {
                                *link = e->next;
                                n->counts[j]--;
                            }
                            link = &e->next;
                        }
                        e = e->next;
                    }
                }
                obj->slots[i] = 0;
                found = 1;
            }
        }
        if (found) func_ov024_021eb4e4((Struct_ov024_021da9e0_4*)obj, (int)obj->fc);
    }
    union { struct { int lo; int hi; }; unsigned long long value; } effects;
    effects.lo = 0;
    effects.hi = 0;
    int apply = 1;
    if (rec->f18.kind == 0x14 && cnt == 0) apply = 0;
    if (apply) effects.value = func_ov024_021e4b14(obj, a, id, rec, arg4);
    if (func_ov000_02159f18(obj->world, effects.value, 0xe) || func_ov000_02159f18(obj->world, effects.value, 0x17))
        obj->unknown_70_ = 0;
    struct Struct_ov024_021da9e0_10* entry = func_ov000_0215e958(obj->world);
    if (!entry) return 0;
    short hp = 0;
    if (!func_ov000_02159f18(obj->world, effects.value, 0xd) && !func_ov000_02159f18(obj->world, effects.value, 0x29)) {
        struct Struct_ov024_021da9e0_8* r = rec;
        if (obj->list) {
            struct Struct_ov024_021da9e0* first = func_ov000_02160094((Struct_ov000_0215440c_2*)obj->list, 0);
            if (first) {
                if (first->f20 != a) r = 0;
                unsigned int k = rec->f4.id;
                if (k == 1 || k == 2 || k == 0xdb || k == 0xdf || k == 0xe0 || obj->fc->unknown_1d_.b0)
                    r = func_02079e2c((char*)func_020797dc(), 1);
            }
        }
        hp = func_ov000_0215a004(obj->world, a, id, arg4, &effects, r, obj->fc->f1c.unknown_0_7_ != 0, 0);
    }
    if (arg4 > 0) obj->count++;
    else func_ov000_02159eac(obj->world, &effects, 4);
    if (func_ov000_02159f18(obj->world, effects.value, 2) || func_ov000_02159f18(obj->world, effects.value, 0xd)) {
        *flags |= 2;
        obj->fc->entries[1] = 0;
        obj->fc->counts[1] = 0;
        obj->fc->entries[2] = 0;
        obj->fc->counts[2] = 0;
        if (obj->list && func_ov000_02159f18(obj->world, effects.value, 2) && rec->f4.id != 0x61) {
            if (inline_ov024_021da9e0(id))
                func_ov000_0215a88c(obj->world, entry, (unsigned short)rec->f28.a);
            obj->f68 = entry;
        }
    } else if (!func_ov000_02159f18(obj->world, effects.value, 0x29)) {
        if (!inline_ov024_021da9e0(id) && inline_ov024_021da9e0_2(a) && arg4 > 0) {
            int ok = 0;
            float now = func_ov024_021db358(c);
            if (ratio >= 0.25f && now < 0.25f) {
                if (func_ov024_021eb08c(obj, a, id, 4)) ok = 1;
            } else if (ratio >= 0.5f && now < 0.5f) {
                if (func_ov024_021eb08c(obj, a, id, 3)) ok = 1;
            }
            if (ok) func_ov000_0215a908(obj->world, id);
        }
    }
    if (rec->f4.id == 0x61) {
        if (obj->f18 > 0) func_ov000_0215a88c(obj->world, entry, 0x1f0);
        unsigned short sel;
        if (arg4 > 0) {
            sel = func_ov024_021e9b24(obj, id, rec, 0);
        } else {
            struct Struct_ov024_021da9e0* fc = obj->fc;
            if (fc && (fc->f1c.b1 || fc->f1c.b2 || fc->f1c.b3 || fc->f1c.unknown_0_4_ || fc->f1c.unknown_0_5_ || fc->f1c.unknown_0_6_))
                sel = 0;
            else
#if defined(jpn)
                sel = 0x1b;
#else
                sel = func_ov024_021da644(id, 0x26d, 0x1b);
#endif
        }
        if (sel) func_ov000_0215a88c(obj->world, entry, sel);
        if (obj->list && func_ov000_02159f18(obj->world, effects.value, 2)) {
            if (inline_ov024_021da9e0(id))
                func_ov000_0215a88c(obj->world, entry, (unsigned short)rec->f28.a);
            else
                func_ov000_0215a88c(obj->world, entry, (unsigned short)rec->f28.b);
            *flags |= 2;
            obj->fc->entries[1] = 0;
            obj->fc->counts[1] = 0;
            obj->fc->entries[2] = 0;
            obj->fc->counts[2] = 0;
        }
    }
    if (func_ov000_02159f18(obj->world, effects.value, 0xd)) {
        arg4 = 0;
        hp = 0;
        if (inline_ov024_021da9e0(id))
            func_ov000_0215a88c(obj->world, entry, 8);
        else
            func_ov000_0215a88c(obj->world, entry, 0x45);
        obj->unknown_6e_ = 1;
    } else if (func_ov000_02159f18(obj->world, effects.value, 0x29)) {
        arg4 = 0;
        hp = 1;
        func_ov000_0215a88c(obj->world, entry, 0xc8);
        obj->unknown_6e_ = 1;
    }
    func_ov000_0215ccbc(obj->world, entry, c, arg4, hp, inline_ov024_021da9e0_3(c), effects.value, obj->fc->f1c.unknown_0_7_ != 0);
    return entry;
}
