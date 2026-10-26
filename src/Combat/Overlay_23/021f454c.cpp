#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Util/Random.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int RandomIntBelow(int span);

struct S_10088;
struct Struct_02053dfc;
struct Struct_02070b6c_3;

extern "C" int GameState_GetPartyOrderEntry(void* obj, unsigned int idx);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_02053dfc(struct Struct_02053dfc* obj);
extern "C" int func_02083b00(unsigned char* obj, int index);
extern "C" unsigned short GameObject_GetPartyMemberLevel(void* obj);

struct Struct_ov023_021f454c_7 {
    unsigned short key;
    unsigned char type2;
    unsigned char type3;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

extern "C" struct Struct_ov023_021f454c_7* func_02070fd0(struct Struct_02070b6c_3* container, int key);

#if defined(jpn)
#define data_ov023_021fd888 data_ov023_021fcb3c
#endif
extern int data_ov023_021fd888[];

struct Struct_ov023_021f454c {
#if defined(jpn)
    char pad0[0x144];
#else
    char pad0[0x150];
#endif
    unsigned char* status;
};

struct Struct_ov023_021f454c_2 {
    unsigned short action : 3;
    unsigned short count : 11;
    unsigned short flagA : 1;
    unsigned short unknown_1_7_ : 1;
    unsigned short key;
    unsigned short unknown_4_;
    unsigned char flags;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
};

struct Struct_ov023_021f454c_3 {
    char pad0[0x8d66];
    struct Struct_ov023_021f454c_2 rewards[12];
    char unknown_8dde_[0x8e30 - 0x8dde];
    int unknown_8e30_;
};

struct Struct_ov023_021f454c_4 {
    char pad0[0x24];
    unsigned char f24;
    unsigned char special;
};

struct Struct_ov023_021f454c_5 {
    unsigned short id;
    unsigned short key : 15;
    unsigned short top : 1;
    unsigned char kind;
    signed char member;
};

struct Struct_ov023_021f454c_6 {
#if defined(jpn)
    char pad0[0x218];
#else
    char pad0[0x29c];
#endif
    struct Struct_ov023_021f454c_3* world;
    struct Struct_ov023_021f454c_4* info;
#if defined(jpn)
    char unknown_220_[0x5abc - 0x220];
#else
    char unknown_2a4_[0x58cc - 0x2a4];
#endif
    unsigned short unknown_58cc_;
    char unknown_58ce_[2];
    struct Struct_ov023_021f454c_5 unknown_58d0_[8];
    unsigned char unknown_5900_;
    signed char memberMask;
#if defined(jpn)
    char unknown_5af2_[0x7014 - 0x5af2];
#else
    char unknown_5902_[0x6e24 - 0x5902];
#endif
    int map;
    unsigned short unknown_6e28_;
    unsigned char mapType;
    unsigned char unknown_6e2b_;
    unsigned short unknown_6e2c_;
};

#define IsSpecial(info) ((info)->f24 != 0 || (info)->special != 0)

#if defined(jpn)
enum { regionalOffset0 = 0x240c };
#else
enum { regionalOffset0 = 0x23ec };
#endif

// USA: func_ov023_021f454c
extern "C" ARM void func_ov023_021f454c(struct Struct_ov023_021f454c_6* self) {
    unsigned char buf[4];
    GameState* gs;
    unsigned short var2;
    int count;
    float var4;
    int rate;
    struct Random* rng;
    int j;
    int key;
    struct Struct_ov023_021f454c_2* rewards;
    int var10;
    int var11;
    struct Struct_02070b6c_3* table;
    DetailedTreasureMapData* detail;
    int round;
    int var15;
    struct Struct_ov023_021f454c_2* r;
    struct Struct_ov023_021f454c_5* cur;

    gs = GameState::GetInstance();
    table = (struct Struct_02070b6c_3*)((char*)self->info + 0x684);
    LinkSession_GetInstance();
    detail = ((ActiveGrottoClass*)((char*)Zone3D_GetInstance() + regionalOffset0))->GetDetailedData();
    var2 = 0;
    if (IsSpecial(self->info)) {
        if (detail->mapType_ == 1) {
            var2 = detail->regular_.bossMonsterID_;
        } else if (detail->mapType_ == 2) {
            var2 = detail->legacy_.MaybeGetCurrentAlternateID();
        }
    }

    self->unknown_5900_ = 0;
    self->memberMask = 0;
    count = self->world->unknown_8e30_;
    rewards = self->world->rewards;
    cur = self->unknown_58d0_;
    var4 = (float)self->unknown_58cc_;
    for (round = 0; round < 5; round++) {
        rate = 100;
        if (round > 0) {
            int member = GameState_GetPartyOrderEntry(gs, (unsigned char)(round - 1));
            struct Struct_ov023_021f454c* c = (struct Struct_ov023_021f454c*)func_0200ff1c(gs, member);
            if (c == 0) continue;
            if (!func_020a35e0((unsigned char*)self->info, member)) continue;
            if (func_02010088((struct S_10088*)c)) continue;
            if ((float)(unsigned int)func_02053dfc((struct Struct_02053dfc*)c) / var4 < 0.5f) continue;
            if (!func_02083b00(c->status, 0xa4)) continue;
            rate = GameObject_GetPartyMemberLevel(c);
            cur->member = member;
        } else {
            cur->member = -1;
        }

        if (IsSpecial(self->info)) {
            int i;
            for (i = 0; i < count; i++) {
                if (var2 == rewards[i].key) break;
            }
            struct Struct_ov023_021f454c_2* found = 0;
            if (i < count) found = &rewards[i];
            rng = GetBTRandom();
            for (int k = 2; k >= 0; k--) {
                var15 = detail->treasureDropRates_[k];
                if (round > 0) {
                    int v = var15 * rate / 100;
                    if (detail->treasureDropRates_[k] >= 100) v = 0;
                    var15 = v;
                } else if (found != 0) {
                    if (found->flagA && k == 2) var15 = 100;
                    if (found->unknown_1_7_ && k == 1) var15 = 100;
                }
                if (NextRandomMax(rng, 100) >= var15) continue;
                detail->discoveredTreasures_[k] = 1;
                if (GetTreasureMapTypeFromItemID(detail->treasureItemIDs_[k], buf)) {
                    if (self->map == 0) {
                        self->map = 1;
                        self->unknown_6e28_ = detail->treasureItemIDs_[k];
                        self->mapType = buf[0];
                        self->unknown_6e2b_ = buf[1];
                        self->unknown_6e2c_ = *(unsigned short*)&buf[2];
                    }
                    continue;
                }
                cur->id = detail->treasureItemIDs_[k];
                cur->key = var2;
                struct Struct_ov023_021f454c_7* e = func_02070fd0(table, var2);
                if (e != 0) {
                    if (e->unknown_6_ == cur->id) {
                        cur->kind = 2;
                    } else if (e->unknown_4_ == cur->id) {
                        cur->kind = 1;
                    } else {
                        cur->kind = 0;
                    }
                }
                self->unknown_5900_++;
                if (self->unknown_5900_ >= 8) break;
                signed char m = cur->member;
                cur++;
                cur->member = m;
            }
        }

        if (self->unknown_5900_ >= 8) break;

        for (j = 0; j < count; j++) {
            r = &rewards[j];
            if (r->count == r->unknown_9_) continue;
            key = r->key;
            struct Struct_ov023_021f454c_7* e = func_02070fd0(table, key);
            if (e == 0) continue;
            if (IsSpecial(self->info) && var2 == key) continue;

            var10 = e->type3;
            int chanceA = data_ov023_021fd888[var10];
            if (chanceA > 0) {
                if (round > 0) {
                    int v = chanceA * 100 / rate;
                    if (var10 == 0) v = 0;
                    chanceA = v;
                } else if (r->flagA) {
                    chanceA = 1;
                }
                if (chanceA > 0 && RandomIntBelow(chanceA) == 0) {
                    cur->id = e->unknown_6_;
                    cur->key = key;
                    cur->kind = 2;
                    self->unknown_5900_++;
                    if (self->unknown_5900_ >= 8) break;
                    signed char m = cur->member;
                    cur++;
                    cur->member = m;
                    continue;
                }
            }

            var11 = e->type2;
            int chanceB = data_ov023_021fd888[var11];
            if (chanceB <= 0) continue;
            if (round > 0) {
                int v = chanceB * 100 / rate;
                if (var11 == 0) v = 0;
                chanceB = v;
            } else if (r->unknown_1_7_) {
                chanceB = 1;
            }
            if (chanceB <= 0) continue;
            if (RandomIntBelow(chanceB) != 0) continue;
            cur->id = e->unknown_4_;
            cur->key = key;
            cur->kind = 1;
            self->unknown_5900_++;
            if (self->unknown_5900_ >= 8) break;
            signed char m = cur->member;
            cur++;
            cur->member = m;
        }

        if (self->unknown_5900_ >= 8) break;
    }

    if (self->unknown_5900_ != 0 || self->map != 0) {
        for (int i = 0; i < 4; i++) {
            if (!func_020a35e0((unsigned char*)self->info, i)) continue;
            struct Struct_ov023_021f454c* c = (struct Struct_ov023_021f454c*)func_0200ff1c(gs, i);
            if (c == 0) continue;
            if (!((float)(unsigned int)func_02053dfc((struct Struct_02053dfc*)c) / var4 < 0.5f)) {
                self->memberMask |= 1 << i;
            }
        }
    }
}
