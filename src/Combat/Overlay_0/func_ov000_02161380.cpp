#include <globaldefs.h>
#if defined(jpn)
#define LOW_REGION(j,u) (j)
#else
#define LOW_REGION(j,u) (u)
#endif
#include "GameState/GameState.h"

struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
struct S_10088;
struct Struct_02048934;
struct Random;
struct Struct_02048850;
struct Struct_02048850_2;
struct SearchStruct0202c1a4;

extern "C" void* LinkSession_GetInstance(void);
extern "C" GameObject* func_0200fea4(GameState* battleStruct, int combatantId);
extern "C" void __clear(void* buf, int n);
extern "C" unsigned char* func_02070fd0(Struct_02070b6c_3* table, int key);
extern "C" Struct_02048850_2* func_0206f4f0(Struct_0206f01c_2* table, int key);
extern "C" int func_02010088(S_10088* obj);
extern "C" int func_ov000_02161bb8(unsigned char* obj);
extern "C" void func_02048934(void* p, Struct_02048934* f, Random* r);
extern "C" void func_020891cc(void* obj);
extern "C" void func_02089630(void* dst, void* src, int arg2);
extern "C" void func_ov000_02161bec(unsigned char* p);
extern "C" void func_02048614(unsigned char* obj);
extern "C" void func_02049c88(void* obj, void* model);
extern "C" void func_02048850(Struct_02048850* obj, Struct_02048850_2* param);
extern "C" void func_020488ec(char* obj);
extern "C" void func_02049f3c(unsigned char* obj);
extern "C" void func_0200fd38(GameState* battleStruct, int id, GameObject* combatant);
extern "C" int LinkSession_IsActive(int* obj);
extern "C" signed char LinkSession_GetOwnSlot(SearchStruct0202c1a4* obj);

struct Struct_ov000_02161380 {
    unsigned short field_0;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown_8_[0x10];
    unsigned int flags;
    unsigned char unknown_1c_[9];
    unsigned char slot;
    unsigned char unknown_26_[0xa4 - 0x26];
};

struct Struct_ov000_02161380_2 {
    Object3D object;
    unsigned char unknown_ac_[0x134 - 0xac];
    unsigned char* unknown_134_;
    Struct_ov000_02161380* stats;
    unsigned char unknown_13c_[0xc];
    unsigned char* entry;
    unsigned char unknown_14c_[0x30];
    unsigned char mode;
    unsigned char unknown_17d_[7];
    unsigned char active;
    unsigned char unknown_185_;
    unsigned short kind;
    unsigned short unknown_188_;
    unsigned short unknown_18a_;
    unsigned char group;
    unsigned char slot;
    unsigned char unknown_18e_[2];
};

struct Struct_01ff8b48_3 { unsigned char data[0x70]; };

struct Struct_ov000_02161380_3 {
    unsigned char unknown_0_[0x158];
    Struct_ov000_02161380 stats[8];
};

struct Struct_ov000_02161380_4 {
    unsigned short kind;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char used : 4;
    unsigned char unknown_b_[2];
    unsigned char names[8];
    unsigned char nameCount;
    unsigned char unknown_16_[2];
};

struct Struct_ov000_02161380_5 {
    unsigned char next;
    unsigned char unknown_1_;
    unsigned short kind;
    unsigned int slots;
};

struct Struct_ov000_02161380_6 {
    unsigned char unknown_0_0_ : 4;
    unsigned char groupCount : 2;
    unsigned char pairCount : 2;
};

struct Struct_ov000_02161380_7 {
    unsigned char total;
    unsigned char unknown_1_0_ : 4;
    unsigned char groupCount : 2;
    unsigned char pairCount : 2;
    unsigned char unknown_2_[2];
    Struct_ov000_02161380_4 groups[3];
    Struct_ov000_02161380_5 pairs[4];
};

struct Struct_ov000_02161380_8 {
    unsigned char unknown_0_[0x81b0];
    Struct_ov000_02161380_7 formation;
};

struct Struct_ov000_02161380_9 {
    Object3D object;
};

struct Struct_ov000_02161380_10 {
    unsigned char unknown_0_[LOW_REGION(0x218,0x29c)];
    Struct_ov000_02161380_8* data;
    Struct_ov000_02161380_3* roster;
    unsigned char unknown_2a4_[0xc14];
    Struct_ov000_02161380_9* unknown_eb8_[4];
    unsigned short unknown_ec8_;
    unsigned char unknown_eca_[LOW_REGION(0x51ce,0x4f5a)];
    Struct_ov000_02161380_2 unknown_5e24_[8];
    Struct_01ff8b48_3 models[8];
};

// USA: func_ov000_02161380
extern "C" ARM int func_ov000_02161380(Struct_ov000_02161380_10* scene, int kind, int group, int unused) {
    Struct_02070b6c_3* names;
    GameState* game;
    void* search;
    Struct_0206f01c_2* var3;
    int id;
    Struct_02048850_2* info;
    int pass;
    Struct_ov000_02161380* var7;
    int var8;
    unsigned short v0;
    Struct_ov000_02161380* stats;
    int slot;
    unsigned char* entry;
    Struct_ov000_02161380_2* c;
    int start;
    Struct_ov000_02161380_2* var15;
    Struct_ov000_02161380_7* f;
    f = &scene->data->formation;
    int limit = 5;
    if (kind == 0x10a) limit = 8;
    if (limit <= f->unknown_1_0_) return -1;

    Struct_ov000_02161380_9* source = 0;
    for (int i = 0; i < 4; i++) {
        Struct_ov000_02161380_9* candidate = scene->unknown_eb8_[i];
        if (candidate && kind == candidate->object.unknown_2_) {
            source = candidate;
            break;
        }
    }
    if (!source) return -1;

    game = GameState::GetInstance();
    search = LinkSession_GetInstance();
    names = (Struct_02070b6c_3*)((unsigned char*)scene->roster + 0x684);
    var3 = (Struct_0206f01c_2*)((unsigned char*)scene->roster + 0x678);
    id = -1;
    for (int i = 0; i < 8; i++) {
        if (func_0200fea4(game, i + 0xc0) == 0) {
            id = (short)(i + 0xc0);
            break;
        }
    }

    int found = 0;
    int pair = -1;
    if (group < 0) {
        for (int g = 0; g < f->groupCount; g++) {
            if (kind == f->groups[g].kind) {
                group = g;
                found = 1;
                break;
            }
        }
    } else {
        found = 1;
    }

    if (!found) {
        if (f->groupCount >= 3) {
            int g;
            for (g = 0; g < ((Struct_ov000_02161380_6*)((unsigned char*)f + 1))->groupCount; g++) {
                if (f->groups[g].used == 0) {
                    group = g;
                    break;
                }
            }
            if (g >= 3) return -1;
            for (int p = 0; p < f->pairCount; p++) {
                if (kind == f->pairs[p].kind) {
                    pair = p;
                    break;
                }
            }
            if (pair <= -1) {
                unsigned int count = ((Struct_ov000_02161380_6*)((unsigned char*)f + 1))->pairCount;
                if (count >= 4) return -1;
                pair = count;
                f->pairCount = pair + 1;
                memset(&f->pairs[pair], 0, sizeof(Struct_ov000_02161380_5));
                f->pairs[pair].kind = kind;
                f->pairs[pair].next = 1;
            }
            start = 0;
            if (id < 0) {
                id = (short)(f->groups[group].ids[0] + 0xc0);
                start = 1;
            }
            unsigned char buf[8];
            __clear(buf, 8);
            unsigned char n = 0;
            for (; start < f->groups[group].count; start++) {
                buf[n++] = f->groups[group].ids[start];
            }
            memset(&f->groups[group], 0, sizeof(Struct_ov000_02161380_4));
            f->groups[group].kind = kind;
            memcpy(f->groups[group].names, buf, 8);
            f->groups[group].nameCount = n;
        } else {
            group = f->groupCount;
            pair = f->pairCount;
            f->groupCount = group + 1;
            f->pairCount++;
            memset(&f->groups[group], 0, sizeof(Struct_ov000_02161380_4));
            memset(&f->pairs[pair], 0, sizeof(Struct_ov000_02161380_5));
            unsigned short k = kind;
            f->groups[group].kind = k;
            f->pairs[pair].kind = k;
            f->pairs[pair].next = 1;
        }
    } else {
        for (int p = 0; p < f->pairCount; p++) {
            if (f->pairs[p].kind == f->groups[group].kind) {
                pair = p;
                break;
            }
        }
    }

    entry = func_02070fd0(names, kind);
    info = func_0206f4f0(var3, (short)kind);
    if (!entry) return -1;
    if (!info) return -1;

    for (pass = 0; pass < 2; pass++) {
        for (int j = 0; j < f->groups[group].count; j++) {
            c = (Struct_ov000_02161380_2*)func_0200fea4(game, f->groups[group].ids[j] + 0xc0);
            if (!c) continue;
            unsigned char flags[2];
            flags[0] = (c->stats->flags & 0x2000) != 0;
            flags[1] = func_02010088((S_10088*)c);
            if (flags[pass] == 0) continue;
            if (c->active != 0) continue;

            f->groups[group].used++;
            f->unknown_1_0_++;
            var8 = c->stats->slot;
            slot = func_ov000_02161bb8((unsigned char*)&f->pairs[pair]);
            func_02048934(c, (Struct_02048934*)entry, (Random*)scene->data);
            v0 = c->unknown_188_;
            unsigned short v2 = c->unknown_18a_;
            stats = c->stats;
            func_020891cc(stats);
            func_02089630(stats, entry + 0x2c, 0);
            c->stats->field_0 = v0;
            c->stats->unknown_4_ = v0;
            c->stats->unknown_2_ = v2;
            c->stats->unknown_6_ = v2;
            c->kind = kind;
            c->group = group;
            c->slot = slot;
            c->active = 1;
            f->pairs[pair].slots |= 1 << c->slot;
            func_ov000_02161bec((unsigned char*)&f->pairs[pair]);
            f->pairs[pair].slots &= ~(1 << var8);
            return (short)(f->groups[group].ids[j] + 0xc0);
        }
    }

    if (id >= 0xc0) {
        int index = id - 0xc0;
        var7 = &scene->roster->stats[index];
        var15 = &scene->unknown_5e24_[index];
        func_020891cc(var7);
        if (var15) {
            func_02048614((unsigned char*)var15);
            func_02049c88(var15, &scene->models[index]);
            func_02089630(var7, entry + 0x2c, 0);
            var15->object.SetField06(scene->unknown_ec8_);
            var15->stats = var7;
            var15->unknown_134_ = entry + 0x2c;
            var15->entry = entry;
            func_02048850((Struct_02048850*)var15, info);
            func_02048934(var15, (Struct_02048934*)entry, (Random*)scene->data);
            unsigned short v0 = var15->unknown_188_;
            unsigned short v2 = var15->unknown_18a_;
            var15->stats->field_0 = v0;
            var15->stats->unknown_4_ = v0;
            var15->stats->unknown_2_ = v2;
            var15->stats->unknown_6_ = v2;
            unsigned char* slots = (unsigned char*)&f->pairs[pair];
            unsigned char slot = func_ov000_02161bb8(slots);
            if (slot == 1) slot = 0;
            var15->object.unknown_2_ = kind;
            var15->mode = group;
            var15->stats->slot = slot;
            func_020488ec((char*)var15);
            var15->kind = kind;
            var15->group = group;
            var15->slot = slot;
            var15->active = 1;
            var15->object.MakeHidden();
            func_02049f3c((unsigned char*)var15);
            f->pairs[pair].slots |= 1 << var15->slot;
            func_ov000_02161bec(slots);
            func_0200fd38(game, id, (GameObject*)var15);
            f->groups[group].ids[f->groups[group].count] = index;
            f->groups[group].count++;
            f->groups[group].used++;
            f->total++;
            f->unknown_1_0_++;
            if (LinkSession_IsActive((int*)search)) {
                LinkSession_GetOwnSlot((SearchStruct0202c1a4*)search);
            }
            return id;
        }
    }
    return -1;
}
