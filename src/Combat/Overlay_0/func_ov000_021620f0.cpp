#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Util/Random.h"

#if defined(jpn)
#define data_ov000_02182ff8 data_ov000_021840b0
#define data_ov000_02182fd4 data_ov000_0218408c
#endif

struct Struct_02070b6c_3;
struct Struct_0206f01c_2;
struct Struct_02048934 {
    unsigned char unknown_0_[0x2c];
    unsigned char payload[1];
};
struct Struct_02048850;
struct Struct_02048850_2;

struct Struct_ov000_021620f0_7 {
    unsigned short field_0;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
    unsigned char unknown_8_[0x1d];
    unsigned char slot;
    unsigned char unknown_26_[0xa4 - 0x26];

    unsigned char inline_ov000_021620f0_2() { return slot; }
};

struct Struct_ov000_021620f0_8 {
    Object3D object;
    unsigned char unknown_ac_[0x134 - 0xac];
    unsigned char* payload;
    Struct_ov000_021620f0_7* stats;
    unsigned char unknown_13c_[0xc];
    Struct_02048934* entry;
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

struct Struct_01ff91ac_8 { unsigned char data[0x70]; };

struct Struct_ov000_021620f0 {
    unsigned char unknown_0_[0x158];
    Struct_ov000_021620f0_7 stats[8];
    unsigned char unknown_678_[0xc];
    unsigned char names[0xc];
};

struct Struct_ov000_021620f0_2 {
    unsigned short kind;
    unsigned char ids[8];
    unsigned char count : 4;
    unsigned char used : 4;
    unsigned char unknown_b_[2];
    unsigned char names[8];
    unsigned char nameCount;
    unsigned char unknown_16_[2];
};

struct Struct_ov000_021620f0_3 {
    unsigned char next;
    unsigned char unknown_1_;
    unsigned short kind;
    unsigned int slots;
};

struct Struct_ov000_021620f0_4 {
    unsigned char total;
    unsigned char unknown_1_0_ : 4;
    unsigned char groupCount : 2;
    unsigned char pairCount : 2;
    unsigned short unknown_2_;
    Struct_ov000_021620f0_2 groups[3];
    Struct_ov000_021620f0_3 pairs[4];
};

struct Struct_ov000_021620f0_5 {
    Random unknown_0_;
    unsigned char unknown_20_[0x81b0 - sizeof(Random)];
    Struct_ov000_021620f0_4 formation;

    Random* inline_ov000_021620f0() { return &unknown_0_; }
};

struct Struct_ov000_021620f0_6 {
#if defined(jpn)
    unsigned char unknown_0_[0x218];
    Struct_ov000_021620f0_5* data;
    Struct_ov000_021620f0* roster;
    unsigned char unknown_220_[0xe44 - 0x220];
    unsigned short unknown_ec8_;
    unsigned char unknown_e46_[0x6014 - 0xe46];
#else
    unsigned char unknown1_0_[0x29c];
    Struct_ov000_021620f0_5* data;
    Struct_ov000_021620f0* roster;
    unsigned char unknown_2a4_[0xec8 - 0x2a4];
    unsigned short unknown_ec8_;
    unsigned char unknown_eca_[0x5e24 - 0xeca];
#endif
    Struct_ov000_021620f0_8 unknown_5e24_[8];
    Struct_01ff91ac_8 models[8];
};

extern "C" void* LinkSession_GetInstance(void);
extern "C" GameObject* func_0200fea4(GameState* gameState, int combatantId);
struct Struct_ov000_02161e30_3;
extern "C" void func_ov000_021620d8(Struct_ov000_02161e30_3*);
extern "C" Struct_02048934* func_02070fd0(Struct_02070b6c_3* table, int key);
extern "C" Struct_02048850_2* func_0206f4f0(Struct_0206f01c_2* table, int key);
extern "C" void func_ov000_02167c28(unsigned char* obj, int id);
extern "C" int func_ov000_02161bb8(unsigned char* obj);
extern "C" void func_020891cc(void* obj);
extern "C" void func_02089630(void* dst, void* src, int arg2);
extern "C" void func_02049c88(void* obj, void* model);
extern "C" void func_0200fd38(GameState* gameState, int id, GameObject* combatant);
extern "C" void func_ov000_02161274(GameObject* obj);
extern "C" void func_02048934(void* p, Struct_02048934* f, Random* r);
extern "C" void func_ov000_02161bec(unsigned char* p);
extern "C" void func_02048614(unsigned char* obj);
extern "C" void func_02048850(Struct_02048850* obj, Struct_02048850_2* param);
extern "C" void func_020488ec(char* obj);
extern "C" void func_02049f3c(unsigned char* obj);

extern const short data_ov000_02182ff8[][3];
extern const signed char data_ov000_02182fd4[][3];

// USA: func_ov000_021620f0
extern "C" ARM void func_ov000_021620f0(Struct_ov000_021620f0_6* scene, int formation) {
    unsigned short kind;
    int id;
    Struct_ov000_021620f0_8* c;
    Struct_ov000_021620f0_4* f = &scene->data->formation;
    GameState* game = GameState::GetInstance();
    LinkSession_GetInstance();
    Struct_02070b6c_3* names = (Struct_02070b6c_3*)scene->roster->names;
    Struct_0206f01c_2* var6 = (Struct_0206f01c_2*)scene->roster->unknown_678_;
    f->total = 0;
    f->unknown_1_0_ = 0;
    f->groupCount = 0;
    f->pairCount = 0;
    f->unknown_2_ = 0;
    for (int i = 0; i < 3; i++) {
        memset(&f->groups[i], 0, sizeof(Struct_ov000_021620f0_2));
    }
    for (int i = 0; i < 4; i++) {
        func_ov000_021620d8((Struct_ov000_02161e30_3*)&f->pairs[i]);
    }
    const short* kinds = data_ov000_02182ff8[formation];
    const signed char* counts = data_ov000_02182fd4[formation];
    int g;
    for (g = 0, id = 0; kinds[g] != -1; g++) {
        Struct_02048934* entry = func_02070fd0(names, kinds[g]);
        Struct_02048850_2* info = func_0206f4f0(var6, kinds[g]);
        if (!entry || !info) return;
        int key = kinds[g];
        kind = key;
        f->groups[g].kind = kind;
        f->pairs[g].kind = kind;
        f->pairs[g].next = 1;
        f->groupCount++;
        f->pairCount++;
        for (int j = 0; j < counts[g]; j++, id++) {
            c = (Struct_ov000_021620f0_8*)func_0200fea4(game, id + 0xc0);
            Struct_ov000_021620f0_7* stats = &scene->roster->stats[id];
            func_020891cc(stats);
            if (!c) {
                func_ov000_02167c28((unsigned char*)scene, id + 0xc0);
                c = &scene->unknown_5e24_[id];
                func_02048614((unsigned char*)c);
                func_02049c88(c, &scene->models[id]);
                func_02089630(stats, entry->payload, 0);
                c->object.SetField06(scene->unknown_ec8_);
                c->stats = stats;
                c->payload = entry->payload;
                c->entry = entry;
                func_02048850((Struct_02048850*)c, info);
                c->object.MakeHidden();
                func_02049f3c((unsigned char*)c);
                func_0200fd38(game, id + 0xc0, (GameObject*)c);
            }
            func_02048934(c, entry, scene->data->inline_ov000_021620f0());
            unsigned short v0 = c->unknown_188_;
            unsigned short v2 = c->unknown_18a_;
            c->stats->field_0 = v0;
            c->stats->unknown_4_ = v0;
            c->stats->unknown_2_ = v2;
            c->stats->unknown_6_ = v2;
            unsigned char slot = func_ov000_02161bb8((unsigned char*)&f->pairs[g]);
            if (slot == 1) {
                slot = 0;
            } else if (slot == 2) {
                func_ov000_02161274((GameObject*)c);
            }
            c->object.unknown_2_ = key;
            c->mode = g;
            c->stats->slot = slot;
            func_020488ec((char*)c);
            c->kind = kind;
            c->group = g;
            c->slot = slot;
            c->active = 1;
            int bit = c->stats->inline_ov000_021620f0_2();
            f->pairs[g].slots |= 1 << bit;
            func_ov000_02161bec((unsigned char*)&f->pairs[g]);
            f->groups[g].ids[j] = id;
            f->groups[g].count++;
            f->groups[g].used++;
            f->total++;
            f->unknown_1_0_++;
        }
    }
}
