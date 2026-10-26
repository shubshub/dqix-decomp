#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Memory/SafeAllocator.h"
#include "Combat/Main/BattleList.h"
#include "std_library_functions.h"

#if defined(jpn)
enum { Enum_ov025_021e0638_668 = 0x218, Enum_ov025_021e0638_21976 = 0x57c8, Enum_ov025_021e0638_396 = 0x180, Enum_ov025_021e0638_3704 = 0xdf4 };
#else
enum { Enum_ov025_021e0638_668 = 0x29c, Enum_ov025_021e0638_21976 = 0x55d8, Enum_ov025_021e0638_396 = 0x18c, Enum_ov025_021e0638_3704 = 0xe78 };
#endif

struct BattleStruct {
    int unk0;
    int unk4;
    struct CombatantStruct* combatantList[0xe9];
};
struct CombatantStruct {
    unsigned short flags;
    char unk[0x132];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
};

struct Struct_02048c90;
struct Struct_02049410;
struct Struct_02048f64;
struct Struct_02048f64_2;
struct Struct_ov000_0215440c_2;
struct Struct_ov000_0215440c;

struct Struct_ov025_021e0638_11 {
    unsigned char id;
    unsigned char val;
    char pad[6];
    unsigned char* obj;
};

struct Struct_ov025_021e0638_12 {
    unsigned char data[12];
    Struct_ov025_021e0638_12* next;
};

struct Struct_ov025_021e0638 {
    unsigned char seq[16];
    unsigned char unknown_10_[16];
    unsigned char len;
};

struct Struct_ov025_021e0638_2 {
    void* data;
    int count;
    unsigned char buf[12];
    unsigned char len;
};

struct Struct_ov025_021e0638_3 {
    unsigned char b[6];
};

struct Struct_ov025_021e0638_4 { int x; int y; int z; };
struct Struct_ov025_021e0638_5 { int v[2]; };

struct Struct_ov025_021e0638_6 {
    char pad0[8];
    unsigned char unknown_8_;
    unsigned char unknown_9_;
    char pad1[6];
    unsigned char* p10;
    unsigned char* unknown_14_;
    char pad2[0x10];
};

struct Struct_ov025_021e0638_7 {
    char pad[0x8000];
    Struct_ov025_021e0638_6 lists[77];
};

struct Struct_ov025_021e0638_8 {
    char pad[0x21c];
    Struct_ov025_021e0638_7 sub;
    int count;
};

static inline Struct_ov025_021e0638_7* inline_ov025_021e0638(Struct_ov025_021e0638_8* world) { return &world->sub; }
static inline Struct_ov025_021e0638_6* inline_ov025_021e0638_2(Struct_ov025_021e0638_7* sub) { return sub->lists; }

struct Struct_ov025_021e0638_9 {
    char pad[0x10];
    unsigned int flags;
};

struct Struct_ov025_021e0638_10 {
    Struct_ov025_021e0638_4 a;
    Struct_ov025_021e0638_4 b;
    int radius;
    unsigned char flag;
};

extern "C" int func_ov025_021e1048(void* world, void* out);
extern "C" void func_ov025_021e20ec(void* tbl, SafeAllocator* alloc);
extern "C" int func_ov025_021e2148(void* tbl, int a, int b, void* out, int n);
extern "C" void func_ov025_021e120c(void* buf, int id, int a, int b, int c);
extern "C" void HaltSystem(void);
extern "C" void func_ov000_0216f82c(Struct_ov025_021e0638_3* out, const int* cell);
extern "C" void func_ov000_0216f74c(Struct_ov025_021e0638_5* out, const int* cell);
struct Vector3i;
extern "C" void __clear(void* p, int n);

extern "C" void func_ov025_021e20d8(void* obj);
extern "C" void func_02048c90(Struct_02048c90*);
extern "C" int func_020493a4(unsigned char*);
extern "C" int func_020493c8(unsigned char*);
extern "C" int func_02049444(unsigned char*);
extern "C" int func_02049ee8(unsigned char*);
extern "C" void func_ov025_021e2114(unsigned char*, void*, int);
extern "C" void func_02049410(Struct_02049410*, void*, int);
extern "C" void func_02049a74(Struct_02048f64*);
extern "C" void func_02049ae4(unsigned char*);
extern "C" void func_0204950c(unsigned char*);
extern "C" void func_020494f8(unsigned char*);
extern "C" void func_02048994(void);
extern "C" Struct_ov025_021e0638_10* func_020489b0(void);
extern "C" int func_02049ec0(unsigned char*);
extern "C" int func_02048c10(unsigned char*);
extern "C" void func_020494c0(Struct_02048f64_2*);
extern "C" unsigned char* func_ov000_02160094(Struct_ov000_0215440c_2*, int);
extern "C" unsigned char* func_ov000_021600f8(Struct_ov000_0215440c*, int);

static inline Struct_ov025_021e0638_12* inline_01ff8b48_2(Struct_ov025_021e0638_12* head, int idx) {
    if (idx == 0) {
        return head;
    }
    Struct_ov025_021e0638_12* p = head->next;
    for (int x = 0; x < idx - 1; x++) {
        if (p == 0) {
            return 0;
        }
        p = p->next;
    }
    return p;
}

// USA: func_ov025_021e0638
extern "C" ARM void func_ov025_021e0638(unsigned char* self) {
    int n;
    Struct_ov025_021e0638_12* tail;
    GameState* gs = GameState::GetInstance();
    Struct_ov025_021e0638_8* world = *(Struct_ov025_021e0638_8**)(self + Enum_ov025_021e0638_668);
    Struct_ov025_021e0638_6* cur = &world->sub.lists[*(int*)(self + Enum_ov025_021e0638_21976)];
    Struct_ov025_021e0638_11 ents[12];
    int ids[60];
    unsigned char seen[0x51];
    Struct_ov025_021e0638_12 head;
    Struct_ov025_021e0638_2 tbl;
    unsigned char tmp[12];
    unsigned char out[16];
    unsigned char var12[32];
    unsigned char var13[6];
    Struct_ov025_021e0638_5 var14;
    Struct_ov025_021e0638_5 pos;
    int var16;
    int var17;
    Struct_ov025_021e0638_3 var18;
    int var19;
    Struct_ov025_021e0638_3 var20;
    Struct_ov025_021e0638_3 s2;
    Struct_ov025_021e0638_3 s1;
    SafeAllocator* alloc = (SafeAllocator*)(self + 0x30);

    alloc->Reset();
    n = func_ov025_021e1048(world, ents);
    head.next = 0;
    Struct_ov025_021e0638* pool = (Struct_ov025_021e0638*)alloc->Allocate(n * 33);
    if (pool == 0) {
        return;
    }
    for (int i = 0; i < n; i++) {
        func_02048c90((Struct_02048c90*)ents[i].obj);
        head.data[i] = func_020493a4(ents[i].obj);
        pool[i].len = 0;
        memset(pool[i].unknown_10_, 0, 0x10);
    }
    func_ov025_021e20d8(&tbl);
    func_ov025_021e20ec(&tbl, alloc);
    int i;
    int changed;
    int nodes;
    int var29;
    nodes = 0;
    var29 = 0;
    changed = 1;
    tail = &head;
    for (i = *(int*)(self + Enum_ov025_021e0638_21976); i < world->count; i++) {
        unsigned char* o = inline_ov025_021e0638_2(inline_ov025_021e0638(world))[i].p10;
        if (o != 0) {
            ids[var29++] = *(unsigned short*)(o + 0x20);
        }
    }
    Struct_ov025_021e0638_7* lists = &world->sub;
    for (int j = 0; j < *(int*)(self + Enum_ov025_021e0638_21976); j++) {
        Struct_ov025_021e0638_6* e = &lists->lists[j];
        if (e->p10 != 0) {
            ids[var29++] = *(unsigned short*)(e->p10 + 0x20);
        }
    }
    while (changed) {
        changed = 0;
        for (int i = 0; i < var29; i++) {
            int id = ids[i];
            int k;
            for (k = 0; k < n; k++) {
                if (id == ents[k].id) {
                    goto found;
                }
            }
            k = -1;
found:
            if (k < 0 || n <= k) {
                continue;
            }
            unsigned char* obj = ents[k].obj;
            int target;
            int off = k * 33;
            unsigned char* entry = (unsigned char*)pool + off;
            unsigned char len = (&pool->len)[off];
            if (len >= 0x10) {
                continue;
            }
            int prev;
            if (len != 0) {
                prev = entry[len - 1];
            } else {
                prev = func_020493a4(obj);
            }
            target = func_020493c8(obj);
            if (prev == target) {
                continue;
            }
            unsigned char m = 0;
            for (int j = 0; j < n; j++) {
                unsigned char b = tail->data[j];
                if (target != b) {
                    tmp[m++] = b;
                }
            }
            func_ov025_021e2114((unsigned char*)&tbl, tmp, m);
            __clear(out, 0x10);
            unsigned char cnt = func_ov025_021e2148(&tbl, prev, target, out, 0x10);
            if (cnt < 2) {
                continue;
            }
            if (len == 0) {
                entry[len++] = tail->data[k];
            }
            if (len >= 0x10) {
                HaltSystem();
            }
            unsigned char v = out[cnt - 2];
            unsigned char var48 = len + 1;
            entry[len] = v;
            (&pool->len)[off] = var48;
            tail->data[k] = v;
            if (var48 > 2 && nodes > 0) {
                unsigned char c;
                unsigned char a = entry[var48 - 1];
                unsigned char var51 = entry[var48 - 3];
                int y;
                int x;
                int m2;
                unsigned char u;
                unsigned char cc;
                int flag;
                int var58;
                int x2;
                int y2;
                Struct_ov025_021e0638_12* p;
                var19 = var51;
                func_ov000_0216f82c(&var20, &var19);
                s1 = var20;
                var17 = a;
                func_ov000_0216f82c(&var18, &var17);
                s2 = var18;
                m2 = 0;
                for (x = 0; x < 6; x++) {
                    u = s1.b[x];
                    if (u == 0xff) {
                        continue;
                    }
                    for (y = 0; y < 6; y++) {
                        unsigned char w = s2.b[y];
                        if (w == 0xff) {
                            continue;
                        }
                        if (u == w) {
                            var13[m2] = u;
                            m2++;
                        }
                    }
                }
                cc = m2;
                if (nodes - 1 == 0) {
                    p = &head;
                } else {
                    p = head.next;
                    for (var58 = 0; var58 < nodes - 2; var58++) {
                        if (p == 0) {
                            p = 0;
                            break;
                        }
                        p = p->next;
                    }
                }
                flag = 0;
                for (x2 = 0; x2 < cc; x2++) {
                    flag = 1;
                    y2 = 0;
                    c = var13[x2];
                    for (; y2 < n; y2++) {
                        if (y2 == i) {
                            continue;
                        }
                        if (c == p->data[y2]) {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 0) {
                        break;
                    }
                }
                if (flag != 0) {
                    unsigned char* mp = (unsigned char*)((unsigned int)pool + off);
                    mp += var48 - 2;
                    mp[0x10] = 1;
                }
            }
            changed = 1;
        }
        Struct_ov025_021e0638_12* node = (Struct_ov025_021e0638_12*)alloc->Allocate(0x10);
        if (node == 0) {
            break;
        }
        memcpy(node, tail, 0x10);
        node->next = 0;
        Struct_ov025_021e0638_12* t = tail->next;
        if (t == 0) {
            tail->next = node;
        } else {
            while (t->next != 0) {
                t = t->next;
            }
            t->next = node;
        }
        nodes++;
        tail = node;
    }
    for (int i = 0; i < n; i++) {
        unsigned char m = 0;
        for (int j = 0; j < pool[i].len; j++) {
            if (pool[i].unknown_10_[j] == 0) {
                var12[m++] = pool[i].seq[j];
            }
        }
        func_02049410((Struct_02049410*)ents[i].obj, var12, m);
    }
    for (int i = 0; i < n; i++) {
        int flag = 0;
        unsigned char* c = (unsigned char*)(CombatantStruct*)func_0200ff1c(gs, *(short*)(ents[i].obj + 4));
        if (c != 0 && (*(unsigned int*)(c + Enum_ov025_021e0638_396) & 1)) {
            flag = 1;
        }
        if (func_02049ee8(ents[i].obj) != 0 && flag == 0 && self[Enum_ov025_021e0638_3704] != 0) {
            func_02049a74((Struct_02048f64*)ents[i].obj);
        } else {
            func_02049ae4(ents[i].obj);
        }
        func_0204950c(ents[i].obj);
    }
    for (int i = 0; i < var29; i++) {
        unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(ids[i]);
        if (c != 0 && func_02049444(c) != 0) {
            func_02049ae4(c);
            func_020494f8(c);
        }
    }
    for (int i = 0; i < cur->unknown_8_; i++) {
        if (cur->p10 != 0) {
            unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(*(unsigned short*)(cur->p10 + i * 0x34 + 0x20));
            if (c != 0) {
                func_02049ae4(c);
                func_0204950c(c);
            }
        }
    }
    for (int i = 0; i < cur->unknown_9_; i++) {
        if (cur->unknown_14_ != 0) {
            unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(*(short*)(cur->unknown_14_ + i * 0x24 + 0xe));
            if (c != 0) {
                func_02049ae4(c);
                func_0204950c(c);
            }
        }
    }
    for (int i = 0; i < cur->unknown_9_; i++) {
        if (cur->unknown_14_ != 0) {
            unsigned char* c = (unsigned char*)gs->GetCombatantByIndex(*(short*)(cur->unknown_14_ + i * 0x24 + 0xe));
            if (c != 0) {
                memset(seen, 0, 0x51);
                Struct_ov025_021e0638_9* sub = 0;
                int extra = 1;
                if (*(unsigned short*)c & 0x400) {
                    sub = *(Struct_ov025_021e0638_9**)(c + 0x148);
                }
                if (sub != 0) {
                    unsigned int t2 = (sub->flags << 1) >> 0x1e;
                    if (t2 != 0) {
                        extra += t2;
                    }
                }
                func_ov025_021e120c(seen, func_020493a4(c), 1, extra & 0xff, 0);
                for (int j = 0; j < n; j++) {
                    int id = func_020493c8(ents[j].obj);
                    if (id < 0x51 && seen[id] == 1) {
                        func_02049ae4(c);
                        func_0204950c(c);
                    }
                }
            }
        }
    }
    func_02048994();
    unsigned char* var85 = func_ov000_02160094((Struct_ov000_0215440c_2*)cur, 0);
    unsigned char* nb = func_ov000_021600f8((Struct_ov000_0215440c*)cur, 0);
    if (var85 != 0 && nb != 0) {
        unsigned char* var87 = (unsigned char*)gs->GetCombatantByIndex(*(unsigned short*)(var85 + 0x20));
        unsigned char* cb = (unsigned char*)gs->GetCombatantByIndex(*(short*)(nb + 0xe));
        if (var87 != 0 && cb != 0) {
            unsigned int id = func_020493c8(var87);
            if (id >= 0x51) {
                id = func_020493a4(var87);
            }
            if (id < 0x51) {
                var16 = id;
                func_ov000_0216f74c(&pos, &var16);
                var14 = pos;
                Struct_ov025_021e0638_4 var90;
                __clear(&var90, 0xc);
                var90.x = var14.v[0];
                var90.z = var14.v[1];
                Struct_ov025_021e0638_4 var91 = *(Struct_ov025_021e0638_4*)(cb + 0x44);
                var91.y = 0;
                Struct_ov025_021e0638_10* d = func_020489b0();
                *(Vector3i*)&d->a = *(Vector3i const*)&var90;
                *(Vector3i*)&d->b = *(Vector3i const*)&var91;
                d->radius = ((Object3D*)var87)->GetRadius() >> 1;
                d->flag = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        unsigned char* o = ents[i].obj;
        if (func_02049ee8(o) != 0 && func_02049444(o) == 0 && func_02049ec0(o) != 0
            && (*(unsigned int*)(*(unsigned char**)(o + 0x138) + 0x14) & 1) == 0 && self[Enum_ov025_021e0638_3704] != 0
            && func_02048c10(o) == 0) {
            func_020494c0((Struct_02048f64_2*)o);
        }
    }
}
