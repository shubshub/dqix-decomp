#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#include "Combat/BattleSkillEligibility.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "GameState/GameState.h"
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

struct S_10088;
struct Random;
struct S021719c0;
struct S02171698;

struct Struct_ov024_021f68c8 {
    short f0;
    char f2;
    char f3;
    float f4;
    char pad[4];
};

struct Struct_ov024_021f7478_8 {
    char pad[0x3b];
    unsigned char lo : 3;
    unsigned char unknown_3b_3_ : 1;
};

struct Struct_ov024_021f7478_9 {
    char pad0[0x18];
    unsigned short unknown_18_[6];
    char pad24[0x48];
    unsigned char res[7];
};

struct Struct_ov024_021f7478_10 {
    char pad0[2];
    short unknown_2_;
    short id;
    char pad6[0x12e];
    struct BaseCombatStats* baseStats;
    struct ModifiableCombatStats* currentStats;
#if defined(jpn)
    char unknown_13c_[8];
    unsigned char* f150;
    struct Struct_ov024_021f7478_9* unknown_148_;
    char unknown_14c_[0x30];
#else
    char unknown1_13c_[0xc];
    struct Struct_ov024_021f7478_9* unknown_148_;
    char unknown1_14c_[4];
    unsigned char* f150;
    char unknown_154_[0x28];
#endif
    unsigned char unknown_17c_;
};

struct Struct_ov024_021f7478 {
    int unknown_0_;
    unsigned int id : 12;
    unsigned int pad4 : 20;
    unsigned int lo8 : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int pad8 : 12;
    unsigned int category : 5;
    unsigned int unknown_b_3_ : 1;
    unsigned int unknown_b_4_ : 4;
    int unknown_c_;
    unsigned int flags;
    int unknown_14_;
    unsigned int element : 5;
    unsigned int effect : 7;
    unsigned int pad18 : 20;
};

struct Struct_ov024_021f7478_2 {
    char pad0[8];
    unsigned int lo : 19;
    unsigned int flag : 1;
    unsigned int hi : 12;
    char unknown_c_[0xa];
    unsigned short unknown_16_;
    short uses;
};

struct Struct_ov024_021f7478_3 {
    unsigned char b0;
    unsigned char lo : 4;
    unsigned char groupCount : 2;
    char pad2[4];
    unsigned char ids[8];
    unsigned char memberCount : 4;
    char unknown_f_[9];
};

struct PartyWork_021f7478 {
    char pad[0x25];
    unsigned char f25;
};

struct Battle_021f7478 {
    char pad[0x8e18];
    unsigned char* partyWork;
};

struct Struct_ov024_021f7478_6 {
    unsigned short id;
    signed char slot;
    unsigned char flag;
};

struct Struct_ov024_021f7478_7 {
    char* battle;
    short id;
    unsigned char mode;
    unsigned char unknown_7_;
    struct Struct_ov024_021f7478_10* self;
    int total;
    unsigned char enabled[0x15];
    char unknown_25_[3];
    const unsigned char* table;
    char pad2c[4];
    float unknown_30_;
    char unknown_34_[0x10];
    float unknown_44_[4];
    unsigned char unknown_54_[0x15];
    unsigned char unknown_69_[9];
    char unknown_72_[2];
    int unknown_74_;
    int unknown_78_;
    struct Struct_ov024_021f7478_10* list[8];
    int count;
    unsigned char unknown_a0_[3][8];
    int groupCounts[3];
    int hp[8];
    float ratio[8];
    int unknown_104_[4];
    float unknown_114_[4];
    float unknown_124_;
    int unknown_128_;
    int unknown_12c_;
    int unknown_130_;
    int unknown_134_;
    unsigned char unknown_138_;
    unsigned char unknown_139_;
    char unknown_13a_[2];
    int unknown_13c_[6];
    int unknown_154_[6];
    int unknown_16c_;
    float unknown_170_;
    int unknown_174_;
    struct Struct_ov024_021f7478_6 entries[0x80];
    struct Struct_ov024_021f68c8 first[4];
    struct Struct_ov024_021f68c8 elems[14][4];
    void* unknown_648_;
    void* unknown_64c_;
    int unknown_650_;
    unsigned char unknown_654_;
};

extern "C" void func_ov024_021f68c8(struct Struct_ov024_021f68c8* arr);
extern "C" struct Struct_ov024_021f7478_10* func_ov000_021536f8(int unused, int id);
struct Struct_ov024_021f7478_10* GetCombatantByID(int unused, int id);
extern "C" int func_02010088(struct S_10088* obj);
extern "C" int func_ov024_021e6798(GameObject* obj);
extern "C" float func_ov024_021db358(struct Struct_ov024_021f7478_10* obj);
extern "C" int func_ov000_0215e9fc(int a, short* buf, int max, int start);
extern "C" int func_020a35e0(unsigned char* obj, unsigned char index);
extern "C" void __clear(void* dst, int count);
extern "C" double func_02008f5c(double);
extern "C" int func_02053c6c(unsigned char* obj);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov000_02159cb4(int a, int id);
extern "C" void* func_ov000_02160130(void);
extern "C" void* func_ov000_02160f08(void* obj);
extern "C" void* func_ov024_021f69b4(char* base, int key);
extern "C" int func_ov000_021719c0(struct S021719c0* p);
extern "C" void func_ov000_0217c32c(void* p);
extern "C" int func_ov000_0217c4e8(void* p, int i);
extern "C" struct Struct_ov024_021f7478* func_ov000_0217199c(void* p, int i);
extern "C" int func_ov000_02171698(struct S02171698* p);
extern "C" struct Struct_ov024_021f7478* func_ov000_02171674(void* p, int i);
extern "C" int func_ov000_02171bc0(void* p);
extern "C" struct Struct_ov024_021f7478_2* func_ov000_02171b9c(void* p, int i);
extern "C" struct Struct_ov024_021f7478* func_02079e2c(char* p, int key);
extern "C" int func_02085748(unsigned char* obj);
float NextRandomFloat01(struct Random* rng);
int NextRandomMax(struct Random* rng, int max);
int NextRandomBetween(struct Random* rng, int lo, int hi);
float NextRandomFloatBetween(struct Random* rng, float lo, float hi);

extern unsigned char data_ov024_02200154[];
extern const signed char data_ov024_021fefb0[];
extern const unsigned char data_ov024_021ff084[];
extern const unsigned char data_ov024_021ff0d8[];
extern const unsigned char data_ov024_021ff12c[];
extern const unsigned char data_ov024_021ff180[];

static inline unsigned short inline_ov000_0215cd44(struct Struct_ov024_021f7478_10* c) { return c->currentStats->primaryStats.currHP; }
static inline unsigned short inline_ov024_021dc700(struct Struct_ov024_021f7478_10* c) { return c->currentStats->primaryStats.maxHP; }
static inline unsigned short GetAttack(struct Struct_ov024_021f7478_10* c) { return c->currentStats->primaryStats.attack; }
static inline unsigned short inline_ov024_021d8ad8_3(struct Struct_ov024_021f7478_10* c) { return c->currentStats->primaryStats.defense; }

static inline int inline_02000c9c_8(unsigned short max, unsigned short cur, float weight) {
    return (int)(0.1f * (float)cur + weight * (float)max);
}

static inline float inline_ov024_021f7478(unsigned short attack, unsigned short arg1) {
    return ((float)attack - (float)arg1 / 2.0f) / 2.0f;
}

static inline float inline_ov024_021f7478_2(int attack, unsigned short arg1) {
    return ((float)attack - (float)arg1 / 2.0f) / 2.0f;
}

// USA: func_ov024_021f7478
extern "C" ARM void func_ov024_021f7478(struct Struct_ov024_021f7478_7* obj) {
#if defined(jpn)
 enum { regionalGrottoOffset=0x240c };
#else
 enum { regionalGrottoOffset=0x23ec };
#endif
    int var0[8];
    int var1[8];
    short bufA[4];
    short var3[4];
    unsigned char res[6];
    int i;
    const unsigned char* table;
    unsigned char var7;
    unsigned char scale;

    obj->unknown_170_ = 0.4f;
    obj->unknown_174_ = 0;
    func_ov024_021f68c8(obj->first);
    for (int i = 0; i < 14; i++) {
        func_ov024_021f68c8(obj->elems[i]);
    }

    GameState* gs = GameState::GetInstance();
    obj->self = (struct Struct_ov024_021f7478_10*)(CombatantStruct*)func_0200ff1c(gs, obj->id);
    memset(obj->groupCounts, 0, 0xc);

    int cnt;
    int j;
    struct Struct_ov024_021f7478_3* groups = (struct Struct_ov024_021f7478_3*)(obj->battle + 0x81b0);
    for (i = 0; i < groups->groupCount; i++) {
        cnt = 0;
        for (j = 0; j < groups[i].memberCount; j++) {
            struct Struct_ov024_021f7478_10* c = func_ov000_021536f8((int)obj->battle, (short)(groups[i].ids[j] + 0xc0));
            if (c == 0) continue;
            if (func_02010088((struct S_10088*)c)) continue;
            if (func_ov024_021e6798((GameObject*)c)) continue;
            obj->list[obj->count] = c;
            obj->unknown_a0_[i][cnt] = obj->count;
            obj->hp[obj->count] = c->currentStats->primaryStats.currHP;
            if (obj->mode == 0) {
                if (func_ov024_021db358(c) <= 1.0f) {
                    {
                    unsigned short cur = inline_ov000_0215cd44(c);
                    unsigned short max = inline_ov024_021dc700(c);
                    obj->hp[obj->count] = (int)(0.9f * max + 0.1f * cur);
                    }
                }
            } else {
                if (func_ov024_021db358(c) <= 0.33333f) {
                    unsigned short cur = inline_ov000_0215cd44(c);
                    unsigned short max = inline_ov024_021dc700(c);
                    int v = (int)(0.3f * max + 0.1f * cur);
                    if (v > obj->hp[i]) {
                        obj->hp[obj->count] = v;
                    }
                }
            }
            obj->count++;
            cnt++;
        }
        obj->groupCounts[i] = cnt;
    }

    obj->unknown_74_ = func_ov000_0215e9fc((int)obj->battle, bufA, 4, 0);
    obj->unknown_78_ = func_ov000_0215e9fc((int)obj->battle, var3, 4, 1);

    int var20 = 0;
    obj->unknown_128_ = 0;
    obj->unknown_12c_ = -1;
    obj->unknown_139_ = 0;
    obj->unknown_130_ = 0;
    obj->unknown_134_ = 0;
    for (long i = 0; i < 4; i++) {
        obj->unknown_114_[i] = 1.0f;
        if (!func_020a35e0(((struct Battle_021f7478*)obj->battle)->partyWork, i)) continue;
        struct Struct_ov024_021f7478_10* c = GetCombatantByID((int)obj->battle, (short)i);
        if (c == 0) continue;
        obj->unknown_114_[i] = func_ov024_021db358(c);
        obj->unknown_104_[i] = c->currentStats->primaryStats.currHP;
        if (func_02010088((struct S_10088*)c)) {
            if (obj->unknown_12c_ < 0) obj->unknown_12c_ = i;
            obj->unknown_114_[i] = 1.0f;
            continue;
        }
        if (obj->unknown_114_[i] < obj->unknown_114_[obj->unknown_128_]) obj->unknown_128_ = i;
        if (obj->unknown_114_[i] <= 0.08f) obj->unknown_130_++;
        if (obj->unknown_114_[i] <= 0.25f) obj->unknown_134_++;
        if (var20 < c->currentStats->primaryStats.attack) var20 = c->currentStats->primaryStats.attack;
    }
    if (obj->unknown_134_ >= 2) obj->unknown_139_ = 1;

    struct Struct_ov024_021f7478_10* self = (struct Struct_ov024_021f7478_10*)(CombatantStruct*)func_0200ff1c(gs, obj->id);
    memset(obj->ratio, 0, 0x20);
    for (int i = 0; i < obj->count; i++) {
        float v = inline_ov024_021f7478(GetAttack(self), inline_ov024_021d8ad8_3(obj->list[i]));
        if (v < 1.0f) v = 1.0f;
        obj->ratio[i] = v;
    }

    __clear(var0, 0x20);
    __clear(var1, 0x20);
    for (int i = 0; i < obj->count; i++) {
        float v = inline_ov024_021f7478_2(var20, inline_ov024_021d8ad8_3(obj->list[i]));
        if (v < 1.0f) v = 1.0f;
        var0[i] = (int)v;
        var1[i] = (int)(((float)var0[i] + obj->ratio[i]) / 2.0f);
    }

    int total = 0;
    int count = obj->count;
    for (int i = 0; i < count; i++) {
        total += (int)(float)func_02008f5c((double)((float)obj->hp[i] / (0.5f + 0.9375f * (float)var1[i]))) + 1;
    }
    obj->total = total;

    func_02053c6c((unsigned char*)self);
    obj->unknown_174_ = 0;
    struct Struct_ov024_021f7478_6* entries = obj->entries;
    Zone3D_GetInstance();
    struct Struct_ov024_021f7478_6* e = &entries[obj->unknown_174_];
    e->id = 1;
    e->slot = -1;
    e->flag = 0;
    obj->unknown_174_++;

    if (((struct Struct_ov024_021f7478_8*)self->currentStats)->unknown_3b_3_) {
        int extra = func_ov000_02159cb4((int)obj->battle, self->id);
        if (extra != 0) {
            struct Struct_ov024_021f7478_6* e = &entries[obj->unknown_174_];
            e->id = extra;
            e->slot = -1;
            e->flag = 0;
            obj->unknown_174_++;
        }
    }

    void* work = func_ov024_021f69b4((char*)func_ov000_02160f08(func_ov000_02160130()), obj->id);
    int n = func_ov000_021719c0((struct S021719c0*)work);
    if (n > 0) {
        if (data_ov024_02200154[obj->id] == 0) {
            func_ov000_0217c32c(work);
            data_ov024_02200154[obj->id] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (!func_ov000_0217c4e8(work, i)) continue;
            struct Struct_ov024_021f7478* m = func_ov000_0217199c(work, i);
            if (m == 0) continue;
            if (!m->unknown_b_3_) continue;
            struct Struct_ov024_021f7478_6* e = &entries[obj->unknown_174_];
            e->id = m->id;
            e->slot = -1;
            e->flag = 0;
            obj->unknown_174_++;
            if (obj->unknown_174_ == 0x80) return;
        }
    }

    n = func_ov000_02171698((struct S02171698*)work);
    for (int i = 0; i < n; i++) {
        struct Struct_ov024_021f7478* m = func_ov000_02171674(work, i);
        if (m == 0) continue;
        if (!m->unknown_b_3_) continue;
        struct Struct_ov024_021f7478_6* e = &entries[obj->unknown_174_];
        e->id = m->id;
        e->slot = -1;
        e->flag = 0;
        obj->unknown_174_++;
        if (obj->unknown_174_ == 0x80) return;
    }

    ActionDataTables* var43 = func_020797dc();
    int n3 = func_ov000_02171bc0(work);
    for (int i = 0; i < n3; i++) {
        struct Struct_ov024_021f7478_2* var46 = func_ov000_02171b9c(work, i);
        if (var46 == 0) continue;
        if (var46->uses <= 0) continue;
        unsigned short var47 = var46->unknown_16_;
        if (var47 == 0) continue;
        struct Struct_ov024_021f7478* m = func_02079e2c((char*)var43, (short)var47);
        if (m == 0) continue;
        if (!m->unknown_b_3_) continue;
        unsigned char flag = var46->flag ? 1 : 0;
        struct Struct_ov024_021f7478_6* e = &entries[obj->unknown_174_];
        e->id = var47;
        e->slot = i;
        e->flag = flag;
        obj->unknown_174_++;
        if (obj->unknown_174_ == 0x80) return;
    }

    obj->unknown_654_ = 0;
    const signed char* pair = data_ov024_021fefb0;
    self = (struct Struct_ov024_021f7478_10*)(CombatantStruct*)func_0200ff1c(gs, obj->id);
    if (self != 0) {
        for (; pair[0] != -1; pair += 2) {
            if (pair[1] == func_02085748(self->f150)) {
                obj->unknown_654_ = pair[0];
                break;
            }
        }
    }

    if (obj->unknown_7_ != 0) return;

    memset(obj->unknown_69_, 0, 9);
    for (int i = 1; i <= 5; i++) {
        obj->unknown_154_[i] = 0xff;
        obj->unknown_13c_[i] = 0;
    }

    ActionDataTables* var53 = func_020797dc();
    for (int i = 0; i < obj->count; i++) {
        struct Struct_ov024_021f7478_10* c = obj->list[i];
        int var56 = c->unknown_17c_;
        if (var56 < 0) continue;
        if (var56 >= 3) continue;
        if (c->unknown_148_ == 0) continue;
        struct Struct_ov024_021f7478_9* set = c->unknown_148_;
        for (int j = 0; j < 6; j++) {
            unsigned short var59 = set->unknown_18_[j];
            if (GameState_IsInGrotto(gs) && ((struct PartyWork_021f7478*)((struct Battle_021f7478*)obj->battle)->partyWork)->f25 != 0) {
                char* detail = (char*)((ActiveGrottoClass*)((char*)Zone3D_GetInstance() + regionalGrottoOffset))->GetDetailedData();
                short var61 = c->unknown_2_;
                unsigned short var62 = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
                if (var62 == var61) {
                    if (!((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->CanUseLevelUpMove(var59)) continue;
                }
            }
            struct Struct_ov024_021f7478* m = func_02079e2c((char*)var53, (short)var59);
            if (m == 0) continue;
            if (m->flags & 1) obj->unknown_69_[3] = 1;
            if (m->unknown_9_0_ == 1 || m->unknown_9_0_ == 3) {
                if (m->flags & 0x400) {
                    if (m->effect == 1) obj->unknown_69_[2] = 1;
                }
            }
            if (m->flags & 4) {
                obj->unknown_69_[4] = 1;
                if (m->effect == 1) obj->unknown_69_[5] = 1;
            }
            if (m->category == 1) obj->unknown_69_[6] = 1;
            if (m->category == 2) obj->unknown_69_[7] = 1;
            if (m->effect == 0x11 || m->element == 0x14 || m->effect == 0x23) obj->unknown_69_[8] = 1;
        }
        res[1] = set->res[0];
        res[2] = set->res[1];
        res[3] = set->res[3] > set->res[2] ? set->res[3] : set->res[2];
        res[4] = set->res[5] > set->res[4] ? set->res[5] : set->res[4];
        res[5] = set->res[6];
        for (int j = 1; j <= 5; j++) {
            if (obj->unknown_154_[j] > res[j]) obj->unknown_154_[j] = res[j];
            if (obj->unknown_13c_[j] < res[j]) obj->unknown_13c_[j] = res[j];
        }
    }

    int var65 = 1;
    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(((struct Battle_021f7478*)obj->battle)->partyWork, i)) continue;
        struct Struct_ov024_021f7478_10* c = (struct Struct_ov024_021f7478_10*)(CombatantStruct*)func_0200ff1c(gs, i);
        if (c == 0) continue;
        if (c->baseStats->primaryStats.attack > var65) var65 = c->baseStats->primaryStats.attack;
    }
    for (int i = 0; i < 4; i++) {
        if (!func_020a35e0(((struct Battle_021f7478*)obj->battle)->partyWork, i)) continue;
        struct Struct_ov024_021f7478_10* c = (struct Struct_ov024_021f7478_10*)(CombatantStruct*)func_0200ff1c(gs, i);
        if (c == 0) continue;
        obj->unknown_44_[i] = (float)c->baseStats->primaryStats.attack / (float)var65;
    }

    struct Random* rng = (struct Random*)obj->battle;
    NextRandomFloat01(rng);
    table = data_ov024_021ff084;
    if (obj->mode == 1 || obj->mode == 4) {
        table = data_ov024_021ff0d8;
    } else if (obj->mode == 2) {
        table = data_ov024_021ff12c;
    } else if (obj->mode == 3) {
        table = data_ov024_021ff180;
    }
    obj->table = table;
    for (i = 0; i < 0x15; i++) {
        var7 = table[i * 4];
        scale = table[i * 4 + 1];
        if ((unsigned char)NextRandomMax(rng, 100) < var7) obj->enabled[i] = 1;
        if (total < scale * obj->unknown_78_ / 10) obj->enabled[i] = 0;
    }
    for (int i = 0; i < 0x15; i++) {
        obj->unknown_54_[i] = NextRandomBetween(rng, table[i * 4 + 2], table[i * 4 + 3]);
    }
    obj->unknown_30_ = NextRandomFloatBetween(rng, 0.0f, 0.9f);
}
