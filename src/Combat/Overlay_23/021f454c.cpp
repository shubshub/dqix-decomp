#include <globaldefs.h>
#include "GameState/GameState.h"
#include "Grotto/Main/ActiveGrottoClass.h"
#include "Util/Random.h"

extern "C" void* LinkSession_GetInstance(void);
extern "C" void* Zone3D_GetInstance(void);
extern "C" int RandomIntBelow(int span);

struct Struct_02010088;
struct Struct_02053dfc;
struct Struct_02070b6c_3;

int GameState_GetPartyOrderEntry(void* obj, unsigned int idx);
int TestBitAt0x34_020a35e0(unsigned char* obj, unsigned char index);
int IsFlag10088Set_02010088(struct S_10088* obj);
int GetField8FromField19c_02053dfc(struct Obj53dfc* obj);
int TestBitInArray0x8ec_02083b00(unsigned char* obj, int index);
unsigned short GameObject_GetPartyMemberLevel(void* obj);

struct Struct_ov023_021f454c_7 {
    unsigned short unknown_0_;
    unsigned char unknown_2_;
    unsigned char unknown_3_;
    unsigned short unknown_4_;
    unsigned short unknown_6_;
};

extern "C" struct Struct_ov023_021f454c_7* func_02070fd0(struct Struct_02070b6c_3* arg0, int arg1);

#if defined(jpn)
#define data_ov023_021fd888 data_ov023_021fcb3c
#endif
extern int data_ov023_021fd888[];

struct Struct_ov023_021f454c {
#if defined(jpn)
    char unknown_0_[0x144];
#else
    char unknown1_0_[0x150];
#endif
    unsigned char* unknown_150_;
};

struct Struct_ov023_021f454c_2 {
    unsigned short unknown_0_0_ : 3;
    unsigned short unknown_0_3_ : 11;
    unsigned short unknown_1_6_ : 1;
    unsigned short unknown_1_7_ : 1;
    unsigned short unknown_2_;
    unsigned short unknown_4_;
    unsigned char unknown_6_;
    unsigned char unknown_7_;
    unsigned char unknown_8_;
    unsigned char unknown_9_;
};

struct Struct_ov023_021f454c_3 {
    char unknown_0_[0x8d66];
    struct Struct_ov023_021f454c_2 unknown_8d66_[12];
    char unknown_8dde_[0x8e30 - 0x8dde];
    int unknown_8e30_;
};

struct Struct_ov023_021f454c_4 {
    char unknown_0_[0x24];
    unsigned char unknown_24_;
    unsigned char unknown_25_;
};

struct Struct_ov023_021f454c_5 {
    unsigned short unknown_0_;
    unsigned short unknown_2_0_ : 15;
    unsigned short unknown_3_7_ : 1;
    unsigned char unknown_4_;
    signed char unknown_5_;
};

struct Struct_ov023_021f454c_6 {
#if defined(jpn)
    char unknown_0_[0x218];
#else
    char unknown1_0_[0x29c];
#endif
    struct Struct_ov023_021f454c_3* unknown_29c_;
    struct Struct_ov023_021f454c_4* unknown_2a0_;
#if defined(jpn)
    char unknown_220_[0x5abc - 0x220];
#else
    char unknown_2a4_[0x58cc - 0x2a4];
#endif
    unsigned short unknown_58cc_;
    char unknown_58ce_[2];
    struct Struct_ov023_021f454c_5 unknown_58d0_[8];
    unsigned char unknown_5900_;
    signed char unknown_5901_;
#if defined(jpn)
    char unknown_5af2_[0x7014 - 0x5af2];
#else
    char unknown_5902_[0x6e24 - 0x5902];
#endif
    int unknown_6e24_;
    unsigned short unknown_6e28_;
    unsigned char unknown_6e2a_;
    unsigned char unknown_6e2b_;
    unsigned short unknown_6e2c_;
};

#define IsSpecial(info) ((info)->unknown_24_ != 0 || (info)->unknown_25_ != 0)

#if defined(jpn)
enum { Enum_ov023_021f454c_9196 = 0x240c };
#else
enum { Enum_ov023_021f454c_9196 = 0x23ec };
#endif

// USA: func_ov023_021f454c
extern "C" ARM void func_ov023_021f454c(struct Struct_ov023_021f454c_6* arg0) {
    unsigned char var0[4];
    GameState* var1;
    unsigned short var2;
    int var3;
    float var4;
    int var5;
    struct Random* var6;
    int var7;
    int var8;
    struct Struct_ov023_021f454c_2* var9;
    int var10;
    int var11;
    struct Struct_02070b6c_3* var12;
    DetailedTreasureMapData* var13;
    int var14;
    int var15;
    struct Struct_ov023_021f454c_2* var16;
    struct Struct_ov023_021f454c_5* var17;

    gs = GameState::GetInstance();
    table = (struct Container02070e60*)((char*)self->info + 0x684);
    LinkSession_GetInstance();
    detail = ((ActiveGrottoClass*)((char*)Zone3D_GetInstance() + regionalOffset0))->GetDetailedData();
    altId = 0;
    if (IsSpecial(self->info)) {
        if (detail->mapType_ == 1) {
            altId = detail->regular_.bossMonsterID_;
        } else if (detail->mapType_ == 2) {
            altId = detail->legacy_.MaybeGetCurrentAlternateID();
        }
    }

    self->dropCount = 0;
    self->memberMask = 0;
    count = self->world->rewardCount;
    rewards = self->world->rewards;
    cur = self->drops;
    scaledF = (float)self->scaled;
    for (round = 0; round < 5; round++) {
        rate = 100;
        if (round > 0) {
            int member = GameState_GetPartyOrderEntry(gs, (unsigned char)(round - 1));
            struct Combatant_021f454c* c = (struct Combatant_021f454c*)GetCombatantWithFlag0x100_0200ff1c(gs, member);
            if (c == 0) continue;
            if (!TestBitAt0x34_020a35e0((unsigned char*)self->info, member)) continue;
            if (IsFlag10088Set_02010088((struct S_10088*)c)) continue;
            if ((float)(unsigned int)GetField8FromField19c_02053dfc((struct Obj53dfc*)c) / scaledF < 0.5f) continue;
            if (!TestBitInArray0x8ec_02083b00(c->status, 0xa4)) continue;
            rate = GameObject_GetPartyMemberLevel(c);
            cur->member = member;
        } else {
            var17->unknown_5_ = -1;
        }

        if (IsSpecial(arg0->unknown_2a0_)) {
            int var20;
            for (var20 = 0; var20 < var3; var20++) {
                if (var2 == var9[var20].unknown_2_) break;
            }
            struct Struct_ov023_021f454c_2* var21 = 0;
            if (var20 < var3) var21 = &var9[var20];
            var6 = GetBTRandom();
            for (int var22 = 2; var22 >= 0; var22--) {
                var15 = var13->treasureDropRates_[var22];
                if (var14 > 0) {
                    int var23 = var15 * var5 / 100;
                    if (var13->treasureDropRates_[var22] >= 100) var23 = 0;
                    var15 = var23;
                } else if (var21 != 0) {
                    if (var21->unknown_1_6_ && var22 == 2) var15 = 100;
                    if (var21->unknown_1_7_ && var22 == 1) var15 = 100;
                }
                if (NextRandomMax(var6, 100) >= var15) continue;
                var13->discoveredTreasures_[var22] = 1;
                if (GetTreasureMapTypeFromItemID(var13->treasureItemIDs_[var22], var0)) {
                    if (arg0->unknown_6e24_ == 0) {
                        arg0->unknown_6e24_ = 1;
                        arg0->unknown_6e28_ = var13->treasureItemIDs_[var22];
                        arg0->unknown_6e2a_ = var0[0];
                        arg0->unknown_6e2b_ = var0[1];
                        arg0->unknown_6e2c_ = *(unsigned short*)&var0[2];
                    }
                    continue;
                }
                var17->unknown_0_ = var13->treasureItemIDs_[var22];
                var17->unknown_2_0_ = var2;
                struct Struct_ov023_021f454c_7* var24 = func_02070fd0(var12, var2);
                if (var24 != 0) {
                    if (var24->unknown_6_ == var17->unknown_0_) {
                        var17->unknown_4_ = 2;
                    } else if (var24->unknown_4_ == var17->unknown_0_) {
                        var17->unknown_4_ = 1;
                    } else {
                        var17->unknown_4_ = 0;
                    }
                }
                arg0->unknown_5900_++;
                if (arg0->unknown_5900_ >= 8) break;
                signed char var25 = var17->unknown_5_;
                var17++;
                var17->unknown_5_ = var25;
            }
        }

        if (arg0->unknown_5900_ >= 8) break;

        for (var7 = 0; var7 < var3; var7++) {
            var16 = &var9[var7];
            if (var16->unknown_0_3_ == var16->unknown_9_) continue;
            var8 = var16->unknown_2_;
            struct Struct_ov023_021f454c_7* var26 = func_02070fd0(var12, var8);
            if (var26 == 0) continue;
            if (IsSpecial(arg0->unknown_2a0_) && var2 == var8) continue;

            var10 = var26->unknown_3_;
            int var27 = data_ov023_021fd888[var10];
            if (var27 > 0) {
                if (var14 > 0) {
                    int var28 = var27 * 100 / var5;
                    if (var10 == 0) var28 = 0;
                    var27 = var28;
                } else if (var16->unknown_1_6_) {
                    var27 = 1;
                }
                if (chanceA > 0 && RandomIntBelow(chanceA) == 0) {
                    cur->id = e->item6;
                    cur->key = key;
                    cur->kind = 2;
                    self->dropCount++;
                    if (self->dropCount >= 8) break;
                    signed char m = cur->member;
                    cur++;
                    cur->member = m;
                    continue;
                }
            }

            var11 = var26->unknown_2_;
            int var30 = data_ov023_021fd888[var11];
            if (var30 <= 0) continue;
            if (var14 > 0) {
                int var31 = var30 * 100 / var5;
                if (var11 == 0) var31 = 0;
                var30 = var31;
            } else if (var16->unknown_1_7_) {
                var30 = 1;
            }
            if (chanceB <= 0) continue;
            if (RandomIntBelow(chanceB) != 0) continue;
            cur->id = e->item4;
            cur->key = key;
            cur->kind = 1;
            self->dropCount++;
            if (self->dropCount >= 8) break;
            signed char m = cur->member;
            cur++;
            cur->member = m;
        }

        if (arg0->unknown_5900_ >= 8) break;
    }

    if (arg0->unknown_5900_ != 0 || arg0->unknown_6e24_ != 0) {
        for (int var33 = 0; var33 < 4; var33++) {
            if (!func_020a35e0((unsigned char*)arg0->unknown_2a0_, var33)) continue;
            struct Struct_ov023_021f454c* var34 = (struct Struct_ov023_021f454c*)func_0200ff1c(var1, var33);
            if (var34 == 0) continue;
            if (!((float)(unsigned int)func_02053dfc((struct Struct_02053dfc*)var34) / var4 < 0.5f)) {
                arg0->unknown_5901_ |= 1 << var33;
            }
        }
    }
}
