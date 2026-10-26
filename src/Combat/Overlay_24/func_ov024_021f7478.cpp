#include <globaldefs.h>
#include "Resource/ActionDataTables.h"

#include "Combat/BattleSkillEligibility.h"
#include "std_library_functions.h"
#include "Combat/Main/BattleList.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "GameState/GameState.h"
struct Struct_0203d028_2 {
    int unknown_0_;
    int unknown_4_;
    struct Struct_0203d028_3* unknown_8_[0xe9];
};
struct Struct_0203d028_3 {
    unsigned short unknown_0_;
    char unknown_2_[0x132];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
};

struct Struct_02010088;
struct Random;
struct Struct_ov000_02171968;
struct Struct_ov000_02171640;

struct Struct_ov024_021f68c8 {
    short unknown_0_;
    char unknown_2_;
    char unknown_3_;
    float unknown_4_;
    char unknown_8_[4];
};

struct Struct_ov024_021f7478_8 {
    char unknown_0_[0x3b];
    unsigned char unknown_3b_0_ : 3;
    unsigned char unknown_3b_3_ : 1;
};

struct Struct_ov024_021f7478_9 {
    char unknown_0_[0x18];
    unsigned short unknown_18_[6];
    char unknown_24_[0x48];
    unsigned char unknown_6c_[7];
};

struct Struct_ov024_021f7478_10 {
    char unknown_0_[2];
    short unknown_2_;
    short unknown_4_;
    char unknown_6_[0x12e];
    struct BaseCombatStats* unknown_134_;
    struct ModifiableCombatStats* unknown_138_;
#if defined(jpn)
    char unknown_13c_[8];
    unsigned char* unknown_150_;
    struct Struct_ov024_021f7478_9* unknown_148_;
    char unknown_14c_[0x30];
#else
    char unknown1_13c_[0xc];
    struct Struct_ov024_021f7478_9* unknown_148_;
    char unknown1_14c_[4];
    unsigned char* unknown_150_;
    char unknown_154_[0x28];
#endif
    unsigned char unknown_17c_;
};

struct Struct_ov024_021f7478 {
    int unknown_0_;
    unsigned int unknown_4_0_ : 12;
    unsigned int unknown_5_4_ : 20;
    unsigned int unknown_8_0_ : 8;
    unsigned int unknown_9_0_ : 2;
    unsigned int unknown_9_2_ : 12;
    unsigned int unknown_a_6_ : 5;
    unsigned int unknown_b_3_ : 1;
    unsigned int unknown_b_4_ : 4;
    int unknown_c_;
    unsigned int unknown_10_;
    int unknown_14_;
    unsigned int unknown_18_0_ : 5;
    unsigned int unknown_18_5_ : 7;
    unsigned int unknown_19_4_ : 20;
};

struct Struct_ov024_021f7478_2 {
    char unknown_0_[8];
    unsigned int unknown_8_0_ : 19;
    unsigned int unknown_a_3_ : 1;
    unsigned int unknown_a_4_ : 12;
    char unknown_c_[0xa];
    unsigned short unknown_16_;
    short unknown_18_;
};

struct Struct_ov024_021f7478_3 {
    unsigned char unknown_0_;
    unsigned char unknown_1_0_ : 4;
    unsigned char unknown_1_4_ : 2;
    char unknown_2_[4];
    unsigned char unknown_6_[8];
    unsigned char unknown_e_0_ : 4;
    char unknown_f_[9];
};

struct Struct_ov024_021f7478_4 {
    char unknown_0_[0x25];
    unsigned char unknown_25_;
};

struct Struct_ov024_021f7478_5 {
    char unknown_0_[0x8e18];
    unsigned char* unknown_8e18_;
};

struct Struct_ov024_021f7478_6 {
    unsigned short unknown_0_;
    signed char unknown_2_;
    unsigned char unknown_3_;
};

struct Struct_ov024_021f7478_7 {
    char* unknown_0_;
    short unknown_4_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    struct Struct_ov024_021f7478_10* unknown_8_;
    int unknown_c_;
    unsigned char unknown_10_[0x15];
    char unknown_25_[3];
    const unsigned char* unknown_28_;
    char unknown_2c_[4];
    float unknown_30_;
    char unknown_34_[0x10];
    float unknown_44_[4];
    unsigned char unknown_54_[0x15];
    unsigned char unknown_69_[9];
    char unknown_72_[2];
    int unknown_74_;
    int unknown_78_;
    struct Struct_ov024_021f7478_10* unknown_7c_[8];
    int unknown_9c_;
    unsigned char unknown_a0_[3][8];
    int unknown_b8_[3];
    int unknown_c4_[8];
    float unknown_e4_[8];
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
    struct Struct_ov024_021f7478_6 unknown_178_[0x80];
    struct Struct_ov024_021f68c8 unknown_378_[4];
    struct Struct_ov024_021f68c8 unknown_3a8_[14][4];
    void* unknown_648_;
    void* unknown_64c_;
    int unknown_650_;
    unsigned char unknown_654_;
};

extern "C" void func_ov024_021f68c8(struct Struct_ov024_021f68c8* arg0);
extern "C" struct Struct_ov024_021f7478_10* func_ov000_021536f8(int arg0, int arg1);
struct Struct_ov024_021f7478_10* GetCombatantByID(int unused, int id);
extern "C" int func_02010088(struct Struct_02010088* arg0);
extern "C" int func_ov024_021e6798(GameObject* arg0);
extern "C" float func_ov024_021db358(struct Struct_ov024_021f7478_10* arg0);
extern "C" int func_ov000_0215e9fc(int arg0, short* arg1, int arg2, int arg3);
extern "C" int func_020a35e0(unsigned char* arg0, unsigned char arg1);
extern "C" void __clear(void* arg0, int arg1);
extern "C" double func_02008f5c(double);
int GetFieldAt0x150_02053c6c(unsigned char* obj);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int func_ov000_02159cb4(int a, int id);
void* GetActiveCombatWork_ov000_02160130(void);
void* GetOffsetPtr02160f08(void* obj);
void* FindByKeyIndexed_021f69b4(char* base, int key);
int CountNonZero021719c0(struct S021719c0* p);
extern "C" void func_ov000_0217c32c(void* p);
int IsBitFlagSet0217c4e8(void* p, int i);
struct MoveData_021f7478* GetBoundedField420_0217199c(void* p, int i);
int CountNonZero02171698(struct S02171698* p);
struct MoveData_021f7478* GetBoundedField156_02171674(void* p, int i);
extern "C" int func_ov000_02171bc0(void* p);
struct LearnedMove_021f7478* GetPointerField_02171b9c_02171b9c(void* p, int i);
struct MoveData_021f7478* SearchBothTables02079e2c(char* p, int key);
int GetBits23To25At0x2f4_02085748(unsigned char* obj);
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

static inline unsigned short inline_ov000_0215cd44(struct Struct_ov024_021f7478_10* arg0) { return arg0->unknown_138_->primaryStats.currHP; }
static inline unsigned short inline_ov024_021dc700(struct Struct_ov024_021f7478_10* arg0) { return arg0->unknown_138_->primaryStats.maxHP; }
static inline unsigned short inline_ov024_021d8ad8_2(struct Struct_ov024_021f7478_10* arg0) { return arg0->unknown_138_->primaryStats.attack; }
static inline unsigned short inline_ov024_021d8ad8_3(struct Struct_ov024_021f7478_10* arg0) { return arg0->unknown_138_->primaryStats.defense; }

static inline int inline_02000c9c_8(unsigned short arg0, unsigned short arg1, float arg2) {
    return (int)(0.1f * (float)arg1 + arg2 * (float)arg0);
}

static inline float inline_ov024_021f7478(unsigned short arg0, unsigned short arg1) {
    return ((float)arg0 - (float)arg1 / 2.0f) / 2.0f;
}

static inline float inline_ov024_021f7478_2(int arg0, unsigned short arg1) {
    return ((float)arg0 - (float)arg1 / 2.0f) / 2.0f;
}

// USA: func_ov024_021f7478
extern "C" ARM void func_ov024_021f7478(struct Struct_ov024_021f7478_7* arg0) {
#if defined(jpn)
 enum { Enum_ov024_021f7478_9196=0x240c };
#else
 enum { Enum_ov024_021f7478_9196=0x23ec };
#endif
    int var0[8];
    int var1[8];
    short var2[4];
    short var3[4];
    unsigned char var4[6];
    int var5;
    const unsigned char* var6;
    unsigned char var7;
    unsigned char var8;

    arg0->unknown_170_ = 0.4f;
    arg0->unknown_174_ = 0;
    func_ov024_021f68c8(arg0->unknown_378_);
    for (int var9 = 0; var9 < 14; var9++) {
        func_ov024_021f68c8(arg0->unknown_3a8_[var9]);
    }

    GameState* var10 = GameState::GetInstance();
    arg0->unknown_8_ = (struct Struct_ov024_021f7478_10*)(Struct_0203d028_3*)func_0200ff1c(var10, arg0->unknown_4_);
    memset(arg0->unknown_b8_, 0, 0xc);

    int var11;
    int var12;
    struct Struct_ov024_021f7478_3* var13 = (struct Struct_ov024_021f7478_3*)(arg0->unknown_0_ + 0x81b0);
    for (var5 = 0; var5 < var13->unknown_1_4_; var5++) {
        var11 = 0;
        for (var12 = 0; var12 < var13[var5].unknown_e_0_; var12++) {
            struct Struct_ov024_021f7478_10* var14 = func_ov000_021536f8((int)arg0->unknown_0_, (short)(var13[var5].unknown_6_[var12] + 0xc0));
            if (var14 == 0) continue;
            if (func_02010088((struct Struct_02010088*)var14)) continue;
            if (func_ov024_021e6798((GameObject*)var14)) continue;
            arg0->unknown_7c_[arg0->unknown_9c_] = var14;
            arg0->unknown_a0_[var5][var11] = arg0->unknown_9c_;
            arg0->unknown_c4_[arg0->unknown_9c_] = var14->unknown_138_->primaryStats.currHP;
            if (arg0->unknown_6_ == 0) {
                if (func_ov024_021db358(var14) <= 1.0f) {
                    {
                    unsigned short var15 = inline_ov000_0215cd44(var14);
                    unsigned short var16 = inline_ov024_021dc700(var14);
                    arg0->unknown_c4_[arg0->unknown_9c_] = (int)(0.9f * var16 + 0.1f * var15);
                    }
                }
            } else {
                if (func_ov024_021db358(var14) <= 0.33333f) {
                    unsigned short var17 = inline_ov000_0215cd44(var14);
                    unsigned short var18 = inline_ov024_021dc700(var14);
                    int var19 = (int)(0.3f * var18 + 0.1f * var17);
                    if (var19 > arg0->unknown_c4_[var5]) {
                        arg0->unknown_c4_[arg0->unknown_9c_] = var19;
                    }
                }
            }
            arg0->unknown_9c_++;
            var11++;
        }
        arg0->unknown_b8_[var5] = var11;
    }

    arg0->unknown_74_ = func_ov000_0215e9fc((int)arg0->unknown_0_, var2, 4, 0);
    arg0->unknown_78_ = func_ov000_0215e9fc((int)arg0->unknown_0_, var3, 4, 1);

    int var20 = 0;
    arg0->unknown_128_ = 0;
    arg0->unknown_12c_ = -1;
    arg0->unknown_139_ = 0;
    arg0->unknown_130_ = 0;
    arg0->unknown_134_ = 0;
    for (long var21 = 0; var21 < 4; var21++) {
        arg0->unknown_114_[var21] = 1.0f;
        if (!func_020a35e0(((struct Struct_ov024_021f7478_5*)arg0->unknown_0_)->unknown_8e18_, var21)) continue;
        struct Struct_ov024_021f7478_10* var22 = GetCombatantByID((int)arg0->unknown_0_, (short)var21);
        if (var22 == 0) continue;
        arg0->unknown_114_[var21] = func_ov024_021db358(var22);
        arg0->unknown_104_[var21] = var22->unknown_138_->primaryStats.currHP;
        if (func_02010088((struct Struct_02010088*)var22)) {
            if (arg0->unknown_12c_ < 0) arg0->unknown_12c_ = var21;
            arg0->unknown_114_[var21] = 1.0f;
            continue;
        }
        if (arg0->unknown_114_[var21] < arg0->unknown_114_[arg0->unknown_128_]) arg0->unknown_128_ = var21;
        if (arg0->unknown_114_[var21] <= 0.08f) arg0->unknown_130_++;
        if (arg0->unknown_114_[var21] <= 0.25f) arg0->unknown_134_++;
        if (var20 < var22->unknown_138_->primaryStats.attack) var20 = var22->unknown_138_->primaryStats.attack;
    }
    if (arg0->unknown_134_ >= 2) arg0->unknown_139_ = 1;

    struct Struct_ov024_021f7478_10* var23 = (struct Struct_ov024_021f7478_10*)(Struct_0203d028_3*)func_0200ff1c(var10, arg0->unknown_4_);
    memset(arg0->unknown_e4_, 0, 0x20);
    for (int var24 = 0; var24 < arg0->unknown_9c_; var24++) {
        float var25 = inline_ov024_021f7478(inline_ov024_021d8ad8_2(var23), inline_ov024_021d8ad8_3(arg0->unknown_7c_[var24]));
        if (var25 < 1.0f) var25 = 1.0f;
        arg0->unknown_e4_[var24] = var25;
    }

    __clear(var0, 0x20);
    __clear(var1, 0x20);
    for (int var26 = 0; var26 < arg0->unknown_9c_; var26++) {
        float var27 = inline_ov024_021f7478_2(var20, inline_ov024_021d8ad8_3(arg0->unknown_7c_[var26]));
        if (var27 < 1.0f) var27 = 1.0f;
        var0[var26] = (int)var27;
        var1[var26] = (int)(((float)var0[var26] + arg0->unknown_e4_[var26]) / 2.0f);
    }

    int var28 = 0;
    int var29 = arg0->unknown_9c_;
    for (int var30 = 0; var30 < var29; var30++) {
        var28 += (int)(float)func_02008f5c((double)((float)arg0->unknown_c4_[var30] / (0.5f + 0.9375f * (float)var1[var30]))) + 1;
    }
    arg0->unknown_c_ = var28;

    GetFieldAt0x150_02053c6c((unsigned char*)self);
    obj->numEntries = 0;
    struct Entry_021f7478* entries = obj->entries;
    Zone3D_GetInstance();
    struct Entry_021f7478* e = &entries[obj->numEntries];
    e->id = 1;
    e->slot = -1;
    e->flag = 0;
    obj->numEntries++;

    if (((struct Struct_ov024_021f7478_8*)var23->unknown_138_)->unknown_3b_3_) {
        int var33 = func_ov000_02159cb4((int)arg0->unknown_0_, var23->unknown_4_);
        if (var33 != 0) {
            struct Struct_ov024_021f7478_6* var34 = &var31[arg0->unknown_174_];
            var34->unknown_0_ = var33;
            var34->unknown_2_ = -1;
            var34->unknown_3_ = 0;
            arg0->unknown_174_++;
        }
    }

    void* var35 = func_ov024_021f69b4((char*)func_ov000_02160f08(func_ov000_02160130()), arg0->unknown_4_);
    int var36 = func_ov000_021719c0((struct Struct_ov000_02171968*)var35);
    if (var36 > 0) {
        if (data_ov024_02200154[arg0->unknown_4_] == 0) {
            func_ov000_0217c32c(var35);
            data_ov024_02200154[arg0->unknown_4_] = 1;
        }
        for (int var37 = 0; var37 < var36; var37++) {
            if (!func_ov000_0217c4e8(var35, var37)) continue;
            struct Struct_ov024_021f7478* var38 = func_ov000_0217199c(var35, var37);
            if (var38 == 0) continue;
            if (!var38->unknown_b_3_) continue;
            struct Struct_ov024_021f7478_6* var39 = &var31[arg0->unknown_174_];
            var39->unknown_0_ = var38->unknown_4_0_;
            var39->unknown_2_ = -1;
            var39->unknown_3_ = 0;
            arg0->unknown_174_++;
            if (arg0->unknown_174_ == 0x80) return;
        }
    }

    var36 = func_ov000_02171698((struct Struct_ov000_02171640*)var35);
    for (int var40 = 0; var40 < var36; var40++) {
        struct Struct_ov024_021f7478* var41 = func_ov000_02171674(var35, var40);
        if (var41 == 0) continue;
        if (!var41->unknown_b_3_) continue;
        struct Struct_ov024_021f7478_6* var42 = &var31[arg0->unknown_174_];
        var42->unknown_0_ = var41->unknown_4_0_;
        var42->unknown_2_ = -1;
        var42->unknown_3_ = 0;
        arg0->unknown_174_++;
        if (arg0->unknown_174_ == 0x80) return;
    }

    Struct_02108e10* var43 = func_020797dc();
    int var44 = func_ov000_02171bc0(var35);
    for (int var45 = 0; var45 < var44; var45++) {
        struct Struct_ov024_021f7478_2* var46 = func_ov000_02171b9c(var35, var45);
        if (var46 == 0) continue;
        if (var46->unknown_18_ <= 0) continue;
        unsigned short var47 = var46->unknown_16_;
        if (var47 == 0) continue;
        struct Struct_ov024_021f7478* var48 = func_02079e2c((char*)var43, (short)var47);
        if (var48 == 0) continue;
        if (!var48->unknown_b_3_) continue;
        unsigned char var49 = var46->unknown_a_3_ ? 1 : 0;
        struct Struct_ov024_021f7478_6* var50 = &var31[arg0->unknown_174_];
        var50->unknown_0_ = var47;
        var50->unknown_2_ = var45;
        var50->unknown_3_ = var49;
        arg0->unknown_174_++;
        if (arg0->unknown_174_ == 0x80) return;
    }

    arg0->unknown_654_ = 0;
    const signed char* var51 = data_ov024_021fefb0;
    var23 = (struct Struct_ov024_021f7478_10*)(Struct_0203d028_3*)func_0200ff1c(var10, arg0->unknown_4_);
    if (var23 != 0) {
        for (; var51[0] != -1; var51 += 2) {
            if (var51[1] == func_02085748(var23->unknown_150_)) {
                arg0->unknown_654_ = var51[0];
                break;
            }
        }
    }

    if (arg0->unknown_7_ != 0) return;

    memset(arg0->unknown_69_, 0, 9);
    for (int var52 = 1; var52 <= 5; var52++) {
        arg0->unknown_154_[var52] = 0xff;
        arg0->unknown_13c_[var52] = 0;
    }

    ActionDataTables* moveTable2 = GetData02108e10_020797dc();
    for (int i = 0; i < obj->count; i++) {
        struct Combatant_021f7478* c = obj->list[i];
        int side = c->side;
        if (side < 0) continue;
        if (side >= 3) continue;
        if (c->moveSet == 0) continue;
        struct MoveSet_021f7478* set = c->moveSet;
        for (int j = 0; j < 6; j++) {
            unsigned short moveId = set->moves[j];
            if (GameState_IsInGrotto(gs) && ((struct PartyWork_021f7478*)((struct Battle_021f7478*)obj->battle)->partyWork)->f25 != 0) {
                char* detail = (char*)((ActiveGrottoClass*)((char*)Zone3D_GetInstance() + regionalGrottoOffset))->GetDetailedData();
                short kindId = c->kindId;
                unsigned short alt = ((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->MaybeGetCurrentAlternateID();
                if (alt == kindId) {
                    if (!((DetailedTreasureMapData::LegacyBossMapData*)(detail + 0x4c))->CanUseLevelUpMove(moveId)) continue;
                }
            }
            struct Struct_ov024_021f7478* var63 = func_02079e2c((char*)var53, (short)var59);
            if (var63 == 0) continue;
            if (var63->unknown_10_ & 1) arg0->unknown_69_[3] = 1;
            if (var63->unknown_9_0_ == 1 || var63->unknown_9_0_ == 3) {
                if (var63->unknown_10_ & 0x400) {
                    if (var63->unknown_18_5_ == 1) arg0->unknown_69_[2] = 1;
                }
            }
            if (var63->unknown_10_ & 4) {
                arg0->unknown_69_[4] = 1;
                if (var63->unknown_18_5_ == 1) arg0->unknown_69_[5] = 1;
            }
            if (var63->unknown_a_6_ == 1) arg0->unknown_69_[6] = 1;
            if (var63->unknown_a_6_ == 2) arg0->unknown_69_[7] = 1;
            if (var63->unknown_18_5_ == 0x11 || var63->unknown_18_0_ == 0x14 || var63->unknown_18_5_ == 0x23) arg0->unknown_69_[8] = 1;
        }
        var4[1] = var57->unknown_6c_[0];
        var4[2] = var57->unknown_6c_[1];
        var4[3] = var57->unknown_6c_[3] > var57->unknown_6c_[2] ? var57->unknown_6c_[3] : var57->unknown_6c_[2];
        var4[4] = var57->unknown_6c_[5] > var57->unknown_6c_[4] ? var57->unknown_6c_[5] : var57->unknown_6c_[4];
        var4[5] = var57->unknown_6c_[6];
        for (int var64 = 1; var64 <= 5; var64++) {
            if (arg0->unknown_154_[var64] > var4[var64]) arg0->unknown_154_[var64] = var4[var64];
            if (arg0->unknown_13c_[var64] < var4[var64]) arg0->unknown_13c_[var64] = var4[var64];
        }
    }

    int var65 = 1;
    for (int var66 = 0; var66 < 4; var66++) {
        if (!func_020a35e0(((struct Struct_ov024_021f7478_5*)arg0->unknown_0_)->unknown_8e18_, var66)) continue;
        struct Struct_ov024_021f7478_10* var67 = (struct Struct_ov024_021f7478_10*)(Struct_0203d028_3*)func_0200ff1c(var10, var66);
        if (var67 == 0) continue;
        if (var67->unknown_134_->primaryStats.attack > var65) var65 = var67->unknown_134_->primaryStats.attack;
    }
    for (int var68 = 0; var68 < 4; var68++) {
        if (!func_020a35e0(((struct Struct_ov024_021f7478_5*)arg0->unknown_0_)->unknown_8e18_, var68)) continue;
        struct Struct_ov024_021f7478_10* var69 = (struct Struct_ov024_021f7478_10*)(Struct_0203d028_3*)func_0200ff1c(var10, var68);
        if (var69 == 0) continue;
        arg0->unknown_44_[var68] = (float)var69->unknown_134_->primaryStats.attack / (float)var65;
    }

    struct Random* var70 = (struct Random*)arg0->unknown_0_;
    NextRandomFloat01(var70);
    var6 = data_ov024_021ff084;
    if (arg0->unknown_6_ == 1 || arg0->unknown_6_ == 4) {
        var6 = data_ov024_021ff0d8;
    } else if (arg0->unknown_6_ == 2) {
        var6 = data_ov024_021ff12c;
    } else if (arg0->unknown_6_ == 3) {
        var6 = data_ov024_021ff180;
    }
    arg0->unknown_28_ = var6;
    for (var5 = 0; var5 < 0x15; var5++) {
        var7 = var6[var5 * 4];
        var8 = var6[var5 * 4 + 1];
        if ((unsigned char)NextRandomMax(var70, 100) < var7) arg0->unknown_10_[var5] = 1;
        if (var28 < var8 * arg0->unknown_78_ / 10) arg0->unknown_10_[var5] = 0;
    }
    for (int var71 = 0; var71 < 0x15; var71++) {
        arg0->unknown_54_[var71] = NextRandomBetween(var70, var6[var71 * 4 + 2], var6[var71 * 4 + 3]);
    }
    arg0->unknown_30_ = NextRandomFloatBetween(var70, 0.0f, 0.9f);
}
